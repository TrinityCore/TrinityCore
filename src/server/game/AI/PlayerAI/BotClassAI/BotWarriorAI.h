
#ifndef _BOT_WARRIOR_AI_H_
#define _BOT_WARRIOR_AI_H_

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum WarriorTalentType
{
    WarriorTalent_Weapon,
    WarriorTalent_Defance,
    WarriorTalent_Rage
};

class BotWarriorAI : public BotBGAI
{
public:
    BotWarriorAI(Player* player) :
        BotBGAI(player),
        m_NeedPuniness(-1),
        m_BotTalentType(0),
        m_ChargeWaitTick(0),
        m_IsIDLEBuff(false)
    {}
    ~BotWarriorAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetRagePowerPer();
    void EachTick() override;
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void InitializeSpells();
    void UpdateTalentType();
    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    void UpdateWarriorPose();

    void ProcessWeaponRangeSpell(Unit* pTarget);
    void ProcessRageRangeSpell(Unit* pTarget);
    void ProcessDefanceRangeSpell(Unit* pTarget);
    void ProcessWeaponMeleeSpell(Unit* pTarget);
    void ProcessRageMeleeSpell(Unit* pTarget);
    void ProcessDefanceMeleeSpell(Unit* pTarget);
    bool ProcessSurviveSpell();
    bool ProcessFullAttack(Unit* pTarget);
    void OnCastCharge(Unit* pTarget);

private:
    int32 m_NeedPuniness;
    uint32 m_BotTalentType;
    int32 m_ChargeWaitTick;
    bool m_IsIDLEBuff;

    uint32 WarriorIDLE_AOEAddLife;// = 47440;			// 命令怒吼
    uint32 WarriorIDLE_AOEAddPower;// = 47436;			// 攻强怒吼

    uint32 WarriorWeapon_Status;// = 2457;
    uint32 WarriorDefance_Status;// = 71;
    uint32 WarriorRage_Status;// = 2458;

    uint32 WarriorCommon_PowerAtt;// = 47450;			// 英勇打击
    uint32 WarriorCommon_PowerThrow;// = 57755;			// 英勇投掷
    uint32 WarriorCommon_PowerRelife;// = 55694;		// 狂怒恢复（有狂暴时使用回血）
    uint32 WarriorCommon_ClearCtrl;// = 18499;			// 狂暴之怒（移除控制）
    uint32 WarriorCommon_AOEFear;// = 5246;			// 近战范围群恐惧
    uint32 WarriorCommon_SweepAtt;// = 47520;			// 顺劈斩
    uint32 WarriorCommon_AddPower;// = 2687;			// 加怒气
    uint32 WarriorCommon_AOEDecPower;// = 47437;		// 群体减攻强吼

    uint32 WarriorDefance_HPojia;// = 47498;			// 毁灭打击
    uint32 WarriorDefance_Fuchou;// = 57823;			// 复仇
    uint32 WarriorDefance_ShieldBlock;// = 2565;		// 盾牌格挡
    uint32 WarriorDefance_ShieldAtt;// = 47488;			// 盾牌猛击
    uint32 WarriorDefance_Pojia;// = 7386;				// 破甲
    uint32 WarriorDefance_MaxLife;// = 12975;			// 破釜沉舟
    uint32 WarriorDefance_ShiledWall;// = 871;			// 盾墙
    uint32 WarriorDefance_Disarm;// = 676;				// 缴械
    uint32 WarriorDefance_Support;// = 3411;			// 援助
    uint32 WarriorDefance_Conk;// = 12809;				// 单体击晕
    uint32 WarriorDefance_AOEConk;// = 46968;			// 前方范围击晕

    uint32 WarriorWeaponDefance_AOEAtt;// = 47502;		// 雷霆一击
    uint32 WarriorWeaponDefance_Bleed;// = 47465;		// 撕裂
    uint32 WarriorWeaponDefance_SpellReflect;// = 23920;	// 法术反射
    uint32 WarriorWeaponDefance_ShieldHit;// = 72;		// 盾击（施法打断）

    uint32 WarriorWeapon_SwordStorm;// = 46924;			// 剑刃风暴
    uint32 WarriorWeapon_HighThrow;// = 64382;			// 破无敌投掷
    uint32 WarriorWeapon_Charge;// = 11578;			// 冲锋
    uint32 WarriorWeapon_Suppress;// = 7384;			// 压制
    uint32 WarriorWeapon_Backstorm;// = 20230;			// 反击风暴
    uint32 WarriorWeapon_DeadAtt;// = 47486;			// 致死打击

    uint32 WarriorWeaponRage_FullKill;// = 47471;		// 斩杀
    uint32 WarriorWeaponRage_WinAttack;// = 34428;		// 乘胜追击
    uint32 WarriorWeaponRage_Backfillet;// = 1715;		// 断筋

    uint32 WarriorRage_Harsh;// = 12323;				// 刺耳怒吼
    uint32 WarriorRage_HeadAtt;// = 6552;				// 拳击（施法打断）
    uint32 WarriorRage_Intercept;// = 20252;			// 拦截
    uint32 WarriorRage_Whirlwind;// = 1680;			// 旋风斩
    uint32 WarriorRage_Impertinency;// = 1719;			// 鲁莽
    uint32 WarriorRage_Needdead;// = 12292;			// 死亡之愿
    uint32 WarriorRage_Bloodthirsty;// = 23881;			// 嗜血
    uint32 WarriorRage_ReIntercept;// = 60970;			// 解除移动限制和解除拦截CD
};

#endif // !_BOT_WARRIOR_AI_H_
