/* Copyright (C) 2009 - 2010 Nostalrius <http://nostalrius.ath.cx/>
 * Auteur        : Daemon
 * All rights reserved */

#include "scriptPCH.h"
#include "dire_maul.h"


enum
{
    SPELL_INTENSIVE_PAIN =   22478,
    SPELL_SACRIFICE      =   22651,
};

// boss_zevrim
struct boss_zevrimAI : public ScriptedAI
{
    boss_zevrimAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_dire_maul*) pCreature->GetInstanceData();
        Reset();
    }

    instance_dire_maul* m_pInstance;
    uint32 m_uiIntensePainTimer;
    uint32 m_uiSacrificeTimer;

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_BOSS_ZEVRIM, DONE);
    }

    void Reset() override
    {
        m_uiIntensePainTimer    = urand(5000, 9000);
        m_uiSacrificeTimer      = urand(9000, 12000);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || m_creature->IsNonMeleeSpellCasted(false))
            return;

        if (m_uiIntensePainTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_INTENSIVE_PAIN);
            m_uiIntensePainTimer = urand(20000, 26000);
        }
        else
            m_uiIntensePainTimer -= uiDiff;

        if (m_uiSacrificeTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_NO_TOTEM))
                if (!pTarget->IsPet())
                {
                    DoCastSpellIfCan(pTarget, SPELL_SACRIFICE);
                    m_uiSacrificeTimer = urand(15000, 18000);
                }
        }
        else
            m_uiSacrificeTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_zevrim(Creature* pCreature)
{
    return new boss_zevrimAI(pCreature);
}

void AddSC_boss_zevrim()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "boss_zevrim";
    pNewScript->GetAI = &GetAI_boss_zevrim;
    pNewScript->RegisterSelf();
}
