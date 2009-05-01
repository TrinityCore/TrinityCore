/* Script Data Start
SDName: Boss slad_ran
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_slad_ran' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_POISON_NOVA                           55081
#define SPELL_POISON_NOVA_2                         59842
//--
#define SPELL_POWERFUL_BITE                         48287
#define SPELL_POWERFUL_BITE_2                       59840
//--
#define SPELL_VENOM_BOLT                            54970
#define SPELL_VENOM_BOLT_2                          59839
//At 30% HPStart summoning small serpents

//Yell
#define SAY_AGGRO                                 -1604017
#define SAY_SLAY_1                                -1604018
#define SAY_SLAY_2                                -1604019
#define SAY_SLAY_3                                -1604020
#define SAY_DEATH                                 -1604021
#define SAY_SUMMON_SNAKES                         -1604022  //npc 29680
#define SAY_SUMMON_CONSTRICTORS                   -1604023  //npc 29713, can cast Grip of Slad'ran (spell 55093)

struct TRINITY_DLL_DECL boss_slad_ranAI : public ScriptedAI
{
    boss_slad_ranAI(Creature *c) : ScriptedAI(c) {}

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

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 30)
        {
            //Summon 3 snakes --> npc 29680
            DoScriptText(SAY_SUMMON_SNAKES,m_creature);
        }
        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 25)
        {
            //Summon 3 constrictors --> npc 29713
            DoScriptText(SAY_SUMMON_CONSTRICTORS,m_creature);
        }

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
            case 0:DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1:DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2:DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_slad_ran(Creature *_Creature)
{
    return new boss_slad_ranAI (_Creature);
}

void AddSC_boss_slad_ran()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_slad_ran";
    newscript->GetAI = &GetAI_boss_slad_ran;
    newscript->RegisterSelf();
}
