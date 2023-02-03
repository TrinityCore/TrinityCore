
#ifndef _BOT_AI_SPELLS_H_
#define _BOT_AI_SPELLS_H_

#include "ScriptSystem.h"
#include "BotAITool.h"

class BotWarriorSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 WarriorIDLE_AOEAddLife;// = 47440;			// ????
	uint32 WarriorIDLE_AOEAddPower;// = 47436;			// ????

	uint32 WarriorWeapon_Status;// = 2457;
	uint32 WarriorDefance_Status;// = 71;
	uint32 WarriorRage_Status;// = 2458;

	uint32 WarriorCommon_PowerAtt;// = 47450;			// ????
	uint32 WarriorCommon_PowerThrow;// = 57755;			// ????
	uint32 WarriorCommon_PowerRelife;// = 55694;		// ????(????????)
	uint32 WarriorCommon_ClearCtrl;// = 18499;			// ????(????)
	uint32 WarriorCommon_AOEFear;// = 5246;			// ???????
	uint32 WarriorCommon_SweepAtt;// = 47520;			// ???
	uint32 WarriorCommon_AddPower;// = 2687;			// ???
	uint32 WarriorCommon_AOEDecPower;// = 47437;		// ??????

	uint32 WarriorDefance_HPojia;// = 47498;			// ????
	uint32 WarriorDefance_Fuchou;// = 57823;			// ??
	uint32 WarriorDefance_ShieldBlock;// = 2565;		// ????
	uint32 WarriorDefance_ShieldAtt;// = 47488;			// ????
	uint32 WarriorDefance_Pojia;// = 7386;				// ??
	uint32 WarriorDefance_MaxLife;// = 12975;			// ????
	uint32 WarriorDefance_ShiledWall;// = 871;			// ??
	uint32 WarriorDefance_Disarm;// = 676;				// ??
	uint32 WarriorDefance_Support;// = 3411;			// ??
	uint32 WarriorDefance_Conk;// = 12809;				// ????
	uint32 WarriorDefance_AOEConk;// = 46968;			// ??????
	uint32 WarriorDefance_Pull;// = 355;				// ??

	uint32 WarriorWeapon_SwordStorm;// = 46924;			// ????
	uint32 WarriorWeaponDefance_AOEAtt;// = 47502;		// ????
	uint32 WarriorWeaponDefance_Bleed;// = 47465;		// ??
	uint32 WarriorWeaponDefance_SpellReflect;// = 23920;	// ????
	uint32 WarriorWeaponDefance_ShieldHit;// = 72;		// ??(????)

	uint32 WarriorWeapon_HighThrow;// = 64382;			// ?????
	uint32 WarriorWeapon_Charge;// = 11578;			// ??
	uint32 WarriorWeapon_Suppress;// = 7384;			// ??
	uint32 WarriorWeapon_Backstorm;// = 20230;			// ????
	uint32 WarriorWeapon_DeadAtt;// = 47486;			// ????

	uint32 WarriorWeaponRage_FullKill;// = 47471;		// ??
	uint32 WarriorWeaponRage_WinAttack;// = 34428;		// ????
	uint32 WarriorWeaponRage_Backfillet;// = 1715;		// ??

	uint32 WarriorRage_Harsh;// = 12323;				// ????
	uint32 WarriorRage_HeadAtt;// = 6552;				// ??(????)
	uint32 WarriorRage_Intercept;// = 20252;			// ??
	uint32 WarriorRage_Whirlwind;// = 1680;			// ???
	uint32 WarriorRage_Impertinency;// = 1719;			// ??
	uint32 WarriorRage_Needdead;// = 12292;			// ????
	uint32 WarriorRage_Bloodthirsty;// = 23881;			// ??
	uint32 WarriorRage_ReIntercept;// = 60970;			// ???????????CD
};

class BotPaladinSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 PaladinIDLE_MountAura;// 32223			??????
	uint32 PaladinIDLE_CastAura;// 19746			????
	uint32 PaladinIDLE_JudgeAura;// 54043			????
	uint32 PaladinIDLE_ArmorAura;// 48942			????
	uint32 PaladinIDLE_AOEGuardWish;// 25899			??????(???)
	uint32 PaladinIDLE_GuardWish;// 20911			????(???)
	uint32 PaladinIDLE_AOEKingWish;// 25898			??????
	uint32 PaladinIDLE_KingWish;// 20217			????
	uint32 PaladinIDLE_AOEWitWish;// 48938			??????
	uint32 PaladinIDLE_WitWish;// 48936				????
	uint32 PaladinIDLE_AOEStrWish;// 48934			??????
	uint32 PaladinIDLE_StrWish;// 48932				????
	uint32 PaladinIDLE_JusticeRage;// 25780			???? ????
	uint32 PaladinIDLE_Revive;// 48950				????

	uint32 PaladinGuard_UnShield;// 53601			????
	uint32 PaladinGuard_FreeAura;// 1044			????
	uint32 PaladinGuard_Invincible;// 642			??? ??
	uint32 PaladinGuard_Sacrifice;// 6940			???? ??????
	uint32 PaladinGuard_AOESacrifice;// 64205		???? ??????(???)
	uint32 PaladinGuard_BlockShield;// 48952			????(???)
	uint32 PaladinGuard_PhyImmune;// 10278			??????
	uint32 PaladinGuard_Pull;// 62124				??

	uint32 PaladinAssist_UpPower;// 31884			??? UP??
	uint32 PaladinAssist_RevengeStamp;// 31801		???? ??5?????
	uint32 PaladinAssist_LifeStamp;// 20165			???? ????
	uint32 PaladinAssist_ManaStamp;// 20166			???? ????
	uint32 PaladinAssist_JusticeStamp;// 21084		???? ????
	uint32 PaladinAssist_StunStamp;// 20164			???? ??????
	uint32 PaladinAssist_ComStamp;// 20375			???? ????(???)
	uint32 PaladinAssist_Confession;// 20066			?? ??(???)
	uint32 PaladinAssist_StunMace;// 10308			???? ??
	uint32 PaladinAssist_ReviveMana;// 54428			??BUF
	uint32 PaladinAssist_HealCrit;// 20216			next????(???)
	uint32 PaladinAssist_LowMana;// 31842			??????(???)
	uint32 PaladinAssist_AuraUP;// 31821			??????BUF(???)
	uint32 PaladinAssist_Dispel;// 4987				??????

	uint32 PaladinHeal_FastHoly;// 48785			????
	uint32 PaladinHeal_BigHoly;// 48782				???
	uint32 PaladinHeal_FullHoly;// 48788			??

	uint32 PaladinMelee_AOEOffertory;// 48819		??
	uint32 PaladinMelee_KillMace;// 48806			???? ????20%?
	uint32 PaladinMelee_FlyShield;// 48827			????(???)
	uint32 PaladinMelee_ShieldAtt;// 61411			????(???)
	uint32 PaladinMelee_MaceAtt;// 53595			????(???)
	uint32 PaladinMelee_HolyAtt;// 48825			????(???)
	uint32 PaladinMelee_LifeJudge;// 20271			????
	uint32 PaladinMelee_ManaJudge;// 53408			????
	uint32 PaladinMelee_FleeJudge;// 53407			????
	uint32 PaladinMelee_WeaponAtt;// 35395			?????(???)
	uint32 PaladinMelee_HolyStrom;// 53385			????(???)

	uint32 PaladinFlag_MomentHoly;// 59578			???? ????
	uint32 PaladinFlag_Discipline;// 25771			?? DEBUFF
};

class BotDeathknightSpells
{
public:
	void InitializeSpells(Player* player);

protected:
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

    uint32 DKAssist_BloodBuf;// 55233		吸血鬼之血 (鲜血系)
    uint32 DKAssist_SummonRuneWeapon;// 49028	召唤符文武器，独立战斗(鲜血系)
    uint32 DKAssist_RuneWeapon;// 47568		符文武器增效 激活全符文，25符文能量
    uint32 DKAssist_Infect;// 50842			血液沸腾 目标的冰血疾病扩散传染
    uint32 DKAssist_RuneShunt;// 45529		活力分流 血符文转公共符文
    uint32 DKAssist_IceLock;// 45524		冰锁链，目标10秒内移动速度低
    uint32 DKAssist_DeadRevive;// 47541		死亡缠绕，攻击目标或者亡灵恢复

    uint32 DKAssist_PetPower;// 63560		黑暗突变 食尸鬼狂乱(邪恶系)
    uint32 DKAssist_SummonFlyAtt;// 49206	召唤石像鬼 轰炸机(邪恶系)

    uint32 DKAttack_AreaAOE;// 43265		枯萎凋零，指定范围AOE
    uint32 DKAttack_BloodAtt;// 49998		灵界打击，有疾病时伤害UP
    uint32 DKAttack_ShadowAtt;// 85948		脓疮打击，血疾病
    uint32 DKAttack_FrostAtt;// 49143		冰霜打击(寒冰系)
    uint32 DKAttack_RuneAttack;// 49020		湮灭
    uint32 DKAttack_IceWindAtt;// 49184		冰风冲击(寒冰系)
    uint32 DKAttack_CorpseExplosion;// 77575	爆发(邪恶系)
    uint32 DKAttack_NaturalAtt;// 55090		天灾打击(邪恶系)
    uint32 DKAttack_CoreAtt;// 206930		心脏打击(鲜血系)
    uint32 DKAttack_Deaths_caress;// 195292 死神的抚摩
};

class BotRogueSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 RogueGuard_Sneak;// 1784				??
	uint32 RogueGuard_ShadowCloak;// 31224		暗影斗篷
	uint32 RogueGuard_Disappear;// 26889		??
	uint32 RogueGuard_Dodge;// 5277			    闪避
	uint32 RogueGuard_Sprint;// 11305			??

	uint32 RogueSneak_Stick;// 6770			    闷棍
	uint32 RogueSneak_Premeditate;// 14183		预谋 TO DO
	uint32 RogueSneak_Ambush;// 8676			伏击
	uint32 RogueSneak_Surprise;// 1833			偷袭

	uint32 RogueAssist_ShadowDance;// 185313	暗影之舞(敏锐)
	uint32 RogueAssist_ShadowFlash;// 36554		???(???)
	uint32 RogueAssist_ReadyCD;// 14185			??(???)
	uint32 RogueAssist_Blind;// 2094			致盲
	uint32 RogueAssist_Disarm;// 51722			??
	uint32 RogueAssist_NextCrit;// 79140		宿敌(刺杀)
	uint32 RogueAssist_blood;// 51662			?? ???????(???)
	uint32 RogueAssist_FastEnergy;// 13750		冲动(狂徒)
	uint32 RogueAssist_BlockCast;// 1766		脚踢 打断施法
	uint32 RogueAssist_Paralyze;// 1776			?? ????
	uint32 RogueAssist_FastSpeed;// 13877		?????20(???)

	uint32 RogueAOE_Knife;// 51723				刀扇(刺杀)
	uint32 RogueAOE_AllDance;// 193315			军刀猛刺(狂徒)

	uint32 RogueAttack_Blood;// 212283			死亡符记(敏锐) +40能量
	uint32 RogueAttack_Ghost;// 195452 			夜刃(敏锐) 终结技
	uint32 RogueAttack_Injure;// 1329			毁伤(刺杀)
	uint32 RogueAttack_PoisonAtt;// 5938		??
	uint32 RogueAttack_BackAtt;// 53			背刺

	uint32 RogueAttack_Damage;// 48668			??
	uint32 RogueAttack_Separate;// 48672		??
	uint32 RogueAttack_Stun;// 8643				??
	uint32 RogueAttack_PoisonDmg;// 57993		??
	uint32 RogueAttack_Incision;// 6774			??(???????)
	uint32 RogueRange_Throw;// 48674			????

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

	uint32 DruidStatus_Travel;// 783			????
	uint32 DruidStatus_Bear;// 5487				????
	uint32 DruidStatus_Cat;// 768				????
	uint32 DruidStatus_Bird;// 24858			????(???)
	uint32 DruidStatus_Tree;// 33891			????(???)

    uint32 DruidGuard_Thrash;// 77758          痛击
    uint32 DruidGuard_Swipe;//213764            横扫
	uint32 DruidGuard_Sneak;// 5215				猎豹潜行
	uint32 DruidGuard_Harden;// 22812			树皮术 免伤20%
	//uint32 DruidGuard_Thorns;// 53307			荆棘术 攻击反伤
	//uint32 DruidGuard_AutoTwine;// 53312		受击缠绕目标
	uint32 DruidGuard_Twine;// 339			缠绕目标
	
	uint32 DruidGuard_Pofu;// 61336				野性形态破釜沉舟(野性系)
	uint32 DruidGuard_TreeMan;// 205636			自然之力召唤树人(平衡系)

	//uint32 DruidAssist_PersonSpirit;// 770		人形态精灵之火
	//uint32 DruidAssist_BeastSpirit;// 16857		野性形态精灵之火
	uint32 DruidAssist_Active;// 29166			激活 目标回蓝
	uint32 DruidAssist_DecCruse;// 2782			德鲁伊解除诅咒
	uint32 DruidAssist_DecCruel;// 2782			德鲁伊解毒，BUF

	uint32 DruidCast_Moonfire;// 48463			月火 持续伤害技能
	uint32 DruidCast_Insect;// 93402			日炎 持续伤害技能(平衡系)
	uint32 DruidCast_Anger;// 48461				愤怒
	uint32 DruidCast_Spark;// 48465				星火 cast长
    //uint32 DruidGuard_Control;// 209753			吹风 平衡 控制目标目标放逐

	//uint32 DruidAOE_Hurricane;// 48467			飓风 AOE
	//uint32 DruidAOE_Typhoon;// 61384			台风 AOE(平衡系)
	uint32 DruidAOE_FallStar;// 191034			群星坠落 AOE(平衡系)

    //uint32 DruidHeal_Nourishing;// 50464		滋补术 小读秒加血 有持续治疗效果时加强
    uint32 DruidHeal_Relife;// 774			回春术 小持续加血
    uint32 DruidHeal_Coalescence;// 8936		愈合术 小加血
    uint32 DruidHeal_Touch;// 5185				治疗之触 大加血
    uint32 DruidHeal_LifeBurst;// 33763			生命绽放 持续效果结束时再加血
    uint32 DruidHeal_MergerLife;// 18562		迅捷治疗 吞并回春或愈合 加血(恢复系)
    //uint32 DruidHeal_MomentHeal;// 17116		自然之握 nextHeal施法瞬发(恢复系)
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
    //uint32 DruidCat_Surprise;// 1822			猫 斜掠 潜行时第1击昏迷
    uint32 DruidCat_Sack;// 5221				猫 潜行时第1击伤害
    uint32 DruidCat_Claw;// 1822				猫 撕碎
    //uint32 DruidCat_BackStab;// 48572			猫 背刺
    uint32 DruidCat_Attack;// 106785			猫 横扫群攻
    uint32 DruidCat_Sweep;// 106830				猫 痛击
    //uint32 DruidCat_Laceration;// 48566			猫 裂伤(野性系)

    uint32 DruidBear_DecAtt;// 192081			熊 铁鬃
    //uint32 DruidBear_AddPower;// 5229			熊 加怒气
    uint32 DruidBear_PowerLife;// 22842			熊 怒气回血
    uint32 DruidBear_Laceration;// 33917		熊 裂伤(野性系)
    //uint32 DruidBear_Sweep;// 48568			熊 流血攻击
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

    uint32 HunterDebug_Sleep;// 49012			沉睡钉刺(生存系)

    uint32 HunterShot_CharmShot;// 187707		压制(生存系)
    uint32 HunterShot_Explode;// 60053			爆炸射击(生存系)
    uint32 HunterShot_Aim;// 49050				瞄准射击(射击系)
    uint32 HunterShot_Silence;// 147362			反制射击(射击系)
    uint32 HunterShot_Shock;// 5116				震荡射击
    uint32 HunterShot_Cast;// 49052				稳固射击 施法时间的射击
    uint32 HunterShot_MgcShot;// 49045			奥术射击
    uint32 HunterShot_MulShot;// 2643			多重射击
    uint32 HunterShot_QMLShot;// 53209			奇美拉射击(射击系)
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
	uint32 ShamanIDLE_LifeWeapon;// 51994		????
	uint32 ShamanIDLE_IceWeapon;// 58796		????
	uint32 ShamanIDLE_FireWeapon;// 58790		????
	uint32 ShamanIDLE_PhyWeapon;// 10399		????
	uint32 ShamanIDLE_FastWeapon;// 58804		????
	uint32 ShamanIDLE_Revive;// 49277			????

	uint32 ShamanShield_Earth;// 49284			????(???)
	uint32 ShamanShield_Water;// 57960			???
	uint32 ShamanShield_Lightning;// 49281		????

	uint32 ShamanAssist_Frog;// 51514			????
	uint32 ShamanAssist_HealCrit;// 55198		next3??????(???)
	uint32 ShamanAssist_MomentHeal;// 16188		nextHeal????(???)
	uint32 ShamanAssist_MomentCast;// 16166		nextCast????(???)
	uint32 ShamanAssist_BlockCast;// 57994		????
	uint32 ShamanAssist_Cleansing;// 8012		????2?BUFF
	uint32 ShamanAssist_FireNova;// 61657		?????AOE??
	uint32 ShamanAssist_Heroic;// 32182			????
	uint32 ShamanAssist_DecCruel;// 526			???? ???

	uint32 ShamanAtt_StormStrike;// 17364		????(???)
	uint32 ShamanAtt_FireStrike;// 60103		????(???)

	uint32 ShamanCast_LightningArrow;// 49238	???
	uint32 ShamanCast_LightningChain;// 49271	???
	uint32 ShamanCast_LightningStorm;// 59159	????(???)
	uint32 ShamanCast_FireThud;// 49233			????
	uint32 ShamanCast_IceThud;// 49236			????
	uint32 ShamanCast_EarthThud;// 49231		????
	uint32 ShamanCast_FireStrike;// 60043		???? ????

	uint32 ShamanHealth_Fast;// 49276			????
	uint32 ShamanHealth_Bast;// 49273			????
	uint32 ShamanHealth_Chain;// 55459			???
	uint32 ShamanHealth_Torrent;// 61301		?? ?????+????(???)
	uint32 ShamanDispel_Refine;// 51886			??

	uint32 ShamanTotem_Recycle;// 36936			????

	uint32 ShamanTotem_Life;// 58757			????
	uint32 ShamanTotem_Mana;// 58774			????
	uint32 ShamanTotem_BMana;// 16190			?????

	uint32 ShamanTotem_SummonFire;// 2894		???????
	uint32 ShamanTotem_MgcPower;// 57722		??????(???)
	uint32 ShamanTotem_Attack;// 58704			????????
	uint32 ShamanTotem_AOEAttack;// 58734		????????
	uint32 ShamanTotem_MgcHeal;// 58656			???????????

	uint32 ShamanTotem_DecMove;// 2484			???????
	uint32 ShamanTotem_SummonSoil;// 2062		???????
	uint32 ShamanTotem_PhyPower;// 58643		??????
	uint32 ShamanTotem_Armor;// 58753			????

	uint32 ShamanTotem_AbsorbBuff;// 8177		????BUFF??
	uint32 ShamanTotem_AttSpeed;// 8512			????????
	uint32 ShamanTotem_MgcSpeed;// 3738			????????

	uint32 ShamanFlag_NoHeroic;// 57723			??give??????
};

class BotMageSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 MageIDLE_ManaGem;// 42985		????
	uint32 MageIDLE_ArcaneMagic;// 42995	????
	uint32 MageIDLE_AOEArcaneMagic;// 43002	??????
	uint32 MageIDLE_MgcArmor;// 43024		???
	uint32 MageIDLE_FrostArmor;// 43008		???
	uint32 MageIDLE_IceArmor;// 7301		???
	uint32 MageIDLE_FireArmor;// 43046		????
	uint32 MageIDLE_MagicAdd;// 43017		????
	uint32 MageIDLE_MagicDec;// 43015		????
	uint32 MageIDLE_SummonRite;// 58659		????

	uint32 MageGuard_MagicShield;// 43020	????
	uint32 MageGuard_FrostShield;// 43039	????
	uint32 MageGuard_FrostScherm;// 45438	????
	uint32 MageGuard_FrostNova;// 42917		????
	uint32 MageGuard_FireBreath;// 42950	????
	uint32 MageGuard_FireNova;// 42945		????

	uint32 MageAssist_Mirror;// 55342		????
	uint32 MageAssist_Rouse;// 12051		??
	uint32 MageAssist_Stealth;// 66			???
	uint32 MageAssist_Teleport;// 1953		???
	uint32 MageAssist_DecCurse;// 475		????
	uint32 MageAssist_Grace;// 12043		????
	uint32 MageAssist_ArcanePower;// 12042	????
	uint32 MageAssist_CastSpeed;// 12472	????
	uint32 MageAssist_FastColddown;// 11958	??????CD
	uint32 MageAssist_FrostPet;// 31687		?????
	uint32 MageAssist_FireCritAura;// 11129	??3???????AURA

	uint32 MageConfine_BreakCast;// 2139	????
	uint32 MageConfine_AuraSteal;// 30449	BUFF??
	uint32 MageConfine_ArcaneSlow;// 31589	????
	uint32 MageConfine_ToSheep;// 12826		??
	uint32 MageConfine_Freeze;// 44572		????????

	uint32 MageAOE_ArcaneExplode;// 42921	????
	uint32 MageAOE_Snowstorm;// 42940		???
	uint32 MageAOE_IcePiton;// 42931		???
	uint32 MageAOE_FireStorm;// 42926		????

	uint32 MageArcane_Barrage;// 44781		????
	uint32 MageArcane_Bullet;// 42846		????
	uint32 MageArcane_ArcaneShock;// 42897	????

	uint32 MageFrost_IceArrow;// 42842		???
	uint32 MageFrost_IceLance;// 42914		??
	uint32 MageFrost_FFArrow;// 47610		???

	uint32 MageFire_FireArrow;// 42833		???
	uint32 MageFire_FireShock;// 42873		????
	uint32 MageFire_Firing;// 42859			??
	uint32 MageFire_BigFireBall;// 42891	???
	uint32 MageFire_FireBomb;// 55360		????

	uint32 MagePet_FrostNova;// 33395		???????

	uint32 MageFlag_FireStun;// 64343		Aura:??????
	uint32 MageFlag_FastFStorm;// 54741		Aura:??????
	uint32 MageFlag_FastBFBall;// 48108		Aura:?????
	uint32 MageFlag_FastFFArrow;// 57761	Aura:?????
	uint32 MageFlag_CanFrozen;// 74396		Aura:?????????
	uint32 MageFlag_Scherm;// 45438			Aura:?????
};

class BotWarlockSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 WarlockIDLE_LowArmor;// 696			????
	uint32 WarlockIDLE_Armor;// 47889			????
	uint32 WarlockIDLE_HighArmor;// 47893		????
	uint32 WarlockIDLE_SoulLink;// 19028		??????(???)
	uint32 WarlockIDLE_ShadowShield;// 47891		???
	uint32 WarlockIDLE_SummonFireDemon;// 688	小鬼
	uint32 WarlockIDLE_SummonHollowDemon;// 697	虚空行者
	uint32 WarlockIDLE_SummonSuccubus;// 712		魅魔
	uint32 WarlockIDLE_SummonDogDemon;// 691		地狱猎犬
	uint32 WarlockIDLE_SummonGuardDemon;// 30146	恐惧卫士
	uint32 WarlockIDLE_FastSummon;// 18708		????(???)
	uint32 WarlockIDLE_OpenGate;// 48018		??????
	uint32 WarlockIDLE_TeleGate;// 48020		???????
	uint32 WarlockIDLE_SummonRite;// 29893		????

	uint32 WarlockDemon_ToDemon;// 47241		?????
	uint32 WarlockDemon_Charge;// 104316		召唤猎犬
	uint32 WarlockDemon_MeleeAOE;// 193440		恶魔之怒
	uint32 WarlockDemon_Sacrifice;// 50589		????

	uint32 WarlockAssist_DemonPower;// 47193		???????(???)
	uint32 WarlockAssist_ExtractMana;// 59092	??????(???)
	uint32 WarlockAssist_ConvertMana;// 57946	???? ???
	uint32 WarlockAssist_StealLife;// 47857		????
	uint32 WarlockAssist_StealMana;// 198590	吸取灵魂
	uint32 WarlockAssist_BaseFear;// 6215		???
	uint32 WarlockAssist_FastFear;// 6789		死亡缠绕
	uint32 WarlockAssist_AOEFear;// 17928		?????

	uint32 WarlockAOE_MeleeFire;// 61290		????AOE
	uint32 WarlockAOE_RainFire;// 47820			???AOE
	uint32 WarlockAOE_ShadowRage;// 193440		恶魔之怒 重复

	uint32 WarlockCurse_UpDmg;// 47865			????????
	uint32 WarlockCurse_MoveLow;// 18223		???? ??????(???)
	uint32 WarlockCurse_MgcDmg;// 47864			???? DOT??
	uint32 WarlockCurse_MeleeLow;// 50511		???? ????
	uint32 WarlockCurse_CastLow;// 11719		???? ??????

	uint32 WarlockDot_LeechSoul;// 980		    痛楚(痛苦)
	uint32 WarlockDot_HighDmg;// 30108			痛苦无常(痛苦)
	uint32 WarlockDot_LowDmg;// 172			    腐蚀术
	uint32 WarlockDot_AOEDmg;// 27243			腐蚀之种
	uint32 WarlockDot_Sacrifice;// 348		    献祭

	uint32 WarlockCast_ShadowArrow;// 47809		????
	uint32 WarlockCast_ShadowShock;// 47827		????24?(???)
	uint32 WarlockCast_ChaosArrow;// 59172		????(???)
	uint32 WarlockCast_FullBurn;// 29722		烧尽
	uint32 WarlockCast_FireBurn;// 17962		燃烧
	uint32 WarlockCast_BigFireBall;// 105174	古尔丹之手

	uint32 WarlockPetDemon_Charge;// 47996		??pet??
	uint32 WarlockPetDemon_Melee;// 47994		??pet???
	uint32 WarlockPetDog_MagicBuf;// 57567		??pet??BUF
	uint32 WarlockPetDog_EatMgc;// 48011		??pet????
	uint32 WarlockPetDog_Bite;// 54053			??pet??
	uint32 WarlockPetDog_Silence;// 19647		??pet??
	uint32 WarlockPetSuccubus_Lash;// 47992		??pet??
	uint32 WarlockPetSuccubus_Sneak;// 7870		??pet??
	uint32 WarlockPetSuccubus_Charm;// 6358		??pet??
	uint32 WarlockPetGhost_Shield;// 47983		??pet??
	uint32 WarlockPetGhost_Sneak;// 4511		??pet??
	uint32 WarlockPetGhost_Stamp;// 47982		??pet???
	uint32 WarlockPetGhost_FireArrow;// 47964	??pet???

	uint32 WarlockFlag_SoulItem;// 6265			??????
	uint32 WarlockFlag_SoulLink;// 25228		??????BUF
	uint32 WarlockFlag_OpenGate;// 48018		????BUF
	uint32 WarlockFlag_Sacrifice;// 50589		????BUF
};

class BotPriestSpells
{
public:
	void InitializeSpells(Player* player);

protected:
	uint32 PriestIDLE_AllHardRes;// 48162			????
	uint32 PriestIDLE_HardRes;// 48161				????
	uint32 PriestIDLE_SoulFire;// 48168				????
	uint32 PriestIDLE_AllSpiritRes;// 48074			????
	uint32 PriestIDLE_SpiritRes;// 48073			????
	uint32 PriestIDLE_Bloodsucker;// 15286			?????
	uint32 PriestIDLE_AllShadowRes;// 48170			??????
	uint32 PriestIDLE_ShadowRes;// 48169			??????
	uint32 PriestIDLE_ShadowStatus;// 15473			????
	uint32 PriestIDLE_Revive;// 48171				????

	uint32 PriestGuard_ShadowFear;// 64044			????(???)
	uint32 PriestGuard_AOEFear;// 10890				???????
	uint32 PriestGuard_DefFear;// 6346				?????
	uint32 PriestGuard_RecoverMana;// 47585			???????(???)
	uint32 PriestGuard_DmgAnnul;// 33206			????(???)
	uint32 PriestGuard_DefShield;// 48066			??? ?
	uint32 PriestGuard_SelfHealth;// 48173			???? ??????(???)
	uint32 PriestGuard_GuardSoul;// 47788			???? target?????(???)

	uint32 PriestAssist_SoulAbs;// 14751			????next0??(???)
	uint32 PriestAssist_AddHolyPower;// 10060		????target???????(???)
	uint32 PriestAssist_AllDispel;// 32375			??????
	uint32 PriestAssist_Dispel;// 988				??????
	uint32 PriestAssist_ShadowDemon;// 34433			????
	uint32 PriestAssist_Silence;// 15487			????(???)
	uint32 PriestAssist_AllResMana;// 64901			??????
	uint32 PriestAssist_AllResLife;// 64843			??????
	uint32 PriestAssist_DecIllness;// 552			??????,BUF

	uint32 PriestDebuf_Ache;// 48125				?
	uint32 PriestDebuf_Drown;// 48158				?
	uint32 PriestDebuf_Plague;// 48300				??

	uint32 PriestAOE_ShadowExplode;// 53023			????AOE(???)
	uint32 PriestAOE_HolyNova;// 48078				????

	uint32 PriestShadow_ShadowTouch;// 48160			????(???)
	uint32 PriestShadow_Knocking;// 48127			????
	uint32 PriestShadow_Lech;// 48156				????(???)
	uint32 PriestHoly_Smite;// 48123				??
	uint32 PriestHoly_BigFire;// 48135				????
	uint32 PriestPrecept_ManaBurn;// 8129			????

	uint32 PriestHeal_ZeroHeal;// 2050				????
	uint32 PriestHeal_LowHeal;// 6064				????
	uint32 PriestHeal_Resume;// 48068				??
	uint32 PriestHeal_FastHeal;// 48071				????
	uint32 PriestHeal_BigHeal;// 48063				???
	uint32 PriestHeal_LinkHeal;// 48120				?????????
	uint32 PriestHeal_UnionHeal;// 48113			???? target next heal
	uint32 PriestHeal_RingHeal;// 48089				????(???)
	uint32 PriestHeal_AOEHeal;// 48072				???? aoe heal
	uint32 PriestHeal_Awareness;// 53007			?? ??3?????????(???)

	uint32 PriestFlag_DeadSoul;// 27827				???? ?????
	uint32 PriestFlag_NonShield;// 6788				???DEBUFF
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
