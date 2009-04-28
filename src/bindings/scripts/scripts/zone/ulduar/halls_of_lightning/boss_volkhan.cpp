/* Script Data Start
SDName: Boss volkhan
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_volkhan' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_HEAT                                  52387
#define SPELL_HEAT_2                                59528
#define SPELL_SHATTERING_STOMP                      52237
#define SPELL_SHATTERING_STOMP_2                    59529
#define SPELL_TEMPER                                52238 //Dummy ---> Strikes Volkhan's Anvil, creating a number of Molten Golems.

#define NPC_VOLKHANS_ANVIL                          28823
#define MOB_MOLTEN_GOLEM                            28695

//Yells
#define SAY_AGGRO                                -1602028
#define SAY_SLAY_1                               -1602029
#define SAY_SLAY_2                               -1602030
#define SAY_SLAY_3                               -1602031
#define SAY_DEATH                                -1602032
#define SAY_STOMP_1                              -1602033
#define SAY_STOMP_2                              -1602034
#define SAY_FORGE_1                              -1602035
#define SAY_FORGE_2                              -1602036

struct TRINITY_DLL_DECL boss_volkhanAI : public ScriptedAI
{
    boss_volkhanAI(Creature *c) : ScriptedAI(c) {}
    
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

/*######
## Mob Molten Golem
######*/
//Molten Golem Spells
#define SPELL_BLAST_WAVE                            23113
#define SPELL_IMMOLATION_STRIKE                     52433
#define SPELL_IMMOLATION_STRIKE_2                   59530 
//Effect #1    Apply Aura: Periodic Damage, value: 900 every 3 seconds
//Effect #2    School Damage (Fire), value: 900
//Effect #3    Script Effect
#define SPELL_SHATTER                               52429 
//Effect #1    School Damage (Physical), value: 9250 to 10750, radius: 10 yards
//Effect #2    Dummy, Server-side script
#define SPELL_SHATTER_2    

struct TRINITY_DLL_DECL mob_molten_golemAI : public ScriptedAI
{
    mob_molten_golemAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit* who) {}
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

CreatureAI* GetAI_mob_molten_golem(Creature *_Creature)
{
    return new mob_molten_golemAI (_Creature);
}

CreatureAI* GetAI_boss_volkhan(Creature *_Creature)
{
    return new boss_volkhanAI (_Creature);
}

void AddSC_boss_volkhan()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_volkhan";
    newscript->GetAI = GetAI_boss_volkhan;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="mob_molten_golem";
    newscript->GetAI = GetAI_mob_molten_golem;
    newscript->RegisterSelf();
}
