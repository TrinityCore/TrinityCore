/* Script Data Start
SDName: Boss novos
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_novos' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_ARCANE_BLAST_N                      49198
#define SPELL_ARCANE_BLAST_H                      59909
#define SPELL_ARCANE_FIELD                        47346
#define SPELL_BLIZZARD_N                          49034
#define SPELL_BLIZZARD_H                          59854
#define SPELL_FROSTBOLT_N                         49037
#define SPELL_FROSTBOLT_H                         59855
#define SPELL_WRATH_OF_MISERY_N                   50089
#define SPELL_WRATH_OF_MISERY_H                   59856
#define SPELL_SUMMON_MINIONS                      59910 //Summons an army of Fetid Troll Corpses to assist the caster.

//Yell
#define SAY_AGGRO                              -1600000
#define SAY_KILL                               -1600001
#define SAY_DEATH                              -1600002
#define SAY_NECRO_ADD                          -1600003
#define SAY_REUBBLE_1                          -1600004
#define SAY_REUBBLE_2                          -1600005

struct TRINITY_DLL_DECL boss_novosAI : public ScriptedAI
{
    boss_novosAI(Creature *c) : ScriptedAI(c) {}

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
    void JustDied(Unit* killer)  {}
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_novos(Creature *_Creature)
{
    return new boss_novosAI (_Creature);
}

void AddSC_boss_novos()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_novos";
    newscript->GetAI = &GetAI_boss_novos;
    newscript->RegisterSelf();
}
