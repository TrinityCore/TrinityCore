//#include "ScriptMgr.h"
//#include "ObjectMgr.h"
//#include "Chat.h"
//#include "Language.h"
//#include "Player.h"
//#include "DatabaseEnv.h"
//#include "WorldSession.h"
//#include "Map.h"
//#include "Pet.h"
//#include "SpellInfo.h"
//#include "AAData.h"
//#include "LootItemStorage.h"
//#include "GroupMgr.h"
//#include "ScriptedGossip.h"
//#include "SpellAuras.h"
//#include "Guild.h"
//#include "StringConvert.h"
//#include "Log.h"
//#include "AccountMgr.h"
//#include "DisableMgr.h"
//#include "MapManager.h"
//#include "LFGMgr.h"
//#include "TerrainMgr.h"
//#include "PhasingHandler.h"
//#include "ChatCommand.h"
//
//using namespace Trinity::ChatCommands;
//
//class aa_commandscript : public CommandScript
//{
//public:
//    aa_commandscript() : CommandScript("aa_commandscript") { }
//    ChatCommandTable GetCommands() const override
//    {
//        static ChatCommandTable setCommandTable =
//        {
//            { "scale",              AA_HandleSetScaleCommand,       LANG_VALUE_SAVED,        rbac::RBAC_ROLE_GAMEMASTER,          Console::Yes }
//            { "display",			AA_HandleSetDisplayCommand,			"" },
//            { "name",				AA_HandleSetNameCommand,				"" },
//            { "subname",			AA_HandleSetSubNameCommand,			"" },
//            { "npcflag",			AA_HandleSetNPCFlagCommand,			"" },
//            { "equip",              AA_npcWuqi,                            "" },
//            { "entry",              AA_npcentry,                           "" },
//
//        };
//        static ChatCommandTable commandTable =
//        {
//            { "_set", setCommandTable },
//            { "_npcarea",   SEC_GAMEMASTER,         false,      &AA_npcarea,                    "" },
//            { "_db_clear",	SEC_CONSOLE,			true,		&AA_HandleDBClearCommand,	    	"" },
//            { "_morpet",	SEC_GAMEMASTER,			false,		&AA_HandlePetMorphCommand,		    "" },
//            { "_emote",		SEC_GAMEMASTER,			false,		&AA_HandleEmoteCommand,			"" },
//            { "_clearbag",	SEC_GAMEMASTER,			false,		&AA_HandleClearBagCommand,		"" },
//            { "_group",		SEC_GAMEMASTER,			false,		&AA_HandleGroupCommand,			"" },
//            { "_heal",		SEC_GAMEMASTER,			false,		&AA_HandleHealCommand,			"" },
//            { "_level",		SEC_GAMEMASTER,			false,		&AA_HandleLevelCommand,			"" },
//            { "_pet",		SEC_GAMEMASTER,			false,		&AA_HandlePetCommand,			"" },
//            { "_cast",		SEC_GAMEMASTER,			false,		&AA_HandleCastCommand,			"" },
//            { "_learn",		SEC_GAMEMASTER,			false,		&AA_HandleLearnCommand,			"" },
//            { "_unlearn",		SEC_GAMEMASTER,			false,		&AA_HandleUnLearnCommand,			"" },
//            { "_aura",		SEC_GAMEMASTER,			false,		&AA_HandleAuraCommand,			"" },
//            { "_unaura",		SEC_GAMEMASTER,			false,		&AA_HandleUnAuraCommand,			"" },
//            { "ui",                SEC_GAMEMASTER,         false, &AA_ui,                   "" },
//            { "ai",                SEC_GAMEMASTER,         false, &AA_DoAi,                   "" },
//            /*格式命令*/
//            { "zuhe",                SEC_GAMEMASTER,         true, &AA_zuhe,                   "" },
//            { "组合",                SEC_GAMEMASTER,         true, &AA_zuhe,                   "" },
//            { "zh",                SEC_GAMEMASTER,         true, &AA_zuhe,                   "" },
//            { "suiji",                SEC_GAMEMASTER,         true, &AA_suiji,                   "" },
//            { "随机",                SEC_GAMEMASTER,         true, &AA_suiji,                   "" },
//            { "sj",                SEC_GAMEMASTER,         true, &AA_suiji,                   "" },
//            /*sql操作*/
//            { "jiazaitese",                SEC_GAMEMASTER,         true, &AA_jiazaitese,                   "" },
//            { "加载特色",                SEC_GAMEMASTER,         true, &AA_jiazaitese,                   "" },
//            { "jzts",                SEC_GAMEMASTER,         true, &AA_jiazaitese,                   "" },
//            { "采集坐标",                SEC_GAMEMASTER,         false, &AA_caijizuobiao,                   "" },
//            { "cjzb",                SEC_GAMEMASTER,         false, &AA_caijizuobiao,                   "" },
//            { "采集生物",                SEC_GAMEMASTER,         false, &AA_caijishengwu,                   "" },
//            { "cjsw",                SEC_GAMEMASTER,         false, &AA_caijishengwu,                   "" },
//            { "采集玩家",                SEC_GAMEMASTER,         false, &AA_caijiwanjia,                   "" },
//            { "cjwj",                SEC_GAMEMASTER,         false, &AA_caijiwanjia,                   "" },
//            /*不支持的操作-我的队友执行*/
//            { "传唤",                SEC_GAMEMASTER,         false, &AA_chuanhuan,                   "" },
//            { "ch",                SEC_GAMEMASTER,         false, &AA_chuanhuan,                   "" },
//            /*玩家操作-我执行*/
//            { "领取积分",                SEC_GAMEMASTER,         false, &AA_lingqujifen,                   "" },
//            { "lqjf",                SEC_GAMEMASTER,         false, &AA_lingqujifen,                   "" },
//            { "传送模板",                SEC_GAMEMASTER,         false, &AA_chuansongmoban,                   "" },
//            { "csmb",                SEC_GAMEMASTER,         false, &AA_chuansongmoban,                   "" },
//            { "传送玩家",                SEC_GAMEMASTER,         false, &AA_chuansongwanjia,                   "" },
//            { "cswj",                SEC_GAMEMASTER,         false, &AA_chuansongwanjia,                   "" },
//            { "传送",                SEC_GAMEMASTER,         false, &AA_chuansong,                   "" },
//            { "cs",                SEC_GAMEMASTER,         false, &AA_chuansong,                   "" },
//            { "拾取",                SEC_GAMEMASTER,         false, &AA_shiqu,                   "" },
//            { "sq",                SEC_GAMEMASTER,         false, &AA_shiqu,                   "" },
//            { "奖励",                SEC_GAMEMASTER,         false, &AA_jiangli,                   "" },
//            { "需求",                SEC_GAMEMASTER,         false, &AA_xuqiu,                   "" },
//            { "xq",                SEC_GAMEMASTER,         false, &AA_xuqiu,                   "" },
//            { "会员等级",                SEC_GAMEMASTER,         false, &AA_huiyuandengji,                   "" },
//            { "hydj",                SEC_GAMEMASTER,         false, &AA_huiyuandengji,                   "" },
//            { "积分",                SEC_GAMEMASTER,         false, &AA_jifen,                   "" },
//            { "jf",                SEC_GAMEMASTER,         false, &AA_jifen,                   "" },
//            { "魔币",                SEC_GAMEMASTER,         false, &AA_mobi,                   "" },
//            { "mb",                SEC_GAMEMASTER,         false, &AA_mobi,                   "" },
//            { "泡点",                SEC_GAMEMASTER,         false, &AA_paodian,                   "" },
//            { "pd",                SEC_GAMEMASTER,         false, &AA_paodian,                   "" },
//            { "战场积分",                SEC_GAMEMASTER,         false, &AA_zhanchangjifen,                   "" },
//            { "dzjf",                SEC_GAMEMASTER,         false, &AA_zhanchangjifen,                   "" },
//            { "巅峰等级",                SEC_GAMEMASTER,         false, &AA_dianfengdengji,                   "" },
//            { "dfdj",                SEC_GAMEMASTER,         false, &AA_dianfengdengji,                   "" },
//            { "斗气等级",                SEC_GAMEMASTER,         false, &AA_douqidengji,                   "" },
//            { "dqdj",                SEC_GAMEMASTER,         false, &AA_douqidengji,                   "" },
//            { "军衔等级",                SEC_GAMEMASTER,         false, &AA_junxiandengji,                   "" },
//            { "jxdj",                SEC_GAMEMASTER,         false, &AA_junxiandengji,                   "" },
//            { "展示商人",                SEC_GAMEMASTER,         false, &AA_xianshishangren,                   "" },
//            { "zssr",                SEC_GAMEMASTER,         false, &AA_xianshishangren,                   "" },
//            { "随身商人",                SEC_GAMEMASTER,         false, &AA_suishenshangren,                   "" },
//            { "sssr",                SEC_GAMEMASTER,         false, &AA_suishenshangren,                   "" },
//            { "展示训练师",                SEC_GAMEMASTER,         false, &AA_zhanshixunlianshi,                   "" },
//            { "zsxls",                SEC_GAMEMASTER,         false, &AA_zhanshixunlianshi,                   "" },
//            { "转职",                SEC_GAMEMASTER,         false, &AA_zhuanzhi,                   "" },
//            { "zz",                SEC_GAMEMASTER,         false, &AA_zhuanzhi,                   "" },
//            { "公告",                SEC_GAMEMASTER,         false, &AA_gonggao,                   "" },
//            { "gg",                SEC_GAMEMASTER,         false, &AA_gonggao,                   "" },
//            { "弹窗",                SEC_GAMEMASTER,         false, &AA_tanchuang,                   "" },
//            { "tc",                SEC_GAMEMASTER,         false, &AA_tanchuang,                   "" },
//            { "弹窗内容",                SEC_GAMEMASTER,         false, &AA_tanchuangneirong,                   "" },
//            { "tcnr",                SEC_GAMEMASTER,         false, &AA_tanchuangneirong,                   "" },
//            { "重置日任务",                SEC_GAMEMASTER,         false, &AA_chongzhirirenwu,                   "" },
//            { "czrrw",                SEC_GAMEMASTER,         false, &AA_chongzhirirenwu,                   "" },
//            { "重置周任务",                SEC_GAMEMASTER,         false, &AA_chongzhizhourenwu,                   "" },
//            { "czzrw",                SEC_GAMEMASTER,         false, &AA_chongzhizhourenwu,                   "" },
//            { "重置月任务",                SEC_GAMEMASTER,         false, &AA_chongzhiyuerenwu,                   "" },
//            { "czyrw",                SEC_GAMEMASTER,         false, &AA_chongzhiyuerenwu,                   "" },
//            { "加血",                SEC_GAMEMASTER,         false, &AA_jiaxue,                   "" },
//            { "jx",                SEC_GAMEMASTER,         false, &AA_jiaxue,                   "" },
//            { "解卡",                SEC_PLAYER,         false, &AA_jieka,                   "" },
//            { "jk",                SEC_PLAYER,         false, &AA_jieka,                   "" },
//            { "邮件",                SEC_PLAYER,         false, &AA_youjian,                   "" },
//            { "yj",                SEC_PLAYER,         false, &AA_youjian,                   "" },
//            { "重置理财",                SEC_GAMEMASTER,         false, &AA_chongzhilicailingqu,                   "" },
//            { "czlc",                SEC_GAMEMASTER,         false, &AA_chongzhilicailingqu,                   "" },
//            { "重置首充",                SEC_GAMEMASTER,         false, &AA_chongzhishouchonglingqu,                   "" },
//            { "czsc",                SEC_GAMEMASTER,         false, &AA_chongzhishouchonglingqu,                   "" },
//            { "重置签到",                SEC_GAMEMASTER,         false, &AA_chongzhiqiandaolingqu,                   "" },
//            { "czqd",                SEC_GAMEMASTER,         false, &AA_chongzhiqiandaolingqu,                   "" },
//            { "召唤",                SEC_GAMEMASTER,         false, &AA_zhaohuan,                   "" },
//            { "zhao",                SEC_GAMEMASTER,         false, &AA_zhaohuan,                   "" },
//            { "专业",                SEC_GAMEMASTER,         false, &AA_zhuanye,                   "" },
//            { "zy",                SEC_GAMEMASTER,         false, &AA_zhuanye,                   "" },
//            { "杀死全图",                SEC_GAMEMASTER,         false, &AA_shasiquantu,                   "" },
//            { "ssqt",                SEC_GAMEMASTER,         false, &AA_shasiquantu,                   "" },
//            { "变身",                SEC_GAMEMASTER,         false, &AA_bianshen,                   "" },
//            { "bs",                SEC_GAMEMASTER,         false, &AA_bianshen,                   "" },
//
//            { "排行奖励",                SEC_GAMEMASTER,         false, &AA_paihangjiangli,                   "" },
//            { "phjl",                SEC_GAMEMASTER,         false, &AA_paihangjiangli,                   "" },
//            { "个人银行",                SEC_GAMEMASTER,         false, &AA_gerenyinhang,                   "" },
//            { "gryh",                SEC_GAMEMASTER,         false, &AA_gerenyinhang,                   "" },
//            { "个人邮箱",                SEC_GAMEMASTER,         false, &AA_gerenyouxiang,                   "" },
//            { "gryx",                SEC_GAMEMASTER,         false, &AA_gerenyouxiang,                   "" },
//            { "装备修理",                SEC_GAMEMASTER,         false, &AA_zhuangbeixiuli,                   "" },
//            { "zbxl",                SEC_GAMEMASTER,         false, &AA_zhuangbeixiuli,                   "" },
//            { "重置天赋",                SEC_GAMEMASTER,         false, &AA_chongzhitianfu,                   "" },
//            { "cztf",                SEC_GAMEMASTER,         false, &AA_chongzhitianfu,                   "" },
//            { "重置宠物天赋",                SEC_GAMEMASTER,         false, &AA_chongzhichongwutianfu,                   "" },
//            { "czcwtf",                SEC_GAMEMASTER,         false, &AA_chongzhichongwutianfu,                   "" },
//            { "双天赋",                SEC_GAMEMASTER,         false, &AA_shuangtianfu,                   "" },
//            { "stf",                SEC_GAMEMASTER,         false, &AA_shuangtianfu,                   "" },
//            { "解除虚弱",                SEC_GAMEMASTER,         false, &AA_jiechuxuruo,                   "" },
//            { "jcxr",                SEC_GAMEMASTER,         false, &AA_jiechuxuruo,                   "" },
//            { "重置副本",                SEC_GAMEMASTER,         false, &AA_chongzhifuben,                   "" },
//            { "czfb",                SEC_GAMEMASTER,         false, &AA_chongzhifuben,                   "" },
//            { "解除战斗",                SEC_GAMEMASTER,         false, &AA_jiechuzhandou,                   "" },
//            { "jczd",                SEC_GAMEMASTER,         false, &AA_jiechuzhandou,                   "" },
//            { "恢复生命魔法",                SEC_GAMEMASTER,         false, &AA_huifuhpmp,                   "" },
//            { "hfsmmf",                SEC_GAMEMASTER,         false, &AA_huifuhpmp,                   "" },
//            { "重置技能冷却",                SEC_GAMEMASTER,         false, &AA_chongzhijineng,                   "" },
//            { "czjnlq",                SEC_GAMEMASTER,         false, &AA_chongzhijineng,                   "" },
//            { "加入百团大战",                SEC_GAMEMASTER,         false, &AA_jiarubaituan,                   "" },
//            { "jrbtdz",                SEC_GAMEMASTER,         false, &AA_jiarubaituan,                   "" },
//            { "修改阵营",                SEC_GAMEMASTER,         false, &AA_xiugaizhenying,                   "" },
//            { "xgzy",                SEC_GAMEMASTER,         false, &AA_xiugaizhenying,                   "" },
//            { "修改种族",                SEC_GAMEMASTER,         false, &AA_xiugaizhongzhu,                   "" },
//            { "xgzz",                SEC_GAMEMASTER,         false, &AA_xiugaizhongzhu,                   "" },
//            { "修改名字",                SEC_GAMEMASTER,         false, &AA_xiugaimingzi,                   "" },
//            { "xgmz",                SEC_GAMEMASTER,         false, &AA_xiugaimingzi,                   "" },
//            { "修改外观",                SEC_GAMEMASTER,         false, &AA_xiugaiwaiguan,                   "" },
//            { "xgwg",                SEC_GAMEMASTER,         false, &AA_xiugaiwaiguan,                   "" },
//            { "回收",                SEC_GAMEMASTER,         false, &AA_huishou,                   "" },
//            { "hs",                SEC_GAMEMASTER,         false, &AA_huishou,                   "" },
//            { "物品回收",                SEC_GAMEMASTER,         false, &AA_huishouwupin,                   "" },
//            { "wphs",                SEC_GAMEMASTER,         false, &AA_huishouwupin,                   "" },
//            { "巅峰属性",                SEC_GAMEMASTER,         false, &AA_dianfengshuxing,                   "" },
//            { "dfsx",                SEC_GAMEMASTER,         false, &AA_dianfengshuxing,                   "" },
//            { "斗气属性",                SEC_GAMEMASTER,         false, &AA_douqishuxing,                   "" },
//            { "dqsx",                SEC_GAMEMASTER,         false, &AA_douqishuxing,                   "" },
//            { "军衔属性",                SEC_GAMEMASTER,         false, &AA_junxianshuxing,                   "" },
//            { "jxsx",                SEC_GAMEMASTER,         false, &AA_junxianshuxing,                   "" },
//            { "重置巅峰",                SEC_GAMEMASTER,         false, &AA_chongzhidianfeng,                   "" },
//            { "czdf",                SEC_GAMEMASTER,         false, &AA_chongzhidianfeng,                   "" },
//            { "重置斗气",                SEC_GAMEMASTER,         false, &AA_chongzhidouqi,                   "" },
//            { "czdq",                SEC_GAMEMASTER,         false, &AA_chongzhidouqi,                   "" },
//            { "重置军衔",                SEC_GAMEMASTER,         false, &AA_chongzhijunxian,                   "" },
//            { "czjx",                SEC_GAMEMASTER,         false, &AA_chongzhijunxian,                   "" },
//            { "会员升级",                SEC_GAMEMASTER,         false, &AA_huiyuanshengji,                   "" },
//            { "hysj",                SEC_GAMEMASTER,         false, &AA_huiyuanshengji,                   "" },
//            { "生成兑换码",                SEC_GAMEMASTER,         false, &AA_duihuanmashengcheng,                   "" },
//            { "scdhm",                SEC_GAMEMASTER,         false, &AA_duihuanmashengcheng,                   "" },
//            { "兑换码",                SEC_GAMEMASTER,         false, &AA_duihuanma,                   "" },
//            { "dhm",                SEC_GAMEMASTER,         false, &AA_duihuanma,                   "" },
//            { "召唤模板",                SEC_GAMEMASTER,         true, &AA_zhaohuanmoban,                   "" },
//            { "zhmb",                SEC_GAMEMASTER,         true, &AA_zhaohuanmoban,                   "" },
//            { "领取累充",                SEC_GAMEMASTER,         true, &AA_lingquleichong,                   "" },
//            { "leichong",                SEC_GAMEMASTER,         true, &AA_lingquleichong,                   "" },
//            { "领取首充",                SEC_GAMEMASTER,         true, &AA_lingqushouchong,                   "" },
//            { "lqsc",                SEC_GAMEMASTER,         true, &AA_lingqushouchong,                   "" },
//            { "领取签到",                SEC_GAMEMASTER,         true, &AA_lingquqiandao,                   "" },
//            { "lqqd",                SEC_GAMEMASTER,         true, &AA_lingquqiandao,                   "" },
//            { "领取等级",                SEC_GAMEMASTER,         true, &AA_lingqudengji,                   "" },
//            { "lqdj",                SEC_GAMEMASTER,         true, &AA_lingqudengji,                   "" },
//            { "领取理财",                SEC_GAMEMASTER,         true, &AA_lingqulicai,                   "" },
//            { "licai",                SEC_GAMEMASTER,         true, &AA_lingqulicai,                   "" },
//            { "采集物品",                SEC_GAMEMASTER,         false, &AA_caijiwupin,                   "" },
//            { "cjwp",                SEC_GAMEMASTER,         false, &AA_caijiwupin,                   "" },
//            { "抽奖",                SEC_GAMEMASTER,         false, &AA_choujiang,                   "" },
//            { "cj",                SEC_GAMEMASTER,         false, &AA_choujiang,                   "" },
//            { "重置购买次数",                SEC_GAMEMASTER,         false, &AA_chongzhigoumaicishu,                   "" },
//            { "czgmcs",                SEC_GAMEMASTER,         false, &AA_chongzhigoumaicishu,                   "" },
//            { "传送列表",                SEC_GAMEMASTER,         false, &AA_chuansongliebiao,                   "" },
//            { "cslb",                SEC_GAMEMASTER,         false, &AA_chuansongliebiao,                   "" },
//            { "招募",                SEC_GAMEMASTER,         false, &AA_zhaomu,                   "" },
//            { "zm",                SEC_GAMEMASTER,         false, &AA_zhaomu,                   "" },
//            { "制造",                SEC_GAMEMASTER,         false, &AA_zhizao,                   "" },
//            { "zhizao",                SEC_GAMEMASTER,         false, &AA_zhizao,                   "" },
//            { "关键字",                SEC_GAMEMASTER,         false, &AA_guanjianzi,                   "" },
//            { "gjz",                SEC_GAMEMASTER,         false, &AA_guanjianzi,                   "" },
//            { "翻牌弹窗",                SEC_GAMEMASTER,         false, &AA_fanpaitanchuang,                   "" },
//            { "fptc",                SEC_GAMEMASTER,         false, &AA_fanpaitanchuang,                   "" },
//            { "翻牌",                SEC_GAMEMASTER,         false, &AA_fanpai,                   "" },
//            { "fp",                SEC_GAMEMASTER,         false, &AA_fanpai,                   "" },
//            { "打开网址",                SEC_GAMEMASTER,         false, &AA_www,                   "" },
//            { "dkwz",                SEC_GAMEMASTER,         false, &AA_www,                   "" },
//            { "野外挑战开始",                SEC_GAMEMASTER,         false, &AA_yewaitiaozhankaishi,                   "" },
//            { "ywtzks",                SEC_GAMEMASTER,         false, &AA_yewaitiaozhankaishi,                   "" },
//            { "清理缓存",                SEC_GAMEMASTER,         false, &AA_qinglihuancun,                   "" },
//            { "qlhc",                SEC_GAMEMASTER,         false, &AA_qinglihuancun,                   "" },
//            { "变量",                SEC_GAMEMASTER,         false, &AA_bianliang,                   "" },
//            { "bl",                 SEC_GAMEMASTER,         false, &AA_bianliang,                    "" },
//        };
//        return commandTable;
//    }
//    static bool AA_HandleCastCommand(ChatHandler* handler, const char* args)
//    {
//        Player *player = handler->GetSession()->GetPlayer();
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!player || !target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* typestr = strtok(nullptr, " ");
//
//        if (!zustr) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._cast 参数1（模板_技能_组） 参数2（施放类型 0施放当前组所有技能，1按几率随机施放组内一个技能）");
//            return false;
//        }
//
//        int32 zu = int32(std::atoi(zustr));
//        int32 type = 0;
//        if (typestr) {
//            type = int32(std::atoi(typestr));
//        }
//        std::vector<uint32> allids; allids.clear();
//        if (zu > 0) {
//            if (type == 0) {
//                allids = aaCenter.aa_spellid_conf_zus[zu];
//            }
//            else {
//                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
//                //获取总chance，分母
//                int count = ids.size();
//                if (count > 0) {
//                    uint32 chanceMax = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        chanceMax += conf.chance;
//                    }
//                    //获取随机chance，分子
//                    if (chanceMax == 0) { // 数据库的chance都为0
//                        chanceMax = 1;
//                    }
//                    uint32 chanceVal = rand() % chanceMax;
//                    //获取Index
//                    uint32 max = 0;
//                    uint32 min = 0;
//                    int index = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        max = conf.chance + max;
//                        min = 0;
//                        if (i == 0) {
//                            min = 0;
//                        }
//                        else {
//                            uint32 id = ids[i - 1];
//                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                            min = conf.chance + min;
//                        }
//                        if (min <= chanceVal && chanceVal < max) {
//                            index = i;
//                            break;
//                        }
//                    }
//                    allids.clear();
//                    uint32 id = ids[index];
//                    allids.push_back(id);
//                }
//            }
//        }
//
//        for (auto id : allids) {
//            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//            if (conf.spellid > 0) {
//                player->CastSpell(target, conf.spellid);
//            }
//        }
//
//        return true;
//    }
//    static bool AA_HandleLearnCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* typestr = strtok(nullptr, " ");
//
//        if (!zustr) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._learn 参数1（模板_技能_组） 参数2（学习类型 0学习当前组所有技能，1按几率随机学习组内一个技能）");
//            return false;
//        }
//
//        int32 zu = int32(std::atoi(zustr));
//        int32 type = 0;
//        if (typestr) {
//            type = int32(std::atoi(typestr));
//        }
//        std::vector<uint32> allids; allids.clear();
//        if (zu > 0) {
//            if (type == 0) {
//                allids = aaCenter.aa_spellid_conf_zus[zu];
//            }
//            else {
//                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
//                //获取总chance，分母
//                int count = ids.size();
//                if (count > 0) {
//                    uint32 chanceMax = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        chanceMax += conf.chance;
//                    }
//                    //获取随机chance，分子
//                    if (chanceMax == 0) { // 数据库的chance都为0
//                        chanceMax = 1;
//                    }
//                    uint32 chanceVal = rand() % chanceMax;
//                    //获取Index
//                    uint32 max = 0;
//                    uint32 min = 0;
//                    int index = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        max = conf.chance + max;
//                        min = 0;
//                        if (i == 0) {
//                            min = 0;
//                        }
//                        else {
//                            uint32 id = ids[i - 1];
//                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                            min = conf.chance + min;
//                        }
//                        if (min <= chanceVal && chanceVal < max) {
//                            index = i;
//                            break;
//                        }
//                    }
//                    allids.clear();
//                    uint32 id = ids[index];
//                    allids.push_back(id);
//                }
//            }
//        }
//
//        for (auto id : allids) {
//            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//            if (conf.spellid > 0) {
//                target->LearnSpell(conf.spellid, true);
//            }
//        }
//        return true;
//    }
//    static bool AA_HandleUnLearnCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* typestr = strtok(nullptr, " ");
//
//        if (!zustr) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._unlearn 参数1（模板_技能_组） 参数2（遗忘技能类型 0遗忘当前组所有技能，1按几率随机遗忘组内一个技能）");
//            return false;
//        }
//
//        int32 zu = int32(std::atoi(zustr));
//        int32 type = 0;
//        if (typestr) {
//            type = int32(std::atoi(typestr));
//        }
//        std::vector<uint32> allids; allids.clear();
//        if (zu > 0) {
//            if (type == 0) {
//                allids = aaCenter.aa_spellid_conf_zus[zu];
//            }
//            else {
//                std::vector<uint32> ids = aaCenter.aa_spellid_conf_zus[zu];
//                //获取总chance，分母
//                int count = ids.size();
//                if (count > 0) {
//                    uint32 chanceMax = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        chanceMax += conf.chance;
//                    }
//                    //获取随机chance，分子
//                    if (chanceMax == 0) { // 数据库的chance都为0
//                        chanceMax = 1;
//                    }
//                    uint32 chanceVal = rand() % chanceMax;
//                    //获取Index
//                    uint32 max = 0;
//                    uint32 min = 0;
//                    int index = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                        max = conf.chance + max;
//                        min = 0;
//                        if (i == 0) {
//                            min = 0;
//                        }
//                        else {
//                            uint32 id = ids[i - 1];
//                            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//                            min = conf.chance + min;
//                        }
//                        if (min <= chanceVal && chanceVal < max) {
//                            index = i;
//                            break;
//                        }
//                    }
//                    allids.clear();
//                    uint32 id = ids[index];
//                    allids.push_back(id);
//                }
//            }
//        }
//
//        for (auto id : allids) {
//            AA_SpellId_Conf conf = aaCenter.aa_spellid_confs[id];
//            if (conf.spellid > 0) {
//                std::string gm = ".组合 *.unlearn " + std::to_string(conf.spellid) + "<$自身>";
//                aaCenter.AA_DoCommand(target, gm.c_str());
//            }
//        }
//        return true;
//    }
//    static bool AA_HandleAuraCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* typestr = strtok(nullptr, " ");
//
//        if (!zustr) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._aura 参数1（模板_光环_组）参数2（附加类型 0附加当前组所有光环，1按几率随机附加组内某一个光环）");
//            return false;
//        }
//
//        int32 zu = int32(std::atoi(zustr));
//        int32 type = 0;
//        if (typestr) {
//            type = int32(std::atoi(typestr));
//        }
//        std::vector<uint32> allids; allids.clear();
//        if (zu > 0) {
//            if (type == 0) {
//                allids = aaCenter.aa_auraid_conf_zus[zu];
//            }
//            else {
//                std::vector<uint32> ids = aaCenter.aa_auraid_conf_zus[zu];
//                //获取总chance，分母
//                int count = ids.size();
//                if (count > 0) {
//                    uint32 chanceMax = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                        chanceMax += conf.chance;
//                    }
//                    //获取随机chance，分子
//                    if (chanceMax == 0) { // 数据库的chance都为0
//                        chanceMax = 1;
//                    }
//                    uint32 chanceVal = rand() % chanceMax;
//                    //获取Index
//                    uint32 max = 0;
//                    uint32 min = 0;
//                    int index = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                        max = conf.chance + max;
//                        min = 0;
//                        if (i == 0) {
//                            min = 0;
//                        }
//                        else {
//                            uint32 id = ids[i - 1];
//                            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                            min = conf.chance + min;
//                        }
//                        if (min <= chanceVal && chanceVal < max) {
//                            index = i;
//                            break;
//                        }
//                    }
//                    allids.clear();
//                    uint32 id = ids[index];
//                    allids.push_back(id);
//                }
//            }
//        }
//
//        for (auto id : allids) {
//            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//            if (conf.auraid > 0) {
//                target->AddAura(conf.auraid, target);
//            }
//        }
//        return true;
//    }
//    static bool AA_HandleUnAuraCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* typestr = strtok(nullptr, " ");
//
//        if (!zustr) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._unaura 参数1（模板_光环_组）参数2（取消类型 0附加当前组所有光环，1按几率随机取消组内某一个光环）");
//            return false;
//        }
//
//        int32 zu = int32(std::atoi(zustr));
//        int32 type = 0;
//        if (typestr) {
//            type = int32(std::atoi(typestr));
//        }
//        std::vector<uint32> allids; allids.clear();
//        if (zu > 0) {
//            if (type == 0) {
//                allids = aaCenter.aa_auraid_conf_zus[zu];
//            }
//            else {
//                std::vector<uint32> ids = aaCenter.aa_auraid_conf_zus[zu];
//                //获取总chance，分母
//                int count = ids.size();
//                if (count > 0) {
//                    uint32 chanceMax = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                        chanceMax += conf.chance;
//                    }
//                    //获取随机chance，分子
//                    if (chanceMax == 0) { // 数据库的chance都为0
//                        chanceMax = 1;
//                    }
//                    uint32 chanceVal = rand() % chanceMax;
//                    //获取Index
//                    uint32 max = 0;
//                    uint32 min = 0;
//                    int index = 0;
//                    for (int i = 0; i < count; i++) {
//                        uint32 id = ids[i];
//                        AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                        max = conf.chance + max;
//                        min = 0;
//                        if (i == 0) {
//                            min = 0;
//                        }
//                        else {
//                            uint32 id = ids[i - 1];
//                            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//                            min = conf.chance + min;
//                        }
//                        if (min <= chanceVal && chanceVal < max) {
//                            index = i;
//                            break;
//                        }
//                    }
//                    allids.clear();
//                    uint32 id = ids[index];
//                    allids.push_back(id);
//                }
//            }
//        }
//
//        for (auto id : allids) {
//            AA_AuraId_Conf conf = aaCenter.aa_auraid_confs[id];
//            if (conf.auraid > 0) {
//                target->RemoveAura(conf.auraid);
//            }
//        }
//        return true;
//    }
//    static bool AA_HandlePetCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->GetSession()->GetPlayer();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._pet 1-6（1停留 2跟随 3攻击 4攻击型 5防守型 6被动型）");
//            return false;
//        }
//        int32 type = atoi(typestr);
//        std::list<Creature*> minions = aaCenter.AA_GetAllPet(target);
//        for (auto guardian : minions) {
//            if (!guardian) {
//                continue;
//            }
//            ObjectGuid guid1 = guardian->GetGUID();
//            ObjectGuid guid2;
//            if (target->GetSelectedUnit()) {
//                guid2 = target->GetSelectedUnit()->GetGUID();
//            }
//            switch (type)
//            {
//            case 1:                          //flat=1792  //STAY
//            {
//                bool controlledMotion = guardian->GetMotionMaster()->GetMotionSlotType(MOTION_SLOT_CONTROLLED) != NULL_MOTION_TYPE;
//                if (!controlledMotion)
//                {
//                    guardian->StopMovingOnCurrentPos();
//                    guardian->GetMotionMaster()->Clear(false);
//                    guardian->GetMotionMaster()->MoveIdle();
//                }
//                break;
//            }
//            case 2:                        //spellId=1792  //FOLLOW
//            {
//                guardian->AttackStop();
//                guardian->InterruptNonMeleeSpells(false);
//                guardian->ClearInPetCombat();
//                guardian->GetMotionMaster()->MoveFollow(target, PET_FOLLOW_DIST, guardian->GetFollowAngle());
//                break;
//            }
//            case 3:                        //spellId=1792  //ATTACK
//            {
//                // Can't attack if owner is pacified
//                if (target->HasAuraType(SPELL_AURA_MOD_PACIFY))
//                {
//                    //pet->SendPetCastFail(spellId, SPELL_FAILED_PACIFIED);
//                    //TODO: Send proper error message to client
//                    continue;
//                }
//
//                // only place where pet can be player
//                Unit* TargetUnit = ObjectAccessor::GetUnit(*target, guid2);
//                if (!TargetUnit)
//                    break;
//
//                if (Unit* owner = guardian->GetOwner())
//                    if (!owner->IsValidAttackTarget(TargetUnit))
//                        break;
//
//                // pussywizard (excluded charmed)
//                if (!guardian->IsCharmed())
//                    if (Creature* creaturePet = guardian->ToCreature())
//                        if (!creaturePet->CanCreatureAttack(TargetUnit))
//                            break;
//
//                // Not let attack through obstructions
//                bool checkLos = !DisableMgr::IsPathfindingEnabled(guardian->GetMap()) ||
//                    (TargetUnit->GetTypeId() == TYPEID_UNIT && (TargetUnit->ToCreature()->isWorldBoss() || TargetUnit->ToCreature()->IsDungeonBoss()));
//
//                if (checkLos && !guardian->IsWithinLOSInMap(TargetUnit))
//                {
//                    WorldPacket data(SMSG_CAST_FAILED, 1 + 4 + 1);
//                    data << uint8(0);
//                    data << uint32(7389);
//                    data << uint8(SPELL_FAILED_LINE_OF_SIGHT);
//                    target->GetSession()->SendPacket(&data);
//                    break;
//                }
//
//                guardian->ClearUnitState(UNIT_STATE_FOLLOW);
//
//                // This is true if pet has no target or has target but targets differs.
//                guardian->AttackStop();
//
//                if (guardian->GetTypeId() != TYPEID_PLAYER && guardian->ToCreature()->IsAIEnabled)
//                {
//                    guardian->ToCreature()->AI()->AttackStart(TargetUnit);
//
//                    //10% chance to play special pet attack talk, else growl
//                    if (guardian->IsPet() && ((Pet*)guardian)->getPetType() == SUMMON_PET && guardian != TargetUnit && urand(0, 100) < 10)
//                        guardian->SendPetTalk((uint32)PET_TALK_ATTACK);
//                    else
//                    {
//                        // 90% chance for pet and 100% chance for charmed creature
//                        guardian->SendPetAIReaction(guid1);
//                    }
//                }
//                else                                // charmed player
//                {
//                    guardian->Attack(TargetUnit, true);
//                    guardian->SendPetAIReaction(guid1);
//                }
//                break;
//            }
//            case 4:                         //passive
//            {
//                guardian->AttackStop();
//                if (guardian->ToPet())
//                    guardian->ToPet()->ClearCastWhenWillAvailable();
//                guardian->ClearInPetCombat();
//                [[fallthrough]]; /// @todo: Not sure whether the fallthrough was a mistake (forgetting a break) or intended. This should be double-checked.
//                break;
//            }
//            case 5:                       //recovery
//            {
//                if (guardian->GetTypeId() == TYPEID_UNIT)
//                    guardian->ToCreature()->SetReactState(ReactStates(1));
//                break;
//            }
//            case 6:                      //activete
//            {
//                if (guardian->GetTypeId() == TYPEID_UNIT)
//                    guardian->ToCreature()->SetReactState(ReactStates(0));
//                break;
//            }
//            default:
//                break;
//            }
//        }
//        
//        return true;
//    }
//    static bool AA_HandleSetScaleCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        float Scale = (float)atof((char*)args);
//        if (Scale > 10.0f || Scale < 0.1f)
//        {
//            handler->SendSysMessage(LANG_BAD_VALUE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        Unit* target = handler->getSelectedUnit();
//        if (!target || target->GetTypeId() != TYPEID_UNIT)
//        {
//            handler->SendSysMessage(LANG_SELECT_CREATURE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//
//        target->SetObjectScale(Scale);
//        WorldDatabase.DirectExecute("Update creature_template Set scale = {} WHERE entry = {}", Scale, target->GetEntry());
//        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][Scale]设置为%f", target->GetName().c_str(), Scale);
//
//        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
//        aaCenter.AA_DoCommand(nullptr, gm.c_str());
//        return true;
//    }
//    static bool AA_HandleSetDisplayCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        uint32 displayId = atoi(args);
//
//        Unit* target = handler->getSelectedUnit();
//        if (!target || target->GetTypeId() != TYPEID_UNIT)
//        {
//            handler->SendSysMessage(LANG_SELECT_CREATURE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        target->SetDisplayId(displayId);
//        WorldDatabase.DirectExecute("Update creature_template Set modelid1 = {},modelid2 = 0,modelid3 = 0,modelid4 = 0 WHERE entry = {}", displayId, target->GetEntry());
//        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][DisplayId]设置为%d", target->GetName().c_str(), displayId);
//
//        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
//        aaCenter.AA_DoCommand(nullptr, gm.c_str());
//        return true;
//    }
//    static bool AA_HandleSetNameCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        std::string name = args;
//
//        Unit* target = handler->getSelectedUnit();
//        if (!target || target->GetTypeId() != TYPEID_UNIT)
//        {
//            handler->SendSysMessage(LANG_SELECT_CREATURE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][Name]设置为%s", target->GetName().c_str(), name.c_str());
//        target->SetName(name);
//
//        if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(target->GetEntry()))
//        {
//            WorldPacket queryData;
//            queryData.Initialize(SMSG_CREATURE_QUERY_RESPONSE, 1);
//
//            queryData << uint32(target->GetEntry());                  // creature entry
//            queryData << name;
//            queryData << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4, always empty
//            queryData << ci->SubName;
//            queryData << ci->IconName;                               // "Directions" for guard, string for Icons 2.3.0
//            queryData << uint32(ci->type_flags);                     // flags
//            queryData << uint32(ci->type);                           // CreatureType.dbc
//            queryData << uint32(ci->family);                         // CreatureFamily.dbc
//            queryData << uint32(ci->rank);                           // Creature Rank (elite, boss, etc)
//            queryData << uint32(ci->KillCredit[0]);                  // new in 3.1, kill credit
//            queryData << uint32(ci->KillCredit[1]);                  // new in 3.1, kill credit
//            queryData << uint32(ci->Modelid1);                       // Modelid1
//            queryData << uint32(ci->Modelid2);                       // Modelid2
//            queryData << uint32(ci->Modelid3);                       // Modelid3
//            queryData << uint32(ci->Modelid4);                       // Modelid4
//            queryData << float(ci->ModHealth);                       // dmg/hp modifier
//            queryData << float(ci->ModMana);                         // dmg/mana modifier
//            queryData << uint8(ci->RacialLeader);
//            for (uint32 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
//                queryData << uint32(0);              // itemId[6], quest drop
//            queryData << uint32(ci->movementId);                     // CreatureMovementInfo.dbc
//
//            handler->GetSession()->SendPacket(&queryData);
//        }
//
//        WorldDatabase.DirectExecute("Update creature_template Set name = '{}' WHERE entry = {}", name.c_str(), target->GetEntry());
//
//        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
//        aaCenter.AA_DoCommand(nullptr, gm.c_str());
//        return true;
//    }
//    static bool AA_HandleSetSubNameCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        std::string subName = args;
//
//        Unit* target = handler->getSelectedUnit();
//        if (!target || target->GetTypeId() != TYPEID_UNIT)
//        {
//            handler->SendSysMessage(LANG_SELECT_CREATURE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(target->GetEntry()))
//        {
//            WorldPacket queryData;
//            queryData.Initialize(SMSG_CREATURE_QUERY_RESPONSE, 1);
//
//            queryData << uint32(target->GetEntry());                 // creature entry
//            queryData << ci->Name;
//            queryData << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4, always empty
//            queryData << subName;
//            queryData << ci->IconName;                               // "Directions" for guard, string for Icons 2.3.0
//            queryData << uint32(ci->type_flags);                     // flags
//            queryData << uint32(ci->type);                           // CreatureType.dbc
//            queryData << uint32(ci->family);                         // CreatureFamily.dbc
//            queryData << uint32(ci->rank);                           // Creature Rank (elite, boss, etc)
//            queryData << uint32(ci->KillCredit[0]);                  // new in 3.1, kill credit
//            queryData << uint32(ci->KillCredit[1]);                  // new in 3.1, kill credit
//            queryData << uint32(ci->Modelid1);                       // Modelid1
//            queryData << uint32(ci->Modelid2);                       // Modelid2
//            queryData << uint32(ci->Modelid3);                       // Modelid3
//            queryData << uint32(ci->Modelid4);                       // Modelid4
//            queryData << float(ci->ModHealth);                       // dmg/hp modifier
//            queryData << float(ci->ModMana);                         // dmg/mana modifier
//            queryData << uint8(ci->RacialLeader);
//            for (uint32 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
//                queryData << uint32(0);              // itemId[6], quest drop
//            queryData << uint32(ci->movementId);                     // CreatureMovementInfo.dbc
//
//            handler->GetSession()->SendPacket(&queryData);
//        }
//
//        WorldDatabase.DirectExecute("Update creature_template Set subname = '{}' WHERE entry = {}", subName.c_str(), target->GetEntry());
//        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][SubName]设置为%s", target->GetName().c_str(), subName.c_str());
//
//        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
//        aaCenter.AA_DoCommand(nullptr, gm.c_str());
//        return true;
//    }
//    static bool AA_HandleSetNPCFlagCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        uint32 npcflag = atoi(args);
//
//        Unit* target = handler->getSelectedUnit();
//        if (!target || target->GetTypeId() != TYPEID_UNIT)
//        {
//            handler->SendSysMessage(LANG_SELECT_CREATURE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        target->SetUInt32Value(UNIT_NPC_FLAGS, npcflag);
//        WorldDatabase.DirectExecute("Update creature_template Set npcflag = {} WHERE entry = {}", npcflag, target->GetEntry());
//        ChatHandler(handler->GetSession()).PSendSysMessage("[%s][NpcFlag]设置为%d", target->GetName().c_str(), npcflag);
//
//        std::string gm = ".reload creature_template " + std::to_string(target->GetEntry());
//        aaCenter.AA_DoCommand(nullptr, gm.c_str());
//        return true;
//    }
//    static bool AA_HandleDBClearCommand(ChatHandler* handler, const char* args)
//    {
//        QueryResult result = LoginDatabase.Query("SELECT MAX(id) FROM account");
//
//        if (!result)
//            return true;
//
//        uint32 max = result->Fetch()[0].GetUInt32();
//
//        for (size_t i = 0; i < max + 1; i++)
//            AccountMgr::DeleteAccount(i);
//
//        LoginDatabase.DirectExecute("TRUNCATE account_rank");
//        TC_LOG_INFO("server.loading", ">> Delete account_rank..");
//
//        LoginDatabase.DirectExecute("TRUNCATE account_spells");
//        TC_LOG_INFO("server.loading", ">> Delete account_spells..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE account_instance_times");
//        TC_LOG_INFO("server.loading", ">> Delete account_instance_times..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE challenge");
//        TC_LOG_INFO("server.loading", ">> Delete challenge..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_talisman");
//        TC_LOG_INFO("server.loading", ">> Delete character_talisman..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE characters_extra_equipments");
//        TC_LOG_INFO("server.loading", ">> Delete characters_extra_equipments..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE chatacters_anticheat");
//        TC_LOG_INFO("server.loading", ">> Delete chatacters_anticheat..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE chatacters_token_monitor");
//        TC_LOG_INFO("server.loading", ">> Delete chatacters_token_monitor..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_recruit");
//        TC_LOG_INFO("server.loading", ">> Delete character_recruit..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_lottery");
//        TC_LOG_INFO("server.loading", ">> Delete character_lottery..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_day_item");
//        TC_LOG_INFO("server.loading", ">> Delete character_day_item..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_achievement_progress");
//        TC_LOG_INFO("server.loading", ">> Delete character_custom_skill..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE characters_talent_req");
//        TC_LOG_INFO("server.loading", ">> Delete characters_talent_req..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_achievement");
//        TC_LOG_INFO("server.loading", ">> Delete character_achievement..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild");
//        TC_LOG_INFO("server.loading", ">> Delete guild..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_bank_eventlog");
//        TC_LOG_INFO("server.loading", ">> Delete guild_bank_eventlog..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_bank_item");
//        TC_LOG_INFO("server.loading", ">> Delete guild_bank_item..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_bank_right");
//        TC_LOG_INFO("server.loading", ">> Delete guild_bank_right..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_bank_tab");
//        TC_LOG_INFO("server.loading", ">> Delete guild_bank_tab..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_eventlog");
//        TC_LOG_INFO("server.loading", ">> Delete guild_eventlog..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_member");
//        TC_LOG_INFO("server.loading", ">> Delete guild_member..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_member_withdraw");
//        TC_LOG_INFO("server.loading", ">> Delete guild_member_withdraw..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE guild_rank");
//        TC_LOG_INFO("server.loading", ">> Delete guild_rank..");
//
//        CharacterDatabase.DirectExecute("TRUNCATE character_rank");
//        TC_LOG_INFO("server.loading", ">> Delete character_rank..");
//
//        TC_LOG_INFO("server.loading", ">> 账号库、角色库清理完毕！");
//        return true;
//    }
//    static bool AA_HandlePetMorphCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        Player* target = handler->GetSession()->GetPlayer();
//
//        if (!target)
//            return false;
//
//        uint32 displayID = atoi(args);
//
//        CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(displayID);
//
//        if (!minfo)
//        {
//            ChatHandler(target->GetSession()).PSendSysMessage("%u - 不是一个有效的模型ID", displayID);
//            return true;
//        }
//
//        if (Pet* pet = target->GetPet())
//        {
//            pet->SetDisplayId(displayID);
//            pet->SetNativeDisplayId(displayID);
//            CharacterDatabase.DirectExecute("UPDATE character_pet SET modelid = '{}' WHERE owner = '{}' AND entry = '{}'", displayID, target->GetGUIDLow(), pet->GetEntry());
//            ChatHandler(target->GetSession()).PSendSysMessage("改变宠物模型为 - %u", displayID);
//            return true;
//        }
//        else
//            ChatHandler(target->GetSession()).PSendSysMessage("你没有召唤一个宠物", displayID);
//
//        return true;
//    }
//    static bool AA_HandleEmoteCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//        Unit* target = handler->getSelectedUnit();
//
//        if (!target)
//            target = handler->GetSession()->GetPlayer();
//
//        target->HandleEmoteCommand(atoi(args));
//
//        return true;
//    }
//    static bool AA_HandleClearBagCommand(ChatHandler* handler, const char* args)
//    {
//        if (Player* player = handler->GetSession()->GetPlayer())
//            for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
//                if (Bag* pBag = player->GetBagByPos(i))
//                    for (uint32 j = 0; j < pBag->GetBagSize(); j++)
//                        if (Item* item = player->GetItemByPos(i, j))
//                            player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
//
//        return true;
//    }
//    static bool AA_HandleGroupCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//
//        if (!player)
//            return false;
//
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("命令格式._group summon/revive");
//            return false;
//        }
//
//        Group* group = player->GetGroup();
//
//        if (!group)
//            return true;
//
//        std::string param = (char*)args;
//
//        if (param == "summon")
//        {
//            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
//                if (Player* member = itr->GetSource())
//                    if (member->IsInWorld() && member->GetGUID() != player->GetGUID())
//                        member->TeleportTo(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
//            return true;
//        }
//
//        if (param == "revive")
//        {
//            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
//                if (Player* member = itr->GetSource())
//                    if (member->IsInWorld() && !member->IsAlive())
//                    {
//                        member->ResurrectPlayer(1.0f);
//                        member->SpawnCorpseBones();
//                    }
//
//            return true;
//        }
//
//        ChatHandler(handler->GetSession()).PSendSysMessage("命令格式._group summon/revive");
//        return false;
//    }
//    static bool AA_HandleHealCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//
//        if (!player)
//            return false;
//
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._heal 生物编号 血量");
//            return false;
//        }
//
//        char* s_entry = strtok((char*)args, " ");
//        char* s_health = strtok(NULL, " ");
//
//        if (!s_entry || !s_health)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._heal 生物编号 血量");
//            return false;
//        }
//
//        uint32 entry = atoi(s_entry);
//        uint32 health = atoi(s_health);
//
//        if (Creature* c = player->FindNearestCreature(entry, 1000.0f))
//            c->ModifyHealth(health);
//
//        return true;
//    }
//    static bool AA_HandleLevelCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//
//        if (!player)
//            return false;
//
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._level 等级（调整人物到指定等级）");
//            return false;
//        }
//
//        uint32 level = atoi(args);
//        int32 rlevel = 0;
//        rlevel = level - player->getLevel();
//
//        std::string gm = ".level " + std::to_string(rlevel);
//        aaCenter.AA_DoCommand(player, gm.c_str());
//
//        return true;
//    }
//    static bool AA_npcarea(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* mapIdstr = strtok((char*)args, " ");
//        uint32 mapId = uint32(std::atoi(mapIdstr));
//        Map* map = sMapMgr->CreateMap(mapId, player);
//        QueryResult result = WorldDatabase.PQuery("SELECT * from creature where map = {}", mapId);
//        std::vector<uint32> guids;
//        std::map<uint32, uint32> maps;
//        std::map<uint32, float> xs;
//        std::map<uint32, float> ys;
//        std::map<uint32, float> zs;
//
//        if (result) {
//            do {
//                Field* fields = result->Fetch();
//                uint32 guid = fields[1].GetInt32();
//                guids.push_back(guid);
//                maps[guid] = fields[5].GetInt32();
//                xs[guid] = fields[11].GetFloat();
//                ys[guid] = fields[12].GetFloat();
//                zs[guid] = fields[13].GetFloat();
//            } while (result->NextRow());
//        }
//
//        for (auto itr : maps)
//        {
//            uint32 guid = itr.first;
//            uint32 map = itr.second;
//            float x = xs[guid];
//            float y = ys[guid];
//            float z = zs[guid];
//            uint32 zone = 0;
//            uint32 area = 0;
//            player->GetZoneAndAreaId(zone, area);
//
//            WorldDatabase.PExecute("UPDATE creature SET zoneId = {}, areaId = {} WHERE guid = {}", zone, area, guid);
//        }
//        return true;
//    }
//
//    static bool AA_bianliang(ChatHandler* handler, const char* args)
//    {
//        char* typestr = strtok((char*)args, " ");
//        char* namestr = strtok(nullptr, " ");
//        char* valuestr = strtok(nullptr, " ");
//        char* allstr = strtok(nullptr, " ");
//        if (!typestr || !namestr || !valuestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.变量 类型 变量名 变量值（.变量 系统/角色/账号 变量名 +/-/=数值） all（全部执行）");
//            return false;
//        }
//        std::string type = typestr;
//        std::string name = namestr;
//        std::string value = valuestr;
//        std::string all = "";
//        if (allstr) {
//            all = allstr;
//        }
//
//        if (type == "角色") {
//            std::vector<ObjectGuid::LowType> guidlows; guidlows.clear();
//            if (all == "all") {
//                for (auto itr : aaCenter.aa_characterss)
//                {
//                    guidlows.push_back(itr.first);
//                }
//            }
//            else {
//                Player* player = handler->getSelectedPlayerOrSelf();
//                if (!player || !player->IsInWorld()) {
//                    return false;
//                }
//                guidlows.push_back(player->GetGUIDLow());
//            }
//            for (auto guidlow : guidlows)
//            {
//                std::string m_diy_guids = aaCenter.aa_characterss[guidlow].diy_guid;
//                std::map<std::string, std::string> mdiy_guids; mdiy_guids.clear();
//                aaCenter.AA_StringToStringMap(m_diy_guids, mdiy_guids);
//                std::string k = namestr;
//                std::string v = valuestr;
//                std::string v2 = mdiy_guids[k];
//                double value2 = aaCenter.AA_StringFloat(v2);
//                if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
//                    aaCenter.AA_StringReplaceFirst(v, "+", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    value2 += value;
//                }
//                if (v.find("-") != string::npos) { //减
//                    aaCenter.AA_StringReplaceFirst(v, "-", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    if (value2 >= value) {
//                        value2 -= value;
//                    }
//                    else {
//                        value2 = 0;
//                    }
//                }
//                if (v.find("=") != string::npos) { //赋值
//                    aaCenter.AA_StringReplaceFirst(v, "=", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    value2 = value;
//                }
//                mdiy_guids[k] = std::to_string(value2);
//                time_t timep;
//                time(&timep); /*当前time_t类型UTC时间*/
//                aaCenter.aa_characterss[guidlow].update_time = timep;
//                aaCenter.aa_characterss[guidlow].isUpdate = true;
//                std::string str = "";
//                aaCenter.AA_StringMapToString(mdiy_guids, str);
//                aaCenter.aa_characterss[guidlow].diy_guid = str;
//                CharacterDatabase.DirectExecute("UPDATE _玩家角色数据 SET 自定义角色变量=\"{}\",update_time={} where guid={};", str, timep, guidlow);
//            }
//        }
//        else if (type == "系统") {
//            std::string m_diy_systems = aaCenter.aa_system_conf.diy_system;
//            std::map<std::string, std::string> mdiy_systems; mdiy_systems.clear();
//            aaCenter.AA_StringToStringMap(m_diy_systems, mdiy_systems);
//            std::string k = namestr;
//            std::string v = valuestr;
//            std::string v2 = mdiy_systems[k];
//            double value2 = aaCenter.AA_StringFloat(v2);
//            if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
//                aaCenter.AA_StringReplaceFirst(v, "+", "");
//                double value = aaCenter.AA_StringFloat(v);
//                value2 += value;
//            }
//            if (v.find("-") != string::npos) { //减
//                aaCenter.AA_StringReplaceFirst(v, "-", "");
//                double value = aaCenter.AA_StringFloat(v);
//                if (value2 >= value) {
//                    value2 -= value;
//                }
//                else {
//                    value2 = 0;
//                }
//            }
//            if (v.find("=") != string::npos) { //赋值
//                aaCenter.AA_StringReplaceFirst(v, "=", "");
//                double value = aaCenter.AA_StringFloat(v);
//                value2 = value;
//            }
//            mdiy_systems[k] = std::to_string(value2);
//            time_t timep;
//            time(&timep); /*当前time_t类型UTC时间*/
//            aaCenter.aa_system_conf.update_time = timep;
//            aaCenter.aa_system_conf.isUpdate = true;
//            std::string str = "";
//            aaCenter.AA_StringMapToString(mdiy_systems, str);
//            aaCenter.aa_system_conf.diy_system = str;
//        }
//        else if (type == "账号") {
//            std::vector<uint32> accountids; accountids.clear();
//            if (all == "all") {
//                for (auto itr : aaCenter.aa_accounts)
//                {
//                    accountids.push_back(itr.first);
//                }
//            }
//            else {
//                Player* player = handler->getSelectedPlayerOrSelf();
//                if (!player || !player->IsInWorld()) {
//                    return false;
//                }
//                accountids.push_back(player->GetSession()->GetAccountId());
//            }
//            for (auto accountid : accountids) {
//                std::string m_diy_accounts = aaCenter.aa_accounts[accountid].diy_account;
//                std::map<std::string, std::string> mdiy_accounts; mdiy_accounts.clear();
//                aaCenter.AA_StringToStringMap(m_diy_accounts, mdiy_accounts);
//                std::string k = namestr;
//                std::string v = valuestr;
//                std::string v2 = mdiy_accounts[k];
//                double value2 = aaCenter.AA_StringFloat(v2);
//                if (v.find("+") != string::npos || (v.find("+") == string::npos && v.find("-") == string::npos && v.find("=") == string::npos)) { //加
//                    aaCenter.AA_StringReplaceFirst(v, "+", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    value2 += value;
//                }
//                if (v.find("-") != string::npos) { //减
//                    aaCenter.AA_StringReplaceFirst(v, "-", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    if (value2 >= value) {
//                        value2 -= value;
//                    }
//                    else {
//                        value2 = 0;
//                    }
//                }
//                if (v.find("=") != string::npos) { //赋值
//                    aaCenter.AA_StringReplaceFirst(v, "=", "");
//                    double value = aaCenter.AA_StringFloat(v);
//                    value2 = value;
//                }
//                mdiy_accounts[k] = std::to_string(value2);
//                time_t timep;
//                time(&timep); /*当前time_t类型UTC时间*/
//                aaCenter.aa_accounts[accountid].update_time = timep;
//                aaCenter.aa_accounts[accountid].isUpdate = true;
//                std::string str = "";
//                aaCenter.AA_StringMapToString(mdiy_accounts, str);
//                aaCenter.aa_accounts[accountid].diy_account = str;
//                LoginDatabase.DirectExecute("UPDATE _aa_account SET 自定义账号变量=\"{}\", 更新时间 = {} where id = {}; ", str, timep, accountid);
//            }
//        }
//        
//        return true;
//    }
//
//    static bool AA_ui(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        char* idstr = strtok(nullptr, " ");
//        if (!typestr || !idstr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.ui 类型 id（类型1客户端ui，类型2自定义ui传送）");
//            return false;
//        }
//        uint32 type = uint32(std::atoi(typestr));
//        uint32 id = uint32(std::atoi(idstr));
//        std::string result = "{["; result += std::to_string(type); result += "]={";
//        std::string msg = "";
//        if (type == 1) {
//            result += std::to_string(id);
//            result += "}}";
//            msg = result;
//        }
//        else if (type == 2) { //自定义ui_传送
//            time_t timep;
//            time(&timep); /*当前time_t类型UTC时间*/
//            std::string miyao = std::to_string(timep);
//            aaCenter.aa_ui_miyaos[timep] = 1;
//            AA_UI_Chuansong conf = aaCenter.aa_ui_chuansongs[id];
//            if (conf.id > 0) {
//                result += "\"";
//                result += std::to_string(conf.id); result += "\",\"";
//                result += miyao; result += "\",\"";
//                result += conf.title; result += "\",\"";
//                result += conf.detail1; result += "\",\"";
//                result += conf.detail2; result += "\",\"";
//                result += conf.detail3; result += "\",\"";
//                result += conf.detail4; result += "\",\"";
//                result += conf.detail5; result += "\",\"";
//
//                std::string items = "";
//                if (conf.items != "") {
//                    std::vector<int32> types; types.clear();
//                    std::vector<int32> values; values.clear();
//                    aaCenter.AA_StringToVector2(conf.items, types, values);
//                    if (types.size() > 0) {
//                        bool isOk = false;
//                        for (size_t i = 0; i < types.size(); i++)
//                        {
//                            if (isOk) {
//                                items += ",";
//                            }
//                            uint32 entry = types[i];
//                            std::string itemLink = aaCenter.AA_GetItemLink(entry);
//                            uint32 count = values[i];
//                            items += "\\\""; items += itemLink; items += "\\\"";
//                            items += " ";
//                            items += std::to_string(count);
//                            isOk = true;
//                        }
//                    }
//                }
//
//                result += items;
//                result += "\"}}";
//                msg = result;
//            }
//        }
//;       if (msg != "") {
//            aaCenter.M_SendClientAddonData(player, "999", msg);
//        }
//
//        return true;
//    }
//
//    static bool AA_qinglihuancun(ChatHandler* handler, const char* args)
//    {
//        ObjectAccessor::SaveAllPlayers();
//        handler->SendSysMessage(LANG_PLAYERS_SAVED);
//        TC_LOG_INFO("server.loading", "开始清理垃圾数据...");
//        aaCenter.DeleteAAData_Characters();
//        TC_LOG_INFO("server.loading", "开始加载特色数据...");
//        aaCenter.LoadAAData_Characters();
//        return true;
//    }
//
//    static bool AA_yewaitiaozhankaishi(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* confidstr = strtok((char*)args, " ");
//        char* isokstr = strtok(nullptr, " ");
//        if (!confidstr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.野外挑战开始 _属性调整_地图_id 是否强制开始0否1是");
//            return false;
//        }
//        uint32 confid = uint32(std::atoi(confidstr));
//        bool isOk = false;
//        if (isokstr) {
//            isOk = std::atoi(isokstr);
//        }
//        if (!confid) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.野外挑战开始 _属性调整_地图_id 是否强制开始0否1是");
//        }
//        AA_Map_Player_Conf conf = aaCenter.aa_map_player_confs[confid];
//        if (conf.id == 0 || conf.xianzhitime <= 0) {
//            return false;
//        }
//        if (conf.area != -1) {
//            if (isOk || (!isOk && aaCenter.aa_mareavalues[conf.area][1] == 0)) {
//                aaCenter.aa_map_area_values.erase(conf.area);
//                aaCenter.aa_player_area_values.erase(conf.area);
//                CharacterDatabase.DirectExecute("delete from _数据地图area where area = {}", conf.area);
//                CharacterDatabase.DirectExecute("delete from _数据玩家area where area = {}", conf.area);
//                aaCenter.aa_mareavalues.erase(conf.area);
//                aaCenter.aa_mareabools.erase(conf.area);
//                aaCenter.aa_pareavalues.erase(conf.area);
//                aaCenter.aa_pareabools.erase(conf.area);
//                aaCenter.aa_mareavalues[conf.area][0] = conf.id;
//                aaCenter.aa_mareavalues[conf.area][1] = 1;
//                aaCenter.aa_mareavalues[conf.area][3] = 2;
//                aaCenter.AA_UpdateValueBools(conf.area, 2, true);
//            }
//        }
//        else if (conf.zone != -1) {
//            if (isOk || (!isOk && aaCenter.aa_mzonevalues[conf.zone][1] == 0)) {
//                aaCenter.aa_map_zone_values.erase(conf.zone);
//                aaCenter.aa_player_zone_values.erase(conf.zone);
//                CharacterDatabase.DirectExecute("delete from _数据地图zone where zone = {}", conf.zone);
//                CharacterDatabase.DirectExecute("delete from _数据玩家zone where zone = {}", conf.zone);
//                aaCenter.aa_mzonevalues.erase(conf.zone);
//                aaCenter.aa_mzonebools.erase(conf.zone);
//                aaCenter.aa_pzonevalues.erase(conf.zone);
//                aaCenter.aa_pzonebools.erase(conf.zone);
//                aaCenter.aa_mzonevalues[conf.zone][0] = conf.id;
//                aaCenter.aa_mzonevalues[conf.zone][1] = 1;
//                aaCenter.aa_mzonevalues[conf.zone][3] = 2;
//                aaCenter.AA_UpdateValueBools(conf.zone, 1, true);
//            }
//        }
//        else if (conf.map != -1 || (conf.area == -1 && conf.zone == -1 && conf.map == -1)) {
//            if (isOk || (!isOk && aaCenter.aa_mmapvalues[conf.map][1] == 0)) {
//                aaCenter.aa_map_map_values.erase(conf.map);
//                aaCenter.aa_player_map_values.erase(conf.map);
//                CharacterDatabase.DirectExecute("delete from _数据地图map where map = {}", conf.map);
//                CharacterDatabase.DirectExecute("delete from _数据玩家map where map = {}", conf.map);
//                aaCenter.aa_mmapvalues.erase(conf.map);
//                aaCenter.aa_mmapbools.erase(conf.map);
//                aaCenter.aa_pmapvalues.erase(conf.map);
//                aaCenter.aa_pmapbools.erase(conf.map);
//                aaCenter.aa_mmapvalues[conf.map][0] = conf.id;
//                aaCenter.aa_mmapvalues[conf.map][1] = 1;
//                aaCenter.aa_mmapvalues[conf.map][3] = 0;
//                aaCenter.AA_UpdateValueBools(conf.map, 1, true);
//            }
//        }
//        return true;
//    }
//    static bool AA_npcWuqi(ChatHandler* handler, const char* args)
//    {
//        Creature* target = handler->getSelectedCreature();
//        if (!target) {
//            return false;
//        }
//        char* zustr1 = strtok((char*)args, " ");
//        char* zustr2 = strtok(nullptr, " ");
//        char* zustr3 = strtok(nullptr, " ");
//        if (!zustr1 || !zustr2 || !zustr3) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._set equip 主手id 副手id 远程id 是否修改数据库（0否1是）");
//            return false;
//        }
//
//        int32 zu1 = int32(std::atoi(zustr1));
//        int32 zu2 = int32(std::atoi(zustr2));
//        int32 zu3 = int32(std::atoi(zustr3));
//
//        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, zu1);
//        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, zu2);
//        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, zu3);
//
//        char* isstr = strtok(nullptr, " ");
//        if (isstr)
//        {
//            int32 isOk = int32(std::atoi(isstr));
//            if (isOk) {
//                WorldDatabase.DirectExecute("INSERT INTO creature_equip_template (CreatureID, ID, ItemID1, ItemID2, ItemID3, VerifiedBuild) VALUES ({}, 1, {}, {}, {}, 18019) ON DUPLICATE KEY UPDATE ItemID1 = {}, ItemID2 = {}, ItemID3 = {}", target->GetEntry(), zu1, zu2, zu3, zu1, zu2, zu3);
//                sObjectMgr->LoadEquipmentTemplates();
//            }
//        }
//
//        return true;
//    }
//    static bool AA_www(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* url = strtok((char*)args, " ");
//        if (!url)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.打开网址 http://www.baidu.com");
//            return false;
//        }
//
//        aaCenter.M_SendClientAddonData(player, "888", url);
//
//        return true;
//    }
//    static bool AA_fanpaitanchuang(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a104b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return true;
//        }
//        char* zustr1 = strtok((char*)args, " ");
//        char* zustr2 = strtok(nullptr, " ");
//        char* zustr3 = strtok(nullptr, " ");
//        if (!zustr1 || !zustr2 || !zustr3) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.翻牌弹窗 组1 组2 组3(分别对应翻牌第一排，第二排，第三排。功能表：_奖励_翻牌x)");
//            return false;
//        }
//        int32 zu1 = int32(std::atoi(zustr1));
//        int32 zu2 = int32(std::atoi(zustr2));
//        int32 zu3 = int32(std::atoi(zustr3));
//        time_t timep;
//        time(&timep); /*当前time_t类型UTC时间*/
//        //{"timp+guid"}
//        std::string msg = "";
//        Group* group = player->GetGroup();
//        uint64 miyao = 0;
//        if (group) {//队伍翻牌
//            miyao = timep + group->GetLeaderGUID().GetRawValue();
//            Group::MemberSlotList const& members = group->GetMemberSlots();
//            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
//            {
//                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
//                    if (!p->IsInWorld()) { continue; }
//                    msg = "{" + std::to_string(miyao) + "," + std::to_string(p->GetGUIDLow()) + "}";
//                    aaCenter.M_SendClientAddonData(p, "1012", msg);
//                }
//            }
//        }
//        else {//个人翻牌
//            miyao = timep + player->GetGUIDLow();
//            msg = "{" + std::to_string(miyao) + "," + std::to_string(player->GetGUIDLow()) + "}";
//            aaCenter.M_SendClientAddonData(player, "1012", msg);
//        }
//        aaCenter.aa_fanpai_tanchuang1[miyao] = zu1;
//        aaCenter.aa_fanpai_tanchuang2[miyao] = zu2;
//        aaCenter.aa_fanpai_tanchuang3[miyao] = zu3;
//        return true;
//    }
//    static bool AA_fanpai(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a104b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return true;
//        }
//
//        //秘钥：翻牌弹窗时间戳+guid
//        //接收{指令id,秘钥,牌子序号} //加密，秘钥:{guid,序号,开关=已翻}
//        //{秘钥={角色guid:{序号=物品id} }}
//        //{[秘钥]={[guid]={[序号]=物品id,[序号]=物品id},[guid]={[序号]=itemlink,[序号]=itemlink} }}
//        //发送{指令id:{牌子序号:{角色guid,牌子内容},牌子序号:{角色guid,牌子内容}}
//        //加密，翻牌弹窗时间戳+guid:{guid+序号开关}
//
//        char* miyaostr = strtok((char*)args, " ");
//        char* indexstr = strtok(nullptr, " ");
//        if (!miyaostr || !indexstr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.翻牌 秘钥 牌子序号");
//            return false;
//        }
//        uint64 miyao = uint64(std::stoul(miyaostr));
//        int32 num = int32(std::atoi(indexstr));
//        uint32 zu1 = aaCenter.aa_fanpai_tanchuang1[miyao];
//        uint32 zu2 = aaCenter.aa_fanpai_tanchuang2[miyao];
//        uint32 zu3 = aaCenter.aa_fanpai_tanchuang3[miyao];
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        if (zu1 <= 0 || zu2 <= 0 || zu3 <= 0) return true; //防封包，弹窗的才可以翻
//        if (std::find(aaCenter.aa_fanpai_pai[miyao][guidlow].begin(), aaCenter.aa_fanpai_pai[miyao][guidlow].end(), num) != aaCenter.aa_fanpai_pai[miyao][guidlow].end()) {//已经翻过，不能再翻
//            return true;
//        }
//
//        std::vector<uint32> itemids; itemids.clear();
//        std::vector<uint32> conf_ids; conf_ids.clear();
//        if (num >= 1 && num <= 4) {
//            conf_ids = aaCenter.aa_fanpai_zus[zu1];
//        }
//        else if (num >= 5 && num <= 8) {
//            conf_ids = aaCenter.aa_fanpai_zus[zu2];
//        }
//        else if (num >= 9 && num <= 12) {
//            conf_ids = aaCenter.aa_fanpai_zus[zu3];
//        }
//        int count = conf_ids.size();
//        if (!count) {
//            return false;
//        }
//        uint32 chanceMax = 0;
//        for (int i = 0; i < count; i++) {
//            uint32 id = conf_ids[i];
//            AA_Fanpai conf = aaCenter.aa_fanpais[id];
//            chanceMax += conf.chance;
//        }
//        if (chanceMax == 0) { chanceMax = 1; }
//        AA_Fanpai conf;
//        //获取随机chance，分子
//        uint32 chanceVal = rand() % chanceMax;
//        //获取Index
//        uint32 max = 0;
//        uint32 min = 0;
//        int index = -1;
//        for (int i = 0; i < count; i++) {
//            uint32 id = conf_ids[i];
//            AA_Fanpai conf = aaCenter.aa_fanpais[id];
//            max = conf.chance + max;
//            min = 0;
//            if (i == 0) {
//                min = 0;
//            }
//            else {
//                uint32 id = conf_ids[i - 1];
//                AA_Fanpai conf = aaCenter.aa_fanpais[id];
//                min = conf.chance + min;
//            }
//
//            if (min <= chanceVal && chanceVal < max) {
//                index = i;
//                break;
//            }
//        }
//        uint32 id = conf_ids[index];
//        conf = aaCenter.aa_fanpais[id];
//        if (conf.gm != "" && conf.gm != "0") {
//            aaCenter.AA_DoCommand(player, conf.gm.c_str());
//        }
//        time_t timep;
//        time(&timep); /*当前time_t类型UTC时间*/
//        //{"timp+guid"}
//        Item* item = aaCenter.AA_AddItem(player, conf.itemid, 1);
//        std::string msg = "";
//        if (item) {
//            std::string itemlink = aaCenter.AA_GetItemLinkJd(item);
//            //{[秘钥]={[guid]={[序号]=物品id,[序号]=物品id},[guid]={[序号]=itemlink,[序号]=itemlink} }}
//            msg = "{[" + std::to_string(miyao) + "]={[" + std::to_string(guidlow) + "]={[" + std::to_string(num) + "]=\"" + itemlink + "\"}}}";
//        }
//        Group* group = player->GetGroup();
//        if (group) {//队伍翻牌
//            Group::MemberSlotList const& members = group->GetMemberSlots();
//            for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
//            {
//                if (Player* p = ObjectAccessor::FindPlayer((*itr).guid)) {
//                    if (!p->IsInWorld()) { continue; }
//                    aaCenter.M_SendClientAddonData(p, "1013", msg);
//                }
//            }
//        }
//        else {//个人翻牌
//            aaCenter.M_SendClientAddonData(player, "1013", msg);
//        }
//        aaCenter.aa_fanpai_pai[miyao][guidlow].push_back(num);
//        return true;
//    }
//    static bool AA_npcentry(ChatHandler* handler, const char* args)
//    {
//        Creature* target = handler->getSelectedCreature();
//        if (!target) {
//            return false;
//        }
//        ObjectGuid::LowType guidlow = target->GetGUIDLow();
//        char* prefix = strtok((char*)args, " ");
//        char* suffix = strtok(nullptr, " ");
//        if (!prefix || !suffix)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:._set entry entry time（修改生物的entry 和 刷新时间）");
//            return false;
//        }
//        int32 entry = int32(std::atoi(prefix));
//        int32 time = int32(std::atoi(suffix));
//        WorldDatabase.DirectExecute("UPDATE creature SET id = {},spawntimesecs = {} WHERE guid = {}", entry, time, guidlow);
//        target->Kill(target, target);
//        target->Respawn();
//        return true;
//    }
//    static bool AA_guanjianzi(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//        char* zustr = strtok((char*)args, " ");
//        if (!zustr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.关键字 <$奖励@1>");
//            return false;
//        }
//        //排名显示
//        AA_Paihang p_conf;
//        std::string zustr1 = zustr;
//        if (zustr1.find("排行") != string::npos) {
//            p_conf = aaCenter.AA_GetPaihangs();
//            p_conf.isOk = true;
//        }
//        AA_Message aa_message;
//        std::string gjz = aaCenter.GetMyInfo(target, zustr, aa_message);
//        if (p_conf.isOk) {
//            aaCenter.AA_GetPaihangInfo(gjz, p_conf);
//        }
//        ChatHandler(handler->GetSession()).PSendSysMessage("%s", gjz.c_str());
//        return true;
//    }
//    static bool AA_zhizao(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//        char* zustr = strtok((char*)args, " ");
//        if (!zustr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.制造 __采集_物品_组(同一组中按几率随机)");
//            return false;
//        }
//        int32 zu = int32(std::atoi(zustr));
//        AA_Caiji_Item conf;
//        std::vector<uint32> conf_ids = aaCenter.aa_caiji_item_zus[zu];
//        //获取总chance，分母
//        int count = conf_ids.size();
//        if (count) {
//            uint32 chanceMax = 0;
//            for (int i = 0; i < count; i++) {
//                uint32 id = conf_ids[i];
//                AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
//                chanceMax += conf.chance;
//            }
//            if (chanceMax == 0) { chanceMax = 1; }
//            //获取随机chance，分子
//            uint32 chanceVal = rand() % chanceMax;
//            //获取Index
//            uint32 max = 0;
//            uint32 min = 0;
//            int index = -1;
//            for (int i = 0; i < count; i++) {
//                uint32 id = conf_ids[i];
//                AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
//                max = conf.chance + max;
//                min = 0;
//                if (i == 0) {
//                    min = 0;
//                }
//                else {
//                    uint32 id = conf_ids[i - 1];
//                    AA_Caiji_Item conf = aaCenter.aa_caiji_items[id];
//                    min = conf.chance + min;
//                }
//
//                if (min <= chanceVal && chanceVal < max) {
//                    index = i;
//                    break;
//                }
//            }
//            uint32 id = conf_ids[index];
//            conf = aaCenter.aa_caiji_items[id];
//        }
//
//        if (conf.id > 0 && conf.entry && conf.count > 0) {
//            if (Item* pItem = aaCenter.AA_AddItem(target, conf.entry, conf.count))
//            {
//                if (pItem->GetTemplate()->Bonding == BIND_WHEN_PICKED_UP ||
//                    pItem->GetTemplate()->Bonding == BIND_QUEST_ITEM)
//                    pItem->SetBinding(true);
//            }
//        }
//        else {
//            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的__采集_物品_组");
//            return false;
//        }
//        return true;
//    }
//    static bool AA_zhaomu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        if (!player || !player->IsInWorld()) {
//            return true;
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        char* arg1 = strtok((char*)args, " ");
//        if (!arg1 || guidlow == 0)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.招募 招募者姓名");
//            return false;
//        }
//        QueryResult result = CharacterDatabase.PQuery("SELECT 招募者姓名 from _玩家角色数据 where guid = {}", guidlow);
//        if (result) {
//            Field* fields = result->Fetch();
//            std::string zhaomu = fields[0].GetString();
//            if (zhaomu != "") {
//                std::string zmstr = "|cff00FFFF[系统提示]|cffFF0000你已经拥有招募者：" + zhaomu;
//                aaCenter.AA_SendMessage(player, 1, zmstr.c_str());
//                return false;
//            }
//            else {
//                Player* p = ObjectAccessor::FindPlayerByName(zhaomu);
//                uint32 accountId = 0;
//                if (p && p->IsInWorld()) {
//                    accountId = p->GetSession()->GetAccountId();
//                }
//                if (accountId == 0) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该玩家未找到或不在线，无法设置。");
//                    return false;
//                }
//                if (player->GetSession()->GetAccountId() == accountId) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000无法招募当前账号的角色。");
//                    return false;
//                }
//                CharacterDatabase.DirectExecute("UPDATE _玩家角色数据 SET 招募者姓名 = '{}' WHERE guid = {}", zhaomu, guidlow);
//                return true;
//            }
//        }
//        return false;
//    }
//    static bool AA_huishouwupin(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (aaCenter.AA_GetEmptyBag(player) < 5) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.物品回收 物品guid");
//            return false;
//        }
//        uint32 itemGuidLow = atoi(typestr);
//        bool isOk = false;
//        if (itemGuidLow > 0) {
//            if (Item* pItem = aaCenter.GetItemByGUIDLow(player, itemGuidLow)) {
//                if (player->aa_target_item == pItem) {
//                    uint32 count = pItem->GetCount();
//                    AA_Huishou_Conf conf = aaCenter.AA_GetHuiShouConf(player, player->aa_target_item->GetGUIDLow(), player->aa_target_item->GetEntry());
//                    if (conf.need > 0) {
//                        aaCenter.M_Need(player, conf.need, count);
//                    }
//                    if (conf.reward > 0) {
//                        aaCenter.M_Reward(player, conf.reward, count);
//                        player->DestroyItemCount(pItem, count, true);
//                        isOk = true;
//                        player->aa_item = nullptr;
//                        player->aa_target_item = nullptr;
//                    }
//                }
//            }
//        }
//        if (isOk) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00回收成功");
//        }
//        else {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000该物品无法回收");
//        }
//        return true;
//    }
//    static bool AA_huishou(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (aaCenter.AA_GetEmptyBag(player) < 5) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包剩余空间不足5个。");
//            return false;
//        }
//        bool isOk = false;
//        bool isBaoshi = false;
//        bool isFuwen = false;
//        std::set<Item*> items = aaCenter.M_GetBagItems(player);
//        for (auto pItem : items) {
//            if (pItem && pItem->GetState() != ITEM_REMOVED && pItem->IsInWorld()) {
//                if (ItemTemplate const* pProto = pItem->GetTemplate()) {
//                    uint32 entry = aaCenter.AA_GetBaoshiEntry(pItem, 0);
//                    if (entry > 0) {
//                        isBaoshi = true;
//                        continue;
//                    }
//                    isFuwen = aaCenter.AA_IsFuwenItem(pItem);
//                    if (isFuwen) {
//                        continue;
//                    }
//                    uint32 count = pItem->GetCount();
//                    AA_Huishou_Conf conf = aaCenter.AA_GetHuiShouConf(player, pItem->GetGUIDLow(), pItem->GetEntry());
//                    if (conf.need > 0) {
//                        aaCenter.M_Need(player, conf.need, count);
//                    }
//                    if (conf.reward > 0) {
//                        aaCenter.M_Reward(player, conf.reward, count);
//                        if (pItem && pItem->GetState() != ITEM_REMOVED && pItem->IsInWorld()) {
//                            player->DestroyItemCount(pItem, count, true);
//                        }
//                        isOk = true;
//                    }
//                }
//            }
//        }
//        if (isBaoshi) {
//            aaCenter.AA_SendMessage(player, 0, "|cff00FFFF[系统提示]|cffFF0000背包中有镶嵌过宝石的物品不能回收。");
//        }
//        if (isFuwen) {
//            aaCenter.AA_SendMessage(player, 0, "|cff00FFFF[系统提示]|cffFF0000背包中有镶嵌过符文的物品不能回收。");
//        }
//        if (isOk) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00回收成功");
//        }
//        else {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000背包没有可回收的物品");
//        }
//        return true;
//    }
//    static bool AA_DoAi(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        if (!player || !player->IsInWorld()) {
//            return true;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        if (!arg1)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.Ai _自定义ai_Id 伤害值");
//            return false;
//        }
//        char* arg2 = strtok(nullptr, " ");
//        int32 value = 0;
//        if (arg2)
//        {
//            value = int32(std::atoi(arg2));
//        }
//        uint32 ai_id = int32(std::atoi(arg1));
//        AA_Ai conf = aaCenter.aa_ais[ai_id];
//        if (conf.id > 0) {
//            Unit* target = handler->getSelectedUnit();
//            if (target && target->IsInWorld()) {
//                aaCenter.AA_AiStart(player, target, conf.id, value, true);
//            }
//            else {
//                aaCenter.AA_AiStart(player, player, conf.id, value, true);
//            }
//        }
//        return true;
//    }
//
//    static bool AA_chuansongliebiao(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return true;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        if (!arg1)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送列表 _传送_物品物体生物副本id");
//            return false;
//        }
//        uint32 entry = 0;
//        if (arg1) {
//            entry = int32(std::atoi(arg1));
//        }
//        player->aa_menuId = entry;
//        //aawow 进入副本撞门提示
//        //获取menus
//        vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
//        size_t size = menus.size();
//        if (size > 0) {
//            //如果只有一项m，直接执行功能
//            if (size == 1) {
//                uint32 id = menus[0];
//                AA_Teleport_Conf conf = aaCenter.aa_teleports[id];
//                aaCenter.AA_TelScript(player, conf);
//                if (conf.notice > 0) {
//                    AA_Message aa_message;
//                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                }
//            }
//            else {
//                //否则显示菜单
//                // 传送石
//                vector<uint32> menus = aaCenter.aa_teleport_targets[entry];
//                ClearGossipMenuFor(player); // Clears old options
//                int pId = -1;
//                AA_Message aa_message;
//                //排名显示
//                AA_Paihang p_conf;
//                for (size_t i = 0; i < menus.size(); i++) {
//                    uint32 menuid = menus[i];
//                    AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
//                    if (conf.title.find("排行") != string::npos || conf.subtitle.find("排行") != string::npos) {
//                        p_conf = aaCenter.AA_GetPaihangs();
//                        p_conf.isOk = true;
//                        break;
//                    }
//                }
//                for (size_t i = 0; i < menus.size(); i++) {
//                    uint32 menuid = menus[i];
//                    AA_Teleport_Conf conf = aaCenter.aa_teleports[menuid];
//                    if (conf.menuid != 0 || conf.is_visible == 2) {
//                        continue;
//                    }
//                    if (conf.need > 0) {
//                        if (!aaCenter.M_CanNeed(player, conf.need, 1, false) && conf.is_visible == 1) {
//                            continue;
//                        }
//                    }
//                    std::string title = aaCenter.GetMyInfo(player, conf.title, aa_message);
//                    if (p_conf.isOk) {
//                        aaCenter.AA_GetPaihangInfo(title, p_conf);
//                    }
//                    std::string subtitle = conf.subtitle;
//                    if (subtitle != "") {
//                        subtitle = aaCenter.GetMyInfo(player, subtitle, aa_message);
//                        if (p_conf.isOk) {
//                            aaCenter.AA_GetPaihangInfo(subtitle, p_conf);
//                        }
//                        if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
//                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, subtitle, 0, true);
//                        }
//                        else {
//                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, subtitle, 0, false);
//                        }
//                    }
//                    else {
//                        if (conf.script == "兑换码" || conf.script == "招募" || conf.script == "变身" || conf.script == "解卡") {
//                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid, "", 0, true);
//                        }
//                        else {
//                            AddGossipItemFor(player, GossipOptionNpc(conf.icon1), title, 0, menuid);
//                        }
//                    }
//                    pId = aaCenter.aa_teleports[conf.menuid].menuid;
//                }
//                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
//            }
//        }
//        return true;
//    }
//    static bool AA_chongzhigoumaicishu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        time_t timep;
//        time(&timep);
//        if (player) {
//            {
//                uint32 accountid = player->GetSession()->GetAccountId();
//                AA_Account conf = aaCenter.aa_accounts[accountid];
//                conf.id = accountid;
//                conf.buy_time = "";
//                conf.buy_time_yj = "";
//                conf.isUpdate = true;
//                conf.update_time = timep;
//                aaCenter.aa_accounts[accountid] = conf;
//            }
//            {
//                ObjectGuid::LowType guidlow = player->GetGUIDLow();
//                AA_Characters conf = aaCenter.aa_characterss[guidlow];
//                conf.guid = guidlow;
//                conf.buy_time = "";
//                conf.buy_time_yj = "";
//                conf.isUpdate = true;
//                conf.update_time = timep;
//                aaCenter.aa_characterss[guidlow] = conf;
//            }
//        }
//        ChatHandler(handler->GetSession()).PSendSysMessage("重置购买次数成功");
//        return true;
//    }
//    static bool AA_choujiang(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a100b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* cishustr = strtok(nullptr, " ");
//        if (!zustr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.抽奖 _奖励_抽奖x_组(同一组中按几率随机坐标) 抽奖次数(选填)");
//            return false;
//        }
//        int32 zu = int32(std::atoi(zustr));
//        int32 rcishu = 0;
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        uint32 needid = aaCenter.aa_world_confs[73].value1;
//        if (zu > 0) {
//            //抽奖次数奖励
//            time_t timep;
//            time(&timep);
//            aaCenter.aa_characterss[guidlow].update_time = timep;
//            aaCenter.aa_characterss[guidlow].isUpdate = true;
//            std::vector<int32> types; types.clear();
//            std::vector<int32> values; values.clear();
//            aaCenter.AA_StringToVector2(aaCenter.aa_world_confs[73].value2, types, values);
//            uint32 cishu = 1;
//            if (cishustr) {
//                cishu = uint32(std::atoi(cishustr));
//            }
//            if (needid > 0) {
//                if (!aaCenter.M_CanNeed(player, needid, cishu)) {
//                    return false;
//                }
//            }
//            std::vector<uint32> itemids; itemids.clear();
//            std::vector<uint32> conf_ids = aaCenter.aa_choujiang_zus[zu];
//            int count = conf_ids.size();
//            if (!count) {
//                return false;
//            }
//            uint32 chanceMax = 0;
//            for (int i = 0; i < count; i++) {
//                uint32 id = conf_ids[i];
//                AA_Choujiang conf = aaCenter.aa_choujiangs[id];
//                chanceMax += conf.chance;
//            }
//            if (chanceMax == 0) { chanceMax = 1; }
//            for (uint32 i = 0; i < cishu; i++) {
//                AA_Choujiang conf;
//                //获取随机chance，分子
//                uint32 chanceVal = rand() % chanceMax;
//                //获取Index
//                uint32 max = 0;
//                uint32 min = 0;
//                int index = -1;
//                for (int i = 0; i < count; i++) {
//                    uint32 id = conf_ids[i];
//                    AA_Choujiang conf = aaCenter.aa_choujiangs[id];
//                    max = conf.chance + max;
//                    min = 0;
//                    if (i == 0) {
//                        min = 0;
//                    }
//                    else {
//                        uint32 id = conf_ids[i - 1];
//                        AA_Choujiang conf = aaCenter.aa_choujiangs[id];
//                        min = conf.chance + min;
//                    }
//
//                    if (min <= chanceVal && chanceVal < max) {
//                        index = i;
//                        break;
//                    }
//                }
//                uint32 id = conf_ids[index];
//                conf = aaCenter.aa_choujiangs[id];
//
//                if (conf.id > 0) {
//                    aaCenter.aa_characterss[guidlow].choujiang += 1;
//                    size_t count = types.size();
//                    for (size_t i = 0; i < count; i++) {
//                        uint32 cishu = AA_SafeObjectAtIndex(types, i);
//                        uint32 reward = AA_SafeObjectAtIndex(values, i);
//                        if (aaCenter.aa_characterss[guidlow].choujiang > cishu &&
//                            aaCenter.aa_characterss[guidlow].choujianglq < cishu) {
//                            aaCenter.aa_characterss[guidlow].choujianglq = cishu;
//                            if (reward > 0) {
//                                aaCenter.M_Reward(player, reward);
//                                std::string msg = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00累计抽奖达到|r【" + std::to_string(cishu) + "次|cffFFFF00】获得了额外奖励|r";
//                                aaCenter.AA_SendMessage(player, 2, msg.c_str());
//                            }
//                        }
//                    }
//                    rcishu++;
//                    itemids.push_back(conf.itemid);
//                    if (conf.reward > 0) {
//                        aaCenter.M_Reward(player, conf.reward);
//                        std::string text = aaCenter.aa_rewards[conf.reward].text;
//                        if (text == "") {
//                            text = aaCenter.AA_GetItemLink(conf.itemid);
//                        }
//                        if (conf.notice == 1) { //显示+公告
//                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + text + "|cffFFFF00】|r";
//                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
//                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + text;
//                            aaCenter.aa_choujiangStrs.push_back(msg2);
//                            if (aaCenter.aa_choujiangStrs.size() > 8) {
//                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
//                            }
//                        }
//                        else if (conf.notice == 2) { //只显示
//                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + text;
//                            aaCenter.aa_choujiangStrs.push_back(msg2);
//                            if (aaCenter.aa_choujiangStrs.size() > 8) {
//                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
//                            }
//                        }
//                        else if (conf.notice == 3) { //只公告
//                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + text + "|cffFFFF00】|r";
//                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
//                        }
//                    }
//                    else {
//                        if (conf.itemid > 0) {
//                            player->AddItem(conf.itemid, 1);
//                        }
//                        if (conf.notice == 1) { //显示+公告
//                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + aaCenter.AA_GetItemLink(conf.itemid) + "|cffFFFF00】|r";
//                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
//                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + aaCenter.AA_GetItemLink(conf.itemid);
//                            aaCenter.aa_choujiangStrs.push_back(msg2);
//                            if (aaCenter.aa_choujiangStrs.size() > 8) {
//                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
//                            }
//                        }
//                        else if (conf.notice == 2) { //只显示
//                            std::string msg2 = aaCenter.AA_GetPlayerNameLink(player) + " 获得了 " + aaCenter.AA_GetItemLink(conf.itemid);
//                            aaCenter.aa_choujiangStrs.push_back(msg2);
//                            if (aaCenter.aa_choujiangStrs.size() > 8) {
//                                aaCenter.aa_choujiangStrs.erase(aaCenter.aa_choujiangStrs.begin());
//                            }
//                        }
//                        else if (conf.notice == 3) { //只公告
//                            std::string msg1 = "|cff00FFFF[幸运抽奖]|r|cffFFFF00【|r" + aaCenter.AA_GetPlayerNameLink(player) + "】|cffFFFF00获得了【|r" + aaCenter.AA_GetItemLink(conf.itemid) + "|cffFFFF00】|r";
//                            aaCenter.AA_SendMessage(player, 2, msg1.c_str());
//                        }
//                    }
//                }
//            }
//            if (needid > 0) {
//                aaCenter.M_Need(player, needid, cishu);
//            }
//            if (aaCenter.aa_world_confs[91].value1 > 0 && cishu >= aaCenter.aa_world_confs[91].value1) {
//                if (aaCenter.aa_world_confs[91].value2 != "" && aaCenter.aa_world_confs[91].value2 != "0") {
//                    uint32 reward = aaCenter.AA_StringUint32(aaCenter.aa_world_confs[91].value2);
//                    if (reward > 0) {
//                        aaCenter.M_Reward(player, reward);
//                    }
//                }
//            }
//            if (rcishu > 0) {
//                CharacterDatabase.DirectExecute("UPDATE _玩家角色数据 SET 累计抽奖次数 = {} WHERE guid = {}", aaCenter.aa_characterss[guidlow].choujiang, guidlow);
//                if (itemids.size() > 0) {
//                    std::string items = "{";
//                    for (uint32 id : itemids) {
//                        items += "\""; items += aaCenter.AA_GetItemLink(id); items += "\",";
//                    }
//                    items += "}";
//                    aaCenter.AA_StringReplaceLast(items, ",}", "}");
//                    aaCenter.M_SendClientAddonData(player, "10073", items);
//                }
//                std::string items = "{";
//                if (aaCenter.aa_choujiangStrs.size() > 0) {
//                    for (std::string str : aaCenter.aa_choujiangStrs) {
//                        items += "\""; items += str; items += "\",";
//                    }
//                }
//                items += "}";
//                aaCenter.AA_StringReplaceLast(items, ",}", "}");
//                aaCenter.M_SendClientAddonData(player, "10072", items);
//            }
//        }
//        else {
//            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的 _奖励_抽奖x_组");
//            return false;
//        }
//
//        return true;
//    }
//    static bool AA_caijiwupin(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.采集物品 物品id 组 数量 注释");
//            return false;
//        }
//
//        uint32 itemId = 0;
//
//        if (args[0] == '[')                                        // [name] manual form
//        {
//            char const* itemNameStr = strtok((char*)args, "]");
//
//            if (itemNameStr && itemNameStr[0])
//            {
//                std::string itemName = itemNameStr + 1;
//                WorldDatabase.EscapeString(itemName);
//
//                WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ITEM_TEMPLATE_BY_NAME);
//                stmt->SetData(0, itemName);
//                PreparedQueryResult result = WorldDatabase.Query(stmt);
//
//                if (!result)
//                {
//                    handler->PSendSysMessage(LANG_COMMAND_COULDNOTFIND, itemNameStr + 1);
//                    handler->SetSentErrorMessage(true);
//                    return false;
//                }
//                itemId = result->Fetch()->Get<uint32>();
//            }
//            else
//                return false;
//        }
//        else                                                    // item_id or [name] Shift-click form |color|Hitem:item_id:0:0:0|h[name]|h|r
//        {
//            char const* id = handler->extractKeyFromLink((char*)args, "Hitem");
//            if (!id)
//                return false;
//            itemId = uint32(atol(id));
//        }
//        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
//        if (!itemTemplate)
//        {
//            handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//        char* arg2 = strtok(nullptr, " ");
//        int32 zu = 1;
//        if (arg2) {
//            zu = int32(std::atoi(arg2));
//        }
//        char* arg3 = strtok(nullptr, " ");
//        uint32 count = 1;
//        if (arg3) {
//            count = int32(std::atoi(arg3));
//        }
//        char* arg4 = strtok(nullptr, " ");
//        std::string zs = "";
//        if (arg4) {
//            zs = arg4;
//        }
//        WorldDatabase.DirectExecute("INSERT INTO __采集_物品 (注释,组,entry,class,subclass,name,displayid,Quality,notice) VALUES ('{}',{},{},{},{},'{}',{},{},{})", zs, zu, itemTemplate->ItemId, itemTemplate->Class, itemTemplate->SubClass, itemTemplate->GetName(LOCALE_zhCN), itemTemplate->DisplayInfoID, itemTemplate->Quality, 1);
//        QueryResult result = WorldDatabase.Query("SELECT id from __采集_物品");
//        int32 rid = 0;
//        if (result) {
//            do {
//                Field* fields = result->Fetch();
//                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
//            } while (result->NextRow());
//        }
//        AA_Caiji_Item conf;
//        conf.text = zs;
//        conf.id = rid + 1;
//        conf.zu = zu;
//        conf.chance = 100;
//        conf.count = count;
//        conf.entry = itemTemplate->ItemId;
//        conf.class1 = itemTemplate->Class;
//        conf.subclass = itemTemplate->SubClass;
//        conf.name = itemTemplate->GetName(LOCALE_zhCN);
//        conf.displayid = itemTemplate->DisplayInfoID;
//        conf.Quality = itemTemplate->Quality;
//        conf.notice = 1;
//        aaCenter.aa_caiji_items[conf.id] = conf;
//        aaCenter.aa_caiji_item_zus[conf.zu].push_back(conf.id);
//        std::string rs = "|cff00FFFF[采集物品]|cffFFFF00模板id:" + std::to_string(conf.id) + " 组:" + std::to_string(zu) + " name:" + itemTemplate->GetName(LOCALE_zhCN);
//        aaCenter.AA_SendMessage(handler->getSelectedPlayerOrSelf(), 0, rs.c_str());
//        return true;
//    }
//    static bool AA_lingquleichong(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a1b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取累充 数值");
//            return false;
//        }
//        uint32 level = atoi(typestr);
//        AA_Reward_Leiji_Conf conf = aaCenter.aa_reward_leiji_confs[level];
//        if (conf.jifen > 0) {
//            std::vector<int32> levelv; levelv.clear();
//            uint32 accountid = player->GetSession()->GetAccountId();
//            AA_Account a_conf = aaCenter.aa_accounts[accountid];
//            time_t timep;
//            time(&timep);
//            a_conf.update_time = timep;
//            a_conf.isUpdate = true;
//            std::string levels = a_conf.leichong;
//            aaCenter.AA_StringToVectorInt(levels, levelv, ",");
//            bool isOk = false;
//            for (size_t i = 0; i < levelv.size(); i++) {
//                uint32 leveli = levelv[i];
//                if (leveli == conf.jifen) {
//                    isOk = true; break;
//                }
//            }
//            if (a_conf.jifen_all < conf.jifen) {
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
//                return false;
//            }
//            if (!isOk) { //没有领取过
//                if (levels == "") {
//                    a_conf.leichong = std::to_string(level);
//                }
//                else {
//                    a_conf.leichong = levels + "," + std::to_string(level);
//                }
//                aaCenter.aa_accounts[accountid] = a_conf;
//                if (conf.reward > 0) {
//                    aaCenter.M_Reward(player, conf.reward);
//                }
//                if (conf.notice > 0) {
//                    AA_Message aa_message;
//                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                }
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
//                aaCenter.M_SendAA_Conf(player, "1005");
//                return true;
//            }
//            else {
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
//                return true;
//            }
//        }
//        return true;
//    }
//    static bool AA_lingqushouchong(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a3b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 accountid = player->GetSession()->GetAccountId();
//        AA_Account a_conf = aaCenter.aa_accounts[accountid];
//        time_t time1 = time(NULL);//获取系统时间，单位为秒;
//        struct tm* time = localtime(&time1);//转换成tm类型的结构体;
//        uint32 day = time->tm_wday == 0 ? 7 : time->tm_wday;
//        AA_Reward_Shouchong_Conf it = aaCenter.aa_reward_shouchong_confs[day];
//        if (a_conf.shouchong_day < it.jifen) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
//            return false;
//        }
//        if (a_conf.shouchong == 1) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
//            return true;
//        }
//        if (it.reward > 0) {
//            aaCenter.M_Reward(player, it.reward);
//        }
//        if (it.notice > 0) {
//            AA_Message aa_message;
//            AA_Notice notice = aaCenter.aa_notices[it.notice];
//            aaCenter.AA_SendNotice(player, notice, true, aa_message);
//        }
//        aaCenter.aa_accounts[accountid].shouchong = 1;
//        aaCenter.aa_accounts[accountid].isUpdate = true;
//        aaCenter.aa_accounts[accountid].update_time = time1;
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
//        aaCenter.M_SendAA_Conf(player, "1004");
//        return true;
//    }
//    static bool AA_lingquqiandao(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取签到 签到索引天数");
//            return false;
//        }
//        uint32 level = atoi(typestr);
//        AA_Reward_Qiandao_Conf conf = aaCenter.aa_reward_qiandao_confs[level];
//        if (level == 999) { //签到
//            uint32 accountid = player->GetSession()->GetAccountId();
//            AA_Account a_conf = aaCenter.aa_accounts[accountid];
//            if (a_conf.denglu_qiandao == 1) { //已签到
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你今天已经签到了。");
//                aaCenter.M_SendAA_Conf(player, "1006");
//            }
//            else {
//                if (conf.reward > 0) {
//                    aaCenter.M_Reward(player, conf.reward);
//                }
//                if (conf.notice > 0) {
//                    AA_Message aa_message;
//                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                }
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00签到成功");
//                aaCenter.aa_accounts[accountid].denglu_qiandao = 1;
//                aaCenter.aa_accounts[accountid].denglu_day += 1;
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_accounts[accountid].update_time = timep;
//                aaCenter.aa_accounts[accountid].isUpdate = true;
//                aaCenter.M_SendAA_Conf(player, "1006");
//            }
//        }
//        else if (level > 0) { //领取奖励
//            if (conf.day > 0) {
//                std::vector<int32> levelv; levelv.clear();
//                uint32 accountid = player->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                std::string levels = a_conf.denglu;
//                aaCenter.AA_StringToVectorInt(levels, levelv, ",");
//                bool isOk = false;
//                for (size_t i = 0; i < levelv.size(); i++) {
//                    uint32 leveli = levelv[i];
//                    if (leveli == conf.day) {
//                        isOk = true; break;
//                    }
//                }
//                if (a_conf.denglu_day < conf.day) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000条件不足");
//                    return true;
//                }
//                if (!isOk) { //没有领取过
//                    if (levels == "") {
//                        aaCenter.aa_accounts[accountid].denglu = std::to_string(level);
//                    }
//                    else {
//                        aaCenter.aa_accounts[accountid].denglu = levels + "," + std::to_string(level);
//                    }
//                    time_t timep;
//                    time(&timep);
//                    aaCenter.aa_accounts[accountid].update_time = timep;
//                    aaCenter.aa_accounts[accountid].isUpdate = true;
//                    if (conf.reward > 0) {
//                        aaCenter.M_Reward(player, conf.reward);
//                    }
//                    if (conf.notice > 0) {
//                        AA_Message aa_message;
//                        AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                        aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                    }
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
//                    aaCenter.M_SendAA_Conf(player, "1006");
//                }
//                else { //已经领取过
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
//                }
//            }
//        }
//
//        return true;
//    }
//    static bool AA_lingqudengji(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a4b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.领取等级 索引等级");
//            return false;
//        }
//        uint32 level = atoi(typestr);
//        AA_Reward_Level_Conf conf = aaCenter.aa_reward_level_confs[level];
//        if (conf.level > 0) {
//            std::vector<int32> levelv; levelv.clear();
//            ObjectGuid::LowType guidlow = player->GetGUIDLow();
//            AA_Characters aconf = aaCenter.aa_characterss[guidlow];
//            AA_Characters_Junxian jxconf = aaCenter.aa_characters_junxians[guidlow];
//            AA_Characters_Douqi dqconf = aaCenter.aa_characters_douqis[guidlow];
//            AA_Characters_Dianfeng dfconf = aaCenter.aa_characters_dianfengs[guidlow];
//            std::string levels = aconf.shengji;
//            aaCenter.AA_StringToVectorInt(levels, levelv, ",");
//            bool isOk = false;
//            for (size_t i = 0; i < levelv.size(); i++) {
//                uint32 leveli = levelv[i];
//                if (leveli == conf.level) {
//                    isOk = true; break;
//                }
//            }
//            if (conf.type == 0) { //等级类型(0普通1vip2军衔3斗气4巅峰)
//                if (player->GetLevel() < level) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
//                    return false;
//                }
//            }
//            else if (conf.type == 1) {
//                uint32 accountid = player->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                if (a_conf.vip < level) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
//                    return false;
//                }
//            }
//            else if (conf.type == 2) {
//                if (jxconf.level < level) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
//                    return false;
//                }
//            }
//            else if (conf.type == 3) {
//                if (dqconf.level < level) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
//                    return false;
//                }
//            }
//            else if (conf.type == 4) {
//                if (dfconf.level < level) {
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000等级不足");
//                    return false;
//                }
//            }
//            if (!isOk) { //没有领取过
//                if (levels == "") {
//                    aaCenter.aa_characterss[player->GetGUIDLow()].shengji = std::to_string(level);
//                }
//                else {
//                    aaCenter.aa_characterss[player->GetGUIDLow()].shengji = levels + "," + std::to_string(level);
//                }
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_characterss[player->GetGUIDLow()].update_time = timep;
//                aaCenter.aa_characterss[player->GetGUIDLow()].isUpdate = true;
//                if (conf.reward > 0) {
//                    aaCenter.M_Reward(player, conf.reward);
//                }
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
//                if (conf.notice > 0) {
//                    AA_Message aa_message;
//                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                    aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                }
//                aaCenter.M_SendAA_Conf(player, "1002");
//            }
//            else {
//                if (conf.notice > 0) {
//                    AA_Message aa_message;
//                    AA_Notice notice = aaCenter.aa_notices[conf.notice];
//                    aaCenter.AA_SendNotice(player, notice, false, aa_message);
//                }
//                aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已经领取过奖励");
//            }
//        }
//        return true;
//    }
//    static bool AA_lingqulicai(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a2b")) {
//            return false;
//        }
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 accountid = player->GetSession()->GetAccountId();
//        AA_Account a_conf = aaCenter.aa_accounts[accountid];
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_accounts[accountid].update_time = timep;
//        aaCenter.aa_accounts[accountid].isUpdate = true;
//        AA_Reward_Licai_Conf it = aaCenter.aa_reward_licai_confs[1];
//        //                std::string status = "0"; // 0领取 1已领取 2未达到
//        if (a_conf.licai_day == 0) { //购买
//            if (it.need > 0) {
//                if (aaCenter.M_CanNeed(player, it.need)) {
//                    aaCenter.M_Need(player, it.need);
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00购买成功");
//                    aaCenter.aa_accounts[accountid].licai_day += it.day;
//                    aaCenter.M_SendAA_Conf(player, "1003");
//                }
//            }
//        }
//        else { // 领取
//            if (a_conf.licai == 0) {
//                if (it.reward > 0) {
//                    aaCenter.M_Reward(player, it.reward);
//                    aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00领取成功");
//                    aaCenter.aa_accounts[accountid].licai_day -= 1;
//                    aaCenter.aa_accounts[accountid].licai = 1;
//                    aaCenter.M_SendAA_Conf(player, "1003");
//                    if (it.notice > 0) {
//                        AA_Message aa_message;
//                        AA_Notice notice = aaCenter.aa_notices[it.notice];
//                        aaCenter.AA_SendNotice(player, notice, true, aa_message);
//                    }
//                }
//            }
//        }
//        return true;
//    }
//    static bool AA_gerenyinhang(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->GetSession()->SendShowBank(player->GetGUID());
//        return true;
//    }
//    static bool AA_gerenyouxiang(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->GetSession()->SendShowMailBox(player->GetGUID());
//        return true;
//    }
//    static bool AA_zhuangbeixiuli(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->DurabilityRepairAll(false, 0, false);
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修理装备成功!");
//        return true;
//    }
//    static bool AA_chongzhichongwutianfu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (!player->IsAlive()) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000死亡状态下无法使用!");
//            return false;
//        }
//        Pet* pet = player->GetPet();
//
//        if (!pet || pet->getPetType() != HUNTER_PET)
//        {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你没有猎人宠物!");
//            return false;
//        }
//        if (pet->m_usedTalentCount == 0)
//        {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的宠物没有天赋可重置!");
//            return false;
//        }
//        player->ResetPetTalents();
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置宠物天赋成功!");
//        return true;
//    }
//    static bool AA_chongzhitianfu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (!player->IsAlive()) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000死亡状态下无法使用!");
//            return false;
//        }
//        Player* me = handler->GetSession()->GetPlayer();
//        std::string gm = "";
//        if (me == player) {
//            gm = ".组合 *.reset talents<$自身>";
//            if (me->IsInWorld()) {
//                if (Pet* pet = me->GetPet()) {
//                    if (pet->IsInWorld()) {
//                        pet->RemoveFromWorld();
//                    }
//                }
//            }
//        }
//        else {
//            gm = ".组合 *.reset talents<$目标>";
//        }
//        uint32 curCount = player->GetSpecsCount();
//        if (curCount == 2) {
//            uint8 spec = player->GetActiveSpec();
//            aaCenter.AA_DoCommand(player, gm.c_str());
//            if (spec == 0) {
//                player->ActivateSpec(1);
//                aaCenter.AA_DoCommand(player, gm.c_str());
//            }
//            else {
//                player->ActivateSpec(0);
//                aaCenter.AA_DoCommand(player, gm.c_str());
//            }
//        }
//        else {
//            aaCenter.AA_DoCommand(player, gm.c_str());
//        }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置天赋成功!");
//        return true;
//    }
//    static bool AA_shuangtianfu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->LearnSpell(63644, true);
//        player->CastSpell(player, 63624);
//        player->LearnSpell(63645);
//        player->UpdateSpecCount(2);
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00学习双天赋成功!");
//        return true;
//    }
//    static bool AA_jiechuxuruo(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (player->HasAura(15007)) { player->RemoveAura(15007); }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00解除虚弱成功!");
//        return true;
//    }
//
//    static bool AA_chongzhifuben(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayer();
//        if (!player)
//            player = handler->GetSession()->GetPlayer();
//
//        uint16 counter = 0;
//
//        char* mapstr = strtok((char*)args, " ");
//        if (!mapstr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.重置副本 mapid(-1表示所有副本)");
//            return false;
//        }
//
//        int32 mapId = atoi(mapstr);
//
//        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
//        {
//            BoundInstancesMap const& m_boundInstances = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUID(), Difficulty(i));
//            for (BoundInstancesMap::const_iterator itr = m_boundInstances.begin(); itr != m_boundInstances.end();)
//            {
//                InstanceSave const* save = itr->second.save;
//                if (itr->first != player->GetMapId() && (mapId == -1 || !mapId || mapId == itr->first))
//                {
//                    uint32 resetTime = itr->second.extended ? save->GetExtendedResetTime() : save->GetResetTime();
//                    uint32 ttr = (resetTime >= time(nullptr) ? resetTime - time(nullptr) : 0);
//                    std::string timeleft = secsToTimeString(ttr);
//                    handler->PSendSysMessage("unbinding map: %d, inst: %d, perm: %s, diff: %d, canReset: %s, TTR: %s%s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str(), (itr->second.extended ? " (extended)" : ""));
//                    sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUID(), itr->first, Difficulty(i), true, player);
//                    sInstanceSaveMgr->DeleteInstanceSaveIfNeeded(save->GetInstanceId(), true);
//                    itr = m_boundInstances.begin();
//                    counter++;
//                }
//                else
//                    ++itr;
//            }
//        }
//
//        handler->PSendSysMessage("重置副本成功: 地图ID %d", counter);
//
//        return true;
//    }
//    static bool AA_jiechuzhandou(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (player->combatTime > 10000) {
//            player->ClearInCombat();
//            player->ClearInPetCombat();
//            player->combatTime = 0;
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00脱离战斗成功!");
//        }
//        else {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000功能冷却中!");
//        }
//        return true;
//    }
//    static bool AA_huifuhpmp(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        if (player->getPowerType() == POWER_MANA) {
//            player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
//        }
//        player->SetHealth(player->GetMaxHealth());
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00恢复生命和魔法!");
//        return true;
//    }
//    static bool AA_chongzhijineng(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->RemoveArenaSpellCooldowns();
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置冷却成功!");
//        return true;
//    }
//    static bool AA_jiarubaituan(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.加入百团大战 战场id");
//            return false;
//        }
//        uint32 type = atoi(typestr);
//
//        WorldPacket data;
//        data << player->GetGUID();
//        data << type;
//        data << 99;
//        data << 0;
//        player->GetSession()->HandleBattlemasterJoinOpcode(data);
//        return true;
//    }
//    static bool AA_xiugaizhenying(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择阵营!");
//        std::string gm = ".组合 *.character changefaction<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        return true;
//    }
//    static bool AA_xiugaizhongzhu(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择种族!");
//        std::string gm = ".组合 *.character changerace<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        return true;
//    }
//    static bool AA_xiugaimingzi(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退修改名字!");
//        std::string gm = ".组合 *.character rename<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        return true;
//    }
//    static bool AA_xiugaiwaiguan(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00修改成功，请小退重新选择外观!");
//        std::string gm = ".组合 *.character customize<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        return true;
//    }
//    static bool AA_dianfengshuxing(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        char* valuestr = strtok(NULL, " ");
//        if (!typestr || !valuestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.巅峰属性 属性类型 属性值");
//            return false;
//        }
//        uint32 type = atoi(typestr);
//        uint32 value = atoi(valuestr);
//        if (type != 1000)
//        {
//            if (type < 0) {
//                return false;
//            }
//        }
//        if (value <= 0) {
//            return false;
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Dianfeng d_conf = aaCenter.aa_characters_dianfengs[guidlow];
//        if (d_conf.dianshu == -1) { //重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
//            return false;
//        }
//        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
//            int32 num = 0;
//            {
//                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
//                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
//                aaCenter.AA_SendMessage(player, 1, msg.c_str());
//                return false;
//            }
//        }
//        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
//            return false;
//        }
//        aaCenter.aa_characters_dianfengs[guidlow].dianshu = d_conf.dianshu + 1;
//        if (type == 1000) { //天赋
//            aaCenter.aa_characters_dianfengs[guidlow].tianfu = d_conf.tianfu + value;
//            player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
//            if (!player->GetSession()->PlayerLoading())
//                player->SendTalentsInfoData(false);                         // update at client
//        }
//        else {
//            std::map<int32, int32> values; values.clear();
//            aaCenter.AA_StringToMap(d_conf.value, values);
//            values[type] += value;
//            std::string str = "";
//            aaCenter.AA_MapToString(values, str);
//            aaCenter.aa_characters_dianfengs[guidlow].value = str;
//            aaCenter.AddValue(player, type, value, true);
//        }
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
//        aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_douqishuxing(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        char* valuestr = strtok(NULL, " ");
//        if (!typestr || !valuestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.斗气属性 属性类型 属性值");
//            return false;
//        }
//        uint32 type = atoi(typestr);
//        uint32 value = atoi(valuestr);
//        if (type != 1000)
//        {
//            if (type < 0) {
//                return false;
//            }
//        }
//        if (value <= 0) {
//            return false;
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Douqi d_conf = aaCenter.aa_characters_douqis[guidlow];
//        if (d_conf.dianshu == -1) { //重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
//            return false;
//        }
//        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
//            int32 num = 0;
//            {
//                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
//                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
//                aaCenter.AA_SendMessage(player, 1, msg.c_str());
//                return false;
//            }
//        }
//        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
//            return false;
//        }
//        aaCenter.aa_characters_douqis[guidlow].dianshu = d_conf.dianshu + 1;
//        if (type == 1000) { //天赋
//            aaCenter.aa_characters_douqis[guidlow].tianfu = d_conf.tianfu + value;
//            player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
//            if (!player->GetSession()->PlayerLoading())
//                player->SendTalentsInfoData(false);                         // update at client
//        }
//        else {
//            std::map<int32, int32> values; values.clear();
//            aaCenter.AA_StringToMap(d_conf.value, values);
//            values[type] += value;
//            std::string str = "";
//            aaCenter.AA_MapToString(values, str);
//            aaCenter.aa_characters_douqis[guidlow].value = str;
//            aaCenter.AddValue(player, type, value, true);
//        }
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_douqis[guidlow].update_time = timep;
//        aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_junxianshuxing(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        char* valuestr = strtok(NULL, " ");
//        if (!typestr || !valuestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.军衔属性 属性类型 属性值");
//            return false;
//        }
//        uint32 type = atoi(typestr);
//        uint32 value = atoi(valuestr);
//        if (type != 1000)
//        {
//            if (type < 0) {
//                return false;
//            }
//        }
//        if (value <= 0) {
//            return false;
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Junxian d_conf = aaCenter.aa_characters_junxians[guidlow];
//        if (d_conf.dianshu == -1) { //重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你重置过属性，请小退!");
//            return false;
//        }
//        if (aaCenter.aa_stat_xianzhis[type].value > 0) {
//            int32 num = 0;
//            {
//                std::string c_value = aaCenter.aa_characters_dianfengs[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_douqis[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            {
//                std::string c_value = aaCenter.aa_characters_junxians[guidlow].value;
//                std::map<int32, int32> values; values.clear();
//                aaCenter.AA_StringToMap(c_value, values);
//                num += values[type];
//            }
//            if (num >= aaCenter.aa_stat_xianzhis[type].value) {
//                std::string msg = "|cff00FFFF[系统提示]|cffFF0000这个属性最大限制" + std::to_string(aaCenter.aa_stat_xianzhis[type].value) + "点。";
//                aaCenter.AA_SendMessage(player, 1, msg.c_str());
//                return false;
//            }
//        }
//        if (d_conf.dianshu_all - d_conf.dianshu <= 0) {//点数不足
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你的点数不足!");
//            return false;
//        }
//        aaCenter.aa_characters_junxians[guidlow].dianshu = d_conf.dianshu + 1;
//        if (type == 1000) { //天赋
//            aaCenter.aa_characters_junxians[guidlow].tianfu = d_conf.tianfu + value;
//            player->SetFreeTalentPoints(player->GetFreeTalentPoints() + value);
//            if (!player->GetSession()->PlayerLoading())
//                player->SendTalentsInfoData(false);                         // update at client
//        }
//        else {
//            std::map<int32, int32> values; values.clear();
//            aaCenter.AA_StringToMap(d_conf.value, values);
//            values[type] += value;
//            std::string str = "";
//            aaCenter.AA_MapToString(values, str);
//            aaCenter.aa_characters_junxians[guidlow].value = str;
//            aaCenter.AddValue(player, type, value, true);
//        }
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_junxians[guidlow].update_time = timep;
//        aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_chongzhidianfeng(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 need = aaCenter.aa_world_confs[51].value1;
//        if (need > 0) {
//            if (!aaCenter.M_CanNeed(player, need)) {
//                return false;
//            }
//            aaCenter.M_Need(player, need);
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Dianfeng d_conf = aaCenter.aa_characters_dianfengs[guidlow];
//        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000没有可重置的点数!");
//            return false;
//        }
//        aaCenter.aa_characters_dianfengs[guidlow].value = "";
//        aaCenter.aa_characters_dianfengs[guidlow].dianshu = -1;
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
//        aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_chongzhidouqi(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 need = aaCenter.aa_world_confs[53].value1;
//        if (need > 0) {
//            if (!aaCenter.M_CanNeed(player, need)) {
//                return false;
//            }
//            aaCenter.M_Need(player, need);
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Douqi d_conf = aaCenter.aa_characters_douqis[guidlow];
//        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00没有可重置的点数!");
//            return false;
//        }
//        aaCenter.aa_characters_douqis[guidlow].value = "";
//        aaCenter.aa_characters_douqis[guidlow].dianshu = -1;
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_douqis[guidlow].update_time = timep;
//        aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_chongzhijunxian(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 need = aaCenter.aa_world_confs[52].value1;
//        if (need > 0) {
//            if (!aaCenter.M_CanNeed(player, need)) {
//                return false;
//            }
//            aaCenter.M_Need(player, need);
//        }
//        ObjectGuid::LowType guidlow = player->GetGUIDLow();
//        AA_Characters_Junxian d_conf = aaCenter.aa_characters_junxians[guidlow];
//        if (d_conf.dianshu == -1 || d_conf.dianshu == 0 || d_conf.dianshu_all == 0) { //无需重置
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00没有可重置的点数!");
//            return false;
//        }
//        aaCenter.aa_characters_junxians[guidlow].value = "";
//        aaCenter.aa_characters_junxians[guidlow].dianshu = -1;
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00重置成功，请小退生效!");
//        time_t timep;
//        time(&timep);
//        aaCenter.aa_characters_junxians[guidlow].update_time = timep;
//        aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
//        return true;
//    }
//    static bool AA_huiyuanshengji(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint32 accountid = player->GetSession()->GetAccountId();
//        uint32 viplevel = aaCenter.aa_accounts[accountid].vip + 1;
//        AA_Vip_Conf conf = aaCenter.aa_vip_confs[viplevel];
//        if (conf.level <= 0) {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000你已达到最大会员等级");
//            return false;
//        }
//        if (conf.need > 0) {
//            if (!aaCenter.M_CanNeed(player, conf.need)) {
//                return false;
//            }
//            else {
//                aaCenter.M_Need(player, conf.need);
//            }
//        }
//        aaCenter.aa_accounts[accountid].vip = viplevel;
//        AA_Vip_Conf vip_conf = aaCenter.aa_vip_confs[viplevel];
//        if (vip_conf.reward > 0) {
//            aaCenter.M_Reward(player, vip_conf.reward);
//        }
//        if (vip_conf.notice > 0) {
//            AA_Message aa_message;
//            AA_Notice notice = aaCenter.aa_notices[vip_conf.notice];
//            aaCenter.AA_SendNotice(player, notice, true, aa_message);
//        }
//        return true;
//    }
//    static bool AA_paihangjiangli(ChatHandler* handler, const char* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a200b")) {
//            return false;
//        }
//        Player* me = handler->getSelectedPlayerOrSelf();
//        if (!me || !me->IsInWorld()) {
//            return false;
//        }
//        aaCenter.AA_PaihangReward();
//        return true;
//    }
//    static bool AA_bianshen(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            char* disstr = strtok((char*)args, " ");
//            char* scalestr = strtok(NULL, " ");
//            char* timestr = strtok(NULL, " ");
//            if (!disstr || !scalestr)
//            {
//                ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.变身 模型id 模型大小 变身单位秒（可选）");
//                return false;
//            }
//            uint32 display = atoi(disstr);
//            double scale = aaCenter.AA_StringFloat(scalestr);
//            uint32 time = 0;
//            if (timestr) {
//                time = atoi(timestr);
//            }
//
//            std::string msg = "";
//            if (target->GetDisplayId() == display) {
//                aaCenter.aa_bianshen1[target->GetGUIDLow()] = 0;
//                aaCenter.aa_bianshen2[target->GetGUIDLow()] = 0;
//                target->RestoreDisplayId();
//                target->SetObjectScale(1);
//                if (time == 0) {
//                    std::string gm = ".组合 *.变量 角色 modelid =0<$自身>";
//                    aaCenter.AA_DoCommand(target, gm.c_str());
//                    gm = ".组合 *.变量 角色 scale =0<$自身>";
//                    aaCenter.AA_DoCommand(target, gm.c_str());
//                }
//                time = 0;
//            }
//            else {
//                aaCenter.aa_bianshen1[target->GetGUIDLow()] = display;
//                aaCenter.aa_bianshen2[target->GetGUIDLow()] = scale;
//                if (time == 0) {
//                    std::string gm = ".组合 *.变量 角色 modelid =" + std::to_string(display) + "<$自身>";
//                    aaCenter.AA_DoCommand(target, gm.c_str());
//                    gm = ".组合 *.变量 角色 scale =" + std::to_string(scale) + "<$自身>";
//                    aaCenter.AA_DoCommand(target, gm.c_str());
//                }
//            }
//            aaCenter.aa_bianshen3[target->GetGUIDLow()] = time * 1000;
//        }
//        return true;
//    }
//    static bool AA_shasiquantu(ChatHandler* handler, const char* args)
//    {
//        Player* me = handler->getSelectedPlayerOrSelf();
//        std::list<Creature*> list; list.clear();
//        aaCenter.BB_GetCreatureListInMap(me, list, me->GetMapId());
//        for (Creature* target : list)
//        {
//            if (target->IsAlive())
//            {
//                if (sWorld->getBoolConfig(CONFIG_DIE_COMMAND_MODE))
//                {
//                    if (target->GetTypeId() == TYPEID_UNIT && handler->GetSession()->GetSecurity() == SEC_CONSOLE) // pussywizard
//                        target->ToCreature()->LowerPlayerDamageReq(target->GetMaxHealth());
//                    Unit::Kill(handler->getSelectedPlayerOrSelf(), target);
//                }
//                else
//                    Unit::DealDamage(handler->getSelectedPlayerOrSelf(), target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false, true);
//            }
//
//        }
//
//        return true;
//    }
//    static bool AA_zhuanye(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.专业 专业中文拼音缩写 数值，如.专业 cy 450");
//            return false;
//        }
//
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        char* skillName = strtok((char*)args, " ");
//        char* value = strtok(NULL, " ");
//        if (!skillName || !value)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.专业 专业中文拼音缩写 数值，如.专业 cy 450");
//            return false;
//        }
//
//        uint32 skillid = 0;
//
//        if (strcmp(skillName, "cy") == 0)        skillid = 182;
//        else if (strcmp(skillName, "ck") == 0)    skillid = 186;
//        else if (strcmp(skillName, "bp") == 0)    skillid = 393;
//        else if (strcmp(skillName, "dz") == 0)    skillid = 164;
//        else if (strcmp(skillName, "cf") == 0)    skillid = 197;
//        else if (strcmp(skillName, "zp") == 0)    skillid = 165;
//        else if (strcmp(skillName, "gc") == 0)    skillid = 202;
//        else if (strcmp(skillName, "lj") == 0)    skillid = 171;
//        else if (strcmp(skillName, "mw") == 0)    skillid = 773;
//        else if (strcmp(skillName, "fm") == 0)    skillid = 333;
//        else if (strcmp(skillName, "zb") == 0)    skillid = 755;
//        else if (strcmp(skillName, "jj") == 0)    skillid = 129;
//        else if (strcmp(skillName, "pr") == 0)    skillid = 185;
//        else if (strcmp(skillName, "dy") == 0)    skillid = 356;
//
//        int32 point = atoi(value);
//
//        if (skillid == 0 || point <= 0)
//            return false;
//
//        if (target->HasSkill(skillid) && target->GetSkillValue(skillid) < point)
//            target->SetSkill(skillid, 1, point, point);
//
//        return true;
//    }
//    static bool AA_zhaohuan(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.召唤 参数1：entry（正数 - Creature Entry;负数 - Gameobject Entry) 参数2：存在时间(Creature或Gameobject持续的时间，单位秒）参数3 ：难度id(可选参数，_属性调整_生物_id或_属性调整_物体_id 参数4：坐标x（可选） 参数5：坐标y（可选） 参数6：坐标z（可选） 参数7：坐标o（可选）");
//            return false;
//        }
//
//        char* s_entry = strtok((char*)args, " ");
//        char* s_time = strtok(NULL, " ");
//        char* n_id = strtok(NULL, " ");
//        char* xstr = strtok(NULL, " ");
//        char* ystr = strtok(NULL, " ");
//        char* zstr = strtok(NULL, " ");
//        char* ostr = strtok(NULL, " ");
//
//        if (!s_entry || !s_time)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.召唤 参数1：entry（正数 - Creature Entry;负数 - Gameobject Entry) 参数2：存在时间(Creature或Gameobject持续的时间，单位秒）参数3 ：难度id(可选参数，_属性调整_生物_id或_属性调整_物体_id 参数4：坐标x（可选） 参数5：坐标y（可选） 参数6：坐标z（可选） 参数7：坐标o（可选）");
//            return false;
//        }
//        float x = 0;
//        float y = 0;
//        float z = 0;
//        float o = 0;
//        if (xstr) {
//            x = (float)atof(xstr);
//        }
//        if (ystr) {
//            y = (float)atof(ystr);
//        }
//        if (zstr) {
//            z = (float)atof(zstr);
//        }
//        if (ostr) {
//            o = (float)atof(ostr);
//        }
//
//        int32 entry = atoi(s_entry);
//        uint32 time = atoi(s_time);
//        uint32 nandu = 0;
//        if (n_id) {
//            nandu = atoi(n_id);
//        }
//        Map* map = target->GetMap();
//        if (!map) {
//            return false;
//        }
//
//        Position pos;
//        if (x != 0) {
//            pos.m_positionX = x;
//            pos.m_positionY = y;
//            pos.m_positionZ = z;
//            pos.SetOrientation(o);
//        }
//        else {
//            pos.m_positionX = target->GetPositionX();
//            pos.m_positionY = target->GetPositionY();
//            pos.m_positionZ = target->GetPositionZ();
//            pos.SetOrientation(target->GetOrientation());
//        }
//        if (entry > 0) {
//            Creature* creature = nullptr;
//
//            if (Map* map = target->GetMap()) {
//                creature = target->SummonCreature(entry, pos, TEMPSUMMON_TIMED_DESPAWN, time * 1000s);
//            }
//            if (nandu > 0) {
//                AA_Creature conf = aaCenter.aa_creatures[nandu];
//                if (conf.id > 0) {
//                    aaCenter.AA_ModifyCreature(creature, conf);
//                }
//            }
//            AA_Boss_Conf bconf = aaCenter.aa_boss_confs[entry];
//
//            if (creature && bconf.id > 0) {
//                creature->aa_boss_id = bconf.id;
//                creature->aa_boss_time_max = (time / 60);
//                creature->aa_boss_time = 0;
//                creature->aa_boss_dmg.clear();
//            }
//        }
//        else if (entry < 0) {
//            GameObject* gameObject = map->SummonGameObject(abs(entry), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, time, false);
//
//            if (nandu > 0) {
//                AA_Object conf = aaCenter.aa_objects[nandu];
//                if (conf.id > 0) {
//                    aaCenter.AA_ModifyGameObject(gameObject, conf);
//                }
//            }
//        }
//
//        return true;
//    }
//
//    static bool AA_zhaohuanmoban(ChatHandler* handler, const char* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!*args)
//        {
//            if (target) {
//                aaCenter.AA_SendMessage(target, 1, "语法格式:.召唤模板 参数1:（__采集_生物_组 time） 参数2（Creature或Gameobject持续的时间，单位 秒)  参数3，可选（是否组内随机，0组内按几率随机一个，1组内全部召唤）  参数4，可选(_属性调整_生物_id或_属性调整_物体_id");
//            }
//            return false;
//        }
//
//        if (!target->GetMap()) {
//            return false;
//        }
//
//        char* s_zu = strtok((char*)args, " ");
//        char* s_time = strtok(NULL, " ");
//        char* s_suiji = strtok(NULL, " ");
//        char* n_id = strtok(NULL, " ");
//
//        if (!s_zu || !s_time)
//        {
//            if (target) {
//                aaCenter.AA_SendMessage(target, 1, "语法格式:.召唤模板 参数1:（__采集_生物_组 time） 参数2（Creature或Gameobject持续的时间，单位 秒)  参数3，可选（是否组内随机，0组内按几率随机一个，1组内全部召唤）  参数4，可选(_属性调整_生物_id或_属性调整_物体_id");
//            }
//            return false;
//        }
//
//        int32 zu = atoi(s_zu);
//        uint32 time = atoi(s_time);
//        uint32 suiji = 0;
//        uint32 nandu = 0;
//        if (s_suiji) {
//            suiji = atoi(s_suiji);
//        }
//        if (n_id) {
//            nandu = atoi(n_id);
//        }
//
//        std::vector<uint32> conf_ids = aaCenter.aa_caiji_creature_zus[zu];
//        if (suiji == 0) {
//            //获取总chance，分母
//            int count = conf_ids.size();
//            if (count) {
//                uint32 chanceMax = 0;
//                for (int i = 0; i < count; i++) {
//                    uint32 id = conf_ids[i];
//                    AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
//                    chanceMax += conf.chance;
//                }
//                if (chanceMax == 0) { chanceMax = 1; }
//                //获取随机chance，分子
//                uint32 chanceVal = rand() % chanceMax;
//                //获取Index
//                uint32 max = 0;
//                uint32 min = 0;
//                int index = -1;
//                for (int i = 0; i < count; i++) {
//                    uint32 id = conf_ids[i];
//                    AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
//                    max = conf.chance + max;
//                    min = 0;
//                    if (i == 0) {
//                        min = 0;
//                    }
//                    else {
//                        uint32 id = conf_ids[i - 1];
//                        AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
//                        min = conf.chance + min;
//                    }
//
//                    if (min <= chanceVal && chanceVal < max) {
//                        index = i;
//                        break;
//                    }
//                }
//                uint32 id = conf_ids[index];
//                conf_ids.clear();
//                conf_ids.push_back(id);
//            }
//        }
//        for (auto id : conf_ids) {
//            AA_Caiji_Creature conf = aaCenter.aa_caiji_creatures[id];
//            Map* map = nullptr;
//            if (map = sMapMgr->CreateMap(conf.map, target)) {
//                if (map->IsDungeon()) {//如果是副本，并且自己也在当前副本，召唤生物。
//                    if (target->GetMapId() == conf.map) {
//                        map = sMapMgr->FindMap(conf.map, target->GetInstanceId());
//                    }
//                }
//            }
//            if (!map) {
//                continue;
//            }
//            if (conf.entry > 0) {
//                Creature* creature = nullptr;
//
//                Position pos;
//                pos.m_positionX = conf.position_x;
//                pos.m_positionY = conf.position_y;
//                pos.m_positionZ = conf.position_z;
//                pos.SetOrientation(conf.orientation);
//
//                creature = map->SummonCreature(conf.entry, pos, NULL, time * 1000);
//                if (creature) {
//                    if (nandu > 0) {
//                        AA_Creature conf = aaCenter.aa_creatures[nandu];
//                        if (conf.id > 0) {
//                            aaCenter.AA_ModifyCreature(creature, conf);
//                        }
//                    }
//
//                    AA_Boss_Conf bconf = aaCenter.aa_boss_confs[conf.entry];
//                    if (creature && bconf.id > 0) {
//                        creature->aa_boss_id = bconf.id;
//                        creature->aa_boss_time_max = (time / 60);
//                        creature->aa_boss_time = 0;
//                        creature->aa_boss_dmg.clear();
//                    }
//                }
//            }
//            else {
//                GameObject* gameObject = map->SummonGameObject(abs(conf.entry), conf.position_x, conf.position_y, conf.position_z, conf.orientation, 0.0f, 0.0f, 0.0f, 0.0f, time, false);
//                if (nandu > 0) {
//                    AA_Object conf = aaCenter.aa_objects[nandu];
//                    if (conf.id > 0) {
//                        aaCenter.AA_ModifyGameObject(gameObject, conf);
//                    }
//                }
//            }
//        }
//        
//        return true;
//    }
//    static bool AA_chongzhilicailingqu(ChatHandler* handler, char const* args)
//    {
//        Player* receiver = handler->getSelectedPlayerOrSelf();
//        if (!receiver || !receiver->IsInWorld()) {
//            return false;
//        }
//        time_t timep;
//        time(&timep);
//        if (receiver) {
//            uint32 accountid = receiver->GetSession()->GetAccountId();
//            AA_Account conf = aaCenter.aa_accounts[accountid];
//            conf.id = accountid;
//            conf.licai = 0;
//            conf.isUpdate = true;
//            conf.update_time = timep;
//            aaCenter.aa_accounts[accountid] = conf;
//        }
//        ChatHandler(handler->GetSession()).PSendSysMessage("重置理财领取状态成功");
//        return true;
//    }
//    static bool AA_chongzhishouchonglingqu(ChatHandler* handler, char const* args)
//    {
//        Player* receiver = handler->getSelectedPlayerOrSelf();
//        if (!receiver || !receiver->IsInWorld()) {
//            return false;
//        }
//        time_t timep;
//        time(&timep);
//        if (receiver) {
//            uint32 accountid = receiver->GetSession()->GetAccountId();
//            AA_Account conf = aaCenter.aa_accounts[accountid];
//            conf.id = accountid;
//            conf.shouchong = 0;
//            conf.isUpdate = true;
//            conf.update_time = timep;
//            aaCenter.aa_accounts[accountid] = conf;
//        }
//        ChatHandler(handler->GetSession()).PSendSysMessage("重置首充领取状态成功");
//        return true;
//    }
//    static bool AA_chongzhiqiandaolingqu(ChatHandler* handler, char const* args)
//    {
//        Player* receiver = handler->getSelectedPlayerOrSelf();
//        if (!receiver || !receiver->IsInWorld()) {
//            return false;
//        }
//        time_t timep;
//        time(&timep);
//        if (receiver) {
//            uint32 accountid = receiver->GetSession()->GetAccountId();
//            AA_Account conf = aaCenter.aa_accounts[accountid];
//            conf.id = accountid;
//            conf.denglu_qiandao = 0;
//            conf.isUpdate = true;
//            conf.update_time = timep;
//            aaCenter.aa_accounts[accountid] = conf;
//        }
//        ChatHandler(handler->GetSession()).PSendSysMessage("重置签到领取状态成功");
//        return true;
//    }
//    static bool AA_youjian(ChatHandler* handler, char const* args)
//    {
//        std::string argstr = args;
//        char const* args1 = argstr.c_str();
//        // format: name "subject text" "mail text" item1[:count1] item2[:count2] ... item12[:count12]
//        Player* receiver = handler->getSelectedPlayerOrSelf();
//        if (!receiver || !receiver->IsInWorld()) {
//            return false;
//        }
//        ObjectGuid receiverGuid = receiver->GetGUID();
//        std::string receiverName = receiver->GetName();
//        char* tail1 = strtok((char*)args1, "");
//        if (!tail1)
//            return false;
//
//        char const* msgSubject = handler->extractQuotedArg(tail1);
//        if (!msgSubject)
//            return false;
//
//        char* tail2 = strtok(nullptr, "");
//        if (!tail2)
//            return false;
//
//        char const* msgText = handler->extractQuotedArg(tail2);
//        if (!msgText)
//            return false;
//
//        // msgSubject, msgText isn't NUL after prev. check
//        std::string subject = msgSubject;
//        std::string text = msgText;
//
//        // extract items
//        typedef std::pair<uint32, uint32> ItemPair;
//        typedef std::list< ItemPair > ItemPairs;
//        ItemPairs items;
//
//        // get all tail string
//        char* tail = strtok(nullptr, "");
//
//        // get from tail next item str
//        while (char* itemStr = strtok(tail, " "))
//        {
//            // and get new tail
//            tail = strtok(nullptr, "");
//
//            // parse item str
//            char const* itemIdStr = strtok(itemStr, ":");
//            char const* itemCountStr = strtok(nullptr, " ");
//
//            uint32 itemId = atoi(itemIdStr);
//            if (!itemId)
//                return false;
//
//            ItemTemplate const* item_proto = sObjectMgr->GetItemTemplate(itemId);
//            if (!item_proto)
//            {
//                handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//
//            uint32 itemCount = itemCountStr ? atoi(itemCountStr) : 1;
//            if (itemCount < 1 || (item_proto->MaxCount > 0 && itemCount > uint32(item_proto->MaxCount)))
//            {
//                handler->PSendSysMessage(LANG_COMMAND_INVALID_ITEM_COUNT, itemCount, itemId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//
//            while (itemCount > item_proto->GetMaxStackSize())
//            {
//                items.push_back(ItemPair(itemId, item_proto->GetMaxStackSize()));
//                itemCount -= item_proto->GetMaxStackSize();
//            }
//
//            items.push_back(ItemPair(itemId, itemCount));
//
//            if (items.size() > MAX_MAIL_ITEMS)
//            {
//                handler->PSendSysMessage(LANG_COMMAND_MAIL_ITEMS_LIMIT, MAX_MAIL_ITEMS);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//        }
//
//        // from console show not existed sender
//        MailSender sender(MAIL_NORMAL, handler->GetSession() ? handler->getSelectedPlayerOrSelf()->GetGUIDLow() : 0, MAIL_STATIONERY_GM);
//
//        // fill mail
//        MailDraft draft(subject, text);
//
//        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
//
//        for (ItemPairs::const_iterator itr = items.begin(); itr != items.end(); ++itr)
//        {
//            if (Item* item = Item::CreateItem(itr->first, itr->second, handler->GetSession() ? handler->getSelectedPlayerOrSelf() : 0))
//            {
//                item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted
//                draft.AddItem(item);
//            }
//        }
//        draft.SendMailTo(trans, MailReceiver(receiver, receiverGuid.GetCounter()), sender);
//        CharacterDatabase.CommitTransaction(trans);
//
//        std::string nameLink = handler->playerLink(receiverName);
//        handler->PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
//        return true;
//    }
//    static bool AA_jiaxue(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//
//        if (!player)
//            return false;
//
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.加血 生物编号 血量");
//            return false;
//        }
//
//        char* s_entry = strtok((char*)args, " ");
//        char* s_health = strtok(NULL, " ");
//
//        if (!s_entry || !s_health)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.加血 生物编号 血量");
//            return false;
//        }
//
//        uint32 entry = atoi(s_entry);
//        uint32 health = atoi(s_health);
//
//        if (Creature* c = player->FindNearestCreature(entry, 1000.0f))
//            c->ModifyHealth(health);
//
//        return true;
//    }
//    static bool AA_jieka(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//
//        if (!target)
//            return true;
//
//        if (!*args)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.解卡 角色名");
//            return false;
//        }
//
//        char* name = strtok((char*)args, " ");
//        std::string currName = target->GetName();
//        if (target->GetName() == name) {
//            //该角色不属于您的账号，请重新输入
//            //无法解卡自己
//            //没有该角色，请重新输入
//            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000无法解卡自己");
//            return false;
//        }
//        else {
//            uint32 currAccountId = 0; //目标玩家
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = \"{}\"", currName);
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    currAccountId = fields[0].GetUInt32();
//                }
//            }
//            if (currAccountId == 0) {
//                return false;
//            }
//            uint32 accountId = 0; //当前角色
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = \"{}\"", name);
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    accountId = fields[0].GetUInt32();
//                }
//            }
//            if (accountId == 0) {
//                aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000没有该角色，请重新输入");
//                return false; //未知错误
//            }
//            if (currAccountId != accountId) {
//                aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000该角色不属于您的账号，请重新输入");
//                return false;
//            }
//        }
//
//        CharacterDatabase.DirectExecute("UPDATE characters SET position_x = {},position_y = {}, position_z = {}, map = {}, instance_id = 0, instance_mode_mask = 0 where name=\"{}\";", target->m_homebindX, target->m_homebindY, target->m_homebindZ, target->m_homebindMapId, currName);
//        aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|r|cffFFFF00解卡成功，角色已经被传送至出生点");
//        return true;
//    }
//    static bool AA_chongzhirirenwu(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->ResetDailyQuestStatus();
//        return true;
//    }
//    static bool AA_chongzhizhourenwu(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->ResetWeeklyQuestStatus();
//        return true;
//    }
//    static bool AA_chongzhiyuerenwu(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        player->ResetMonthlyQuestStatus();
//        return true;
//    }
//    static bool AA_zuhe(ChatHandler* handler, char const* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a6b")) {
//            return false;
//        }
//        Player* me = handler->GetSession()->GetPlayer();
//        if (!me || !me->IsInWorld()) {
//            return false;
//        }
//        if (!args) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.组合 *.命令");
//            return false;
//        }
//        std::string argstr = std::string(args);
//        aaCenter.AA_StringReplaceFirst(argstr, "*", "");
//        //.组合*.xx*.xx*.xx<$需求@1><$队伍><$公会@AA>
//        //1、取命令
//        std::vector<std::string> gms; gms.clear();
//        aaCenter.AA_StringToVectorString(std::string(argstr), gms, "*");
//        int32 count = gms.size();
//        for (int32 i = 0; i < count; i++) {
//            std::string gm = AA_SafeStringAtIndex(gms, i);
//            if (gm != "") {
//                std::set<Player*> players; players.clear();
//                players = aaCenter.AA_GetPlayerRange(me, gm);
//                int need = 0;
//                if (gm.find("<$需求@") != std::string::npos) {
//                    std::string prestr = "<$需求@";
//                    std::string nums = aaCenter.AA_StringGet(gm, prestr, ">");
//                    if (nums != "") {
//                        need = atoi(nums.c_str());
//                    }
//                }
//                for (Player* p : players) {
//                    if (need > 0) {
//                        if (aaCenter.M_CanNeed(p, need)) {
//                        }
//                        else {
//                            continue;
//                        }
//                    }
//                    std::string gmstr = gm;
//                    if (gm.find("<$") != std::string::npos) {
//                        gmstr = "." + aaCenter.AA_StringGet(gm, ".", "<");
//                    }
//                    bool isOk = aaCenter.AA_DoCommand(p, gmstr.c_str());
//                    if (isOk && need > 0) {
//                        aaCenter.M_Need(p, need);
//                    }
//                }
//            }
//        }
//        return true;
//    }
//    static bool AA_suiji(ChatHandler* handler, char const* args)
//    {
//        if (!aaCenter.AA_VerifyCode("a6b")) {
//            return false;
//        }
//        Player* me = handler->GetSession()->GetPlayer();
//        if (!me || !me->IsInWorld()) {
//            return false;
//        }
//        if (!args) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.随机 *.命令");
//            return false;
//        }
//        std::string argstr = std::string(args);
//        aaCenter.AA_StringReplaceFirst(argstr, "*", "");
//        //.组合*.xx*.xx*.xx<$需求@1><$队伍><$公会@AA>
//        //1、取命令
//        std::vector<std::string> gms; gms.clear();
//        aaCenter.AA_StringToVectorString(std::string(argstr), gms, "*");
//        int32 count = gms.size();
//        int32 randomIndex = rand() % count;
//        std::string gm = AA_SafeStringAtIndex(gms, randomIndex);
//        if (gm != "") {
//            std::set<Player*> players; players.clear();
//            players = aaCenter.AA_GetPlayerRange(me, gm);
//            int need = 0;
//            if (gm.find("<$需求@") != std::string::npos) {
//                std::string prestr = "<$需求@";
//                std::string nums = aaCenter.AA_StringGet(gm, prestr, ">");
//                if (nums != "") {
//                    need = atoi(nums.c_str());
//                }
//            }
//            for (Player* p : players) {
//                if (need > 0) {
//                    if (aaCenter.M_CanNeed(p, need)) {
//                    }
//                    else {
//                        continue;
//                    }
//                }
//                std::string gmstr = gm;
//                if (gm.find("<$") != std::string::npos) {
//                    gmstr = "." + aaCenter.AA_StringGet(gm, ".", "<");
//                }
//                bool isOk = aaCenter.AA_DoCommand(p, gmstr.c_str());
//                if (isOk && need > 0) {
//                    aaCenter.M_Need(p, need);
//                }
//            }
//        }
//        return true;
//    }
//    static bool AA_lingqujifen(ChatHandler* handler, char const* /*args*/)
//    {
//        Player* me = handler->getSelectedPlayerOrSelf();
//        if (!me || !me->IsInWorld()) {
//            return false;
//        }
//        uint32 accountid = me->GetSession()->GetAccountId();
//        AA_Account conf = aaCenter.aa_accounts[accountid];
//        QueryResult result = LoginDatabase.PQuery("SELECT jifen from _aa_account where id = {}", accountid);
//        int32 jifen_cz = conf.jifen_cz;
//        if (result) {
//            Field* fields = result->Fetch();
//            uint32 jifen = fields[0].GetUInt32();
//            if (jifen > 0) {
//                jifen_cz += jifen;
//            }
//        }
//        if (jifen_cz > 0) {
//            conf.jifen += jifen_cz;
//            conf.jifen_all += jifen_cz;
//            conf.jifen_day += jifen_cz;
//            if (conf.shouchong_day == 0) {
//                conf.shouchong_day += jifen_cz;
//            }
//            conf.jifen_cz = 0;
//            time_t timep;
//            time(&timep);
//            conf.isUpdate = true;
//            conf.update_time = timep;
//            aaCenter.aa_accounts[accountid] = conf;
//            LoginDatabase.DirectExecute("UPDATE _aa_account SET 当前积分 = {},jifen = 0,累计充值积分={},每日累充积分={},每日首充积分={},更新时间=0 WHERE id = {};", conf.jifen, conf.jifen_all, conf.jifen_day, conf.shouchong_day, conf.id);
//            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[64].value2 + "增加：" + std::to_string(jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), me);
//            std::string jfstr = "|cff00FFFF[系统提示]|r|cffFFFF00恭喜玩家【" + aaCenter.AA_GetPlayerNameLink(me) + "】获得充值奖励，" + aaCenter.aa_world_confs[64].value2 + "增加【" + std::to_string(jifen_cz) + "】！";
//            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
//            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
//            aaCenter.AA_SendMessage(nullptr, 1, jfstr.c_str());
//            aaCenter.M_SendAA_Conf(me, "1004");
//            aaCenter.M_SendAA_Conf(me, "1005");
//        }
//        return true;
//    }
//
//    static bool AA_zhuanzhi(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        uint8 newclass = uint8(std::atoi(args));
//        //检查
//        if (!player || !player->IsInWorld() || !player->IsAlive() || player->IsInCombat() || player->GetClass() == newclass || newclass <= 0 || newclass >= MAX_CLASSES)
//            return false;
//
//        std::string newclasstext = aaCenter.GetPlayerClass(newclass);
//        // xinef: learn default race/class spells
//        PlayerInfo const* sinfo = sObjectMgr->GetPlayerInfo(player->GetRace(), newclass);
//        if (!sinfo) {
//            std::string message = "|cff00FFFF[系统提示]|cffFF0000你的种族不适合[" + newclasstext + "]职业";
//            ChatHandler(player->GetSession()).PSendSysMessage("{}", message.c_str());
//            aaCenter.AA_SendMessage(player, 1, message.c_str());
//            return false;
//        }
//        //移除宠物 与相关的东西
//        if (Pet* pet = player->GetPet())
//        {
//            uint32 PGuid = pet->GetCharmInfo()->GetPetNumber();
//            player->RemovePet(pet, PET_SAVE_NOT_IN_SLOT);
//            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
//            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME);
//            stmt->SetData(0, PGuid);
//            trans->Append(stmt);
//            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
//            stmt->SetData(0, PGuid);
//            trans->Append(stmt);
//            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELLS);
//            stmt->SetData(0, PGuid);
//            trans->Append(stmt);
//            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_COOLDOWNS);
//            stmt->SetData(0, PGuid);
//            trans->Append(stmt);
//            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_OWNER);
//            stmt->SetData(0, player->GetGUIDLow());
//            trans->Append(stmt);
//            CharacterDatabase.CommitTransaction(trans);
//        }
//        //移除雕文
//        for (uint32 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
//        {
//            if (slot >= MAX_GLYPH_SLOT_INDEX)
//                continue;
//
//            if (uint32 glyph = player->GetGlyph(slot))
//            {
//                if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
//                {
//                    player->RemoveAurasDueToSpell(gp->SpellId);
//                    player->SetGlyph(slot, 0, false);
//                    player->SendTalentsInfoData(false);
//                }
//            }
//        }
//        //遗忘技能
//        if (player->HasAtLoginFlag(AT_LOGIN_RESET_SPELLS))
//            player->RemoveAtLoginFlag(AT_LOGIN_RESET_SPELLS, true);
//
//        PlayerSpellMap spellMap = player->GetSpellMap();
//
//        for (PlayerSpellMap::const_iterator iter = spellMap.begin(); iter != spellMap.end(); ++iter)
//        {
//            AA_Zhuanzhi_Spell conf = aaCenter.aa_zhuanzhi_spells[iter->first];
//            if (conf.spellid > 0 && conf.spellid == iter->first) {
//                continue;
//            }
//            player->removeSpell(iter->first, SPEC_MASK_ALL, false);
//        }
//
//        for (uint32 id = 0; id < sSkillLineStore.GetNumRows(); id++)
//        {
//            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(id);
//            if (!pSkill)
//                continue;
//
//            if (pSkill->categoryId != SKILL_CATEGORY_CLASS)
//                continue;
//
//            player->SetSkill(id, 0, 0, 0);
//        }
//
//        //重置天赋
//        player->resetTalents();
//        player->InitTalentForLevel();
//        player->SendTalentsInfoData(false);
//
//        //执行转职
//        player->SetByteValue(UNIT_FIELD_BYTES_0, 1, newclass);
//
//        //更新角色新职业信息
//        //        sWorld->UpdateGlobalPlayerData(player->GetGUIDLow(), PLAYER_UPDATE_DATA_CLASS, player->GetName(), player->GetLevel(), player->GetGender(), player->GetRace(), newclass);
//
//        //强制把身上不符合新职业的武器装备卸下 有位置就放 没位置自动发到邮箱里
//        for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
//        {
//            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
//            {
//                if (!pItem->IsInWorld()) {
//                    continue;
//                }
//                ItemPosCountVec dest;
//                uint8 Msg = player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, pItem, false);
//                if (Msg == EQUIP_ERR_OK)
//                {
//                    player->RemoveItem(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
//                    player->StoreItem(dest, pItem, true);
//                    //更新泰坦之握
//                    player->UpdateTitansGrip();
//                }
//                else
//                {
//                    player->MoveItemFromInventory(INVENTORY_SLOT_BAG_0, pItem->GetSlot(), true);
//                    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
//                    pItem->DeleteFromInventoryDB(trans);
//                    pItem->SaveToDB(trans);
//                    MailDraft("转职", "这些装备不支持新职业").AddItem(pItem).SendMailTo(trans, player, MailSender(player, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_COPIED);
//                    CharacterDatabase.CommitTransaction(trans);
//                }
//            }
//        }
//
//        //保存角色信息
//        player->SaveToDB(false, false);
//        //重新学习默认技能
//        player->LearnDefaultSkills();
//        player->LearnCustomSpells();
//        player->learnQuestRewardedSpells();
//        //重置属性获取对应职业的Power(能量条/怒气条之类的)
//        player->InitStatsForLevel(true);
//        //如果新职业是DK就载入符文冷却
//        if (newclass == CLASS_DEATH_KNIGHT) {
//            player->InitRunes();
//        }
//        //更新角色属性
//        player->SetCanModifyStats(true);
//        player->UpdateAllStats();
//
//        //CharacterDatabase.DirectExecute("update characters set class={} where guid ={}", targetClass, player->GetGUIDLow()); //更新转职后的职业
//        CharacterDatabase.DirectExecute("delete from character_glyphs where guid ={}", player->GetGUIDLow()); // 删除雕文
//        CharacterDatabase.DirectExecute("delete from character_pet where owner ={}", player->GetGUIDLow());//删除宠物
//
//        std::string gm = ".组合 *.cache delete<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        gm = ".组合 *.cache refresh<$自身>";
//        aaCenter.AA_DoCommand(player, gm.c_str());
//        //Customize(GetGUID(), GetGender(), 1, 1, 1, 1, 1);
////        player->GetSession()->KickPlayer("GlobalMethods::Kick Kick the player");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");
//        aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFFFF00转职成功，请小退!");
//
//        return true;
//    }
//
//
//    static bool AA_jifen(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            uint32 accountid = target->GetSession()->GetAccountId();
//            int32 jifen_cz = int32(std::atoi(args));
//            if (jifen_cz >= 0) {
//                time_t timep;
//                time(&timep);
//                AA_Account conf = aaCenter.aa_accounts[accountid];
//                int32 jfcz = (int32)conf.jifen_cz + jifen_cz;
//                conf.jifen += jfcz;
//                conf.jifen_all += jfcz;
//                conf.jifen_day += jfcz;
//                if (conf.shouchong_day == 0) {
//                    conf.shouchong_day += jfcz;
//                }
//                conf.jifen_cz = 0;
//                conf.update_time = timep;
//                conf.isUpdate = true;
//                aaCenter.aa_accounts[accountid] = conf;
//                LoginDatabase.DirectExecute("UPDATE _aa_account SET 当前积分 = {},jifen = 0,累计充值积分={},每日累充积分={},每日首充积分={},更新时间=0 WHERE id = {};", conf.jifen, conf.jifen_all, conf.jifen_day, conf.shouchong_day, conf.id);
//                std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[64].value2 + "增加：" + std::to_string(jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
//                sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//            }
//            else if (jifen_cz < 0) {
//                int32 val = aaCenter.aa_accounts[accountid].jifen;
//                val = val += jifen_cz; val = val < 0 ? 0 : val;
//                aaCenter.aa_accounts[accountid].jifen = val;
//                LoginDatabase.DirectExecute("UPDATE _aa_account SET 当前积分 = {}, 更新时间=0 WHERE id = {};", val, accountid);
//                std::string msg = "|cff00FFFF[系统提示]|cffFF0000你的" + aaCenter.aa_world_confs[64].value2 + "减少：" + std::to_string(-jifen_cz) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].jifen);
//                sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//            }
//        }
//        return true;
//    }
//    static bool AA_mobi(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            uint32 accountid = target->GetSession()->GetAccountId();
//            int32 count = int32(std::atoi(args));
//            int32 val = aaCenter.aa_accounts[accountid].mobi;
//            val = val += count; val = val < 0 ? 0 : val;
//            time_t timep;
//            time(&timep);
//            aaCenter.aa_accounts[accountid].update_time = timep;
//            aaCenter.aa_accounts[accountid].mobi = val;
//            aaCenter.aa_accounts[accountid].isUpdate = true;
//            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[63].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].mobi);
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_paodian(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            uint32 accountid = target->GetSession()->GetAccountId();
//            int32 count = int32(std::atoi(args));
//            int32 val = aaCenter.aa_accounts[accountid].paodian;
//            val = val += count; val = val < 0 ? 0 : val;
//            time_t timep;
//            time(&timep);
//            aaCenter.aa_accounts[accountid].update_time = timep;
//            aaCenter.aa_accounts[accountid].paodian = val;
//            aaCenter.aa_accounts[accountid].isUpdate = true;
//            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[62].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].paodian);
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_zhanchangjifen(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            uint32 accountid = target->GetSession()->GetAccountId();
//            int32 count = int32(std::atoi(args));
//            int32 val = aaCenter.aa_accounts[accountid].battlecore;
//            val = val += count; val = val < 0 ? 0 : val;
//            time_t timep;
//            time(&timep);
//            aaCenter.aa_accounts[accountid].battlecore = val;
//            aaCenter.aa_accounts[accountid].update_time = timep;
//            aaCenter.aa_accounts[accountid].isUpdate = true;
//            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00你的" + aaCenter.aa_world_confs[65].value2 + "增加：" + std::to_string(count) + "，剩余：" + std::to_string(aaCenter.aa_accounts[accountid].battlecore);
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_huiyuandengji(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        if (target) {
//            uint32 accountid = target->GetSession()->GetAccountId();
//            int32 count = int32(std::atoi(args));
//            uint32 level = aaCenter.aa_accounts[accountid].vip;
//            level += count;
//            level = level < 1 ? 1 : level;
//            AA_Vip_Conf conf = aaCenter.aa_vip_confs[level];
//            std::string msg = "";
//            if (conf.level == 0) {
//                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大会员等级";
//            }
//            else {
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_accounts[accountid].update_time = timep;
//                aaCenter.aa_accounts[accountid].vip = level;
//                aaCenter.aa_accounts[accountid].isUpdate = true;
//                msg = "|cff00FFFF[系统提示]|cffFFFF00你的会员等级提升：" + std::to_string(count) + "，当前等级：" + std::to_string(level) + "，请小退重新登录游戏！";
//
//                //更新客户端玩家信息
//                ObjectGuid::LowType guidlow = target->GetGUIDLow();
//                uint32 accountid = target->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
//                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
//                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
//                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
//                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
//            }
//            aaCenter.AA_SendMessage(target, 0, msg.c_str());
//            aaCenter.AA_SendMessage(target, 0, msg.c_str());
//            aaCenter.AA_SendMessage(target, 0, msg.c_str());
//        }
//        return true;
//    }
//    static bool AA_junxiandengji(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (target) {
//            ObjectGuid::LowType guidlow = target->GetGUIDLow();
//            int32 count = int32(std::atoi(args));
//            int32 level = aaCenter.aa_characters_junxians[guidlow].level;
//            level += count;
//            level = level < 1 ? 1 : level;
//            AA_Junxian_Conf conf = aaCenter.aa_junxian_confs[level];
//            std::string msg = "";
//            if (conf.level == 0) {
//                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大军衔等级";
//            }
//            else {
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_characters_junxians[guidlow].update_time = timep;
//                aaCenter.aa_characters_junxians[guidlow].level = level;
//                aaCenter.aa_characters_junxians[guidlow].isUpdate = true;
//                msg = "|cff00FFFF[系统提示]|cffFFFF00你的军衔等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);
//
//                //更新客户端玩家信息
//                ObjectGuid::LowType guidlow = target->GetGUIDLow();
//                uint32 accountid = target->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
//                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
//                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
//                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
//                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
//            }
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_douqidengji(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (target) {
//            ObjectGuid::LowType guidlow = target->GetGUIDLow();
//            int32 count = int32(std::atoi(args));
//            int32 level = aaCenter.aa_characters_douqis[guidlow].level;
//            level += count;
//            level = level < 1 ? 1 : level;
//            AA_Douqi_Conf conf = aaCenter.aa_douqi_confs[level];
//            std::string msg = "";
//            if (conf.level == 0) {
//                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大斗气等级";
//            }
//            else {
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_characters_douqis[guidlow].update_time = timep;
//                aaCenter.aa_characters_douqis[guidlow].level = level;
//                aaCenter.aa_characters_douqis[guidlow].isUpdate = true;
//                msg = "|cff00FFFF[系统提示]|cffFFFF00你的斗气等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);
//
//                //更新客户端玩家信息
//                ObjectGuid::LowType guidlow = target->GetGUIDLow();
//                uint32 accountid = target->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
//                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
//                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
//                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
//                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
//            }
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_dianfengdengji(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (target) {
//            ObjectGuid::LowType guidlow = target->GetGUIDLow();
//            int32 count = int32(std::atoi(args));
//            int32 level = aaCenter.aa_characters_dianfengs[guidlow].level;
//            level += count;
//            level = level < 1 ? 1 : level;
//            AA_Dianfeng_Conf conf = aaCenter.aa_dianfeng_confs[level];
//            std::string msg = "";
//            if (conf.level == 0) {
//                msg = "|cff00FFFF[系统提示]|cffFF0000你已达到最大巅峰等级";
//            }
//            else {
//                time_t timep;
//                time(&timep);
//                aaCenter.aa_characters_dianfengs[guidlow].update_time = timep;
//                aaCenter.aa_characters_dianfengs[guidlow].level = level;
//                aaCenter.aa_characters_dianfengs[guidlow].isUpdate = true;
//                msg = "|cff00FFFF[系统提示]|cffFFFF00你的巅峰等级增加：" + std::to_string(count) + "，当前等级：" + std::to_string(level);
//
//                //更新客户端玩家信息
//                ObjectGuid::LowType guidlow = target->GetGUIDLow();
//                uint32 accountid = target->GetSession()->GetAccountId();
//                AA_Account a_conf = aaCenter.aa_accounts[accountid];
//                AA_Characters_Dianfeng df_conf = aaCenter.aa_characters_dianfengs[guidlow];
//                AA_Characters_Douqi dq_conf = aaCenter.aa_characters_douqis[guidlow];
//                AA_Characters_Junxian jx_conf = aaCenter.aa_characters_junxians[guidlow];
//                std::string result = "{" + std::to_string(df_conf.level) + "," + std::to_string(dq_conf.level) + "," + std::to_string(jx_conf.level) + "," + std::to_string(a_conf.vip) + "}";
//                aaCenter.M_SendClientAddonData(const_cast<Player*>(target), "10012", result);
//            }
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_jiazaitese(ChatHandler* handler, char const* /*args*/)
//    {
//        aaCenter.LoadAAData_World();
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (target) {
//            std::string msg = "|cff00FFFF[系统提示]|cffFFFF00特色数据库已全部重新加载。";
//            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), target);
//        }
//        return true;
//    }
//    static bool AA_caijizuobiao(ChatHandler* handler, char const* args)
//    {
//        Unit* target = handler->getSelectedUnit();
//        if (target) {
//            char* arg1 = strtok((char*)args, " ");
//            char* arg2 = strtok(nullptr, " ");
//            std::string arg1str = "";
//            int32 zu = 1;
//            if (arg1) {
//                arg1str = arg1;
//            }
//            if (arg2) {
//                zu = int32(std::atoi(arg2));
//            }
//            WorldDatabase.DirectExecute("INSERT INTO __采集_坐标 (注释,组,name,map,zone,area,position_x,position_y,position_z,orientation,instanceId) VALUES ('{}',{},'{}',{},{},{},{},{},{},{},{})", arg1str, zu, target->GetMap()->GetMapName(), target->GetMapId(), target->GetZoneId(), target->GetAreaId(), target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), target->GetInstanceId());
//            QueryResult result = WorldDatabase.Query("SELECT id from __采集_坐标");
//            int32 rid = 0;
//            if (result) {
//                do {
//                    Field* fields = result->Fetch();
//                    rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
//                } while (result->NextRow());
//            }
//            AA_Caiji_Zuobiao conf;
//            conf.text = arg1str;
//            conf.id = rid + 1;
//            conf.zu = zu;
//            conf.chance = 100;
//            conf.name = target->GetMap()->GetMapName();
//            conf.map = target->GetMapId();
//            conf.zone = target->GetZoneId();
//            conf.area = target->GetAreaId();
//            conf.position_x = target->GetPositionX();
//            conf.position_y = target->GetPositionY();
//            conf.position_z = target->GetPositionZ();
//            conf.orientation = target->GetOrientation();
//            conf.instanceId = target->GetInstanceId();
//            aaCenter.aa_caiji_zuobiaos[conf.id] = conf;
//            aaCenter.aa_caiji_zuobiao_zus[conf.zu].push_back(conf.id);
//            std::string rs = "|cff00FFFF[采集坐标]|cffFFFF00模板id:" + std::to_string(conf.id) + " 地图:" + target->GetMap()->GetMapName() + " 地图id:" + std::to_string(target->GetMapId()) + " zoneid:" + std::to_string(target->GetZoneId()) + " areaid:" + std::to_string(target->GetAreaId()) + " x:" + std::to_string(target->GetPositionX()) + " y:" + std::to_string(target->GetPositionY()) + " z:" + std::to_string(target->GetPositionZ()) + " o:" + std::to_string(target->GetOrientation());
//            aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
//        }
//        return true;
//    }
//    static bool AA_caijishengwu(ChatHandler* handler, char const* args)
//    {
//        Creature* target = handler->getSelectedCreature();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        char* arg2 = strtok(nullptr, " ");
//        std::string arg1str = "";
//        int32 zu = 1;
//        if (arg1) {
//            arg1str = arg1;
//        }
//        if (arg2) {
//            zu = int32(std::atoi(arg2));
//        }
//        //aatodo target为生物，可能有错
//        AA_Map_Player_Conf map_conf = aaCenter.AA_GetAA_Map_Player_Conf(target);
//        WorldDatabase.DirectExecute("INSERT INTO __采集_生物 (注释,组,name,subname,entry,faction,displayid,map,zone,area,秘境难度,position_x,position_y,position_z,orientation,instanceId) VALUES ('{}',{},'{}','{}',{},{},{},{},{},{},{},{},{},{},{},{})", arg1str, zu, target->GetName(), target->GetCreatureTemplate()->SubName, target->GetEntry(), target->GetFaction(), target->GetDisplayId(), target->GetMapId(), target->GetZoneId(), target->GetAreaId(), map_conf.nanduid, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), target->GetInstanceId());
//        QueryResult result = WorldDatabase.Query("SELECT id from __采集_生物");
//        int32 rid = 0;
//        if (result) {
//            do {
//                Field* fields = result->Fetch();
//                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
//            } while (result->NextRow());
//        }
//        AA_Caiji_Creature conf;
//        conf.text = arg1str;
//        conf.id = rid + 1;
//        conf.zu = zu;
//        conf.chance = 100;
//        conf.name = target->GetCreatureTemplate()->Name;
//        conf.subname = target->GetCreatureTemplate()->SubName;
//        conf.entry = target->GetEntry();
//        conf.faction = target->GetFaction();
//        conf.displayid = target->GetDisplayId();
//        conf.map = target->GetMapId();
//        conf.zone = target->GetZoneId();
//        conf.area = target->GetAreaId();
//        conf.nandu = map_conf.nanduid;
//        conf.position_x = target->GetPositionX();
//        conf.position_y = target->GetPositionY();
//        conf.position_z = target->GetPositionZ();
//        conf.orientation = target->GetOrientation();
//        conf.instanceId = target->GetInstanceId();
//        aaCenter.aa_caiji_creatures[conf.id] = conf;
//        aaCenter.aa_caiji_creature_zus[conf.zu].push_back(conf.id);
//        std::string rs = "|cff00FFFF[采集生物]|cffFFFF00模板id:" + std::to_string(conf.id) + " 生物名称:" + target->GetName();
//        aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
//        return true;
//    }
//    static bool AA_caijiwanjia(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        char* arg2 = strtok(nullptr, " ");
//        std::string arg1str = "";
//        int32 zu = 1;
//        if (arg1) {
//            arg1str = arg1;
//        }
//        if (arg2) {
//            zu = int32(std::atoi(arg2));
//        }
//        WorldDatabase.DirectExecute("INSERT INTO __采集_玩家 (注释,账号id,角色id,组,name,ip) VALUES ('{}',{},{},{},'{}','{}')", arg1str, target->GetSession()->GetAccountId(), target->GetGUIDLow(), zu, target->GetName(), target->GetSession()->GetRemoteAddress());
//        QueryResult result = WorldDatabase.Query("SELECT id from __采集_玩家");
//        int32 rid = 0;
//        if (result) {
//            do {
//                Field* fields = result->Fetch();
//                rid = fields[0].GetInt32() > rid ? fields[0].GetInt32() : rid;
//            } while (result->NextRow());
//        }
//        AA_Caiji_Player conf;
//        conf.text = arg1str;
//        conf.id = rid + 1;
//        conf.account = target->GetSession()->GetAccountId();
//        conf.guid = target->GetGUIDLow();
//        conf.zu = zu;
//        conf.chance = 100;
//        conf.name = target->GetName();
//        conf.ip = target->GetSession()->GetRemoteAddress();
//        aaCenter.aa_caiji_players[conf.id] = conf;
//        std::string rs = "|cff00FFFF[采集玩家]|cffFFFF00模板id:" + std::to_string(conf.id) + " 玩家名称:" + target->GetName();
//        aaCenter.AA_SendMessage(handler->GetSession()->GetPlayer(), 0, rs.c_str());
//        return true;
//    }
//    static bool AA_zhanshixunlianshi(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//
//        ObjectGuid guid = aaCenter.aa_vendor_guid[player->GetGUID()];
//        Creature* unit = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, guid);
//        
//        if (!unit || !unit->IsInWorld()) {
//            return false;
//        }
//
//        if (!*args)
//            return false;
//
//        /*Tokenizer entries(std::string(args), ' ');
//        Tokenizer::const_iterator itr = entries.begin();
//        uint32 entry = uint32(atoi(*itr));*/
//        std::vector<std::string_view> entries = Acore::Tokenize(args, ' ', false);
//        auto itr = entries.begin();
//        //std::string_view itr = entries[0];
//        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
//        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));
//
//        if (entry == 0) {
//            return false;
//        }
//
//        // remove fake death
//        if (player->HasUnitState(UNIT_STATE_DIED))
//            player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
//
//        CreatureTemplate const* ci = unit->GetCreatureTemplate();
//
//        if (!ci)
//        {
//#if defined(ENABLE_EXTRAS) && defined(ENABLE_EXTRA_LOGS)
//            sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: SendTrainerList - (GUID: {}) NO CREATUREINFO!", GUID_LOPART(guid));
//#endif
//            return false;
//        }
//
//        TrainerSpellData const* trainer_spells = sObjectMgr->GetNpcTrainerSpells(entry);
//        if (!trainer_spells)
//        {
//#if defined(ENABLE_EXTRAS) && defined(ENABLE_EXTRA_LOGS)
//            sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: SendTrainerList - Training spells not found for creature (GUID: {} Entry: {})", GUID_LOPART(guid), unit->GetEntry());
//#endif
//            return false;
//        }
//
//        WorldPacket data(SMSG_TRAINER_LIST, 8 + 4 + 4 + trainer_spells->spellList.size() * 38 + 1);
//        data << guid;
//        data << uint32(trainer_spells->trainerType);
//
//        size_t count_pos = data.wpos();
//        data << uint32(trainer_spells->spellList.size());
//
//        // reputation discount
//        float fDiscountMod = player->GetReputationPriceDiscount(unit);
//        bool can_learn_primary_prof = player->GetFreePrimaryProfessionPoints() > 0;
//
//        uint32 count = 0;
//        for (TrainerSpellMap::const_iterator itr = trainer_spells->spellList.begin(); itr != trainer_spells->spellList.end(); ++itr)
//        {
//            TrainerSpell const* tSpell = &itr->second;
//
//            bool valid = true;
//            bool primary_prof_first_rank = false;
//            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
//            {
//                if (!tSpell->learnedSpell[i])
//                    continue;
//                if (!player->IsSpellFitByClassAndRace(tSpell->learnedSpell[i]))
//                {
//                    valid = false;
//                    break;
//                }
//                SpellInfo const* learnedSpellInfo = sSpellMgr->GetSpellInfo(tSpell->learnedSpell[i]);
//                if (learnedSpellInfo && learnedSpellInfo->IsPrimaryProfessionFirstRank())
//                    primary_prof_first_rank = true;
//            }
//            if (!valid)
//                continue;
//
//            TrainerSpellState state = player->GetTrainerSpellState(tSpell);
//
//            data << uint32(tSpell->spell);                      // learned spell (or cast-spell in profession case)
//            data << uint8(state == TRAINER_SPELL_GREEN_DISABLED ? TRAINER_SPELL_GREEN : state);
//            data << uint32(floor(tSpell->spellCost * fDiscountMod));
//
//            data << uint32(primary_prof_first_rank && can_learn_primary_prof ? 1 : 0);
//            // primary prof. learn confirmation dialog
//            data << uint32(primary_prof_first_rank ? 1 : 0);    // must be equal prev. field to have learn button in enabled state
//            data << uint8(tSpell->reqLevel);
//            data << uint32(tSpell->reqSkill);
//            data << uint32(tSpell->reqSkillValue);
//            //prev + req or req + 0
//            uint8 maxReq = 0;
//            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
//            {
//                if (!tSpell->learnedSpell[i])
//                    continue;
//                if (uint32 prevSpellId = sSpellMgr->GetPrevSpellInChain(tSpell->learnedSpell[i]))
//                {
//                    data << uint32(prevSpellId);
//                    ++maxReq;
//                }
//                if (maxReq == 3)
//                    break;
//                SpellsRequiringSpellMapBounds spellsRequired = sSpellMgr->GetSpellsRequiredForSpellBounds(tSpell->learnedSpell[i]);
//                for (SpellsRequiringSpellMap::const_iterator itr2 = spellsRequired.first; itr2 != spellsRequired.second && maxReq < 3; ++itr2)
//                {
//                    data << uint32(itr2->second);
//                    ++maxReq;
//                }
//                if (maxReq == 3)
//                    break;
//            }
//            while (maxReq < 3)
//            {
//                data << uint32(0);
//                ++maxReq;
//            }
//
//            ++count;
//        }
//
//        data << "";
//
//        data.put<uint32>(count_pos, count);
//        player->GetSession()->SendPacket(&data);
//
//        unit->aa_vendor_entry = entry;
//        return true;
//    }
//
//    static bool AA_suishenshangren(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//
//        Creature* vendor = nullptr;
//
//        Unit* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, player->GetCritterGUID());
//        if (!pet || pet->GetEntry() != 36911 || !pet->IsInWorld())
//        {//召唤
//            player->CastSpell(player, 69541);
//            pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, player->GetCritterGUID());
//        }
//        if (pet && pet->GetEntry() == 36911 && pet->IsInWorld()) {
//            if (Creature* c = pet->ToCreature()) {
//                vendor = c;
//            }
//        }
//        if (vendor) {
//            player->vendorSummonTime = aaCenter.aa_world_confs[59].value1 > 0 ? aaCenter.aa_world_confs[59].value1 * 1000 : 60000;
//            if (aaCenter.aa_world_confs[59].value2 != "" && aaCenter.aa_world_confs[59].value2 != "0") {
//                uint32 displayId = aaCenter.AA_StringUint32(aaCenter.aa_world_confs[59].value2);
//                if (sCreatureDisplayInfoStore.LookupEntry(displayId))
//                {
//                    vendor->SetDisplayId(displayId);
//                    vendor->SetNativeDisplayId(displayId);
//                }
//            }
//        }
//
//        if (!vendor || !vendor->IsInWorld()) {
//            return false;
//        }
//
//        if (!*args)
//            return false;
//
//        /*Tokenizer entries(std::string(args), ' ');
//        Tokenizer::const_iterator itr = entries.begin();
//        uint32 entry = uint32(atoi(*itr));*/
//        std::vector<std::string_view> entries = Acore::Tokenize(args, ' ', false);
//        auto itr = entries.begin();
//        //std::string_view itr = entries[0];
//        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
//        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));
//
//        if (entry == 0) {
//            return false;
//        }
//
//        // remove fake death
//        if (player->HasUnitState(UNIT_STATE_DIED))
//            player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
//
//        // Stop the npc if moving
//        if (vendor->HasUnitState(UNIT_STATE_MOVING))
//            vendor->StopMoving();
//
//        VendorItemData const* items = sObjectMgr->GetNpcVendorItemList(entry);
//        if (!items)
//        {
//            WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + 1);
//            data << pet->GetGUID();
//            data << uint8(0);                                   // count == 0, next will be error code
//            data << uint8(0);                                   // "Vendor has no inventory"
//            player->GetSession()->SendPacket(&data);
//            return false;
//        }
//
//        uint8 itemCount = items->GetItemCount();
//        uint8 count = 0;
//
//        WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + itemCount * 8 * 4);
//        data << pet->GetGUID();
//
//        size_t countPos = data.wpos();
//        data << uint8(count);
//
//        float discountMod = player->GetReputationPriceDiscount(vendor);
//
//        for (uint8 slot = 0; slot < itemCount; ++slot)
//        {
//            if (VendorItem const* item = items->GetItem(slot))
//            {
//                if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(item->item))
//                {
//                    // reputation discount
//                    int32 price = item->IsGoldRequired(itemTemplate) ? uint32(floor(itemTemplate->BuyPrice * discountMod)) : 0;
//
//                    data << uint32(slot + 1);       // client expects counting to start at 1
//                    data << uint32(item->item);
//                    data << uint32(itemTemplate->DisplayInfoID);
//                    data << int32(1);
//                    data << uint32(price);
//                    data << uint32(itemTemplate->MaxDurability);
//                    data << uint32(itemTemplate->BuyCount);
//                    data << uint32(item->ExtendedCost);
//
//                    if (++count >= MAX_VENDOR_ITEMS)
//                        break;
//                }
//            }
//        }
//
//        if (count == 0)
//        {
//            data << uint8(0);
//            player->GetSession()->SendPacket(&data);
//            return false;
//        }
//
//        data.put<uint8>(countPos, count);
//        player->GetSession()->SendPacket(&data);
//
//        aaCenter.aa_vendor_guid[player->GetGUID()] = pet->GetGUID();
//        pet->aa_vendor_entry = entry;
//        return true;
//    };
//    static bool AA_xianshishangren(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        ObjectGuid vendorGuid = aaCenter.aa_vendor_guid[player->GetGUID()];
//        Creature* vendor = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, vendorGuid);
//
//        if (!vendor || !vendor->IsInWorld()) {
//            return false;
//        }
//
//        if (!*args)
//            return false;
//
//        /*Tokenizer entries(std::string(args), ' ');
//        Tokenizer::const_iterator itr = entries.begin();
//        uint32 entry = uint32(atoi(*itr));*/
//        std::vector<std::string_view> entries = Acore::Tokenize(args, ' ', false);
//        auto itr = entries.begin();
//        //std::string_view itr = entries[0];
//        //Optional<uint32> entry = Acore::StringTo<uint32>(itr);
//        uint32 entry = uint32(atoi(static_cast<std::string>(*itr).c_str()));
//
//        if (entry == 0) {
//            return false;
//        }
//
//        // remove fake death
//        if (player->HasUnitState(UNIT_STATE_DIED))
//            player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
//
//        // Stop the npc if moving
//        if (vendor->HasUnitState(UNIT_STATE_MOVING))
//            vendor->StopMoving();
//
//        VendorItemData const* items = sObjectMgr->GetNpcVendorItemList(entry);
//        if (!items)
//        {
//            WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + 1);
//            data << vendorGuid;
//            data << uint8(0);                                   // count == 0, next will be error code
//            data << uint8(0);                                   // "Vendor has no inventory"
//            player->GetSession()->SendPacket(&data);
//            return false;
//        }
//
//        uint8 itemCount = items->GetItemCount();
//        uint8 count = 0;
//
//        WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + itemCount * 8 * 4);
//        data << vendorGuid;
//
//        size_t countPos = data.wpos();
//        data << uint8(count);
//
//        float discountMod = player->GetReputationPriceDiscount(vendor);
//
//        for (uint8 slot = 0; slot < itemCount; ++slot)
//        {
//            if (VendorItem const* item = items->GetItem(slot))
//            {
//                if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(item->item))
//                {
//                    // reputation discount
//                    int32 price = item->IsGoldRequired(itemTemplate) ? uint32(floor(itemTemplate->BuyPrice * discountMod)) : 0;
//
//                    data << uint32(slot + 1);       // client expects counting to start at 1
//                    data << uint32(item->item);
//                    data << uint32(itemTemplate->DisplayInfoID);
//                    data << int32(1);
//                    data << uint32(price);
//                    data << uint32(itemTemplate->MaxDurability);
//                    data << uint32(itemTemplate->BuyCount);
//                    data << uint32(item->ExtendedCost);
//
//                    if (++count >= MAX_VENDOR_ITEMS)
//                        break;
//                }
//            }
//        }
//
//        if (count == 0)
//        {
//            data << uint8(0);
//            player->GetSession()->SendPacket(&data);
//            return false;
//        }
//
//        data.put<uint8>(countPos, count);
//        player->GetSession()->SendPacket(&data);
//
//        vendor->aa_vendor_entry = entry;
//        return true;
//    };
//
//    static bool AA_chuansongmoban(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//        char* zustr = strtok((char*)args, " ");
//        char* nanduidstr = strtok(nullptr, " ");
//        char* moshiidstr = strtok(nullptr, " ");
//        if (!zustr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送模板 __采集_坐标_组(同一组中按几率随机坐标) 秘境难度等级(选填) 副本模式(选填)1代表5人普通和10人普通，2代表5人英雄和25人普通，3代表10人英雄，4代表25人英雄");
//            return false;
//        }
//        int32 zu = int32(std::atoi(zustr));
//        AA_Caiji_Zuobiao conf;
//        std::vector<uint32> conf_ids = aaCenter.aa_caiji_zuobiao_zus[zu];
//        //获取总chance，分母
//        int count = conf_ids.size();
//        if (count) {
//            uint32 chanceMax = 0;
//            for (int i = 0; i < count; i++) {
//                uint32 id = conf_ids[i];
//                AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
//                chanceMax += conf.chance;
//            }
//            if (chanceMax == 0) { chanceMax = 1; }
//            //获取随机chance，分子
//            uint32 chanceVal = rand() % chanceMax;
//            //获取Index
//            uint32 max = 0;
//            uint32 min = 0;
//            int index = -1;
//            for (int i = 0; i < count; i++) {
//                uint32 id = conf_ids[i];
//                AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
//                max = conf.chance + max;
//                min = 0;
//                if (i == 0) {
//                    min = 0;
//                }
//                else {
//                    uint32 id = conf_ids[i - 1];
//                    AA_Caiji_Zuobiao conf = aaCenter.aa_caiji_zuobiaos[id];
//                    min = conf.chance + min;
//                }
//
//                if (min <= chanceVal && chanceVal < max) {
//                    index = i;
//                    break;
//                }
//            }
//            uint32 id = conf_ids[index];
//            conf = aaCenter.aa_caiji_zuobiaos[id];
//        }
//
//        if (conf.id > 0) {
//            int32 nanduid = -2;
//            int32 moshiid = -2;
//            if (nanduidstr) {
//                nanduid = uint32(std::atoi(nanduidstr));
//            }
//            if (moshiidstr) {
//                moshiid = int32(std::atoi(moshiidstr));
//            }
//
//            target->aa_teleport_nandu = nanduid;
//            target->aa_teleport_moshi = moshiid;
//            target->aa_teleport_map = conf.map;
//            aaCenter.AA_TeleportMoban(target, conf.id);
//            target->aa_teleport_map = -2;
//
//        }
//        else {
//            ChatHandler(handler->GetSession()).PSendSysMessage("错误，不存在的__采集_坐标_组");
//            return false;
//        }
//        return true;
//    }
//
//    static bool AA_chuansongwanjia(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return true;
//        }
//
//        char* name = strtok((char*)args, " ");
//
//        if (!name)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送玩家 玩家名字");
//            return false;
//        }
//
//        std::string namestr = name;
//
//        if (Player* toPlayer = ObjectAccessor::FindPlayerByName(namestr))
//        {
//            if (toPlayer->IsInWorld()) {
//                target->TeleportTo(toPlayer->GetMapId(), toPlayer->GetPositionX(), toPlayer->GetPositionY(), toPlayer->GetPositionZ(), toPlayer->GetOrientation());
//            }
//        }
//
//        return true;
//    }
//
//    static bool AA_chuansong(ChatHandler* handler, char const* args)
//    {
//        if (!*args)
//            return false;
//
//        Player* player = handler->getSelectedPlayerOrSelf();
//        char* goX = strtok((char*)args, " ");
//        if (goX && goX == "触发者") {
//            return true;
//        }
//        char* goY = strtok(nullptr, " ");
//        char* goZ = strtok(nullptr, " ");
//        char* id = strtok(nullptr, " ");
//        char* port = strtok(nullptr, " ");
//        char* goNandu = strtok(nullptr, " ");
//        char* moshiidstr = strtok(nullptr, " ");
//
//        if (!goX || !goY) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.传送 x y z mapid o 难度等级(选填) 副本模式(选填)1代表5人普通和10人普通，2代表5人英雄和25人普通，3代表10人英雄，4代表25人英雄");
//            return false;
//        }
//
//        float x = (float)atof(goX);
//        float y = (float)atof(goY);
//        float z;
//        float ort = port ? (float)atof(port) : player->GetOrientation();
//        ort = ort == 0 ? player->GetOrientation() : ort;
//        uint32 mapId = id ? (uint32)atoi(id) : player->GetMapId();
//
//        if (goZ)
//        {
//            z = (float)atof(goZ);
//            if (!MapMgr::IsValidMapCoord(mapId, x, y, z))
//            {
//                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//        }
//        else
//        {
//            if (!MapMgr::IsValidMapCoord(mapId, x, y))
//            {
//                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//            Map const* map = sMapMgr->CreateMap(mapId, target);
//            z = std::max(map->GetHeight(x, y, MAX_HEIGHT), map->GetWaterLevel(x, y));
//        }
//
//        if (goZ)
//        {
//            z = (float)atof(goZ);
//            if (!MapManager::IsValidMapCoord(mapId, x, y, z))
//            {
//                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//        }
//        else
//        {
//            if (!MapManager::IsValidMapCoord(mapId, x, y))
//            {
//                handler->PSendSysMessage(LANG_INVALID_TARGET_COORD, x, y, mapId);
//                handler->SetSentErrorMessage(true);
//                return false;
//            }
//            std::shared_ptr<TerrainInfo> terrain = sTerrainMgr.LoadTerrain(mapId);
//            z = std::max(terrain->GetStaticHeight(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y, MAX_HEIGHT), terrain->GetWaterLevel(PhasingHandler::GetEmptyPhaseShift(), mapId, x, y));
//        }
//
//
//        // stop flight if need
//        if (player->IsInFlight())
//            player->FinishTaxiFlight();
//        else
//            player->SaveRecallPosition(); // save only in non-flight case
//
//        int32 nanduid = -2;
//        if (goNandu) {
//            nanduid = (int32)(std::atoi(goNandu));
//        }
//        int32 moshiid = -2;
//        if (moshiidstr) {
//            moshiid = int32(std::atoi(moshiidstr));
//        }
//
//        player->aa_teleport_nandu = nanduid;
//        player->aa_teleport_moshi = moshiid;
//        player->aa_teleport_map = mapId;
//        player->TeleportTo(mapId, x, y, z, ort);
//        player->aa_teleport_map = -2;
//
//        return true;
//    }
//    static bool AA_chuanhuan(ChatHandler* handler, char const* args)
//    {
//        Player* me = handler->GetSession()->GetPlayer();
//        if (!me || !me->IsInWorld()) {
//            return false;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        std::string arg1str = "";
//        if (arg1) {
//            arg1str = arg1;
//        }
//        std::set<Player*> players; players.clear();
//        players = aaCenter.AA_GetPlayerRange(me, arg1str);
//        for (Player* p : players) {
//            if (!p->IsInWorld()) {
//                continue;
//            }
//            p->TeleportTo(me->GetMapId(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
//        }
//        return true;
//    }
//    static bool AA_shiqu(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player || !player->IsInWorld()) {
//            return false;
//        }
//        char* typestr = strtok((char*)args, " ");
//        if (!typestr)
//        {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.拾取 拾取范围");
//            return false;
//        }
//        uint32 type = atoi(typestr);
//        if (!player->IsAlive())
//        {
//            aaCenter.AA_SendMessage(player, 1, "|cff00FFFF[系统提示]|cffFF0000死亡状态下无法使用");
//            return false;
//        }
//        if (player->IsNonMeleeSpellCast(false))
//            player->InterruptNonMeleeSpells(false);
//        std::list<Creature*> list;
//        aaCenter.BB_GetCreatureListInGrid(player, list, type);
//        Group* group = player->GetGroup();
//        if (!list.empty())
//        {
//            for (std::list<Creature*>::iterator itr = list.begin(); itr != list.end(); ++itr)
//            {
//                Creature* c = *itr;
//                if (c && c->IsAlive())
//                    continue;
//                WorldPacket data;
//                data << c->GetGUID();
//                Loot* loot = &c->loot;
//                if (!group) {
//                    if (loot->lootOwnerGUID == player->GetGUID()) {
//                        player->SetLootGUID(c->GetGUID());
//                        uint32 max_slot = loot->GetMaxSlotInLootFor(player);
//                        for (uint32 i = 0; i < max_slot; ++i)
//                        {
//                            WorldPacket data;
//                            data << i;
//                            player->GetSession()->AA_HandleAutostoreLootItemOpcode(data);
//                        }
//                        player->GetSession()->AA_HandleLootMoneyOpcode(data);
//                    }
//                }
//                else {
//                    bool isOk = false;
//                    Group::MemberSlotList const& members = player->GetGroup()->GetMemberSlots();
//                    for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
//                    {
//                        if ((*itr).guid == loot->lootOwnerGUID) {
//                            isOk = true;
//                            break;
//                        }
//                    }
//                    if (isOk) {
//                        if (group->GetLootMethod() == FREE_FOR_ALL) {
//                            player->SetLootGUID(c->GetGUID());
//                            uint32 max_slot = loot->GetMaxSlotInLootFor(player);
//                            for (uint32 i = 0; i < max_slot; ++i)
//                            {
//                                WorldPacket data;
//                                data << i;
//                                player->GetSession()->AA_HandleAutostoreLootItemOpcode(data);
//                            }
//                            player->GetSession()->AA_HandleLootMoneyOpcode(data);
//                        }
//                        else {
//                            player->GetSession()->AA_HandleLootOpcode(data);
//                            player->SetLootGUID(c->GetGUID());
//                            player->GetSession()->AA_HandleLootMoneyOpcode(data);
//                        }
//                    }
//                }
//            }
//        }
//        return true;
//    }
//    static bool AA_jiangli(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        int32 id = int32(std::atoi(args));
//        if (id <= 0) {
//            return true;
//        }
//        aaCenter.M_Reward(target, id);
//        return true;
//    }
//    static bool AA_xuqiu(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        int32 id = int32(std::atoi(args));
//        if (id <= 0) {
//            return true;
//        }
//        if (aaCenter.M_CanNeed(target, id))
//        {
//            aaCenter.M_Need(target, id);
//        }
//        return true;
//    }
//    static bool AA_gonggao(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        int32 id = int32(std::atoi(args));
//        if (id <= 0) {
//            return true;
//        }
//        AA_Message aa_message;
//        AA_Notice notice = aaCenter.aa_notices[id];
//        aaCenter.AA_SendNotice(target, notice, true, aa_message);
//        return true;
//    }
//    static bool AA_tanchuang(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        int32 id = int32(std::atoi(args));
//        if (id <= 0) {
//            return true;
//        }
//        aaCenter.AA_EventStart(target, id);
//        return true;
//    }
//    static bool AA_tanchuangneirong(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        char* arg2 = strtok(nullptr, " ");
//        if (!arg1 && !arg2) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.弹窗内容 标题 内容");
//            return false;
//        }
//        std::string title = "";
//        std::string text = "";
//        if (arg1) {
//            title = std::string(arg1);
//        }
//        if (arg2) {
//            text = std::string(arg2);
//        }
//        aaCenter.AA_SendEvent(target, title, text);
//        return true;
//    }
//    static bool AA_duihuanmashengcheng(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->GetSession()->GetPlayer();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        char* arg2 = strtok(nullptr, " ");
//        char* arg3 = strtok(nullptr, " ");
//        if (!arg1 || !arg2) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.生成兑换码 奖励id 生成数量 注释");
//            return false;
//        }
//        uint32 reward = uint32(std::atoi(arg1));
//        uint32 count = uint32(std::atoi(arg2));
//        count = count == 0 ? 1 : count;
//        char chr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//            'A', 'B', 'C', 'D', 'E', 'F', 'G',
//            'H', 'I', 'J', 'K', 'L', 'M', 'N',
//            'O', 'P', 'Q', 'R', 'S', 'T',
//            'U', 'V', 'W', 'X', 'Y', 'Z',
//            'a', 'b', 'c', 'd', 'e', 'f', 'g',
//            'h', 'i', 'j', 'k', 'l', 'm', 'n',
//            'o', 'p', 'q', 'r', 's', 't',
//            'u', 'v', 'w', 'x', 'y', 'z' };
//        std::string sqlstrs = "";
//        srand((unsigned)time(0));
//        for (uint32 i = 0; i < count; i++) {
//            std::string cdk = "";
//            for (int i = 0; i < 10; i++) {
//                int index = rand() % 62;
//                cdk = cdk + chr[index];
//            }
//            std::string arg3str = "";
//            if (arg3) {
//                arg3str = arg3;
//            }
//            std::string sqlstr = "('" + arg3str + "','" + cdk + "'," + std::to_string(reward) + ")";
//            sqlstrs = sqlstrs + sqlstr + ",";
//            AA_Duihuanma conf;
//            conf.cdk = cdk;
//            conf.reward = reward;
//            aaCenter.aa_duihuanmas[cdk] = conf;
//        }
//        std::string sql = "INSERT INTO _奖励_兑换码 (注释,兑换码,奖励) VALUES " + sqlstrs;
//        aaCenter.AA_StringReplaceLast(sql, ",", "");
//        WorldDatabase.DirectExecute(sql.c_str());
//        aaCenter.AA_SendMessage(target, 0, "|cff00FFFF[系统提示]|cffFFFF00兑换码生成成功");
//        return true;
//    }
//    static bool AA_duihuanma(ChatHandler* handler, char const* args)
//    {
//        Player* target = handler->getSelectedPlayerOrSelf();
//        if (!target || !target->IsInWorld()) {
//            return false;
//        }
//        char* arg1 = strtok((char*)args, " ");
//        if (!arg1) {
//            ChatHandler(handler->GetSession()).PSendSysMessage("语法格式:.兑换码 兑换码");
//            return false;
//        }
//        AA_Duihuanma conf = aaCenter.aa_duihuanmas[arg1];
//        if (conf.cdk == "") {
//            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000兑换码不存在。");
//            return false;
//        }
//        if (conf.time == 0) {
//            aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000兑换码已失效。");
//            return false;
//        }
//        ObjectGuid::LowType guidlow = target->GetGUIDLow();
//        uint32 accountid = target->GetSession()->GetAccountId();
//        std::string ip = target->GetSession()->GetRemoteAddress();
//        if (ip != "") {
//            AA_Duihuanma_Conf conf1 = aaCenter.aa_duihuanma_confs[conf.zu];
//            if (conf1.zu > 0) {
//                //获取数量
//                uint32 count_guidlow = 0;
//                uint32 count_account = 0;
//                uint32 count_ip = 0;
//                for (auto d_conf : aaCenter.aa_duihuanmas) {
//                    if (d_conf.second.zu != conf.zu) {
//                        continue;
//                    }
//                    if (d_conf.second.guid != "") {
//                        std::vector<int32> guids; guids.clear();
//                        aaCenter.AA_StringToVectorInt(d_conf.second.guid, guids, ",");
//                        for (auto guid : guids) {
//                            if (guid == (int32)guidlow) {
//                                count_guidlow++;
//                            }
//                        }
//                    }
//                    if (d_conf.second.account != "") {
//                        std::vector<int32> accounts; accounts.clear();
//                        aaCenter.AA_StringToVectorInt(d_conf.second.account, accounts, ",");
//                        for (auto account : accounts) {
//                            if (account == (int32)accountid) {
//                                count_account++;
//                            }
//                        }
//                    }
//                    if (d_conf.second.ip != "") {
//                        std::vector<std::string> ips; ips.clear();
//                        aaCenter.AA_StringToVectorString(d_conf.second.ip, ips, ",");
//                        for (auto ip1 : ips) {
//                            if (ip1 == ip) {
//                                count_ip++;
//                            }
//                        }
//                    }
//                }
//                if (conf1.guid > 0 && conf1.guid <= count_guidlow) { //角色领取限制
//                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的角色达到领取数量限制。");
//                    return false;
//                }
//                if (conf1.account > 0 && conf1.account <= count_account) { //账号领取限制
//                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的账号达到领取数量限制。");
//                    return false;
//                }
//                if (conf1.ip > 0 && conf1.ip <= count_ip) { //ip领取限制
//                    aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFF0000你的IP达到领取数量限制。");
//                    return false;
//                }
//            }
//        }
//        if (conf.need > 0) {
//            if (aaCenter.M_CanNeed(target, conf.need)) {
//                aaCenter.M_Need(target, conf.need);
//            }
//            else {
//                return false;
//            }
//        }
//        if (conf.reward > 0) {
//            aaCenter.M_Reward(target, conf.reward, 1);
//        }
//        int32 dh_time = (conf.time - 1) >= 0 ? (conf.time - 1) : 0;
//        {
//            std::vector<int32> guids; guids.clear();
//            aaCenter.AA_StringToVectorInt(aaCenter.aa_duihuanmas[arg1].guid, guids, ",");
//            guids.push_back(guidlow);
//            std::string str = "";
//            aaCenter.AA_VectorIntToString(str, guids, ",");
//            aaCenter.aa_duihuanmas[arg1].guid = str;
//        }
//        {
//            std::vector<int32> accounts; accounts.clear();
//            aaCenter.AA_StringToVectorInt(aaCenter.aa_duihuanmas[arg1].account, accounts, ",");
//            accounts.push_back(accountid);
//            std::string str = "";
//            aaCenter.AA_VectorIntToString(str, accounts, ",");
//            aaCenter.aa_duihuanmas[arg1].account = str;
//        }
//        {
//            std::vector<std::string> ips; ips.clear();
//            aaCenter.AA_StringToVectorString(aaCenter.aa_duihuanmas[arg1].ip, ips, ",");
//            ips.push_back(ip);
//            std::string str = "";
//            aaCenter.AA_VectorStringToString(str, ips, ",");
//            aaCenter.aa_duihuanmas[arg1].ip = str;
//        }
//        WorldDatabase.DirectExecute("update _奖励_兑换码 set 兑换角色 = '{}',兑换账号 = '{}',兑换IP = '{}',兑换次数 = {} where 兑换码 = '{}'", aaCenter.aa_duihuanmas[arg1].guid, aaCenter.aa_duihuanmas[arg1].account, aaCenter.aa_duihuanmas[arg1].ip, dh_time, arg1);
//        aaCenter.aa_duihuanmas[arg1].time = dh_time;
//        if (conf.notice > 0) {
//            AA_Message aa_message;
//            AA_Notice notice = aaCenter.aa_notices[conf.notice];
//            aaCenter.AA_SendNotice(target, notice, true, aa_message);
//        }
//        aaCenter.AA_SendMessage(target, 1, "|cff00FFFF[系统提示]|cffFFFF00兑换码兑换成功");
//        return true;
//    }
//};
//
//void AddAA_CommandScript()
//{
//    new aa_commandscript();
//}
