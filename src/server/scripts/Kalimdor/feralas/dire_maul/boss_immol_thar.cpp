/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"

enum
{
    SPELL_TRAMPLE              = 5568,
    SPELL_INFECTED_BITE        = 16128,
    SPELL_EYE_OF_IMMOL_THAR    = 22899,
    SPELL_PORTAL_OF_IMMOL_THAR = 22950,
    SPELL_ENRAGE               = 8269,
};

// boss_immol_thar
struct boss_immol_tharAI : public ScriptedAI
{
    boss_immol_tharAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiTrampleTimer;
    uint32 m_uiInfectedBiteTimer;
    uint32 m_uiEyeOfImmolTharTimer;
    uint32 m_uiPortalOfImmolTharTimer;
    uint32 m_uiEnrageTimer;
    uint32 CheckBug_Timer;
    bool   m_bEngage;

    bool ManageTimer(uint32 const diff, uint32* timer, uint32 cooldown)
    {
        if ((*timer) < diff)
        {
            (*timer) = cooldown;
            return true;
        }
        (*timer) -= diff;
        return false;
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_IMMOL_THAR, DONE);
    }

    void Reset() override
    {
        m_uiEnrageTimer            = 50000;
        m_uiTrampleTimer           = urand(5000, 9000);
        m_uiInfectedBiteTimer      = urand(2000, 4000);
        m_uiEyeOfImmolTharTimer    = urand(7000, 12000);
        m_uiPortalOfImmolTharTimer = urand(10000, 14000);
        CheckBug_Timer = 0;
        m_bEngage = false;
    }

    void EnterEvadeMode() override
    {
        m_creature->RemoveGuardians();
        
        ScriptedAI::EnterEvadeMode();
    }

    void Aggro(Unit* pWho) override
    {
        if(!m_bEngage)
            m_bEngage = true;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            // En cas de bug pathfinding
            CheckBug_Timer += uiDiff;
            if (CheckBug_Timer > 5000)
            {
                EnterEvadeMode();
                m_creature->CombatStop();
                m_creature->SetHealth(m_creature->GetMaxHealth());
            }
            return;
        }
        else
            CheckBug_Timer = 0;

        if (m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (ManageTimer(uiDiff, &m_uiTrampleTimer,              urand(9000, 14000)))
            DoCastSpellIfCan(m_creature, SPELL_TRAMPLE);

        if (ManageTimer(uiDiff, &m_uiInfectedBiteTimer,         urand(8000, 12000)))
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_INFECTED_BITE);

        if (ManageTimer(uiDiff, &m_uiEyeOfImmolTharTimer,       urand(15000, 22000)))
        {
            if (Creature* tmp = m_creature->SummonCreature(14396,
                m_creature->GetPositionX(),
                m_creature->GetPositionY(),
                m_creature->GetPositionZ(),
                m_creature->GetOrientation(),
                TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000))
            {
                m_creature->SendSpellGo(tmp, 25681);
                tmp->Attack(m_creature->GetVictim(), true);
            }
        }

        if (ManageTimer(uiDiff, &m_uiPortalOfImmolTharTimer,    urand(17000, 24000)))
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                /** Invoque player in front of him */
                float x = m_creature->GetPositionX();
                float y = m_creature->GetPositionY();
                float z = m_creature->GetPositionZ() + 1;
                float orientation = pTarget->GetOrientation();
                m_creature->SendSpellGo(pTarget, 25681);
                pTarget->NearTeleportTo(x, y, z, orientation);
                m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
            }
        }
        if (m_uiEnrageTimer < uiDiff)
        {
            if (!m_creature->HasAura(SPELL_ENRAGE) && m_bEngage)
                m_creature->CastSpell(m_creature, SPELL_ENRAGE, true);
        }
        else
            m_uiEnrageTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_immol_thar(Creature* pCreature)
{
    return new boss_immol_tharAI(pCreature);
}

void AddSC_boss_immol_thar()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_immol_thar";
    pNewScript->GetAI = &GetAI_boss_immol_thar;
    pNewScript->RegisterSelf();
}
