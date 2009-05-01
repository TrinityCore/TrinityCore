/* Script Data Start
SDName: Boss loken
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_loken' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_ARC_NOVA                            52921
//Effect #1    School Damage (Nature), Value: 3238 to 3762
//Effect #2    Apply Aura: Dummy,  Value: 3238 to 3762, Server-side script

#define SPELL_LIGHTNING_NOVA                      52960
#define SPELL_LIGHTNING_NOVA_2                    59835

//Yell
#define SAY_AGGRO                              -1602015
#define SAY_INTRO_1                            -1602016
#define SAY_INTRO_2                            -1602017
#define SAY_SLAY_1                             -1602018
#define SAY_SLAY_2                             -1602019
#define SAY_SLAY_3                             -1602020
#define SAY_DEATH                              -1602021
#define SAY_NOVA_1                             -1602022
#define SAY_NOVA_2                             -1602023
#define SAY_NOVA_3                             -1602024
#define SAY_75HEALTH                           -1602025
#define SAY_50HEALTH                           -1602026
#define SAY_25HEALTH                           -1602027

struct TRINITY_DLL_DECL boss_lokenAI : public ScriptedAI
{
    boss_lokenAI(Creature *c) : ScriptedAI(c) {}

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

CreatureAI* GetAI_boss_loken(Creature *_Creature)
{
    return new boss_lokenAI (_Creature);
}

void AddSC_boss_loken()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_loken";
    newscript->GetAI = &GetAI_boss_loken;
    newscript->RegisterSelf();
}
