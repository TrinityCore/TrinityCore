/* Script Data Start
SDName: Boss Eck the Ferocious
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: Only appears in Heroic mode
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

#define SPELL_ECK_BERSERK                       55816 //Eck goes berserk, increasing his attack speed by 150% and all damage he deals by 500%.
#define SPELL_ECK_BITE                          55813 //Eck bites down hard, inflicting 150% of his normal damage to an enemy.
#define SPELL_ECK_SPIT                          55814 //Eck spits toxic bile at enemies in a cone in front of him, inflicting 2970 Nature damage and draining 220 mana every 1 sec for 3 sec.
#define SPELL_ECK_SPRING_1                      55815 //Eck leaps at a distant target.  --> Drops aggro and charges a random player. Tank can simply taunt him back.
#define SPELL_ECK_SPRING_2                      55837 //Eck leaps at a distant target.

struct TRINITY_DLL_DECL boss_eckAI : public ScriptedAI
{
    boss_eckAI(Creature *c) : ScriptedAI(c) {}

    uint32 berserk;
    
    void Reset() 
    {
        //Source Deadly Boss Mod
        berserk = 120000; //2min
    }
    
    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
            
        if(berserk < diff)
        {
            DoCast(m_creature,SPELL_ECK_BERSERK);
            berserk = 120000;
        }else berserk -= diff;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  {}
};

CreatureAI* GetAI_boss_eck(Creature *_Creature)
{
    return new boss_eckAI (_Creature);
}

void AddSC_boss_eck()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_eck";
    newscript->GetAI = GetAI_boss_eck;
    newscript->RegisterSelf();
}
