
#ifndef _BOT_DRUID_AI_H
#define _BOT_DRUID_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

//enum DruidTalentType  
//{
//    DruidTalent_Balance,
//    DruidTalent_Ferity,
//    DruidTalent_Revive
//};

class BotDruidAI : public BotBGAI
{
public:
    BotDruidAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0)
    {}
    ~BotDruidAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    uint32 GetEnergyPowerPer();
    uint32 GetRagePowerPer();
    void InitializeSpells();
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessArenaHealthMember();

    bool ProcessSneak();
    void ProcessBearCombat(Unit* pTarget);
    void ProcessCatCombat(Unit* pTarget);
    void ProcessBalanceCombat(Unit* pTarget);
    bool ProcessActive();

    bool CastingControlCommandSpell() override;
    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool CanMeleeHealthMe();
    bool CanConsumeCombo(Unit* pTarget);
    bool TargetHasMechanic(Unit* pTarget);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool HasEnergyStore();
    void UpEnergy();
    void UpPower();
    void UpMana();
    void SwitchStatus(uint32 status);
    bool CanAttackSpell();
    bool ProcessControl(Unit* pTarget);

    void OnCastSneak();
    void OnCastCharge(Unit* pTarget);

private:
    uint32 m_BotTalentType;

    uint32 DruidIDLE_AOEFerityWish;// 48470		群体野性祝福

    uint32 DruidStatus_Travel;// 783			旅行形态
    uint32 DruidStatus_Bear;// 9634				巨熊形态
    uint32 DruidStatus_Cat;// 768				猎豹形态
    uint32 DruidStatus_Bird;// 24858			枭兽形态(平衡系)
    uint32 DruidStatus_Tree;// 33891			奶树形态(恢复系)

    uint32 DruidGuard_Sneak;// 5215				猎豹潜行
    uint32 DruidGuard_Harden;// 22812			树皮术 免伤20%
    uint32 DruidGuard_Thorns;// 53307			荆棘术 攻击反伤
    uint32 DruidGuard_AutoTwine;// 53312		受击缠绕目标
    uint32 DruidGuard_Twine;// 53308			缠绕目标
    uint32 DruidGuard_Control;// 33786			吹风 控制目标目标放逐
    uint32 DruidGuard_Pofu;// 61336				野性形态破釜沉舟(野性系)
    uint32 DruidGuard_TreeMan;// 33831			自然之力召唤树人(平衡系)

    uint32 DruidAssist_PersonSpirit;// 770		人形态精灵之火
    uint32 DruidAssist_BeastSpirit;// 16857		野性形态精灵之火
    uint32 DruidAssist_Active;// 29166			激活 目标回蓝

    uint32 DruidCast_Moonfire;// 48463			月火 持续伤害技能
    uint32 DruidCast_Insect;// 48468			虫群 持续伤害技能(平衡系)
    uint32 DruidCast_Anger;// 48461				愤怒
    uint32 DruidCast_Spark;// 48465				星火 cast长

    uint32 DruidAOE_Hurricane;// 48467			飓风 AOE
    uint32 DruidAOE_Typhoon;// 61384			台风 AOE(平衡系)
    uint32 DruidAOE_FallStar;// 48505			群星坠落 AOE(平衡系)

    uint32 DruidHeal_Nourishing;// 50464		滋补术 小读秒加血 有持续治疗效果时加强
    uint32 DruidHeal_Relife;// 48441			回春术 小持续加血
    uint32 DruidHeal_Coalescence;// 48443		愈合术 小加血
    uint32 DruidHeal_Touch;// 48378				治疗之触 大加血
    uint32 DruidHeal_LifeBurst;// 48451			生命绽放 持续效果结束时再加血
    uint32 DruidHeal_MergerLife;// 18562		迅捷治疗 吞并回春或愈合 加血(恢复系)
    uint32 DruidHeal_MomentHeal;// 17116		自然之握 nextHeal施法瞬发(恢复系)

    uint32 DruidHeal_AOETranquility;// 48447		宁静
    uint32 DruidHeal_AOEFerity;// 53251			野性群体治疗(恢复系)

    uint32 DruidCat_Stun;// 49802				猫 击晕 终结技
    uint32 DruidCat_Bite;// 48577				猫 凶猛咬 立即伤害终结技
    uint32 DruidCat_Roar;// 52610				猫 咆哮 给自己加伤害力终结技
    uint32 DruidCat_Separate;// 49800			猫 割裂 持续伤害终结技

    uint32 DruidCat_Tiger;// 50213				猫 猛虎之怒 伤害BUF
    uint32 DruidCat_FastMove;// 33357			猫 疾跑
    uint32 DruidCat_Charge;// 49376				猫 冲锋(野性系)
    uint32 DruidCat_Surprise;// 49803			猫 潜行时第1击昏迷
    uint32 DruidCat_Sack;// 48579				猫 潜行时第1击伤害
    uint32 DruidCat_Claw;// 48570				猫 爪击
    uint32 DruidCat_BackStab;// 48572			猫 背刺
    uint32 DruidCat_Attack;// 62078				猫 挥击群攻
    uint32 DruidCat_Sweep;// 48574				猫 流血攻击
    uint32 DruidCat_Laceration;// 48566			猫 裂伤(野性系)

    uint32 DruidBear_DecAtt;// 48560			熊 减攻强吼
    uint32 DruidBear_AddPower;// 5229			熊 加怒气
    uint32 DruidBear_PowerLife;// 22842			熊 怒气回血
    uint32 DruidBear_Laceration;// 48564		熊 裂伤(野性系)
    uint32 DruidBear_Sweep;// 48568				熊 流血攻击
    uint32 DruidBear_Attack;// 48562			熊 挥击群攻
    uint32 DruidBear_NextAtt;// 48480			熊 Next攻击加强
    uint32 DruidBear_Stun;// 8983				熊 击晕
    uint32 DruidBear_Charge;// 16979			熊 冲锋(野性系)
};

#endif // !_BOT_DRUID_AI_H
