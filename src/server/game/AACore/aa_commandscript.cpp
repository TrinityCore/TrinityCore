#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "DatabaseEnv.h"
#include "WorldSession.h"
#include "Map.h"
#include "Pet.h"
#include "SpellInfo.h"
#include "AAData.h"
#include "LootItemStorage.h"
#include "GroupMgr.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "Guild.h"
#include "StringConvert.h"
#include "Log.h"
#include "AccountMgr.h"
#include "DisableMgr.h"
#include "MapManager.h"
#include "LFGMgr.h"
#include "TerrainMgr.h"
#include "PhasingHandler.h"
#include "ChatCommand.h"
#include "SharedDefines.h"
#include "Bag.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Mail.h"
#include "Object.h"

using namespace Trinity::ChatCommands;

class aa_commandscript : public CommandScript
{
public:
    aa_commandscript() : CommandScript("aa_commandscript") { }
    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable setCommandTable =
        {
            { "scale",              AA_HandleSetScaleCommand, LANG_AA_HandleSetScaleCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes },
            { "display",			AA_HandleSetDisplayCommand, LANG_AA_HandleSetDisplayCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes },
            { "equip",              AA_npcWuqi, LANG_AA_npcWuqi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes },
            { "entry",              AA_npcentry, LANG_AA_npcentry, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes }
        };
        static ChatCommandTable commandTable =
        {
            { "_set", setCommandTable },
            { "_npcarea" ,AA_npcarea, LANG_AA_npcarea, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_morpet" ,AA_HandlePetMorphCommand, LANG_AA_HandlePetMorphCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_emote" ,AA_HandleEmoteCommand, LANG_AA_HandleEmoteCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_clearbag" ,AA_HandleClearBagCommand, LANG_AA_HandleClearBagCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_group" ,AA_HandleGroupCommand, LANG_AA_HandleGroupCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_heal" ,AA_HandleHealCommand, LANG_AA_HandleHealCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_level" ,AA_HandleLevelCommand, LANG_AA_HandleLevelCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_cast" ,AA_HandleCastCommand, LANG_AA_HandleCastCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_learn" ,AA_HandleLearnCommand, LANG_AA_HandleLearnCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_unlearn" ,AA_HandleUnLearnCommand, LANG_AA_HandleUnLearnCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_aura" ,AA_HandleAuraCommand, LANG_AA_HandleAuraCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "_unaura" ,AA_HandleUnAuraCommand, LANG_AA_HandleUnAuraCommand, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "ui" ,AA_ui, LANG_AA_ui, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "ai" ,AA_DoAi, LANG_AA_DoAi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            /*格式命令*/
            { "zuhe" ,AA_zuhe, LANG_AA_zuhe, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "组合" ,AA_zuhe, LANG_AA_zuhe, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zh" ,AA_zuhe, LANG_AA_zuhe, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "suiji" ,AA_suiji, LANG_AA_suiji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "随机" ,AA_suiji, LANG_AA_suiji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "sj" ,AA_suiji, LANG_AA_suiji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            /*sql操作*/
            { "jiazaitese" ,AA_jiazaitese, LANG_AA_jiazaitese, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "加载特色" ,AA_jiazaitese, LANG_AA_jiazaitese, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jzts" ,AA_jiazaitese, LANG_AA_jiazaitese, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "采集坐标" ,AA_caijizuobiao, LANG_AA_caijizuobiao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cjzb" ,AA_caijizuobiao, LANG_AA_caijizuobiao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "采集生物" ,AA_caijishengwu, LANG_AA_caijishengwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cjsw" ,AA_caijishengwu, LANG_AA_caijishengwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "采集玩家" ,AA_caijiwanjia, LANG_AA_caijiwanjia, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cjwj" ,AA_caijiwanjia, LANG_AA_caijiwanjia, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            /*不支持的操作-我的队友执行*/
            { "传唤" ,AA_chuanhuan, LANG_AA_chuanhuan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "ch" ,AA_chuanhuan, LANG_AA_chuanhuan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            /*玩家操作-我执行*/
            { "领取积分" ,AA_lingqujifen, LANG_AA_lingqujifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "lqjf" ,AA_lingqujifen, LANG_AA_lingqujifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "传送模板" ,AA_chuansongmoban, LANG_AA_chuansongmoban, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "csmb" ,AA_chuansongmoban, LANG_AA_chuansongmoban, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "传送玩家" ,AA_chuansongwanjia, LANG_AA_chuansongwanjia, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cswj" ,AA_chuansongwanjia, LANG_AA_chuansongwanjia, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "传送" ,AA_chuansong, LANG_AA_chuansong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cs" ,AA_chuansong, LANG_AA_chuansong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "拾取" ,AA_shiqu, LANG_AA_shiqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "sq" ,AA_shiqu, LANG_AA_shiqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "奖励" ,AA_jiangli, LANG_AA_jiangli, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "需求" ,AA_xuqiu, LANG_AA_xuqiu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "xq" ,AA_xuqiu, LANG_AA_xuqiu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "会员等级" ,AA_huiyuandengji, LANG_AA_huiyuandengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "hydj" ,AA_huiyuandengji, LANG_AA_huiyuandengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "积分" ,AA_jifen, LANG_AA_jifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jf" ,AA_jifen, LANG_AA_jifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "魔币" ,AA_mobi, LANG_AA_mobi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "mb" ,AA_mobi, LANG_AA_mobi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "泡点" ,AA_paodian, LANG_AA_paodian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "pd" ,AA_paodian, LANG_AA_paodian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "战场积分" ,AA_zhanchangjifen, LANG_AA_zhanchangjifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dzjf" ,AA_zhanchangjifen, LANG_AA_zhanchangjifen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "巅峰等级" ,AA_dianfengdengji, LANG_AA_dianfengdengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dfdj" ,AA_dianfengdengji, LANG_AA_dianfengdengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "斗气等级" ,AA_douqidengji, LANG_AA_douqidengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dqdj" ,AA_douqidengji, LANG_AA_douqidengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "军衔等级" ,AA_junxiandengji, LANG_AA_junxiandengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jxdj" ,AA_junxiandengji, LANG_AA_junxiandengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "展示商人" ,AA_xianshishangren, LANG_AA_xianshishangren, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zssr" ,AA_xianshishangren, LANG_AA_xianshishangren, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "随身商人" ,AA_suishenshangren, LANG_AA_suishenshangren, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "sssr" ,AA_suishenshangren, LANG_AA_suishenshangren, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "展示训练师" ,AA_zhanshixunlianshi, LANG_AA_zhanshixunlianshi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zsxls" ,AA_zhanshixunlianshi, LANG_AA_zhanshixunlianshi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "转职" ,AA_zhuanzhi, LANG_AA_zhuanzhi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zz" ,AA_zhuanzhi, LANG_AA_zhuanzhi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "公告" ,AA_gonggao, LANG_AA_gonggao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "gg" ,AA_gonggao, LANG_AA_gonggao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "弹窗" ,AA_tanchuang, LANG_AA_tanchuang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "tc" ,AA_tanchuang, LANG_AA_tanchuang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "弹窗内容" ,AA_tanchuangneirong, LANG_AA_tanchuangneirong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "tcnr" ,AA_tanchuangneirong, LANG_AA_tanchuangneirong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置日任务" ,AA_chongzhirirenwu, LANG_AA_chongzhirirenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czrrw" ,AA_chongzhirirenwu, LANG_AA_chongzhirirenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置周任务" ,AA_chongzhizhourenwu, LANG_AA_chongzhizhourenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czzrw" ,AA_chongzhizhourenwu, LANG_AA_chongzhizhourenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置月任务" ,AA_chongzhiyuerenwu, LANG_AA_chongzhiyuerenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czyrw" ,AA_chongzhiyuerenwu, LANG_AA_chongzhiyuerenwu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "加血" ,AA_jiaxue, LANG_AA_jiaxue, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jx" ,AA_jiaxue, LANG_AA_jiaxue, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "解卡" ,AA_jieka, LANG_AA_jieka, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jk" ,AA_jieka, LANG_AA_jieka, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "邮件" ,AA_youjian, LANG_AA_youjian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "yj" ,AA_youjian, LANG_AA_youjian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置理财" ,AA_chongzhilicailingqu, LANG_AA_chongzhilicailingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czlc" ,AA_chongzhilicailingqu, LANG_AA_chongzhilicailingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置首充" ,AA_chongzhishouchonglingqu, LANG_AA_chongzhishouchonglingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czsc" ,AA_chongzhishouchonglingqu, LANG_AA_chongzhishouchonglingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置签到" ,AA_chongzhiqiandaolingqu, LANG_AA_chongzhiqiandaolingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czqd" ,AA_chongzhiqiandaolingqu, LANG_AA_chongzhiqiandaolingqu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "召唤" ,AA_zhaohuan, LANG_AA_zhaohuan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zhao" ,AA_zhaohuan, LANG_AA_zhaohuan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "专业" ,AA_zhuanye, LANG_AA_zhuanye, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zy" ,AA_zhuanye, LANG_AA_zhuanye, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "杀死全图" ,AA_shasiquantu, LANG_AA_shasiquantu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "ssqt" ,AA_shasiquantu, LANG_AA_shasiquantu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "变身" ,AA_bianshen, LANG_AA_bianshen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "bs" ,AA_bianshen, LANG_AA_bianshen, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "排行奖励" ,AA_paihangjiangli, LANG_AA_paihangjiangli, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "phjl" ,AA_paihangjiangli, LANG_AA_paihangjiangli, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "个人银行" ,AA_gerenyinhang, LANG_AA_gerenyinhang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "gryh" ,AA_gerenyinhang, LANG_AA_gerenyinhang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "个人邮箱" ,AA_gerenyouxiang, LANG_AA_gerenyouxiang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "gryx" ,AA_gerenyouxiang, LANG_AA_gerenyouxiang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "装备修理" ,AA_zhuangbeixiuli, LANG_AA_zhuangbeixiuli, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zbxl" ,AA_zhuangbeixiuli, LANG_AA_zhuangbeixiuli, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置天赋" ,AA_chongzhitianfu, LANG_AA_chongzhitianfu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cztf" ,AA_chongzhitianfu, LANG_AA_chongzhitianfu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "解除虚弱" ,AA_jiechuxuruo, LANG_AA_jiechuxuruo, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jcxr" ,AA_jiechuxuruo, LANG_AA_jiechuxuruo, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "解除战斗" ,AA_jiechuzhandou, LANG_AA_jiechuzhandou, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jczd" ,AA_jiechuzhandou, LANG_AA_jiechuzhandou, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "恢复生命魔法" ,AA_huifuhpmp, LANG_AA_huifuhpmp, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "hfsmmf" ,AA_huifuhpmp, LANG_AA_huifuhpmp, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置技能冷却" ,AA_chongzhijineng, LANG_AA_chongzhijineng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czjnlq" ,AA_chongzhijineng, LANG_AA_chongzhijineng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "修改阵营" ,AA_xiugaizhenying, LANG_AA_xiugaizhenying, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "xgzy" ,AA_xiugaizhenying, LANG_AA_xiugaizhenying, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "修改种族" ,AA_xiugaizhongzhu, LANG_AA_xiugaizhongzhu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "xgzz" ,AA_xiugaizhongzhu, LANG_AA_xiugaizhongzhu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "修改名字" ,AA_xiugaimingzi, LANG_AA_xiugaimingzi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "xgmz" ,AA_xiugaimingzi, LANG_AA_xiugaimingzi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "修改外观" ,AA_xiugaiwaiguan, LANG_AA_xiugaiwaiguan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "xgwg" ,AA_xiugaiwaiguan, LANG_AA_xiugaiwaiguan, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "回收" ,AA_huishou, LANG_AA_huishou, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "hs" ,AA_huishou, LANG_AA_huishou, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "物品回收" ,AA_huishouwupin, LANG_AA_huishouwupin, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "wphs" ,AA_huishouwupin, LANG_AA_huishouwupin, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "巅峰属性" ,AA_dianfengshuxing, LANG_AA_dianfengshuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dfsx" ,AA_dianfengshuxing, LANG_AA_dianfengshuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "斗气属性" ,AA_douqishuxing, LANG_AA_douqishuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dqsx" ,AA_douqishuxing, LANG_AA_douqishuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "军衔属性" ,AA_junxianshuxing, LANG_AA_junxianshuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "jxsx" ,AA_junxianshuxing, LANG_AA_junxianshuxing, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置巅峰" ,AA_chongzhidianfeng, LANG_AA_chongzhidianfeng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czdf" ,AA_chongzhidianfeng, LANG_AA_chongzhidianfeng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置斗气" ,AA_chongzhidouqi, LANG_AA_chongzhidouqi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czdq" ,AA_chongzhidouqi, LANG_AA_chongzhidouqi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置军衔" ,AA_chongzhijunxian, LANG_AA_chongzhijunxian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czjx" ,AA_chongzhijunxian, LANG_AA_chongzhijunxian, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "会员升级" ,AA_huiyuanshengji, LANG_AA_huiyuanshengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "hysj" ,AA_huiyuanshengji, LANG_AA_huiyuanshengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "生成兑换码" ,AA_duihuanmashengcheng, LANG_AA_duihuanmashengcheng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "scdhm" ,AA_duihuanmashengcheng, LANG_AA_duihuanmashengcheng, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "兑换码" ,AA_duihuanma, LANG_AA_duihuanma, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dhm" ,AA_duihuanma, LANG_AA_duihuanma, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "召唤模板" ,AA_zhaohuanmoban, LANG_AA_zhaohuanmoban, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zhmb" ,AA_zhaohuanmoban, LANG_AA_zhaohuanmoban, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "领取累充" ,AA_lingquleichong, LANG_AA_lingquleichong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "leichong" ,AA_lingquleichong, LANG_AA_lingquleichong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "领取首充" ,AA_lingqushouchong, LANG_AA_lingqushouchong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "lqsc" ,AA_lingqushouchong, LANG_AA_lingqushouchong, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "领取签到" ,AA_lingquqiandao, LANG_AA_lingquqiandao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "lqqd" ,AA_lingquqiandao, LANG_AA_lingquqiandao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "领取等级" ,AA_lingqudengji, LANG_AA_lingqudengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "lqdj" ,AA_lingqudengji, LANG_AA_lingqudengji, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "领取理财" ,AA_lingqulicai, LANG_AA_lingqulicai, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "licai" ,AA_lingqulicai, LANG_AA_lingqulicai, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "采集物品" ,AA_caijiwupin, LANG_AA_caijiwupin, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cjwp" ,AA_caijiwupin, LANG_AA_caijiwupin, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "抽奖" ,AA_choujiang, LANG_AA_choujiang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cj" ,AA_choujiang, LANG_AA_choujiang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "重置购买次数" ,AA_chongzhigoumaicishu, LANG_AA_chongzhigoumaicishu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "czgmcs" ,AA_chongzhigoumaicishu, LANG_AA_chongzhigoumaicishu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "传送列表" ,AA_chuansongliebiao, LANG_AA_chuansongliebiao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "cslb" ,AA_chuansongliebiao, LANG_AA_chuansongliebiao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "招募" ,AA_zhaomu, LANG_AA_zhaomu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zm" ,AA_zhaomu, LANG_AA_zhaomu, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "制造" ,AA_zhizao, LANG_AA_zhizao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "zhizao" ,AA_zhizao, LANG_AA_zhizao, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "关键字" ,AA_guanjianzi, LANG_AA_guanjianzi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "gjz" ,AA_guanjianzi, LANG_AA_guanjianzi, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "翻牌弹窗" ,AA_fanpaitanchuang, LANG_AA_fanpaitanchuang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "fptc" ,AA_fanpaitanchuang, LANG_AA_fanpaitanchuang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "翻牌" ,AA_fanpai, LANG_AA_fanpai, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "fp" ,AA_fanpai, LANG_AA_fanpai, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "打开网址" ,AA_www, LANG_AA_www, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "dkwz" ,AA_www, LANG_AA_www, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "清理缓存" ,AA_qinglihuancun, LANG_AA_qinglihuancun, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "qlhc" ,AA_qinglihuancun, LANG_AA_qinglihuancun, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "变量" ,AA_bianliang, LANG_AA_bianliang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes},
            { "bl" ,AA_bianliang, LANG_AA_bianliang, rbac::RBAC_ROLE_GAMEMASTER, Console::Yes}
        };
        return commandTable;
    }
    static bool AA_HandleCastCommand(ChatHandler* handler, const char* args)
    {
        Player *player = handler->GetSession()->GetPlayer();
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!player || !target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* typestr = strtok(nullptr, " ");

        if (!zustr) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._cast 参数1（模板_技能_组） 参数2（施放类型 0施放当前组所有技能，1按几率随机施放组内一个技能）");
            return false;
        }

        int32 zu = int32(std::atoi(zustr));
        int32 type = 0;
        if (typestr) {
            type = int32(std::atoi(typestr));
        }
        std::vector<uint32> allids; allids.clear();
        if (zu > 0) {
            if (type == 0) {
                allids = aaCenter.aa_spellid_conf_zus[zu];
            }
            else {
                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
                //获取总chance，分母
                int count = ids.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
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
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = ids[i - 1];
                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    allids.clear();
                    uint32 id = ids[index];
                    allids.push_back(id);
                }
            }
        }

        for (auto id : allids) {
            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
            if (conf.spellid > 0) {
                player->CastSpell(target, conf.spellid);
            }
        }

        return true;
    }
    static bool AA_HandleLearnCommand(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* typestr = strtok(nullptr, " ");

        if (!zustr) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._learn 参数1（模板_技能_组） 参数2（学习类型 0学习当前组所有技能，1按几率随机学习组内一个技能）");
            return false;
        }

        int32 zu = int32(std::atoi(zustr));
        int32 type = 0;
        if (typestr) {
            type = int32(std::atoi(typestr));
        }
        std::vector<uint32> allids; allids.clear();
        if (zu > 0) {
            if (type == 0) {
                allids = aaCenter.aa_spellid_conf_zus[zu];
            }
            else {
                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
                //获取总chance，分母
                int count = ids.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
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
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = ids[i - 1];
                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    allids.clear();
                    uint32 id = ids[index];
                    allids.push_back(id);
                }
            }
        }

        for (auto id : allids) {
            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
            if (conf.spellid > 0) {
                target->LearnSpell(conf.spellid, true);
            }
        }
        return true;
    }
    static bool AA_HandleUnLearnCommand(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* typestr = strtok(nullptr, " ");

        if (!zustr) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._unlearn 参数1（模板_技能_组） 参数2（遗忘技能类型 0遗忘当前组所有技能，1按几率随机遗忘组内一个技能）");
            return false;
        }

        int32 zu = int32(std::atoi(zustr));
        int32 type = 0;
        if (typestr) {
            type = int32(std::atoi(typestr));
        }
        std::vector<uint32> allids; allids.clear();
        if (zu > 0) {
            if (type == 0) {
                allids = aaCenter.aa_spellid_conf_zus[zu];
            }
            else {
                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
                //获取总chance，分母
                int count = ids.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
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
                        uint32 id = ids[i];
                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = ids[i - 1];
                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    allids.clear();
                    uint32 id = ids[index];
                    allids.push_back(id);
                }
            }
        }

        for (auto id : allids) {
            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
            if (conf.spellid > 0) {
                std::string gm = ".组合 *.unlearn " + std::to_string(conf.spellid) + "<$自身>";
                aaCenter.AA_DoCommand(target, gm.c_str());
            }
        }
        return true;
    }
    static bool AA_HandleAuraCommand(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* typestr = strtok(nullptr, " ");

        if (!zustr) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._aura 参数1（模板_光环_组）参数2（附加类型 0附加当前组所有光环，1按几率随机附加组内某一个光环）");
            return false;
        }

        int32 zu = int32(std::atoi(zustr));
        int32 type = 0;
        if (typestr) {
            type = int32(std::atoi(typestr));
        }
        std::vector<uint32> allids; allids.clear();
        if (zu > 0) {
            if (type == 0) {
                allids = aaCenter.aa_auraid_conf_zus[zu];
            }
            else {
                std::vector<uint32> ids = aaCenter.aa_auraid_conf_zus[zu];
                //获取总chance，分母
                int count = ids.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        uint32 id = ids[i];
                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
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
                        uint32 id = ids[i];
                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = ids[i - 1];
                            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    allids.clear();
                    uint32 id = ids[index];
                    allids.push_back(id);
                }
            }
        }

        for (auto id : allids) {
            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
            if (conf.auraid > 0) {
                target->AddAura(conf.auraid, target);
            }
        }
        return true;
    }
    static bool AA_HandleUnAuraCommand(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* typestr = strtok(nullptr, " ");

        if (!zustr) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._unaura 参数1（模板_光环_组）参数2（取消类型 0附加当前组所有光环，1按几率随机取消组内某一个光环）");
            return false;
        }

        int32 zu = int32(std::atoi(zustr));
        int32 type = 0;
        if (typestr) {
            type = int32(std::atoi(typestr));
        }
        std::vector<uint32> allids; allids.clear();
        if (zu > 0) {
            if (type == 0) {
                allids = aaCenter.aa_auraid_conf_zus[zu];
            }
            else {
                std::vector<uint32> ids = aaCenter.aa_auraid_conf_zus[zu];
                //获取总chance，分母
                int count = ids.size();
                if (count > 0) {
                    uint32 chanceMax = 0;
                    for (int i = 0; i < count; i++) {
                        uint32 id = ids[i];
                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
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
                        uint32 id = ids[i];
                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
                        max = conf.chance + max;
                        min = 0;
                        if (i == 0) {
                            min = 0;
                        }
                        else {
                            uint32 id = ids[i - 1];
                            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
                            min = conf.chance + min;
                        }
                        if (min <= chanceVal && chanceVal < max) {
                            index = i;
                            break;
                        }
                    }
                    allids.clear();
                    uint32 id = ids[index];
                    allids.push_back(id);
                }
            }
        }

        for (auto id : allids) {
            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
            if (conf.auraid > 0) {
                target->RemoveAura(conf.auraid);
            }
        }
        return true;
    }
    static bool AA_HandleSetScaleCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float Scale = (float)atof((char*)args);
        if (Scale > 10.0f || Scale < 0.1f)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Unit* target = handler->getSelectedUnit();
        if (!target || target->GetTypeId() != TYPEID_UNIT)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }


        target->SetObjectScale(Scale);
        WorldDatabase.DirectPExecute("Update creature_template Set scale = {} WHERE entry = {}", Scale, target->GetEntry());
        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][Scale]设置为%f", target->GetName().c_str(), Scale);

        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
        aaCenter.AA_DoCommand(nullptr, gm.c_str());
        return true;
    }
    static bool AA_HandleSetDisplayCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 displayId = atoi(args);

        Unit* target = handler->getSelectedUnit();
        if (!target || target->GetTypeId() != TYPEID_UNIT)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->SetDisplayId(displayId);
        WorldDatabase.DirectPExecute("Update creature_template Set modelid1 = {},modelid2 = 0,modelid3 = 0,modelid4 = 0 WHERE entry = {}", displayId, target->GetEntry());
        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][DisplayId]设置为%d", target->GetName().c_str(), displayId);

        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
        aaCenter.AA_DoCommand(nullptr, gm.c_str());
        return true;
    }
    static bool AA_HandlePetMorphCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* target = handler->GetSession()->GetPlayer();

        if (!target)
            return false;

        uint32 displayID = atoi(args);

        CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(displayID);

        if (!minfo)
        {
            ChatHandler(target->GetSession()).PSendSysMessage("%u - 不是一个有效的模型ID", displayID);
            return true;
        }

        if (Pet* pet = target->GetPet())
        {
            pet->SetDisplayId(displayID);
            CharacterDatabase.DirectPExecute("UPDATE character_pet SET modelid = '{}' WHERE owner = '{}' AND entry = '{}'", displayID, target->GetGUIDLow(), pet->GetEntry());
            ChatHandler(target->GetSession()).PSendSysMessage("改变宠物模型为 - %u", displayID);
            return true;
        }
        else
            ChatHandler(target->GetSession()).PSendSysMessage("你没有召唤一个宠物", displayID);

        return true;
    }
    static bool AA_HandleEmoteCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;
        Unit* target = handler->getSelectedUnit();

        if (!target)
            target = handler->GetSession()->GetPlayer();

        uint32 emote = atoi(args);
        target->HandleEmoteCommand(Emote(emote));

        return true;
    }
    static bool AA_HandleClearBagCommand(ChatHandler* handler, const char* args)
    {
        if (Player* player = handler->GetSession()->GetPlayer())
            for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
                if (Bag* pBag = player->GetBagByPos(i))
                    for (uint32 j = 0; j < pBag->GetBagSize(); j++)
                        if (Item* item = player->GetItemByPos(i, j))
                            player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);

        return true;
    }
    static bool AA_HandleGroupCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return false;

        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("命令格式._group summon/revive");
            return false;
        }

        Group* group = player->GetGroup();

        if (!group)
            return true;

        std::string param = (char*)args;

        if (param == "summon")
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                if (Player* member = itr->GetSource())
                    if (member->IsInWorld() && member->GetGUID() != player->GetGUID())
                        member->TeleportTo(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
            return true;
        }

        if (param == "revive")
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                if (Player* member = itr->GetSource())
                    if (member->IsInWorld() && !member->IsAlive())
                    {
                        member->ResurrectPlayer(1.0f);
                        member->SpawnCorpseBones();
                    }

            return true;
        }

        ChatHandler(handler->GetSession()).PSendSysMessage("命令格式._group summon/revive");
        return false;
    }
    static bool AA_HandleHealCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return false;

        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._heal 生物编号 血量");
            return false;
        }

        char* s_entry = strtok((char*)args, " ");
        char* s_health = strtok(NULL, " ");

        if (!s_entry || !s_health)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._heal 生物编号 血量");
            return false;
        }

        uint32 entry = atoi(s_entry);
        uint32 health = atoi(s_health);

        if (Creature* c = player->FindNearestCreature(entry, 1000.0f))
            c->ModifyHealth(health);

        return true;
    }
    static bool AA_HandleLevelCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return false;

        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._level 等级（调整人物到指定等级）");
            return false;
        }

        uint32 level = atoi(args);
        int32 rlevel = 0;
        rlevel = level - player->GetLevel();

        std::string gm = ".level " + std::to_string(rlevel);
        aaCenter.AA_DoCommand(player, gm.c_str());

        return true;
    }
    static bool AA_npcarea(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* mapIdstr = strtok((char*)args, " ");
        uint32 mapId = uint32(std::atoi(mapIdstr));
        Map* map = sMapMgr->CreateMap(mapId, player);
        QueryResult result = WorldDatabase.PQuery("SELECT * from creature where map = {}", mapId);
        std::vector<uint32> guids;
        std::map<uint32, uint32> maps;
        std::map<uint32, float> xs;
        std::map<uint32, float> ys;
        std::map<uint32, float> zs;

        if (result) {
            do {
                Field* fields = result->Fetch();
                uint32 guid = fields[1].GetInt32();
                guids.push_back(guid);
                maps[guid] = fields[5].GetInt32();
                xs[guid] = fields[11].GetFloat();
                ys[guid] = fields[12].GetFloat();
                zs[guid] = fields[13].GetFloat();
            } while (result->NextRow());
        }

        for (auto itr : maps)
        {
            uint32 guid = itr.first;
            uint32 map = itr.second;
            float x = xs[guid];
            float y = ys[guid];
            float z = zs[guid];
            uint32 zone = 0;
            uint32 area = 0;
            player->GetZoneAndAreaId(zone, area);

            WorldDatabase.PExecute("UPDATE creature SET zoneId = {}, areaId = {} WHERE guid = {}", zone, area, guid);
        }
        return true;
    }

    static bool AA_bianliang(ChatHandler* handler, const char* args)
    {
        char* typestr = strtok((char*)args, " ");
        char* namestr = strtok(nullptr, " ");
        char* valuestr = strtok(nullptr, " ");
        char* allstr = strtok(nullptr, " ");
        if (!typestr || !namestr || !valuestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.变量 类型 变量名 变量值（.变量 系统/角色/账号 变量名 +/-/=数值） all（全部执行）");
            return false;
        }
        std::string type = typestr;
        std::string name = namestr;
        std::string value = valuestr;
        std::string all = "";
        if (allstr) {
            all = allstr;
        }

        if (type == "角色") {
            std::vector<ObjectGuid::LowType> guidlows; guidlows.clear();
            if (all == "all") {
                for (auto itr : aaCenter.aa_characterss)
                {
                    guidlows.push_back(itr.first);
                }
            }
            else {
                Player* player = handler->getSelectedPlayerOrSelf();
                if (!player || !player->IsInWorld()) {
                    return false;
                }
                guidlows.push_back(player->GetGUIDLow());
            }
            for (auto guidlow : guidlows)
            {
                std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
                std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
                aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);
                std::string k = namestr;
                std::string v = valuestr;
                std::string v2 = mdiy_guids[k];
                double value2 = aaCenter.AA_StringFloat(v2);
                if (v.find("+") != std::string::npos || (v.find("+") == std::string::npos && v.find("-") == std::string::npos && v.find("=") == std::string::npos)) { //加
                    aaCenter.AA_StringReplaceFirst(v, "+", "");
                    double value = aaCenter.AA_StringFloat(v);
                    value2 += value;
                }
                if (v.find("-") != std::string::npos) { //减
                    aaCenter.AA_StringReplaceFirst(v, "-", "");
                    double value = aaCenter.AA_StringFloat(v);
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                }
                if (v.find("=") != std::string::npos) { //赋值
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    double value = aaCenter.AA_StringFloat(v);
                    value2 = value;
                }
                mdiy_guids[k] = std::to_string(value2);
                time_t timep;
                time(&timep); /*当前time_t类型UTC时间*/
                aaCenter.aa_characterss[guidlow].update_time = timep;
                aaCenter.aa_characterss[guidlow].isUpdate = true;
                std::string str = "";
                aaCenter.AA_StringMapToString(mdiy_guids, str);
                aaCenter.aa_characterss[guidlow].diy_guid = str;
                CharacterDatabase.DirectPExecute("UPDATE _玩家角色数据 SET 自定义角色变量=\"{}\",update_time={} where guid={};", str, timep, guidlow);
            }
        }
        else if (type == "系统") {
            std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
            std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
            aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);
            std::string k = namestr;
            std::string v = valuestr;
            std::string v2 = mdiy_systems[k];
            double value2 = aaCenter.AA_StringFloat(v2);
            if (v.find("+") != std::string::npos || (v.find("+") == std::string::npos && v.find("-") == std::string::npos && v.find("=") == std::string::npos)) { //加
                aaCenter.AA_StringReplaceFirst(v, "+", "");
                double value = aaCenter.AA_StringFloat(v);
                value2 += value;
            }
            if (v.find("-") != std::string::npos) { //减
                aaCenter.AA_StringReplaceFirst(v, "-", "");
                double value = aaCenter.AA_StringFloat(v);
                if (value2 >= value) {
                    value2 -= value;
                }
                else {
                    value2 = 0;
                }
            }
            if (v.find("=") != std::string::npos) { //赋值
                aaCenter.AA_StringReplaceFirst(v, "=", "");
                double value = aaCenter.AA_StringFloat(v);
                value2 = value;
            }
            mdiy_systems[k] = std::to_string(value2);
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            aaCenter.aa_system_conf.update_time = timep;
            aaCenter.aa_system_conf.isUpdate = true;
            std::string str = "";
            aaCenter.AA_StringMapToString(mdiy_systems, str);
            aaCenter.aa_system_conf.diy_system = str;
        }
        else if (type == "账号") {
            std::vector<uint32> accountids; accountids.clear();
            if (all == "all") {
                for (auto itr : aaCenter.aa_accounts)
                {
                    accountids.push_back(itr.first);
                }
            }
            else {
                Player* player = handler->getSelectedPlayerOrSelf();
                if (!player || !player->IsInWorld()) {
                    return false;
                }
                accountids.push_back(player->GetSession()->GetAccountId());
            }
            for (auto accountid : accountids) {
                std::string m_diy_accounts = aaCenter.aa_accounts[accountid].diy_account;
                std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
                aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);
                std::string k = namestr;
                std::string v = valuestr;
                std::string v2 = mdiy_accounts[k];
                double value2 = aaCenter.AA_StringFloat(v2);
                if (v.find("+") != std::string::npos || (v.find("+") == std::string::npos && v.find("-") == std::string::npos && v.find("=") == std::string::npos)) { //加
                    aaCenter.AA_StringReplaceFirst(v, "+", "");
                    double value = aaCenter.AA_StringFloat(v);
                    value2 += value;
                }
                if (v.find("-") != std::string::npos) { //减
                    aaCenter.AA_StringReplaceFirst(v, "-", "");
                    double value = aaCenter.AA_StringFloat(v);
                    if (value2 >= value) {
                        value2 -= value;
                    }
                    else {
                        value2 = 0;
                    }
                }
                if (v.find("=") != std::string::npos) { //赋值
                    aaCenter.AA_StringReplaceFirst(v, "=", "");
                    double value = aaCenter.AA_StringFloat(v);
                    value2 = value;
                }
                mdiy_accounts[k] = std::to_string(value2);
                time_t timep;
                time(&timep); /*当前time_t类型UTC时间*/
                aaCenter.aa_accounts[accountid].update_time = timep;
                aaCenter.aa_accounts[accountid].isUpdate = true;
                std::string str = "";
                aaCenter.AA_StringMapToString(mdiy_accounts, str);
                aaCenter.aa_accounts[accountid].diy_account = str;
                LoginDatabase.DirectPExecute("UPDATE _aa_account SET 自定义账号变量=\"{}\", 更新时间 = {} where id = {}; ", str, timep, accountid);
            }
        }

        return true;
    }

    static bool AA_ui(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        char* idstr = strtok(nullptr, " ");
        if (!typestr || !idstr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.ui 类型 id（类型1客户端ui，类型2自定义ui传送）");
            return false;
        }
        uint32 type = uint32(std::atoi(typestr));
        uint32 id = uint32(std::atoi(idstr));
        std::string result = "{["; result += std::to_string(type); result += "]={";
        std::string msg = "";
        if (type == 1) {
            result += std::to_string(id);
            result += "}}";
            msg = result;
        }
        else if (type == 2) { //自定义ui_传送
            time_t timep;
            time(&timep); /*当前time_t类型UTC时间*/
            std::string miyao = std::to_string(timep);
            aaCenter.aa_ui_miyaos[timep] = 1;
            AA_UI_Chuansong conf = aaCenter.aa_ui_chuansongs[id];
            if (conf.id > 0) {
                result += "\"";
                result += std::to_string(conf.id); result += "\",\"";
                result += miyao; result += "\",\"";
                result += conf.title; result += "\",\"";
                result += conf.detail1; result += "\",\"";
                result += conf.detail2; result += "\",\"";
                result += conf.detail3; result += "\",\"";
                result += conf.detail4; result += "\",\"";
                result += conf.detail5; result += "\",\"";

                std::string items = "";
                if (conf.items != "") {
                    std::vector<int32> types; types.clear();
                    std::vector<int32> values; values.clear();
                    aaCenter.AA_StringToVector2(conf.items, types, values);
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

                result += items;
                result += "\"}}";
                msg = result;
            }
        }
;       if (msg != "") {
            aaCenter.M_SendClientAddonData(player, "999", msg);
        }

        return true;
    }

    static bool AA_qinglihuancun(ChatHandler* handler, const char* args)
    {
        ObjectAccessor::SaveAllPlayers();
        handler->SendSysMessage(LANG_PLAYERS_SAVED);
        TC_LOG_INFO("server.loading", "开始清理垃圾数据...");
        aaCenter.DeleteAAData_Characters();
        TC_LOG_INFO("server.loading", "开始加载特色数据...");
        aaCenter.LoadAAData_Characters();
        return true;
    }
    static bool AA_npcWuqi(ChatHandler* handler, const char* args)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target) {
            return false;
        }
        char* zustr1 = strtok((char*)args, " ");
        char* zustr2 = strtok(nullptr, " ");
        char* zustr3 = strtok(nullptr, " ");
        if (!zustr1 || !zustr2 || !zustr3) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._set equip 主手id 副手id 远程id 是否修改数据库（0否1是）");
            return false;
        }

        int32 zu1 = int32(std::atoi(zustr1));
        int32 zu2 = int32(std::atoi(zustr2));
        int32 zu3 = int32(std::atoi(zustr3));

        target->SetVirtualItem(0, zu1, 0, 0);
        target->SetVirtualItem(1, zu2, 0, 0);
        target->SetVirtualItem(2, zu3, 0, 0);

        char* isstr = strtok(nullptr, " ");
        if (isstr)
        {
            int32 isOk = int32(std::atoi(isstr));
            if (isOk) {
                WorldDatabase.DirectPExecute("INSERT INTO creature_equip_template (CreatureID, ID, ItemID1, AppearanceModID1, ItemVisual1, ItemID2, AppearanceModID2, ItemVisual2, ItemID3, AppearanceModID3, ItemVisual3, VerifiedBuild) VALUES (?, 1, ?, 0, 0, ?, 0, 0, ?, 0, 0, 18019) ON DUPLICATE KEY UPDATE ItemID1 = ?, ItemID2 = ?, ItemID3 = ?", target->GetEntry(), zu1, zu2, zu3, zu1, zu2, zu3);
                sObjectMgr->LoadEquipmentTemplates();
            }
        }

        return true;
    }
    static bool AA_www(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* url = strtok((char*)args, " ");
        if (!url)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.打开网址 http://www.baidu.com");
            return false;
        }

        aaCenter.M_SendClientAddonData(player, "888", url);

        return true;
    }
    static bool AA_fanpaitanchuang(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a104b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return true;
        }
        char* zustr1 = strtok((char*)args, " ");
        char* zustr2 = strtok(nullptr, " ");
        char* zustr3 = strtok(nullptr, " ");
        if (!zustr1 || !zustr2 || !zustr3) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.翻牌弹窗 组1 组2 组3(分别对应翻牌第一排，第二排，第三排。功能表：_奖励_翻牌x)");
            return false;
        }
        int32 zu1 = int32(std::atoi(zustr1));
        int32 zu2 = int32(std::atoi(zustr2));
        int32 zu3 = int32(std::atoi(zustr3));
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        //{"timp+guid"}
        std::string msg = "";
        Group* group = player->GetGroup();
        uint64 miyao = 0;
        if (group) {//队伍翻牌
            miyao = timep + group->GetLeaderGUID().GetCounter();
            Group::MemberSlotList const& members = group->GetMemberSlots();
            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                    if (!p->IsInWorld()) { continue; }
                    msg = "{" + std::to_string(miyao) + "," + std::to_string(p->GetGUIDLow()) + "}";
                    aaCenter.M_SendClientAddonData(p, "1012", msg);
                }
            }
        }
        else {//个人翻牌
            miyao = timep + player->GetGUIDLow();
            msg = "{" + std::to_string(miyao) + "," + std::to_string(player->GetGUIDLow()) + "}";
            aaCenter.M_SendClientAddonData(player, "1012", msg);
        }
        aaCenter.aa_fanpai_tanchuang1[miyao] = zu1;
        aaCenter.aa_fanpai_tanchuang2[miyao] = zu2;
        aaCenter.aa_fanpai_tanchuang3[miyao] = zu3;
        return true;
    }
    static bool AA_fanpai(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a104b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return true;
        }

        //秘钥：翻牌弹窗时间戳+guid
        //接收{指令id,秘钥,牌子序号} //加密，秘钥:{guid,序号,开关=已翻}
        //{秘钥={角色guid:{序号=物品id} }}
        //{[秘钥]={[guid]={[序号]=物品id,[序号]=物品id},[guid]={[序号]=itemlink,[序号]=itemlink} }}
        //发送{指令id:{牌子序号:{角色guid,牌子内容},牌子序号:{角色guid,牌子内容}}
        //加密，翻牌弹窗时间戳+guid:{guid+序号开关}

        char* miyaostr = strtok((char*)args, " ");
        char* indexstr = strtok(nullptr, " ");
        if (!miyaostr || !indexstr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.翻牌 秘钥 牌子序号");
            return false;
        }
        uint64 miyao = uint64(std::stoul(miyaostr));
        int32 num = int32(std::atoi(indexstr));
        uint32 zu1 = aaCenter.aa_fanpai_tanchuang1[miyao];
        uint32 zu2 = aaCenter.aa_fanpai_tanchuang2[miyao];
        uint32 zu3 = aaCenter.aa_fanpai_tanchuang3[miyao];
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        if (zu1 <= 0 || zu2 <= 0 || zu3 <= 0) return true; //防封包，弹窗的才可以翻
        if (std::find(aaCenter.aa_fanpai_pai[miyao][guidlow].begin(), aaCenter.aa_fanpai_pai[miyao][guidlow].end(), num) != aaCenter.aa_fanpai_pai[miyao][guidlow].end()) {//已经翻过，不能再翻
            return true;
        }

        std::vector<uint32> itemids; itemids.clear();
        std::vector<uint32> conf_ids; conf_ids.clear();
        if (num >= 1 && num <= 4) {
            conf_ids = aaCenter.aa_fanpai_zus[zu1];
        }
        else if (num >= 5 && num <= 8) {
            conf_ids = aaCenter.aa_fanpai_zus[zu2];
        }
        else if (num >= 9 && num <= 12) {
            conf_ids = aaCenter.aa_fanpai_zus[zu3];
        }
        int count = conf_ids.size();
        if (!count) {
            return false;
        }
        uint32 chanceMax = 0;
        for (int i = 0; i < count; i++) {
            uint32 id = conf_ids[i];
            AA_Fanpai conf = aaCenter.aa_fanpais[id];
            chanceMax += conf.chance;
        }
        if (chanceMax == 0) { chanceMax = 1; }
        AA_Fanpai conf;
        //获取随机chance，分子
        uint32 chanceVal = rand() % chanceMax;
        //获取Index
        uint32 max = 0;
        uint32 min = 0;
        int index = -1;
        for (int i = 0; i < count; i++) {
            uint32 id = conf_ids[i];
            AA_Fanpai conf = aaCenter.aa_fanpais[id];
            max = conf.chance + max;
            min = 0;
            if (i == 0) {
                min = 0;
            }
            else {
                uint32 id = conf_ids[i - 1];
                AA_Fanpai conf = aaCenter.aa_fanpais[id];
                min = conf.chance + min;
            }

            if (min <= chanceVal && chanceVal < max) {
                index = i;
                break;
            }
        }
        uint32 id = conf_ids[index];
        conf = aaCenter.aa_fanpais[id];
        if (conf.gm != "" && conf.gm != "0") {
            aaCenter.AA_DoCommand(player, conf.gm.c_str());
        }
        time_t timep;
        time(&timep); /*当前time_t类型UTC时间*/
        //{"timp+guid"}
        Item* item = aaCenter.AA_AddItem(player, conf.itemid, 1);
        std::string msg = "";
        if (item) {
            std::string itemlink = aaCenter.AA_GetItemLinkJd(item);
            //{[秘钥]={[guid]={[序号]=物品id,[序号]=物品id},[guid]={[序号]=itemlink,[序号]=itemlink} }}
            msg = "{[" + std::to_string(miyao) + "]={[" + std::to_string(guidlow) + "]={[" + std::to_string(num) + "]=\"" + itemlink + "\"}}}";
        }
        Group* group = player->GetGroup();
        if (group) {//队伍翻牌
            Group::MemberSlotList const& members = group->GetMemberSlots();
            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
                    if (!p->IsInWorld()) { continue; }
                    aaCenter.M_SendClientAddonData(p, "1013", msg);
                }
            }
        }
        else {//个人翻牌
            aaCenter.M_SendClientAddonData(player, "1013", msg);
        }
        aaCenter.aa_fanpai_pai[miyao][guidlow].push_back(num);
        return true;
    }
    static bool AA_npcentry(ChatHandler* handler, const char* args)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target) {
            return false;
        }
        ObjectGuid::LowType guidlow = target->GetGUIDLow();
        char* prefix = strtok((char*)args, " ");
        char* suffix = strtok(nullptr, " ");
        if (!prefix || !suffix)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._set entry entry time（修改生物的entry 和 刷新时间）");
            return false;
        }
        int32 entry = int32(std::atoi(prefix));
        int32 time = int32(std::atoi(suffix));
        WorldDatabase.DirectPExecute("UPDATE creature SET id = {},spawntimesecs = {} WHERE guid = {}", entry, time, guidlow);
        target->Kill(target, target);
        target->Respawn();
        return true;
    }
    static bool AA_guanjianzi(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return true;
        }
        char* zustr = strtok((char*)args, " ");
        if (!zustr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.关键字 <$奖励@1>");
            return false;
        }
        //排名显示
        AA_Paihang p_conf;
        std::string zustr1 = zustr;
        if (zustr1.find("排行") != std::string::npos) {
            p_conf = aaCenter.AA_GetPaihangs();
            p_conf.isOk = true;
        }
        AA_Message aa_message;
        std::string gjz = aaCenter.GetMyInfo(target, zustr, aa_message);
        if (p_conf.isOk) {
            aaCenter.AA_GetPaihangInfo(gjz, p_conf);
        }
        ChatHandler(handler->GetSession()).PSendSysMessage("%s", gjz.c_str());
        return true;
    }
    static bool AA_zhizao(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return true;
        }
        char* zustr = strtok((char*)args, " ");
        if (!zustr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.制造 __采集_物品_组(同一组中按几率随机)");
            return false;
        }
        int32 zu = int32(std::atoi(zustr));
        AA_Caiji_Item conf;
        std::vector<uint32> conf_ids = aaCenter.aa_caiji_item_zus[zu];
        //获取总chance，分母
        int count = conf_ids.size();
        if (count) {
            uint32 chanceMax = 0;
            for (int i = 0; i < count; i++) {
                uint32 id = conf_ids[i];
                AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
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
                AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
                max = conf.chance + max;
                min = 0;
                if (i == 0) {
                    min = 0;
                }
                else {
                    uint32 id = conf_ids[i - 1];
                    AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
                    min = conf.chance + min;
                }

                if (min <= chanceVal && chanceVal < max) {
                    index = i;
                    break;
                }
            }
            uint32 id = conf_ids[index];
            conf = aaCenter.aa_caiji_items[id];
        }

        if (conf.id > 0 && conf.entry && conf.count > 0) {
            if (Item* pItem = aaCenter.AA_AddItem(target, conf.entry, conf.count))
            {
                if (pItem->GetTemplate()->GetBonding() == BIND_ON_ACQUIRE ||
                    pItem->GetTemplate()->GetBonding() == BIND_QUEST)
                    pItem->SetBinding(true);
            }
        }
        else {
            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的__采集_物品_组");
            return false;
        }
        return true;
    }
    static bool AA_zhaomu(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player || !player->IsInWorld()) {
            return true;
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        char* arg1 = strtok((char*)args, " ");
        if (!arg1 || guidlow == 0)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.招募 招募者姓名");
            return false;
        }
        QueryResult result = CharacterDatabase.PQuery("SELECT 招募者姓名 from _玩家角色数据 where guid = {}", guidlow);
        if (result) {
            Field* fields = result->Fetch();
            std::string zhaomu = fields[0].GetString();
            if (zhaomu != "") {
                std::string zmstr = "|cff00FFFF[系统提示]|cffFF0000你已经拥有招募者：" + zhaomu;
                aaCenter.AA_SendMessage(player, 1, zmstr.c_str());
                return false;
            }
            else {
                Player* p = ObjectAccessor::FindPlayerByName(zhaomu);
                uint32 accountId = 0;
                if (p && p->IsInWorld()) {
                    accountId = p->GetSession()->GetAccountId();
                }
                if (accountId == 0) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该玩家未找到或不在线，无法设置。");
                    return false;
                }
                if (player->GetSession()->GetAccountId() == accountId) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法招募当前账号的角色。");
                    return false;
                }
                CharacterDatabase.DirectPExecute("UPDATE _玩家角色数据 SET 招募者姓名 = '{}' WHERE guid = {}", zhaomu, guidlow);
                return true;
            }
        }
        return false;
    }
    static bool AA_huishouwupin(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (aaCenter.AA_GetEmptyBag(player) < 5) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        if (!typestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.物品回收 物品guid");
            return false;
        }
        uint32 itemGuidLow = atoi(typestr);
        bool isOk = false;
        if (itemGuidLow > 0) {
            if (Item* pItem = aaCenter.GetItemByGUIDLow(player, itemGuidLow)) {
                if (player->aa_target_item == pItem) {
                    uint32 count = pItem->GetCount();
                    AA_Huishou_Conf conf = aaCenter.AA_GetHuiShouConf(player, player->aa_target_item->GetGUIDLow(), player->aa_target_item->GetEntry());
                    if (conf.need > 0) {
                        aaCenter.M_Need(player, conf.need, count);
                    }
                    if (conf.reward > 0) {
                        aaCenter.M_Reward(player, conf.reward, count);
                        player->DestroyItemCount(pItem, count, true);
                        isOk = true;
                        player->aa_item = nullptr;
                        player->aa_target_item = nullptr;
                    }
                }
            }
        }
        if (isOk) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00回收成功");
        }
        else {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法回收");
        }
        return true;
    }
    static bool AA_huishou(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (aaCenter.AA_GetEmptyBag(player) < 5) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
            return false;
        }
        bool isOk = false;
        bool isBaoshi = false;
        bool isFuwen = false;
        std::set<Item*> items = aaCenter.M_GetBagItems(player);
        for (auto pItem : items) {
            if (pItem && pItem->GetState() != ITEM_REMOVED && pItem->IsInWorld()) {
                if (ItemTemplate const* pProto = pItem->GetTemplate()) {
                    uint32 entry = aaCenter.AA_GetBaoshiEntry(pItem, 0);
                    if (entry > 0) {
                        isBaoshi = true;
                        continue;
                    }
                    isFuwen = aaCenter.AA_IsFuwenItem(pItem);
                    if (isFuwen) {
                        continue;
                    }
                    uint32 count = pItem->GetCount();
                    AA_Huishou_Conf conf = aaCenter.AA_GetHuiShouConf(player, pItem->GetGUIDLow(), pItem->GetEntry());
                    if (conf.need > 0) {
                        aaCenter.M_Need(player, conf.need, count);
                    }
                    if (conf.reward > 0) {
                        aaCenter.M_Reward(player, conf.reward, count);
                        if (pItem && pItem->GetState() != ITEM_REMOVED && pItem->IsInWorld()) {
                            player->DestroyItemCount(pItem, count, true);
                        }
                        isOk = true;
                    }
                }
            }
        }
        if (isBaoshi) {
            aaCenter.AA_SendMessage(player, 0, "|cff00FFFF[系统提示]|cffFF0000背包中有镶嵌过宝石的物品不能回收。");
        }
        if (isFuwen) {
            aaCenter.AA_SendMessage(player, 0, "|cff00FFFF[系统提示]|cffFF0000背包中有镶嵌过符文的物品不能回收。");
        }
        if (isOk) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00回收成功");
        }
        else {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包没有可回收的物品");
        }
        return true;
    }
    static bool AA_DoAi(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player || !player->IsInWorld()) {
            return true;
        }
        char* arg1 = strtok((char*)args, " ");
        if (!arg1)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.Ai _自定义ai_Id 伤害值");
            return false;
        }
        char* arg2 = strtok(nullptr, " ");
        int32 value = 0;
        if (arg2)
        {
            value = int32(std::atoi(arg2));
        }
        uint32 ai_id = int32(std::atoi(arg1));
        AA_Ai conf = aaCenter.aa_ais[ai_id];
        if (conf.id > 0) {
            Unit* target = handler->getSelectedUnit();
            if (target && target->IsInWorld()) {
                aaCenter.AA_AiStart(player, target, conf.id, value, true);
            }
            else {
                aaCenter.AA_AiStart(player, player, conf.id, value, true);
            }
        }
        return true;
    }

    static bool AA_chuansongliebiao(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return true;
        }
        char* arg1 = strtok((char*)args, " ");
        if (!arg1)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送列表 _传送_物品物体生物副本id");
            return false;
        }
        uint32 entry = 0;
        if (arg1) {
            entry = int32(std::atoi(arg1));
        }
        player->aa_menuId = entry;
        //aawow 进入副本撞门提示
        //获取menus
        std::vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
        size_t size = menus.size();
        if (size > 0) {
            //如果只有一项m，直接执行功能
            if (size == 1) {
                uint32 id = menus[0];
                AA_Teleport_Conf conf = aaCenter.aa_teleports[id];
                aaCenter.AA_TelScript(player, conf);
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
            }
            else {
                //否则显示菜单
                // 传送石
                std::vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
                ClearGossipMenuFor(player); // Clears old options
                int pId = -1;
                AA_Message aa_message;
                //排名显示
                AA_Paihang p_conf;
                for (size_t i = 0; i < menus.size(); i++) {
                    uint32 menuid = menus[i];
                    AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
                    if (conf.title.find("排行") != std::string::npos || conf.subtitle.find("排行") != std::string::npos) {
                        p_conf = aaCenter.AA_GetPaihangs();
                        p_conf.isOk = true;
                        break;
                    }
                }
                for (size_t i = 0; i < menus.size(); i++) {
                    uint32 menuid = menus[i];
                    AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
                    if (conf.menuid != 0 || conf.is_visible == 2) {
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
                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, subtitle, 0, true);
                        }
                        else {
                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, subtitle, 0, false);
                        }
                    }
                    else {
                        if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, "", 0, true);
                        }
                        else {
                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid);
                        }
                    }
                    pId = aaCenter.aa_teleports[conf.menuid].menuid;
                }
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
            }
        }
        return true;
    }
    static bool AA_chongzhigoumaicishu(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        time_t timep;
        time(&timep);
        if (player) {
            {
                uint32 accountid = player->GetSession()->GetAccountId();
                AA_Account conf = aaCenter.aa_accounts[accountid];
                conf.id = accountid;
                conf.buy_time = "";
                conf.buy_time_yj = "";
                conf.isUpdate = true;
                conf.update_time = timep;
                aaCenter.aa_accounts[accountid] = conf;
            }
            {
                ObjectGuid::LowType guidlow = player->GetGUIDLow();
                AA_Characters conf = aaCenter.aa_characterss[guidlow];
                conf.guid = guidlow;
                conf.buy_time = "";
                conf.buy_time_yj = "";
                conf.isUpdate = true;
                conf.update_time = timep;
                aaCenter.aa_characterss[guidlow] = conf;
            }
        }
        ChatHandler(handler->GetSession()).PSendSysMessage("重置购买次数成功");
        return true;
    }
    static bool AA_choujiang(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a100b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* zustr = strtok((char*)args, " ");
        char* cishustr = strtok(nullptr, " ");
        if (!zustr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.抽奖 _奖励_抽奖x_组(同一组中按几率随机坐标) 抽奖次数(选填)");
            return false;
        }
        int32 zu = int32(std::atoi(zustr));
        int32 rcishu = 0;
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        uint32 needid = aaCenter.aa_world_confs[73].value1;
        if (zu > 0) {
            //抽奖次数奖励
            time_t timep;
            time(&timep);
            aaCenter.aa_characterss[guidlow].update_time = timep;
            aaCenter.aa_characterss[guidlow].isUpdate = true;
            std::vector<int32> types; types.clear();
            std::vector<int32> values; values.clear();
            aaCenter.AA_StringToVector2(aaCenter.aa_world_confs[73].value2, types, values);
            uint32 cishu = 1;
            if (cishustr) {
                cishu = uint32(std::atoi(cishustr));
            }
            if (needid > 0) {
                if (!aaCenter.M_CanNeed(player, needid, cishu)) {
                    return false;
                }
            }
            std::vector<uint32> itemids; itemids.clear();
            std::vector<uint32> conf_ids = aaCenter.aa_choujiang_zus[zu];
            int count = conf_ids.size();
            if (!count) {
                return false;
            }
            uint32 chanceMax = 0;
            for (int i = 0; i < count; i++) {
                uint32 id = conf_ids[i];
                AA_Choujiang conf = aaCenter.aa_choujiangs[id];
                chanceMax += conf.chance;
            }
            if (chanceMax == 0) { chanceMax = 1; }
            for (uint32 i = 0; i < cishu; i++) {
                AA_Choujiang conf;
                //获取随机chance，分子
                uint32 chanceVal = rand() % chanceMax;
                //获取Index
                uint32 max = 0;
                uint32 min = 0;
                int index = -1;
                for (int i = 0; i < count; i++) {
                    uint32 id = conf_ids[i];
                    AA_Choujiang conf = aaCenter.aa_choujiangs[id];
                    max = conf.chance + max;
                    min = 0;
                    if (i == 0) {
                        min = 0;
                    }
                    else {
                        uint32 id = conf_ids[i - 1];
                        AA_Choujiang conf = aaCenter.aa_choujiangs[id];
                        min = conf.chance + min;
                    }

                    if (min <= chanceVal && chanceVal < max) {
                        index = i;
                        break;
                    }
                }
                uint32 id = conf_ids[index];
                conf = aaCenter.aa_choujiangs[id];

                if (conf.id > 0) {
                    aaCenter.aa_characterss[guidlow].choujiang += 1;
                    size_t count = types.size();
                    for (size_t i = 0; i < count; i++) {
                        uint32 cishu = AA_SafeObjectAtIndex(types, i);
                        uint32 reward = AA_SafeObjectAtIndex(values, i);
                        if (aaCenter.aa_characterss[guidlow].choujiang > cishu &&
                            aaCenter.aa_characterss[guidlow].choujianglq < cishu) {
                            aaCenter.aa_characterss[guidlow].choujianglq = cishu;
                            if (reward > 0) {
                                aaCenter.M_Reward(player, reward);
                                std::string msg = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00累计抽奖达到|r【" + std::to_string(cishu) + "次|cffFFFF00】获得了额外奖励|r";
                                aaCenter.AA_SendMessage(player, 2, msg.c_str());
                            }
                        }
                    }
                    rcishu++;
                    itemids.push_back(conf.itemid);
                    if (conf.reward > 0) {
                        aaCenter.M_Reward(player, conf.reward);
                        std::string text = aaCenter.aa_rewards[conf.reward].text;
                        if (text == "") {
                            text = aaCenter.AA_GetItemLink(conf.itemid);
                        }
                        if (conf.notice == 1) { //显示+公告
                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + text + "|cffFFFF00】|r";
                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + text;
                            aaCenter.aa_choujiangStrs.push_back(msg2);
                            if (aaCenter.aa_choujiangStrs.size() > 8) {
                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
                            }
                        }
                        else if (conf.notice == 2) { //只显示
                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + text;
                            aaCenter.aa_choujiangStrs.push_back(msg2);
                            if (aaCenter.aa_choujiangStrs.size() > 8) {
                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
                            }
                        }
                        else if (conf.notice == 3) { //只公告
                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + text + "|cffFFFF00】|r";
                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
                        }
                    }
                    else {
                        if (conf.itemid > 0) {
                            player->AddItem(conf.itemid, 1);
                        }
                        if (conf.notice == 1) { //显示+公告
                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + aaCenter.AA_GetItemLink(conf.itemid) + "|cffFFFF00】|r";
                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + aaCenter.AA_GetItemLink(conf.itemid);
                            aaCenter.aa_choujiangStrs.push_back(msg2);
                            if (aaCenter.aa_choujiangStrs.size() > 8) {
                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
                            }
                        }
                        else if (conf.notice == 2) { //只显示
                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + aaCenter.AA_GetItemLink(conf.itemid);
                            aaCenter.aa_choujiangStrs.push_back(msg2);
                            if (aaCenter.aa_choujiangStrs.size() > 8) {
                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
                            }
                        }
                        else if (conf.notice == 3) { //只公告
                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + aaCenter.AA_GetItemLink(conf.itemid) + "|cffFFFF00】|r";
                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
                        }
                    }
                }
            }
            if (needid > 0) {
                aaCenter.M_Need(player, needid, cishu);
            }
            if (aaCenter.aa_world_confs[91].value1 > 0 && cishu >= aaCenter.aa_world_confs[91].value1) {
                if (aaCenter.aa_world_confs[91].value2 != "" && aaCenter.aa_world_confs[91].value2 != "0") {
                    uint32 reward = aaCenter.AA_StringUint32(aaCenter.aa_world_confs[91].value2);
                    if (reward > 0) {
                        aaCenter.M_Reward(player, reward);
                    }
                }
            }
            if (rcishu > 0) {
                CharacterDatabase.DirectPExecute("UPDATE _玩家角色数据 SET 累计抽奖次数 = {} WHERE guid = {}", aaCenter.aa_characterss[guidlow].choujiang, guidlow);
                if (itemids.size() > 0) {
                    std::string items = "{";
                    for (uint32 id : itemids) {
                        items += "\""; items += aaCenter.AA_GetItemLink(id); items += "\",";
                    }
                    items += "}";
                    aaCenter.AA_StringReplaceLast(items, ",}", "}");
                    aaCenter.M_SendClientAddonData(player, "10073", items);
                }
                std::string items = "{";
                if (aaCenter.aa_choujiangStrs.size() > 0) {
                    for (std::string str : aaCenter.aa_choujiangStrs) {
                        items += "\""; items += str; items += "\",";
                    }
                }
                items += "}";
                aaCenter.AA_StringReplaceLast(items, ",}", "}");
                aaCenter.M_SendClientAddonData(player, "10072", items);
            }
        }
        else {
            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的 _奖励_抽奖x_组");
            return false;
        }

        return true;
    }
    static bool AA_caijiwupin(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.采集物品 物品id 组 数量 注释");
            return false;
        }

        uint32 itemId = 0;

        if (args[0] == '[')                                        // [name] manual form
        {
            char const* itemNameStr = strtok((char*)args, "]");

            if (itemNameStr && itemNameStr[0])
            {
                std::string itemName = itemNameStr + 1;
                auto itr = std::find_if(sItemSparseStore.begin(), sItemSparseStore.end(), [&itemName](ItemSparseEntry const* sparse)
                    {
                        for (LocaleConstant i = LOCALE_enUS; i < TOTAL_LOCALES; i = LocaleConstant(i + 1))
                            if (itemName == sparse->Display[i])
                                return true;
                        return false;
                    });

                if (itr == sItemSparseStore.end())
                {
                    handler->PSendSysMessage(LANG_COMMAND_COULDNOTFIND, itemNameStr + 1);
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                itemId = itr->ID;
            }
            else
                return false;
        }
        else                                                    // item_id or [name] Shift-click form |color|Hitem:item_id:0:0:0|h[name]|h|r
        {
            char const* id = handler->extractKeyFromLink((char*)args, "Hitem");
            if (!id)
                return false;

            itemId = Trinity::StringTo<uint32>(id).value_or(0);
        }

        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        if (!itemTemplate)
        {
            handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* arg2 = strtok(nullptr, " ");
        int32 zu = 1;
        if (arg2) {
            zu = int32(std::atoi(arg2));
        }
        char* arg3 = strtok(nullptr, " ");
        uint32 count = 1;
        if (arg3) {
            count = int32(std::atoi(arg3));
        }
        char* arg4 = strtok(nullptr, " ");
        std::string zs = "";
        if (arg4) {
            zs = arg4;
        }
        WorldDatabase.DirectPExecute("INSERT INTO __采集_物品 (注释,组,entry,class,subclass,name,displayid,Quality,抽奖公告开关) VALUES ('{}',{},{},{},{},'{}',{},{},{})", zs, zu, itemTemplate->GetId(), itemTemplate->GetClass(), itemTemplate->GetSubClass(), itemTemplate->GetName(LOCALE_zhCN), 0, itemTemplate->GetQuality(), 1);
        QueryResult result = WorldDatabase.Query("SELECT id from __采集_物品");
        int32 rid = 0;
        if (result) {
            do {
                Field* fields = result->Fetch();
                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
            } while (result->NextRow());
        }
        AA_Caiji_Item conf;
        conf.text = zs;
        conf.id = rid + 1;
        conf.zu = zu;
        conf.chance = 100;
        conf.count = count;
        conf.entry = itemTemplate->GetId();
        conf.class1 = itemTemplate->GetClass();
        conf.subclass = itemTemplate->GetSubClass();
        conf.name = itemTemplate->GetName(LOCALE_zhCN);
        conf.displayid = 0;
        conf.Quality = itemTemplate->GetQuality();
        conf.notice = 1;
        aaCenter.aa_caiji_items[conf.id] = conf;
        aaCenter.aa_caiji_item_zus[conf.zu].push_back(conf.id);
        std::string rs = "|cff00FFFF[采集物品]|cffFFFF00模板id:" + std::to_string(conf.id) + " 组:" + std::to_string(zu) + " name:" + itemTemplate->GetName(LOCALE_zhCN);
        aaCenter.AA_SendMessage(handler->getSelectedPlayerOrSelf(), 0, rs.c_str());
        return true;
    }
    static bool AA_lingquleichong(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a1b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        if (!typestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取累充 数值");
            return false;
        }
        uint32 level = atoi(typestr);
        AA_Reward_Leiji_Conf conf = aaCenter.aa_reward_leiji_confs[level];
        if (conf.jifen > 0) {
            std::vector<int32> levelv; levelv.clear();
            uint32 accountid = player->GetSession()->GetAccountId();
            AA_Account a_conf = aaCenter.aa_accounts[accountid];
            time_t timep;
            time(&timep);
            a_conf.update_time = timep;
            a_conf.isUpdate = true;
            std::string levels = a_conf.leichong;
            aaCenter.AA_StringToVectorInt(levels, levelv, ",");
            bool isOk = false;
            for (size_t i = 0; i < levelv.size(); i++) {
                uint32 leveli = levelv[i];
                if (leveli == conf.jifen) {
                    isOk = true; break;
                }
            }
            if (a_conf.jifen_all < conf.jifen) {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
                return false;
            }
            if (!isOk) { //没有领取过
                if (levels == "") {
                    a_conf.leichong = std::to_string(level);
                }
                else {
                    a_conf.leichong = levels + "," + std::to_string(level);
                }
                aaCenter.aa_accounts[accountid] = a_conf;
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
                aaCenter.M_SendAA_Conf(player, "1005");
                return true;
            }
            else {
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
                return true;
            }
        }
        return true;
    }
    static bool AA_lingqushouchong(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a3b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        time_t time1 = time(NULL);//获取系统时间，单位为秒;
        struct tm* time = localtime(&time1);//转换成tm类型的结构体;
        uint32 day = time->tm_wday == 0 ? 7 : time->tm_wday;
        AA_Reward_Shouchong_Conf it = aaCenter.aa_reward_shouchong_confs[day];
        if (a_conf.shouchong_day < it.jifen) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
            return false;
        }
        if (a_conf.shouchong == 1) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
            return true;
        }
        if (it.reward > 0) {
            aaCenter.M_Reward(player, it.reward);
        }
        if (it.notice > 0) {
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[it.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
        aaCenter.aa_accounts[accountid].shouchong = 1;
        aaCenter.aa_accounts[accountid].isUpdate = true;
        aaCenter.aa_accounts[accountid].update_time = time1;
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
        aaCenter.M_SendAA_Conf(player, "1004");
        return true;
    }
    static bool AA_lingquqiandao(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        if (!typestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取签到 签到索引天数");
            return false;
        }
        uint32 level = atoi(typestr);
        AA_Reward_Qiandao_Conf conf = aaCenter.aa_reward_qiandao_confs[level];
        if (level == 999) { //签到
            uint32 accountid = player->GetSession()->GetAccountId();
            AA_Account a_conf = aaCenter.aa_accounts[accountid];
            if (a_conf.denglu_qiandao == 1) { //已签到
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你今天已经签到了。");
                aaCenter.M_SendAA_Conf(player, "1006");
            }
            else {
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00签到成功");
                aaCenter.aa_accounts[accountid].denglu_qiandao = 1;
                aaCenter.aa_accounts[accountid].denglu_day += 1;
                time_t timep;
                time(&timep);
                aaCenter.aa_accounts[accountid].update_time = timep;
                aaCenter.aa_accounts[accountid].isUpdate = true;
                aaCenter.M_SendAA_Conf(player, "1006");
            }
        }
        else if (level > 0) { //领取奖励
            if (conf.day > 0) {
                std::vector<int32> levelv; levelv.clear();
                uint32 accountid = player->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                std::string levels = a_conf.denglu;
                aaCenter.AA_StringToVectorInt(levels, levelv, ",");
                bool isOk = false;
                for (size_t i = 0; i < levelv.size(); i++) {
                    uint32 leveli = levelv[i];
                    if (leveli == conf.day) {
                        isOk = true; break;
                    }
                }
                if (a_conf.denglu_day < conf.day) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
                    return true;
                }
                if (!isOk) { //没有领取过
                    if (levels == "") {
                        aaCenter.aa_accounts[accountid].denglu = std::to_string(level);
                    }
                    else {
                        aaCenter.aa_accounts[accountid].denglu = levels + "," + std::to_string(level);
                    }
                    time_t timep;
                    time(&timep);
                    aaCenter.aa_accounts[accountid].update_time = timep;
                    aaCenter.aa_accounts[accountid].isUpdate = true;
                    if (conf.reward > 0) {
                        aaCenter.M_Reward(player, conf.reward);
                    }
                    if (conf.notice > 0) {
                        AA_Message aa_message;
                        AA_Notice notice = aaCenter.aa_notices[conf.notice];
                        aaCenter.AA_SendNotice(player, notice, true, aa_message);
                    }
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
                    aaCenter.M_SendAA_Conf(player, "1006");
                }
                else { //已经领取过
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
                }
            }
        }

        return true;
    }
    static bool AA_lingqudengji(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a4b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        if (!typestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取等级 索引等级");
            return false;
        }
        uint32 level = atoi(typestr);
        AA_Reward_Level_Conf conf = aaCenter.aa_reward_level_confs[level];
        if (conf.level > 0) {
            std::vector<int32> levelv; levelv.clear();
            ObjectGuid::LowType guidlow = player->GetGUIDLow();
            AA_Characters aconf = aaCenter.aa_characterss[guidlow];
            AA_Characters_Junxian jxconf = aaCenter.aa_characters_junxians[guidlow];
            AA_Characters_Douqi dqconf = aaCenter.aa_characters_douqis[guidlow];
            AA_Characters_Dianfeng dfconf = aaCenter.aa_characters_dianfengs[guidlow];
            std::string levels = aconf.shengji;
            aaCenter.AA_StringToVectorInt(levels, levelv, ",");
            bool isOk = false;
            for (size_t i = 0; i < levelv.size(); i++) {
                uint32 leveli = levelv[i];
                if (leveli == conf.level) {
                    isOk = true; break;
                }
            }
            if (conf.type == 0) { //等级类型(0普通1vip2军衔3斗气4巅峰)
                if (player->GetLevel() < level) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
                    return false;
                }
            }
            else if (conf.type == 1) {
                uint32 accountid = player->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                if (a_conf.vip < level) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
                    return false;
                }
            }
            else if (conf.type == 2) {
                if (jxconf.level < level) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
                    return false;
                }
            }
            else if (conf.type == 3) {
                if (dqconf.level < level) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
                    return false;
                }
            }
            else if (conf.type == 4) {
                if (dfconf.level < level) {
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
                    return false;
                }
            }
            if (!isOk) { //没有领取过
                if (levels == "") {
                    aaCenter.aa_characterss[player->GetGUIDLow()].shengji = std::to_string(level);
                }
                else {
                    aaCenter.aa_characterss[player->GetGUIDLow()].shengji = levels + "," + std::to_string(level);
                }
                time_t timep;
                time(&timep);
                aaCenter.aa_characterss[player->GetGUIDLow()].update_time = timep;
                aaCenter.aa_characterss[player->GetGUIDLow()].isUpdate = true;
                if (conf.reward > 0) {
                    aaCenter.M_Reward(player, conf.reward);
                }
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
                }
                aaCenter.M_SendAA_Conf(player, "1002");
            }
            else {
                if (conf.notice > 0) {
                    AA_Message aa_message;
                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
                    aaCenter.AA_SendNotice(player, notice, false, aa_message);
                }
                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
            }
        }
        return true;
    }
    static bool AA_lingqulicai(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a2b")) {
            return false;
        }
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 accountid = player->GetSession()->GetAccountId();
        AA_Account a_conf = aaCenter.aa_accounts[accountid];
        time_t timep;
        time(&timep);
        aaCenter.aa_accounts[accountid].update_time = timep;
        aaCenter.aa_accounts[accountid].isUpdate = true;
        AA_Reward_Licai_Conf it = aaCenter.aa_reward_licai_confs[1];
        //                std::string status = "0"; // 0领取 1已领取 2未达到
        if (a_conf.licai_day == 0) { //购买
            if (it.need > 0) {
                if (aaCenter.M_CanNeed(player, it.need)) {
                    aaCenter.M_Need(player, it.need);
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00购买成功");
                    aaCenter.aa_accounts[accountid].licai_day += it.day;
                    aaCenter.M_SendAA_Conf(player, "1003");
                }
            }
        }
        else { // 领取
            if (a_conf.licai == 0) {
                if (it.reward > 0) {
                    aaCenter.M_Reward(player, it.reward);
                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
                    aaCenter.aa_accounts[accountid].licai_day -= 1;
                    aaCenter.aa_accounts[accountid].licai = 1;
                    aaCenter.M_SendAA_Conf(player, "1003");
                    if (it.notice > 0) {
                        AA_Message aa_message;
                        AA_Notice notice = aaCenter.aa_notices[it.notice];
                        aaCenter.AA_SendNotice(player, notice, true, aa_message);
                    }
                }
            }
        }
        return true;
    }
    static bool AA_gerenyinhang(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->GetSession()->SendShowBank(player->GetGUID());
        return true;
    }
    static bool AA_gerenyouxiang(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->GetSession()->SendShowMailBox(player->GetGUID());
        return true;
    }
    static bool AA_zhuangbeixiuli(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->DurabilityRepairAll(false, 0, false);
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修理装备成功!");
        return true;
    }
    static bool AA_chongzhitianfu(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (!player->IsAlive()) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000死亡状态下无法使用!");
            return false;
        }
        Player* me = handler->GetSession()->GetPlayer();
        std::string gm = "";
        if (me == player) {
            gm = ".组合 *.reset talents<$自身>";
            if (me->IsInWorld()) {
                if (Pet* pet = me->GetPet()) {
                    if (pet->IsInWorld()) {
                        pet->RemoveFromWorld();
                    }
                }
            }
        }
        else {
            gm = ".组合 *.reset talents<$目标>";
        }
        uint8 spec = player->GetActiveTalentGroup();
        if (spec != 0) {
            player->SetActiveTalentGroup(0);
            player->SendTalentsInfoData();
        }

        aaCenter.AA_DoCommand(player, gm.c_str());
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00天赋重置成功!");
        return true;
    }
    static bool AA_jiechuxuruo(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (player->HasAura(15007)) { player->RemoveAura(15007); }
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00解除虚弱成功!");
        return true;
    }

    static bool AA_jiechuzhandou(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (player->combatTime > 10000) {
            player->ClearInCombat();
            player->combatTime = 0;
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00脱离战斗成功!");
        }
        else {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000功能冷却中!");
        }
        return true;
    }
    static bool AA_huifuhpmp(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        if (player->GetPowerType() == POWER_MANA) {
            player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
        }
        player->SetHealth(player->GetMaxHealth());
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00恢复生命和魔法!");
        return true;
    }
    static bool AA_chongzhijineng(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->RemoveArenaSpellCooldowns();
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置冷却成功!");
        return true;
    }
    static bool AA_xiugaizhenying(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
        std::string gm = ".组合 *.character changefaction<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        return true;
    }
    static bool AA_xiugaizhongzhu(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
        std::string gm = ".组合 *.character changerace<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        return true;
    }
    static bool AA_xiugaimingzi(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
        std::string gm = ".组合 *.character rename<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        return true;
    }
    static bool AA_xiugaiwaiguan(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
        std::string gm = ".组合 *.character customize<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        return true;
    }
    static bool AA_dianfengshuxing(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        char* valuestr = strtok(NULL, " ");
        if (!typestr || !valuestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.巅峰属性 属性类型 属性值");
            return false;
        }
        uint32 type = atoi(typestr);
        uint32 value = atoi(valuestr);
        if (type != 1000)
        {
            if (type < 0) {
                return false;
            }
        }
        if (value <= 0) {
            return false;
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Dianfeng d_conf = aaCenter.aa_characters_dianfengs[guidlow];
        if (d_conf.dianshu == -1) { //重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
            return false;
        }
        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
            int32 num = 0;
            {
                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
                aaCenter.AA_SendMessage(player, 1, msg.c_str());
                return false;
            }
        }
        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
            return false;
        }
        aaCenter.aa_characters_dianfengs[guidlow].dianshu = d_conf.dianshu + 1;
        if (type == 1000) { //天赋
            //aaCenter.aa_characters_dianfengs[guidlow].tianfu = d_conf.tianfu + value;
            //player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
            //if (!player->GetSession()->PlayerLoading())
            //    player->SendTalentsInfoData();                         // update at client
        }
        else {
            std::map<int32, int32> values; values.clear();
            aaCenter.AA_StringToMap(d_conf.value, values);
            values[type] += value;
            std::string str = "";
            aaCenter.AA_MapToString(values, str);
            aaCenter.aa_characters_dianfengs[guidlow].value = str;
            aaCenter.AddValue(player, type, value, true);
        }
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
        aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_douqishuxing(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        char* valuestr = strtok(NULL, " ");
        if (!typestr || !valuestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.斗气属性 属性类型 属性值");
            return false;
        }
        uint32 type = atoi(typestr);
        uint32 value = atoi(valuestr);
        if (type != 1000)
        {
            if (type < 0) {
                return false;
            }
        }
        if (value <= 0) {
            return false;
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Douqi d_conf = aaCenter.aa_characters_douqis[guidlow];
        if (d_conf.dianshu == -1) { //重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
            return false;
        }
        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
            int32 num = 0;
            {
                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
                aaCenter.AA_SendMessage(player, 1, msg.c_str());
                return false;
            }
        }
        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
            return false;
        }
        aaCenter.aa_characters_douqis[guidlow].dianshu = d_conf.dianshu + 1;
        if (type == 1000) { //天赋
            //aaCenter.aa_characters_douqis[guidlow].tianfu = d_conf.tianfu + value;
            //player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
            //if (!player->GetSession()->PlayerLoading())
            //    player->SendTalentsInfoData(false);                         // update at client
        }
        else {
            std::map<int32, int32> values; values.clear();
            aaCenter.AA_StringToMap(d_conf.value, values);
            values[type] += value;
            std::string str = "";
            aaCenter.AA_MapToString(values, str);
            aaCenter.aa_characters_douqis[guidlow].value = str;
            aaCenter.AddValue(player, type, value, true);
        }
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_douqis[guidlow].update_time = timep;
        aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_junxianshuxing(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        char* valuestr = strtok(NULL, " ");
        if (!typestr || !valuestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.军衔属性 属性类型 属性值");
            return false;
        }
        uint32 type = atoi(typestr);
        uint32 value = atoi(valuestr);
        if (type != 1000)
        {
            if (type < 0) {
                return false;
            }
        }
        if (value <= 0) {
            return false;
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Junxian d_conf = aaCenter.aa_characters_junxians[guidlow];
        if (d_conf.dianshu == -1) { //重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
            return false;
        }
        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
            int32 num = 0;
            {
                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            {
                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
                std::map<int32, int32> values; values.clear();
                aaCenter.AA_StringToMap(c_value, values);
                num += values[type];
            }
            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
                aaCenter.AA_SendMessage(player, 1, msg.c_str());
                return false;
            }
        }
        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
            return false;
        }
        aaCenter.aa_characters_junxians[guidlow].dianshu = d_conf.dianshu + 1;
        if (type == 1000) { //天赋
            //aaCenter.aa_characters_junxians[guidlow].tianfu = d_conf.tianfu + value;
            //player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
            //if (!player->GetSession()->PlayerLoading())
            //    player->SendTalentsInfoData(false);                         // update at client
        }
        else {
            std::map<int32, int32> values; values.clear();
            aaCenter.AA_StringToMap(d_conf.value, values);
            values[type] += value;
            std::string str = "";
            aaCenter.AA_MapToString(values, str);
            aaCenter.aa_characters_junxians[guidlow].value = str;
            aaCenter.AddValue(player, type, value, true);
        }
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_junxians[guidlow].update_time = timep;
        aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_chongzhidianfeng(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 need = aaCenter.aa_world_confs[51].value1;
        if (need > 0) {
            if (!aaCenter.M_CanNeed(player, need)) {
                return false;
            }
            aaCenter.M_Need(player, need);
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Dianfeng d_conf = aaCenter.aa_characters_dianfengs[guidlow];
        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000没有可重置的点数!");
            return false;
        }
        aaCenter.aa_characters_dianfengs[guidlow].value = "";
        aaCenter.aa_characters_dianfengs[guidlow].dianshu = -1;
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
        aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_chongzhidouqi(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 need = aaCenter.aa_world_confs[53].value1;
        if (need > 0) {
            if (!aaCenter.M_CanNeed(player, need)) {
                return false;
            }
            aaCenter.M_Need(player, need);
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Douqi d_conf = aaCenter.aa_characters_douqis[guidlow];
        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00没有可重置的点数!");
            return false;
        }
        aaCenter.aa_characters_douqis[guidlow].value = "";
        aaCenter.aa_characters_douqis[guidlow].dianshu = -1;
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_douqis[guidlow].update_time = timep;
        aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_chongzhijunxian(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 need = aaCenter.aa_world_confs[52].value1;
        if (need > 0) {
            if (!aaCenter.M_CanNeed(player, need)) {
                return false;
            }
            aaCenter.M_Need(player, need);
        }
        ObjectGuid::LowType guidlow = player->GetGUIDLow();
        AA_Characters_Junxian d_conf = aaCenter.aa_characters_junxians[guidlow];
        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00没有可重置的点数!");
            return false;
        }
        aaCenter.aa_characters_junxians[guidlow].value = "";
        aaCenter.aa_characters_junxians[guidlow].dianshu = -1;
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
        time_t timep;
        time(&timep);
        aaCenter.aa_characters_junxians[guidlow].update_time = timep;
        aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
        return true;
    }
    static bool AA_huiyuanshengji(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint32 accountid = player->GetSession()->GetAccountId();
        uint32 viplevel = aaCenter.aa_accounts[accountid].vip + 1;
        AA_Vip_Conf conf = aaCenter.aa_vip_confs[viplevel];
        if (conf.level <= 0) {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已达到最大会员等级");
            return false;
        }
        if (conf.need > 0) {
            if (!aaCenter.M_CanNeed(player, conf.need)) {
                return false;
            }
            else {
                aaCenter.M_Need(player, conf.need);
            }
        }
        aaCenter.aa_accounts[accountid].vip = viplevel;
        AA_Vip_Conf vip_conf = aaCenter.aa_vip_confs[viplevel];
        if (vip_conf.reward > 0) {
            aaCenter.M_Reward(player, vip_conf.reward);
        }
        if (vip_conf.notice > 0) {
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[vip_conf.notice];
            aaCenter.AA_SendNotice(player, notice, true, aa_message);
        }
        return true;
    }
    static bool AA_paihangjiangli(ChatHandler* handler, const char* args)
    {
        if (!aaCenter.AA_VerifyCode("a200b")) {
            return false;
        }
        Player* me = handler->getSelectedPlayerOrSelf();
        if (!me || !me->IsInWorld()) {
            return false;
        }
        aaCenter.AA_PaihangReward();
        return true;
    }
    static bool AA_bianshen(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            char* disstr = strtok((char*)args, " ");
            char* scalestr = strtok(NULL, " ");
            char* timestr = strtok(NULL, " ");
            if (!disstr || !scalestr)
            {
                ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.变身 模型id 模型大小 变身单位秒（可选）");
                return false;
            }
            uint32 display = atoi(disstr);
            double scale = aaCenter.AA_StringFloat(scalestr);
            uint32 time = 0;
            if (timestr) {
                time = atoi(timestr);
            }

            std::string msg = "";
            if (target->GetDisplayId() == display) {
                aaCenter.aa_bianshen1[target->GetGUIDLow()] = 0;
                aaCenter.aa_bianshen2[target->GetGUIDLow()] = 0;
                target->RestoreDisplayId();
                target->SetObjectScale(1);
                if (time == 0) {
                    std::string gm = ".组合 *.变量 角色 modelid =0<$自身>";
                    aaCenter.AA_DoCommand(target, gm.c_str());
                    gm = ".组合 *.变量 角色 scale =0<$自身>";
                    aaCenter.AA_DoCommand(target, gm.c_str());
                }
                time = 0;
            }
            else {
                aaCenter.aa_bianshen1[target->GetGUIDLow()] = display;
                aaCenter.aa_bianshen2[target->GetGUIDLow()] = scale;
                if (time == 0) {
                    std::string gm = ".组合 *.变量 角色 modelid =" + std::to_string(display) + "<$自身>";
                    aaCenter.AA_DoCommand(target, gm.c_str());
                    gm = ".组合 *.变量 角色 scale =" + std::to_string(scale) + "<$自身>";
                    aaCenter.AA_DoCommand(target, gm.c_str());
                }
            }
            aaCenter.aa_bianshen3[target->GetGUIDLow()] = time * 1000;
        }
        return true;
    }
    static bool AA_shasiquantu(ChatHandler* handler, const char* args)
    {
        Player* me = handler->getSelectedPlayerOrSelf();
        std::list<Creature*> list; list.clear();
        aaCenter.BB_GetCreatureListInMap(me, list, me->GetMapId());
        for (Creature* target : list)
        {
            if (target->IsAlive())
            {
                if (sWorld->getBoolConfig(CONFIG_DIE_COMMAND_MODE))
                {
                    if (target->GetTypeId() == TYPEID_UNIT && handler->GetSession()->GetSecurity() == SEC_CONSOLE) // pussywizard
                        target->ToCreature()->LowerPlayerDamageReq(target->GetMaxHealth());
                    Unit::Kill(handler->getSelectedPlayerOrSelf(), target);
                }
                else
                    Unit::DealDamage(handler->getSelectedPlayerOrSelf(), target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false, true);
            }

        }

        return true;
    }
    static bool AA_zhuanye(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.专业 专业中文拼音缩写 数值，如.专业 cy 450");
            return false;
        }

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* skillName = strtok((char*)args, " ");
        char* value = strtok(NULL, " ");
        if (!skillName || !value)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.专业 专业中文拼音缩写 数值，如.专业 cy 450");
            return false;
        }

        uint32 skillid = 0;

        if (strcmp(skillName, "cy") == 0)        skillid = 182;
        else if (strcmp(skillName, "ck") == 0)    skillid = 186;
        else if (strcmp(skillName, "bp") == 0)    skillid = 393;
        else if (strcmp(skillName, "dz") == 0)    skillid = 164;
        else if (strcmp(skillName, "cf") == 0)    skillid = 197;
        else if (strcmp(skillName, "zp") == 0)    skillid = 165;
        else if (strcmp(skillName, "gc") == 0)    skillid = 202;
        else if (strcmp(skillName, "lj") == 0)    skillid = 171;
        else if (strcmp(skillName, "mw") == 0)    skillid = 773;
        else if (strcmp(skillName, "fm") == 0)    skillid = 333;
        else if (strcmp(skillName, "zb") == 0)    skillid = 755;
        else if (strcmp(skillName, "jj") == 0)    skillid = 129;
        else if (strcmp(skillName, "pr") == 0)    skillid = 185;
        else if (strcmp(skillName, "dy") == 0)    skillid = 356;

        int32 point = atoi(value);

        if (skillid == 0 || point <= 0)
            return false;

        if (target->HasSkill(skillid) && target->GetSkillValue(skillid) < point)
            target->SetSkill(skillid, 1, point, point);

        return true;
    }
    static bool AA_zhaohuan(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.召唤 参数1：entry（正数 - Creature Entry;负数 - Gameobject Entry) 参数2：存在时间(Creature或Gameobject持续的时间，单位秒）参数3 ：难度id(可选参数，_属性调整_生物_id或_属性调整_物体_id 参数4：坐标x（可选） 参数5：坐标y（可选） 参数6：坐标z（可选） 参数7：坐标o（可选）");
            return false;
        }

        char* s_entry = strtok((char*)args, " ");
        char* s_time = strtok(NULL, " ");
        char* n_id = strtok(NULL, " ");
        char* xstr = strtok(NULL, " ");
        char* ystr = strtok(NULL, " ");
        char* zstr = strtok(NULL, " ");
        char* ostr = strtok(NULL, " ");

        if (!s_entry || !s_time)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.召唤 参数1：entry（正数 - Creature Entry;负数 - Gameobject Entry) 参数2：存在时间(Creature或Gameobject持续的时间，单位秒）参数3 ：难度id(可选参数，_属性调整_生物_id或_属性调整_物体_id 参数4：坐标x（可选） 参数5：坐标y（可选） 参数6：坐标z（可选） 参数7：坐标o（可选）");
            return false;
        }
        float x = 0;
        float y = 0;
        float z = 0;
        float o = 0;
        if (xstr) {
            x = (float)atof(xstr);
        }
        if (ystr) {
            y = (float)atof(ystr);
        }
        if (zstr) {
            z = (float)atof(zstr);
        }
        if (ostr) {
            o = (float)atof(ostr);
        }

        int32 entry = atoi(s_entry);
        uint32 time = atoi(s_time);
        uint32 nandu = 0;
        if (n_id) {
            nandu = atoi(n_id);
        }
        Map* map = target->GetMap();
        if (!map) {
            return false;
        }

        Position pos;
        if (x != 0) {
            pos.m_positionX = x;
            pos.m_positionY = y;
            pos.m_positionZ = z;
            pos.SetOrientation(o);
        }
        else {
            pos.m_positionX = target->GetPositionX();
            pos.m_positionY = target->GetPositionY();
            pos.m_positionZ = target->GetPositionZ();
            pos.SetOrientation(target->GetOrientation());
        }
        if (entry > 0) {
            Creature* creature = nullptr;

            if (Map* map = target->GetMap()) {
                creature = target->SummonCreature(entry, pos, TEMPSUMMON_TIMED_DESPAWN, time * 1s);
            }
            if (nandu > 0) {
                AA_Creature conf = aaCenter.aa_creatures[nandu];
                if (conf.id > 0) {
                    creature->aa_id = conf.id;
                    creature->SelectLevel();
                }
            }
            AA_Boss_Conf bconf = aaCenter.aa_boss_confs[entry];

            if (creature && bconf.id > 0) {
                creature->aa_boss_id = bconf.id;
                creature->aa_boss_time_max = (time / 60);
                creature->aa_boss_time = 0;
                creature->aa_boss_dmg.clear();
            }
        }
        else if (entry < 0) {
            GameObject* gameObject = target->SummonGameObject(abs(entry), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), QuaternionData(), time * 1s);

            if (nandu > 0) {
                AA_Object conf = aaCenter.aa_objects[nandu];
                if (conf.id > 0) {
                    aaCenter.AA_ModifyGameObject(gameObject, conf);
                }
            }
        }

        return true;
    }

    static bool AA_zhaohuanmoban(ChatHandler* handler, const char* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!*args)
        {
            if (target) {
                aaCenter.AA_SendMessage(target, 1, "语法格式:.召唤模板 参数1:（__采集_生物_组 time） 参数2（Creature或Gameobject持续的时间，单位 秒)  参数3，可选（是否组内随机，0组内按几率随机一个，1组内全部召唤）  参数4，可选(_属性调整_生物_id或_属性调整_物体_id");
            }
            return false;
        }

        if (!target->GetMap()) {
            return false;
        }

        char* s_zu = strtok((char*)args, " ");
        char* s_time = strtok(NULL, " ");
        char* s_suiji = strtok(NULL, " ");
        char* n_id = strtok(NULL, " ");

        if (!s_zu || !s_time)
        {
            if (target) {
                aaCenter.AA_SendMessage(target, 1, "语法格式:.召唤模板 参数1:（__采集_生物_组 time） 参数2（Creature或Gameobject持续的时间，单位 秒)  参数3，可选（是否组内随机，0组内按几率随机一个，1组内全部召唤）  参数4，可选(_属性调整_生物_id或_属性调整_物体_id");
            }
            return false;
        }

        int32 zu = atoi(s_zu);
        uint32 time = atoi(s_time);
        uint32 suiji = 0;
        uint32 nandu = 0;
        if (s_suiji) {
            suiji = atoi(s_suiji);
        }
        if (n_id) {
            nandu = atoi(n_id);
        }

        std::vector<uint32> conf_ids = aaCenter.aa_caiji_creature_zus[zu];
        if (suiji == 0) {
            //获取总chance，分母
            int count = conf_ids.size();
            if (count) {
                uint32 chanceMax = 0;
                for (int i = 0; i < count; i++) {
                    uint32 id = conf_ids[i];
                    AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
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
                    AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
                    max = conf.chance + max;
                    min = 0;
                    if (i == 0) {
                        min = 0;
                    }
                    else {
                        uint32 id = conf_ids[i - 1];
                        AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
                        min = conf.chance + min;
                    }

                    if (min <= chanceVal && chanceVal < max) {
                        index = i;
                        break;
                    }
                }
                uint32 id = conf_ids[index];
                conf_ids.clear();
                conf_ids.push_back(id);
            }
        }
        for (auto id : conf_ids) {
            AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
            Map* map = nullptr;
            if (map = sMapMgr->CreateMap(conf.map, target)) {
                if (map->IsDungeon()) {//如果是副本，并且自己也在当前副本，召唤生物。
                    if (target->GetMapId() == conf.map) {
                        map = sMapMgr->FindMap(conf.map, target->GetInstanceId());
                    }
                }
            }
            if (!map) {
                continue;
            }
            if (conf.entry > 0) {
                Creature* creature = nullptr;

                Position pos;
                pos.m_positionX = conf.position_x;
                pos.m_positionY = conf.position_y;
                pos.m_positionZ = conf.position_z;
                pos.SetOrientation(conf.orientation);

                creature = target->SummonCreature(conf.entry, pos, TEMPSUMMON_TIMED_DESPAWN, time * 1s);
                if (creature) {
                    if (nandu > 0) {
                        AA_Creature conf = aaCenter.aa_creatures[nandu];
                        if (conf.id > 0) {
                            creature->aa_id = conf.id;
                            creature->SelectLevel();
                        }
                    }

                    AA_Boss_Conf bconf = aaCenter.aa_boss_confs[conf.entry];
                    if (creature && bconf.id > 0) {
                        creature->aa_boss_id = bconf.id;
                        creature->aa_boss_time_max = (time / 60);
                        creature->aa_boss_time = 0;
                        creature->aa_boss_dmg.clear();
                    }
                }
            }
            else {
                GameObject* gameObject = target->SummonGameObject(abs(conf.entry), conf.position_x, conf.position_y, conf.position_z, conf.orientation, QuaternionData(), time * 1s);

                if (nandu > 0) {
                    AA_Object conf = aaCenter.aa_objects[nandu];
                    if (conf.id > 0) {
                        aaCenter.AA_ModifyGameObject(gameObject, conf);
                    }
                }
            }
        }

        return true;
    }
    static bool AA_chongzhilicailingqu(ChatHandler* handler, char const* args)
    {
        Player* receiver = handler->getSelectedPlayerOrSelf();
        if (!receiver || !receiver->IsInWorld()) {
            return false;
        }
        time_t timep;
        time(&timep);
        if (receiver) {
            uint32 accountid = receiver->GetSession()->GetAccountId();
            AA_Account conf = aaCenter.aa_accounts[accountid];
            conf.id = accountid;
            conf.licai = 0;
            conf.isUpdate = true;
            conf.update_time = timep;
            aaCenter.aa_accounts[accountid] = conf;
        }
        ChatHandler(handler->GetSession()).PSendSysMessage("重置理财领取状态成功");
        return true;
    }
    static bool AA_chongzhishouchonglingqu(ChatHandler* handler, char const* args)
    {
        Player* receiver = handler->getSelectedPlayerOrSelf();
        if (!receiver || !receiver->IsInWorld()) {
            return false;
        }
        time_t timep;
        time(&timep);
        if (receiver) {
            uint32 accountid = receiver->GetSession()->GetAccountId();
            AA_Account conf = aaCenter.aa_accounts[accountid];
            conf.id = accountid;
            conf.shouchong = 0;
            conf.isUpdate = true;
            conf.update_time = timep;
            aaCenter.aa_accounts[accountid] = conf;
        }
        ChatHandler(handler->GetSession()).PSendSysMessage("重置首充领取状态成功");
        return true;
    }
    static bool AA_chongzhiqiandaolingqu(ChatHandler* handler, char const* args)
    {
        Player* receiver = handler->getSelectedPlayerOrSelf();
        if (!receiver || !receiver->IsInWorld()) {
            return false;
        }
        time_t timep;
        time(&timep);
        if (receiver) {
            uint32 accountid = receiver->GetSession()->GetAccountId();
            AA_Account conf = aaCenter.aa_accounts[accountid];
            conf.id = accountid;
            conf.denglu_qiandao = 0;
            conf.isUpdate = true;
            conf.update_time = timep;
            aaCenter.aa_accounts[accountid] = conf;
        }
        ChatHandler(handler->GetSession()).PSendSysMessage("重置签到领取状态成功");
        return true;
    }
    static bool AA_youjian(ChatHandler* handler, char const* args)
    {
        // format: name "subject text" "mail text"
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        char* tail1 = strtok(nullptr, "");
        if (!tail1)
            return false;

        char const* msgSubject = handler->extractQuotedArg(tail1);
        if (!msgSubject)
            return false;

        char* tail2 = strtok(nullptr, "");
        if (!tail2)
            return false;

        char const* msgText = handler->extractQuotedArg(tail2);
        if (!msgText)
            return false;

        // msgSubject, msgText isn't NUL after prev. check
        std::string subject = msgSubject;
        std::string text = msgText;

        // from console, use non-existing sender
        MailSender sender(MAIL_NORMAL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetGUID().GetCounter() : UI64LIT(0), MAIL_STATIONERY_GM);

        /// @todo Fix poor design
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        MailDraft(subject, text)
            .SendMailTo(trans, MailReceiver(target, targetGuid.GetCounter()), sender);

        CharacterDatabase.CommitTransaction(trans);

        std::string nameLink = handler->playerLink(targetName);
        handler->PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
        return true;
    }
    static bool AA_jiaxue(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();

        if (!player)
            return false;

        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.加血 生物编号 血量");
            return false;
        }

        char* s_entry = strtok((char*)args, " ");
        char* s_health = strtok(NULL, " ");

        if (!s_entry || !s_health)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.加血 生物编号 血量");
            return false;
        }

        uint32 entry = atoi(s_entry);
        uint32 health = atoi(s_health);

        if (Creature* c = player->FindNearestCreature(entry, 1000.0f))
            c->ModifyHealth(health);

        return true;
    }
    static bool AA_jieka(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
            return true;

        if (!*args)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.解卡 角色名");
            return false;
        }

        char* name = strtok((char*)args, " ");
        std::string currName = target->GetName();
        if (target->GetName() == name) {
            //该角色不属于您的账号，请重新输入
            //无法解卡自己
            //没有该角色，请重新输入
            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000无法解卡自己");
            return false;
        }
        else {
            uint32 currAccountId = 0; //目标玩家
            {
                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = \"{}\"", currName);
                if (result)
                {
                    Field* fields = result->Fetch();
                    currAccountId = fields[0].GetUInt32();
                }
            }
            if (currAccountId == 0) {
                return false;
            }
            uint32 accountId = 0; //当前角色
            {
                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = \"{}\"", name);
                if (result)
                {
                    Field* fields = result->Fetch();
                    accountId = fields[0].GetUInt32();
                }
            }
            if (accountId == 0) {
                aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000没有该角色，请重新输入");
                return false; //未知错误
            }
            if (currAccountId != accountId) {
                aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000该角色不属于您的账号，请重新输入");
                return false;
            }
        }

        CharacterDatabase.DirectPExecute("UPDATE characters SET position_x = {},position_y = {}, position_z = {}, map = {}, instance_id = 0, instance_mode_mask = 0 where name=\"{}\";", target->m_homebind.GetPositionX(), target->m_homebind.GetPositionY(), target->m_homebind.GetPositionZ(), target->m_homebind.GetMapId(), currName);
        aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|r|cffFFFF00解卡成功，角色已经被传送至出生点");
        return true;
    }
    static bool AA_chongzhirirenwu(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->DailyReset();
        return true;
    }
    static bool AA_chongzhizhourenwu(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->ResetWeeklyQuestStatus();
        return true;
    }
    static bool AA_chongzhiyuerenwu(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        player->ResetMonthlyQuestStatus();
        return true;
    }
    static bool AA_zuhe(ChatHandler* handler, char const* args)
    {
        if (!aaCenter.AA_VerifyCode("a6b")) {
            return false;
        }
        Player* me = handler->GetSession()->GetPlayer();
        if (!me || !me->IsInWorld()) {
            return false;
        }
        if (!args) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.组合 *.命令");
            return false;
        }
        std::string argstr = std::string(args);
        aaCenter.AA_StringReplaceFirst(argstr, "*", "");
        //.组合*.xx*.xx*.xx<$需求@1><$队伍><$公会@AA>
        //1、取命令
        std::vector<std::string> gms; gms.clear();
        aaCenter.AA_StringToVectorString(std::string(argstr), gms, "*");
        int32 count = gms.size();
        for (int32 i = 0; i < count; i++) {
            std::string gm = AA_SafeStringAtIndex(gms, i);
            if (gm != "") {
                std::set<Player*> players; players.clear();
                players = aaCenter.AA_GetPlayerRange(me, gm);
                int need = 0;
                if (gm.find("<$需求@") != std::string::npos) {
                    std::string prestr = "<$需求@";
                    std::string nums = aaCenter.AA_StringGet(gm, prestr, ">");
                    if (nums != "") {
                        need = atoi(nums.c_str());
                    }
                }
                for (Player* p : players) {
                    if (need > 0) {
                        if (aaCenter.M_CanNeed(p, need)) {
                        }
                        else {
                            continue;
                        }
                    }
                    std::string gmstr = gm;
                    if (gm.find("<$") != std::string::npos) {
                        gmstr = "." + aaCenter.AA_StringGet(gm, ".", "<");
                    }
                    bool isOk = aaCenter.AA_DoCommand(p, gmstr.c_str());
                    if (isOk && need > 0) {
                        aaCenter.M_Need(p, need);
                    }
                }
            }
        }
        return true;
    }
    static bool AA_suiji(ChatHandler* handler, char const* args)
    {
        if (!aaCenter.AA_VerifyCode("a6b")) {
            return false;
        }
        Player* me = handler->GetSession()->GetPlayer();
        if (!me || !me->IsInWorld()) {
            return false;
        }
        if (!args) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.随机 *.命令");
            return false;
        }
        std::string argstr = std::string(args);
        aaCenter.AA_StringReplaceFirst(argstr, "*", "");
        //.组合*.xx*.xx*.xx<$需求@1><$队伍><$公会@AA>
        //1、取命令
        std::vector<std::string> gms; gms.clear();
        aaCenter.AA_StringToVectorString(std::string(argstr), gms, "*");
        int32 count = gms.size();
        int32 randomIndex = rand() % count;
        std::string gm = AA_SafeStringAtIndex(gms, randomIndex);
        if (gm != "") {
            std::set<Player*> players; players.clear();
            players = aaCenter.AA_GetPlayerRange(me, gm);
            int need = 0;
            if (gm.find("<$需求@") != std::string::npos) {
                std::string prestr = "<$需求@";
                std::string nums = aaCenter.AA_StringGet(gm, prestr, ">");
                if (nums != "") {
                    need = atoi(nums.c_str());
                }
            }
            for (Player* p : players) {
                if (need > 0) {
                    if (aaCenter.M_CanNeed(p, need)) {
                    }
                    else {
                        continue;
                    }
                }
                std::string gmstr = gm;
                if (gm.find("<$") != std::string::npos) {
                    gmstr = "." + aaCenter.AA_StringGet(gm, ".", "<");
                }
                bool isOk = aaCenter.AA_DoCommand(p, gmstr.c_str());
                if (isOk && need > 0) {
                    aaCenter.M_Need(p, need);
                }
            }
        }
        return true;
    }
    static bool AA_lingqujifen(ChatHandler* handler, char const* /*args*/)
    {
        Player* me = handler->getSelectedPlayerOrSelf();
        if (!me || !me->IsInWorld()) {
            return false;
        }
        uint32 accountid = me->GetSession()->GetAccountId();
        AA_Account conf = aaCenter.aa_accounts[accountid];
        QueryResult result = LoginDatabase.PQuery("SELECT jifen from _aa_account where id = {}", accountid);
        int32 jifen_cz = conf.jifen_cz;
        if (result) {
            Field* fields = result->Fetch();
            uint32 jifen = fields[0].GetUInt32();
            if (jifen > 0) {
                jifen_cz += jifen;
            }
        }
        if (jifen_cz > 0) {
            conf.jifen += jifen_cz;
            conf.jifen_all += jifen_cz;
            conf.jifen_day += jifen_cz;
            if (conf.shouchong_day == 0) {
                conf.shouchong_day += jifen_cz;
            }
            conf.jifen_cz = 0;
            time_t timep;
            time(&timep);
            conf.isUpdate = true;
            conf.update_time = timep;
            aaCenter.aa_accounts[accountid] = conf;
            LoginDatabase.DirectPExecute("UPDATE _aa_account SET 当前积分 = {},jifen = 0,累计充值积分={},每日累充积分={},每日首充积分={},更新时间=0 WHERE id = {};", conf.jifen, conf.jifen_all, conf.jifen_day, conf.shouchong_day, conf.id);
            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[64].value2 + "增加：" + std::to_string(jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), me);
            std::string jfstr = "|cff00FFFF[系统提示]|r|cffFFFF00恭喜玩家【" + aaCenter.AA_GetPlayerNameLink(me) + "】获得充值奖励，" + aaCenter.aa_world_confs[64].value2 + "增加【" + std::to_string(jifen_cz) + "】！";
            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
            aaCenter.M_SendAA_Conf(me, "1004");
            aaCenter.M_SendAA_Conf(me, "1005");
        }
        return true;
    }

    static bool AA_zhuanzhi(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        uint8 newclass = uint8(std::atoi(args));
        //检查
        if (!player || !player->IsInWorld() || !player->IsAlive() || player->IsInCombat() || player->GetClass() == newclass || newclass <= 0 || newclass >= MAX_CLASSES)
            return false;

        std::string newclasstext = aaCenter.GetPlayerClass(newclass);
        // xinef: learn default race/class spells
        PlayerInfo const* sinfo = sObjectMgr->GetPlayerInfo(player->GetRace(), newclass);
        if (!sinfo) {
            std::string message = "|cff00FFFF[系统提示]|cffFF0000你的种族不适合[" + newclasstext + "]职业";
            ChatHandler(player->GetSession()).PSendSysMessage("{}", message.c_str());
            aaCenter.AA_SendMessage(player, 1, message.c_str());
            return false;
        }
        //移除宠物 与相关的东西
        if (Pet* pet = player->GetPet())
        {
            uint32 PGuid = pet->GetCharmInfo()->GetPetNumber();
            player->RemovePet(pet, PET_SAVE_NOT_IN_SLOT);
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME);
            stmt->setUInt32(0, PGuid);
            trans->Append(stmt);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
            stmt->setUInt32(0, PGuid);
            trans->Append(stmt);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELLS);
            stmt->setUInt32(0, PGuid);
            trans->Append(stmt);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_COOLDOWNS);
            stmt->setUInt32(0, PGuid);
            trans->Append(stmt);
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_OWNER);
            stmt->setUInt64(0, player->GetGUIDLow());
            trans->Append(stmt);
            CharacterDatabase.CommitTransaction(trans);
        }
        //遗忘技能
        if (player->HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
            player->RemoveAtLoginFlag(AT_LOGIN_RESET_SPELLS, true);

        PlayerSpellMap spellMap = player->GetSpellMap();

        for (PlayerSpellMap::const_iterator iter = spellMap.begin(); iter != spellMap.end(); ++iter)
        {
            AA_Zhuanzhi_Spell conf = aaCenter.aa_zhuanzhi_spells[iter->first];
            if (conf.spellid > 0 && conf.spellid == iter->first) {
                continue;
            }
            player->RemoveSpell(iter->first, false, false);
        }

        for (uint32 id = 0; id < sSkillLineStore.GetNumRows(); id++)
        {
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(id);
            if (!pSkill)
                continue;

            if (pSkill->CategoryID != SKILL_CATEGORY_CLASS)
                continue;

            player->SetSkill(id, 0, 0, 0);
        }

        //重置天赋
        player->ResetTalents();
        player->InitTalentForLevel();
        player->SendTalentsInfoData();

        //执行转职
        player->SetClass(newclass);

        //更新角色新职业信息
        //        sWorld->UpdateGlobalPlayerData(player->GetGUIDLow(), PLAYER_UPDATE_DATA_CLASS, player->GetName(), player->GetLevel(), player->GetGender(), player->GetRace(), newclass);

        //强制把身上不符合新职业的武器装备卸下 有位置就放 没位置自动发到邮箱里
        for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            {
                if (!pItem->IsInWorld()) {
                    continue;
                }
                ItemPosCountVec dest;
                uint8 Msg = player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, pItem, false);
                if (Msg == EQUIP_ERR_OK)
                {
                    player->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    player->StoreItem(dest, pItem, true);
                }
                else
                {
                    player->MoveItemFromInventory(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
                    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                    pItem->DeleteFromInventoryDB(trans);
                    pItem->SaveToDB(trans);
                    MailDraft("转职", "这些装备不支持新职业").AddItem(pItem).SendMailTo(trans, player, MailSender(player, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);
                    CharacterDatabase.CommitTransaction(trans);
                }
            }
        }

        //保存角色信息
        player->SaveToDB();
        //重新学习默认技能
        player->LearnDefaultSkills();
        player->LearnCustomSpells();
        //重置属性获取对应职业的Power(能量条/怒气条之类的)
        player->InitStatsForLevel(true);
        //如果新职业是DK就载入符文冷却
        if (newclass == CLASS_DEATH_KNIGHT) {
            player->InitRunes();
        }
        //更新角色属性
        player->SetCanModifyStats(true);
        player->UpdateAllStats();

        //CharacterDatabase.DirectPExecute("update characters set class={} where guid ={}", targetClass, player->GetGUIDLow()); //更新转职后的职业
        CharacterDatabase.DirectPExecute("delete from character_glyphs where guid ={}", player->GetGUIDLow()); // 删除雕文
        CharacterDatabase.DirectPExecute("delete from character_pet where owner ={}", player->GetGUIDLow());//删除宠物

        std::string gm = ".组合 *.cache delete<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        gm = ".组合 *.cache refresh<$自身>";
        aaCenter.AA_DoCommand(player, gm.c_str());
        //Customize(GetGUID(), GetGender(), 1, 1, 1, 1, 1);
//        player->GetSession()->KickPlayer("GlobalMethods::Kick Kick the player");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");
        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");

        return true;
    }


    static bool AA_jifen(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            uint32 accountid = target->GetSession()->GetAccountId();
            int32 jifen_cz = int32(std::atoi(args));
            if (jifen_cz >= 0) {
                time_t timep;
                time(&timep);
                AA_Account conf = aaCenter.aa_accounts[accountid];
                int32 jfcz = (int32)conf.jifen_cz + jifen_cz;
                conf.jifen += jfcz;
                conf.jifen_all += jfcz;
                conf.jifen_day += jfcz;
                if (conf.shouchong_day == 0) {
                    conf.shouchong_day += jfcz;
                }
                conf.jifen_cz = 0;
                conf.update_time = timep;
                conf.isUpdate = true;
                aaCenter.aa_accounts[accountid] = conf;
                LoginDatabase.DirectPExecute("UPDATE _aa_account SET 当前积分 = {},jifen = 0,累计充值积分={},每日累充积分={},每日首充积分={},更新时间=0 WHERE id = {};", conf.jifen, conf.jifen_all, conf.jifen_day, conf.shouchong_day, conf.id);
                std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[64].value2 + "增加：" + std::to_string(jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
                sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
            }
            else if (jifen_cz < 0) {
                int32 val = aaCenter.aa_accounts[accountid].jifen;
                val = val += jifen_cz; val = val < 0 ? 0 : val;
                aaCenter.aa_accounts[accountid].jifen = val;
                LoginDatabase.DirectPExecute("UPDATE _aa_account SET 当前积分 = {}, 更新时间=0 WHERE id = {};", val, accountid);
                std::string msg = "|cff00FFFF[系统提示]|cffFF0000你的" + aaCenter.aa_world_confs[64].value2 + "减少：" + std::to_string(-jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
                sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
            }
        }
        return true;
    }
    static bool AA_mobi(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            uint32 accountid = target->GetSession()->GetAccountId();
            int32 count = int32(std::atoi(args));
            int32 val = aaCenter.aa_accounts[accountid].mobi;
            val = val += count; val = val < 0 ? 0 : val;
            time_t timep;
            time(&timep);
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].mobi = val;
            aaCenter.aa_accounts[accountid].isUpdate = true;
            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[63].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].mobi);
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_paodian(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            uint32 accountid = target->GetSession()->GetAccountId();
            int32 count = int32(std::atoi(args));
            int32 val = aaCenter.aa_accounts[accountid].paodian;
            val = val += count; val = val < 0 ? 0 : val;
            time_t timep;
            time(&timep);
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].paodian = val;
            aaCenter.aa_accounts[accountid].isUpdate = true;
            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[62].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].paodian);
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_zhanchangjifen(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            uint32 accountid = target->GetSession()->GetAccountId();
            int32 count = int32(std::atoi(args));
            int32 val = aaCenter.aa_accounts[accountid].battlecore;
            val = val += count; val = val < 0 ? 0 : val;
            time_t timep;
            time(&timep);
            aaCenter.aa_accounts[accountid].battlecore = val;
            aaCenter.aa_accounts[accountid].update_time = timep;
            aaCenter.aa_accounts[accountid].isUpdate = true;
            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[65].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].battlecore);
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_huiyuandengji(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        if (target) {
            uint32 accountid = target->GetSession()->GetAccountId();
            int32 count = int32(std::atoi(args));
            uint32 level = aaCenter.aa_accounts[accountid].vip;
            level += count;
            level = level < 1 ? 1 : level;
            AA_Vip_Conf conf = aaCenter.aa_vip_confs[level];
            std::string msg = "";
            if (conf.level == 0) {
                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大会员等级";
            }
            else {
                time_t timep;
                time(&timep);
                aaCenter.aa_accounts[accountid].update_time = timep;
                aaCenter.aa_accounts[accountid].vip = level;
                aaCenter.aa_accounts[accountid].isUpdate = true;
                msg = "|cff00FFFF[系统提示]|cffFFFF00你的会员等级提升：" + std::to_string(count) + "，当前等级：" + std::to_string(level) + "，请小退重新登录游戏！";

                //更新客户端玩家信息
                ObjectGuid::LowType guidlow = target->GetGUIDLow();
                uint32 accountid = target->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
            }
            aaCenter.AA_SendMessage(target, 0, msg.c_str());
            aaCenter.AA_SendMessage(target, 0, msg.c_str());
            aaCenter.AA_SendMessage(target, 0, msg.c_str());
        }
        return true;
    }
    static bool AA_junxiandengji(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (target) {
            ObjectGuid::LowType guidlow = target->GetGUIDLow();
            int32 count = int32(std::atoi(args));
            int32 level = aaCenter.aa_characters_junxians[guidlow].level;
            level += count;
            level = level < 1 ? 1 : level;
            AA_Junxian_Conf conf = aaCenter.aa_junxian_confs[level];
            std::string msg = "";
            if (conf.level == 0) {
                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大军衔等级";
            }
            else {
                time_t timep;
                time(&timep);
                aaCenter.aa_characters_junxians[guidlow].update_time = timep;
                aaCenter.aa_characters_junxians[guidlow].level = level;
                aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
                msg = "|cff00FFFF[系统提示]|cffFFFF00你的军衔等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);

                //更新客户端玩家信息
                ObjectGuid::LowType guidlow = target->GetGUIDLow();
                uint32 accountid = target->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
            }
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_douqidengji(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (target) {
            ObjectGuid::LowType guidlow = target->GetGUIDLow();
            int32 count = int32(std::atoi(args));
            int32 level = aaCenter.aa_characters_douqis[guidlow].level;
            level += count;
            level = level < 1 ? 1 : level;
            AA_Douqi_Conf conf = aaCenter.aa_douqi_confs[level];
            std::string msg = "";
            if (conf.level == 0) {
                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大斗气等级";
            }
            else {
                time_t timep;
                time(&timep);
                aaCenter.aa_characters_douqis[guidlow].update_time = timep;
                aaCenter.aa_characters_douqis[guidlow].level = level;
                aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
                msg = "|cff00FFFF[系统提示]|cffFFFF00你的斗气等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);

                //更新客户端玩家信息
                ObjectGuid::LowType guidlow = target->GetGUIDLow();
                uint32 accountid = target->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
            }
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_dianfengdengji(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (target) {
            ObjectGuid::LowType guidlow = target->GetGUIDLow();
            int32 count = int32(std::atoi(args));
            int32 level = aaCenter.aa_characters_dianfengs[guidlow].level;
            level += count;
            level = level < 1 ? 1 : level;
            AA_Dianfeng_Conf conf = aaCenter.aa_dianfeng_confs[level];
            std::string msg = "";
            if (conf.level == 0) {
                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大巅峰等级";
            }
            else {
                time_t timep;
                time(&timep);
                aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
                aaCenter.aa_characters_dianfengs[guidlow].level = level;
                aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
                msg = "|cff00FFFF[系统提示]|cffFFFF00你的巅峰等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);

                //更新客户端玩家信息
                ObjectGuid::LowType guidlow = target->GetGUIDLow();
                uint32 accountid = target->GetSession()->GetAccountId();
                AA_Account a_conf = aaCenter.aa_accounts[accountid];
                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
            }
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_jiazaitese(ChatHandler* handler, char const* /*args*/)
    {
        aaCenter.LoadAAData_World();
        Player* target = handler->getSelectedPlayerOrSelf();
        if (target) {
            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00特色数据库已全部重新加载。";
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
        }
        return true;
    }
    static bool AA_caijizuobiao(ChatHandler* handler, char const* args)
    {
        Unit* target = handler->getSelectedUnit();
        if (target) {
            char* arg1 = strtok((char*)args, " ");
            char* arg2 = strtok(nullptr, " ");
            std::string arg1str = "";
            int32 zu = 1;
            if (arg1) {
                arg1str = arg1;
            }
            if (arg2) {
                zu = int32(std::atoi(arg2));
            }
            WorldDatabase.DirectPExecute("INSERT INTO __采集_坐标 (注释,组,name,map,zone,area,position_x,position_y,position_z,orientation,instanceId) VALUES ('{}',{},'{}',{},{},{},{},{},{},{},{})", arg1str, zu, target->GetMap()->GetMapName(), target->GetMapId(), target->GetZoneId(), target->GetAreaId(), target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), target->GetInstanceId());
            QueryResult result = WorldDatabase.Query("SELECT id from __采集_坐标");
            int32 rid = 0;
            if (result) {
                do {
                    Field* fields = result->Fetch();
                    rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
                } while (result->NextRow());
            }
            AA_Caiji_Zuobiao conf;
            conf.text = arg1str;
            conf.id = rid + 1;
            conf.zu = zu;
            conf.chance = 100;
            conf.name = target->GetMap()->GetMapName();
            conf.map = target->GetMapId();
            conf.zone = target->GetZoneId();
            conf.area = target->GetAreaId();
            conf.position_x = target->GetPositionX();
            conf.position_y = target->GetPositionY();
            conf.position_z = target->GetPositionZ();
            conf.orientation = target->GetOrientation();
            conf.instanceId = target->GetInstanceId();
            aaCenter.aa_caiji_zuobiaos[conf.id] = conf;
            aaCenter.aa_caiji_zuobiao_zus[conf.zu].push_back(conf.id);
            std::string rs = "|cff00FFFF[采集坐标]|cffFFFF00模板id:" + std::to_string(conf.id) + " 地图:" + target->GetMap()->GetMapName() + " 地图id:" + std::to_string(target->GetMapId()) + " zoneid:" + std::to_string(target->GetZoneId()) + " areaid:" + std::to_string(target->GetAreaId()) + " x:" + std::to_string(target->GetPositionX()) + " y:" + std::to_string(target->GetPositionY()) + " z:" + std::to_string(target->GetPositionZ()) + " o:" + std::to_string(target->GetOrientation());
            aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
        }
        return true;
    }
    static bool AA_caijishengwu(ChatHandler* handler, char const* args)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target || !target->IsInWorld()) {
            return true;
        }
        char* arg1 = strtok((char*)args, " ");
        char* arg2 = strtok(nullptr, " ");
        std::string arg1str = "";
        int32 zu = 1;
        if (arg1) {
            arg1str = arg1;
        }
        if (arg2) {
            zu = int32(std::atoi(arg2));
        }
        //aatodo target为生物，可能有错
        AA_Map_Player_Conf map_conf = aaCenter.AA_GetAA_Map_Player_Conf(target);
        WorldDatabase.DirectPExecute("INSERT INTO __采集_生物 (注释,组,name,subname,entry,faction,displayid,map,zone,area,秘境难度,position_x,position_y,position_z,orientation,instanceId) VALUES ('{}',{},'{}','{}',{},{},{},{},{},{},{},{},{},{},{},{})", arg1str, zu, target->GetName(), target->GetCreatureTemplate()->SubName, target->GetEntry(), target->GetFaction(), target->GetDisplayId(), target->GetMapId(), target->GetZoneId(), target->GetAreaId(), map_conf.nanduid, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), target->GetInstanceId());
        QueryResult result = WorldDatabase.Query("SELECT id from __采集_生物");
        int32 rid = 0;
        if (result) {
            do {
                Field* fields = result->Fetch();
                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
            } while (result->NextRow());
        }
        AA_Caiji_Creature conf;
        conf.text = arg1str;
        conf.id = rid + 1;
        conf.zu = zu;
        conf.chance = 100;
        conf.name = target->GetCreatureTemplate()->Name;
        conf.subname = target->GetCreatureTemplate()->SubName;
        conf.entry = target->GetEntry();
        conf.faction = target->GetFaction();
        conf.displayid = target->GetDisplayId();
        conf.map = target->GetMapId();
        conf.zone = target->GetZoneId();
        conf.area = target->GetAreaId();
        conf.nandu = map_conf.nanduid;
        conf.position_x = target->GetPositionX();
        conf.position_y = target->GetPositionY();
        conf.position_z = target->GetPositionZ();
        conf.orientation = target->GetOrientation();
        conf.instanceId = target->GetInstanceId();
        aaCenter.aa_caiji_creatures[conf.id] = conf;
        aaCenter.aa_caiji_creature_zus[conf.zu].push_back(conf.id);
        std::string rs = "|cff00FFFF[采集生物]|cffFFFF00模板id:" + std::to_string(conf.id) + " 生物名称:" + target->GetName();
        aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
        return true;
    }
    static bool AA_caijiwanjia(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return true;
        }
        char* arg1 = strtok((char*)args, " ");
        char* arg2 = strtok(nullptr, " ");
        std::string arg1str = "";
        int32 zu = 1;
        if (arg1) {
            arg1str = arg1;
        }
        if (arg2) {
            zu = int32(std::atoi(arg2));
        }
        WorldDatabase.DirectPExecute("INSERT INTO __采集_玩家 (注释,账号id,角色id,组,name,ip) VALUES ('{}',{},{},{},'{}','{}')", arg1str, target->GetSession()->GetAccountId(), target->GetGUIDLow(), zu, target->GetName(), target->GetSession()->GetRemoteAddress());
        QueryResult result = WorldDatabase.Query("SELECT id from __采集_玩家");
        int32 rid = 0;
        if (result) {
            do {
                Field* fields = result->Fetch();
                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
            } while (result->NextRow());
        }
        AA_Caiji_Player conf;
        conf.text = arg1str;
        conf.id = rid + 1;
        conf.account = target->GetSession()->GetAccountId();
        conf.guid = target->GetGUIDLow();
        conf.zu = zu;
        conf.chance = 100;
        conf.name = target->GetName();
        conf.ip = target->GetSession()->GetRemoteAddress();
        aaCenter.aa_caiji_players[conf.id] = conf;
        std::string rs = "|cff00FFFF[采集玩家]|cffFFFF00模板id:" + std::to_string(conf.id) + " 玩家名称:" + target->GetName();
        aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
        return true;
    }
    static bool AA_zhanshixunlianshi(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player || !player->IsInWorld()) {
            return false;
        }

        ObjectGuid guid = aaCenter.aa_vendor_guid[player->GetGUID()];
        Creature* unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, guid);

        if (!unit || !unit->IsInWorld()) {
            return false;
        }

        if (!*args)
            return false;

        /*Tokenizer entries(std::string(args), ' ');
        Tokenizer::const_iterator itr = entries.begin();
        uint32 entry = uint32(atoi(*itr));*/
        std::vector<std::string_view> entries = Trinity::Tokenize(args, ' ', false);
        auto itr = entries.begin();
        //std::string_view itr = entries[0];
        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));

        if (entry == 0) {
            return false;
        }

        player->GetSession()->SendTrainerList(unit, entry);

        unit->aa_vendor_entry = entry;
        return true;
    }

    static bool AA_suishenshangren(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player || !player->IsInWorld()) {
            return false;
        }

        Creature* vendor = nullptr;

        Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, player->GetCritterGUID());
        if (!pet || pet->GetEntry() != 36911 || !pet->IsInWorld())
        {//召唤
            player->CastSpell(player, 69541);
            pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, player->GetCritterGUID());
        }
        if (pet && pet->GetEntry() == 36911 && pet->IsInWorld()) {
            if (Creature* c = pet->ToCreature()) {
                vendor = c;
            }
        }
        if (vendor) {
            player->vendorSummonTime = aaCenter.aa_world_confs[59].value1 > 0 ? aaCenter.aa_world_confs[59].value1 * 1000 : 60000;
            if (aaCenter.aa_world_confs[59].value2 != "" && aaCenter.aa_world_confs[59].value2 != "0") {
                uint32 displayId = aaCenter.AA_StringUint32(aaCenter.aa_world_confs[59].value2);
                if (sCreatureDisplayInfoStore.LookupEntry(displayId))
                {
                    vendor->SetDisplayId(displayId);
                }
            }
        }

        if (!vendor || !vendor->IsInWorld()) {
            return false;
        }

        if (!*args)
            return false;

        /*Tokenizer entries(std::string(args), ' ');
        Tokenizer::const_iterator itr = entries.begin();
        uint32 entry = uint32(atoi(*itr));*/
        std::vector<std::string_view> entries = Trinity::Tokenize(args, ' ', false);
        auto itr = entries.begin();
        //std::string_view itr = entries[0];
        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));

        if (entry == 0) {
            return false;
        }
        
        player->GetSession()->SendListInventory(vendor->GetGUID(), entry);

        aaCenter.aa_vendor_guid[player->GetGUID()] = pet->GetGUID();
        pet->aa_vendor_entry = entry;
        return true;
    };
    static bool AA_xianshishangren(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        ObjectGuid vendorGuid = aaCenter.aa_vendor_guid[player->GetGUID()];
        Creature* vendor = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, vendorGuid);

        if (!vendor || !vendor->IsInWorld()) {
            return false;
        }

        if (!*args)
            return false;

        /*Tokenizer entries(std::string(args), ' ');
        Tokenizer::const_iterator itr = entries.begin();
        uint32 entry = uint32(atoi(*itr));*/
        std::vector<std::string_view> entries = Trinity::Tokenize(args, ' ', false);
        auto itr = entries.begin();
        //std::string_view itr = entries[0];
        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));

        if (entry == 0) {
            return false;
        }

        player->GetSession()->SendListInventory(vendor->GetGUID(), entry);
        
        vendor->aa_vendor_entry = entry;
        return true;
    };

    static bool AA_chuansongmoban(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return true;
        }
        char* zustr = strtok((char*)args, " ");
        char* nanduidstr = strtok(nullptr, " ");
        char* moshiidstr = strtok(nullptr, " ");
        if (!zustr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送模板 __采集_坐标_组(同一组中按几率随机坐标) 秘境难度等级(选填) 副本模式(选填)1代表5人普通和10人普通，2代表5人英雄和25人普通，3代表10人英雄，4代表25人英雄");
            return false;
        }
        int32 zu = int32(std::atoi(zustr));
        AA_Caiji_Zuobiao conf;
        std::vector<uint32> conf_ids = aaCenter.aa_caiji_zuobiao_zus[zu];
        //获取总chance，分母
        int count = conf_ids.size();
        if (count) {
            uint32 chanceMax = 0;
            for (int i = 0; i < count; i++) {
                uint32 id = conf_ids[i];
                AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
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
                AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
                max = conf.chance + max;
                min = 0;
                if (i == 0) {
                    min = 0;
                }
                else {
                    uint32 id = conf_ids[i - 1];
                    AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
                    min = conf.chance + min;
                }

                if (min <= chanceVal && chanceVal < max) {
                    index = i;
                    break;
                }
            }
            uint32 id = conf_ids[index];
            conf = aaCenter.aa_caiji_zuobiaos[id];
        }

        if (conf.id > 0) {
            int32 nanduid = -2;
            int32 moshiid = -2;
            if (nanduidstr) {
                nanduid = uint32(std::atoi(nanduidstr));
            }
            if (moshiidstr) {
                moshiid = int32(std::atoi(moshiidstr));
            }

            target->aa_teleport_nandu = nanduid;
            target->aa_teleport_moshi = moshiid;
            target->aa_teleport_map = conf.map;
            aaCenter.AA_TeleportMoban(target, conf.id);
            target->aa_teleport_map = -2;

        }
        else {
            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的__采集_坐标_组");
            return false;
        }
        return true;
    }

    static bool AA_chuansongwanjia(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return true;
        }

        char* name = strtok((char*)args, " ");

        if (!name)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送玩家 玩家名字");
            return false;
        }

        std::string namestr = name;

        if (Player* toPlayer = ObjectAccessor::FindPlayerByName(namestr))
        {
            if (toPlayer->IsInWorld()) {
                target->TeleportTo(toPlayer->GetMapId(), toPlayer->GetPositionX(), toPlayer->GetPositionY(), toPlayer->GetPositionZ(), toPlayer->GetOrientation());
            }
        }

        return true;
    }

    static bool AA_chuansong(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->getSelectedPlayerOrSelf();
        char* goX = strtok((char*)args, " ");
        if (goX && goX == "触发者") {
            return true;
        }
        char* goY = strtok(nullptr, " ");
        char* goZ = strtok(nullptr, " ");
        char* id = strtok(nullptr, " ");
        char* port = strtok(nullptr, " ");
        char* goNandu = strtok(nullptr, " ");
        char* moshiidstr = strtok(nullptr, " ");

        if (!goX || !goY) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送 x y z mapid o 难度等级(选填) 副本模式(选填)1代表5人普通和10人普通，2代表5人英雄和25人普通，3代表10人英雄，4代表25人英雄");
            return false;
        }

        float x = (float)atof(goX);
        float y = (float)atof(goY);
        float z;
        float ort = port ? (float)atof(port) : player->GetOrientation();
        ort = ort == 0 ? player->GetOrientation() : ort;
        uint32 mapId = id ? (uint32)atoi(id) : player->GetMapId();

        if (goZ)
        {
            z = (float)atof(goZ);
            if (!MapManager::IsValidMapCoord(mapId, x, y, z))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            if (!MapManager::IsValidMapCoord(mapId, x, y))
            {
                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
                handler->SetSentErrorMessage(true);
                return false;
            }
            std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(mapId);
            z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y));
        }


        // stop flight if need
        if (player->IsInFlight())
            player->FinishTaxiFlight();
        else
            player->SaveRecallPosition(); // save only in non-flight case

        int32 nanduid = -2;
        if (goNandu) {
            nanduid = (int32)(std::atoi(goNandu));
        }
        int32 moshiid = -2;
        if (moshiidstr) {
            moshiid = int32(std::atoi(moshiidstr));
        }

        player->aa_teleport_nandu = nanduid;
        player->aa_teleport_moshi = moshiid;
        player->aa_teleport_map = mapId;
        player->TeleportTo(mapId, x, y, z, ort);
        player->aa_teleport_map = -2;

        return true;
    }
    static bool AA_chuanhuan(ChatHandler* handler, char const* args)
    {
        Player* me = handler->GetSession()->GetPlayer();
        if (!me || !me->IsInWorld()) {
            return false;
        }
        char* arg1 = strtok((char*)args, " ");
        std::string arg1str = "";
        if (arg1) {
            arg1str = arg1;
        }
        std::set<Player*> players; players.clear();
        players = aaCenter.AA_GetPlayerRange(me, arg1str);
        for (Player* p : players) {
            if (!p->IsInWorld()) {
                continue;
            }
            p->TeleportTo(me->GetMapId(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }
        return true;
    }
    static bool AA_shiqu(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player || !player->IsInWorld()) {
            return false;
        }
        char* typestr = strtok((char*)args, " ");
        if (!typestr)
        {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.拾取 拾取范围");
            return false;
        }
        uint32 type = atoi(typestr);
        if (!player->IsAlive())
        {
            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000死亡状态下无法使用");
            return false;
        }
        if (player->IsNonMeleeSpellCast(false))
            player->InterruptNonMeleeSpells(false);
        std::list<Creature*> list;
        aaCenter.BB_GetCreatureListInGrid(player, list, type);
        Group* group = player->GetGroup();
        if (!list.empty())
        {
            for (std::list<Creature*>::iterator itr = list.begin(); itr != list.end(); ++itr)
            {
                Creature* c = *itr;
                if (c && c->IsAlive())
                    continue;
                WorldPacket data;
                data << c->GetGUID();
                Loot* loot = c->GetLootForPlayer(player);
                player->SendLoot(*loot, true);
            }
        }
        return true;
    }
    static bool AA_jiangli(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        int32 id = int32(std::atoi(args));
        if (id <= 0) {
            return true;
        }
        aaCenter.M_Reward(target, id);
        return true;
    }
    static bool AA_xuqiu(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        int32 id = int32(std::atoi(args));
        if (id <= 0) {
            return true;
        }
        if (aaCenter.M_CanNeed(target, id))
        {
            aaCenter.M_Need(target, id);
        }
        return true;
    }
    static bool AA_gonggao(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        int32 id = int32(std::atoi(args));
        if (id <= 0) {
            return true;
        }
        AA_Message aa_message;
        AA_Notice notice = aaCenter.aa_notices[id];
        aaCenter.AA_SendNotice(target, notice, true, aa_message);
        return true;
    }
    static bool AA_tanchuang(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        int32 id = int32(std::atoi(args));
        if (id <= 0) {
            return true;
        }
        aaCenter.AA_EventStart(target, id);
        return true;
    }
    static bool AA_tanchuangneirong(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        char* arg1 = strtok((char*)args, " ");
        char* arg2 = strtok(nullptr, " ");
        if (!arg1 && !arg2) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.弹窗内容 标题 内容");
            return false;
        }
        std::string title = "";
        std::string text = "";
        if (arg1) {
            title = std::string(arg1);
        }
        if (arg2) {
            text = std::string(arg2);
        }
        aaCenter.AA_SendEvent(target, title, text);
        return true;
    }
    static bool AA_duihuanmashengcheng(ChatHandler* handler, char const* args)
    {
        Player* target = handler->GetSession()->GetPlayer();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        char* arg1 = strtok((char*)args, " ");
        char* arg2 = strtok(nullptr, " ");
        char* arg3 = strtok(nullptr, " ");
        if (!arg1 || !arg2) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.生成兑换码 奖励id 生成数量 注释");
            return false;
        }
        uint32 reward = uint32(std::atoi(arg1));
        uint32 count = uint32(std::atoi(arg2));
        count = count == 0 ? 1 : count;
        char chr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z',
            'a', 'b', 'c', 'd', 'e', 'f', 'g',
            'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z' };
        std::string sqlstrs = "";
        srand((unsigned)time(0));
        for (uint32 i = 0; i < count; i++) {
            std::string cdk = "";
            for (int i = 0; i < 10; i++) {
                int index = rand() % 62;
                cdk = cdk + chr[index];
            }
            std::string arg3str = "";
            if (arg3) {
                arg3str = arg3;
            }
            std::string sqlstr = "('" + arg3str + "','" + cdk + "'," + std::to_string(reward) + ")";
            sqlstrs = sqlstrs + sqlstr + ",";
            AA_Duihuanma conf;
            conf.cdk = cdk;
            conf.reward = reward;
            aaCenter.aa_duihuanmas[cdk] = conf;
        }
        std::string sql = "INSERT INTO _奖励_兑换码 (注释,兑换码,奖励) VALUES " + sqlstrs;
        aaCenter.AA_StringReplaceLast(sql, ",", "");
        WorldDatabase.DirectExecute(sql.c_str());
        aaCenter.AA_SendMessage(target, 0, "|cff00FFFF[系统提示]|cffFFFF00兑换码生成成功");
        return true;
    }
    static bool AA_duihuanma(ChatHandler* handler, char const* args)
    {
        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target || !target->IsInWorld()) {
            return false;
        }
        char* arg1 = strtok((char*)args, " ");
        if (!arg1) {
            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.兑换码 兑换码");
            return false;
        }
        AA_Duihuanma conf = aaCenter.aa_duihuanmas[arg1];
        if (conf.cdk == "") {
            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000兑换码不存在。");
            return false;
        }
        if (conf.time == 0) {
            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000兑换码已失效。");
            return false;
        }
        ObjectGuid::LowType guidlow = target->GetGUIDLow();
        uint32 accountid = target->GetSession()->GetAccountId();
        std::string ip = target->GetSession()->GetRemoteAddress();
        if (ip != "") {
            AA_Duihuanma_Conf conf1 = aaCenter.aa_duihuanma_confs[conf.zu];
            if (conf1.zu > 0) {
                //获取数量
                uint32 count_guidlow = 0;
                uint32 count_account = 0;
                uint32 count_ip = 0;
                for (auto d_conf : aaCenter.aa_duihuanmas) {
                    if (d_conf.second.zu != conf.zu) {
                        continue;
                    }
                    if (d_conf.second.guid != "") {
                        std::vector<int32> guids; guids.clear();
                        aaCenter.AA_StringToVectorInt(d_conf.second.guid, guids, ",");
                        for (auto guid : guids) {
                            if (guid == (int32)guidlow) {
                                count_guidlow++;
                            }
                        }
                    }
                    if (d_conf.second.account != "") {
                        std::vector<int32> accounts; accounts.clear();
                        aaCenter.AA_StringToVectorInt(d_conf.second.account, accounts, ",");
                        for (auto account : accounts) {
                            if (account == (int32)accountid) {
                                count_account++;
                            }
                        }
                    }
                    if (d_conf.second.ip != "") {
                        std::vector<std::string> ips; ips.clear();
                        aaCenter.AA_StringToVectorString(d_conf.second.ip, ips, ",");
                        for (auto ip1 : ips) {
                            if (ip1 == ip) {
                                count_ip++;
                            }
                        }
                    }
                }
                if (conf1.guid > 0 && conf1.guid <= count_guidlow) { //角色领取限制
                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的角色达到领取数量限制。");
                    return false;
                }
                if (conf1.account > 0 && conf1.account <= count_account) { //账号领取限制
                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的账号达到领取数量限制。");
                    return false;
                }
                if (conf1.ip > 0 && conf1.ip <= count_ip) { //ip领取限制
                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的IP达到领取数量限制。");
                    return false;
                }
            }
        }
        if (conf.need > 0) {
            if (aaCenter.M_CanNeed(target, conf.need)) {
                aaCenter.M_Need(target, conf.need);
            }
            else {
                return false;
            }
        }
        if (conf.reward > 0) {
            aaCenter.M_Reward(target, conf.reward, 1);
        }
        int32 dh_time = (conf.time - 1) >= 0 ? (conf.time - 1) : 0;
        {
            std::vector<int32> guids; guids.clear();
            aaCenter.AA_StringToVectorInt(aaCenter.aa_duihuanmas[arg1].guid, guids, ",");
            guids.push_back(guidlow);
            std::string str = "";
            aaCenter.AA_VectorIntToString(str, guids, ",");
            aaCenter.aa_duihuanmas[arg1].guid = str;
        }
        {
            std::vector<int32> accounts; accounts.clear();
            aaCenter.AA_StringToVectorInt(aaCenter.aa_duihuanmas[arg1].account, accounts, ",");
            accounts.push_back(accountid);
            std::string str = "";
            aaCenter.AA_VectorIntToString(str, accounts, ",");
            aaCenter.aa_duihuanmas[arg1].account = str;
        }
        {
            std::vector<std::string> ips; ips.clear();
            aaCenter.AA_StringToVectorString(aaCenter.aa_duihuanmas[arg1].ip, ips, ",");
            ips.push_back(ip);
            std::string str = "";
            aaCenter.AA_VectorStringToString(str, ips, ",");
            aaCenter.aa_duihuanmas[arg1].ip = str;
        }
        WorldDatabase.DirectPExecute("update _奖励_兑换码 set 兑换角色 = '{}',兑换账号 = '{}',兑换IP = '{}',兑换次数 = {} where 兑换码 = '{}'", aaCenter.aa_duihuanmas[arg1].guid, aaCenter.aa_duihuanmas[arg1].account, aaCenter.aa_duihuanmas[arg1].ip, dh_time, arg1);
        aaCenter.aa_duihuanmas[arg1].time = dh_time;
        if (conf.notice > 0) {
            AA_Message aa_message;
            AA_Notice notice = aaCenter.aa_notices[conf.notice];
            aaCenter.AA_SendNotice(target, notice, true, aa_message);
        }
        aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFFFF00兑换码兑换成功");
        return true;
    }
};

void AddAA_CommandScript()
{
    new aa_commandscript();
}
