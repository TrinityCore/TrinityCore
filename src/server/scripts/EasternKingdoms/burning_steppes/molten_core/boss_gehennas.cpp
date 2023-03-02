/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Gehennas
SD%Complete: 100
SDComment: -
SDCategory: Molten Core
EndScriptData */

#include "scriptPCH.h"
#include "molten_core.h"

enum
{
    SPELL_GEHENNAS_CURSE        = 19716,
    SPELL_RAIN_OF_FIRE          = 19717,
    SPELL_SHADOW_BOLT_RANDOM    = 19728,
    SPELL_SHADOW_BOLT_TARGET    = 19729,
};

struct boss_gehennasAI : public ScriptedAI
{
    boss_gehennasAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 m_uiGehennasCurseTimer;
    uint32 m_uiRainOfFireTimer;
    uint32 m_uiShadowBoltRandomTimer;
    uint32 m_uiShadowBoltTargetTimer;

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        m_uiGehennasCurseTimer = urand(5 * IN_MILLISECONDS, 10 * IN_MILLISECONDS);
        m_uiRainOfFireTimer = urand(6 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
        m_uiShadowBoltRandomTimer = urand(3 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);
        m_uiShadowBoltTargetTimer = urand(3 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_GEHENNAS, NOT_STARTED);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GEHENNAS, IN_PROGRESS);
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GEHENNAS, DONE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Rain of Fire
        if (m_uiRainOfFireTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_RAIN_OF_FIRE) == CAST_OK)
                m_uiRainOfFireTimer = urand(6 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
        }
        else
            m_uiRainOfFireTimer -= uiDiff;

        // Gehennas' Curse
        if (m_uiGehennasCurseTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_GEHENNAS_CURSE) == CAST_OK)
                m_uiGehennasCurseTimer = urand(25 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
        }
        else
            m_uiGehennasCurseTimer -= uiDiff;

        // Shadow Bolt (random)
        if (m_uiShadowBoltRandomTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_SHADOW_BOLT_RANDOM) == CAST_OK)
                m_uiShadowBoltRandomTimer = urand(3 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);
        }
        else
            m_uiShadowBoltRandomTimer -= uiDiff;

        // Shadow Bolt (target)
        if (m_uiShadowBoltTargetTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOW_BOLT_TARGET) == CAST_OK)
                m_uiShadowBoltTargetTimer = urand(3 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);
        }
        else
            m_uiShadowBoltTargetTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gehennas(Creature* pCreature)
{
    return new boss_gehennasAI(pCreature);
}

void AddSC_boss_gehennas()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_gehennas";
    newscript->GetAI = &GetAI_boss_gehennas;
    newscript->RegisterSelf();
}
