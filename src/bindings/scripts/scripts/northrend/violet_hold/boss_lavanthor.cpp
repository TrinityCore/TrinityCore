/* Script Data Start
SDName: Boss lavanthor
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
#define SPELL_CAUTERIZING_FLAMES                      59466
#define SPELL_FIREBOLT                                54235
#define SPELL_FLAME_BREATH                            54282
#define SPELL_LAVA_BURN                               54249

struct TRINITY_DLL_DECL boss_lavanthorAI : public ScriptedAI
{
    boss_lavanthorAI(Creature *c) : ScriptedAI(c) {}

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

CreatureAI* GetAI_boss_lavanthor(Creature* pCreature)
{
    return new boss_lavanthorAI (pCreature);
}

void AddSC_boss_lavanthor()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_lavanthor";
    newscript->GetAI = &GetAI_boss_lavanthor;
    newscript->RegisterSelf();
}
