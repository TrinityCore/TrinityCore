
#ifndef _BOT_PALADIN_AI_H
#define _BOT_PALADIN_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum PaladinTalentType
{
    PaladinTalent_Holy,
    PaladinTalent_Defance,
    PaladinTalent_Punish
};

class BotPaladinAI : public BotBGAI
{
public:
    BotPaladinAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0)
    {}
    ~BotPaladinAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializeSpells();
    void UpdateTalentType();
    void EachTick() override;
    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;
    bool ProcessArenaHealthMember();

    bool ProcessStamp();
    bool ProcessDispel();
    bool ProcessAura();
    bool ProcessControl(Unit* pTarget);
    bool ProcessFreeAura();
    bool ProcessTryFriendImmune();
    bool ProcessTryFullHealth();

    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool TargetNeedInvincible(Unit* player);
    bool TargetNeedFree(Unit* player);
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool NeedUseGuardWish(Player* player);
    bool NeedUseKingWish(Player* player);
    bool NeedUseWitWish(Player* player);
    bool NeedUseStrWish(Player* player);
    bool ExistWish(Unit* player);
    bool TargetIsCtrl(Unit* pTarget);

private:
    uint32 m_BotTalentType;

    uint32 PaladinIDLE_MountAura;// 32223			坐骑速度光环
    uint32 PaladinIDLE_CastAura;// 19746			施法光环
    uint32 PaladinIDLE_JudgeAura;// 54043			惩戒光环
    uint32 PaladinIDLE_ArmorAura;// 48942			防御光环
    uint32 PaladinIDLE_AOEGuardWish;// 25899			群体庇护祝福(防御系)
    uint32 PaladinIDLE_AOEKingWish;// 25898			群体王者祝福
    uint32 PaladinIDLE_AOEWitWish;// 48938			群体智慧祝福
    uint32 PaladinIDLE_AOEStrWish;// 48934			群体力量祝福
    uint32 PaladinIDLE_JusticeRage;// 25780			正义之怒 防骑使用

    uint32 PaladinGuard_UnShield;// 53601			崇圣护盾
    uint32 PaladinGuard_FreeAura;// 1044			自由祝福
    uint32 PaladinGuard_Invincible;// 642			圣盾术 无敌
    uint32 PaladinGuard_Sacrifice;// 6940			牺牲之手 目标受伤转移
    uint32 PaladinGuard_AOESacrifice;// 64205		神圣牺牲 团队受伤转移(防御系)
    uint32 PaladinGuard_BlockShield;// 48952			神圣格挡(防御系)
    uint32 PaladinGuard_PhyImmune;// 10278			目标物理免疫

    uint32 PaladinAssist_UpPower;// 31884			开翅膀 UP伤害
    uint32 PaladinAssist_RevengeStamp;// 31801		复仇圣印 叠加5层伤害提高
    uint32 PaladinAssist_LifeStamp;// 20165			光明圣印 攻击回血
    uint32 PaladinAssist_ManaStamp;// 20166			智慧圣印 攻击回蓝
    uint32 PaladinAssist_JusticeStamp;// 21084		正义圣印 攻击提高
    uint32 PaladinAssist_StunStamp;// 20164			公正圣印 攻击几率昏迷
    uint32 PaladinAssist_ComStamp;// 20375			命令圣印 攻击加强(惩戒系)
    uint32 PaladinAssist_Confession;// 20066			忏悔 控制(惩戒系)
    uint32 PaladinAssist_StunMace;// 10308			制裁之锤 昏迷
    uint32 PaladinAssist_ReviveMana;// 54428			回蓝BUF
    uint32 PaladinAssist_HealCrit;// 20216			next治疗暴击(神圣系)
    uint32 PaladinAssist_LowMana;// 31842			法术耗蓝降低(神圣系)
    uint32 PaladinAssist_AuraUP;// 31821			光环效果加强BUF(神圣系)
    uint32 PaladinAssist_Dispel;// 4987				驱散魔法中毒

    uint32 PaladinHeal_FastHoly;// 48785			圣光闪现
    uint32 PaladinHeal_BigHoly;// 48782				圣光术
    uint32 PaladinHeal_FullHoly;// 48788			圣疗

    uint32 PaladinMelee_AOEOffertory;// 48819		奉献
    uint32 PaladinMelee_KillMace;// 48806			斩杀之锤 目标低于20%血
    uint32 PaladinMelee_FlyShield;// 48827			弹射飞盾(防御系)
    uint32 PaladinMelee_ShieldAtt;// 61411			盾牌打击(防御系)
    uint32 PaladinMelee_MaceAtt;// 53595			正义之锤(防御系)
    uint32 PaladinMelee_HolyAtt;// 48825			神圣震击(神圣系)
    uint32 PaladinMelee_LifeJudge;// 20271			光明审判
    uint32 PaladinMelee_ManaJudge;// 53408			智慧审判
    uint32 PaladinMelee_FleeJudge;// 53407			公正审判
    uint32 PaladinMelee_WeaponAtt;// 35395			十字军打击(惩戒系)
    uint32 PaladinMelee_HolyStrom;// 53385			神圣风暴(惩戒系)

    uint32 PaladinFlag_MomentHoly;// 59578			战争艺术 瞬发圣闪
    uint32 PaladinFlag_Discipline;// 25771			自律 DEBUFF
};

#endif // !_BOT_PALADIN_AI_H
