#ifndef __CLY_AACENTER_H__
#define __CLY_AACENTER_H__

#define AA_FACTION_DUEL 10000
#define AA_GUILD_DUEL 20000

#include <iostream>

class Player;
class Item;
class Unit;
class Spell;
class Creature;
class SpellInfo;
class WorldObject;
class WorldSession;
class GameObject;
class Group;
struct ItemTemplate;
struct GameObjectTemplate;

using namespace std;
template <typename AAInt>
inline AAInt AA_SafeObjectAtIndex(std::vector<AAInt> objects, size_t index)
{
    if (objects.size() > index) {
        return objects[index];
    }
    else {
        return 0;
    }
}
template <typename AAString>
inline AAString AA_SafeStringAtIndex(std::vector<AAString> objects, size_t index)
{
    if (objects.size() > index) {
        return objects[index];
    }
    else {
        return "";
    }
}

//活动答题
struct AA_Dati_Conf
{
    uint32 id = 0;// ` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '答题id',
    uint32 zu = 0;// 组` int(10) unsigned NOT NULL DEFAULT '0' COMMENT '对应GM命令（.答题提问 组 限制答题时间秒）',
    uint32 chance = 0;// 随机几率` int(10) unsigned NOT NULL DEFAULT '100' COMMENT '公式：当前几率除以一个组的几率之和',
    std::string title = "";// 题目内容` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string result = "";// 正确答案` enum('A', 'B', 'C', 'D') CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT 'A',
    std::string a = "";// 选项A` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string b = "";// 选项B` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string c = "";// 选项C` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string d = "";// 选项D` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string gm_win = "";// 回答正确触发GM命令` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    std::string gm_lose = "";// 回答错误触发GM命令`
};

//1V1竞技场
struct AA_Arena_Conf
{
    uint32 id = 0;
    float value1 = 0;
    std::string value2 = "";
};

//比武大会
struct AA_Biwu_Conf {
    uint32 event_id = 0;//活动进场事件
    uint32 area = 0;//区域id
    ObjectGuid::LowType guid = 0;//比武大会GOB的GUID
    uint32 player_min = 0;//最少人数
    uint32 alert_id = 0;//_弹窗_id
    uint32 wait_time = 0;//单位秒，到达等待时间后开始战斗
    uint32 juedou_time = 0;//每场决斗限制时间
    std::string gm_win = "";//决斗胜利调用GM命令
    std::string gm_lose = "";//决斗失败调用GM命令
    std::string gm_1 = "";//比武结束第一名调用GM命令
};

struct AA_Biwu_Team {
    ObjectGuid::LowType p1 = 0;
    ObjectGuid::LowType p2 = 0;
};

struct AA_Diy_Duel {
    uint32 id = 0;
    std::string name = "";
    std::string namepre = "";
    std::string namesuf = "";
    uint32 need_add = 0;
    std::string gm_add = "";
    uint32 need_exit = 0;
    std::string gm_exit = "";
};

struct AA_Xitong_Group {
    uint32 id = 0;
    uint32 game_event = 0;
    uint32 count = 0;
    int32 zoneid = -1;
    uint32 iszhenying = 0;
    uint32 isgonghui = 0;
};

struct AA_Item_Set
{
    uint32 id = 0;
    uint32 zu = 0;
    uint32 count = 0;
    std::string spells = "";
    std::string text = "";
    uint32 update_time = 0;
};

struct AA_Item_Set_Conf
{
    uint32 zu = 0;
    std::string text = "";
};

struct AA_UI_Jijie
{
    uint32 id = 0;
    std::string name = "";
    std::string title = "";
    std::string icon = "";
    uint32 count_min = 0;
    uint32 count_max = 0;
    uint32 time = 0;
    uint32 need = 0;
    std::string gm = "";
};

struct AA_UI_Shenqi
{
    uint32 id = 0;
    uint32 lan = 0;
    uint32 level = 0;
    uint32 item = 0;
    std::string image = "";
    uint32 count = 1;
    int32 x = 0;
    int32 y = 0;
    std::string needs = "";
    uint32 need = 0;
    uint32 notice = 0;
};

struct AA_UI_Juanxian_Paiming
{
    uint32 id = 0;
    std::string guanghuans = "";
    uint32 guanghuan_item = 0;
};

struct AA_UI_Juanxian_Shuliang
{
    uint32 id = 0;
    std::string guanghuans = "";
    std::string guanghuan_details = "";
};

struct AA_UI_Shizhuang
{
    uint32 id = 0;
    uint32 lan = 0;
    uint32 item = 0;
    uint32 modelid = 0;
    float scale = 0;
    std::string needs = "";
    uint32 need = 0;
    uint32 notice = 0;
};

struct AA_UI_Chuansong
{
    uint32 id = 0;
    std::string title = "";
    std::string detail1 = "";
    std::string detail2 = "";
    std::string detail3 = "";
    std::string detail4 = "";
    std::string detail5 = "";
    std::string items = "";
    std::string gm = "";
};

struct AA_Item_Shuangjia
{
    uint32 id = 0;
    uint32 lan = 0;
    std::string items = "";
    std::string display_items = "";
    std::string need_xiangqian = "";
    std::string need_chaixie = "";
    std::string guanghuans = "";
    uint32 guanghuan_item = 0;
};
struct AA_Item_Shuangjia_Xianzhi
{
    uint32 zu = 0;
    uint32 xiangqian = 0;
};

struct AA_Item_Instance
{
    uint64 guid = 0;
    uint32 itemEntry = 0;
    uint64 owner_guid = 0;
    uint64 creatorGuid = 0;
    uint64 giftCreatorGuid = 0;
    uint32 count = 0;
    int32 duration = 0;
    std::string charges = "";
    uint32 flags = 0;
    std::string enchantments = "";
    int16 randomPropertyId = 0;
    uint16 durability = 0;
    uint32 playedTime = 0;
    std::string text = "";
    std::string weizhi = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Shop
{
    uint32 id = 0;//    `id` int unsigned NOT NULL DEFAULT '0' COMMENT 'Global Unique Identifier',
    std::string name = "";//    `栏目名称` text CHARACTER SET utf8 COLLATE utf8_general_ci,
    uint32 zu = 0;//    `第几栏` int unsigned NOT NULL DEFAULT '0',
    uint32 ye = 0;//    `第几页` int unsigned NOT NULL DEFAULT '0',
    uint32 entry = 0;//    `展示物品entry` int unsigned NOT NULL DEFAULT '0',
    ObjectGuid::LowType guidlow = 0;//    `展示物品guid` int unsigned NOT NULL DEFAULT '0' COMMENT '展示已存在物品guid',
    uint32 need = 0;//    `购买需求` int unsigned NOT NULL DEFAULT '0',
    uint32 reward = 0;//    `触发奖励` int unsigned NOT NULL DEFAULT '0',
    uint32 tanchuang = 0;//    `触发弹窗` int unsigned NOT NULL DEFAULT '0',
    std::string gm = "";//    `触发GM命令` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
    uint32 is_zhandou = 0;//    `允许战斗中使用` int unsigned NOT NULL DEFAULT '0' COMMENT '0不允许 1允许',
    uint32 notice = 0;//    `公告` int unsigned NOT NULL DEFAULT '0',
};

struct AA_Realmlist
{
    uint32 id = 0;
    std::string name = "";
    std::string address = "";
    uint32 port = 0;
};

struct AA_Item_NoJianding
{
    uint32 itemid = 0;
};

struct AA_Version
{
    std::string version = "";
    std::string ip = "";
    std::string uuid = "";
    uint32 playerCount = 0; //当前人数
    int32 aa_login_count = 1; //限制人数
    std::string status = ""; //"a1ba2ba99b"  a1b表示开通 生物排行
};

struct AA_Creature_Exp
{
    uint32 creatureid = 0;
    uint32 expdf = 0;
    float exppdf = 0;
    uint32 expdq = 0;
    float exppdq = 0;
    uint32 expjx = 0;
    float exppjx = 0;
    uint32 expcz = 0;
    float exppcz = 0;
};
struct AA_CreatureTemplate
{
    uint32 entry = 0;
    uint32 entry1 = 0;
    uint32 chance = 0;
};

struct AA_Zhuanzhi_Spell
{
    uint32 spellid = 0;
};

struct AA_Chengzhang_Item
{
    uint32 itemid = 0;
    uint32 need = 0;
    uint32 exp = 0;
    std::string items = "";
    std::string pcitems = "";
    uint32 notice = 0;
};

struct AA_Cuiqu_Item
{
    uint32 itemid = 0;
    uint32 need = 0;
    std::string cuiqu_pos = "";
    std::string items = "";
    std::string pcitems = "";
};

struct AA_Jianding_Item {
    uint32 itemid = 0;
    uint32 need = 0;
    uint32 chance = 0;
    uint32 nonsuchid = 0;
    std::string items = "";
    std::string pcitems = "";
    uint32 notice = 0;
};

struct AA_Chat
{
    std::string msg = "";
    std::string tomsg = "";
    uint32 show = 0;
};

struct AA_Liansha
{
    uint32 count = 0;
    uint32 reward_liansha = 0;
    std::string quyu_liansha = "";
    uint32 notice_liansha = 0;
    uint32 reward_zhongjie = 0;
    std::string quyu_zhongjie = "";
    uint32 notice_zhongjie = 0;
};

struct AA_Account
{
    uint32 id = 0;
    uint32 vip = 0;
    uint32 jifen = 0;
    uint32 jifen_cz = 0;
    uint32 jifen_all = 0;
    uint32 paodian = 0;
    uint32 mobi = 0;
    uint32 battlecore = 0;
    uint32 jifen_day = 0;
    uint32 shouchong_day = 0;
    uint32 shouchong = 0;
    std::string leichong = "";
    uint32 denglu_day = 0;
    std::string denglu = "";
    uint32 denglu_qiandao = 0;
    uint32 licai_day = 0;
    uint32 licai = 0;
    std::string buy_time = "";
    std::string buy_time_yj = "";
    std::string diy_account = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_System
{
    std::string diy_system = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Character_Juanxian
{
    ObjectGuid::LowType guid = 0;
    std::string name = "";
    uint32 juanxian = 0;
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Characters
{
    ObjectGuid::LowType guid = 0;
    uint32 playtime = 0;
    std::string shengji = "";
    uint32 tianfu = 0;
    uint32 choujiang = 0;
    uint32 choujianglq = 0;
    std::string buy_time = "";
    std::string buy_time_yj = "";
    std::string zhaomu = "";
    std::string diy_guid = "";
    std::string name_pre = "";
    std::string name_suf = "";
    uint32 duel_diy = 0;
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Vip_Conf
{
    uint32 level = 0;
    uint32 need = 0;
    uint32 talent = 0;
    uint32 reward = 0;
    uint32 add_reward = 0;
    float exp = 0;
    uint32 zhuanye = 0;
    float loot = 0;
    uint32 shuliang = 0;
    float shuliang_chance = 0;
    uint32 paodian = 0;
    float qianghua = 0;
    float hecheng = 0;
    std::string spells = "";
    uint32 botcount = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Douqi_Conf
{
    uint32 level = 0;
    uint32 exp = 0;
    uint32 reward = 0;
    std::string spells = "";
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Characters_Douqi
{
    ObjectGuid::LowType guid = 0;
    uint32 level = 0;
    uint32 exp = 0;
    uint32 dianshu_all = 0;
    int32 dianshu = 0;
    uint32 tianfu = 0;
    std::string value = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Junxian_Conf
{
    uint32 level = 0;
    uint32 exp = 0;
    uint32 reward = 0;
    std::string spells = "";
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Characters_Junxian
{
    ObjectGuid::LowType guid = 0;
    uint32 level = 0;
    uint32 exp = 0;
    uint32 dianshu_all = 0;
    int32 dianshu = 0;
    uint32 tianfu = 0;
    std::string value = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Dianfeng_Conf
{
    uint32 level = 0;
    uint32 exp = 0;
    uint32 reward = 0;
    std::string spells = "";
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Characters_Dianfeng
{
    ObjectGuid::LowType guid = 0;
    uint32 level = 0;
    uint32 exp = 0;
    uint32 dianshu_all = 0;
    int32 dianshu = 0;
    uint32 tianfu = 0;
    std::string value = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

struct AA_Need_Conf
{
    uint32 id = 0;
    uint32 level = 0;
    uint32 jxlevel = 0;
    uint32 dqlevel = 0;
    uint32 dflevel = 0;
    uint32 viplevel = 0;
    uint32 jifen_all = 0;
    uint32 money = 0;
    uint32 paodian = 0;
    uint32 mobi = 0;
    uint32 jifen = 0;
    uint32 battlecore = 0;
    uint32 honorcore = 0;
    uint32 tianfu = 0;
    uint32 deplete = 0;
    std::string items = "";
    uint32 level_item_ItemLevel = 0; //物品ItemLevel
    uint32 level_item_Quality = 0; //物品Quality
    uint32 level_item_jd = 0; //物品鉴定等级
    uint32 level_item_cz = 0; //物品成长等级
    uint32 level_item_qh = 0; //物品强化等级
    uint32 level_item_jxsx = 0; //物品觉醒属性等级
    uint32 level_item_jxjn = 0; //物品觉醒技能等级
    uint32 level_pet_jh = 0; //宠物进化等级
    uint32 level_pet_qh = 0; //宠物强化等级
    uint32 level_pet_jx = 0; //宠物觉醒等级
    std::string quests = "";
    std::string achievements = "";
    std::string spells = "";
    std::string buffs = "";
    uint32 gender = 0;
    uint8 team = 0;
    uint32 race = 0;
    uint32 class1 = 0;
    uint32 guild = 0;
    int32 mapid = -1;
    int32 areaid = -1;
    int32 zoneid = -1;
    std::string diy_guid = "";
    std::string diy_account = "";
    std::string diy_system = "";
    std::string game_event = "";
    uint32 group_count = 0;
    uint32 group_duizhang = 0;
    uint32 is_yongbing = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_AuraId_Conf
{
    uint32 id = 0;
    uint32 zu = 0;
    float chance = 0;
    uint32 auraid = 0;
};
struct AA_SpellId_Conf
{
    uint32 id = 0;
    uint32 zu = 0;
    float chance = 0;
    uint32 spellid = 0;
};
struct AA_Reward_Conf
{
    uint32 id = 0;
    uint32 chance = 0;
    uint32 exp = 0;
    uint32 jxexp = 0;
    uint32 dqexp = 0;
    uint32 dfexp = 0;
    uint32 czexp = 0;
    uint32 money = 0;
    uint32 paodian = 0;
    uint32 mobi = 0;
    uint32 jifen = 0;
    uint32 battlecore = 0;
    uint32 honorcore = 0;
    std::string items = "";
    std::string spells = "";
    std::string buffs = "";
    int32 teleport_id = 0;
    uint32 vip_level = 0;
    uint32 tianfu = 0;
    uint32 jxds = 0;
    uint32 dqds = 0;
    uint32 dfds = 0;
    uint32 touxian = 0;
    std::string gm = "";
    std::string diy_guid = "";
    std::string diy_account = "";
    std::string diy_system = "";
    std::string game_event = "";
    std::string text = "";
};

struct AA_Character_Instance
{
    ObjectGuid::LowType guid = 0; //guid
    uint32 itemEntry = 0; //itemEntry
    ObjectGuid::LowType owner_guid = 0; //owner_guid
    std::string name = ""; //name
    uint32 fugai_zu = 0; //覆盖组
    std::string fugai = ""; //原始属性
    uint32 jd_zu = 0; //鉴定组-----拾取鉴定
    uint32 jd_id = 0; //鉴定id
    uint32 jd_level = 0; //鉴定等级
    std::string jd_values = ""; //鉴定属性
    uint32 qh_zu = 0; //强化组-----拾取鉴定
    uint32 qh_id = 0; //强化id
    uint32 qh_level = 0; //强化等级
    std::string qh_values = ""; //强化属性
    uint32 qh_reward_value = 0; //强化奖励属性
    uint32 qh_reward_point = 0; //强化奖励属性百分比
    std::string qh_reward_spell = ""; //强化奖励技能
    uint32 cz_zu = 0; //成长组-----拾取鉴定
    uint32 cz_id = 0; //成长id
    uint32 cz_level = 0; //成长等级
    uint32 cz_exp = 0; //成长经验
    std::string cz_values = ""; //成长属性
    uint32 cz_reward_value = 0; //成长奖励属性
    uint32 cz_reward_point = 0; //成长奖励属性百分比
    std::string cz_reward_spell = ""; //成长奖励技能
    uint32 fm_spell_count = 0; //附魔技能数量-----拾取鉴定
    std::string fm_spells = ""; //附魔技能-----拾取鉴定
    uint32 fm_value_count = 0; //附魔属性数量-----拾取鉴定
    std::string fm_values = ""; //附魔属性-----拾取鉴定
    uint32 chongzhu_count = 0; //重铸次数
    uint32 chongzhu_value = 0; //重铸属性需要
    uint32 chongzhu_spell = 0; //重铸技能需要
    uint32 fw_count = 0; //符文数量
    std::string fw_values = ""; //符文属性
    std::string fwzh_values = ""; //符文组合属性
    int32 cuiqu_pos = -1; //萃取位置
    uint32 baoshi_entry = 0;
    uint32 item_set = 0;
    uint32 update_time = 0; //update_time
    bool isUpdate = false;
};
struct AA_Stat {
    std::string text = "";
    uint32 id = 0;
    uint32 zu = 0;
    uint32 type = 0;
    uint32 chance = 0;
    int32 value = 0;
    int32 point = 0;
    uint32 cuiqu_need = 0;
    uint32 cuiqu_only = 0;
    uint32 update_time = 0;
};

struct AA_Stat_Xianzhi {
    uint32 type = 0;
    int32 value = 0;
};

struct AA_Spell {
    std::string text = "";
    uint32 id = 0;
    uint32 zu = 0;
    std::string class1 = "-1";
    std::string subclass = "-1";
    std::string inventoryType = "-1";
    std::string values = "";
    uint32 chance = 0;

    int32 SpellID;
    uint8 LegacySlotIndex;
    int8 TriggerType;
    int16 Charges;
    int32 CoolDownMSec;
    int32 CategoryCoolDownMSec;
    uint16 SpellCategoryID;
    uint16 ChrSpecializationID;

    uint32 cuiqu_need = 0;
    uint32 cuiqu_only = 0;
    uint32 update_time = 0;
};

struct AA_Item_Nonsuch {
    uint32 id = 0;
    uint32 zu = 0;
    uint32 level = 0;
    uint32 chance = 0;
    std::string cz_zus = "";
    std::string qh_zus = "";
    uint32 fg_statzu = 0;
    uint32 fg_count1 = 0;
    uint32 fg_count2 = 0;
    uint32 fg_value1 = 0;
    uint32 fg_value2 = 0;
    uint32 fg_only = 0;
    uint32 jp_statzu = 0;
    uint32 jp_type = 0;
    uint32 jp_value1 = 0;
    uint32 jp_value2 = 0;
    uint32 jp_percent1 = 0;
    uint32 jp_percent2 = 0;
    std::string fmval_statzu = "";
    uint32 fmval_count1 = 0;
    uint32 fmval_count2 = 0;
    int32 fmval_value1 = 0;
    int32 fmval_value2 = 0;
    uint32 fmval_only = 0;
    std::string fmspell_spellzu = "";
    uint32 fmspell_count1 = 0;
    uint32 fmspell_count2 = 0;
    uint32 fmspell_only = 0;
    std::string text = "";
    std::string textpre = "";
    std::string textsuf = "";
    std::string detail = "";
    uint32 chuandai = 0;
    uint32 fw_count1 = 0;
    uint32 fw_count2 = 0;
    std::string itemsets = "";
    uint32 notice = 0;
};

struct AA_Item_Nonsuch_Id {
    uint32 entry = 0;
    uint32 zu = 0;
};

struct AA_Item_Upgrade {
    std::string upgrade_spell = "";
    uint32 id = 0;
    uint32 zu = 0;
    uint32 level = 0;
    float chance = 0;
    uint32 stat_group = 0;
    uint32 distribution = 0;
    uint32 value1 = 0;
    uint32 value2 = 0;
    uint32 percent1 = 0;
    uint32 percent2 = 0;
    uint32 reward_value = 0;
    uint32 reward_percent = 0;
    uint32 destroy = 0;//0升级失败不变 1升级失败清零 2升级失败消失
    uint32 need = 0;
    float chance_jd = 0;
    uint32 notice = 0;
};

struct AA_Item_Level {
    uint32 id = 0;
    uint32 zu = 0;
    uint32 level = 0;
    uint32 exp = 0;
    uint32 stat_group = 0;
    uint32 distribution = 0;
    uint32 value1 = 0;
    uint32 value2 = 0;
    uint32 percent1 = 0;
    uint32 percent2 = 0;
    uint32 reward_value = 0;
    uint32 reward_percent = 0;
    std::string spell = "";
    uint32 notice = 0;
};

struct AA_Teleport_Conf {
    uint32 id = 0;
    uint32 menuid = 0;
    uint32 targetid = 0;
    std::string title = "";
    std::string subtitle = "";
    uint32 icon1 = 0;
    std::string script = "";
    std::string gm = "";
    uint32 need = 0;
    uint32 is_visible = 0;
    uint32 is_zhandou = 0;
    uint32 nanduid = 0;
    uint32 notice = 0;
};

struct AA_Map_Player_Conf {
    uint32 id = 0;
    std::string nandumoshi = "";
    uint32 nanduid = 0;
    uint32 playercount = 0;
    int32 map = -1;
    int32 zone = -1;
    int32 area = -1;
    uint32 need = 0;
    std::string PvpType = "";
    uint32 isMaxHealth = 0;
    std::string namePre = "";
    std::string nameSuf = "";
    uint32 GroupOnOff = 0;
    uint32 FlyOnOff = 0;
    std::string jyjineng = "";
    std::string jywupin = "";
    std::string hdguanghuan = "";
    std::string zuoqis = "";
    float visibility_dist = 0;
    std::string zuobiao_lm = "";
    std::string zuobiao_bl = "";
    uint32 dietime = 0;//死亡次数
    uint32 xianzhitime = 0;//挑战时间
    std::string jindu_exp = "";
    std::string jindu_reward = "";
    std::string jindu_reward_duixiang = "";
    uint32 jindu_notice = 0;
    uint32 notice_jr = 0;

    //临时变量
    uint32 m_dietime = 0;
    ObjectGuid::LowType m_guidlow = 0;
    uint32 m_mapid = 0;
    uint32 m_mapmoshi = 0;
    uint32 m_xianzhitime = 0;
    uint32 m_jindu_exp = 0;
    std::map<uint32, uint32> m_jindu_status;
};

struct AA_Aura_Conf
{
    uint32 spellid = 0; //`技能ID
    std::string values = "";
    std::string spell_pvp = "";
    std::string spell_pve = "";
    std::string heal_pvp = "";
    std::string heal_pve = "";
    uint32 diejia_ceng = 0;
    std::string diejia_spell = "";
    std::string diejia_gm = "";
    uint32 yichu_ceng = 0;
    uint32 die = 0;
    uint32 dietime = 0;
    uint32 zu = 0; //光环唯一组
};

struct AA_Spell_Conf
{
    uint32 spellid = 0; //`技能ID
    uint32 need = 0; //`释放技能需求模板ID
    std::string spell_cast = ""; //施放技能触发技能
    std::string gm_cast = ""; //`施放技能触发GM命令
    std::string gm_learn = ""; //`学习技能触发GM命令
    std::string gm_unlearn = ""; //`遗忘技能触发GM命令
    std::string target = ""; //`技能目标限制`enum('','boss','小怪','玩家','小怪玩家','boss玩家','小怪boss')
    float dmg_pvp = 0; //`伤害倍率
    float dmg_pve = 0; //`伤害倍率
    float healing_pvp = 0; //`治疗倍率
    float healing_pve = 0; //`治疗倍率
    std::string isOk = ""; //`是否禁用
    uint32 time_shifa = 0; //`施法时间
    uint32 time_chixu = 0; //`持续时间
    uint32 time_lengque = 0; //`冷却时间
    float chance = 0;//`触发机率`
    uint32 shifangxianzhi = 0;//施放限制开关,开启后不消耗符文、能量、魔法值、怒气。不限制变身，狂暴姿势、防御姿势、战斗姿势、隐身模式，不限制射程太近
    uint32 Periodic[3];//`周期123`
};

struct AA_Pet_Conf
{
    uint32 class1 = 0;
    float agility = 0;
    float strength = 0;
    float intellect = 0;
    float spirit = 0;
    float stamina = 0;
};

struct AA_Pet_Spell
{
    uint32 id = 0;
    uint32 group = 0;
    uint32 chance = 0;
    uint32 spellid = 0;
};
struct AA_Event_Conf
{
    uint32 id = 0;
    uint32 chance = 0;
    uint32 target = 0;
    uint32 need = 0;
    std::string gm = "";
    uint32 notice = 0;
    uint32 done_need = 0;
    std::string done_gm = "";
    uint32 done_notice = 0;
    std::string title = "";
    std::string text = "";
};

struct AA_Event_GameEvent
{
    uint32 entry = 0;
    uint32 target = 0;
    std::string gm1 = "";
    std::string gm2 = "";
};

struct AA_Event_Map
{
    uint32 id = 0;
    std::string type = "";
    int32 value = 0;
    int32 mapid = -1;
    int32 zoneid = -1;
    int32 areaid = -1;
    uint32 need = 0;
    std::string gm = "";
};

struct AA_Event_Playtime
{
    uint32 time = 0;
    std::string gm = "";
};

struct AA_Battleground_Conf
{
    uint32 id = 0;
    std::string name = "";
    uint32 player_count = 0;
    uint32 is_open = 0;
    uint32 type = 0;
    uint32 is_randomzy = 0;
    uint32 join_need = 0;
    uint32 alert_jiange = 0;
    uint32 event_id = 0;
    uint32 stop_time = 0;
    uint32 max_time = 0;
    uint32 Reqkillcount = 0;
    uint32 ReqkillCreature_lm = 0;
    uint32 ReqkillCreature_bl = 0;
    uint32 reward_damage = 0;
    uint32 reward_healing = 0;
    uint32 kill_reward = 0;
    uint32 die_reward = 0;
    uint32 win_reward = 0;
    uint32 lose_reward = 0;
};

struct AA_Notice
{
    uint32 entry = 0;
    std::string content_default1 = "";
    std::string content_default2 = "";
    int32 target = 0; //-1不发送0个人1队伍2本阵营3全服
    uint32 type = 0; //0发送到聊天框 1发送到屏幕中央
    std::string msg = "";
};
struct AA_Player_Stats_Conf
{
    uint32 id = 0;
    uint8 class1 = 0;//职业类型',
    int32 map = -1;
    int32 zone = -1;
    int32 area = -1;
    uint32 liliang = 0;
    uint32 liliangbl = 0;
    uint32 minjie = 0;
    uint32 minjiebl = 0;
    uint32 zhili = 0;
    uint32 zhilibl = 0;
    uint32 jingshen = 0;
    uint32 jingshenbl = 0;
    uint32 naili = 0;
    uint32 nailibl = 0;
    uint32 faqiang = 0;
    uint32 faqiangbl = 0;
    uint32 gongqiang = 0;
    uint32 gongqiangbl = 0;
    uint32 zhiliao = 0;
    uint32 zhiliaobl = 0;
    uint32 shensheng = 0;
    uint32 shenshengbl = 0;
    uint32 huoyan = 0;
    uint32 huoyanbl = 0;
    uint32 ziran = 0;
    uint32 ziranbl = 0;
    uint32 bingshuang = 0;
    uint32 bingshuangbl = 0;
    uint32 anying = 0;
    uint32 anyingbl = 0;
    uint32 aoshu = 0;
    uint32 aoshubl = 0;
    uint32 blocksx = 0;//0' COMMENT '格挡上限数值',
    uint32 parrysx = 0;//0' COMMENT '招架数值上限',
    uint32 dodgesx = 0;//100' COMMENT '闪避数值上限',
    uint32 bjsx = 0;//100' COMMENT '暴击上限',
    uint32 renxingsx = 0;//100' COMMENT '韧性上限',
    uint32 renxingbl = 0;//100' COMMENT '韧性倍率   公式为:当前韧性 除以 renxingbl',
    uint32 hujiasx = 0;//100' COMMENT '护甲上限',
    uint32 hujiabl = 0;//100' COMMENT '护甲倍率   公式为:当前护甲 除以 hujiabl',
    uint32 jzsx = 0;//100' COMMENT '精通上限',
    uint32 jzbl = 0;//100' COMMENT '精通倍率',
    uint32 hpsx = 0;//100' COMMENT '血量上限',
    uint32 hpbl = 0;//100' COMMENT '血量倍率',
    uint32 jssx = 0;//100' COMMENT '急速上限',
    uint32 jsbl = 0;//100' COMMENT '急速倍率',
    uint32 ptshsx = 0;//100' COMMENT '普通伤害上限',
    uint32 ptshbl = 0;//100' COMMENT 'PVP普通伤害倍率 公式为:PVP普通伤害 乘以 ptshbl',
    uint32 cptshbl = 0;//100' COMMENT 'PVE普通伤害倍率 公式为:PVE普通伤害 乘以 cptshbl',
    uint32 jnshsx = 0;//100' COMMENT '技能伤害上限',
    uint32 jnshbl = 0;//100' COMMENT 'PVP技能伤害倍率 公式为:PVP技能伤害 乘以 jnshbl',
    uint32 cjnshbl = 0;//100' COMMENT 'PVE技能伤害倍率 公式为:PVE技能伤害 乘以 cjnshbl',
    uint32 zlshsx = 0;//100' COMMENT '治疗伤害上限',
    uint32 zlshbl = 0;//100' COMMENT 'PVP治疗伤害倍率 公式为:PVP治疗伤害 乘以 zlshbl',
    uint32 czlshbl = 0;//100' COMMENT 'PVE治疗伤害倍率 公式为:PVE治疗伤害 乘以 czlshbl',
    int32 jianshangpvp = 0;
    int32 jianshangpve = 0;
    float lltofq = 0;// 力量转法强，
    float mjtofq = 0;// 敏捷转法强，
    float nltofq = 0;// 耐力转法强，
    float zltofq = 0;// 智力转法强，
    float jstofq = 0;// 精神转法强，
    float lltogq = 0;// 力量转攻强，
    float mjtogq = 0;// 敏捷转攻强，
    float nltogq = 0;// 耐力转攻强，
    float zltogq = 0;// 智力转攻强，
    float jstogq = 0;// 精神转攻强
};

struct AA_Ai
{
    uint32 id = 0;
    uint32 zu = 0;
    float event_chance = 0;
    uint32 event_cooldown = 0;
    uint32 gg_zu = 0;
    uint32 gg_cooldown = 0;
    std::string event_type = "";
    int32 event_param1 = 0;
    int32 event_param2 = 0;
    uint32 event_param3 = 0;
    uint32 event_param4 = 0;
    std::string event_param5 = "";
    std::string action_target = "";
    std::string action_target_ids = "";
    std::string action_type = "";
    int32 action_param1 = 0;
    int32 action_param2 = 0;
    int32 action_param3 = 0;
    int8 action_param4 = 0;
    std::string action_param5 = "";
    uint32 notice = 0;
};

struct AA_Ai_Map
{
    std::string target = "";
    int32 map = -1;
    int32 zone = -1;
    int32 area = -1;
    std::string ais = "";
};

struct AA_Ai_Item
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Ai_Pet
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Ai_Creature
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Ai_Spell
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Ai_Spell_Learn
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Ai_Spell_Item
{
    uint32 id = 0;
    std::string ais = "";
};

struct AA_Huishou_Conf
{
    uint32 id = 0;
    uint32 youxianji = 0;
    uint32 itemid = 0;
    uint32 need = 0;
    uint32 reward = 0;
};

struct AA_Reward_Level_Conf
{
    uint32 level = 0;
    uint32 type = 0;
    uint32 reward = 0;
    uint32 count = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Reward_Shouchong_Conf
{
    uint32 id = 0;
    uint32 jifen = 0;
    uint32 reward = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Reward_Licai_Conf //_奖励_理财
{
    uint32 id = 0;
    uint32 need = 0;
    uint32 reward = 0;
    uint32 day = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Reward_Leiji_Conf //_奖励_累充
{
    uint32 jifen = 0;
    uint32 reward = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Reward_Qiandao_Conf //_奖励_签到
{
    uint32 day = 0;
    uint32 reward = 0;
    uint32 notice = 0;
    std::string text = "";
};

struct AA_Desktop_Conf
{
    uint32 id = 0;
    uint32 type = 0;
    uint32 open = 0;
    std::string title = "";
    std::string icon_path = "";
    uint32 icon_spell = 0;
    uint32 icon_item = 0;
    std::string text = "";
    std::string gm = "";
    std::string www = "";
};

struct AA_Fw_Conf
{
    uint32 itemid = 0;
    std::string class1 = "-1";
    std::string subclass = "-1";
    std::string inventoryType = "-1";
    std::string spells = "";
    std::string values = "";
    std::string text = "";
};

struct AA_Baoshi_Conf
{
    uint32 itemid = 0;
    std::string spells = "";
    std::string values = "";
    std::string text = "";
};

struct AA_FwZh_Conf
{
    uint32 id = 0;
    std::string items = "";
    std::string class1 = "-1";
    std::string subclass = "-1";
    std::string inventoryType = "-1";
    std::string spells = "";
    std::string values = "";
    std::string text = "";
};

struct AA_World_Conf
{
    uint32 id = 0;
    uint32 value1 = 0;
    std::string value2 = "";
};

struct AA_Boss_Conf
{
    uint32 id = 0;
    std::string reward = "";
    uint32 show = 0;
};

struct AA_Hecheng_Conf
{
    uint32 itemid = 0;
    float chance = 0;
    uint32 itemid1 = 0;
    uint32 need = 0;
    uint32 destroy = 0;
    std::string is_baoliu = "";
    uint32 notice = 0;
};

struct AA_Chaixie_Conf
{
    uint32 itemid = 0;
    float chance = 0;
    uint32 need = 0;
    uint32 reward = 0;
    uint32 notice = 0;
};

struct AA_Jiebang_Conf
{
    uint32 itemid = 0;
    uint32 need = 0;
    uint32 reward = 0;
    uint32 notice = 0;
};

struct AA_Qianghua_Item
{
    uint32 itemid = 0;
    uint32 need = 0;
    float chance = 0;
    uint32 level = 0;
    std::string items = "";
    std::string pcitems = "";
    uint32 notice = 0;
};

struct AA_Item_Bag
{
    uint32 entry = 0;
    uint32 bag = 0;
};

struct AA_Item_Use_Need
{
    uint32 entry = 0;
    uint32 need = 0;
};

struct AA_Item_Use_Reward
{
    uint32 entry = 0;
    uint32 reward = 0;
    std::string gm = "";
};

struct AA_Item_Buy_Need
{
    uint32 vendor = 0;
    uint32 entry = 0;
    uint32 need = 0;
};

struct AA_Item_Buy_Reward
{
    uint32 entry = 0;
    uint32 reward = 0;
};

struct AA_Item_Jianding_Buy
{
    uint32 entry = 0;
    std::string zus = "";
};

struct AA_Item_Jianding_Cz
{
    uint32 entry = 0;
    uint32 cishu = 0;
    uint32 need_value = 0;
    uint32 need_spell = 0;
};

struct AA_Item_Jianding_Xl
{
    uint32 entry = 0;
    uint32 zu = 0;
};

struct AA_Item_Qh_Id
{
    uint32 entry = 0;
    std::string zus = "";
};

struct AA_Item_Level_Id
{
    uint32 entry = 0;
    std::string zus = "";
};

struct AA_Creature {
    uint32 id = 0;
    uint32 zu = 0;
    float chance = 0;
    uint32 level = 0;
    float walk_speed = 0;
    float walk_speed1 = 0;
    uint32 attack_speed = 0;
    uint32 attack_speed1 = 0;
    uint32 health = 0;
    uint32 health1 = 0;
    uint32 mana = 0;
    uint32 mana1 = 0;
    uint32 armor = 0;
    uint32 armor1 = 0;
    int32 resistance = 0;
    int32 resistance1 = 0;
    uint32 damage_min = 0;
    uint32 damage_max = 0;
    float damage = 0;
    uint32 damage_spell_min = 0;
    uint32 damage_spell_max = 0;
    float damage_spell = 0;
    uint32 health_spell_min = 0;
    uint32 health_spell_max = 0;
    float health_spell = 0;
    int32 jianshang_wl = 0;
    int32 jianshang_mf = 0;
    uint32 shangxian = 0;
    uint32 qiege = 0;
    std::string ais = "";
    uint32 nonsuch_group = 0;
    std::string lootid = "";
    std::string lootid1 = "";
    std::string old_loot = "";
    std::string moxing = "";
    std::string moxing1 = "";
    std::string moxing2 = "";
    std::string moxing3 = "";
    float scale = 0;
    uint32 type = 0;
    uint32 reward = 0;
    float reward_chance = 0;
    uint32 reward_dz = 0;
    float reward_dz_chance = 0;
    uint32 reward_dw = 0;
    float reward_dw_chance = 0;
    uint32 tanchuang = 0;
    uint32 notice = 0;
    uint32 notice_sx = 0;
    std::string creatureName = "";
    uint32 creatureEntry = 0;
};

struct AA_Creature_Id
{
    uint32 entry = 0;
    uint32 nanduid = 0;
    std::string zus = "";
    std::string pet_moxing = "";
    std::string pet_moxing1 = "";
    std::string pet_moxing2 = "";
    std::string pet_moxing3 = "";
    float pet_scale = 0;
};

struct AA_Creature_Map {
    uint32 id = 0;
    std::string nandumoshi = "";
    uint32 nanduid = 0;
    uint32 playercount = 0;
    std::string rank = "";
    int32 map = -1;
    int32 zone = -1;
    int32 area = -1;
    std::string c_zus = "";
    std::string o_zus = "";
    std::string factions = "";
    std::string entrys = "";
};

struct AA_Object {
    uint32 id = 0;
    uint32 zu = 0;
    float chance = 0;
    uint32 nonsuch_group = 0;
    std::string lootid = "";
    std::string lootid1 = "";
    std::string old_loot = "";
    float scale = 0;
    uint32 reward = 0;
    float reward_chance = 0;
    uint32 reward_dz = 0;
    float reward_dz_chance = 0;
    uint32 reward_dw = 0;
    float reward_dw_chance = 0;
    uint32 tanchuang = 0;
    uint32 notice = 0;
};

struct AA_Item {
    uint32 id = 0;
    uint32 nonsuch_group = 0;
    std::string lootid = "";
    std::string lootid1 = "";
    std::string old_loot = "";
    uint32 reward = 0;
    float reward_chance = 0;
    uint32 reward_dz = 0;
    float reward_dz_chance = 0;
    uint32 reward_dw = 0;
    float reward_dw_chance = 0;
    uint32 tanchuang = 0;
    uint32 notice = 0;
};

struct AA_Object_Id
{
    uint32 entry = 0;
    uint32 nanduid = 0;
    std::string zus = "";
    float scale = 0;
};

struct AA_Caiji_Item {
    std::string text = "";
    uint32 id = 0;
    uint32 zu = 0;
    uint32 chance = 0;
    uint32 count = 0;
    uint32 entry = 0;
    uint32 class1 = 0;
    uint32 subclass = 0;
    std::string name = "";
    uint32 displayid = 0;
    uint32 Quality = 0;
    uint32 notice = 0;
    uint32 xiangqian = 0;
    uint32 is_shuangjia = 0;
};

struct AA_Caiji_Zuobiao {
    std::string text = "";
    uint32 id = 0;
    uint32 zu = 0;
    uint32 chance = 0;
    std::string name = "";
    uint32 map = 0;
    uint32 zone = 0;
    uint32 area = 0;
    float position_x = 0;
    float position_y = 0;
    float position_z = 0;
    float orientation = 0;
    uint32 instanceId = 0;
};

struct AA_Caiji_Creature {
    std::string text = "";
    uint32 id = 0;
    uint32 zu = 0;
    uint32 chance = 0;
    std::string name = "";
    std::string subname = "";
    int32 entry = 0;
    uint32 faction = 0;
    uint32 displayid = 0;
    uint32 map = 0;
    uint32 zone = 0;
    uint32 area = 0;
    uint32 nandu = 0;
    float position_x = 0;
    float position_y = 0;
    float position_z = 0;
    float orientation = 0;
    uint32 instanceId = 0;
};

struct AA_Caiji_Player {
    std::string text = "";
    uint32 id = 0;
    uint32 account = 0;
    ObjectGuid::LowType guid = 0;
    uint32 zu = 0;
    uint32 chance = 0;
    std::string name = "";
    std::string ip = "";
};

/*私有属性*/
struct AA_Message {
    Player* target_player = nullptr;
    Item* target_item = nullptr;
    Creature* target_creature = nullptr;
    Item* use_item = nullptr;
    Creature* use_creature = nullptr;
};

struct AA_Duihuanma {
    std::string cdk = "";
    uint32 zu = 0;
    uint32 need = 0;
    uint32 reward = 0;
    std::string guid = "";
    std::string account = "";
    std::string ip = "";
    uint32 time = 0;
    uint32 notice = 0;
};

struct AA_Duihuanma_Conf {
    uint32 zu = 0;
    ObjectGuid::LowType guid = 0;
    uint32 account = 0;
    uint32 ip = 0;
};

struct AA_PaihangX {
    uint32 id = 0;
    std::string type = "";
    std::string type_diy_guid = "";
    std::string type_diy_account = "";
    int32 value = 0;
    uint32 reward = 0;
    std::string auras = "";
    uint32 notice = 0;
};
//1.金币排行：只计算单个角色背包内金币的数量；
//2.生命排行：只计算单个角色穿着装备后最终生命的数值进行排行；
//3.装等排行：只计算以单个角色全身装备物品等级总和的数值进行排行；
//4.成就排行：只计算单个角色成就个数的排行；
//5.声望排行：只计算单个角色成就点数排行；
//6.斗气排行：只计算单个角色斗气等级排行
//7.积分排行：只计算单个角色持有充值积分的数量排行
//8.在线时间：只计算单个角色在线时间排行
//9.击杀排行：只计算单个角色击杀玩家个数排行
//10.自定义排行
struct AA_Paihang { //军衔等级，斗气等级，巅峰等级，今日累充，今日首充，累计积分排行，
    std::vector<std::pair<ObjectGuid, uint32>> aa_money;
    std::vector<std::pair<ObjectGuid, uint32>> aa_health;
    std::vector<std::pair<ObjectGuid, uint32>> aa_zaixianshijian;
    std::vector<std::pair<ObjectGuid, uint32>> aa_jisha;
    std::vector<std::pair<ObjectGuid, uint32>> aa_jx_level;
    std::vector<std::pair<ObjectGuid, uint32>> aa_dq_level;
    std::vector<std::pair<ObjectGuid, uint32>> aa_df_level;
    std::vector<std::pair<ObjectGuid, uint32>> aa_leichong;
    std::vector<std::pair<ObjectGuid, uint32>> aa_jinrileichong;
    std::vector<std::pair<ObjectGuid, uint32>> aa_renwu;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_ItemLevel;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_Quality;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_jd;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_qh;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_cz;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_jxsx;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_item_jxjn;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_pet_jh;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_pet_qh;
    std::vector<std::pair<ObjectGuid, uint32>> aa_level_pet_jx;
    std::map< std::string, std::vector<std::pair<ObjectGuid, uint32>> > aa_diy_guids;
    std::map< std::string, std::vector<std::pair<ObjectGuid, uint32>> > aa_diy_accounts;
    bool isOk = false;
};
//`注释` varchar(255) DEFAULT NULL,
//`id` int unsigned NOT NULL DEFAULT '0' COMMENT '系统id',
//`组` int unsigned NOT NULL DEFAULT '0' COMMENT '抽奖需求',
//`几率` int unsigned NOT NULL DEFAULT '100' COMMENT '每日领取奖励',
//`显示物品id` int unsigned NOT NULL DEFAULT '100',
//`实际抽奖奖励` int unsigned NOT NULL DEFAULT '0',
//`抽奖公告` int unsigned NOT NULL DEFAULT '0',
struct AA_Choujiang {
    uint32 id = 0;
    uint32 zu = 0;
    uint32 chance = 0;
    uint32 itemid = 0;
    uint32 reward = 0;
    uint32 notice = 0;
};

struct AA_Buy_Time {
    uint32 entry = 0;
    uint32 buy_a = 0;
    uint32 buy_c = 0;
    uint32 yongjiu_a = 0;
    uint32 yongjiu_c = 0;
};

//`id` int unsigned NOT NULL DEFAULT '0' COMMENT '战场id,2为战歌 3为阿拉希 7为暴风之眼',
//`game_event` int unsigned NOT NULL DEFAULT '0',
//`距离事件开始时间` int unsigned NOT NULL DEFAULT '0' COMMENT '单位：秒，距离事件开始显示在活动列表中',
//`活动标题` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT '',
//`活动子标题` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT '',
//`活动说明` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT '',
//`活动图标` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT '',
//`接受需求` int unsigned NOT NULL DEFAULT '0' COMMENT '_模板_需求',
//`接受奖励` int unsigned NOT NULL DEFAULT '0' COMMENT '_模板_奖励',
//`允许重复接受`
struct AA_Huodong_Conf {
    uint32 id = 0;
    uint32 game_event = 0;
    uint32 time = 0;
    std::string name = "";
    std::string title = "";
    std::string icon = "";
    std::string button = "";
    uint32 need = 0;
    uint32 reward = 0;
};

struct AA_Fanpai {
    uint32 id = 0;//`id` int unsigned NOT NULL DEFAULT '0' COMMENT '系统id',
    uint32 zu = 0;//`组` int unsigned NOT NULL DEFAULT '0',
    uint32 chance = 0;//`几率` int unsigned NOT NULL DEFAULT '100',
    uint32 itemid = 0;//`显示物品id` int unsigned NOT NULL DEFAULT '0',
    std::string gm = "";//`奖励GM命令` int unsigned NOT NULL DEFAULT '0',
};

struct AA_Player_Map_Value {
    ObjectGuid::LowType guidlow = 0;
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Player_Zone_Value {
    ObjectGuid::LowType guidlow = 0;
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Player_Area_Value {
    ObjectGuid::LowType guidlow = 0;
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Player_Instance_Value {
    ObjectGuid::LowType guidlow = 0;
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Map_Map_Value {
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Map_Zone_Value {
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Map_Area_Value {
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};
struct AA_Map_Instance_Value {
    int32 mapid = 0;
    std::string valueb = "";
    std::string valuev = "";
    uint32 update_time = 0;
    bool isUpdate = false;
};

class AACenter
{
public:
    ~AACenter() {
        std::cout << "destructor called!" << std::endl;
    }
    AACenter(const AACenter&) = delete;
    AACenter& operator=(const AACenter&) = delete;
    static AACenter& get_instance() {
        static AACenter instance;
        return instance;
    }

    AA_Version aa_version;

    void Update(Unit* unit, uint32 diff);

    //技能光环相关
    std::unordered_map<uint32, AA_AuraId_Conf> aa_auraid_confs;
    std::unordered_map<uint32, std::vector<uint32>> aa_auraid_conf_zus;
    std::unordered_map<uint32, AA_SpellId_Conf> aa_spellid_confs;
    std::unordered_map<uint32, std::vector<uint32>> aa_spellid_conf_zus;

    //自定义阵营
    std::unordered_map<int32, AA_Diy_Duel> aa_diy_duels;

    //系统自动组队
    std::unordered_map<int32, std::set<Group *>> aa_groups;
    std::unordered_map<uint32, AA_Xitong_Group> aa_xitong_groups;

    //获取物品属性数量
    uint32 AA_GetItemValueCount(uint32 entry);

    //弹窗翻牌
    std::unordered_map<uint64, uint32> aa_fanpai_tanchuang1; //防封包，弹窗的才可以翻
    std::unordered_map<uint64, uint32> aa_fanpai_tanchuang2; //防封包，弹窗的才可以翻
    std::unordered_map<uint64, uint32> aa_fanpai_tanchuang3; //防封包，弹窗的才可以翻
    std::unordered_map<uint64, std::unordered_map<ObjectGuid::LowType, std::vector<uint32>>> aa_fanpai_pai; //已经翻过，不能再翻

    //变身
    std::unordered_map<ObjectGuid::LowType, uint32> aa_bianshen1;
    std::unordered_map<ObjectGuid::LowType, float> aa_bianshen2;
    std::unordered_map<ObjectGuid::LowType, uint32> aa_bianshen3; //变身时长

    //副本难度
    //临时传送变量
    //个人变量 {mapid, {guidlow, {0,次数} } }  Key=mapid value={0=角色死亡次数}
    std::unordered_map<int32, std::unordered_map<ObjectGuid::LowType, AA_Player_Map_Value>> aa_player_map_values;
    std::unordered_map<int32, std::unordered_map<ObjectGuid::LowType, AA_Player_Zone_Value>> aa_player_zone_values;
    std::unordered_map<int32, std::unordered_map<ObjectGuid::LowType, AA_Player_Area_Value>> aa_player_area_values;
    std::unordered_map<int32, std::unordered_map<ObjectGuid::LowType, AA_Player_Instance_Value>> aa_player_instance_values;

    std::unordered_map<int32, AA_Map_Map_Value> aa_map_map_values;
    std::unordered_map<int32, AA_Map_Zone_Value> aa_map_zone_values;
    std::unordered_map<int32, AA_Map_Area_Value> aa_map_area_values;
    std::unordered_map<int32, AA_Map_Instance_Value> aa_map_instance_values;

    std::map<int32, std::map<int32, int32>> aa_mmapvalues;
    std::map<int32, std::map<int32, int32>> aa_mzonevalues;
    std::map<int32, std::map<int32, int32>> aa_mareavalues;
    std::map<int32, std::map<int32, int32>> aa_minstancevalues;

    std::map<int32, std::map<int32, int32>> aa_mmapbools;
    std::map<int32, std::map<int32, int32>> aa_mzonebools;
    std::map<int32, std::map<int32, int32>> aa_mareabools;
    std::map<int32, std::map<int32, int32>> aa_minstancebools;

    std::map<int32, std::map<int32, std::map<int32, int32>>> aa_pmapvalues;
    std::map<int32, std::map<int32, std::map<int32, int32>>> aa_pzonevalues;
    std::map<int32, std::map<int32, std::map<int32, int32>>> aa_pareavalues;
    std::map<int32, std::map<int32, std::map<int32, int32>>> aa_pinstancevalues;

    std::map<int32, std::map<ObjectGuid::LowType, std::map<int32, int32>>> aa_pmapbools;
    std::map<int32, std::map<ObjectGuid::LowType, std::map<int32, int32>>> aa_pzonebools;
    std::map<int32, std::map<ObjectGuid::LowType, std::map<int32, int32>>> aa_pareabools;
    std::map<int32, std::map<ObjectGuid::LowType, std::map<int32, int32>>> aa_pinstancebools;

    void AA_UpdateValueBools(int32 mapid, uint32 moshi, bool isValue, ObjectGuid::LowType guidlow = 0);

    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_map_values;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_zone_values;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_area_values;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_instance_values;
    //    // {mapid, {0 ,{id bool} }   id0 进度领取状态
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_map_bools;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_zone_bools;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_area_bools;
    //    std::map<uint32, std::map<uint32, std::map<int32, int32>>> aa_player_instance_bools;
    //    
    //    //地图变量 Key=mapid value=(0confid 1已挑战时间 2已获得地图进度经验 3区域模式 4难度)
    //    std::map<uint32, std::map<int32, int32>> aa_map_map_values;
    //    std::map<uint32, std::map<int32, int32>> aa_map_zone_values;
    //    std::map<uint32, std::map<int32, int32>> aa_map_area_values;
    //    std::map<uint32, std::map<int32, int32>> aa_map_instance_values;
    //    // {mapid, {0 ,{id bool} }
    //    std::map<uint32, std::map<int32, int32>> aa_map_map_bools;
    //    std::map<uint32, std::map<int32, int32>> aa_map_zone_bools;
    //    std::map<uint32, std::map<int32, int32>> aa_map_area_bools;
    //    std::map<uint32, std::map<int32, int32>> aa_map_instance_bools;
        //获取AA_Map_Player_Conf
    AA_Map_Player_Conf AA_GetAA_Map_Player_Conf(WorldObject* object);
    //
    //
    //副本模式 5 10 25 -5 -10 -25
    /*
     DUNGEON_DIFFICULTY_NORMAL    = 1, 5人
     DUNGEON_DIFFICULTY_HEROIC    = 2, 5人英雄

     RAID_DIFFICULTY_10MAN_NORMAL = 1, 10人
     RAID_DIFFICULTY_25MAN_NORMAL = 2, 25人
     RAID_DIFFICULTY_10MAN_HEROIC = 3, 10人英雄
     RAID_DIFFICULTY_25MAN_HEROIC = 4, 25人英雄
     */

     //地图中的累计在线时间  <map ,<nandu, time>>
    std::unordered_map<uint32, std::unordered_map<uint32, uint32> > aa_map_times;

    /*DB*/
    void DeleteAAData_Characters();
    void LoadAAData_Characters();
    void LoadAAData_World();
    void LoadAAData_Jindu();

    /*采集*/
    std::unordered_map<uint32, AA_Caiji_Item> aa_caiji_items;
    std::unordered_map<uint32, std::vector<uint32>> aa_caiji_item_zus;
    std::unordered_map<uint32, AA_Caiji_Zuobiao> aa_caiji_zuobiaos;
    std::unordered_map<uint32, std::vector<uint32>> aa_caiji_zuobiao_zus;
    std::unordered_map<uint32, AA_Caiji_Creature> aa_caiji_creatures;
    std::unordered_map<uint32, std::vector<uint32>> aa_caiji_creature_zus;
    std::unordered_map<uint32, AA_Caiji_Player> aa_caiji_players;

    /*value*/
    //鉴定、强化、成长、重铸相关
    std::unordered_map<uint32, AA_Aura_Conf> aa_aura_confs;
    std::unordered_map<uint32, std::vector<uint32>> aa_aura_conf_zus;
    std::unordered_map<uint32, std::set<uint32>> aa_aura_conf_spell_pvps;
    std::unordered_map<uint32, std::set<uint32>> aa_aura_conf_spell_pves;
    std::unordered_map<uint32, std::set<uint32>> aa_aura_conf_heal_pvps;
    std::unordered_map<uint32, std::set<uint32>> aa_aura_conf_heal_pves;
    std::set<uint32> aa_aura_conf_dies;
    std::unordered_map<uint32, AA_Jianding_Item> aa_jianding_items;
    std::unordered_map<uint32, AA_Qianghua_Item> aa_qianghua_items;
    //<group, <type, conf>>
    std::unordered_map<uint32, AA_Stat> aa_stats;
    std::unordered_map<uint32, AA_Stat_Xianzhi> aa_stat_xianzhis;
    std::unordered_map<uint32, std::vector<uint32>> aa_stat_zus;
    std::unordered_map<uint32, std::unordered_map<uint32, uint32>> aa_stat_types;  //zu type = id
    //<group, <id, conf>>
    std::unordered_map<uint32, AA_Spell> aa_spells;
    std::set<uint32> aa_spell_values; //所有带属性的物品技能
    std::unordered_map<uint32, std::vector<uint32>> aa_spell_zus;
    std::unordered_map<ObjectGuid, std::vector<uint32> > aa_allspells1; //所有技能
    std::unordered_map<ObjectGuid, std::set<uint32> > aa_allspells; //所有技能
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, std::vector<uint32>> > aa_allsetspells_old; //所有套装技能
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, std::vector<uint32>> > aa_allsetspells_new; //所有套装技能
    std::unordered_map<ObjectGuid, std::unordered_map<ObjectGuid::LowType, std::vector<uint32> >> aa_allitemspells1; //所有物品技能
    std::unordered_map<ObjectGuid ,std::unordered_map<ObjectGuid::LowType, std::set<uint32> >> aa_allitemspells; //所有物品技能
    std::unordered_map<uint32, AA_Item_Upgrade> aa_item_upgrades;
    std::unordered_map<uint32, std::vector<uint32>> aa_item_upgrade_zus;
    std::unordered_map<uint32, AA_Item_Level> aa_item_levels;
    std::unordered_map<uint32, std::vector<uint32>> aa_item_level_zus;
    std::unordered_map<uint32, AA_Item_Nonsuch> aa_item_nonsuchs;
    std::unordered_map<uint32, std::vector<uint32>> aa_item_nonsuch_zus;
    std::unordered_map<uint32, AA_Item_Nonsuch_Id> aa_item_nonsuch_ids;
    std::unordered_map<uint32, AA_Realmlist> aa_realmlists;
    std::unordered_map<uint32, AA_Item_NoJianding> aa_item_nojiandings;
    std::unordered_map<uint32, std::vector<AA_CreatureTemplate>> aa_creature_templates;
    std::unordered_map<uint32, AA_Spell_Conf> aa_spell_confs;
    std::unordered_map<std::string, AA_Chat> aa_chats;
    std::unordered_map<uint32, AA_Liansha> aa_lianshas;
    std::set<std::string> aa_battleground_ips;
    std::unordered_map<uint32, AA_Zhuanzhi_Spell> aa_zhuanzhi_spells;
    std::unordered_map<uint32, AA_Chengzhang_Item> aa_chengzhang_items;
    std::unordered_map<uint32, AA_Cuiqu_Item> aa_cuiqu_items;
    std::unordered_map<uint32, AA_Hecheng_Conf> aa_hecheng_confs;
    std::unordered_map<uint32, AA_Chaixie_Conf> aa_chaixie_confs;
    std::unordered_map<uint32, AA_Jiebang_Conf> aa_jiebang_confs;
    std::unordered_map<uint32, AA_Boss_Conf> aa_boss_confs;
    std::unordered_map<ObjectGuid::LowType, AA_Characters_Douqi> aa_characters_douqis;
    std::unordered_map<ObjectGuid::LowType, AA_Characters_Junxian> aa_characters_junxians;
    std::unordered_map<ObjectGuid::LowType, AA_Characters_Dianfeng> aa_characters_dianfengs;
    std::unordered_map<uint32, AA_Baoshi_Conf> aa_baoshi_confs;
    std::unordered_map<uint32, AA_Fw_Conf> aa_fw_confs;
    std::unordered_map<uint32, AA_FwZh_Conf> aa_fwzh_confs;
    std::unordered_map<uint32, AA_World_Conf> aa_world_confs;
    std::unordered_map<uint32, AA_Desktop_Conf> aa_desktop_confs;
    std::vector<uint32> aa_desktops;
    std::unordered_map<uint32, AA_Reward_Level_Conf> aa_reward_level_confs;
    std::vector<uint32> aa_reward_levels;
    std::unordered_map<uint32, AA_Reward_Shouchong_Conf> aa_reward_shouchong_confs;
    std::vector<uint32> aa_reward_shouchongs;
    std::unordered_map<uint32, AA_Reward_Licai_Conf> aa_reward_licai_confs;
    std::vector<uint32> aa_reward_licais;
    std::unordered_map<uint32, AA_Reward_Leiji_Conf> aa_reward_leiji_confs;
    std::vector<uint32> aa_reward_leijis;
    std::unordered_map<uint32, AA_Reward_Qiandao_Conf> aa_reward_qiandao_confs;
    std::vector<uint32> aa_reward_qiandaos;
    std::unordered_map<uint32, AA_Huishou_Conf> aa_huishou_confs;
    std::unordered_map<uint32, uint32> aa_huishou_entrys;
    std::vector<uint32> aa_huishou_desc;
    std::unordered_map<uint32, AA_Account> aa_accounts;
    AA_System aa_system_conf;
    std::map<ObjectGuid::LowType, AA_Character_Juanxian> aa_character_juanxians;
    std::unordered_map<ObjectGuid::LowType, AA_Characters> aa_characterss;
    std::unordered_map<uint32, AA_Vip_Conf> aa_vip_confs;
    std::unordered_map<uint32, AA_Douqi_Conf> aa_douqi_confs;
    std::unordered_map<uint32, AA_Junxian_Conf> aa_junxian_confs;
    std::unordered_map<uint32, AA_Dianfeng_Conf> aa_dianfeng_confs;
    std::unordered_map<uint32, AA_Need_Conf> aa_needs;
    std::unordered_map<uint32, AA_Reward_Conf> aa_rewards;
    std::unordered_map<ObjectGuid::LowType, AA_Character_Instance> aa_character_instances;
    std::unordered_map<uint32, std::set<uint32>> aa_character_instance_ids;
    std::unordered_map<ObjectGuid::LowType, std::vector<uint32>> aa_character_instance_owner;
    std::unordered_map<uint32, AA_Notice> aa_notices;
    std::unordered_map<uint32, AA_Teleport_Conf> aa_teleports;
    std::unordered_map<uint32, std::vector<uint32>> aa_teleport_targets;
    std::unordered_map<uint32, AA_Creature> aa_creatures;
    std::unordered_map<uint32, std::vector<AA_Creature>> aa_creature_zus;
    std::unordered_map<uint32, AA_Object> aa_objects;
    std::unordered_map<uint32, std::vector<AA_Object>> aa_object_zus;
    std::unordered_map<uint32, AA_Item> aa_items;
    std::unordered_map<uint32, AA_Map_Player_Conf> aa_map_player_confs;
    //副本-   [区域][模式][难度][队伍人数]
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>> aa_map_player_conf_areas;
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>> aa_map_player_conf_zones;
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>> aa_map_player_conf_maps;
    std::unordered_map <std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>> aa_map_player_conf_alls;
    //野外-   [区域]
    std::unordered_map < uint32, uint32> aa_map_player_conf_yewai_areas;
    std::unordered_map < uint32, uint32> aa_map_player_conf_yewai_zones;
    std::unordered_map < uint32, uint32> aa_map_player_conf_yewai_maps;
    uint32 aa_map_player_conf_yewai_all_id = 0;
    // 宠物部分
    std::unordered_map<uint32, AA_Pet_Conf> aa_pet_confs;
    std::unordered_map<uint32, AA_Pet_Spell> aa_pet_spells;
    std::unordered_map<uint32, std::vector<AA_Pet_Spell>> aa_pet_spell_group;

    std::unordered_map<uint32, AA_Player_Stats_Conf> aa_player_stats_confs;
    //[区域][class][id]
    std::unordered_map<uint32, std::unordered_map<uint8, uint32>> aa_player_stats_conf_areas;
    std::unordered_map<uint32, std::unordered_map<uint8, uint32>> aa_player_stats_conf_zones;
    std::unordered_map<uint32, std::unordered_map<uint8, uint32>> aa_player_stats_conf_maps;
    std::unordered_map<uint8, uint32> aa_player_stats_conf_alls;
    //弹窗
    std::unordered_map<uint32, AA_Event_GameEvent> aa_event_gameevents;
    std::unordered_map<std::string, std::vector<AA_Event_Map>> aa_event_maps;
    std::vector<AA_Event_Playtime> aa_event_playtimes;
    std::unordered_map<uint32, AA_Event_Conf> aa_event_confs;
    std::unordered_map<uint32, std::unordered_map<uint32, uint32>> aa_event_stats;
    std::unordered_map<uint32, AA_Caiji_Zuobiao> aa_event_senders;

    // 百团大战
    std::unordered_map<uint32, std::unordered_map<uint32, AA_Battleground_Conf> > aa_battleground_confs;
    std::unordered_map<uint32, uint32> aa_battleground_events;

    std::unordered_map<ObjectGuid, ObjectGuid> aa_vendor_guid;
    std::unordered_map<uint32, AA_Item_Bag> aa_item_bags;
    std::unordered_map<uint32, AA_Item_Use_Need> aa_item_use_needs;
    std::unordered_map<uint32, AA_Item_Use_Reward> aa_item_use_rewards;
    std::unordered_map<uint32, std::unordered_map<uint32, AA_Item_Buy_Need>> aa_item_buy_needs;
    std::unordered_map<uint32, AA_Item_Buy_Reward> aa_item_buy_rewards;
    std::unordered_map<uint32, AA_Item_Jianding_Buy> aa_item_jianding_buys;
    std::unordered_map<uint32, AA_Item_Jianding_Cz> aa_item_jianding_czs;
    std::unordered_map<uint32, AA_Item_Jianding_Xl> aa_item_jianding_xls;
    std::unordered_map<uint32, AA_Item_Qh_Id> aa_item_qh_ids;
    std::unordered_map<uint32, AA_Item_Level_Id> aa_item_level_ids;
    std::unordered_map<uint32, std::unordered_map<uint32, AA_Creature_Id>> aa_creature_ids;
    std::unordered_map<uint32, AA_Creature_Map> aa_creature_maps;
    //副本-   [区域][模式][生物类型][难度][队伍人数]
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>>> aa_creature_map_areas;
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>>> aa_creature_map_zones;
    std::unordered_map < uint32, std::unordered_map < std::string, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>>> aa_creature_map_maps;
    std::unordered_map <std::string, std::unordered_map < std::string, std::unordered_map < uint32, std::unordered_map < uint32, uint32>>>> aa_creature_map_alls;
    //野外-   [区域]
    std::unordered_map < uint32, std::unordered_map < std::string, uint32>> aa_creature_map_yewai_areas;
    std::unordered_map < uint32, std::unordered_map < std::string, uint32>> aa_creature_map_yewai_zones;
    std::unordered_map < uint32, std::unordered_map < std::string, uint32>> aa_creature_map_yewai_maps;
    std::unordered_map < std::string, uint32> aa_creature_map_yewai_alls;

    std::unordered_map<uint32, std::unordered_map<uint32, AA_Object_Id>> aa_object_ids;
    std::unordered_map<uint32, AA_Creature_Exp> aa_creature_exps;
    /*Ai*/
    std::unordered_map<uint32, AA_Ai> aa_ais;
    std::unordered_map<uint32, std::set<uint32>> aa_ai_zus;
    std::unordered_map<uint32, AA_Ai_Pet> aa_ai_pets;
    std::unordered_map<uint32, AA_Ai_Item> aa_ai_items;
    std::unordered_map<uint32, AA_Ai_Creature> aa_ai_creatures;
    std::unordered_map<uint32, AA_Ai_Spell> aa_ai_spells;
    std::unordered_map<uint32, AA_Ai_Spell_Learn> aa_ai_spell_learns;
    std::unordered_map<uint32, AA_Ai_Spell_Item> aa_ai_spell_items;
    std::vector<AA_Ai_Map> aa_ai_maps;
    //所有有效物品
    std::unordered_map<ObjectGuid, std::vector<uint32>> aa_allitems1;
    std::unordered_map<ObjectGuid, std::set<uint32>> aa_allitems;
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, std::vector<ObjectGuid::LowType>>> aa_allsetitems1;
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, std::set<ObjectGuid::LowType>>> aa_allsetitems;
    /*定制*/
    std::map<uint32, AA_Fanpai> aa_fanpais;
    std::unordered_map<uint32, std::vector<uint32>> aa_fanpai_zus;
    std::map<uint32, AA_Huodong_Conf> aa_huodong_confs;
    std::unordered_map<uint32, AA_Buy_Time> aa_buy_times;
    std::vector<std::string> aa_choujiangStrs;
    std::unordered_map<uint32, AA_Choujiang> aa_choujiangs;
    std::unordered_map<uint32, std::vector<uint32>> aa_choujiang_zus;
    bool AA_VerifyCode(std::string code);
    std::unordered_map<uint32, uint32> aa_boss_time;
    void M_SendMap_Jindu(Player* p);
    void M_SendBoss_Paihang(std::list<Player*> list, Creature* creture, std::vector<std::pair<ObjectGuid, uint32>> aa_boss_dmg);
    std::unordered_map<std::string, AA_Duihuanma> aa_duihuanmas;
    std::unordered_map<uint32, AA_Duihuanma_Conf> aa_duihuanma_confs;
    std::unordered_map<uint32, std::unordered_map<std::string, AA_PaihangX>> aa_paihangxs;
    std::unordered_map<uint32, std::unordered_map<std::string, AA_PaihangX>> aa_paihangx_guids;
    std::unordered_map<uint32, std::unordered_map<std::string, AA_PaihangX>> aa_paihangx_accounts;
    AA_Paihang AA_GetPaihangs();
    std::string AA_GetPaihangInfo(std::string& message, AA_Paihang conf);
    void AA_PaihangReward(bool isAura = false);
    /*
     获取颜色的文字
     */
    std::string aa_color_blue = "|cff00FFFF";    //--浅蓝
    std::string aa_color_blues = "|cff7788FF";    //--深蓝
    std::string aa_color_green = "|cff00FF00";    //--绿色
    std::string aa_color_yellow = "|cffFFFF00";    //--黄色
    std::string aa_color_yellows = "|cffF0B42A";    //--暗金
    std::string aa_color_red = "|cffFF0000";    //--深红
    std::string aa_color_reds = "|cffFF00FF";    //--紫色
    std::string aa_color_white = "|cffFFFFFF";    //--白色
    std::string aa_color_red1 = "|cffb05598";    //--粉色
    std::string aa_color_blue1 = "|cff6d4492";    //--蓝紫


    /*工具*/
    void AA_SendMessage(Player* p, int type, const char* Text, ...);

    /*map*/
    //功能：find函数返回map的value值，如果找不到返回0
    uint32 AA_FindMapValueUint32(std::map<uint32, uint32> m, uint32 key);
    /*string*/
    //功 能：大写字母转小写
    void AA_StringToLower(std::string& s);
    //功 能：float保留两位小数
    std::string AA_StringFromFloat(const float dbNum);
    //功 能：将s字符串以c为分隔符，转换为v数组
    void AA_StringToVectorString(const std::string s, std::vector<std::string>& v, const std::string c);
    void AA_StringToVectorInt(const std::string s, std::vector<int32>& v, const std::string c);
    void AA_StringToVectorFloat(const std::string s, std::vector<float>& v, const std::string c);
    void AA_VectorIntToString(std::string& s, const std::vector<int32> v, const std::string c);
    void AA_VectorStringToString(std::string& s, const std::vector<std::string> v, const std::string c);
    //功 能：将s字符串以c为分隔符，转换为v数组，并获得其中一个
    uint32 AA_StringRandom(const std::string& s);
    //功 能：将a b,a b格式，转化为两个数组
    void AA_FugaiStringToVector(const std::string s, std::vector<int32>& v1, std::vector<int32>& v2, std::vector<int32>& v3, std::vector<int32>& v4);
    void AA_StringToVectorFloat(const std::string s, std::vector<float>& v1, std::vector<float>& v2);
    void AA_StringToVector2(const std::string s, std::vector<int32>& v1, std::vector<int32>& v2);
    void AA_StringToVector3(const std::string s, std::vector<std::string>& v1, std::vector<std::string>& v2);
    void AA_VectorToString(std::string& s, const std::vector<int32>& v1, const std::vector<int32>& v2);
    void AA_VectorToStringSort(std::string& s, const std::vector<int32>& v1, const std::vector<int32>& v2);
    //功 能：将s转化为map
    void AA_StringToMap(const std::string s, std::map<int32, int32>& m);
    void AA_StringToMapFloat(const std::string s, std::map<float, float>& m);
    void AA_StringToStringMap(const std::string s, std::map<std::string, std::string>& m);
    //功 能：将map转化为string
    void AA_MapToString(const std::map<int32, int32> m, std::string& s);
    void AA_StringMapToString(const std::map<std::string, std::string> m, std::string& s);
    //功 能：将s1中的全部s2替换为s3
    void AA_StringReplace(std::string& s1, const std::string& s2, const std::string& s3);
    void AA_StringReplaceFirst(std::string& s1, const std::string& s2, const std::string& s3);
    void AA_StringReplaceLast(std::string& s1, const std::string& s2, const std::string& s3);
    //功 能：string 转 uint32
    float AA_StringFloat(std::string s);
    int32 AA_StringInt32(std::string s);
    uint32 AA_StringUint32(std::string s);
    uint64 AA_StringUint64(std::string s);
    //功 能：截取s1中 s2到s3中间的字符串
    std::string AA_StringGet(std::string& s1, const std::string& s2, const std::string& s3);
    //功 能：字符串a 是否包含字符串b
    bool AA_StringHasString(std::string s1, std::string s2);

    std::string AA_GetRewardText(uint32 rewardid, uint32 count = 1);
    std::string AA_GetNeedText(uint32 needid, uint32 count = 1);

    /*item*/
    Item* AA_AddItem(Player* player, uint32 itemId, uint32 count);
    std::string AA_GetItemName(Item* item);
    std::string AA_GetItemLink(uint32 itemid);
    std::string AA_GetItemLinkJd(Item* item);
    std::string AA_GetMoneyLink(uint32 money);
    std::set<uint32> M_GetAllItemSpell(ObjectGuid::LowType guidlow); // 获取某装备的所有技能
    bool AA_UnequipItem(Player* player, Item* item); //取下装备
    uint32 AA_GetRealItemGuid(uint32 id, uint32 entry);

    /*bag*/
    uint8 AA_GetEmptyBag(Player* player);
    bool AA_IsShenQiItem(Item const* pItem);

    /*objectmgr*/
    void AA_SendNotice(Unit* player, AA_Notice notice, bool succes, AA_Message aa_message);

    /*account*/
    //获取同ip下的战场是否有账号
    bool AA_HasBattlegroundIp(Player* player);

    /*Ai*/
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, uint32>> m_aiTimes; //<玩家guid, <aiid, 冷却时间> >
    std::unordered_map<ObjectGuid, std::unordered_map<uint32, uint32>> m_aiGGTimes; //<玩家guid, <冷却组, 冷却时间> >
    std::set<uint32> AA_GetAis(Unit* attacker, std::string eventtype);
    void AA_AiStart(Unit* attacker, Unit* victim, uint32 aiint, int32 value = 0, bool isOk = false);
    std::set<Creature*> m_ai_creatures;

    /*弹窗*/
    void AA_EventMapStart(Player* eventer, AA_Event_Map conf);
    bool AA_EventStart(Player* eventer, uint32 eventid);
    void AA_SendEvent(Player* player, std::string title, std::string text, uint32 id = 0, ObjectGuid guid = ObjectGuid::Empty);
    void AA_CallBack_Event(Player* eventer, uint32 eventid, uint32 timep, uint32 button);

    /*player*/
    bool AA_TeleportDied(Player* player);
    AA_Player_Stats_Conf AA_GetPlayerStatConfWithMap(Unit const* unit);
    std::string GetMyInfo(Unit* me, std::string message, AA_Message aa_message, bool nnn = false);
    bool AA_HasItemInBagCount(Player* player, uint32 item, uint32 count, uint32 bag = 0) const;
    void AA_DestroyItemInBagCount(Player* player, uint32 itemEntry, uint32 count, bool update, bool unequip_check);
    std::set<Creature*> AA_GetCreatureRange(Player* me, std::string gm);
    std::set<Player*> AA_GetPlayerRange(Player* me, std::string gm);
    std::string AA_GetPlayerColor(Player* player);
    std::string AA_GetPlayerNameLink(Player* player);
    void AA_ApplyItemBonuses(Player* player, Item* pItem, bool apply, bool isShuangjia = false);
    bool AA_DoCommand(Player* player, char const* text);
    bool M_CanNeed(Player* player, uint32 needid, uint32 count = 1, bool notice = true, ObjectGuid::LowType itemGuidlow = 0);
    bool M_CanNeedDo(Player* player, std::string& needstr, uint32 needid, uint32 count = 1, ObjectGuid::LowType itemGuidlow = 0);
    void M_Need(Player* player, uint32 needid, uint32 count = 1);
    bool M_Reward(Player* player, uint32 rewardid, uint32 count = 1);
    void M_RewardDo(Player* player, uint32 rewardid, uint32 count = 1);
    Item* GetItemByGUIDLow(Player* player, ObjectGuid::LowType guid);
    //    void M_NonsuchItem(Player *player, Item* pItem, uint32 nonsuch_group, bool isInit, uint32 nonsuch_id = 0);
    uint32 M_NonsuchItem(Player* player, Item* pItem, uint32 zu, int32 type);
    void M_NonsuchItemJipin(Player* player, Item* pItem, uint32 nonsuchId, int32 type);
    bool M_NonsuchItemFmValue(Player* player, Item* pItem, uint32 nonsuchId, int32 type);
    bool M_NonsuchItemFmSpell(Player* player, Item* pItem, uint32 nonsuchId, int32 type);
    bool M_NonsuchItemSet(Player* player, Item* pItem, uint32 nonsuchId, int32 type);
    void M_UpgradeItem(Player* player, Item* pItem, uint32 qhjlevel = 0);
    void M_CleanUpgradeItem(Item* pItem);
    void M_LevelItem(Player* player, Item* pItem);
    void M_ChangeItemName(Player* player, Item* pItem, std::string name);
    void M_GetSpellText(Player* player, std::vector<uint32> spellIds, std::vector<uint32> spellTimes);
    void M_GetItemText(Player* player, std::vector<uint32> itemIds, std::vector<uint32> itemEntrys, std::vector<uint32> itemTimes);
    void M_GetItemTextPet(Player* player, std::vector<uint32> itemIds, std::vector<uint32> itemEntrys, std::vector<uint32> itemTimes);
    void M_SendAA_Conf(Player* player, std::string type);
    std::string M_GetItemTemplateGuid(Player* player, std::vector<uint32> itemGuids, std::vector<uint32> itemEntrys);
    std::string M_GetItemTemplate(std::set<uint32> itemIds);
    Item* GetEquipItemByEntry(Player* player, uint32 entry);
    uint32 GetAll_level_item_ItemLevel(Player* player);
    uint32 GetAll_level_item_Quality(Player* player);
    uint32 GetAll_level_item_jd(Player* player);
    uint32 GetAll_level_item_qh(Player* player);
    uint32 GetAll_level_item_cz(Player* player);
    uint32 GetAll_level_item_jxsx(Player* player);
    uint32 GetAll_level_item_jxjn(Player* player);
    bool M_SendClientAddonData(Player* player, std::string command, std::string msg);
    void GiveJXXP(Player* player, uint32 xp);
    void GiveDQXP(Player* player, uint32 xp);
    void GiveDFXP(Player* player, uint32 xp);
    bool GiveCZXP(Player* player, uint32 xp, Item* pItem = nullptr);
    void AddValue(Player* player, uint32 statType, int32 val, bool apply);
    std::set<Item*> M_GetBankItems(Player* player);
    std::set<Item*> M_GetBagItems(Player* player);
    std::set<Item*> M_GetEquipItems(Player* player);
    std::set<Item*> M_GetBagAndEquipItems(Player* player);
    std::set<Item*> M_GetBagAndEquipAndBankItems(Player* player);

    void AA_TelScript(Player* player, AA_Teleport_Conf conf, Item *item = nullptr);
    void AA_ReceiveAddon(Player* player, std::string& prefix, std::string& receivemsg);
    std::string GetPlayerClass(uint8 class1);
    std::string GetPlayerRace(Player* player);
    std::string GetPlayerFaction(Player* player);
    void AA_ModifySpellCooldown(Player* caster, SpellInfo const* spellInfo, int32 cooldown);

    /*creature*/
    AA_Object AA_GetGameObjectConf(GameObject* gameObject, GameObjectTemplate const* goinfo);
    AA_Creature AA_GetCreatureConf(Creature* creature);
    void AA_ModifyCreature(Creature* creature, AA_Creature conf);
    void AA_ModifyGameObject(GameObject* gameObject, AA_Object conf);
    uint32 AA_GetCreatureRandomEntry(uint32 entry);

    /*拍卖行*/
    std::string AA_GetAuctionUnit();
    uint32 AA_GetAuctionMoney(Player* player);
    void AA_AuctionModifyMoney(Player* player, int32 money);
    /*宝石相关*/
    bool AA_HasBaoshi(Player* player, uint32 itemid);//是否拥有宝石id
    bool AA_Chaixie(Player* player, int32 index);//拆卸宝石
    uint32 AA_GetBaoshiEntry(Item* pItem, uint32 index);
    /*符文相关*/
    void M_FuWenKaichao(Player* player, Item* pItem, uint32 count); //符文开槽
    void M_FuWenChaixie(Player* player, Item* pItem, uint32 index, bool clear); //符文拆卸
    void M_FuWenXiangqian(Player* player, Item* pItem, std::vector<int32> fwItems, std::vector<int32> fwEntrys);//符文镶嵌
    std::string M_GetFuWenZuheSpell(ItemTemplate const* pProto, AA_Character_Instance conf); //获取符文组合技能id
    bool AA_HasFwItem(Player* player, uint32 fwid);
    bool AA_IsFuwenItem(Item* pItem);

    //装备合成
    bool AA_Hecheng(Player* player);
    //装备解绑
    bool AA_Jiebang(Player* player);
    //装备成长
    bool AA_Chengzhang_Item_Do(Player* player);
    //装备强化
    bool AA_Qianghua_Item_Do(Player* player);
    //装备鉴定券
    bool AA_Jianding_Item_Do(Player* player);
    //装备回收
    AA_Huishou_Conf AA_GetHuiShouConf(Player* player, ObjectGuid::LowType guidlow, uint32 itemEntry);
    bool AA_Huishou(Player* player);
    std::set<Player*> GetOnlinePlayers();

    //命令相关
    void AA_TeleportMoban(Player* player, uint32 mobanid);

    //定制专区
    std::unordered_map<uint32, uint32> aa_jishas;
    std::unordered_map<uint32, uint32> aa_renwus;
    //    std::string GetPaihangInfo(, std::string message,AA_Message aa_message, bool nnn) {

    //随机副本人数
    uint32 AA_GetMaxGroupSize();
    //lbad
    void BB_GetCreatureListInGrid(WorldObject* object, std::list<Creature*>& lList, float fMaxSearchRange) const;
    void BB_GetCreatureListInMap(WorldObject* object, std::list<Creature*>& lList, int32 mapId) const;
    void BB_GetPlayerListInGrid(WorldObject* object, std::list<Player*>& playerList, float maxSearchRange, bool reqAlive = true) const;

    //阵营平衡光环
    uint32 lmcount = 0;
    uint32 blcount = 0;

    //随机套装
    std::map <uint32, AA_Item_Set> aa_item_sets;
    std::unordered_map <uint32, std::vector<uint32>> aa_item_set_zus;
    std::unordered_map <uint32, AA_Item_Set_Conf> aa_item_set_confs;
    //自定义ui功能区
    std::vector<ObjectGuid::LowType> aa_jijie_guidlows;
    std::vector<uint32> aa_jijie_times;
    std::vector<uint32> aa_jijie_ids;
    std::vector<std::string> aa_jijie_msgs;
    std::map<uint32, AA_UI_Jijie> aa_ui_jijies;
    std::map<uint32, AA_UI_Juanxian_Paiming> aa_ui_juanxian_paimings;
    std::map<uint32, AA_UI_Juanxian_Shuliang> aa_ui_juanxian_shuliangs;
    std::unordered_map<uint32, std::map<uint32, std::map<uint32, AA_UI_Shenqi>>> aa_ui_shenqis;
    std::map<uint32, AA_UI_Shenqi> aa_ui_shenqi_entrys;
    std::unordered_map<uint32, std::map<uint32, AA_UI_Shizhuang>> aa_ui_shizhuangs;
    std::unordered_map<uint32, AA_UI_Chuansong> aa_ui_chuansongs;
    std::unordered_map<uint32, uint32> aa_ui_miyaos;

    //商城x
    std::unordered_map<uint32, AA_Shop> aa_shops;
    std::unordered_map<uint32, std::unordered_map<uint32, std::vector<uint32>>> aa_shop_zus;

    //双甲-魂玉x
    std::unordered_map<ObjectGuid::LowType, AA_Item_Instance> aa_item_instances;
    std::unordered_map<ObjectGuid::LowType, std::vector<ObjectGuid::LowType>> aa_item_instance_owner;
    std::map<uint32, AA_Item_Shuangjia> aa_item_shuangjias;
    bool AA_Item_Shuangjia_Chaixie(Player* player, int32 lan, int32 index, bool destroy = false);
    std::unordered_map<uint32, AA_Item_Shuangjia_Xianzhi> aa_item_shuangjia_xianzhis;

    //ui捐献
    bool AA_UpdateJuanxianPaihang();
    bool AA_UpdateJuanxianShuliang(Player *);
    std::map<ObjectGuid::LowType, uint32> aa_juanxian_players;
    std::vector<std::pair<uint32, uint32>> aa_juanxians;
    
    //比武专区
    int32 aa_biwu_start_time = -1;
    uint32 aa_biwu_event_id = 0;
    std::map<ObjectGuid::LowType, uint32> aa_biwu_score;
    std::vector<std::pair<ObjectGuid::LowType, uint32>> aa_biwu_paiming;
    bool aa_biwu_status = false;
    bool aa_biwu_isstart = false;
    uint32 aa_biwu_isnotice = 0;
    std::unordered_map<uint32, AA_Biwu_Conf> aa_biwu_confs;
    std::unordered_map<uint32, AA_Biwu_Team> aa_biwu_teams;
    uint32 aa_biwu_time = 0;
    uint32 aa_biwu_index = 1;
    ObjectGuid aa_biwu_guid = ObjectGuid::Empty;
    std::set<ObjectGuid::LowType> aa_biwu_players;
    std::set<ObjectGuid::LowType> aa_biwu_winners;
    void AA_Biwu_Update(uint32 diff);
    GameObject* AA_Biwu_SpawnGob(ObjectGuid::LowType guid, bool created);
    void AA_Biwu_Start();
    std::unordered_map<uint32, AA_Biwu_Team> AA_Biwu_Fenzu();
    void AA_Biwu_Complete();
    void AA_Biwu_End();
    void AA_Biwu_Go(uint32 teamid);

    //答题
    std::unordered_map<uint32, AA_Dati_Conf> aa_dati_confs;
    std::unordered_map<uint32, std::vector<uint32>> aa_dati_conf_zus;

private:
    AACenter() {
        std::cout << "constructor called!" << std::endl;
    }
};

#endif // __CLY_AACENTER_H__
