
#ifndef _BOT_WARLOCK_AI_H
#define _BOT_WARLOCK_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

//enum WarlockTalentType    //Duplicate in BotAI.h
//{
//    HunterTalent_Pain,
//    HunterTalent_Demon,
//    HunterTalent_Ruin
//};

class BotWarlockAI : public BotBGAI
{
public:
    BotWarlockAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_IsInitedPetSpells(false),
        m_IsSummonPeted(false),
        m_LastAOEDotTick(0),
        m_GatePos(),
        m_LastCharmTarget(ObjectGuid::Empty),
        m_LastCharmTick(0)
    {}
    ~BotWarlockAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializeSpells();
    void InitializePetSpells();
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessPetSpell(Unit* pTarget, bool fleeing);

    bool CastingControlCommandSpell() override;
    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool ProcessGate(Unit* pTarget, bool onlyBuild);
    bool ProcessMana(bool isMoveing);
    bool ProcessDot(Unit* pTarget, bool canCastTime);
    bool ProcessFear(Unit* pTarget);
    void PetAction(Pet* pPet, Unit* pTarget);
    bool TargetIsFear(Unit* pTarget);
    void OnCastTeleGate();
    void InsureSoulItem();
    uint32 TryCastSummonRiteSpell() override;

private:
    uint32 m_BotTalentType;
    bool m_IsInitedPetSpells;
    uint32 m_LastAOEDotTick;
    Position m_GatePos;
    bool m_IsSummonPeted;
    ObjectGuid m_LastCharmTarget;
    uint32 m_LastCharmTick;

    uint32 WarlockIDLE_LowArmor;// 696			低级护甲
    uint32 WarlockIDLE_Armor;// 47889			中级护甲
    uint32 WarlockIDLE_HighArmor;// 47893		高级护甲
    uint32 WarlockIDLE_SoulLink;// 19028		宠物灵魂链接(恶魔系)
    uint32 WarlockIDLE_ShadowShield;// 47891		暗影盾
    uint32 WarlockIDLE_SummonFireDemon;// 688	召唤小鬼
    uint32 WarlockIDLE_SummonHollowDemon;// 697	召唤虚空
    uint32 WarlockIDLE_SummonSuccubus;// 712		召唤魅魔
    uint32 WarlockIDLE_SummonDogDemon;// 691		召唤猎犬
    uint32 WarlockIDLE_SummonGuardDemon;// 30146	召唤地狱守卫
    uint32 WarlockIDLE_FastSummon;// 18708		快速召唤(恶魔系)
    uint32 WarlockIDLE_OpenGate;// 48018		开启传送法阵
    uint32 WarlockIDLE_TeleGate;// 48020		瞬移到传送法阵
    uint32 WarlockIDLE_SummonRite;// 29893		灵魂仪式

    uint32 WarlockDemon_ToDemon;// 47241		变身大恶魔
    uint32 WarlockDemon_Charge;// 54785			恶魔冲锋
    uint32 WarlockDemon_MeleeAOE;// 50581		恶魔顺劈斩
    uint32 WarlockDemon_Sacrifice;// 50589		恶魔献祭

    uint32 WarlockAssist_DemonPower;// 47193		强化召唤的恶魔(恶魔系)
    uint32 WarlockAssist_ExtractMana;// 59092	宠物身上抽蓝(痛苦系)
    uint32 WarlockAssist_ConvertMana;// 57946	生命分流 血转蓝
    uint32 WarlockAssist_StealLife;// 47857		吸取生命
    uint32 WarlockAssist_StealMana;// 5138		吸取法力
    uint32 WarlockAssist_BaseFear;// 6215		恐惧术
    uint32 WarlockAssist_FastFear;// 47860		死亡缠绕
    uint32 WarlockAssist_AOEFear;// 17928		群体恐惧术

    uint32 WarlockAOE_MeleeFire;// 61290		近战前方AOE
    uint32 WarlockAOE_RainFire;// 47820			火焰雨AOE
    uint32 WarlockAOE_ShadowRage;// 47847		暗影之怒AOE群体昏迷(毁灭系)

    uint32 WarlockCurse_UpDmg;// 47865			元素伤害提高诅咒
    uint32 WarlockCurse_MoveLow;// 18223		疲劳诅咒 移动速度降低(痛苦系)
    uint32 WarlockCurse_MgcDmg;// 47864			痛苦诅咒 DOT伤害
    uint32 WarlockCurse_MeleeLow;// 50511		虚弱诅咒 攻强降低
    uint32 WarlockCurse_CastLow;// 11719		语言诅咒 施法时间延迟

    uint32 WarlockDot_LeechSoul;// 59164		浊魂术(痛苦系)
    uint32 WarlockDot_HighDmg;// 47843			痛苦动荡(痛苦系)
    uint32 WarlockDot_LowDmg;// 47813			腐竹术
    uint32 WarlockDot_AOEDmg;// 47836			腐竹种子 dot后范围伤害
    uint32 WarlockDot_Sacrifice;// 47811		毁灭献祭

    uint32 WarlockCast_ShadowArrow;// 47809		暗影之箭
    uint32 WarlockCast_ShadowShock;// 47827		暗影冲击24码(毁灭系)
    uint32 WarlockCast_ChaosArrow;// 59172		混乱之箭(毁灭系)
    uint32 WarlockCast_FullBurn;// 47838		燃尽 有献祭时加强效果(毁灭系)
    uint32 WarlockCast_FireBurn;// 17962		焚烧 消耗献祭(毁灭系)
    uint32 WarlockCast_BigFireBall;// 47825		灵魂大火球

    uint32 WarlockPetDemon_Charge;// 47996		恶魔pet冲锋
    uint32 WarlockPetDemon_Melee;// 47994		恶魔pet顺劈斩
    uint32 WarlockPetDog_MagicBuf;// 57567		猎犬pet团队BUF
    uint32 WarlockPetDog_EatMgc;// 48011		猎犬pet吞食魔法
    uint32 WarlockPetDog_Bite;// 54053			猎犬pet咬人
    uint32 WarlockPetDog_Silence;// 19647		猎犬pet沉默
    uint32 WarlockPetSuccubus_Lash;// 47992		魅魔pet鞭打
    uint32 WarlockPetSuccubus_Sneak;// 7870		魅魔pet潜行
    uint32 WarlockPetSuccubus_Charm;// 6358		魅魔pet魅惑
    uint32 WarlockPetGhost_Shield;// 47983		小鬼pet火盾
    uint32 WarlockPetGhost_Sneak;// 4511		小鬼pet潜行
    uint32 WarlockPetGhost_Stamp;// 47982		小鬼pet血印记
    uint32 WarlockPetGhost_FireArrow;// 47964	小鬼pet火焰箭

    uint32 WarlockFlag_SoulItem;// 6265			灵魂碎片道具
    uint32 WarlockFlag_SoulLink;// 25228		宠物灵魂链接BUF
    uint32 WarlockFlag_OpenGate;// 48018		传送法阵BUF
    uint32 WarlockFlag_Sacrifice;// 50589		恶魔献祭BUF
};

#endif // !_BOT_WARLOCK_AI_H
