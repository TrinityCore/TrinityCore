
#ifndef _BOT_HUNTER_AI_H
#define _BOT_HUNTER_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

//enum HunterTalentType //Duplicate in BotAI.h
//{
//    HunterTalent_Wild,
//    HunterTalent_Shot,
//    HunterTalent_Survival
//};

class BotHunterAI : public BotBGAI
{
public:
    BotHunterAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0),
        m_IsSupplemented(false),
        m_IsReviveManaModel(false)
    {}
    ~BotHunterAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializeSpells();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessAura(bool isFlee);

    //bool TryStartControlCommand() override;
    //float TryPushControlCommand(Player* pTarget) override;
    bool CastRangeSpell(Unit* pTarget);
    bool CastMeleeSpell(Unit* pTarget);
    void PetAction(Pet* pPet, Unit* pTarget);
    bool HasRootMechanic();
    bool TargetIsSuppress(Unit* pTarget);
    bool CheckManaModel();

private:
    uint32 m_BotTalentType;
    bool m_IsSupplemented;
    bool m_IsReviveManaModel;

    uint32 HunterIDLE_SummonPet;// 883			召唤宠物
    uint32 HunterIDLE_RevivePet;// 982			复活宠物
    uint32 HunterIDLE_ManaAura;// 34074			攻击回蓝守护
    uint32 HunterIDLE_DodgeAura;// 13163		闪躲守护
    uint32 HunterIDLE_EagleAura;// 27044		射击守护
    uint32 HunterIDLE_DragonAura;// 61847		龙鹰守护 射击和闪躲守护
    uint32 HunterIDLE_ShotAura;// 19506			强击光环(射击系)

    uint32 HunterTrap_FarFrozen;// 60192		远程冰冻陷阱
    uint32 HunterTrap_Frozen;// 14311			冰冻陷阱
    uint32 HunterTrap_Ice;// 13809				冰霜陷阱
    uint32 HunterTrap_Viper;// 34600			毒蛇陷阱
    uint32 HunterTrap_Explode;// 49067			爆炸陷阱
    uint32 HunterTrap_Fire;// 49056				火焰陷阱
    uint32 HunterTrap_Shot;// 63672				黑浊箭(生存系)

    uint32 HunterAssist_ClearRoot;// 53271		移除定身
    uint32 HunterAssist_PetCommand;// 34026		宠物杀截
    uint32 HunterAssist_HealPet;// 48990		宠物治疗
    uint32 HunterAssist_PetStun;// 19577		宠物击晕目标(野兽系)
    uint32 HunterAssist_PetRage;// 19574		宠物和自己狂暴(野兽系)
    uint32 HunterAssist_Stamp;// 53338			猎人印记
    uint32 HunterAssist_FalseDead;// 5384		假死
    uint32 HunterAssist_BackJump;// 781			后跳
    uint32 HunterAssist_FastSpeed;// 3045		急速射击BUF
    uint32 HunterAssist_ReadyCD;// 23989		准备就绪CD(射击系)

    uint32 HunterMelee_BackRoot;// 48999		招架后反击定身(生存系)
    uint32 HunterMelee_NoDamage;// 19263		威慑 无法攻击
    uint32 HunterMelee_DecSpeed;// 2974			摔拌 近战减移动速
    uint32 HunterMelee_NextAtt;// 48996			next近战攻击加强
    uint32 HunterMelee_MeleeAtt;// 53339		近战攻击

    uint32 HunterDebug_Damage;// 49001			伤害钉刺
    uint32 HunterDebug_Mana;// 3034				吸蓝钉刺
    uint32 HunterDebug_Sleep;// 49012			沉睡钉刺(生存系)

    uint32 HunterShot_AOEShot;// 58434			AOE射击
    uint32 HunterShot_CharmShot;// 19503		打断射击(生存系)
    uint32 HunterShot_Explode;// 60053			爆炸射击(生存系)
    uint32 HunterShot_Aim;// 49050				瞄准射击(射击系)
    uint32 HunterShot_Silence;// 34490			沉默射击(射击系)
    uint32 HunterShot_Shock;// 5116				震荡射击
    uint32 HunterShot_Cast;// 49052				稳固射击 施法时间的射击
    uint32 HunterShot_MgcShot;// 49045			奥术射击
    uint32 HunterShot_KillShot;// 61006			击杀射击 目标20%以下血斩杀式射击
    uint32 HunterShot_MulShot;// 49048			多重射击
    uint32 HunterShot_QMLShot;// 53209			奇美拉射击(射击系)
};

#endif // !_BOT_HUNTER_AI_H
