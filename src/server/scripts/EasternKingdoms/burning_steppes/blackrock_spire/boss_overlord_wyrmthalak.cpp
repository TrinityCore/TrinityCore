/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Overlord_Wyrmthalak
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_BLASTWAVE            = 11130,
    SPELL_SHOUT                = 23511,
    SPELL_CLEAVE               = 20691,
    SPELL_KNOCKAWAY            = 20686,

    NPC_SPIRESTONE_WARLORD     = 9216,
    NPC_SMOLDERTHORN_BERSERKER = 9268

};

float const afLocations[2][4] =
{
    { -39.355381f, -513.456482f, 88.472046f, 4.679872f},
    { -49.875881f, -511.896942f, 88.195160f, 4.613114f}
};

struct boss_overlordwyrmthalakAI : public ScriptedAI
{
    boss_overlordwyrmthalakAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiBlastWaveTimer;
    uint32 m_uiShoutTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiKnockawayTimer;
    bool m_bSummoned;
    bool m_bPulledByPet;
    uint32 m_uiLeashCheckTimer;

    void Reset() override
    {
        m_uiBlastWaveTimer = 20000;
        m_uiShoutTimer     = 2000;
        m_uiCleaveTimer    = 6000;
        m_uiKnockawayTimer = 12000;
        m_bSummoned = false;
        m_bPulledByPet = false;

        m_uiLeashCheckTimer = 5000;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() != NPC_SPIRESTONE_WARLORD && pSummoned->GetEntry() != NPC_SMOLDERTHORN_BERSERKER)
            return;

        if (m_creature->GetVictim())
        {
            Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            pSummoned->AI()->AttackStart(pTarget ? pTarget : m_creature->GetVictim());
        }
    }

    void EnterCombat(Unit* pUnit) override
    {
        // Prevent exploit where pet can run through the wall and pull the boss.
        if (Unit* pOwner = pUnit->GetOwner())
            if (!pOwner->IsWithinLOSInMap(m_creature))
                m_bPulledByPet = true;

        ScriptedAI::EnterCombat(pUnit);
    }

    void LeashIfOutOfCombatArea(uint32 uiDiff)
    {
        if (m_uiLeashCheckTimer < uiDiff)
            m_uiLeashCheckTimer = 3500;
        else
        {
            m_uiLeashCheckTimer -= uiDiff;
            return;
        }

        if (m_bPulledByPet || (m_creature->GetPositionZ() > 100.0f))
            EnterEvadeMode();
    } 

    void UpdateAI(uint32 const uiDiff) override
    {
        // Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Prevent players from pulling Wyrmthalak into UBRS
        LeashIfOutOfCombatArea(uiDiff);

        // BlastWave
        if (m_uiBlastWaveTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_BLASTWAVE);
            m_uiBlastWaveTimer = 20000;
        }
        else
            m_uiBlastWaveTimer -= uiDiff;

        // Shout
        if (m_uiShoutTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_SHOUT);
            m_uiShoutTimer = 10000;
        }
        else
            m_uiShoutTimer -= uiDiff;

        // Cleave
        if (m_uiCleaveTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE);
            m_uiCleaveTimer = 7000;
        }
        else
            m_uiCleaveTimer -= uiDiff;

        // Knockaway
        if (m_uiKnockawayTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_KNOCKAWAY);
            m_uiKnockawayTimer = 14000;
        }
        else
            m_uiKnockawayTimer -= uiDiff;

        // Summon two Beserks
        if (!m_bSummoned && m_creature->GetHealthPercent() < 51.0f)
        {
            m_creature->SummonCreature(NPC_SPIRESTONE_WARLORD, afLocations[0][0], afLocations[0][1], afLocations[0][2], afLocations[0][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
            m_creature->SummonCreature(NPC_SMOLDERTHORN_BERSERKER, afLocations[1][0], afLocations[1][1], afLocations[1][2], afLocations[1][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);

            m_bSummoned = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_overlordwyrmthalak(Creature* pCreature)
{
    return new boss_overlordwyrmthalakAI(pCreature);
}

void AddSC_boss_overlordwyrmthalak()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_overlord_wyrmthalak";
    newscript->GetAI = &GetAI_boss_overlordwyrmthalak;
    newscript->RegisterSelf();
}
