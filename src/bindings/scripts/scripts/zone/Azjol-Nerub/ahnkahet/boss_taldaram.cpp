/* Script Data Start
SDName: Boss taldaram
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_taldaram' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_BLOODTHIRST                         55968
#define SPELL_CONJURE_FLAME_SPHERE                55931
#define SPELL_EMBRACE_OF_THE_VAMPYR_N             55959
#define SPELL_EMBRACE_OF_THE_VAMPYR_H             59513
#define SPELL_VANISH                              55964

//Yell
#define SAY_AGGRO                                -1619021
#define SAY_SLAY_1                               -1619022
#define SAY_SLAY_2                               -1619023
#define SAY_SLAY_3                               -1619024
#define SAY_DEATH                                -1619025
#define SAY_FEED_1                               -1619026
#define SAY_FEED_2                               -1619027
#define SAY_VANISH_1                             -1619028
#define SAY_VANISH_2                             -1619029

struct TRINITY_DLL_DECL boss_taldaramAI : public ScriptedAI
{
    boss_taldaramAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    void Aggro(Unit* who) 
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
        if (victim == m_creature)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_taldaram(Creature *_Creature)
{
    return new boss_taldaramAI (_Creature);
}

void AddSC_boss_taldaram()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_taldaram";
    newscript->GetAI = GetAI_boss_taldaram;
    newscript->RegisterSelf();
}
