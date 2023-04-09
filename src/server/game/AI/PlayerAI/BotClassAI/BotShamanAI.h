#ifndef _BOT_SHAMAN_AI_H
#define _BOT_SHAMAN_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"
#include "Totem.h"

enum ShamanTalentType
{
    ShamanTalent_Element,
    ShamanTalent_Power,
    ShamanTalent_Heal
};

class BotShamanAI : public BotBGAI
{
public:
    BotShamanAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_CurrentPattern(ShamanTotemPattern::ShamanTP_None),
        m_NonFearTotemTick(0),
        m_SummonFireTotemTick(0),
        m_IsUpedWeapon(0)
    {}
    ~BotShamanAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializeSpells();
    void UpdateTalentType();
    bool ProcessUpWeapon();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessDispel();
    bool ProcessHeroic();
    bool ProcessArenaHealthMember();

    bool CastingControlCommandSpell() override;
    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool ProcessShield();
    bool ProcessTotem();
    bool ExistTotemByType(PlayerTotemType totemType, float range);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool TargetIsSuppress(Unit* pTarget);
    bool TryRecycleTotem(ShamanTotemPattern pattern);

private:
    uint32 m_BotTalentType;
    ShamanTotemPattern m_CurrentPattern;
    uint32 m_NonFearTotemTick;
    uint32 m_SummonFireTotemTick;
    uint8 m_IsUpedWeapon;

    uint32 ShamanIDLE_LifeWeapon;// 51994		生命武器
    uint32 ShamanIDLE_IceWeapon;// 58796		冰霜武器
    uint32 ShamanIDLE_FireWeapon;// 58790		火焰武器
    uint32 ShamanIDLE_PhyWeapon;// 10399		石化武器
    uint32 ShamanIDLE_FastWeapon;// 58804		风怒武器

    uint32 ShamanShield_Earth;// 49284			大地之盾(恢复系)
    uint32 ShamanShield_Water;// 57960			水之盾
    uint32 ShamanShield_Lightning;// 49281		闪电之盾

    uint32 ShamanAssist_Frog;// 51514			变形青蛙
    uint32 ShamanAssist_HealCrit;// 55198		next3几率治疗暴击(恢复系)
    uint32 ShamanAssist_MomentHeal;// 16188		nextHeal施法瞬发(恢复系)
    uint32 ShamanAssist_MomentCast;// 16166		nextCast施法瞬发(元素系)
    uint32 ShamanAssist_BlockCast;// 57994		打断施法
    uint32 ShamanAssist_Cleansing;// 8012		净化目标2个BUFF
    uint32 ShamanAssist_FireNova;// 61657		让火焰图腾AOE一次
    uint32 ShamanAssist_Heroic;// 32182			萨满英勇

    uint32 ShamanAtt_StormStrike;// 17364		风暴打击(增强系)
    uint32 ShamanAtt_FireStrike;// 60103		熔岩打击(增强系)

    uint32 ShamanCast_LightningArrow;// 49238	闪电箭
    uint32 ShamanCast_LightningChain;// 49271	闪电链
    uint32 ShamanCast_LightningStorm;// 59159	闪电风暴(元素系)
    uint32 ShamanCast_FireThud;// 49233			火焰震击
    uint32 ShamanCast_IceThud;// 49236			冰霜震击
    uint32 ShamanCast_EarthThud;// 49231		大地震击
    uint32 ShamanCast_FireStrike;// 60043		熔岩打击 远程法术

    uint32 ShamanHealth_Fast;// 49276			快速治疗
    uint32 ShamanHealth_Bast;// 49273			大力治疗
    uint32 ShamanHealth_Chain;// 55459			治疗链
    uint32 ShamanHealth_Torrent;// 61301		激流 瞬发小治疗+持续治疗(恢复系)
    uint32 ShamanDispel_Refine;// 51886			驱散

    uint32 ShamanTotem_Recycle;// 36936			回收图腾

    uint32 ShamanTotem_Life;// 58757			生命图腾
    uint32 ShamanTotem_Mana;// 58774			法力图腾
    uint32 ShamanTotem_BMana;// 16190			大法力图腾
    uint32 ShamanTotem_NonFear;// 8143			战栗图腾
    uint32 ShamanTotem_SummonFire;// 2894		召唤火元素图腾
    uint32 ShamanTotem_MgcPower;// 57722		法术能量图腾(元素系)
    uint32 ShamanTotem_Attack;// 58704			自主火焰攻击图腾
    uint32 ShamanTotem_AOEAttack;// 58734		自主火焰群攻图腾
    uint32 ShamanTotem_MgcHeal;// 58656			法术能量和治疗效果图腾

    uint32 ShamanTotem_DecMove;// 2484			减移动速度图腾
    uint32 ShamanTotem_SummonSoil;// 2062		召唤土元素图腾
    uint32 ShamanTotem_PhyPower;// 58643		力量敏捷图腾
    uint32 ShamanTotem_Armor;// 58753			护甲图腾

    uint32 ShamanTotem_AbsorbBuff;// 8177		吸收有害BUFF图腾
    uint32 ShamanTotem_AttSpeed;// 8512			近战攻击速度图腾
    uint32 ShamanTotem_MgcSpeed;// 3738			法术施法速度图腾

    uint32 ShamanFlag_NoHeroic;// 57723			无法give英勇状态标识
};

#endif // !_BOT_SHAMAN_AI_H
