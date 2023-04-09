
#ifndef _BOT_ROGUE_AI_H
#define _BOT_ROGUE_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

//enum RogueTalentType
//{
//    RogueTalent_Kill,
//    RogueTalent_Combat,
//    RogueTalent_Keen
//};

class BotRogueAI : public BotBGAI
{
public:
    BotRogueAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_IsUpedPoison(0)
    {}
    ~BotRogueAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetEnergyPowerPer();
    uint32 GetPoisonEntryByWeaponType(EquipmentSlots equipSlot);
    void InitializeSpells();
    void UpdateTalentType();
    void EachTick() override;
    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;
    bool ProcessSneakSpell(Unit* pTarget);
    bool ProcessMeleeDance(Unit* pTarget);
    bool ProcessMeleeBlind(Unit* pTarget);

    bool TryStartControlCommand() override;
    float TryPushControlCommand(Player* pTarget) override;
    bool CanConsumeCombo(Unit* pTarget);
    bool CastCloakByNeed();
    bool CanBlind(Unit* pTarget);
    bool CanStartSpell();
    void OnCastSneak();
    void OnCastFlash(Unit* pTarget);
    void UpEnergy();

private:
    uint32 m_BotTalentType;
    uint8 m_IsUpedPoison;

    uint32 RogueGuard_Sneak;// 1784				潜行
    uint32 RogueGuard_ShadowCloak;// 31224		暗影斗篷
    uint32 RogueGuard_Disappear;// 26889		消失
    uint32 RogueGuard_Dodge;// 26669			闪躲
    uint32 RogueGuard_Sprint;// 11305			疾跑

    uint32 RogueSneak_Stick;// 51724			闷棍
    uint32 RogueSneak_Premeditate;// 14183		预谋(敏锐系)
    uint32 RogueSneak_Ambush;// 48691			伏击
    uint32 RogueSneak_Surprise;// 1833			偷袭

    uint32 RogueAssist_ShadowDance;// 51713		暗影之舞(敏锐系)
    uint32 RogueAssist_ShadowFlash;// 36554		暗影步(敏锐系)
    uint32 RogueAssist_ReadyCD;// 14185			预备(敏锐系)
    uint32 RogueAssist_Blind;// 2094			致盲
    uint32 RogueAssist_Disarm;// 51722			缴械
    uint32 RogueAssist_NextCrit;// 14177		冷血 next暴击(刺杀系)
    uint32 RogueAssist_blood;// 51662			鲜血 目标流血时施放(刺杀系)
    uint32 RogueAssist_FastEnergy;// 13750		能量快速回复(战斗系)
    uint32 RogueAssist_BlockCast;// 1766		脚踢 打断施法
    uint32 RogueAssist_Paralyze;// 1776			凿击 瘫痪目标
    uint32 RogueAssist_FastSpeed;// 13877		加攻击速度20(战斗系)

    uint32 RogueAOE_Knife;// 51723				刀刃飞舞
    uint32 RogueAOE_AllDance;// 51690			狂舞杀截(战斗系)

    uint32 RogueAttack_Blood;// 48660			出血(敏锐系)
    uint32 RogueAttack_Ghost;// 14278			鬼魅攻击(敏锐系) 攻击后+闪躲
    uint32 RogueAttack_Injure;// 48666			毁伤(刺杀系)
    uint32 RogueAttack_PoisonAtt;// 5938		毒刃
    uint32 RogueAttack_BackAtt;// 48657			背刺
    uint32 RogueAttack_EvilAtt;// 48638			邪恶攻击

    uint32 RogueAttack_Damage;// 48668			剔骨
    uint32 RogueAttack_Separate;// 48672		割裂
    uint32 RogueAttack_Stun;// 8643				肾击
    uint32 RogueAttack_PoisonDmg;// 57993		毒伤
    uint32 RogueRange_Throw;// 48674			致命投掷

    uint32 RogueFlag_Dance;// 51713				暗影之舞标记
};

#endif // !_BOT_ROGUE_AI_H
