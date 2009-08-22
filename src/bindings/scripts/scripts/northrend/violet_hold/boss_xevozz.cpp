/* Script Data Start
SDName: Boss xevozz
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
#define SPELL_ARCANE_BARRAGE_VOLLEY                    54202
#define SPELL_ARCANE_BUFFET                            54226
#define SPELL_SUMMON_ETHEREAL_SPHERE_1                 54102
#define SPELL_SUMMON_ETHEREAL_SPHERE_2                 54137
#define SPELL_SUMMON_ETHEREAL_SPHERE_3                 54138

//Yells
#define SAY_AGGRO                                   -1608027
#define SAY_SLAY_1                                  -1608028
#define SAY_SLAY_2                                  -1608029
#define SAY_SLAY_3                                  -1608030
#define SAY_DEATH                                   -1608031
#define SAY_SPAWN                                   -1608032
#define SAY_CHARGED                                 -1608033
#define SAY_REPEAT_SUMMON_1                         -1608034
#define SAY_REPEAT_SUMMON_2                         -1608035
#define SAY_SUMMON_ENERGY                           -1608036

struct TRINITY_DLL_DECL boss_xevozzAI : public ScriptedAI
{
    boss_xevozzAI(Creature *c) : ScriptedAI(c) {}

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
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_xevozz(Creature* pCreature)
{
    return new boss_xevozzAI (pCreature);
}

void AddSC_boss_xevozz()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_xevozz";
    newscript->GetAI = &GetAI_boss_xevozz;
    newscript->RegisterSelf();
}
