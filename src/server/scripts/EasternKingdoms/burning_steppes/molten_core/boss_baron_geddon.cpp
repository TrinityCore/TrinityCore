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
SDName: Boss_Baron_Geddon
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "scriptPCH.h"
#include "molten_core.h"

#define EMOTE_SERVICE               -1409000

#define SPELL_INFERNO               19695
#define SPELL_IGNITEMANA            19659
#define SPELL_LIVINGBOMB            20475
#define SPELL_ARMAGEDDOM            20478

struct boss_baron_geddonAI : public ScriptedAI
{
    boss_baron_geddonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 m_uiIgniteManaTimer;
    uint32 m_uiLivingBombTimer;
    uint32 m_uiInfernoTimer;
    uint32 m_uiInfernoAltTimer;
    uint32 m_uiRestoreTargetTimer;
    uint32 InfCount;
    uint32 Tick;
    bool m_bInferno;
    bool m_bArmageddon;

    ScriptedInstance* m_pInstance;

    void Reset() override
    {
        m_uiIgniteManaTimer    = urand(10000, 15000);
        m_uiLivingBombTimer    = urand(15000, 20000);
        m_uiInfernoTimer       = urand(18000, 24000);
        m_uiRestoreTargetTimer = 0;
        m_bInferno             = false;
        m_bArmageddon          = false;

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_GEDDON, NOT_STARTED);

        m_creature->ClearUnitState(UNIT_STAT_ROOT);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GEDDON, IN_PROGRESS);
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GEDDON, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_bArmageddon)
            return;

        //If we are <5% hp cast Armageddom
        if (!m_bArmageddon)
        {
            if (m_creature->GetHealthPercent() < 5.0f)
            {
                m_creature->InterruptNonMeleeSpells(true);
                SetCombatMovement(false);
                //m_creature->SetTargetGuid(ObjectGuid());
                m_creature->CastSpell(m_creature, SPELL_ARMAGEDDOM, true);
                DoScriptText(EMOTE_SERVICE, m_creature);
                m_bArmageddon = true;
                return;
            }
        }

        if (m_uiLivingBombTimer < diff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_LIVINGBOMB) == CAST_OK)
                {
                    m_creature->SetInFront(pTarget);
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_uiLivingBombTimer = urand(12000, 15000);
                    m_uiRestoreTargetTimer = 800;
                }
            }
        }
        else
            m_uiLivingBombTimer -= diff;

        // Restore original target after casting Living Bomb on someone
        if (m_uiRestoreTargetTimer)
        {
            if (m_uiRestoreTargetTimer <= diff)
            {
                if (Unit* pTarget = m_creature->GetVictim())
                {
                    m_creature->SetInFront(pTarget);
                    m_creature->SetTargetGuid(pTarget->GetObjectGuid());
                    m_uiRestoreTargetTimer = 0;
                }
            }
            else
                m_uiRestoreTargetTimer -= diff;
        }

        if (m_uiIgniteManaTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_IGNITEMANA) == CAST_OK)
                m_uiIgniteManaTimer = urand(20000, 30000);
        }
        else
            m_uiIgniteManaTimer -= diff;

        if (m_uiInfernoTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_INFERNO) == CAST_OK)
            {
                m_uiInfernoTimer = urand(18000, 24000);
                InfCount = 0;
                Tick = 1000;
                m_bInferno = true;
                m_creature->AddUnitState(UNIT_STAT_ROOT);
            }
        }
        else
            m_uiInfernoTimer -= diff;

        // Inferno damage increases with each tick
        if (m_bInferno)
        {
            if (Tick >= 1000)
            {
                int Damage = 0;
                switch (InfCount)
                {
                    case 0:
                    case 1:
                        Damage = 500;
                        break;
                    case 2:
                    case 3:
                        Damage = 1000;
                        break;
                    case 4:
                    case 5:
                        Damage = 1500;
                        break;
                    case 6:
                    case 7:
                        Damage = 2000;
                        break;
                    case 8:
                        Damage = 2500;
                        m_bInferno = false;
                        m_creature->ClearUnitState(UNIT_STAT_ROOT);
                        break;
                }
                m_creature->CastCustomSpell(m_creature, 19698, Damage, {}, {}, true);
                InfCount++;
                Tick = 0;
            }
            Tick += diff;
            return;
        }


        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_baron_geddon(Creature* pCreature)
{
    return new boss_baron_geddonAI(pCreature);
}

void AddSC_boss_baron_geddon()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_baron_geddon";
    newscript->GetAI = &GetAI_boss_baron_geddon;
    newscript->RegisterSelf();
}
