/* Script Data Start
SDName: Boss dred
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
#define SPELL_BELLOWING_ROAR                     44863 // fears the group, can be resisted/dispelled
#define SPELL_GRIEVOUS_BITE                      48920 
#define SPELL_MANGLING_SLASH                     48873 //casted on the current tank, adds debuf
#define SPELL_FEARSOME_ROAR_N                    48849
#define SPELL_FEARSOME_ROAR_H                    48849 //Not stacking, debuff
#define SPELL_PIERCING_SLASH                     48878 //debuff -->Armor reduced by 75% 
#define SPELL_RAPTOR_CALL                        59416 //dummy


struct TRINITY_DLL_DECL boss_dredAI : public ScriptedAI
{
    boss_dredAI(Creature *c) : ScriptedAI(c) {}
    
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
};

CreatureAI* GetAI_boss_dred(Creature *_Creature)
{
    return new boss_dredAI (_Creature);
}

void AddSC_boss_dred()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_dred";
    newscript->GetAI = GetAI_boss_dred;
    newscript->RegisterSelf();
}
