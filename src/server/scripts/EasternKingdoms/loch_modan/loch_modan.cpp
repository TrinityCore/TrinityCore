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
SDName: Loch_Modan
SD%Complete: 100
SDComment: Quest support: 309,  273
SDCategory: Loch Modan
EndScriptData */

/* ContentData
npc_miran
EndContentData */

#include "scriptPCH.h"

/*######
## npc_miran
######*/

enum MiranData
{
    QUEST_PROTECTING_THE_SHIPMENT = 309,

    SAY_MIRAN_1           = 510,
    SAY_DARK_IRON_DWARF   = 1936,
    SAY_MIRAN_2           = 511,
    SAY_MIRAN_3           = 498,

    NPC_DARK_IRON_DWARF   = 2149
};

struct Location
{
    float m_fX, m_fY, m_fZ, m_fO;
};

static const Location m_afAmbushSpawn[] =
{
    { -5691.93f, -3745.91f, 319.159f, 2.21f},
    { -5706.98f, -3745.39f, 318.728f, 1.04f}
};

struct npc_miranAI: public npc_escortAI
{
    npc_miranAI(Creature* pCreature): npc_escortAI(pCreature)
    {
        Reset();
    }

    uint8 m_uiDwarves;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
            m_uiDwarves = 0;
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 19:
                DoScriptText(SAY_MIRAN_1, m_creature);
                m_creature->SummonCreature(NPC_DARK_IRON_DWARF, m_afAmbushSpawn[0].m_fX, m_afAmbushSpawn[0].m_fY, m_afAmbushSpawn[0].m_fZ, m_afAmbushSpawn[0].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 25000);
                m_creature->SummonCreature(NPC_DARK_IRON_DWARF, m_afAmbushSpawn[1].m_fX, m_afAmbushSpawn[1].m_fY, m_afAmbushSpawn[1].m_fZ, m_afAmbushSpawn[1].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 25000);
                break;
            case 23:
                DoScriptText(SAY_MIRAN_3, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_PROTECTING_THE_SHIPMENT, m_creature);
                break;
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_DARK_IRON_DWARF)
        {
            --m_uiDwarves;
            if (!m_uiDwarves)
                DoScriptText(SAY_MIRAN_2, m_creature);
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_DARK_IRON_DWARF)
        {
            if (!m_uiDwarves)
                DoScriptText(SAY_DARK_IRON_DWARF, pSummoned);
            ++m_uiDwarves;
            pSummoned->AI()->AttackStart(m_creature);
        }
    }
};

bool QuestAccept_npc_miran(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_PROTECTING_THE_SHIPMENT)
    {
        if (npc_miranAI* pEscortAI = dynamic_cast<npc_miranAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

CreatureAI* GetAI_npc_miran(Creature* pCreature)
{
    return new npc_miranAI(pCreature);
}

//-----------------------------------------------------------------------------
// Quest event implementation (Resupplying the Excavation id:273).
// Author: Kampeador
//-----------------------------------------------------------------------------

enum SaeanData
{
    QUEST_RESUPPLYING_THE_EXCAVATION = 273,
 
    NPC_SAEAN              = 1380,
    NPC_MIRAN              = 1379,
    NPC_HULDAR             = 2057,
    NPC_DARK_IRON_AMBUSHER = 1981,

    FACTION_HOSTILE        = 54
};

struct point3o { float x, y, z, o; };

static const point3o darkIronAmbusherSpawns[] =
{
    { -5759.852051f, -3441.279053f, 305.573212f, 2.174024f },
    { -5757.629883f, -3437.680908f, 304.265106f, 2.610265f }
};

struct npc_saeanAI : public ScriptedAI
{
    Creature* m_darkIronAmbusher[2];
    // num summoned dark iron ambushers used to guarantee that there will be no duplicate spawns.
    uint32 m_numSummonedAmbushers;
    // this one is modified inside area-trigger script.
    bool m_eventStarted;

    npc_saeanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        // zero init required to prevent crash
        for (auto& i : m_darkIronAmbusher)
            i = nullptr;
        m_numSummonedAmbushers = 0;

        m_eventStarted = false;
    }

    void Reset() override { }

    // called when Saean summons his guards
    void JustSummoned(Creature* pSummoned) override
    {
        // optimization: safely assume, that m_numSummonedAmbushers don't go outside range
        m_darkIronAmbusher[m_numSummonedAmbushers] = pSummoned;
        ++m_numSummonedAmbushers;
    }

    void JustDied(Unit* pVictim) override
    {
        // It is safe to forget about ambushers, they will despawn automatically.
        for (auto& i : m_darkIronAmbusher)
            i = nullptr;
        m_numSummonedAmbushers = 0;

        m_eventStarted = false;
    }
};

CreatureAI* GetAI_npc_saean(Creature* pCreature)
{
    return new npc_saeanAI(pCreature);
}

//-----------------------------------------------------------------------------
// Miran and Huldar are ambushed when Area Trigger id:171 is triggered and if quest 273 is active
bool AreaTrigger_at_huldar_miran(Player* pPlayer, AreaTriggerEntry const* /*pAt*/)
{
    // If player is dead, GM mode is ON, quest complete or no quest
    if (!pPlayer->IsAlive() || pPlayer->IsGameMaster() ||
        pPlayer->GetQuestStatus(QUEST_RESUPPLYING_THE_EXCAVATION) == QUEST_STATUS_COMPLETE ||
        pPlayer->GetQuestStatus(QUEST_RESUPPLYING_THE_EXCAVATION) == QUEST_STATUS_NONE)
    return false;

    // rare case: set quest completed on directly trigger,
    // because if NPCs are not available, killed by someone or died in previous event,
    // then, after returning home/respawn, quest will be still incompleted.
    pPlayer->CompleteQuest(QUEST_RESUPPLYING_THE_EXCAVATION);
    pPlayer->SendQuestCompleteEvent(QUEST_RESUPPLYING_THE_EXCAVATION);

    // Check if Huldar is available.
    Creature* huldar = GetClosestCreatureWithEntry(pPlayer, NPC_HULDAR, 60.0f);
    if (huldar)
    {
        if (!huldar->IsAlive())
            return false;
    }
    else
        return false;

    // Check if Miran is available.
    Creature* miran = GetClosestCreatureWithEntry(pPlayer, NPC_MIRAN, 60.0f);
    if (miran)
    {
        if (!miran->IsAlive())
            return false;
        else
        {
            // rare case: handle possible collision with escort quest event: Protecting the Shipment.
            // Since Dark Iron Ambushers are focusing Miran, he shouldn't be on escort druing this event.
            npc_miranAI* miranAI = dynamic_cast<npc_miranAI*>(miran->AI());
            if (miranAI)
            {
                if (miranAI->HasEscortState(STATE_ESCORT_ESCORTING))
                    return false;
            }
        }
    }
    else
        return false;

    // minor optimization: Quest NPCs are already in combat with someone, so skip further checks.
    if (miran->IsInCombat() || huldar->IsInCombat())
        return true;

    // Check if Saean is available.
    Creature* saean = GetClosestCreatureWithEntry(pPlayer, NPC_SAEAN, 60.0f);
    if (saean)
    {
        if (saean->IsAlive())
        {
            npc_saeanAI* saeanAI = dynamic_cast<npc_saeanAI*>(saean->AI());
            if (saeanAI)
            {
                // very rare case: Miran and Huldar are not in combat. Wrong faction in DB, etc.
                if (!saeanAI->m_eventStarted)
                {
                    // set event started
                    saeanAI->m_eventStarted = true;

                    // set temporary faction to hostile
                    saean->SetFactionTemporary(FACTION_HOSTILE, TEMPFACTION_RESTORE_RESPAWN);

                    // rare case: prevent any possible duplicate spawns
                    // 1 player pulled ambushers too far away, while the second one triggers this event
                    if (!saeanAI->m_numSummonedAmbushers)
                    {
                        // summon ambushers
                        saean->SummonCreature(NPC_DARK_IRON_AMBUSHER, darkIronAmbusherSpawns[0].x, darkIronAmbusherSpawns[0].y, darkIronAmbusherSpawns[0].z, darkIronAmbusherSpawns[0].o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 25000);
                        saean->SummonCreature(NPC_DARK_IRON_AMBUSHER, darkIronAmbusherSpawns[1].x, darkIronAmbusherSpawns[1].y, darkIronAmbusherSpawns[1].z, darkIronAmbusherSpawns[1].o, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 25000);
                        // Saean focuses Miran.
                        saeanAI->AttackStart(miran);
                    }
                    else
                    {
                        // ambushers were summoned, so event is already started
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

void AddSC_loch_modan()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_miran";
    newscript->GetAI = &GetAI_npc_miran;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_miran;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_saean";
    newscript->GetAI = &GetAI_npc_saean;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_huldar_miran";
    newscript->pAreaTrigger = &AreaTrigger_at_huldar_miran;
    newscript->RegisterSelf();
}
