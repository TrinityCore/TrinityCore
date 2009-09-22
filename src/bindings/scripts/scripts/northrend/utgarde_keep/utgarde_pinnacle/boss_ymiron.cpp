/* Script Data Start
SDName: Boss ymiron
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_ymiron' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_pinnacle.h"

//Spells
#define SPELL_BANE                                48294
#define SPELL_DARK_SLASH                          48292
#define SPELL_FETID_ROT                           48291
#define SPELL_SCREAMS_OF_THE_DEAD                 51750
#define SPELL_SPIRIT_BURST                        48529
#define SPELL_SPIRIT_STRIKE                       48423
//every 20% stuns the party and runs to a boat

//not in db
//Yell
#define SAY_AGGRO                               -1575028
#define SAY_SLAY_1                              -1575029
#define SAY_SLAY_2                              -1575030
#define SAY_SLAY_3                              -1575031
#define SAY_SLAY_4                              -1575032
#define SAY_DEATH                               -1575033
#define SAY_SUMMON_BJORN                        -1575034
#define SAY_SUMMON_HALDOR                       -1575035
#define SAY_SUMMON_RANULF                       -1575036
#define SAY_SUMMON_TORGYN                       -1575037

struct TRINITY_DLL_DECL boss_ymironAI : public ScriptedAI
{
    boss_ymironAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_KING_YMIRON_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_KING_YMIRON_EVENT, IN_PROGRESS);
    }

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

        if (pInstance)
            pInstance->SetData(DATA_KING_YMIRON_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3,SAY_SLAY_4), m_creature);
    }
};

CreatureAI* GetAI_boss_ymiron(Creature* pCreature)
{
    return new boss_ymironAI(pCreature);
}

void AddSC_boss_ymiron()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_ymiron";
    newscript->GetAI = &GetAI_boss_ymiron;
    newscript->RegisterSelf();
}
