/* Script Data Start
SDName: Boss jedoga
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_jedoga' where entry = '';
*** SQL END ***/
#include "precompiled.h"

#define SPELL_CYCLONE_STRIKE                       56855
#define SPELL_LIGHTNING_BOLT                       56891
#define SPELL_THUNDERSHOCK                         56926

#define SAY_AGGRO                                 -1619000
#define SAY_C_SACRIFICE_1                         -1619001
#define SAY_C_SACRIFICE_2                         -1619002
#define SAY_SACRIFICE_1                           -1619003
#define SAY_SACRIFICE_2                           -1619004
#define SAY_SLAY_1                                -1619005
#define SAY_SLAY_2                                -1619006
#define SAY_SLAY_3                                -1619007
#define SAY_DEATH                                 -1619008
#define SAY_PREACHING_1                           -1619009 
#define SAY_PREACHING_2                           -1619010
#define SAY_PREACHING_3                           -1619011
#define SAY_PREACHING_4                           -1619012
#define SAY_PREACHING_5                           -1619013

struct TRINITY_DLL_DECL boss_jedogaAI : public ScriptedAI
{
    boss_jedogaAI(Creature *c) : ScriptedAI(c) {}

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

CreatureAI* GetAI_boss_jedoga(Creature *_Creature)
{
    return new boss_jedogaAI (_Creature);
}

void AddSC_boss_jedoga()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_jedoga";
    newscript->GetAI = GetAI_boss_jedoga;
    newscript->RegisterSelf();
}
