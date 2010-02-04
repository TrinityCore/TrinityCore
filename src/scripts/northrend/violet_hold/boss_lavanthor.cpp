/* Script Data Start
SDName: Boss lavanthor
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

enum Spells
{
  SPELL_CAUTERIZING_FLAMES                      = 59466, //Only in heroic
  SPELL_FIREBOLT                                = 54235,
  H_SPELL_FIREBOLT                              = 59468,
  SPELL_FLAME_BREATH                            = 54282,
  H_SPELL_FLAME_BREATH                          = 59469,
  SPELL_LAVA_BURN                               = 54249,
  H_SPELL_LAVA_BURN                             = 59594
};

struct boss_lavanthorAI : public ScriptedAI
{
    boss_lavanthorAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiFireboltTimer;
    uint32 uiFlameBreathTimer;
    uint32 uiLavaBurnTimer;
    uint32 uiCauterizingFlamesTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        uiFireboltTimer = 1000;
        uiFlameBreathTimer = 5000;
        uiLavaBurnTimer = 10000;
        uiCauterizingFlamesTimer = 3000;
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

        if (uiFireboltTimer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_FIREBOLT, H_SPELL_FIREBOLT));
            uiFireboltTimer = urand(5000,13000);
        } else uiFireboltTimer -= diff;

        if (uiFlameBreathTimer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_FLAME_BREATH, H_SPELL_FLAME_BREATH));
            uiFlameBreathTimer = urand(10000,15000);
        } else uiFlameBreathTimer -= diff;

        if (uiLavaBurnTimer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_LAVA_BURN, H_SPELL_LAVA_BURN));
            uiLavaBurnTimer = urand(15000,23000);
        }

        if (IsHeroic())
        {
            if (uiCauterizingFlamesTimer <= diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CAUTERIZING_FLAMES);
                uiCauterizingFlamesTimer = urand(10000,16000);
            } else uiCauterizingFlamesTimer -= diff;
        }

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
                pInstance->SetData(DATA_WAVE_COUNT, 13);
            }
        }
    }
};

CreatureAI* GetAI_boss_lavanthor(Creature* pCreature)
{
    return new boss_lavanthorAI (pCreature);
}

void AddSC_boss_lavanthor()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_lavanthor";
    newscript->GetAI = &GetAI_boss_lavanthor;
    newscript->RegisterSelf();
}
