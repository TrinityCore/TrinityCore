/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Ebonroc
SD%Complete: 90
SDComment: Thrash is missing
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    SPELL_SHADOW_FLAME          = 22539,
    SPELL_WING_BUFFET           = 23339,
    SPELL_SHADOW_OF_EBONROC     = 23340,
    SPELL_THRASH                = 3391,                     // TODO missing
};

struct boss_ebonrocAI : public ScriptedAI
{
    boss_ebonrocAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiShadowFlameTimer;
    uint32 m_uiWingBuffetTimer;
    uint32 m_uiShadowOfEbonrocTimer;

    void Reset() override
    {
        m_uiShadowFlameTimer        = 16000;                // These times are probably wrong
        m_uiWingBuffetTimer         = 30000;
        m_uiShadowOfEbonrocTimer    = 8000;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EBONROC, IN_PROGRESS);

        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EBONROC, DONE);
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_EBONROC, FAIL);
    }

    void SpellHitTarget(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_WING_BUFFET)
        {
            if (!pCaster || pCaster->GetTypeId() != TYPEID_PLAYER)
                return;
            if (m_creature->GetThreatManager().getThreat(pCaster))
                m_creature->GetThreatManager().modifyThreatPercent(pCaster, -50);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Shadow Flame Timer
        if (m_uiShadowFlameTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SHADOW_FLAME) == CAST_OK)
                m_uiShadowFlameTimer = 16000;
        }
        else
            m_uiShadowFlameTimer -= uiDiff;

        // Wing Buffet Timer
        if (m_uiWingBuffetTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WING_BUFFET) == CAST_OK)
                m_uiWingBuffetTimer = 30000;
        }
        else
            m_uiWingBuffetTimer -= uiDiff;

        // Shadow of Ebonroc Timer
        if (m_uiShadowOfEbonrocTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOW_OF_EBONROC, CF_AURA_NOT_PRESENT) == CAST_OK)
                m_uiShadowOfEbonrocTimer = 8000;
        }
        else
            m_uiShadowOfEbonrocTimer -= uiDiff;

        if (m_creature->IsAttackReady() && !urand(0, 2))
            DoCastSpellIfCan(m_creature, SPELL_THRASH);

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ebonroc(Creature* pCreature)
{
    return new boss_ebonrocAI(pCreature);
}

void AddSC_boss_ebonroc()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_ebonroc";
    pNewScript->GetAI = &GetAI_boss_ebonroc;
    pNewScript->RegisterSelf();
}
