/* Script Data Start
SDName: Boss maiden_of_grief
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_maiden_of_grief' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spell
#define SPELL_PARTING_SORROW                                59723
#define SPELL_STORM_OF_GRIEF                                50752
#define SPELL_STORM_OF_GRIEF_2                              59772
#define SPELL_SHOCK_OF_SORROW                               50760
#define SPELL_SHOCK_OF_SORROW_2                             59726
#define SPELL_PILLAR_OF_WOE                                 50761
#define SPELL_PILLAR_OF_WOE_2                               59727

//Yell
#define SAY_AGGRO                                        -1599004
#define SAY_SLAY_1                                       -1599005
#define SAY_SLAY_2                                       -1599006
#define SAY_SLAY_3                                       -1599007
#define SAY_SLAY_4                                       -1599008
#define SAY_DEATH                                        -1599009
#define SAY_STUN                                         -1599010

struct TRINITY_DLL_DECL boss_maiden_of_griefAI : public ScriptedAI
{
    boss_maiden_of_griefAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    void EnterCombat(Unit* who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  
    {
        DoScriptText(SAY_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_maiden_of_grief(Creature *_Creature)
{
    return new boss_maiden_of_griefAI (_Creature);
}

void AddSC_boss_maiden_of_grief()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_maiden_of_grief";
    newscript->GetAI = GetAI_boss_maiden_of_grief;
    newscript->RegisterSelf();
}
