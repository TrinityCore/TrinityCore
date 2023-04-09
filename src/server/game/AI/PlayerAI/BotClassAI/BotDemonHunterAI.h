
#ifndef _BOT_DEMONHUNTER_AI_H
#define _BOT_DEMONHUNTER_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

enum DemonHunterTalentType
{
    DemonHunterTalent_Havoc,
    DemonHunterTalent_Vengeance
};

class BotDemonHunterAI : public BotBGAI
{
public:
    BotDemonHunterAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0)
    {}
    ~BotDemonHunterAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializeSpells();
    void UpdateTalentType();

    void ProcessReady() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessVengeanceMeleeSpell(Unit* pTarget);
    void ProcessHavocMeleeSpell(Unit* pTarget);
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessSeduceSpell(Unit* pTarget);

    bool ProcessAura();
    bool ProcessControl(Unit* pTarget);

    bool TargetNeedInvincible(Unit* player);
    bool TargetNeedFree(Unit* player);
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool TargetIsCtrl(Unit* pTarget);

private:
    uint32 m_BotTalentType;

    //SINGEL
    uint32 HAVOC_demons_bite;// 162243			
    uint32 HAVOC_chaos_strike;// 162794
    uint32 HAVOC_fel_rush;// 195072
    //AOE
    uint32 HAVOC_eye_beam;// 198013			
    uint32 HAVOC_blade_dance;// 188499			
    uint32 HAVOC_throw_glaive;// 185123			
    uint32 HAVOC_chaos_nova;// 179057
    //CONTROL
    uint32 HAVOC_disrupt;// 183752		
    uint32 HAVOC_imprison;// 217832
    uint32 HAVOC_vengeful_retreat;// 198793	
    uint32 HAVOC_fel_eruption;// 211881 talent
    //
    uint32 HAVOC_darkness;// 196718			
    uint32 HAVOC_blur;// 198589				
    uint32 HAVOC_metamorphosis;// 191427

    //SINGEL
    uint32 Vengeance_shear;// 203782
    //AOE
    uint32 Vengeance_immolation_aura;// 178740
    uint32 Vengeance_infernal_strike;// 189110
    uint32 Vengeance_throw_glaive;// 204157
    uint32 Vengeance_soul_cleave;// 228477
    uint32 Vengeance_sigil_of_flame;// 204596
    //CONTROL
    uint32 Vengeance_disrupt;// 183752
    uint32 Vengeance_sigil_of_silence;// 202137
    uint32 Vengeance_sigil_of_misery;// 207684

    uint32 Vengeance_demon_spikes;// 203720
    uint32 Vengeance_fiery_brand;// 204021
    uint32 Vengeance_soul_227225;// 227225 //talent
    uint32 Vengeance_metamorphosis;// 187827

    uint32 Vengeance_torment;// 185245

    uint32 DemonHunterIDLE_MountAura;// 200175
};

#endif // !_BOT_PALADIN_AI_H

