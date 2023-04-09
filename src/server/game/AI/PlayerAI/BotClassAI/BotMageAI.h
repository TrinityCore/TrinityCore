
#ifndef _BOT_MAGE_AI_H
#define _BOT_MAGE_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum MageTalentType
{
    MageTalent_Arcane,
    MageTalent_Fire,
    MageTalent_Frost
};

class BotMageAI : public BotBGAI
{
public:
    BotMageAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_LastPolymorphTarget(ObjectGuid::Empty),
        m_StealthTick(0)
    {}
    ~BotMageAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void InitializeSpells();
    void UpdateTalentType();
    bool TargetCanFreeze(Unit* pTarget);
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    bool ProcessArcaneFlee();
    bool ProcessFireFlee();
    bool ProcessFrostFlee();
    void ProcessArcaneRangeSpell(Unit* pTarget);
    void ProcessFireRangeSpell(Unit* pTarget);
    void ProcessFrostRangeSpell(Unit* pTarget);
    void ProcessArcaneMeleeSpell(Unit* pTarget);
    void ProcessFireMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);
    bool ProcessPolymorph(Unit* pTarget);
    bool ProcessFreezeSpell(Unit* pTarget);

    void ProcessPetAttack(Unit* pTarget);
    bool CastingControlCommandSpell() override;
    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool IsStealthing();
    void OnCastTeleport();
    void OnCastPolymorph(Unit* pTarget);
    bool TargetCanPolymorph(Unit* pTarget);
    Position GetTeleportSpellPos();
    bool UseManaJewel();
    Item* FindExistManaJewel();
    uint32 TryCastSummonRiteSpell() override;

private:
    ObjectGuid m_LastPolymorphTarget;
    uint32 m_StealthTick;
    uint32 m_BotTalentType;
    std::set<uint32> m_JewelEntrys;


    uint32 MageIDLE_ManaGem;// 42985		法力宝石
    uint32 MageIDLE_ArcaneMagic;// 42995	奥术智慧
    uint32 MageIDLE_AOEArcaneMagic;// 43002	全体奥术智慧
    uint32 MageIDLE_MgcArmor;// 43024		魔甲术
    uint32 MageIDLE_FrostArmor;// 43008		冰甲术
    uint32 MageIDLE_IceArmor;// 7301		霜甲术
    uint32 MageIDLE_FireArmor;// 43046		火焰装甲
    uint32 MageIDLE_MagicAdd;// 43017		魔法增效
    uint32 MageIDLE_MagicDec;// 43015		魔法压制
    uint32 MageIDLE_SummonRite;// 58659		召唤餐桌

    uint32 MageGuard_MagicShield;// 43020	法力护盾
    uint32 MageGuard_FrostShield;// 43039	寒冰护盾
    uint32 MageGuard_FrostScherm;// 45438	寒冰屏障
    uint32 MageGuard_FrostNova;// 42917		寒冰新星
    uint32 MageGuard_FireBreath;// 42950	龙之吐息
    uint32 MageGuard_FireNova;// 42945		火焰新星

    uint32 MageAssist_Mirror;// 55342		法师镜像
    uint32 MageAssist_Rouse;// 12051		唤醒
    uint32 MageAssist_Stealth;// 66			隐形术
    uint32 MageAssist_Teleport;// 1953		闪现术
    uint32 MageAssist_DecCurse;// 475		解除诅咒
    uint32 MageAssist_Grace;// 12043		气定神闲
    uint32 MageAssist_ArcanePower;// 12042	奥术强化
    uint32 MageAssist_CastSpeed;// 12472	冰冷血脉
    uint32 MageAssist_FastColddown;// 11958	重置冰系技能CD
    uint32 MageAssist_FrostPet;// 31687		召唤水元素
    uint32 MageAssist_FireCritAura;// 11129	主动3次增加火焰暴击AURA

    uint32 MageConfine_BreakCast;// 2139	法术反制
    uint32 MageConfine_AuraSteal;// 30449	BUFF偷取
    uint32 MageConfine_ArcaneSlow;// 31589	奥术缓速
    uint32 MageConfine_ToSheep;// 12826		变羊
    uint32 MageConfine_Freeze;// 44572		冻结被冰冻的目标

    uint32 MageAOE_ArcaneExplode;// 42921	奥术爆炸
    uint32 MageAOE_Snowstorm;// 42940		暴风雪
    uint32 MageAOE_IcePiton;// 42931		冰锥术
    uint32 MageAOE_FireStorm;// 42926		火焰风暴

    uint32 MageArcane_Barrage;// 44781		奥术弹幕
    uint32 MageArcane_Bullet;// 42846		奥术飞弹
    uint32 MageArcane_ArcaneShock;// 42897	奥术冲击

    uint32 MageFrost_IceArrow;// 42842		寒冰箭
    uint32 MageFrost_IceLance;// 42914		冰枪
    uint32 MageFrost_FFArrow;// 47610		霜火箭

    uint32 MageFire_FireArrow;// 42833		火球术
    uint32 MageFire_FireShock;// 42873		火焰冲击
    uint32 MageFire_Firing;// 42859			灼烧
    uint32 MageFire_BigFireBall;// 42891	大火球
    uint32 MageFire_FireBomb;// 55360		活体炸弹

    uint32 MagePet_FrostNova;// 33395		水宝宝寒冰新星

    uint32 MageFlag_FireStun;// 64343		Aura:可以火冲昏迷
    uint32 MageFlag_FastFStorm;// 54741		Aura:火焰风暴瞬发
    uint32 MageFlag_FastBFBall;// 48108		Aura:瞬发大火球
    uint32 MageFlag_FastFFArrow;// 57761	Aura:瞬发霜火箭
    uint32 MageFlag_CanFrozen;// 74396		Aura:目标当成被冰冻状态
    uint32 MageFlag_Scherm;// 45438			Aura:冰箱状态中
};

#endif // !_BOT_MAGE_AI_H
