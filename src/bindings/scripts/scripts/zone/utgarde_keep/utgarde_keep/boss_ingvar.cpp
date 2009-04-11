/* Script Data Start
SDName: Boss ingvar
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_ingvar' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//phase 1 Human
#define SPELL_STAGGERING_ROAR                     42708
#define SPELL_DREADFUL_ROAR                       42729
#define SPELL_SMASH                               42669
#define SPELL_ENRAGE                              42705
#define SPELL_CLEAVE                              42724
//whed killed in phase1 is resurected by Annhylde the Caller and becomes Undead
//only in phase 2 
#define INGVAR_RESURECTION_VISUAL                 24012
#define INGVAR_UNDEAD                             23980
#define INGVAR_IMAGE                              31584
#define INGVAR_THROW_TARGET                       23996
#define INGVAR_THROW_DUMMY                        23997

#define TRANSFORM_INGVAR                          42796
#define INGVAR_FEIGN_DEATH                        42795
#define NPC_ANNHYLDE_THE_CALLER                   24068
#define SPELL_WOE_STRIKE                          42730
#define SPELL_DARK_SMASH                          42723
#define SPELL_SHADOW_AXE                          42748

//Yell
#define SAY_AGGRO                              -1574015
#define SAY_KILL                               -1574016
#define SAY_DEATH                              -1574017
#define SAY_ATTACK_1                           -1574018
#define SAY_ATTACK_2                           -1574019
#define SAY_ATTACK_3                           -1574020
#define SAY_ATTACK_4                           -1574021
#define SAY_PHASE2_AGGRO                       -1574022
#define SAY_PHASE2_KILL                        -1574023
#define SAY_PHASE2_DEATH                       -1574024
#define SAY_ANNHYLDE_THE_CALLER_RESURECTION    -1574025

struct TRINITY_DLL_DECL boss_ingvarAI : public ScriptedAI
{
    boss_ingvarAI(Creature *c) : ScriptedAI(c) {}

    uint32 phase;
    
    void Reset() {}    
    void Aggro(Unit* who) 
    {
        if(phase ==1)
            DoScriptText(SAY_AGGRO, m_creature);
        if(phase ==2)
            DoScriptText(SAY_PHASE2_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
            
        phase =1;
        
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  
    {
        if(phase ==1)
            DoScriptText(SAY_DEATH, m_creature);
        if(phase ==2)
            DoScriptText(SAY_PHASE2_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        if(phase == 1)
            DoScriptText(SAY_KILL, m_creature);
            //remove all auras, set unatackable and untargetable an begin resurection event and set to phase 2
        if(phase ==2)
            DoScriptText(SAY_PHASE2_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_ingvar(Creature *_Creature)
{
    return new boss_ingvarAI (_Creature);
}

void AddSC_boss_ingvar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_ingvar";
    newscript->GetAI = GetAI_boss_ingvar;
    newscript->RegisterSelf();
}
