/* Script Data Start
SDName: Boss moragg
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "ScriptedPch.h"
#include "violet_hold.h"

//Spells
enum Spells
{
    SPELL_CORROSIVE_SALIVA                     = 54527,
    SPELL_OPTIC_LINK                           = 54396
};

struct TRINITY_DLL_DECL boss_moraggAI : public ScriptedAI
{
    boss_moraggAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiOpticLinkTimer;
    uint32 uiCorrosiveSalivaTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiOpticLinkTimer = 10000;
        uiCorrosiveSalivaTimer = 5000;

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
        if (pInstance)
        {
            if (pInstance->GetData(DATA_WAVE_COUNT) == 6)
                pInstance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (pInstance->GetData(DATA_WAVE_COUNT) == 12)
                pInstance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }
    }

    void AttackStart(Unit* pWho)
    {
        if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE) || m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return;

        if (m_creature->Attack(pWho, true))
        {
            m_creature->AddThreat(pWho, 0.0f);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);
            DoStartMovement(pWho);
        }
    }

    void MoveInLineOfSight(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiOpticLinkTimer <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, SPELL_OPTIC_LINK);
            uiOpticLinkTimer = 15000;
        } else uiOpticLinkTimer -= diff;

        if (uiCorrosiveSalivaTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CORROSIVE_SALIVA);
            uiCorrosiveSalivaTimer = 10000;
        } else uiCorrosiveSalivaTimer -= diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
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
                pInstance->SetData(DATA_WAVE_COUNT,13);
            }
        }
    }
};

CreatureAI* GetAI_boss_moragg(Creature* pCreature)
{
    return new boss_moraggAI (pCreature);
}

void AddSC_boss_moragg()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_moragg";
    newscript->GetAI = &GetAI_boss_moragg;
    newscript->RegisterSelf();
}
