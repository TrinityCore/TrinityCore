/* Script Data Start
SDName: Boss drakos
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
#define SPELL_MAGIC_PULL                           51336
#define SPELL_THUNDERING_STOMP                     50774
#define SPELL_THUNDERING_STOMP_2                   59370

//Yell
#define SAY_AGGRO                               -1578000
#define SAY_KILL_1                              -1578001
#define SAY_KILL_2                              -1578002
#define SAY_KILL_3                              -1578003
#define SAY_DEATH                               -1578004
#define SAY_PULL_1                              -1578005
#define SAY_PULL_2                              -1578006
#define SAY_PULL_3                              -1578007
#define SAY_PULL_4                              -1578008
#define SAY_STOMP_1                             -1578009
#define SAY_STOMP_2                             -1578010
#define SAY_STOMP_3                             -1578011

struct TRINITY_DLL_DECL boss_drakosAI : public ScriptedAI
{
    boss_drakosAI(Creature *c) : ScriptedAI(c) {}

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
        if (!UpdateVictim())
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
            case 0: DoScriptText(SAY_KILL_1, m_creature);break;
            case 1: DoScriptText(SAY_KILL_2, m_creature);break;
            case 2: DoScriptText(SAY_KILL_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_drakos(Creature *_Creature)
{
    return new boss_drakosAI (_Creature);
}

void AddSC_boss_drakos()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_drakos";
    newscript->GetAI = &GetAI_boss_drakos;
    newscript->RegisterSelf();
}
