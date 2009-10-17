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
#include "def_violet_hold.h"

enum Spells
{
    SPELL_ARCANE_BARRAGE_VOLLEY                    = 54202,
    H_SPELL_ARCANE_BARRAGE_VOLLEY                  = 59483,
    SPELL_ARCANE_BUFFET                            = 54226,
    H_SPELL_ARCANE_BUFFET                          = 59485,
    SPELL_SUMMON_ETHEREAL_SPHERE_1                 = 54102,
    H_SPELL_SUMMON_ETHEREAL_SPHERE_1               = 61337,
    SPELL_SUMMON_ETHEREAL_SPHERE_2                 = 54137,
    H_SPELL_SUMMON_ETHEREAL_SPHERE_2               = 61338,
    SPELL_SUMMON_ETHEREAL_SPHERE_3                 = 54138,
    H_SPELL_SUMMON_ETHEREAL_SPHERE_3               = 61339
};

enum Creatures
{
    CREATURE_ETHEREAL_SPHERE                       = 29271,
    H_CREATURE_ETHEREAL_SPHERE                     = 32582
};

enum CreatureSpells
{
    SPELL_ARCANE_POWER                             = 54160,
    H_SPELL_ARCANE_POWER                           = 59474,
    SPELL_SUMMON_PLAYERS                           = 54164
};

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1608027,
    SAY_SLAY_1                                  = -1608028,
    SAY_SLAY_2                                  = -1608029,
    SAY_SLAY_3                                  = -1608030,
    SAY_DEATH                                   = -1608031,
    SAY_SPAWN                                   = -1608032,
    SAY_CHARGED                                 = -1608033,
    SAY_REPEAT_SUMMON_1                         = -1608034,
    SAY_REPEAT_SUMMON_2                         = -1608035,
    SAY_SUMMON_ENERGY                           = -1608036
};

struct TRINITY_DLL_DECL boss_xevozzAI : public ScriptedAI
{
    boss_xevozzAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }
    }
    
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }
    
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
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
            {
                pInstance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                pInstance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
            {
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
                pInstance->SetData(DATA_WAVE_COUNT, 13);
            }
        }
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
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
    newscript->Name = "boss_xevozz";
    newscript->GetAI = &GetAI_boss_xevozz;
    newscript->RegisterSelf();
}
