
#ifndef _BOT_PRIEST_AI_H
#define _BOT_PRIEST_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum PriestTalentType
{
    PriestTalent_Precept,
    PriestTalent_Holy,
    PriestTalent_Shadow
};

class BotPriestAI : public BotBGAI
{
public:
    BotPriestAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_ReadyCurrentPrayer(0)
    {}
    ~BotPriestAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    bool HaveManaStore() override;
    bool CastBuffPrayer();
    bool NeedWaitSpecialSpell(uint32 diff) override;
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

    void ProcessNormalRangeSpell(Unit* pTarget);
    void ProcessShadowRangeSpell(Unit* pTarget);

    bool ProcessManaBurn();
    bool ProcessManaRevive();
    bool ProcessDispel();

    bool IsHealerBotAI() override;
    bool IsAttacker() override;

private:
    uint32 m_BotTalentType;
    uint32 m_ReadyCurrentPrayer;

    uint32 PriestIDLE_AllHardRes;// 48162			全体坚韧
    uint32 PriestIDLE_HardRes;// 48161				单体坚韧
    uint32 PriestIDLE_SoulFire;// 48168				心灵之火
    uint32 PriestIDLE_AllSpiritRes;// 48074			全体精神
    uint32 PriestIDLE_SpiritRes;// 48073			单体精神
    uint32 PriestIDLE_Bloodsucker;// 15286			吸血鬼拥抱
    uint32 PriestIDLE_AllShadowRes;// 48170			全体暗影抗性
    uint32 PriestIDLE_ShadowRes;// 48169			单体暗影抗性
    uint32 PriestIDLE_ShadowStatus;// 15473			暗影形态

    uint32 PriestGuard_ShadowFear;// 64044			单体恐惧(暗影系)
    uint32 PriestGuard_AOEFear;// 10890				近战范围群恐惧
    uint32 PriestGuard_DefFear;// 6346				反恐惧结界
    uint32 PriestGuard_RecoverMana;// 47585			暗影回蓝和免伤(暗影系)
    uint32 PriestGuard_DmgAnnul;// 33206			痛苦压制(戒律系)
    uint32 PriestGuard_DefShield;// 48066			真言术 盾
    uint32 PriestGuard_SelfHealth;// 48173			绝望祷言 自己瞬间治疗(神圣系)
    uint32 PriestGuard_GuardSoul;// 47788			灵魂守护 target死亡时守护(神圣系)

    uint32 PriestAssist_SoulAbs;// 14751			心灵专注next0耗蓝(戒律系)
    uint32 PriestAssist_AddHolyPower;// 10060		能力注入target施法急速和暴击(戒律系)
    uint32 PriestAssist_AllDispel;// 32375			全体驱散魔法
    uint32 PriestAssist_Dispel;// 988				单体驱散魔法
    uint32 PriestAssist_ShadowDemon;// 34433			暗影恶魔
    uint32 PriestAssist_Silence;// 15487			暗影沉默(暗影系)
    uint32 PriestAssist_AllResMana;// 64901			引导全体回蓝
    uint32 PriestAssist_AllResLife;// 64843			引导全体回血

    uint32 PriestDebuf_Ache;// 48125				痛
    uint32 PriestDebuf_Drown;// 48158				灭
    uint32 PriestDebuf_Plague;// 48300				瘟疫

    uint32 PriestAOE_ShadowExplode;// 53023			暗影爆炸AOE(暗影系)
    uint32 PriestAOE_HolyNova;// 48078				神圣新星

    uint32 PriestShadow_ShadowTouch;// 48160			吸血之触(暗影系)
    uint32 PriestShadow_Knocking;// 48127			心灵震爆
    uint32 PriestShadow_Lech;// 48156				精神鞭挞(暗影系)
    uint32 PriestHoly_Smite;// 48123				惩击
    uint32 PriestHoly_BigFire;// 48135				神圣之火
    uint32 PriestPrecept_ManaBurn;// 8129			法力燃烧

    uint32 PriestHeal_LowHeal;// 6064				低级治疗
    uint32 PriestHeal_Resume;// 48068				恢复
    uint32 PriestHeal_FastHeal;// 48071				快速治疗
    uint32 PriestHeal_BigHeal;// 48063				大治疗
    uint32 PriestHeal_LinkHeal;// 48120				链接自己和目标治疗
    uint32 PriestHeal_UnionHeal;// 48113			愈合祷言 target next heal
    uint32 PriestHeal_RingHeal;// 48089				治疗之环(神圣系)
    uint32 PriestHeal_AOEHeal;// 48072				治疗祷言 aoe heal
    uint32 PriestHeal_Awareness;// 53007			觉悟 引导3个治疗子弹治疗目标(戒律系)

    uint32 PriestFlag_DeadSoul;// 27827				救赎之魂 神牧死亡后
    uint32 PriestFlag_NonShield;// 6788				真言盾DEBUFF
};

#endif // !_BOT_PRIEST_AI_H
