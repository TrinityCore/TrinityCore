/* Script Data Start
SDName: Boss gal_darah
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
#define SPELL_ENRAGE                                  55285
#define SPELL_IMPALING_CHARGE                         54956
#define SPELL_STOMP                                   55292

#define SPELL_PUNCTURE                                55276
#define SPELL_STAMPEDE                                55218
#define SPELL_WHIRLING_SLASH                          55285

//Yells
#define SAY_AGGRO                                  -1604000
#define SAY_SLAY_1                                 -1604001
#define SAY_SLAY_2                                 -1604002
#define SAY_SLAY_3                                 -1604003
#define SAY_DEATH                                  -1604004
#define SAY_SUMMON_RHINO_1                         -1604005
#define SAY_SUMMON_RHINO_2                         -1604006
#define SAY_SUMMON_RHINO_3                         -1604007
#define SAY_TRANSFORM_1                            -1604008  //Phase change
#define SAY_TRANSFORM_2                            -1604009

struct TRINITY_DLL_DECL boss_gal_darahAI : public ScriptedAI
{
    boss_gal_darahAI(Creature *c) : ScriptedAI(c) {}

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

CreatureAI* GetAI_boss_gal_darah(Creature *_Creature)
{
    return new boss_gal_darahAI (_Creature);
}

void AddSC_boss_gal_darah()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_gal_darah";
    newscript->GetAI = &GetAI_boss_gal_darah;
    newscript->RegisterSelf();
}
