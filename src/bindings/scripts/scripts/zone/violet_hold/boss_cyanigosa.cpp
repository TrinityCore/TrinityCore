/* Script Data Start
SDName: Boss cyanigosa
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
#define SPELL_ARCANE_VACUM                             58694
#define SPELL_BLIZZARD                                 58693
#define SPELL_MANA_DESTRUCTION                         59374
#define SPELL_TAIL_SWEEP                               58690
#define SPELL_UNCONTROLLABLE_ENERGY                    58688

//Yells
#define SAY_AGGRO                                   -1608000
#define SAY_SLAY_1                                  -1608001
#define SAY_SLAY_2                                  -1608002
#define SAY_SLAY_3                                  -1608003
#define SAY_DEATH                                   -1608004
#define SAY_SPAWN                                   -1608005
#define SAY_DISRUPTION                              -1608006
#define SAY_BREATH_ATTACK                           -1608007
#define SAY_SPECIAL_ATTACK_1                        -1608008
#define SAY_SPECIAL_ATTACK_2                        -1608009

struct TRINITY_DLL_DECL boss_cyanigosaAI : public ScriptedAI
{
    boss_cyanigosaAI(Creature *c) : ScriptedAI(c) {}
    
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

CreatureAI* GetAI_boss_cyanigosa(Creature *_Creature)
{
    return new boss_cyanigosaAI (_Creature);
}

void AddSC_boss_cyanigosa()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_cyanigosa";
    newscript->GetAI = GetAI_boss_cyanigosa;
    newscript->RegisterSelf();
}
