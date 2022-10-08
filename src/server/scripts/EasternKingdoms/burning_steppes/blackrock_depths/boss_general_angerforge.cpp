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
SDName: Boss_General_Angerforge
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"

enum
{
    EMOTE_ALARM             = 5286,

    // SPELL_FLURRY          = 15088,       // creature_template_addon
    // SPELL_ENRAGE          = 15097,       // creature_template_addon
    SPELL_SUNDER_ARMOR      = 15572,

    NPC_ANVILRAGE_MEDIC     = 8894,
    NPC_ANVILRAGE_RESERVIST = 8901,

    NPC_ADD_COUNT           = 10,
};

struct sSpawnLocation
{
    uint32 m_uiEntry;
    float m_fX, m_fY, m_fZ, m_fO;
};

static sSpawnLocation m_aAddspawnLocs[NPC_ADD_COUNT] =
{
    { NPC_ANVILRAGE_RESERVIST,  716.8168f, 23.03471f, -45.34414f, 3.159046f },
    { NPC_ANVILRAGE_RESERVIST,  719.8195f, 25.44250f, -45.32854f, 3.193953f },
    { NPC_ANVILRAGE_RESERVIST,  720.0683f, 22.93752f, -45.34140f, 3.159046f },
    { NPC_ANVILRAGE_RESERVIST,  719.9299f, 19.80474f, -45.35873f, 3.106686f },
    { NPC_ANVILRAGE_RESERVIST,  724.4819f, 25.27536f, -45.31646f, 3.193953f },
    { NPC_ANVILRAGE_RESERVIST,  724.4958f, 22.62163f, -45.32786f, 3.159046f },
    { NPC_ANVILRAGE_RESERVIST,  724.7056f, 19.89114f, -45.33829f, 3.124139f },
    { NPC_ANVILRAGE_RESERVIST,  728.7010f, 18.92765f, -46.00228f, 3.106686f },
    { NPC_ANVILRAGE_MEDIC,      728.5464f, 21.52842f, -45.89260f, 3.141593f },
    { NPC_ANVILRAGE_MEDIC,      728.6478f, 24.58055f, -45.94735f, 3.176499f },
};

struct boss_general_angerforgeAI : public ScriptedAI
{
    boss_general_angerforgeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSunderArmorTimer;
    uint32 m_uiAlarmTimer;

    void Reset() override
    {
        m_uiSunderArmorTimer = urand(5 * IN_MILLISECONDS, 10 * IN_MILLISECONDS);
        m_uiAlarmTimer = 0;
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->GetMotionMaster()->MoveFollow(m_creature, 0.0f, 0.0f);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Sunder Armor
        if (m_uiSunderArmorTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SUNDER_ARMOR) == CAST_OK)
                m_uiSunderArmorTimer = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
        }
        else
            m_uiSunderArmorTimer -= uiDiff;

        // Alarm
        if (m_creature->GetHealthPercent() < 30.0f)
        {
            if (m_uiAlarmTimer < uiDiff)
            {
                DoScriptText(EMOTE_ALARM, m_creature);

                for (const auto& spawnData : m_aAddspawnLocs)
                    m_creature->SummonCreature(spawnData.m_uiEntry, spawnData.m_fX, spawnData.m_fY, spawnData.m_fZ, spawnData.m_fO, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30 * IN_MILLISECONDS);

                m_uiAlarmTimer = 3 * MINUTE * IN_MILLISECONDS;
            }
            else
                m_uiAlarmTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_general_angerforge(Creature* pCreature)
{
    return new boss_general_angerforgeAI(pCreature);
}

void AddSC_boss_general_angerforge()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_general_angerforge";
    newscript->GetAI = &GetAI_boss_general_angerforge;
    newscript->RegisterSelf();
}
