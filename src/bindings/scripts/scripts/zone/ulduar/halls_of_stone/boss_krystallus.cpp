/* Script Data Start
SDName: Boss krystallus
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_krystallus' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_BOULDER_TOSS                             50843
#define SPELL_BOULDER_TOSS_2                           59742
#define SPELL_GROUND_SPIKE                             59750
#define SPELL_SHATTER                                  50810
#define SPELL_SHATTER_2                                61546
#define SPELL_STOMP                                    48131
#define SPELL_STOMP_2                                  59744

//Yell
#define SAY_AGGRO                                   -1599000
#define SAY_KILL                                    -1599001
#define SAY_DEATH                                   -1599002
#define SAY_SHATTER                                 -1599003

struct TRINITY_DLL_DECL boss_krystallusAI : public ScriptedAI
{
    boss_krystallusAI(Creature *c) : ScriptedAI(c) {}

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
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_krystallus(Creature *_Creature)
{
    return new boss_krystallusAI (_Creature);
}

void AddSC_boss_krystallus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_krystallus";
    newscript->GetAI = &GetAI_boss_krystallus;
    newscript->RegisterSelf();
}
