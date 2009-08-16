/* Script Data Start
SDName: Boss moorabi
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_moorabi' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_DETERMINED_GORE                       55102
#define SPELL_DETERMINED_STAB_2                     59444
#define SPELL_DETERMINED_STAB_3                     55104

#define SPELL_GROUND_TREMOR                         55142
#define SPELL_MOJO_FRENZY                           55163
#define SPELL_NUMBING_ROAR_1                        55100
#define SPELL_NUMBING_ROAR_2                        55106
#define SPELL_TRANSFORMATION                        55098 //Periodic, The caster transforms into a powerful mammoth, increasing Physical damage done by 25% and granting immunity to Stun effects.
#define SPELL_QUAKE                                 55101

//Yell
#define SAY_AGGRO                                 -1604010
#define SAY_SLAY_1                                -1604011
#define SAY_SLAY_2                                -1604012
#define SAY_SLAY_3                                -1604013
#define SAY_DEATH                                 -1604014
#define SAY_TRANSFORM                             -1604015
#define SAY_QUAKE                                 -1604016

struct TRINITY_DLL_DECL boss_moorabiAI : public ScriptedAI
{
    boss_moorabiAI(Creature *c) : ScriptedAI(c) {}

    uint32 phase;

    void Reset() {}
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        phase =1;
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
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_moorabi(Creature* pCreature)
{
    return new boss_moorabiAI (pCreature);
}

void AddSC_boss_moorabi()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_moorabi";
    newscript->GetAI = &GetAI_boss_moorabi;
    newscript->RegisterSelf();
}
