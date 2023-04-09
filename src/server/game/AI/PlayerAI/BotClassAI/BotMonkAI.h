
#ifndef _BOT_MONK_AI_H
#define _BOT_MONK_AI_H

#include "ScriptSystem.h"
#include "BotAI.h"
#include "AIWaypointsMgr.h"

class BotMonkAI : public BotBGAI
{
public:
    BotMonkAI(Player* player) :
        BotBGAI(player),
        m_BotTalentType(0)
    {}
    ~BotMonkAI() {}

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
    void ProcessBrewMasterCombat(Unit* pTarget);
    void ProcessBattleDancerCombat(Unit* pTarget);
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessArenaHealthMember();

    void ProcessMistWeaverCombat(Unit* pTarget);
    bool CanMeleeHealthMe();

    bool TargetHasMechanic(Unit* pTarget);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool HasEnergyStore();
    void UpEnergy();
    void UpPower();
    void UpMana();

    void OnCastCharge(Unit* pTarget);

private:
    uint32 m_BotTalentType;

    //TALENT_SPEC_MONK_BREWMASTER;
//SINGEL
    uint32 BREWMASTER_tiger_palm;// 100780			
    uint32 BREWMASTER_blackout_strike;// 205523
    uint32 BREWMASTER_keg_smash;// 121253
    uint32 BREWMASTER_chi_wave;// 115098 //talent
    //AOE
    uint32 BREWMASTER_breath_of_fire;// 115181			
    uint32 BREWMASTER_rushing_jade_wind;// 116847
    //CONTROL		
    uint32 BREWMASTER_spear_hand_strike;// 116705			
    uint32 BREWMASTER_leg_sweep;// 119381  //talent
    //
    uint32 BREWMASTER_detox;// 218164
    //HEAL	
    uint32 BREWMASTER_HEAL_01;// 116694
    uint32 BREWMASTER_expel_harm;// 115072
    //
    uint32 BREWMASTER_fortifying_brew;// 115203			
    uint32 BREWMASTER_purifying_brew;// 119582				
    uint32 BREWMASTER_ironskin_brew;// 115308
    uint32 BREWMASTER_dampen_harm;// 122278 //talent

    uint32 BREWMASTER_provoke;// 115546 //pull
    uint32 BREWMASTER_resuscitate;// 115178 //reive


    //TALENT_SPEC_MONK_MISTWEAVER;
    //SINGEL
    uint32 MISTWEAVER_blackout_kick;// 100784
    uint32 MISTWEAVER_rising_sun_kick;// 107428
    uint32 MISTWEAVER_spinning_crane_kick;// 101546 // TALENT
    //AOE
    uint32 MISTWEAVER_chi_wave;// 115098
    //CONTROL
    uint32 MISTWEAVER_song_of_chi_ji;// 198898
    //
    uint32 MISTWEAVER_detox;// 115450
    //HEAL
    uint32 MISTWEAVER_renewing_mist;// 115151
    uint32 MISTWEAVER_enveloping_mist;// 124682
    uint32 MISTWEAVER_HEAL_01;// 116694
    uint32 MISTWEAVER_summon_jade_serpent_statue;// 115313 // talent
    //HEAL AOE
    uint32 MISTWEAVER_essence_font;// 191837
    uint32 MISTWEAVER_revival;// 115310
    uint32 MISTWEAVER_vivify;// 116670 //talent
    //FOR TANK
    uint32 MISTWEAVER_life_cocoon;// 116849
    //REIVE
    uint32 MISTWEAVER_resuscitate;// 115178
    uint32 MISTWEAVER_reawaken;// 212051


    //TALENT_SPEC_MONK_BATTLEDANCER;
    //SINGEL
    uint32 BATTLEDANCER_tiger_palm;// 100780          
    uint32 BATTLEDANCER_rising_sun_kick;// 107428
    uint32 BATTLEDANCER_touch_of_death;// 115080
    uint32 BATTLEDANCER_blackout_kick;// 100784
    uint32 BATTLEDANCER_chi_wave;// 115098 // talent
    uint32 BATTLEDANCER_invoke_xuen_the_white_tiger;// 123904 // talent

    //AOE
    uint32 BATTLEDANCER_fists_of_fury;// 113656        
    uint32 BATTLEDANCER_spinning_crane_kick;// 101546         
    uint32 BATTLEDANCER_whirling_dragon_punch;// 152175 // talent

    //CONTROL
    uint32 BATTLEDANCER_disable;// 116095
    uint32 BATTLEDANCER_leg_sweep;// 119381 // TALENT
    //  
    uint32 BATTLEDANCER_detox;// 218164
    //HEAL
    uint32 BATTLEDANCER_HEAL_01;// 116694
    //
    uint32 BATTLEDANCER_touch_of_karma;// 122470
    uint32 BATTLEDANCER_dampen_harm;// 122278 // talent
    //
    uint32 BATTLEDANCER_resuscitate;// 115178 //REIVE


    uint32 monk_roll;// 109132
};


#endif // !_BOT_MONK_AI_H
