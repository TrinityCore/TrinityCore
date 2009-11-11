/* Script Data Start
SDName: Boss zuramat
SD%Complete:
SDComment: The phasemask for the voids dosen't work.
SDCategory:
Script Data End */

#include "precompiled.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_SHROUD_OF_DARKNESS                       = 54524,
    H_SPELL_SHROUD_OF_DARKNESS                     = 59745,
    SPELL_SUMMON_VOID_SENTRY                       = 54369,
    SPELL_VOID_SHIFT                               = 54361,
    H_SPELL_VOID_SHIFT                             = 59743,
    SPELL_VOID_SHIFTED                             = 54343,

    SPELL_ZUMARAT_ADD_2                            = 59747,
    H_SPELL_ZUMARAT_ADD_2                          = 59747
};

enum Creatures
{
    CREATURE_VOID_SENTRY                           = 29364
};

//not in db
enum Yells
{
    SAY_AGGRO                                   = -1608037,
    SAY_SLAY_1                                  = -1608038,
    SAY_SLAY_2                                  = -1608039,
    SAY_SLAY_3                                  = -1608040,
    SAY_DEATH                                   = -1608041,
    SAY_SPAWN                                   = -1608042,
    SAY_SHIELD                                  = -1608043,
    SAY_WHISPER                                 = -1608044
};

struct TRINITY_DLL_DECL boss_zuramatAI : public ScriptedAI
{
    boss_zuramatAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    Unit* Shifted;

    uint32 SpellVoidShiftTimer;
    uint32 SpellSummonVoidTimer;
    uint32 SpellShroudOfDarknessTimer;
    uint32 SpellVoidShiftedTimer;

    bool shiftcast;

    void Reset()
    {
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        SpellShroudOfDarknessTimer = 22000;
        SpellVoidShiftTimer = 15000;
        SpellSummonVoidTimer = 12000;

        shiftcast = false;
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

        if (SpellSummonVoidTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SUMMON_VOID_SENTRY, false);
            SpellSummonVoidTimer = 20000;
        } else SpellSummonVoidTimer -=diff;

        if(SpellVoidShiftedTimer < diff && shiftcast)
        {
            if (Shifted)
                DoCast(Shifted, SPELL_VOID_SHIFTED, false);
            shiftcast = false;
        } else SpellVoidShiftedTimer -=diff;

        if (SpellVoidShiftTimer <= diff)
        {
            Shifted =  SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (Shifted)
            {
                DoCast(Shifted, HEROIC(SPELL_VOID_SHIFT, H_SPELL_VOID_SHIFT));
                shiftcast = true;
                SpellVoidShiftTimer = 20000;
            }
            SpellVoidShiftedTimer = 5000;
        } else SpellVoidShiftTimer -=diff;

        if (SpellShroudOfDarknessTimer <= diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_SHROUD_OF_DARKNESS, H_SPELL_SHROUD_OF_DARKNESS));
            SpellShroudOfDarknessTimer = 20000;
        } else SpellShroudOfDarknessTimer -=diff;

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
    
    void JustSummoned(Creature* summon)
    {
        summon->AI()->AttackStart(m_creature->getVictim());
        summon->AI()->DoCastAOE(HEROIC(SPELL_ZUMARAT_ADD_2, H_SPELL_ZUMARAT_ADD_2));
        summon->SetPhaseMask(17,true);
    }
};

CreatureAI* GetAI_boss_zuramat(Creature* pCreature)
{
    return new boss_zuramatAI (pCreature);
}

void AddSC_boss_zuramat()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_zuramat";
    newscript->GetAI = &GetAI_boss_zuramat;
    newscript->RegisterSelf();
}
