/* Script Data Start
SDName: Boss ormorok
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_CRYSTAL_SPIKES_1                     47958
#define SPELL_CRYSTAL_SPIKES_2                     57082
#define SPELL_CRYSTAL_SPIKES_3                     57083
#define SPELL_SPELL_REFLECTION                     47981
#define SPELL_TRAMPLE_N                            48016
#define SPELL_TRAMPLE_H                            57066
#define SPELL_FRENZY_N                             48017
#define SPELL_FRENZY_H                             57086
#define SPELL_SUMMON_CRYSTALLINE_TANGLER           61564 //summons npc 32665

//Yell
#define SAY_AGGRO                               -1576016
#define SAY_KILL                                -1576017
#define SAY_DEATH                               -1576018
#define SAY_REFLECT                             -1576019
#define SAY_ICE_SPIKES                          -1576020

struct TRINITY_DLL_DECL boss_ormorokAI : public ScriptedAI
{
    boss_ormorokAI(Creature *c) : ScriptedAI(c) {}

    bool   frenzy;
    
    void Reset() 
    {
        frenzy = false;
    }
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
        
        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) == 25)
        {
            if(!frenzy)
            {
                DoCast(m_creature, SPELL_FRENZY_N);
                frenzy = true;
            }
        }
                
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
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_ormorok(Creature *_Creature)
{
    return new boss_ormorokAI (_Creature);
}

void AddSC_boss_ormorok()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_ormorok";
    newscript->GetAI = GetAI_boss_ormorok;
    newscript->RegisterSelf();
}
