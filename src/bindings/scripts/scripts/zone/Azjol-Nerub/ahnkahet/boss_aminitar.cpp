/* Script Data Start
SDName: Boss Amanitar
SDAuthor: LordVanMartin
SD%Complete: 
SDComment:  Only appears in heroic mode
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_amanitar' where entry = '';
*** SQL END ***/
#include "precompiled.h"

#define SPELL_BASH                                   57094
#define SPELL_ENTANGLING_ROOTS                       57095
#define SPELL_MINI                                   57055
#define SPELL_VENOM_BOLT_VOLLEY                      57088        

struct TRINITY_DLL_DECL boss_amanitarAI : public ScriptedAI
{
    boss_amanitarAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    
    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
            
        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer)  {}

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
    }
};

CreatureAI* GetAI_boss_amanitar(Creature *_Creature)
{
    return new boss_amanitarAI (_Creature);
}

void AddSC_boss_amanitar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_amanitar";
    newscript->GetAI = GetAI_boss_amanitar;
    newscript->RegisterSelf();
}
