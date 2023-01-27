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
SDName: redridge_mountains
SD%Complete: 100%
SDComment: Quest support: 219
SDCategory: Redridge Mountains
EndScriptData */

/* ContentData
npc_corporal_keeshan */

#include "scriptPCH.h"

/*######
## npc_corporal_leehsan
######*/

enum CorporalLeehsanData
{
    FACTION_ESCORTEE        = 10, // only during escort
    FACTION_STORMWIND       = 12, // default ooc faction

    QUEST_MISSING_IN_ACTION = 219,

    SPELL_MOCKING_BLOW      = 21008,
    SPELL_SHIELD_BASH       = 11972,

    SAY_CORPORAL_KEESHAN_1  = 25,
    SAY_CORPORAL_KEESHAN_2  = 26,
    SAY_CORPORAL_KEESHAN_3  = 27,
    SAY_CORPORAL_KEESHAN_4  = 29,
    SAY_CORPORAL_KEESHAN_5  = 30
};

struct npc_corporal_keeshan_escortAI : npc_escortAI
{
    explicit npc_corporal_keeshan_escortAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        npc_corporal_keeshan_escortAI::Reset();
    }

    uint32 m_uiMockingBlowTimer;
    uint32 m_uiShieldBashTimer;

    void Reset() override
    {
        m_uiMockingBlowTimer = 5000;
        m_uiShieldBashTimer  = 8000;
    }

    void WaypointStart(uint32 uiWP) override
    {
        switch (uiWP)
        {
            case 27: // break outside
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_CORPORAL_KEESHAN_3, m_creature, pPlayer);
                m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                break;
            case 54: // say goodbye
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_CORPORAL_KEESHAN_5, m_creature, pPlayer);
                break;
        }
    }

    void WaypointReached(uint32 uiWP) override
    {
        switch (uiWP)
        {
            case 26:                                        //break outside
                m_creature->SetStandState(UNIT_STAND_STATE_SIT);
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_CORPORAL_KEESHAN_2, m_creature, pPlayer);
                break;
            case 53:                                        //quest_complete
                DoScriptText(SAY_CORPORAL_KEESHAN_4, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_MISSING_IN_ACTION, m_creature);
                break;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        //Combat check
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiMockingBlowTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MOCKING_BLOW);
            m_uiMockingBlowTimer = 5000;
        }
        else
            m_uiMockingBlowTimer -= uiDiff;

        if (m_uiShieldBashTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHIELD_BASH);
            m_uiShieldBashTimer = 8000;
        }
        else
            m_uiShieldBashTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_corporal_keeshan(Creature* pCreature)
{
    return new npc_corporal_keeshan_escortAI(pCreature);
}

bool QuestAccept_npc_corporal_keeshan(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_MISSING_IN_ACTION)
    {
        if (auto pEscortAI = dynamic_cast<npc_corporal_keeshan_escortAI*>(pCreature->AI()))
        {
            DoScriptText(SAY_CORPORAL_KEESHAN_1, pCreature, pPlayer);
            pCreature->SetFactionTemporary(FACTION_ESCORTEE, TEMPFACTION_RESTORE_RESPAWN);
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
        }
    }
    return true;
}

void AddSC_redridge_mountains()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "npc_corporal_keeshan";
    NewScript->GetAI = &GetAI_npc_corporal_keeshan;
    NewScript->pQuestAcceptNPC = &QuestAccept_npc_corporal_keeshan;
    NewScript->RegisterSelf();
}
