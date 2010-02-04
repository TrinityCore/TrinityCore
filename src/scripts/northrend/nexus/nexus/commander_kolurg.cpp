/* Script Data Start
SDName: Boss Commander Kolurg
SDAuthor: LordVanMartin
SD%Complete:
SDComment:  Only Alliance Heroic
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_commander_kolurg' where entry = '';
*** SQL END ***/
#include "ScriptedPch.h"

#define SPELL_BATTLE_SHOUT                                    31403
#define SPELL_CHARGE                                          60067
#define SPELL_FRIGHTENING_SHOUT                               19134
#define SPELL_WHIRLWIND_1                                     38619
#define SPELL_WHIRLWIND_2                                     38618

//not used
//Yell
#define SAY_AGGRO                                          -1576024
#define SAY_KILL                                           -1576025
#define SAY_DEATH                                          -1576026

struct boss_commander_kolurgAI : public ScriptedAI
{
    boss_commander_kolurgAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void EnterCombat(Unit* who) {}
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
};

CreatureAI* GetAI_boss_commander_kolurg(Creature* pCreature)
{
    return new boss_commander_kolurgAI (pCreature);
}

void AddSC_boss_commander_kolurg()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_commander_kolurg";
    newscript->GetAI = &GetAI_boss_commander_kolurg;
    newscript->RegisterSelf();
}
