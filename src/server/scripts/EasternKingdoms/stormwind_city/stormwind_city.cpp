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
SDName: Stormwind_City
SD%Complete: 100
SDComment: Quest support: 1640, 1447
SDCategory: Stormwind City
EndScriptData */

/* ContentData
npc_bartleby
npc_dashel_stonefist
EndContentData */

#include "scriptPCH.h"
#include <list>

/*######
## npc_bartleby
######*/

enum BartlebyData
{
    FACTION_ENEMY       = 168,
    QUEST_BEAT          = 1640
};

struct npc_bartlebyAI : public ScriptedAI
{
    npc_bartlebyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_uiNormalFaction = pCreature->GetFactionTemplateId();
        Reset();
    }

    uint32 m_uiNormalFaction;

    void Reset() override
    {
        if (m_creature->GetFactionTemplateId() != m_uiNormalFaction)
            m_creature->SetFactionTemplateId(m_uiNormalFaction);
    }

    void AttackedBy(Unit* pAttacker) override
    {
        if (!pAttacker || m_creature->GetVictim() || m_creature->IsFriendlyTo(pAttacker))
            return;

        AttackStart(pAttacker);
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (!pDoneBy)
            return;

        if (uiDamage > m_creature->GetHealth() || ((m_creature->GetHealth() - uiDamage) * 100 / m_creature->GetMaxHealth() < 15))
        {
            uiDamage = 0;

            if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
                ((Player*)pDoneBy)->AreaExploredOrEventHappens(QUEST_BEAT);

            EnterEvadeMode();
        }
    }
};

bool QuestAccept_npc_bartleby(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (!pPlayer || !pCreature || !pQuest)
        return false;

    if (pQuest->GetQuestId() == QUEST_BEAT)
    {
        pCreature->SetFactionTemplateId(FACTION_ENEMY);
        ((npc_bartlebyAI*)pCreature->AI())->AttackStart(pPlayer);
    }
    return true;
}

CreatureAI* GetAI_npc_bartleby(Creature* pCreature)
{
    return new npc_bartlebyAI(pCreature);
}

/*######
## npc_dashel_stonefist
######*/

//-----------------------------------------------------------------------------
// Full quest event implementation (Missing Diplomat part 8 id:1447).
// Author: Kampeador
//-----------------------------------------------------------------------------
enum DashelStonefistData
{
    // ids from "broadcast_text" table
    SAY_PROGRESS_1_DAS = 1961, // Now you're gonna get it good, "PlayerName".
    SAY_PROGRESS_2_DAS = 1712, // Okay, okay! Enough fighting. No one else needs to get hurt.
    SAY_PROGRESS_3_DAS = 1713, // It's okay, boys. Back off. You've done enough. I'll meet up with you later.
    SAY_PROGRESS_4_THU = 1716, // All right, boss. You sure though? Just seems like a waste of good practice.
    SAY_PROGRESS_5_THU = 1715, // Yeah, okay, boss. No problem.
    // quest id
    QUEST_MISSING_DIPLO_PT8 = 1447,
    // NPCs that helps Dashel
    NPC_OLD_TOWN_THUG = 4969,
    // factions
    FACTION_NEUTRAL = 189,
    FACTION_IRONFORGE = 122, // original faction taken from DB
    FACTION_FRIENDLY_TO_ALL = 35,
    // quest phases
    MDQP_NONE = 0, // Dashel returns his spawn point

    // Occur only if thugs are alive
    MDQP_SAY1 = 1,
    MDQP_SAY2 = 2,
    MDQP_SAY3 = 4,
    MDQP_THUG_WALK_AWAY_1 = 5,
    MDQP_THUG_WALK_AWAY_2 = 6,

    MDQP_QUEST_COMPLETE = 7 // Triggers quest complete
};

float aThugResetPosition[][3] = {
    { -8669.338867f, 448.362976f, 99.740005f },
    { -8686.397461f, 447.595703f, 99.994408f }
};

struct npc_dashel_stonefistAI : public ScriptedAI
{
    // old town thugs
    Creature* m_thugs[2];
    // current event phase
    uint32 m_eventPhase;
    // check if an event has been started.
    bool m_dialogStarted;
    // player guid to trigger: quest completed
    ObjectGuid m_playerGuid;
    // timer to switch between phases
    uint32 m_nextPhaseDelayTimer;
    // used to check if 1 or more thugs are alive
    bool m_thugsAlive;
    // used to check if its a quest fight or not.
    bool m_questFightStarted;

    // if quest fight is active, then dialog event will be triggered
    inline void startQuestFight() { m_questFightStarted = true; }

    npc_dashel_stonefistAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_questFightStarted = false;
        Reset();
    }

    // Prevent Reset() call after Dashel has been defeated.
    void AttackedBy(Unit* pAttacker) override
    {
        if (!pAttacker || m_creature->GetVictim() || m_creature->IsFriendlyTo(pAttacker))
            return;

        AttackStart(pAttacker);
    }

    void Reset() override
    {
        if (m_questFightStarted)
        {
            // Reset() during quest fight -> quest failed.
            Player* player = m_creature->GetMap()->GetPlayer(m_playerGuid);
            if (player)
                player->GroupEventFailHappens(QUEST_MISSING_DIPLO_PT8);

            // remove thugs
            for (const auto& pThug : m_thugs)
            {
                if (pThug && pThug->IsAlive())
                {
                    static_cast<TemporarySummon*>(pThug)->UnSummon();
                }
            }
        }

        // zero init required to prevent crash
        for (auto& pThug : m_thugs)
            pThug = nullptr;

        m_questFightStarted = false;
        m_eventPhase = MDQP_NONE;
        m_dialogStarted = false;
        m_nextPhaseDelayTimer = 3000; // MDQP_SAY1 phase delay
        m_thugsAlive = false;
        // restore some flags
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        // restore faction
        m_creature->SetFactionTemplateId(FACTION_IRONFORGE);
        // reset player guid
        m_playerGuid.Clear();
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (m_questFightStarted)
        {
            if (uiDamage > m_creature->GetHealth() || m_creature->GetHealthPercent() < 20.0f)
            {
                uiDamage = 0;

                // Dashel says: Okay, okay! Enough fighting. No one else needs to get hurt.
                DoScriptText(SAY_PROGRESS_2_DAS, m_creature);

                m_creature->RemoveAllAuras();
                m_creature->SetFactionTemplateId(FACTION_FRIENDLY_TO_ALL);
                m_creature->DeleteThreatList();
                m_creature->CombatStop();

                if (MotionMaster* pMotionMaster = m_creature->GetMotionMaster())
                    pMotionMaster->MoveTargetedHome();

                // check if thugs are alive
                for (const auto& pThug : m_thugs)
                {
                    if (pThug && pThug->IsAlive())
                    {
                        pThug->RemoveAllAuras();
                        pThug->DeleteThreatList();
                        pThug->CombatStop();

                        pThug->SetFactionTemplateId(FACTION_FRIENDLY_TO_ALL);

                        if (MotionMaster* pMotionMaster = pThug->GetMotionMaster())
                            pMotionMaster->MoveTargetedHome();

                        m_thugsAlive = true;
                    }
                }

                m_questFightStarted = false;
                m_dialogStarted = true;
                m_eventPhase = MDQP_NONE;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        switch (m_eventPhase)
        {
        default: // MDQP_NONE
            ScriptedAI::UpdateAI(uiDiff);
            break;
        case MDQP_SAY1: // Occurs only if thugs are alive
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // Dashel says: It's okay, boys. Back off. You've done enough.I'll meet up with you later.
                    DoScriptText(SAY_PROGRESS_3_DAS, m_creature);
                    // switch phase
                    m_nextPhaseDelayTimer = 3000;
                    m_eventPhase = MDQP_SAY2;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        case MDQP_SAY2: // Occurs only if thugs are alive
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // recheck for safety, thugs can be killed by gm command, etc.
                    if (m_thugs[0] && m_thugs[0]->IsAlive())
                    {
                        DoScriptText(SAY_PROGRESS_4_THU, m_thugs[0]);
                    }

                    // switch phase
                    m_nextPhaseDelayTimer = 1500;
                    m_eventPhase = MDQP_SAY3;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        case MDQP_SAY3: // Occurs only if thugs are alive
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // recheck for safety, thugs can be killed by gm command, etc.
                    if (m_thugs[1] && m_thugs[1]->IsAlive())
                    {
                        DoScriptText(SAY_PROGRESS_5_THU, m_thugs[1]);
                    }

                    // switch phase
                    m_nextPhaseDelayTimer = 1000;
                    m_eventPhase = MDQP_THUG_WALK_AWAY_1;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        case MDQP_THUG_WALK_AWAY_1: // Occurs only if thugs are alive
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    ResetThug(0);

                    m_nextPhaseDelayTimer = 1500;
                    m_eventPhase = MDQP_THUG_WALK_AWAY_2;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        case MDQP_THUG_WALK_AWAY_2: // Occurs only if thugs are alive
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // Second thug goes away
                    ResetThug(1);

                    m_nextPhaseDelayTimer = 1000;
                    m_eventPhase = MDQP_QUEST_COMPLETE;
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        case MDQP_QUEST_COMPLETE:
            {
                if (m_nextPhaseDelayTimer < uiDiff)
                {
                    // Set quest completed
                    Player* player = m_creature->GetMap()->GetPlayer(m_playerGuid);
                    if (player)
                        player->GroupEventHappens(QUEST_MISSING_DIPLO_PT8, m_creature);

                    Reset();
                }
                else
                    m_nextPhaseDelayTimer -= uiDiff;
            } break;
        }
    }

    void ResetThug(int thug)
    {
        if (thug >= 2)
            return;

        if (m_thugs[thug] && m_thugs[thug]->IsAlive())
        {
            m_thugs[thug]->GetMotionMaster()->MovePoint(0, aThugResetPosition[thug][0], aThugResetPosition[thug][1], aThugResetPosition[thug][2], MOVE_WALK_MODE);
            m_thugs[thug]->ForcedDespawn(3000);
        }
    }

    // Dashel returns to his spawn point
    void JustReachedHome() override
    {
        // switch to correct dialog phase, depends if thugs are alive.
        if (m_dialogStarted)
        {
            if (m_thugsAlive)
                m_eventPhase = MDQP_SAY1;
            else
                m_eventPhase = MDQP_QUEST_COMPLETE;
        }
    }

    void JustDied(Unit* pUnit) override
    {
        // case: something weird happened, killed by GM command, etc.
        if (m_dialogStarted || m_questFightStarted)
        {
            // remove thugs
            for (auto& pThug : m_thugs)
            {
                if (pThug)
                {
                    static_cast<TemporarySummon*>(pThug)->UnSummon();
                    pThug = nullptr;
                }
            }
        }
    }

    void SummonedCreatureJustDied(Creature *creature) override
    {
        // If the thug died for whatever reason, clear the pointer. Otherwise, if
        // combat is extended, the thug may despawn and we'll access a dangling
        // pointer
        for (auto& pThug : m_thugs)
        {
            if (pThug == creature)
                pThug = nullptr;
        }
    }

    void SummonedCreatureDespawn(Creature* creature) override
    {
        for (auto& pThug : m_thugs)
        {
            if (pThug == creature)
                pThug = nullptr;
        }
    }
};

bool QuestAccept_npc_dashel_stonefist(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (!pPlayer || !pCreature || !pQuest)
        return false;

    if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT8)
    {
        npc_dashel_stonefistAI* dashelStonefistAI = dynamic_cast<npc_dashel_stonefistAI*>(pCreature->AI());
        if (dashelStonefistAI)
        {
            // On official in some cases: he didn't say this phrase. I am not sure if it was a bug or a random feature.
            // Dashel says: Now you're gonna get it good, "PlayerName".
            DoScriptText(SAY_PROGRESS_1_DAS, pCreature, pPlayer);

            pCreature->SetFactionTemplateId(FACTION_NEUTRAL);
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            dashelStonefistAI->m_playerGuid = pPlayer->GetObjectGuid();

            // spawn thugs and make them focus player.
            dashelStonefistAI->m_thugs[0] = pCreature->SummonCreature(NPC_OLD_TOWN_THUG, -8676.075195f, 443.744019f, 99.632210f, 3.981758f, TEMPSUMMON_DEAD_DESPAWN);

            if (!dashelStonefistAI->m_thugs[0] || !dashelStonefistAI->m_thugs[0]->AI())
                return false;

            dashelStonefistAI->m_thugs[0]->AI()->AttackStart(pPlayer);
            dashelStonefistAI->m_thugs[0]->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);

            // thug 2
            if (dashelStonefistAI->m_thugs[1] = pCreature->SummonCreature(NPC_OLD_TOWN_THUG, -8685.416992f, 443.130829f, 99.526917f, 5.759635f, TEMPSUMMON_DEAD_DESPAWN))
            {
                dashelStonefistAI->m_thugs[1]->AI()->AttackStart(pPlayer);
                dashelStonefistAI->m_thugs[1]->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            }
            // start quest fight.
            dashelStonefistAI->startQuestFight();
            // make Dashel focus player.
            dashelStonefistAI->AttackStart(pPlayer);
        }
        else
            return false;
    }
    return true;
}

CreatureAI* GetAI_npc_dashel_stonefist(Creature* pCreature)
{
    return new npc_dashel_stonefistAI(pCreature);
}

/*######
## Quest #434 The Attack
######*/

enum QuestTheAttack
{
    QUEST_ITEMS_OF_SOME_CONSEQUENCE = 2746, // prequest for 434
    QUEST_THE_ATTACK                = 434,

    FACTION_ENEMYY                  = 14,
    FACTION_NORMAL_LESCOVAR         = 12,
    FACTION_NORMAL_MARZON           = 84,

    NPC_LORD_GREGOR_LESCOVAR        = 1754,
    NPC_MARZON_THE_SILENT_BLADE     = 1755,
    NPC_STORMWIND_ROYAL_GUARD       = 1756,
    NPC_PRIESTRESS                  = 7779,
    NPC_TYRION                      = 7766,
    NPC_TYRIONS_SPYBOT              = 8856,

    MODEL_TYRIANA                   = 6703,
    MODEL_SPYBOT                    = 1159,

    DEFAULT_GOSSIP_TEXT_ID          = 2393,
    GOSSIP_TEXT_ID_EVENT_RUNNING    = 2394,

    SAY_SPYBOT                      = 4593,
    SAY_TYRION_1                    = 3761,
    SAY_TYRIONA_1                   = 3781,
    SAY_ROYAL_GUARD_1               = 3783,
    SAY_TYRIONA_2                   = 3782,
    SAY_TYRIONA_3                   = 3762,
    SAY_GREGOR_1                    = 3784,
    SAY_TYRIONA_4                   = 3791,
    SAY_GREGOR_2                    = 322,
    SAY_ROYAL_GUARD_2               = 3690,
    SAY_GREGOR_3                    = 3721,
    SAY_GREGOR_4                    = 323,
    SAY_MARZON_1                    = 324,
    SAY_GREGOR_5                    = 326,
    SAY_MARZON_2                    = 325,
    SAY_TYRION_2                    = 4613,
    SAY_GREGOR_6                    = 3934,
    SAY_MARZON_3                    = 3936,

    SPELL_STEALTH                   = 8874 // for Marzon
};

/*######
## npc_tyrion
######*/

struct npc_tyrionAI : public ScriptedAI
{
    npc_tyrionAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    bool m_IsEventRunning;

    void GetAIInformation(ChatHandler& reader) override
    {
        ScriptedAI::GetAIInformation(reader);
        reader.PSendSysMessage("TYRION: Event running: [%s]", m_IsEventRunning ? "YES" : "NO");
    }

    void Reset() override
    {
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        m_IsEventRunning = false;
    }

    bool AreCreaturesRequiredForQuestPresent(float fMaxSearchRange = 40.0f)
    {
        // m_guidTyrion Spybot
        return GetClosestCreatureWithEntry(m_creature, NPC_TYRIONS_SPYBOT, VISIBLE_RANGE) != nullptr;
    }
};

CreatureAI* GetAI_npc_tyrion(Creature* pCreature)
{
    return new npc_tyrionAI(pCreature);
}

/*######
## npc_lord_gregor_lescovar
######*/
struct npc_lord_gregor_lescovarAI : public npc_escortAI
{
    npc_lord_gregor_lescovarAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiEventTimer;
    uint8 m_uiEventPhase;
    ObjectGuid m_guidGuard1;
    ObjectGuid m_guidGuard2;
    ObjectGuid m_guidMarzon;
    ObjectGuid m_guidTyrion;
    ObjectGuid m_guidPriestress;

    void Reset() override
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        m_uiEventTimer = 0;
        m_uiEventPhase = 0;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (m_creature->GetFactionTemplateId() == FACTION_ENEMYY)
            m_creature->SetFactionTemplateId(FACTION_NORMAL_LESCOVAR);

        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
            if (!pMarzon->IsAlive())
            {
                if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                {
                    pGuard1->ForcedDespawn(0);
                    pGuard1->Respawn();
                }
                if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                {
                    pGuard2->ForcedDespawn(0);
                    pGuard2->Respawn();
                }
                if (Creature* pPriestress = m_creature->GetMap()->GetCreature(m_guidPriestress))
                    pPriestress->Respawn();

                if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                {
                    pTyrion->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pTyrion->AI()))
                        ptyrionAI->Reset();
                }
            }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() != NPC_MARZON_THE_SILENT_BLADE)
            return;

        if (!m_creature->IsAlive())
        {
            if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
            {
                pGuard1->ForcedDespawn(0);
                pGuard1->Respawn();
            }
            if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
            {
                pGuard2->ForcedDespawn(0);
                pGuard2->Respawn();
            }
            if (Creature* pPriestress = m_creature->GetMap()->GetCreature(m_guidPriestress))
                pPriestress->Respawn();

            if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
            {
                pTyrion->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pTyrion->AI()))
                    ptyrionAI->m_IsEventRunning = false;
            }
        }
    }

    void Aggro(Unit* pAttacker) override
    {
        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
        {
            DoScriptText(SAY_MARZON_3, pMarzon);
            DoScriptText(SAY_GREGOR_6, m_creature);
            pMarzon->AI()->AttackStart(pAttacker);
        }
        m_uiEventPhase = 13;
    }

    void SummonedCreatureDespawn(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() != NPC_MARZON_THE_SILENT_BLADE)
            return;

        if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
        {
            pGuard1->ForcedDespawn(0);
            pGuard1->Respawn();
        }

        if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
        {
            pGuard2->ForcedDespawn(0);
            pGuard2->Respawn();
        }

        if (Creature* pPriestress = m_creature->GetMap()->GetCreature(m_guidPriestress))
            pPriestress->Respawn();

        if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
        {
            pTyrion->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pTyrion->AI()))
                ptyrionAI->m_IsEventRunning = false;
        }
    }

    void WaypointReached(uint32 uiPoint) override
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;

        switch (uiPoint)
        {
            case 13:
                SetEscortPaused(false);
                if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                  if (pGuard1->IsAlive())
                      pGuard1->SetFacingToObject(m_creature);
                if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                  if (pGuard2->IsAlive())
                      pGuard2->SetFacingToObject(m_creature);
                DoScriptText(SAY_GREGOR_2, m_creature);
                m_uiEventPhase = 1;
                m_uiEventTimer = 3500;
                SetEscortPaused(true);
                break;
            case 17:
                m_uiEventPhase = 4;
                m_uiEventTimer = 1500;
                SetEscortPaused(true);
                break;
            case 20:
                m_creature->SetFactionTemplateId(FACTION_NORMAL_LESCOVAR);
                if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                {
                    pMarzon->CastSpell(pMarzon, SPELL_STEALTH, true);
                    pMarzon->ForcedDespawn(0);
                }
                break;
            case 21:
                if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                {
                    pGuard1->ForcedDespawn(0);
                    pGuard1->Respawn();
                }
                if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                {
                    pGuard2->ForcedDespawn(0);
                    pGuard2->Respawn();
                }
                if (Creature* pPriestress = m_creature->GetMap()->GetCreature(m_guidPriestress))
                    pPriestress->Respawn();
            
                if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                {
                    pTyrion->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pTyrion->AI()))
                        ptyrionAI->m_IsEventRunning = false;
                }

                if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                    if (!pMarzon->IsInCombat())
                        pMarzon->ForcedDespawn(0);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiEventTimer)
        {
            if (m_uiEventTimer <= uiDiff)
            {
                switch (m_uiEventPhase)
                {
                    case 1:
                        if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                            if (pGuard1->IsAlive() && !pGuard1->GetVictim())
                            {
                                DoScriptText(SAY_ROYAL_GUARD_2, pGuard1);
                                pGuard1->GetMotionMaster()->MovePoint(0, -8364.07f, 406.775f, 122.274f, MOVE_PATHFINDING);
                            }
                        if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                            if (pGuard2->IsAlive() && !pGuard2->GetVictim())
                            {
                                DoScriptText(SAY_ROYAL_GUARD_2, pGuard2);
                                pGuard2->GetMotionMaster()->MovePoint(0, -8353.91f, 415.318f, 122.274f, MOVE_PATHFINDING);
                            }
                        ++m_uiEventPhase;
                        m_uiEventTimer = 3000;
                        break;
                    case 2:
                        ++m_uiEventPhase;
                        SetEscortPaused(false);
                        break;
                    case 4:
                        if (Creature* pMarzon = m_creature->SummonCreature(NPC_MARZON_THE_SILENT_BLADE, -8407.71f, 482.117f, 123.76f, 4.79f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1 * MINUTE*IN_MILLISECONDS))
                        {
                            pMarzon->CastSpell(pMarzon, SPELL_STEALTH, true);
                            pMarzon->GetMotionMaster()->MovePoint(0, -8406.00f, 470.00f, 123.76f, MOVE_PATHFINDING);
                            m_guidMarzon = pMarzon->GetObjectGuid();
                        }
                        m_uiEventTimer = 10000;
                        ++m_uiEventPhase;
                        SetEscortPaused(true);
                        break;
                    case 5:
                        DoScriptText(SAY_GREGOR_3, m_creature);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 6:
                    
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                        {
                            pMarzon->RemoveAura(SPELL_STEALTH, EFFECT_INDEX_0);
                            m_creature->SetFacingToObject(pMarzon);
                        }
                        DoScriptText(SAY_GREGOR_4, m_creature);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 7:
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                            DoScriptText(SAY_MARZON_1, pMarzon);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 8:
                        DoScriptText(SAY_GREGOR_5, m_creature);
                        m_uiEventTimer = 4000;
                        ++m_uiEventPhase;
                        break;
                    case 9:
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                            DoScriptText(SAY_MARZON_2, pMarzon);
                        m_uiEventTimer = 3000;
                        ++m_uiEventPhase;
                        break;
                    case 10:
                        if (Player* pPlayer = GetPlayerForEscort())
                            pPlayer->GroupEventHappens(QUEST_THE_ATTACK, m_creature);
                        if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                            DoScriptText(SAY_TYRION_2, pTyrion);
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                            pMarzon->SetFactionTemplateId(FACTION_ENEMYY);
                        m_creature->SetFactionTemplateId(FACTION_ENEMYY);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 11:
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                        {
                            if (!m_creature->IsInCombat())
                                pMarzon->GetMotionMaster()->MovePoint(0, -8419.00f, 486.26f, 123.75f, MOVE_PATHFINDING);
                            else if (m_creature->GetVictim())
                                pMarzon->AI()->AttackStart(m_creature->GetVictim());
                        }
                        ++m_uiEventPhase;
                        SetEscortPaused(false);
                        break;
                    case 12:
                        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                          if (pMarzon->IsInCombat() && pMarzon->GetVictim() && !m_creature->IsInCombat())
                              m_creature->AI()->AttackStart(pMarzon->GetVictim());
                        break;
                    case 13:
                        if (Player* pPlayer = GetPlayerForEscort())
                            if (pPlayer->IsDead())
                            {
                                SetEscortPaused(false);
                                m_creature->SetFactionTemplateId(FACTION_NORMAL_LESCOVAR);
                                if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
                                    if (!pMarzon->IsDead() && pMarzon->GetFactionTemplateId() == FACTION_ENEMYY)
                                        pMarzon->SetFactionTemplateId(FACTION_NORMAL_MARZON);
                            }
                        if (!m_creature->IsInCombat())
                            SetEscortPaused(false);
                        break;
                    }
            }
            else
                m_uiEventTimer -= uiDiff;
        }

        if (Creature* pMarzon = m_creature->GetMap()->GetCreature(m_guidMarzon))
          if (pMarzon && pMarzon->IsDead() && pMarzon->GetFactionTemplateId() == FACTION_ENEMYY)
              pMarzon->SetFactionTemplateId(FACTION_NORMAL_MARZON);

        npc_escortAI::UpdateAI(uiDiff);

        if (m_creature->SelectHostileTarget() || m_creature->GetVictim())
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_lord_gregor_lescovar(Creature* pCreature)
{
    return new npc_lord_gregor_lescovarAI(pCreature);
}

/*######
## npc_tyrion_spybot
######*/

struct npc_tyrion_spybotAI : public npc_escortAI
{
    npc_tyrion_spybotAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    ObjectGuid m_guidGuard1;
    ObjectGuid m_guidGuard2;
    ObjectGuid m_guidLordGregor;
    ObjectGuid m_guidTyrion;
    ObjectGuid m_guidMarzon;
    ObjectGuid m_guidPriestress;
    uint8 m_uiGardenGuardsCounter;

    uint32 m_uiEventTimer;
    uint8 m_uiEventPhase;
    float m_fDefaultScaleSize;

    void Reset() override
    {

        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        m_fDefaultScaleSize = 0.30f;
        m_uiEventTimer = 0;
        m_uiEventPhase = 0;
        m_uiGardenGuardsCounter = 0;
        m_creature->SetDisplayId(MODEL_SPYBOT);

        if (Creature* tyrion = GetClosestCreatureWithEntry(m_creature, NPC_TYRION, VISIBLE_RANGE))
        {
            if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(tyrion->AI()))
            {
                ptyrionAI->m_IsEventRunning = false;
                tyrion->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            }
        }
    }

    void Aggro(Unit* pAttacker) override { }

    bool AreCreaturesRequiredForQuestPresent(float fMaxSearchRange = 40.0f)
    {
        if (m_guidTyrion && m_guidLordGregor && m_guidGuard1 && m_guidGuard2)
            return true;

        // m_guidPriestress
        if (!m_guidPriestress)
            if (Creature* pPriestress = GetClosestCreatureWithEntry(m_creature, NPC_PRIESTRESS, VISIBLE_RANGE))
            {
                if (!pPriestress)
                    return false;
                else if (pPriestress->GetEntry() != NPC_PRIESTRESS)
                    return false;
                else
                    m_guidPriestress = pPriestress->GetObjectGuid();
            }

        // m_guidTyrion
        if (!m_guidTyrion)
            if (Creature* pTyrion = GetClosestCreatureWithEntry(m_creature, NPC_TYRION, VISIBLE_RANGE))
            {
                if (!pTyrion)
                    return false;
                else if (pTyrion->GetEntry() != NPC_TYRION)
                    return false;
                else
                    m_guidTyrion = pTyrion->GetObjectGuid();
            }

        // Lord Gregor
        if (!m_guidLordGregor)
            if (Creature* pGregor = GetClosestCreatureWithEntry(m_creature, NPC_LORD_GREGOR_LESCOVAR, VISIBLE_RANGE))
            {
                if (!pGregor)
                    return false;
                else if (!pGregor->IsAlive())
                    pGregor->Respawn();
                m_guidLordGregor = pGregor->GetObjectGuid();
            }
        // Stormwind Royal Guards (Garden)
        if (!m_guidGuard1 || !m_guidGuard2)
        {
            std::list<Creature*> lGardenStormwindRoyalGuards;
            GetCreatureListWithEntryInGrid(lGardenStormwindRoyalGuards, m_creature, NPC_STORMWIND_ROYAL_GUARD, fMaxSearchRange);

            if (lGardenStormwindRoyalGuards.empty())
                return true;

            for (const auto pRoyalGuard : lGardenStormwindRoyalGuards)
            {
                if (pRoyalGuard->IsDead() || !pRoyalGuard->IsAlive())
                    pRoyalGuard->Respawn();

                if (m_uiGardenGuardsCounter == 0)
                {
                    m_guidGuard1 = pRoyalGuard->GetObjectGuid();
                    m_uiGardenGuardsCounter++;
                    continue;
                }
                else if (m_uiGardenGuardsCounter == 1)
                {
                    m_guidGuard2 = pRoyalGuard->GetObjectGuid();
                    m_uiGardenGuardsCounter++;
                    continue;
                }
            }
            return true;
        }
        return true;
    }

    void WaypointReached(uint32 uiPoint) override
    {
        if (!AreCreaturesRequiredForQuestPresent())
            return;

        switch (uiPoint)
        {
            case 1:
                if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                {
                    pTyrion->SetFacingToObject(m_creature);
                    pTyrion->HandleEmote(EMOTE_STATE_USESTANDING);
                }
                m_fDefaultScaleSize = m_creature->GetFloatValue(OBJECT_FIELD_SCALE_X);
                m_creature->SetDisplayId(MODEL_TYRIANA);
                m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.00f);

                SetEscortPaused(true);
                m_uiEventTimer = 5000;
                m_uiEventPhase = 1;
                break;
            case 2:
                if (Creature* pPriestress = m_creature->GetMap()->GetCreature(m_guidPriestress))
                    pPriestress->ForcedDespawn(0);
                if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                    DoScriptText(SAY_TYRION_1, pTyrion, GetPlayerForEscort());
                break;
            case 6:
                DoScriptText(SAY_TYRIONA_1, m_creature);
                if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                {
                    if (pGuard1 && pGuard1->IsAlive() && !pGuard1->GetVictim())
                        pGuard1->SetFacingToObject(m_creature);
                }

                if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                {
                    if (pGuard2 && pGuard2->IsAlive() && !pGuard2->GetVictim())
                        pGuard2->SetFacingToObject(m_creature);
                }

                m_uiEventPhase = 2;
                m_uiEventTimer = 5000;
                SetEscortPaused(true);
                break;
            case 18:
                DoScriptText(SAY_TYRIONA_3, m_creature);
                if (Creature* gregor = m_creature->GetMap()->GetCreature(m_guidLordGregor))
                    gregor->SetFacingToObject(m_creature);
                m_uiEventPhase = 5;
                m_uiEventTimer = 5000;
                SetEscortPaused(true);
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {

        if (m_uiEventTimer)
        {
            if (m_uiEventTimer <= uiDiff)
            {
                switch (m_uiEventPhase)
                {
                    case 1:
                        if (Creature* pTyrion = m_creature->GetMap()->GetCreature(m_guidTyrion))
                            pTyrion->HandleEmote(EMOTE_ONESHOT_NONE);
                        SetEscortPaused(false);
                        break;
                    case 2:
                        if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                        {
                            DoScriptText(SAY_ROYAL_GUARD_1, pGuard1);
                            m_creature->SetFacingToObject(pGuard1);
                        }
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 3:
                        DoScriptText(SAY_TYRIONA_2, m_creature);
                        if (Creature* pGuard1 = m_creature->GetMap()->GetCreature(m_guidGuard1))
                            pGuard1->HandleEmote(EMOTE_ONESHOT_KNEEL);
                        if (Creature* pGuard2 = m_creature->GetMap()->GetCreature(m_guidGuard2))
                            pGuard2->HandleEmote(EMOTE_ONESHOT_KNEEL);
                        ++m_uiEventPhase; // 4 = nothing (It's OK)
                        SetEscortPaused(false);
                        break;
                    case 5:
                        if (Creature* gregor = m_creature->GetMap()->GetCreature(m_guidLordGregor))
                            DoScriptText(SAY_GREGOR_1, gregor);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 6:
                        DoScriptText(SAY_TYRIONA_4, m_creature);
                        m_uiEventTimer = 5000;
                        ++m_uiEventPhase;
                        break;
                    case 7:
                        if (Player* pPlayer = GetPlayerForEscort())
                            if (Creature* gregor = m_creature->GetMap()->GetCreature(m_guidLordGregor))
                                if (npc_lord_gregor_lescovarAI* pGregorEscortAI = dynamic_cast<npc_lord_gregor_lescovarAI*>(gregor->AI()))
                                {
                                    pGregorEscortAI->SetMaxPlayerDistance(200.0f);
                                    pGregorEscortAI->Start(false, pPlayer->GetGUID());
                                    pGregorEscortAI->m_guidGuard1 = m_guidGuard1;
                                    pGregorEscortAI->m_guidGuard2 = m_guidGuard2;
                                    pGregorEscortAI->m_guidTyrion = m_guidTyrion;
                                    pGregorEscortAI->m_guidPriestress = m_guidPriestress;
                                }
                        m_creature->SetDisplayId(MODEL_SPYBOT);
                        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, m_fDefaultScaleSize);
                        ++m_uiEventPhase;
                        m_uiEventTimer = 1000;
                        break;
                    case 8:
                        SetEscortPaused(false);
                        break;
                }
            }
            else m_uiEventTimer -= uiDiff;
        }

        npc_escortAI::UpdateAI(uiDiff);
    }
};

CreatureAI* GetAI_npc_tyrion_spybot(Creature* pCreature)
{
    return new npc_tyrion_spybotAI(pCreature);
}

/*######
## npc_tyrion
######*/

bool GossipHello_npc_tyrion(Player* pPlayer, Creature* pCreature)
{
    bool bIsEventReady = false;

    if (npc_tyrionAI* pTyrion = dynamic_cast<npc_tyrionAI*>(pCreature->AI()))
        bIsEventReady =  (!pTyrion->m_IsEventRunning && pTyrion->AreCreaturesRequiredForQuestPresent());

    // Check if event is possible and also check the status of the quests
    if (!bIsEventReady)
    {
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_ID_EVENT_RUNNING, pCreature->GetObjectGuid());
    }
    else
    {
        if (pCreature->IsQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_TEXT_ID, pCreature->GetObjectGuid());
    }

    return true;
}

bool QuestAccept_npc_tyrion(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pCreature->AI()))
        if (ptyrionAI->m_IsEventRunning)
            return false;

    if (pQuest->GetQuestId() == QUEST_THE_ATTACK)
    {
        if (Creature* TyrionSpyBot = GetClosestCreatureWithEntry(pCreature, NPC_TYRIONS_SPYBOT, VISIBLE_RANGE))
        {
            if (npc_tyrion_spybotAI* pSpybotEscortAI = dynamic_cast<npc_tyrion_spybotAI*>(TyrionSpyBot->AI()))
            {
                DoScriptText(SAY_SPYBOT, TyrionSpyBot);
                pSpybotEscortAI->SetMaxPlayerDistance(200.0f);
                pSpybotEscortAI->Start(false, pPlayer->GetGUID(), nullptr, false, false);
                pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                if (npc_tyrionAI* ptyrionAI = dynamic_cast<npc_tyrionAI*>(pCreature->AI()))
                    ptyrionAI->m_IsEventRunning = true;
            }
        }
    }
    return true;
}

/*######
## npc_master_wood
######*/

enum MasterWoodData
{
    SAY_RUDE_1 = 1403,
    SAY_RUDE_2 = 1404,
    SAY_RUDE_3 = 1402
};

struct npc_master_woodAI : public ScriptedAI
{
    npc_master_woodAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiRudeCount;

    void Reset() override
    {
        m_uiRudeCount = 0;
    }

    void ReceiveEmote(Player* pPlayer, uint32 emote) override
    {
        if (pPlayer && (pPlayer->GetTeam() == ALLIANCE) && !m_creature->IsInCombat() && m_creature->IsWithinLOSInMap(pPlayer))
        {
            switch (emote)
            {
                case TEXTEMOTE_RUDE:
                {
                    m_uiRudeCount++;
                    switch (m_uiRudeCount)
                    {
                        case 1:
                            DoScriptText(SAY_RUDE_1, m_creature, pPlayer);
                            break;
                        case 2:
                            DoScriptText(SAY_RUDE_2, m_creature, pPlayer);
                            break;
                        case 3:
                            DoScriptText(SAY_RUDE_3, m_creature, pPlayer);
                            break;
                        case 5:
                            m_creature->GetMotionMaster()->MoveCharge(pPlayer, 1000, true);
                            m_uiRudeCount = 0;
                            break;
                    }
                    break;
                }
                case TEXTEMOTE_WAVE:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    break;
                case TEXTEMOTE_BOW:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
                    break;
                case TEXTEMOTE_SALUTE:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                    break;
                case TEXTEMOTE_FLEX:
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                    break;
            }
        }
    }
};

CreatureAI* GetAI_npc_master_wood(Creature* pCreature)
{
    return new npc_master_woodAI(pCreature);
}

void AddSC_stormwind_city()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_bartleby";
    newscript->GetAI = &GetAI_npc_bartleby;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_bartleby;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dashel_stonefist";
    newscript->GetAI = &GetAI_npc_dashel_stonefist;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_dashel_stonefist;
    newscript->RegisterSelf();

    // The Attack quest
    newscript = new Script;
    newscript->Name = "npc_lord_gregor_lescovar";
    newscript->GetAI = &GetAI_npc_lord_gregor_lescovar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tyrion_spybot";
    newscript->GetAI = &GetAI_npc_tyrion_spybot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tyrion";
    newscript->GetAI = &GetAI_npc_tyrion;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_tyrion;
    newscript->pGossipHello = &GossipHello_npc_tyrion;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_master_wood";
    newscript->GetAI = &GetAI_npc_master_wood;
    newscript->RegisterSelf();
}
