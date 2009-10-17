/* Script Data Start
SDName: Boss ichoron
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
    SPELL_DRAINED                                  = 59820,
    SPELL_FRENZY                                   = 54312,
    H_SPELL_FRENZY                                 = 59522,
    SPELL_PROTECTIVE_BUBBLE                        = 54306,
    SPELL_WATER_BLAST                              = 54237,
    H_SPELL_WATER_BLAST                            = 59520,
    SPELL_WATER_BOLT_VOLLEY                        = 54241,
    H_SPELL_WATER_BOLT_VOLLEY                      = 59521
};

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1608018,
    SAY_SLAY_1                                  = -1608019,
    SAY_SLAY_2                                  = -1608020,
    SAY_SLAY_3                                  = -1608021,
    SAY_DEATH                                   = -1608022,
    SAY_SPAWN                                   = -1608023,
    SAY_ENRAGE                                  = -1608024,
    SAY_SHATTER                                 = -1608025,
    SAY_BUBBLE                                  = -1608026
};

enum CombatPhase
{
    BUBBLED,
    SUMMONS,
    DPS
};

struct TRINITY_DLL_DECL boss_ichoronAI : public ScriptedAI
{
    boss_ichoronAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    CombatPhase Phase;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        Phase = BUBBLED;
        
        DoCast(m_creature, SPELL_PROTECTIVE_BUBBLE);
        
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
                pInstance->SetData(DATA_2ND_BOSS_EVENT, DONE);
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

CreatureAI* GetAI_boss_ichoron(Creature* pCreature)
{
    return new boss_ichoronAI (pCreature);
}

void AddSC_boss_ichoron()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_ichoron";
    newscript->GetAI = &GetAI_boss_ichoron;
    newscript->RegisterSelf();
}
