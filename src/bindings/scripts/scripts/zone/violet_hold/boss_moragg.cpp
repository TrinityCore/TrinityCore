/* Script Data Start
SDName: Boss moragg
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
#define SPELL_CORROSICE_SALIVA                     54527
#define SPELL_OPTIC_LINK                           54396

struct TRINITY_DLL_DECL boss_moraggAI : public ScriptedAI
{
    boss_moraggAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;    
        
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer) {}
};

CreatureAI* GetAI_boss_moragg(Creature* pCreature)
{
    return new boss_moraggAI (pCreature);
}

void AddSC_boss_moragg()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_moragg";
    newscript->GetAI = &GetAI_boss_moragg;
    newscript->RegisterSelf();
}
