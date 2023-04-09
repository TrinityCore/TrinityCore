#ifndef _BOT_DEATHKNIGHT_AI_H
#define _BOT_DEATHKNIGHT_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

class BotDeathknightAI : public BotBGAI
{
public:
    BotDeathknightAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0)
    {}
    ~BotDeathknightAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetRunePowerPer();
    void InitializeSpells();
    void UpdateTalentType();


    void ProcessReady() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    void ProcessBloodMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);
    void ProcessEvilMeleeSpell(Unit* pTarget);

    bool ProcessBlcokCast();
    bool ProcessMgcShield();
    bool ProcessInfected(Unit* pTarget);
    bool ProcessDKPull(Unit* pTarget);

    bool TargetHasMechanic(Unit* pTarget);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;

    void UpPower();
    void PetAction(Unit* pTarget);
    bool IsTankBotAI();
    void OnCastCharge(Unit* pTarget);

private:
    uint32 m_BotTalentType;

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

#endif // !_BOT_DEATHKNIGHT_AI_H
