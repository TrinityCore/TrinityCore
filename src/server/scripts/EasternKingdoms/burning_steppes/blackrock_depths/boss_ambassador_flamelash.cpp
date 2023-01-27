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
SDName: Boss_Ambassador_Flamelash
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_depths.h"

enum
{
    // SPELL_FIREBLAST             = 15573,                    // creature_template_addon
    SPELL_BURNING_SPIRIT        = 13489,
    SPELL_BURNING_SPIRIT_BUFF   = 14744,

    NPC_BURNING_SPIRIT          = 9178,

    DWARF_RUNES_MAX             = 7,
    BURNING_SPIRIT_MAX          = 30,                       // What is a good maximum and should there be any?
};


struct boss_ambassador_flamelashAI : public ScriptedAI
{
    boss_ambassador_flamelashAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_creature->SetCreatureSummonLimit(BURNING_SPIRIT_MAX);
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiSpiritTimer[DWARF_RUNES_MAX];

    GuidList lBurningSpirits;

    void Reset() override
    {
        for (uint32 & i : m_uiSpiritTimer)
            i = 5 * IN_MILLISECONDS;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_BURNING_SPIRIT)
            lBurningSpirits.insert(lBurningSpirits.end(), pSummoned->GetObjectGuid());

        pSummoned->SetWalk(false);
        pSummoned->GetMotionMaster()->MoveFollow(m_creature, 0.0f, 0.0f);
    }

    void Aggro(Unit* pWho) override
    {
        for (uint8 i = 0; i < DWARF_RUNES_MAX; i++)
        {
            if (GameObject* pRune = m_pInstance->GetGameObject(m_pInstance->GetData64(GO_DWARF_RUNE_A01 + i)))
                pRune->UseDoorOrButton();
        }
    }

    void OnCombatStop() override
    {
        for (uint8 i = 0; i < DWARF_RUNES_MAX; i++)
        {
            if (GameObject* pRune = m_pInstance->GetGameObject(m_pInstance->GetData64(GO_DWARF_RUNE_A01 + i)))
                pRune->ResetDoorOrButton();
        }

        for (const auto& guid : lBurningSpirits)
        {
            if (Creature* pSummon = m_creature->GetMap()->GetCreature(guid))
                pSummon->ForcedDespawn();
        }

        lBurningSpirits.clear();
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_BURNING_SPIRIT)
            lBurningSpirits.remove(pSummoned->GetObjectGuid());
    }

    void SpellHit(Unit* pWho, SpellEntry const* pSpell) override
    {
        if (pWho->GetEntry() == NPC_BURNING_SPIRIT && pSpell->Id == SPELL_BURNING_SPIRIT)
            m_creature->CastSpell(m_creature, SPELL_BURNING_SPIRIT_BUFF, true);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        ScriptedAI::MoveInLineOfSight(pWho);

        if (pWho->GetEntry() == NPC_BURNING_SPIRIT && pWho->IsAlive() && !pWho->IsInCombat() && pWho->IsWithinDistInMap(m_creature, 4 * CONTACT_DISTANCE))
            pWho->CastSpell(m_creature, SPELL_BURNING_SPIRIT, true);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Burning Spirit
        for (uint8 i = 0; i < DWARF_RUNES_MAX; i++)
        {
            if (m_uiSpiritTimer[i] < uiDiff)
            {
                if (GameObject* pRune = m_pInstance->GetGameObject(m_pInstance->GetData64(GO_DWARF_RUNE_A01 + i)))
                {
                    if (m_creature->GetCreatureSummonCount() < m_creature->GetCreatureSummonLimit())
                    {
                        m_creature->SummonCreature(NPC_BURNING_SPIRIT, pRune->GetPositionX(), pRune->GetPositionY(), pRune->GetPositionZ(), pRune->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 0);
                        m_uiSpiritTimer[i] = urand(15 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
                    }
                    else
                        m_uiSpiritTimer[i] = 1 * IN_MILLISECONDS;
                }
            }
            else
                m_uiSpiritTimer[i] -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_ambassador_flamelash(Creature* pCreature)
{
    return new boss_ambassador_flamelashAI(pCreature);
}

void AddSC_boss_ambassador_flamelash()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_ambassador_flamelash";
    newscript->GetAI = &GetAI_boss_ambassador_flamelash;
    newscript->RegisterSelf();
}
