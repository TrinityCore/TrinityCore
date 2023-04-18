
#ifndef _BOT_AI_SPELLS_H_
#define _BOT_AI_SPELLS_H_

#include "ScriptSystem.h"
#include "BotAITool.h"

class BotWarriorSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 WarriorIDLE_AOEAddLife;// = 47440,45517;			// 命令怒吼
	uint32 WarriorIDLE_AOEAddPower;// = 47436,27578			// 攻强怒吼	 	

	uint32 WarriorWeapon_Status;// = 2457;
	uint32 WarriorDefance_Status;// = 71;
	uint32 WarriorRage_Status;// = 2458;

	uint32 WarriorCommon_PowerAtt;// = 47450;25712		// 英勇打击
	uint32 WarriorCommon_PowerThrow;// = 57755;			// 英勇投掷
	uint32 WarriorCommon_PowerRelife;// = 55694;184364	// 狂怒恢复（有狂暴时使用回血）
	uint32 WarriorCommon_ClearCtrl;// = 18499;			// 狂暴之怒（移除控制）
	uint32 WarriorCommon_AOEFear;// = 5246;65930		// 近战范围群恐惧
	uint32 WarriorCommon_SweepAtt;// = 47520;231833		// 顺劈斩
	uint32 WarriorCommon_AddPower;// = 2687;173401		// 加怒气 
	uint32 WarriorCommon_AOEDecPower;// = 47437;27579	// 群体减攻强吼
		 	 	 		
	uint32 WarriorDefance_HPojia;// = 47498;186688		// 毁灭打击 
	uint32 WarriorDefance_Fuchou;// = 57823;40392		// 复仇
	uint32 WarriorDefance_ShieldBlock;// = 2565;38031	// 盾牌格挡
	uint32 WarriorDefance_ShieldAtt;// = 47488;23922	// 盾牌猛击
	uint32 WarriorDefance_Pojia;// = 7386;25051			// 破甲
	uint32 WarriorDefance_MaxLife;// = 12975;			// 破釜沉舟
	uint32 WarriorDefance_ShiledWall;// = 871;			// 盾墙
	uint32 WarriorDefance_Disarm;// = 676;11879			// 缴械
	uint32 WarriorDefance_Support;// = 3411;41198		// 援助
	uint32 WarriorDefance_Conk;// = 12809;22427			// 单体击晕
	uint32 WarriorDefance_AOEConk;// = 46968;			// 前方范围击晕
	uint32 WarriorDefance_Pull;// = 355;				// 嘲讽

	uint32 WarriorWeapon_SwordStorm;// = 46924;9632		        // 剑刃风暴
	uint32 WarriorWeaponDefance_AOEAtt;// = 47502;165749        // 雷霆一击
	uint32 WarriorWeaponDefance_Bleed;// = 47465;43931		    // 撕裂
	uint32 WarriorWeaponDefance_SpellReflect;// = 23920;57643   // 法术反射
	uint32 WarriorWeaponDefance_ShieldHit;// = 72;149383		// 盾击（施法打断）

	uint32 WarriorWeapon_HighThrow;// = 64382;65940		// 破无敌投掷
	uint32 WarriorWeapon_Charge;// = 11578;100			// 冲锋
	uint32 WarriorWeapon_Suppress;// = 7384;			// 压制
	uint32 WarriorWeapon_Backstorm;// = 20230;22857		// 反击风暴
	uint32 WarriorWeapon_DeadAtt;// = 47486;27580		// 致死打击

	uint32 WarriorWeaponRage_FullKill;// = 47471;5308	// 斩杀
	uint32 WarriorWeaponRage_WinAttack;// = 34428;		// 乘胜追击
	uint32 WarriorWeaponRage_Backfillet;// = 1715;		// 断筋

	uint32 WarriorRage_Harsh;// = 12323;				// 刺耳怒吼
	uint32 WarriorRage_HeadAtt;// = 6552;				// 拳击（施法打断）
	uint32 WarriorRage_Intercept;// = 20252;20615		// 拦截
	uint32 WarriorRage_Whirlwind;// = 1680;12950		// 旋风斩
	uint32 WarriorRage_Impertinency;// = 1719;13847		// 鲁莽
	uint32 WarriorRage_Needdead;// = 12292;199261		// 死亡之愿
	uint32 WarriorRage_Bloodthirsty;// = 23881;39071	// 嗜血
	uint32 WarriorRage_ReIntercept;// = 60970;184364	// 解除移动限制和解除拦截CD
    };

class BotPaladinSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 PaladinIDLE_MountAura;// 32223			    坐骑速度光环              225454;  
	uint32 PaladinIDLE_CastAura;// 19746		        施法光环	              81455;// 19746
	uint32 PaladinIDLE_JudgeAura;// 54043			    惩戒光环                  8990;// 54043
	uint32 PaladinIDLE_ArmorAura;// 48942		    	防御光环                  41105;// 48942		
	uint32 PaladinIDLE_AOEGuardWish;// 25899			群体庇护祝福(防御系)      210256;// 25899	
	uint32 PaladinIDLE_GuardWish;// 20911			    庇护祝福(防御系)          210256;// 20911
	uint32 PaladinIDLE_AOEKingWish;// 25898			    群体王者祝福              43223;// 25898
	uint32 PaladinIDLE_KingWish;// 20217			    王者祝福                  56525;// 20217
	uint32 PaladinIDLE_AOEWitWish;// 48938		        群体智慧祝福	          203539;// 48938
	uint32 PaladinIDLE_WitWish;// 48936				    智慧祝福                  175365;// 48936
	uint32 PaladinIDLE_AOEStrWish;// 48934			    群体力量祝福              29381;// 48934
	uint32 PaladinIDLE_StrWish;// 48932				    力量祝福                  56520;// 48932             
	uint32 PaladinIDLE_JusticeRage;// 25780			    正义之怒 防骑使用         25780;// 25780
	uint32 PaladinIDLE_Revive;// 48950                  复活玩家                  7328;// 48950

	uint32 PaladinGuard_UnShield;// 53601			    29386;// 53601			崇圣护盾
	uint32 PaladinGuard_FreeAura;// 1044			    1044;// 1044			自由祝福
	uint32 PaladinGuard_Invincible;// 642			     642;// 642			圣盾术 无敌
	uint32 PaladinGuard_Sacrifice;// 6940			 187190;// 6940			牺牲之手 目标受伤转移
	uint32 PaladinGuard_AOESacrifice;// 64205		 13903;// 64205		神圣牺牲 团队受伤转移(防御系)
	uint32 PaladinGuard_BlockShield;// 48952			31904;// 48952			神圣格挡(防御系)
	uint32 PaladinGuard_PhyImmune;// 10278			10278			目标物理免疫
	uint32 PaladinGuard_Pull;// 62124               62124				嘲讽
   
	uint32 PaladinAssist_UpPower;// 31884			31842;// 31884			开翅膀 UP伤害
	uint32 PaladinAssist_RevengeStamp;// 31801		45095;// 31801		复仇圣印 叠加5层伤害提高
	uint32 PaladinAssist_LifeStamp;// 20165			     165745;// 20165			光明圣印 攻击回血
	uint32 PaladinAssist_ManaStamp;// 20166			 130433;// 20166			智慧圣印 攻击回蓝
	uint32 PaladinAssist_JusticeStamp;// 21084		 38008;// 21084		正义圣印 攻击提高
	uint32 PaladinAssist_StunStamp;// 20164			  50907;// 20164			公正圣印 攻击几率昏迷
	uint32 PaladinAssist_ComStamp;// 20375			13903;// 20375			命令圣印 攻击加强(惩戒系)
	uint32 PaladinAssist_Confession;// 20066			173315;// 20066			忏悔 控制(惩戒系)
	uint32 PaladinAssist_StunMace;// 10308			 66863;// 10308			制裁之锤 昏迷
	uint32 PaladinAssist_ReviveMana;// 54428			173521;// 54428			回蓝BUF
	uint32 PaladinAssist_HealCrit;// 20216		210294;// 20216			next治疗暴击(神圣系)
	uint32 PaladinAssist_LowMana;// 31842		 20271;// 31842			法术耗蓝降低(神圣系)
	uint32 PaladinAssist_AuraUP;// 31821		 31821;// 31821			光环效果加强BUF(神圣系)
	uint32 PaladinAssist_Dispel;// 4987              4987;// 4987				驱散魔法中毒

	uint32 PaladinHeal_FastHoly;// 48785		19750;// 48785			圣光闪现	
	uint32 PaladinHeal_BigHoly;// 48782			 13952;// 48782				圣光术	
	uint32 PaladinHeal_FullHoly;// 48788		 9257;// 48788			圣疗	

	uint32 PaladinMelee_AOEOffertory;// 48819		251152;// 48819		奉献
	uint32 PaladinMelee_KillMace;// 48806			37259;// 48806			斩杀之锤 目标低于20%血
	uint32 PaladinMelee_FlyShield;// 48827			 31935;// 48827			弹射飞盾(防御系)
	uint32 PaladinMelee_ShieldAtt;// 61411			 53600;// 61411			盾牌打击(防御系)
	uint32 PaladinMelee_MaceAtt;// 53595			 53595;// 53595			正义之锤(防御系)
	uint32 PaladinMelee_HolyAtt;// 48825			 25914;// 48825			神圣震击(神圣系)
	uint32 PaladinMelee_LifeJudge;// 20271			     31804;// 20271			光明审判
	uint32 PaladinMelee_ManaJudge;// 53408			41368;// 53408			智慧审判
	uint32 PaladinMelee_FleeJudge;// 53407			201371;// 53407			公正审判
	uint32 PaladinMelee_WeaponAtt;// 35395			213844;// 35395			十字军打击(惩戒系)
	uint32 PaladinMelee_HolyStrom;// 53385			 163888;// 53385			神圣风暴(惩戒系)

	uint32 PaladinFlag_MomentHoly;// 59578			 251152;// 59578			战争艺术 瞬发圣闪
	uint32 PaladinFlag_Discipline;// 25771			  25771;// 25771			自律 DEBUFF
};

class BotDeathknightSpells
{
public:
	void InitializeSpells(Player* player);

protected:
    uint32 DKStatus_Frost = 50689;// 48263			冰霜灵气
    uint32 DKStatus_Evil = 50689;// 48265			邪恶灵气
    uint32 DKStatus_Blood = 50689;// 48266			鲜血灵气

    uint32 DKIDLE_SummonPet;//	46584		召唤食尸鬼
    uint32 DKIDLE_SummonAllPets;//	42650	亡者大军 召唤食尸鬼军团

    uint32 DKBlock_Silence;// 221562		窒息 沉默目标
    uint32 DKBlock_Cast;// 47528			心灵冰冻 打断施法

    uint32 DKRevie;// 61999                 复活盟友
    uint32 DKPulls_Pull;// 56222			单体嘲讽
    uint32 DKPulls_DKPull;// 49576			死亡之握
    uint32 DKPulls_DKAllPull;// 108199		血魔之握

    uint32 DKDefense_MgcShield;// 48707		反魔法盾(全系)
    uint32 DKDefense_IceBody;// 48792		冰封之韧(全系)
    uint32 DKDefense_IceArmor;// 196770		冷酷严寒(寒冰系)
    uint32 DKDefense_BoneShield;// 49222	骨髓分裂 白骨之盾(鲜血系)

    uint32 DKAssist_RuneLife;// 49028		符文刃舞(鲜血系)
    uint32 DKAssist_BloodBrand;// 206940	鲜血印记，目标攻击的目标回血(鲜血系)天赋
    //此处添加
    uint32 DKAssist_Frenzied = 188541;// 49016		狂乱，友目标物理伤害UP(鲜血系)
    uint32 DKAssist_NextCrit = 79092;// 49796		激活后冰霜疾病、吞噬疾病、冰霜打击暴击(寒冰系)
    uint32 DKAttack_IceSickness = 52372;// 49909	冰霜疾病，冰灵气时高仇恨
    uint32 DKAttack_DoDestroy = 246593;// 51425		吞噬疾病，高伤害
    uint32 DKAttack_RuneAttack = 62322;// 56815		符文打击，类似压制
    uint32 DKAttack_LifeAttack = 53639;// 49924		攻击恢复生命，一个疾病5%血
    uint32 DKAttack_IceWindAtt = 61061;// 51411		冰风冲击(寒冰系)
    uint32 DKAttack_CorpseExplosion = 17616;// 51328	尸爆(邪恶系)
    uint32 DKAttack_NaturalAtt = 164330;// 55271		天灾打击(邪恶系)
    uint32 DKAttack_CoreAtt = 206930;// 55262		心脏打击(鲜血系)

    uint32 DKAttack_NearAOE = 92025;// 49941		近战范围AOE，有血和冰疾病伤害UP
    uint32 DKAttack_AreaAOE = 43265;// 49938		枯萎凋零，指定范围AOE
    uint32 DKAttack_BloodAtt = 60945;// 49930		鲜血攻击，有疾病时伤害UP
    uint32 DKAttack_ShadowAtt = 50688;// 49921		暗影打击，血疾病
    uint32 DKAttack_FrostAtt = 60951;// 55268		冰霜打击(寒冰系)

    uint32 DKDefense_NoMgcArea = 52893;// 51052		反魔法领域，对自己施放，区域内反魔法(邪恶系)
    uint32 DKDefense_Contract = 48743;// 48743		杀死BB回血40%
    //uint32 DKDefense_IceBody = 66023;// 48792		DK盾墙
    //uint32 DKDefense_IceArmor = 132103;// 51271		铜墙铁壁(提供护甲和力量20秒)(寒冰系)
    //uint32 DKDefense_BoneShield = 232049;// 49222	白骨之盾(邪恶系)

    uint32 DKIDLE_Buffer = 165762;// 57623			全队力量和敏捷BUFF
    //uint32 DKIDLE_SummonPet = 52451;//	46584		召唤食尸鬼
    //uint32 DKIDLE_SummonAllPets = 52478;//	42650	召唤食尸鬼军团

    //uint32 DKBlock_Silence = 66018;// 47476			沉默目标
    //uint32 DKBlock_Cast = 173047;// 47528			打断施法

    //uint32 DKPulls_Pull = 222409;// 56222			单体嘲讽
    //uint32 DKPulls_DKPull = 53276;// 49576			死亡之握

    //uint32 DKDefense_MgcShield = 19645;// 48707		反魔法盾

    uint32 DKAssist_BloodBuf;// 55233		吸血鬼之血 (鲜血系)
    uint32 DKAssist_SummonRuneWeapon;// 49028	召唤符文武器，独立战斗(鲜血系)
    uint32 DKAssist_RuneWeapon;// 47568		符文武器增效 激活全符文，25符文能量
    uint32 DKAssist_Infect;// 50842			血液沸腾 目标的冰血疾病扩散传染
    uint32 DKAssist_RuneShunt;// 45529		活力分流 血符文转公共符文
    uint32 DKAssist_IceLock;// 45524		冰锁链，目标10秒内移动速度低
    uint32 DKAssist_DeadRevive;// 47541		死亡缠绕，攻击目标或者亡灵恢复

    uint32 DKAssist_PetPower;// 63560		黑暗突变 食尸鬼狂乱(邪恶系)
    uint32 DKAssist_SummonFlyAtt;// 49206	召唤石像鬼 轰炸机(邪恶系)

    //uint32 DKAttack_AreaAOE;// 43265		枯萎凋零，指定范围AOE
    //uint32 DKAttack_BloodAtt;// 49998		灵界打击，有疾病时伤害UP
    //uint32 DKAttack_ShadowAtt;// 85948		脓疮打击，血疾病
    //uint32 DKAttack_FrostAtt;// 49143		冰霜打击(寒冰系)
    //uint32 DKAttack_RuneAttack;// 49020		湮灭
    //uint32 DKAttack_IceWindAtt;// 49184		冰风冲击(寒冰系)
    //uint32 DKAttack_CorpseExplosion;// 77575	爆发(邪恶系)
    //uint32 DKAttack_NaturalAtt;// 55090		天灾打击(邪恶系)
    //uint32 DKAttack_CoreAtt;// 206930		心脏打击(鲜血系)
    uint32 DKAttack_Deaths_caress;// 195292 死神的抚摩
};

class BotRogueSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 RogueGuard_Sneak;// 1784				
	uint32 RogueGuard_ShadowCloak;// 31224		暗影斗篷
	uint32 RogueGuard_Disappear;// 26889		
	uint32 RogueGuard_Dodge;// 5277			    闪避
	uint32 RogueGuard_Sprint;// 11305			

	uint32 RogueSneak_Stick;// 6770			    闷棍
	uint32 RogueSneak_Premeditate;// 14183		预谋 TO DO
	uint32 RogueSneak_Ambush;// 8676			伏击
	uint32 RogueSneak_Surprise;// 1833			偷袭

	uint32 RogueAssist_ShadowDance;// 185313	51713		暗影之舞(敏锐系) 暗影之舞(敏锐)
	uint32 RogueAssist_ShadowFlash;// 36554		145426 		暗影步(敏锐系)

	uint32 RogueAssist_ReadyCD;// 14185			145426  预备(敏锐系)
	uint32 RogueAssist_Blind;// 2094			致盲
	uint32 RogueAssist_Disarm;// 51722			
	uint32 RogueAssist_NextCrit;// 79140		宿敌(刺杀)
	uint32 RogueAssist_blood;// 51662			 ()
	uint32 RogueAssist_FastEnergy;// 13750		冲动(狂徒)
	uint32 RogueAssist_BlockCast;// 1766		脚踢 打断施法
	uint32 RogueAssist_Paralyze;// 1776			 
	uint32 RogueAssist_FastSpeed;// 13877		 33735 		加攻击速度20(战斗系)

    /*
    		
    uint32 RogueAssist_Blind = 2094;// 2094			致盲
    uint32 RogueAssist_Disarm = 236077;// 51722			缴械
    uint32 RogueAssist_NextCrit = 213981;// 14177		冷血 next暴击(刺杀系)
    uint32 RogueAssist_blood = 60177;// 51662			鲜血 目标流血时施放(刺杀系)
    uint32 RogueAssist_FastEnergy = 13750;// 13750		能量快速回复(战斗系)
    uint32 RogueAssist_BlockCast = 1766;// 1766		脚踢 打断施法
    uint32 RogueAssist_Paralyze = 1776;// 1776			凿击 瘫痪目标
    */

	uint32 RogueAOE_Knife;// 51723				刀扇(刺杀)
	uint32 RogueAOE_AllDance;// 193315			军刀猛刺(狂徒)

	uint32 RogueAttack_Blood;// 212283			死亡符记(敏锐) +40能量
	uint32 RogueAttack_Ghost;// 195452 			夜刃(敏锐) 终结技
	uint32 RogueAttack_Injure;// 1329			毁伤(刺杀)
	uint32 RogueAttack_PoisonAtt;// 5938		
	uint32 RogueAttack_BackAtt;// 53			背刺

	uint32 RogueAttack_Damage;// 48668			
	uint32 RogueAttack_Separate;// 48672		
	uint32 RogueAttack_Stun;// 8643				
	uint32 RogueAttack_PoisonDmg;// 57993		
	uint32 RogueAttack_Incision;// 6774		 5171       切割(攻击速度终结技)    
    uint32 RogueAttack_EvilAtt = 1752;// 48638			邪恶攻击
	uint32 RogueRange_Throw;// 48674			

	uint32 RogueFlag_Dance;// 185422			暗影之舞buff
};

class BotDruidSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 DruidIDLE_FerityWish;// 48469		野性祝福
	uint32 DruidIDLE_AOEFerityWish;// 48470		群体野性祝福
	uint32 DruidIDLE_Revive;// 50769			复活玩家
	uint32 DruidIDLE_CombatReive;// 20484		战斗复活玩家

	uint32 DruidStatus_Travel;// 783			
	uint32 DruidStatus_Bear;// 5487				
	uint32 DruidStatus_Cat;// 768				
	uint32 DruidStatus_Bird;// 24858			()
	uint32 DruidStatus_Tree;// 33891			()

    uint32 DruidGuard_Thrash;// 77758          痛击
    uint32 DruidGuard_Swipe;//213764            横扫
	uint32 DruidGuard_Sneak;// 5215				猎豹潜行
	uint32 DruidGuard_Harden;// 22812			树皮术 免伤20%
	uint32 DruidGuard_Thorns;// 53307			荆棘术 攻击反伤
	uint32 DruidGuard_AutoTwine;// 53312		受击缠绕目标
	uint32 DruidGuard_Twine;// 339			缠绕目标
	
	uint32 DruidGuard_Pofu;// 61336				野性形态破釜沉舟(野性系)
	uint32 DruidGuard_TreeMan;// 205636			自然之力召唤树人(平衡系)

	uint32 DruidAssist_PersonSpirit;// 770		人形态精灵之火
	uint32 DruidAssist_BeastSpirit;// 16857		野性形态精灵之火
	uint32 DruidAssist_Active;// 29166			激活 目标回蓝
	uint32 DruidAssist_DecCruse;// 2782			德鲁伊解除诅咒
	uint32 DruidAssist_DecCruel;// 2782			德鲁伊解毒，BUF

	uint32 DruidCast_Moonfire;// 48463			月火 持续伤害技能
	uint32 DruidCast_Insect;// 93402			日炎 持续伤害技能(平衡系)
	uint32 DruidCast_Anger;// 48461				愤怒
	uint32 DruidCast_Spark;// 48465				星火 cast长
    uint32 DruidGuard_Control;// 209753			吹风 平衡 控制目标目标放逐

	uint32 DruidAOE_Hurricane;// 48467			飓风 AOE
	uint32 DruidAOE_Typhoon;// 61384			台风 AOE(平衡系)
	uint32 DruidAOE_FallStar;// 191034			群星坠落 AOE(平衡系)

    uint32 DruidHeal_Nourishing;// 50464		滋补术 小读秒加血 有持续治疗效果时加强
    uint32 DruidHeal_Relife;// 774			回春术 小持续加血
    uint32 DruidHeal_Coalescence;// 8936		愈合术 小加血
    uint32 DruidHeal_Touch;// 5185				治疗之触 大加血
    uint32 DruidHeal_LifeBurst;// 33763			生命绽放 持续效果结束时再加血
    uint32 DruidHeal_MergerLife;// 18562		迅捷治疗 吞并回春或愈合 加血(恢复系)
    uint32 DruidHeal_MomentHeal;// 17116		自然之握 nextHeal施法瞬发(恢复系)
    uint32 DruidHeal_WildGrowth;// 48438        野性成长 

	uint32 DruidHeal_AOETranquility;// 740		宁静
	uint32 DruidHeal_AOEFerity;// 145205		百花齐放(恢复系)

    uint32 DruidCat_Stun;// 22570				猫 击晕 终结技
    uint32 DruidCat_Bite;// 22568				猫 凶猛咬 立即伤害终结技
    uint32 DruidCat_Roar;// 52610				猫 咆哮 给自己加伤害力终结技 天赋
    uint32 DruidCat_Separate;// 1079			猫 割裂 持续伤害终结技

    uint32 DruidCat_Tiger;// 5217				猫 猛虎之怒 伤害BUF
    uint32 DruidCat_FastMove;// 1850			猫 疾跑
    uint32 DruidCat_Charge;// 106839			猫 冲锋(野性系)
    uint32 DruidCat_Surprise;// 1822			猫 斜掠 潜行时第1击昏迷
    uint32 DruidCat_Sack;// 5221				猫 潜行时第1击伤害
    uint32 DruidCat_Claw;// 1822				猫 撕碎
    uint32 DruidCat_BackStab;// 48572			猫 背刺
    uint32 DruidCat_Attack;// 106785			猫 横扫群攻
    uint32 DruidCat_Sweep;// 106830				猫 痛击
    uint32 DruidCat_Laceration;// 48566			猫 裂伤(野性系)

    uint32 DruidBear_DecAtt;// 192081			熊 铁鬃
    uint32 DruidBear_AddPower;// 5229			熊 加怒气
    uint32 DruidBear_PowerLife;// 22842			熊 怒气回血
    uint32 DruidBear_Laceration;// 33917		熊 裂伤(野性系)
    uint32 DruidBear_Sweep;// 48568			熊 流血攻击
    uint32 DruidBear_Attack;// 106785			熊 横扫
    uint32 DruidBear_NextAtt;// 6807			熊  重殴
    uint32 DruidBear_Stun;// 5211				熊 击晕
    uint32 DruidBear_Charge;// 106839			熊 冲锋(野性系)
};

class BotHunterSpells
{
public:
	void InitializeSpells(Player* player);

protected:
    uint32 HunterIDLE_SummonPet;// 883			召唤宠物
    uint32 HunterIDLE_RevivePet;// 982			复活宠物
    uint32 HunterIDLE_ManaAura;// 193530		野性守护(兽王)
    uint32 HunterIDLE_DodgeAura;// 186265		灵龟守护(兽王 生存)
    uint32 HunterIDLE_EagleAura;// 186257		猎豹守护
    uint32 HunterIDLE_DragonAura;// 186289		雄鹰守护(生存)
    uint32 HunterIDLE_ShotAura;// 193526		百发百中(射击系)

    uint32 HunterTrap_FarFrozen;// 187650		远程冰冻陷阱
    uint32 HunterTrap_Frozen;// 187698			焦油陷阱
    uint32 HunterTrap_Ice;// 13809				冰霜陷阱
    uint32 HunterTrap_Viper;// 34600			毒蛇陷阱
    uint32 HunterTrap_Explode;// 49067			爆炸陷阱
    uint32 HunterTrap_Fire;// 49056				火焰陷阱
    uint32 HunterTrap_Shot;// 63672				黑浊箭(生存系)

    uint32 HunterAssist_ClearRoot;// 53271		移除定身
    uint32 HunterAssist_DireBeast;// 120679     凶暴野兽
    uint32 HunterAssist_PetCommand;// 34026		宠物杀截
    uint32 HunterAssist_HealPet;// 136		    宠物治疗
    uint32 HunterAssist_PetStun;// 19577		宠物击晕目标(野兽系)
    uint32 HunterAssist_PetRage;// 19574		狂野怒火 宠物和自己狂暴(野兽系)
    uint32 HunterAssist_FalseDead;// 5384		假死
    uint32 HunterAssist_BackJump;// 781			后跳
    uint32 HunterAssist_Mislead;// 34477		误导
    //猎人添加
    uint32 HunterAssist_FastSpeed = 3045;// 3045		急速射击BUF
    uint32 HunterAssist_Stamp = 1130;// 53338			猎人印记
    uint32 HunterShot_KillShot = 69989;// 61006			击杀射击 目标20%以下血斩杀式射击


    uint32 HunterMelee_NoDamage;// 19263		威慑 无法攻击
    uint32 HunterMelee_DecSpeed;// 2974			摔拌 近战减移动速
    uint32 HunterMelee_NextAtt;// 48996			next近战攻击加强
    uint32 HunterMelee_MeleeAtt;// 202800		侧翼打击
    uint32 HunterMelee_Carve;// 187708		    削凿 aoe
    uint32 HunterMelee_Harpoon;// 190925        鱼叉猛刺
    uint32 HunterMelee_MongooseBite;// 190928   猫鼬撕咬
    uint32 HunterMelee_Lacerate;// 185855       裂痕
    uint32 HunterMelee_RaptorStrike;// 186270   猛禽一击
    uint32 HunterMelee_HatchetToss;// 193265    飞斧
    uint32 HunterMelee_BackRoot = 116599;// 48999		招架后反击定身(生存系)

    uint32 HunterDebug_Sleep;// 49012			沉睡钉刺(生存系)
    uint32 HunterDebug_Damage = 160503;// 49001			伤害钉刺
    uint32 HunterDebug_Mana = 31407;// 3034				吸蓝钉刺
    //uint32 HunterDebug_Sleep = 19386;// 49012			沉睡钉刺(生存系)   //later

    uint32 HunterShot_CharmShot;// 187707		压制(生存系)
    uint32 HunterShot_Explode;// 60053			爆炸射击(生存系)
    uint32 HunterShot_Aim;// 49050				瞄准射击(射击系)
    uint32 HunterShot_Silence;// 147362			反制射击(射击系)
    uint32 HunterShot_Shock;// 5116				震荡射击
    uint32 HunterShot_Cast;// 49052				稳固射击 施法时间的射击
    uint32 HunterShot_MgcShot;// 49045			奥术射击
    uint32 HunterShot_MulShot;// 2643			多重射击
    uint32 HunterShot_QMLShot;// 53209			奇美拉射击(射击系)
    uint32 HunterShot_AOEShot = 22908;// 58434			AOE射击
    uint32 Hunter_Exhilaration;// 109304        意气风发
    uint32 Hunter_CobraShot;// 193455           眼镜蛇射击
    uint32 Hunter_MarkShot;// 185901            标记射击
    uint32 Hunter_BurstingShot;// 186387        爆裂射击
    uint32 Hunter_AUTO_SHOT;// 75               自动射击
};

class BotShamanSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 ShamanIDLE_LifeWeapon;// 51994		
	uint32 ShamanIDLE_IceWeapon;// 58796		
	uint32 ShamanIDLE_FireWeapon;// 58790		
	uint32 ShamanIDLE_PhyWeapon;// 10399		
	uint32 ShamanIDLE_FastWeapon;// 58804		
	uint32 ShamanIDLE_Revive;// 49277			

	uint32 ShamanShield_Earth;// 49284			()
	uint32 ShamanShield_Water;// 57960			
	uint32 ShamanShield_Lightning;// 49281		

	uint32 ShamanAssist_Frog;// 51514			
	uint32 ShamanAssist_HealCrit;// 55198		next3()
	uint32 ShamanAssist_MomentHeal;// 16188		nextHeal()
	uint32 ShamanAssist_MomentCast;// 16166		nextCast()
	uint32 ShamanAssist_BlockCast;// 57994		
	uint32 ShamanAssist_Cleansing;// 8012		2?BUFF
	uint32 ShamanAssist_FireNova;// 61657		?AOE
	uint32 ShamanAssist_Heroic;// 32182			
	uint32 ShamanAssist_DecCruel;// 526			 

	uint32 ShamanAtt_StormStrike;// 17364		()
	uint32 ShamanAtt_FireStrike;// 60103		()

	uint32 ShamanCast_LightningArrow;// 49238	
	uint32 ShamanCast_LightningChain;// 49271	
	uint32 ShamanCast_LightningStorm;// 59159	()
	uint32 ShamanCast_FireThud;// 49233			
	uint32 ShamanCast_IceThud;// 49236			
	uint32 ShamanCast_EarthThud;// 49231		
	uint32 ShamanCast_FireStrike;// 60043		 

	uint32 ShamanHealth_Fast;// 49276			
	uint32 ShamanHealth_Bast;// 49273			
	uint32 ShamanHealth_Chain;// 55459			
	uint32 ShamanHealth_Torrent;// 61301		 ?+()
	uint32 ShamanDispel_Refine;// 51886			

	uint32 ShamanTotem_Recycle;// 36936			

	uint32 ShamanTotem_Life;// 58757			
	uint32 ShamanTotem_Mana;// 58774			
	uint32 ShamanTotem_BMana;// 16190			?

	uint32 ShamanTotem_SummonFire;// 2894		
	uint32 ShamanTotem_MgcPower;// 57722		()
	uint32 ShamanTotem_Attack;// 58704			
	uint32 ShamanTotem_AOEAttack;// 58734		
	uint32 ShamanTotem_MgcHeal;// 58656			

	uint32 ShamanTotem_DecMove;// 2484			
	uint32 ShamanTotem_SummonSoil;// 2062		
	uint32 ShamanTotem_PhyPower;// 58643		
	uint32 ShamanTotem_Armor;// 58753			

	uint32 ShamanTotem_AbsorbBuff;// 8177		BUFF
	uint32 ShamanTotem_AttSpeed;// 8512			
	uint32 ShamanTotem_MgcSpeed;// 3738			

	uint32 ShamanFlag_NoHeroic;// 57723			give
};

class BotMageSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 MageIDLE_ManaGem;// 42985		
	uint32 MageIDLE_ArcaneMagic;// 42995	
	uint32 MageIDLE_AOEArcaneMagic;// 43002	
	uint32 MageIDLE_MgcArmor;// 43024		
	uint32 MageIDLE_FrostArmor;// 43008		
	uint32 MageIDLE_IceArmor;// 7301		
	uint32 MageIDLE_FireArmor;// 43046		
	uint32 MageIDLE_MagicAdd;// 43017		
	uint32 MageIDLE_MagicDec;// 43015		
	uint32 MageIDLE_SummonRite;// 58659		

	uint32 MageGuard_MagicShield;// 43020	
	uint32 MageGuard_FrostShield;// 43039	
	uint32 MageGuard_FrostScherm;// 45438	
	uint32 MageGuard_FrostNova;// 42917		
	uint32 MageGuard_FireBreath;// 42950	
	uint32 MageGuard_FireNova;// 42945		

	uint32 MageAssist_Mirror;// 55342		
	uint32 MageAssist_Rouse;// 12051		
	uint32 MageAssist_Stealth;// 66			
	uint32 MageAssist_Teleport;// 1953		
	uint32 MageAssist_DecCurse;// 475		
	uint32 MageAssist_Grace;// 12043		
	uint32 MageAssist_ArcanePower;// 12042	
	uint32 MageAssist_CastSpeed;// 12472	
	uint32 MageAssist_FastColddown;// 11958	CD
	uint32 MageAssist_FrostPet;// 31687		?
	uint32 MageAssist_FireCritAura;// 11129	3AURA

	uint32 MageConfine_BreakCast;// 2139	
	uint32 MageConfine_AuraSteal;// 30449	BUFF
	uint32 MageConfine_ArcaneSlow;// 31589	
	uint32 MageConfine_ToSheep;// 12826		
	uint32 MageConfine_Freeze;// 44572		

	uint32 MageAOE_ArcaneExplode;// 42921	
	uint32 MageAOE_Snowstorm;// 42940		
	uint32 MageAOE_IcePiton;// 42931		
	uint32 MageAOE_FireStorm;// 42926		

	uint32 MageArcane_Barrage;// 44781		
	uint32 MageArcane_Bullet;// 42846		
	uint32 MageArcane_ArcaneShock;// 42897	

	uint32 MageFrost_IceArrow;// 42842		
	uint32 MageFrost_IceLance;// 42914		
	uint32 MageFrost_FFArrow;// 47610		

	uint32 MageFire_FireArrow;// 42833		
	uint32 MageFire_FireShock;// 42873		
	uint32 MageFire_Firing;// 42859			
	uint32 MageFire_BigFireBall;// 42891	
	uint32 MageFire_FireBomb;// 55360		

	uint32 MagePet_FrostNova;// 33395		

	uint32 MageFlag_FireStun;// 64343		Aura:
	uint32 MageFlag_FastFStorm;// 54741		Aura:
	uint32 MageFlag_FastBFBall;// 48108		Aura:?
	uint32 MageFlag_FastFFArrow;// 57761	Aura:?
	uint32 MageFlag_CanFrozen;// 74396		Aura:?
	uint32 MageFlag_Scherm;// 45438			Aura:?
};

class BotWarlockSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 WarlockIDLE_LowArmor;// 696			
	uint32 WarlockIDLE_Armor;// 47889			
	uint32 WarlockIDLE_HighArmor;// 47893		
	uint32 WarlockIDLE_SoulLink;// 19028		()
	uint32 WarlockIDLE_ShadowShield;// 47891		
	uint32 WarlockIDLE_SummonFireDemon;// 688	小鬼
	uint32 WarlockIDLE_SummonHollowDemon;// 697	虚空行者
	uint32 WarlockIDLE_SummonSuccubus;// 712		魅魔
	uint32 WarlockIDLE_SummonDogDemon;// 691		地狱猎犬
	uint32 WarlockIDLE_SummonGuardDemon;// 30146	恐惧卫士
	uint32 WarlockIDLE_FastSummon;// 18708		()
	uint32 WarlockIDLE_OpenGate;// 48018		
	uint32 WarlockIDLE_TeleGate;// 48020		
	uint32 WarlockIDLE_SummonRite;// 29893		

	uint32 WarlockDemon_ToDemon;// 47241		?
	uint32 WarlockDemon_Charge;// 104316		召唤猎犬
	uint32 WarlockDemon_MeleeAOE;// 193440		恶魔之怒
	uint32 WarlockDemon_Sacrifice;// 50589		

	uint32 WarlockAssist_DemonPower;// 47193		()
	uint32 WarlockAssist_ExtractMana;// 59092	()
	uint32 WarlockAssist_ConvertMana;// 57946	 
	uint32 WarlockAssist_StealLife;// 47857		
	uint32 WarlockAssist_StealMana;// 198590	吸取灵魂
	uint32 WarlockAssist_BaseFear;// 6215		
	uint32 WarlockAssist_FastFear;// 6789		死亡缠绕
	uint32 WarlockAssist_AOEFear;// 17928		?

	uint32 WarlockAOE_MeleeFire;// 61290		AOE
	uint32 WarlockAOE_RainFire;// 47820			AOE
	uint32 WarlockAOE_ShadowRage;// 193440		恶魔之怒 重复

	uint32 WarlockCurse_UpDmg;// 47865			
	uint32 WarlockCurse_MoveLow;// 18223		 ()
	uint32 WarlockCurse_MgcDmg;// 47864			 DOT
	uint32 WarlockCurse_MeleeLow;// 50511		 
	uint32 WarlockCurse_CastLow;// 11719		 

	uint32 WarlockDot_LeechSoul;// 980		    痛楚(痛苦)
	uint32 WarlockDot_HighDmg;// 30108			痛苦无常(痛苦)
	uint32 WarlockDot_LowDmg;// 172			    腐蚀术
	uint32 WarlockDot_AOEDmg;// 27243			腐蚀之种
	uint32 WarlockDot_Sacrifice;// 348		    献祭

	uint32 WarlockCast_ShadowArrow;// 47809		
	uint32 WarlockCast_ShadowShock;// 47827		24?()
	uint32 WarlockCast_ChaosArrow;// 59172		()
	uint32 WarlockCast_FullBurn;// 29722		烧尽
	uint32 WarlockCast_FireBurn;// 17962		燃烧
	uint32 WarlockCast_BigFireBall;// 105174	古尔丹之手

	uint32 WarlockPetDemon_Charge;// 47996		pet
	uint32 WarlockPetDemon_Melee;// 47994		pet
	uint32 WarlockPetDog_MagicBuf;// 57567		petBUF
	uint32 WarlockPetDog_EatMgc;// 48011		pet
	uint32 WarlockPetDog_Bite;// 54053			pet
	uint32 WarlockPetDog_Silence;// 19647		pet
	uint32 WarlockPetSuccubus_Lash;// 47992		pet
	uint32 WarlockPetSuccubus_Sneak;// 7870		pet
	uint32 WarlockPetSuccubus_Charm;// 6358		pet
	uint32 WarlockPetGhost_Shield;// 47983		pet
	uint32 WarlockPetGhost_Sneak;// 4511		pet
	uint32 WarlockPetGhost_Stamp;// 47982		pet
	uint32 WarlockPetGhost_FireArrow;// 47964	pet

	uint32 WarlockFlag_SoulItem;// 6265			
	uint32 WarlockFlag_SoulLink;// 25228		BUF
	uint32 WarlockFlag_OpenGate;// 48018		BUF
	uint32 WarlockFlag_Sacrifice;// 50589		BUF
};

class BotPriestSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 PriestIDLE_AllHardRes;// 48162			
	uint32 PriestIDLE_HardRes;// 48161				
	uint32 PriestIDLE_SoulFire;// 48168				
	uint32 PriestIDLE_AllSpiritRes;// 48074			
	uint32 PriestIDLE_SpiritRes;// 48073			
	uint32 PriestIDLE_Bloodsucker;// 15286			?
	uint32 PriestIDLE_AllShadowRes;// 48170			
	uint32 PriestIDLE_ShadowRes;// 48169			
	uint32 PriestIDLE_ShadowStatus;// 15473			
	uint32 PriestIDLE_Revive;// 48171				

	uint32 PriestGuard_ShadowFear;// 64044			()
	uint32 PriestGuard_AOEFear;// 10890				
	uint32 PriestGuard_DefFear;// 6346				?
	uint32 PriestGuard_RecoverMana;// 47585			()
	uint32 PriestGuard_DmgAnnul;// 33206			()
	uint32 PriestGuard_DefShield;// 48066			 ?
	uint32 PriestGuard_SelfHealth;// 48173			 ()
	uint32 PriestGuard_GuardSoul;// 47788			 target?()

	uint32 PriestAssist_SoulAbs;// 14751			next0()
	uint32 PriestAssist_AddHolyPower;// 10060		target()
	uint32 PriestAssist_AllDispel;// 32375			
	uint32 PriestAssist_Dispel;// 988				
	uint32 PriestAssist_ShadowDemon;// 34433			
	uint32 PriestAssist_Silence;// 15487			()
	uint32 PriestAssist_AllResMana;// 64901			
	uint32 PriestAssist_AllResLife;// 64843			
	uint32 PriestAssist_DecIllness;// 552			,BUF

	uint32 PriestDebuf_Ache;// 48125				?
	uint32 PriestDebuf_Drown;// 48158				?
	uint32 PriestDebuf_Plague;// 48300				

	uint32 PriestAOE_ShadowExplode;// 53023			AOE()
	uint32 PriestAOE_HolyNova;// 48078				

	uint32 PriestShadow_ShadowTouch;// 48160			()
	uint32 PriestShadow_Knocking;// 48127			
	uint32 PriestShadow_Lech;// 48156				()
	uint32 PriestHoly_Smite;// 48123				
	uint32 PriestHoly_BigFire;// 48135				
	uint32 PriestPrecept_ManaBurn;// 8129			

	uint32 PriestHeal_ZeroHeal;// 2050				
	uint32 PriestHeal_LowHeal;// 6064				
	uint32 PriestHeal_Resume;// 48068				
	uint32 PriestHeal_FastHeal;// 48071				
	uint32 PriestHeal_BigHeal;// 48063				
	uint32 PriestHeal_LinkHeal;// 48120				?
	uint32 PriestHeal_UnionHeal;// 48113			 target next heal
	uint32 PriestHeal_RingHeal;// 48089				()
	uint32 PriestHeal_AOEHeal;// 48072				 aoe heal
	uint32 PriestHeal_Awareness;// 53007			 3?()

	uint32 PriestFlag_DeadSoul;// 27827				 ?
	uint32 PriestFlag_NonShield;// 6788				DEBUFF
};


class BotDemonHunterSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    //SINGEL
    uint32 HAVOC_demons_bite;// 162243			
    uint32 HAVOC_chaos_strike;// 162794
    uint32 HAVOC_fel_rush;// 195072
    //AOE
    uint32 HAVOC_eye_beam;// 198013			
    uint32 HAVOC_blade_dance;// 188499			
    uint32 HAVOC_throw_glaive;// 185123			
    uint32 HAVOC_chaos_nova;// 179057
    //CONTROL
    uint32 HAVOC_disrupt;// 183752		
    uint32 HAVOC_imprison;// 217832
    uint32 HAVOC_vengeful_retreat;// 198793	
    uint32 HAVOC_fel_eruption;// 211881 talent
    //
    uint32 HAVOC_darkness;// 196718			
    uint32 HAVOC_blur;// 198589				
    uint32 HAVOC_metamorphosis;// 191427

    //SINGEL
    uint32 Vengeance_shear;// 203782
    //AOE
    uint32 Vengeance_immolation_aura;// 178740
    uint32 Vengeance_infernal_strike;// 189110
    uint32 Vengeance_throw_glaive;// 204157
    uint32 Vengeance_soul_cleave;// 228477
    uint32 Vengeance_sigil_of_flame;// 204596
    //CONTROL
    uint32 Vengeance_disrupt;// 183752
    uint32 Vengeance_sigil_of_silence;// 202137
    uint32 Vengeance_sigil_of_misery;// 207684

    uint32 Vengeance_demon_spikes;// 203720
    uint32 Vengeance_fiery_brand;// 204021
    uint32 Vengeance_soul_227225;// 227225 //talent
    uint32 Vengeance_metamorphosis;// 187827

    uint32 Vengeance_torment;// 185245
};


class BotMonkSpells
{
public:
    void InitializeSpells(Player* player);

protected:

    //TALENT_SPEC_MONK_BREWMASTER;
    //SINGEL
    uint32 BREWMASTER_tiger_palm;// 100780			
    uint32 BREWMASTER_blackout_strike;// 205523
    uint32 BREWMASTER_keg_smash;// 121253
    uint32 BREWMASTER_chi_wave;// 115098 //talent
    //AOE
    uint32 BREWMASTER_breath_of_fire;// 115181			
    uint32 BREWMASTER_rushing_jade_wind;// 116847
    //CONTROL		
    uint32 BREWMASTER_spear_hand_strike;// 116705			
    uint32 BREWMASTER_leg_sweep;// 119381  //talent
    //
    uint32 BREWMASTER_detox;// 218164
	//HEAL	
    uint32 BREWMASTER_HEAL_01;// 116694
    uint32 BREWMASTER_expel_harm;// 115072
	//
    uint32 BREWMASTER_fortifying_brew;// 115203			
    uint32 BREWMASTER_purifying_brew;// 119582				
    uint32 BREWMASTER_ironskin_brew;// 115308
    uint32 BREWMASTER_dampen_harm;// 122278 //talent

    uint32 BREWMASTER_provoke;// 115546 //pull
    uint32 BREWMASTER_resuscitate;// 115178 //reive


    //TALENT_SPEC_MONK_MISTWEAVER;
    //SINGEL
    uint32 MISTWEAVER_blackout_kick;// 100784
    uint32 MISTWEAVER_rising_sun_kick;// 107428
    uint32 MISTWEAVER_spinning_crane_kick;// 101546 // TALENT
    //AOE
    uint32 MISTWEAVER_chi_wave;// 115098
    //CONTROL
    uint32 MISTWEAVER_song_of_chi_ji;// 198898
    //
    uint32 MISTWEAVER_detox;// 115450
    //HEAL
    uint32 MISTWEAVER_renewing_mist;// 115151
    uint32 MISTWEAVER_enveloping_mist;// 124682
    uint32 MISTWEAVER_HEAL_01;// 116694
    uint32 MISTWEAVER_summon_jade_serpent_statue;// 115313 // talent
    //HEAL AOE
    uint32 MISTWEAVER_essence_font;// 191837
    uint32 MISTWEAVER_revival;// 115310
    uint32 MISTWEAVER_vivify;// 116670 //talent
    //FOR TANK
    uint32 MISTWEAVER_life_cocoon;// 116849
    //REIVE
    uint32 MISTWEAVER_resuscitate;// 115178
    uint32 MISTWEAVER_reawaken;// 212051


    //TALENT_SPEC_MONK_BATTLEDANCER;
    //SINGEL
    uint32 BATTLEDANCER_tiger_palm;// 100780          
    uint32 BATTLEDANCER_rising_sun_kick;// 107428
    uint32 BATTLEDANCER_touch_of_death;// 115080
    uint32 BATTLEDANCER_blackout_kick;// 100784
    uint32 BATTLEDANCER_chi_wave;// 115098 // talent
    uint32 BATTLEDANCER_invoke_xuen_the_white_tiger;// 123904 // talent

    //AOE
    uint32 BATTLEDANCER_fists_of_fury;// 113656        
    uint32 BATTLEDANCER_spinning_crane_kick;// 101546         
    uint32 BATTLEDANCER_whirling_dragon_punch;// 152175 // talent
           
    //CONTROL
    uint32 BATTLEDANCER_disable;// 116095
    uint32 BATTLEDANCER_leg_sweep;// 119381 // TALENT
    //  
    uint32 BATTLEDANCER_detox;// 218164
    //HEAL
    uint32 BATTLEDANCER_HEAL_01;// 116694
    //
    uint32 BATTLEDANCER_touch_of_karma;// 122470
    uint32 BATTLEDANCER_dampen_harm;// 122278 // talent
    //
    uint32 BATTLEDANCER_resuscitate;// 115178 //REIVE
         
  
    uint32 monk_roll;// 109132
};


#endif // !_BOT_AI_SPELLS_H_




/*


#ifndef _BOT_AI_SPELLS_H_
#define _BOT_AI_SPELLS_H_

#include "ScriptSystem.h"
#include "BotAITool.h"

class BotWarriorSpells
{
public:
    void InitializeSpells(Player* player);

protected:
   

    uint32 WarriorWeapon_Status = 122990;
    uint32 WarriorDefance_Status = 71;
    uint32 WarriorRage_Status = 122989;

    

    

    
};

class BotPaladinSpells
{
public:
    void InitializeSpells(Player* player);

protected:
   
};

class BotDeathknightSpells
{
public:
    void InitializeSpells(Player* player);

protected:
   

    
    
    uint32 DKAssist_RuneLife = 59754;// 48982		符文生命，转换能量为生命(鲜血系)
    uint32 DKAssist_BloodBrand = 206940;// 49005		鲜血印记，目标攻击的目标回血(鲜血系)
    uint32 DKAssist_BloodBuf = 55233;// 55233		死骑破釜沉舟(鲜血系)
    uint32 DKAssist_SummonRuneWeapon = 49028;// 49028	召唤符文武器，独立战斗(鲜血系)
    uint32 DKAssist_RuneWeapon = 47568;// 47568		激活全符文，25符文能量
    uint32 DKAssist_Infect = 91939;// 50842			目标的冰血疾病扩散传染
    uint32 DKAssist_RuneShunt = 7122;// 45529		活力分流 血符文转公共符文
    uint32 DKAssist_IceLock = 53534;// 45524		冰锁链，目标10秒内移动速度低
    uint32 DKAssist_DeadRevive = 121147;// 49895		死亡缠绕，攻击目标或者亡灵恢复
    uint32 DKAssist_NonFear = 49039;// 49039		变身，免疫恐惧魅惑(寒冰系)
    
    uint32 DKAssist_EatIce = 79092; //=79092// 49203			饥饿之寒，冰冻10码范围目标，非疾病伤害打断(寒冰系)
    uint32 DKAssist_PetPower = 49206;// 63560		食尸鬼狂乱(邪恶系)
    uint32 DKAssist_SummonFlyAtt = 49206;// 49206	召唤轰炸机(邪恶系)

   
   
    
};

class BotRogueSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 RogueGuard_Sneak = 1784;// 1784				潜行
    uint32 RogueGuard_ShadowCloak = 31224;// 31224		暗影斗篷
    uint32 RogueGuard_Disappear = 1856;// 26889		消失
    uint32 RogueGuard_Dodge = 248777;// 26669			闪躲
    uint32 RogueGuard_Sprint = 65864;// 11305			疾跑

    uint32 RogueSneak_Stick = 30980;// 51724			闷棍
    uint32 RogueSneak_Premeditate = 235777;// 14183		预谋(敏锐系)
    uint32 RogueSneak_Ambush = 8676;// 48691			伏击
    uint32 RogueSneak_Surprise = 1833;// 1833			偷袭

   
    
    

    uint32 RogueAOE_Knife = 51723;// 51723				刀刃飞舞
    uint32 RogueAOE_AllDance = 51723;// 51690			狂舞杀截(战斗系)

    uint32 RogueAttack_Blood = 65954;// 48660			出血(敏锐系)
    uint32 RogueAttack_Ghost = 123437;// 14278			鬼魅攻击(敏锐系) 攻击后+闪躲
    uint32 RogueAttack_Injure = 31022;// 48666			毁伤(刺杀系)
    uint32 RogueAttack_PoisonAtt = 76511;// 5938		毒刃
    uint32 RogueAttack_BackAtt = 53;// 48657			背刺
    

    uint32 RogueAttack_Damage = 196819;// 48668			剔骨
    uint32 RogueAttack_Separate = 1079;// 48672		割裂
    uint32 RogueAttack_Stun = 408;// 8643				肾击
    uint32 RogueAttack_PoisonDmg = 145416;// 57993		毒伤
    
    uint32 RogueRange_Throw = 158692;// 48674			致命投掷

    uint32 RogueFlag_Dance = 185313;// 51713				暗影之舞标记
};

class BotDruidSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 DruidIDLE_FerityWish = 24752;// 48469		野性祝福
    uint32 DruidIDLE_AOEFerityWish = 165754;// 48470		群体野性祝福
    uint32 DruidIDLE_Revive = 50769;// 50769			复活玩家
    uint32 DruidIDLE_CombatReive = 20484;// 20484		战斗复活玩家

    uint32 DruidStatus_Travel = 783;// 783			旅行形态
    uint32 DruidStatus_Bear = 5487;// 9634				巨熊形态
    uint32 DruidStatus_Cat = 768;// 768				猎豹形态
    uint32 DruidStatus_Bird = 24858;// 24858			枭兽形态(平衡系)
    uint32 DruidStatus_Tree = 33891;// 33891			奶树形态(恢复系)

    uint32 DruidGuard_Sneak = 5215;// 5215				猎豹潜行
    uint32 DruidGuard_Harden = 182872;// 22812			树皮术 免伤20%
    uint32 DruidGuard_Thorns = 209334;// 53307			荆棘术 攻击反伤
    uint32 DruidGuard_AutoTwine = 66071;// 53312		受击缠绕目标
    uint32 DruidGuard_Twine = 339;// 53308			缠绕目标
    uint32 DruidGuard_Control = 33786;// 33786			吹风 控制目标目标放逐
    uint32 DruidGuard_Pofu = 61336;// 61336				野性形态破釜沉舟(野性系)
    uint32 DruidGuard_TreeMan = 6913;// 33831			自然之力召唤树人(平衡系)

    uint32 DruidAssist_PersonSpirit = 13752;// 770		人形态精灵之火
    uint32 DruidAssist_BeastSpirit = 13752;// 16857		野性形态精灵之火
    uint32 DruidAssist_Active = 6950;// 29166			激活 目标回蓝
    uint32 DruidAssist_DecCruse = 30281;// 2782			德鲁伊解除诅咒
    uint32 DruidAssist_DecCruel = 14253;// 2893			德鲁伊解毒，BUF

    uint32 DruidCast_Moonfire = 65856;// 48463			月火 持续伤害技能
    uint32 DruidCast_Insect = 65855;// 48468			虫群 持续伤害技能(平衡系)
    uint32 DruidCast_Anger = 65862;// 48461				愤怒
    uint32 DruidCast_Spark = 98993;// 48465				星火 cast长

    uint32 DruidAOE_Hurricane = 55881;// 48467			飓风 AOE
    uint32 DruidAOE_Typhoon = 51817;// 61384			台风 AOE(平衡系)
    uint32 DruidAOE_FallStar = 100806;// 48505			群星坠落 AOE(平衡系)

    uint32 DruidHeal_Nourishing = 63556;// 50464		滋补术 小读秒加血 有持续治疗效果时加强
    uint32 DruidHeal_Relife = 774;// 48441			回春术 小持续加血
    uint32 DruidHeal_Coalescence = 66067;// 48443		愈合术 小加血
    uint32 DruidHeal_Touch = 5185;// 48378				治疗之触 大加血
    uint32 DruidHeal_LifeBurst = 57763;// 48451			生命绽放 持续效果结束时再加血
    uint32 DruidHeal_MergerLife = 18562;// 18562		迅捷治疗 吞并回春或愈合 加血(恢复系)
    uint32 DruidHeal_MomentHeal = 127316;// 17116		自然之握 nextHeal施法瞬发(恢复系)

    uint32 DruidHeal_AOETranquility = 740;// 48447		宁静
    uint32 DruidHeal_AOEFerity = 173170;// 53251			野性群体治疗(恢复系)

    uint32 DruidCat_Stun = 203123;// 49802				猫 击晕 终结技
    uint32 DruidCat_Bite = 22568;// 48577				猫 凶猛咬 立即伤害终结技
    uint32 DruidCat_Roar = 52610;// 52610				猫 咆哮 给自己加伤害力终结技
    uint32 DruidCat_Separate = 1943;// 49800			猫 割裂 持续伤害终结技

    uint32 DruidCat_Tiger = 5217;// 50213				猫 猛虎之怒 伤害BUF
    uint32 DruidCat_FastMove = 1850;// 33357			猫 疾跑
    uint32 DruidCat_Charge = 16979;// 49376				猫 冲锋(野性系)
    uint32 DruidCat_Surprise = 75008;// 49803			猫 潜行时第1击昏迷
    uint32 DruidCat_Sack = 201427;// 48579				猫 潜行时第1击伤害
    uint32 DruidCat_Claw = 91776;// 48570				猫 爪击
    uint32 DruidCat_BackStab = 5221;// 48572			猫 背刺
    uint32 DruidCat_Attack = 26103;// 62078				猫 挥击群攻
    uint32 DruidCat_Sweep = 1822;// 48574				猫 流血攻击
    uint32 DruidCat_Laceration = 19820;// 48566			猫 裂伤(野性系)

    uint32 DruidBear_DecAtt = 10968;// 48560			熊 减攻强吼
    uint32 DruidBear_AddPower = 8599;// 5229			熊 加怒气
    uint32 DruidBear_PowerLife = 22842;// 22842			熊 怒气回血
    uint32 DruidBear_Laceration = 22689;// 48564		熊 裂伤(野性系)
    uint32 DruidBear_Sweep = 61896;// 48568				熊 流血攻击
    uint32 DruidBear_Attack = 61598;// 48562			熊 挥击群攻
    uint32 DruidBear_NextAtt = 6807;// 48480			熊 Next攻击加强
    uint32 DruidBear_Stun = 1464;// 8983				熊 击晕
    uint32 DruidBear_Charge = 39435;// 16979			熊 冲锋(野性系)
};

class BotHunterSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 HunterIDLE_SummonPet = 23498;// 883			召唤宠物
    uint32 HunterIDLE_RevivePet = 982;// 982			复活宠物
    uint32 HunterIDLE_ManaAura = 210754;// 34074			攻击回蓝守护
    uint32 HunterIDLE_DodgeAura = 210753;// 13163		闪躲守护
    uint32 HunterIDLE_EagleAura = 231555;// 27044		射击守护
    uint32 HunterIDLE_DragonAura = 210752;// 61847		龙鹰守护 射击和闪躲守护
    uint32 HunterIDLE_ShotAura = 31519;// 19506			强击光环(射击系)

    uint32 HunterTrap_FarFrozen = 209789;// 60192		远程冰冻陷阱
    uint32 HunterTrap_Frozen = 43447;// 14311			冰冻陷阱
    uint32 HunterTrap_Ice = 165769;// 13809				冰霜陷阱
    uint32 HunterTrap_Viper = 43449;// 34600			毒蛇陷阱
    uint32 HunterTrap_Explode = 43444;// 49067			爆炸陷阱
    uint32 HunterTrap_Fire = 155623;// 49056				火焰陷阱
    uint32 HunterTrap_Shot = 80003;// 63672				黑浊箭(生存系)

    uint32 HunterAssist_ClearRoot = 53271;// 53271		移除定身
    uint32 HunterAssist_PetCommand = 205440;// 34026		宠物杀截
    uint32 HunterAssist_HealPet = 37381;// 48990		宠物治疗
    uint32 HunterAssist_PetStun = 7093;// 19577		宠物击晕目标(野兽系)
    uint32 HunterAssist_PetRage = 19574;// 19574		宠物和自己狂暴(野兽系)
    
    uint32 HunterAssist_FalseDead = 5384;// 5384		假死
    uint32 HunterAssist_BackJump = 781;// 781			后跳
    
    uint32 HunterAssist_ReadyCD = 203551;// 23989		准备就绪CD(射击系)
    uint32 HunterAssist_Mislead = 34477;// 34477		误导

    
    uint32 HunterMelee_NoDamage = 31567;// 19263		威慑 无法攻击
    uint32 HunterMelee_DecSpeed = 195645;// 2974			摔拌 近战减移动速
    uint32 HunterMelee_NextAtt = 31566;// 48996			next近战攻击加强
    uint32 HunterMelee_MeleeAtt = 190928;// 53339		近战攻击

    

    
    uint32 HunterShot_CharmShot = 23601;// 19503		打断射击(生存系)
    uint32 HunterShot_Explode = 15495;// 60053			爆炸射击(生存系)
    uint32 HunterShot_Aim = 48871;// 49050				瞄准射击(射击系)
    uint32 HunterShot_Silence = 248919;// 34490			沉默射击(射击系)
    uint32 HunterShot_Shock = 5116;// 5116				震荡射击
    uint32 HunterShot_Cast = 65867;// 49052				稳固射击 施法时间的射击
    uint32 HunterShot_MgcShot = 69989;// 49045			奥术射击
    
    uint32 HunterShot_MulShot = 2643;// 49048			多重射击
    uint32 HunterShot_QMLShot = 53209;// 53209			奇美拉射击(射击系)
};

class BotShamanSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 ShamanIDLE_LifeWeapon = 32911;// 51994		生命武器
    uint32 ShamanIDLE_IceWeapon = 78273;// 58796		冰霜武器
    uint32 ShamanIDLE_FireWeapon = 160098;// 58790		火焰武器
    uint32 ShamanIDLE_PhyWeapon = 159974;// 10399		石化武器
    uint32 ShamanIDLE_FastWeapon = 32911;// 58804		风怒武器
    uint32 ShamanIDLE_Revive = 2008;// 49277			复活玩家

    uint32 ShamanShield_Earth = 226078;// 49284			大地之盾(恢复系)
    uint32 ShamanShield_Water = 79949;// 57960			水之盾
    uint32 ShamanShield_Lightning = 20545;// 49281		闪电之盾

    uint32 ShamanAssist_Frog = 11641;// 51514			变形青蛙
    uint32 ShamanAssist_HealCrit = 137531;// 55198		next3几率治疗暴击(恢复系)
    uint32 ShamanAssist_MomentHeal = 127316;// 16188		nextHeal施法瞬发(恢复系)
    uint32 ShamanAssist_MomentCast = 16166;// 16166		nextCast施法瞬发(元素系)
    uint32 ShamanAssist_BlockCast = 52870;// 57994		打断施法
    uint32 ShamanAssist_Cleansing = 370;// 8012		净化目标2个BUFF
    uint32 ShamanAssist_FireNova = 11969;// 61657		让火焰图腾AOE一次
    uint32 ShamanAssist_Heroic = 32182;// 32182			萨满英勇
    uint32 ShamanAssist_DecCruel = 14253;// 526			萨满解毒 解疾病

    uint32 ShamanAtt_StormStrike = 17364;// 17364		风暴打击(增强系)
    uint32 ShamanAtt_FireStrike = 60103;// 60103		熔岩打击(增强系)

    uint32 ShamanCast_LightningArrow = 218013;// 49238	闪电箭
    uint32 ShamanCast_LightningChain = 190332;// 49271	闪电链
    uint32 ShamanCast_LightningStorm = 71935;// 59159	闪电风暴(元素系)
    uint32 ShamanCast_FireThud = 23038;// 49233			火焰震击
    uint32 ShamanCast_IceThud = 22582;// 49236			冰霜震击
    uint32 ShamanCast_EarthThud = 43305;// 49231		大地震击
    uint32 ShamanCast_FireStrike = 58972;// 60043		熔岩打击 远程法术

    uint32 ShamanHealth_Fast = 71985;// 49276			快速治疗
    uint32 ShamanHealth_Bast = 253330;// 49273			大力治疗
    uint32 ShamanHealth_Chain = 237925;// 55459			治疗链
    uint32 ShamanHealth_Torrent = 237920;// 61301		激流 瞬发小治疗+持续治疗(恢复系)
    uint32 ShamanDispel_Refine = 234893;// 51886			驱散

    uint32 ShamanTotem_Recycle = 5394;// 36936			回收图腾

    uint32 ShamanTotem_Life = 35199;// 58757			生命图腾
    uint32 ShamanTotem_Mana = 24854;// 58774			法力图腾
    uint32 ShamanTotem_BMana = 24854;// 16190			大法力图腾

    uint32 ShamanTotem_SummonFire = 27623;// 2894		召唤火元素图腾
    uint32 ShamanTotem_MgcPower = 31985;// 57722		法术能量图腾(元素系)
    uint32 ShamanTotem_Attack = 38116;// 58704			自主火焰攻击图腾
    uint32 ShamanTotem_AOEAttack = 39591;// 58734		自主火焰群攻图腾
    uint32 ShamanTotem_MgcHeal = 31633;// 58656			法术能量和治疗效果图腾

    uint32 ShamanTotem_DecMove = 51485;// 2484			减移动速度图腾
    uint32 ShamanTotem_SummonSoil = 73903;// 2062		召唤土元素图腾
    uint32 ShamanTotem_PhyPower = 65992;// 58643		力量敏捷图腾
    uint32 ShamanTotem_Armor = 73393;// 58753			护甲图腾

    uint32 ShamanTotem_AbsorbBuff = 148819;// 8177		吸收有害BUFF图腾
    uint32 ShamanTotem_AttSpeed = 27621;// 8512			近战攻击速度图腾
    uint32 ShamanTotem_MgcSpeed = 27621;// 3738			法术施法速度图腾

    uint32 ShamanFlag_NoHeroic = 27621;// 57723			无法give英勇状态标识
};

class BotMageSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 MageIDLE_ManaGem = 36883;// 42985		法力宝石
    uint32 MageIDLE_ArcaneMagic = 13326;// 42995	奥术智慧
    uint32 MageIDLE_AOEArcaneMagic = 129171;// 43002	全体奥术智慧
    uint32 MageIDLE_MgcArmor = 164309;// 43024		魔甲术
    uint32 MageIDLE_FrostArmor = 79563;// 43008		冰甲术
    uint32 MageIDLE_IceArmor = 165743;// 7301		霜甲术
    uint32 MageIDLE_FireArmor = 35915;// 43046		火焰装甲
    uint32 MageIDLE_MagicAdd = 70408;// 43017		魔法增效
    uint32 MageIDLE_MagicDec = 44475;// 43015		魔法压制
    uint32 MageIDLE_SummonRite = 43987;// 58659		召唤餐桌

    uint32 MageGuard_MagicShield = 56778;// 43020	法力护盾
    uint32 MageGuard_FrostShield = 201565;// 43039	寒冰护盾
    uint32 MageGuard_FrostScherm = 41590;// 45438	寒冰屏障
    uint32 MageGuard_FrostNova = 64919;// 42917		寒冰新星
    uint32 MageGuard_FireBreath = 31661;// 42950	龙之吐息
    uint32 MageGuard_FireNova = 11969;// 42945		火焰新星

    uint32 MageAssist_Mirror = 166894;// 55342		法师镜像
    uint32 MageAssist_Rouse = 12051;// 12051		唤醒
    uint32 MageAssist_Stealth = 66;// 66			隐形术
    uint32 MageAssist_Teleport = 14514;// 1953		闪现术
    uint32 MageAssist_DecCurse = 15729;// 475		解除诅咒
    uint32 MageAssist_Grace = 29976;// 12043		气定神闲
    uint32 MageAssist_ArcanePower = 12042;// 12042	奥术强化
    uint32 MageAssist_CastSpeed = 12472;// 12472	冰冷血脉
    uint32 MageAssist_FastColddown = 235219;// 11958	重置冰系技能CD
    uint32 MageAssist_FrostPet = 31687;// 31687		召唤水元素
    uint32 MageAssist_FireCritAura = 19428;// 11129	主动3次增加火焰暴击AURA

    uint32 MageConfine_BreakCast = 29443;// 2139	法术反制
    uint32 MageConfine_AuraSteal = 30449;// 30449	BUFF偷取
    uint32 MageConfine_ArcaneSlow = 246;// 31589	奥术缓速
    uint32 MageConfine_ToSheep = 118;// 12826		变羊
    uint32 MageConfine_Freeze = 79130;// 44572		冻结被冰冻的目标

    uint32 MageAOE_ArcaneExplode = 9433;// 42921	奥术爆炸
    uint32 MageAOE_Snowstorm = 15783;// 42940		暴风雪
    uint32 MageAOE_IcePiton = 12557;// 42931		冰锥术
    uint32 MageAOE_FireStorm = 13899;// 42926		火焰风暴

    uint32 MageArcane_Barrage = 44425;// 44781		奥术弹幕
    uint32 MageArcane_Bullet = 5143;// 42846		奥术飞弹
    uint32 MageArcane_ArcaneShock = 16067;// 42897	奥术冲击

    uint32 MageFrost_IceArrow = 9672;// 42842		寒冰箭
    uint32 MageFrost_IceLance = 43571;// 42914		冰枪
    uint32 MageFrost_FFArrow = 70616;// 47610		霜火箭

    uint32 MageFire_FireArrow = 133;// 42833		火球术
    uint32 MageFire_FireShock = 15574;// 42873		火焰冲击
    uint32 MageFire_Firing = 2948;// 42859			灼烧
    uint32 MageFire_BigFireBall = 33051;// 42891	大火球
    uint32 MageFire_FireBomb = 178551;// 55360		活体炸弹

    uint32 MagePet_FrostNova = 40875;// 33395		水宝宝寒冰新星

    uint32 MageFlag_FireStun = 201565;// 64343		Aura:可以火冲昏迷
    uint32 MageFlag_FastFStorm = 201565;// 54741		Aura:火焰风暴瞬发
    uint32 MageFlag_FastBFBall = 201565;// 48108		Aura:瞬发大火球
    uint32 MageFlag_FastFFArrow = 201565;// 57761	Aura:瞬发霜火箭
    uint32 MageFlag_CanFrozen = 201565;// 74396		Aura:目标当成被冰冻状态
    uint32 MageFlag_Scherm = 201565;// 45438			Aura:冰箱状态中
};

class BotWarlockSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 WarlockIDLE_LowArmor = 20798;// 696			低级护甲
    uint32 WarlockIDLE_Armor = 13787;// 47889			中级护甲
    uint32 WarlockIDLE_HighArmor = 44520;// 47893		高级护甲
    uint32 WarlockIDLE_SoulLink = 79957;// 19028		宠物灵魂链接(恶魔系)
    uint32 WarlockIDLE_ShadowShield = 53915;// 47891		暗影盾
    uint32 WarlockIDLE_SummonFireDemon = 688;// 688	召唤小鬼
    uint32 WarlockIDLE_SummonHollowDemon = 697;// 697	召唤虚空
    uint32 WarlockIDLE_SummonSuccubus = 712;// 712		召唤魅魔
    uint32 WarlockIDLE_SummonDogDemon = 691;// 691		召唤猎犬
    uint32 WarlockIDLE_SummonGuardDemon = 30146;// 30146	召唤地狱守卫
    uint32 WarlockIDLE_FastSummon = 53915;// 18708		快速召唤(恶魔系)
    uint32 WarlockIDLE_OpenGate = 48018;// 48018		开启传送法阵
    uint32 WarlockIDLE_TeleGate = 48020;// 48020		瞬移到传送法阵
    uint32 WarlockIDLE_SummonRite = 60429;// 29893		灵魂仪式

    uint32 WarlockDemon_ToDemon = 54840;// 47241		变身大恶魔
    uint32 WarlockDemon_Charge = 104205;// 54785			恶魔冲锋
    uint32 WarlockDemon_MeleeAOE = 215559;// 50581		恶魔顺劈斩
    uint32 WarlockDemon_Sacrifice = 192502;// 50589		恶魔献祭

    uint32 WarlockAssist_DemonPower = 193396;// 47193		强化召唤的恶魔(恶魔系)
    uint32 WarlockAssist_ExtractMana = 108416;// 59092	宠物身上抽蓝(痛苦系)
    uint32 WarlockAssist_ConvertMana = 1454;// 57946	生命分流 血转蓝
    uint32 WarlockAssist_StealLife = 12693;// 47857		吸取生命
    uint32 WarlockAssist_StealMana = 17008;// 5138		吸取法力
    uint32 WarlockAssist_BaseFear = 12096;// 6215		恐惧术
    uint32 WarlockAssist_FastFear = 6789;// 47860		死亡缠绕
    uint32 WarlockAssist_AOEFear = 5484;// 17928		群体恐惧术

    uint32 WarlockAOE_MeleeFire = 22539;// 61290		近战前方AOE
    uint32 WarlockAOE_RainFire = 16005;// 47820			火焰雨AOE
    uint32 WarlockAOE_ShadowRage = 39082;// 47847		暗影之怒AOE群体昏迷(毁灭系)

    uint32 WarlockCurse_UpDmg = 79956;// 47865			元素伤害提高诅咒
    uint32 WarlockCurse_MoveLow = 29539;// 18223		疲劳诅咒 移动速度降低(痛苦系)
    uint32 WarlockCurse_MgcDmg = 14868;// 47864			痛苦诅咒 DOT伤害
    uint32 WarlockCurse_MeleeLow = 8552;// 50511		虚弱诅咒 攻强降低
    uint32 WarlockCurse_CastLow = 12889;// 11719		语言诅咒 施法时间延迟

    uint32 WarlockDot_LeechSoul = 48181;// 59164		浊魂术(痛苦系)
    uint32 WarlockDot_HighDmg = 30108;// 47843			痛苦动荡(痛苦系)
    uint32 WarlockDot_LowDmg = 172;// 47813			腐竹术
    uint32 WarlockDot_AOEDmg = 32863;// 47836			腐竹种子 dot后范围伤害
    uint32 WarlockDot_Sacrifice = 15505;// 47811		毁灭献祭

    uint32 WarlockCast_ShadowArrow = 9613;// 47809		暗影之箭
    uint32 WarlockCast_ShadowShock = 131792;// 47827		暗影冲击24码(毁灭系)
    uint32 WarlockCast_ChaosArrow = 79939;// 59172		混乱之箭(毁灭系)
    uint32 WarlockCast_FullBurn = 41960;// 47838		燃尽 有献祭时加强效果(毁灭系)
    uint32 WarlockCast_FireBurn = 19428;// 17962		焚烧 消耗献祭(毁灭系)
    uint32 WarlockCast_BigFireBall = 131381;// 47825		灵魂大火球

    uint32 WarlockPetDemon_Charge = 225417;// 47996		恶魔pet冲锋
    uint32 WarlockPetDemon_Melee = 161703;// 47994		恶魔pet顺劈斩
    uint32 WarlockPetDog_MagicBuf = 69994;// 57567		猎犬pet团队BUF
    uint32 WarlockPetDog_EatMgc = 19505;// 48011		猎犬pet吞食魔法
    uint32 WarlockPetDog_Bite = 138750;// 54053			猎犬pet咬人
    uint32 WarlockPetDog_Silence = 67519;// 19647		猎犬pet沉默
    uint32 WarlockPetSuccubus_Lash = 15968;// 47992		魅魔pet鞭打
    uint32 WarlockPetSuccubus_Sneak = 12845;// 7870		魅魔pet潜行
    uint32 WarlockPetSuccubus_Charm = 36241;// 6358		魅魔pet魅惑
    uint32 WarlockPetGhost_Shield = 18968;// 47983		小鬼pet火盾
    uint32 WarlockPetGhost_Sneak = 169009;// 4511		小鬼pet潜行
    uint32 WarlockPetGhost_Stamp = 244189;// 47982		小鬼pet血印记
    uint32 WarlockPetGhost_FireArrow = 9057;// 47964	小鬼pet火焰箭

    uint32 WarlockFlag_SoulItem = 6265;// 6265			灵魂碎片道具
    uint32 WarlockFlag_SoulLink = 79957;// 25228		宠物灵魂链接BUF
    uint32 WarlockFlag_OpenGate = 48018;// 48018		传送法阵BUF
    uint32 WarlockFlag_Sacrifice = 223061;// 50589		恶魔献祭BUF
};

class BotPriestSpells
{
public:
    void InitializeSpells(Player* player);

protected:
    uint32 PriestIDLE_AllHardRes = 43939;// 48162			全体坚韧
    uint32 PriestIDLE_HardRes = 23948;// 48161				单体坚韧
    uint32 PriestIDLE_SoulFire = 48168;// 48168				心灵之火
    uint32 PriestIDLE_AllSpiritRes = 43939;// 48074			全体精神
    uint32 PriestIDLE_SpiritRes = 23948;// 48073			单体精神
    uint32 PriestIDLE_Bloodsucker = 15286;// 15286			吸血鬼拥抱
    uint32 PriestIDLE_AllShadowRes = 53915;// 48170			全体暗影抗性
    uint32 PriestIDLE_ShadowRes = 53915;// 48169			单体暗影抗性
    uint32 PriestIDLE_ShadowStatus = 16592;// 15473			暗影形态
    uint32 PriestIDLE_Revive = 2006;// 48171				复活玩家

    uint32 PriestGuard_ShadowFear = 34984;// 64044			单体恐惧(暗影系)
    uint32 PriestGuard_AOEFear = 8122;// 10890				近战范围群恐惧
    uint32 PriestGuard_DefFear = 65544;// 6346				反恐惧结界
    uint32 PriestGuard_RecoverMana = 65544;// 47585			暗影回蓝和免伤(暗影系)
    uint32 PriestGuard_DmgAnnul = 33206;// 33206			痛苦压制(戒律系)
    uint32 PriestGuard_DefShield = 17;// 48066			真言术 盾
    uint32 PriestGuard_SelfHealth = 19236;// 48173			绝望祷言 自己瞬间治疗(神圣系)
    uint32 PriestGuard_GuardSoul = 47788;// 47788			灵魂守护 target死亡时守护(神圣系)

    uint32 PriestAssist_SoulAbs = 196762;// 14751			心灵专注next0耗蓝(戒律系)
    uint32 PriestAssist_AddHolyPower = 10060;// 10060		能力注入target施法急速和暴击(戒律系)
    uint32 PriestAssist_AllDispel = 4526;// 32375			全体驱散魔法
    uint32 PriestAssist_Dispel = 528;// 988				单体驱散魔法
    uint32 PriestAssist_ShadowDemon = 10060;// 34433			暗影恶魔
    uint32 PriestAssist_Silence = 8988;// 15487			暗影沉默(暗影系)
    uint32 PriestAssist_AllResMana = 64843;// 64901			引导全体回蓝
    uint32 PriestAssist_AllResLife = 64843;// 64843			引导全体回血
    uint32 PriestAssist_DecIllness = 3592;// 552			单体驱散疾病，BUF

    uint32 PriestDebuf_Ache = 11639;// 48125				痛
    uint32 PriestDebuf_Drown = 41375;// 48158				灭
    uint32 PriestDebuf_Plague = 138490;// 48300				瘟疫

    uint32 PriestAOE_ShadowExplode = 32000;// 53023			暗影爆炸AOE(暗影系)
    uint32 PriestAOE_HolyNova = 20694;// 48078				神圣新星

    uint32 PriestShadow_ShadowTouch = 18152;// 48160			吸血之触(暗影系)
    uint32 PriestShadow_Knocking = 17194;// 48127			心灵震爆
    uint32 PriestShadow_Lech = 15407;// 48156				精神鞭挞(暗影系)
    uint32 PriestHoly_Smite = 585;// 48123				惩击
    uint32 PriestHoly_BigFire = 17141;// 48135				神圣之火
    uint32 PriestPrecept_ManaBurn = 2691;// 8129			法力燃烧

    uint32 PriestHeal_ZeroHeal = 29170;// 2050				次级治疗
    uint32 PriestHeal_LowHeal = 8812;// 6064				低级治疗
    uint32 PriestHeal_Resume = 27606;// 48068				恢复
    uint32 PriestHeal_FastHeal = 27608;// 48071				快速治疗
    uint32 PriestHeal_BigHeal = 34119;// 48063				大治疗
    uint32 PriestHeal_LinkHeal = 32546;// 48120				链接自己和目标治疗
    uint32 PriestHeal_UnionHeal = 225275;// 48113			愈合祷言 target next heal
    uint32 PriestHeal_RingHeal = 49306;// 48089				治疗之环(神圣系)
    uint32 PriestHeal_AOEHeal = 596;// 48072				治疗祷言 aoe heal
    uint32 PriestHeal_Awareness = 47540;// 53007			觉悟 引导3个治疗子弹治疗目标(戒律系)

    uint32 PriestFlag_DeadSoul = 20711;// 27827				救赎之魂 神牧死亡后
    uint32 PriestFlag_NonShield = 6788;// 6788				真言盾DEBUFF
};

#endif // !_BOT_AI_SPELLS_H_

*/
