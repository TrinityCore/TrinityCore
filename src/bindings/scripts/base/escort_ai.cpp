/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

/* ScriptData
SDName: Npc_EscortAI
SD%Complete: 100
SDComment:
SDCategory: Npc
EndScriptData */

#include "precompiled.h"
#include "escort_ai.h"

enum ePoints
{
    POINT_LAST_POINT    = 0xFFFFFF,
    POINT_HOME          = 0xFFFFFE
};

npc_escortAI::npc_escortAI(Creature* pCreature) : ScriptedAI(pCreature),
    m_uiPlayerGUID(0),
    MaxPlayerDistance(DEFAULT_MAX_PLAYER_DISTANCE),
    m_uiPlayerCheckTimer(1000),
    m_uiWPWaitTimer(2500),
    m_uiEscortState(STATE_ESCORT_NONE),
    m_bIsActiveAttacker(true),
    m_bIsRunning(false),
    DespawnAtEnd(true),
    DespawnAtFar(true),
    m_pQuestForEscort(NULL),
    m_bCanInstantRespawn(false),
    m_bCanReturnToStart(false),
    ScriptWP(false)
{}

void npc_escortAI::AttackStart(Unit* pWho)
{
    if (!pWho)
        return;

    if (m_creature->Attack(pWho, true))
    {
        if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
            m_creature->GetMotionMaster()->MovementExpired();

        if (IsCombatMovement())
            m_creature->GetMotionMaster()->MoveChase(pWho);
    }
}

//see followerAI
bool npc_escortAI::AssistPlayerInCombat(Unit* pWho)
{
    if (!pWho || !pWho->getVictim())
        return false;

    //experimental (unknown) flag not present
    if (!(m_creature->GetCreatureInfo()->type_flags & CREATURE_TYPEFLAGS_UNK13))
        return false;

    //not a player
    if (!pWho->getVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
        return false;

    //never attack friendly
    if (m_creature->IsFriendlyTo(pWho))
        return false;

    //too far away and no free sight?
    if (m_creature->IsWithinDistInMap(pWho, GetMaxPlayerDistance()) && m_creature->IsWithinLOSInMap(pWho))
    {
        //already fighting someone?
        if (!m_creature->getVictim())
        {
            AttackStart(pWho);
            return true;
        }
        else
        {
            pWho->SetInCombatWith(m_creature);
            m_creature->AddThreat(pWho, 0.0f);
            return true;
        }
    }

    return false;
}

void npc_escortAI::MoveInLineOfSight(Unit* pWho)
{
    if (!m_creature->hasUnitState(UNIT_STAT_STUNNED) && pWho->isTargetableForAttack() && pWho->isInAccessiblePlaceFor(m_creature))
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING) && AssistPlayerInCombat(pWho))
            return;

        if (!m_creature->canFly() && m_creature->GetDistanceZ(pWho) > CREATURE_Z_ATTACK_RANGE)
            return;

        if (m_creature->IsHostileTo(pWho))
        {
            float fAttackRadius = m_creature->GetAttackDistance(pWho);
            if (m_creature->IsWithinDistInMap(pWho, fAttackRadius) && m_creature->IsWithinLOSInMap(pWho))
            {
                if (!m_creature->getVictim())
                {
                    pWho->RemoveAurasDueToSpell(SPELL_AURA_MOD_STEALTH);
                    AttackStart(pWho);
                }
                else if (m_creature->GetMap()->IsDungeon())
                {
                    pWho->SetInCombatWith(m_creature);
                    m_creature->AddThreat(pWho, 0.0f);
                }
            }
        }
    }
}

void npc_escortAI::JustDied(Unit* pKiller)
{
    if (!HasEscortState(STATE_ESCORT_ESCORTING) || !m_uiPlayerGUID || !m_pQuestForEscort)
        return;

    if (Player* pPlayer = GetPlayerForEscort())
    {
        if (Group* pGroup = pPlayer->GetGroup())
        {
            for (GroupReference* pRef = pGroup->GetFirstMember(); pRef != NULL; pRef = pRef->next())
            {
                if (Player* pMember = pRef->getSource())
                {
                    if (pMember->GetQuestStatus(m_pQuestForEscort->GetQuestId()) == QUEST_STATUS_INCOMPLETE)
                        pMember->FailQuest(m_pQuestForEscort->GetQuestId());
                }
            }
        }
        else
        {
            if (pPlayer->GetQuestStatus(m_pQuestForEscort->GetQuestId()) == QUEST_STATUS_INCOMPLETE)
                pPlayer->FailQuest(m_pQuestForEscort->GetQuestId());
        }
    }
}

void npc_escortAI::JustRespawned()
{
    m_uiEscortState = STATE_ESCORT_NONE;

    if (!IsCombatMovement())
        SetCombatMovement(true);

    //add a small delay before going to first waypoint, normal in near all cases
    m_uiWPWaitTimer = 2500;

    if (m_creature->getFaction() != m_creature->GetCreatureInfo()->faction_A)
        me->RestoreFaction();

    Reset();
}

void npc_escortAI::ReturnToLastPoint()
{
    float x, y, z, o;
    m_creature->GetHomePosition(x, y, z, o);
    m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, x, y, z);
}

void npc_escortAI::EnterEvadeMode()
{
    m_creature->RemoveAllAuras();
    m_creature->DeleteThreatList();
    m_creature->CombatStop(true);
    m_creature->SetLootRecipient(NULL);

    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        AddEscortState(STATE_ESCORT_RETURNING);
        ReturnToLastPoint();
        debug_log("TSCR: EscortAI has left combat and is now returning to last point");
    }
    else
    {
        m_creature->GetMotionMaster()->MoveTargetedHome();
        Reset();
    }
}

bool npc_escortAI::IsPlayerOrGroupInRange()
{
    if (Player* pPlayer = GetPlayerForEscort())
    {
        if (Group* pGroup = pPlayer->GetGroup())
        {
            for (GroupReference* pRef = pGroup->GetFirstMember(); pRef != NULL; pRef = pRef->next())
            {
                Player* pMember = pRef->getSource();

                if (pMember && m_creature->IsWithinDistInMap(pMember, GetMaxPlayerDistance()))
                {
                    return true;
                    break;
                }
            }
        }
        else
        {
            if (m_creature->IsWithinDistInMap(pPlayer, GetMaxPlayerDistance()))
                return true;
        }
    }
    return false;
}

void npc_escortAI::UpdateAI(const uint32 uiDiff)
{
    //Waypoint Updating
    if (HasEscortState(STATE_ESCORT_ESCORTING) && !m_creature->getVictim() && m_uiWPWaitTimer && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (m_uiWPWaitTimer <= uiDiff)
        {
            //End of the line
            if (CurrentWP == WaypointList.end())
            {
                if (DespawnAtEnd)
                {
                    debug_log("TSCR: EscortAI reached end of waypoints");

                    if (m_bCanReturnToStart)
                    {
                        float fRetX, fRetY, fRetZ;
                        m_creature->GetRespawnCoord(fRetX, fRetY, fRetZ);

                        m_creature->GetMotionMaster()->MovePoint(POINT_HOME, fRetX, fRetY, fRetZ);

                        m_uiWPWaitTimer = 0;

                        debug_log("TSCR: EscortAI are returning home to spawn location: %u, %f, %f, %f", POINT_HOME, fRetX, fRetY, fRetZ);
                        return;
                    }

                    if (m_bCanInstantRespawn)
                    {
                        m_creature->setDeathState(JUST_DIED);
                        m_creature->Respawn();
                    }
                    else
                        m_creature->ForcedDespawn();

                    return;
                }
                else
                {
                    debug_log("TSCR: EscortAI reached end of waypoints with Despawn off");

                    return;
                }
            }

            if (!HasEscortState(STATE_ESCORT_PAUSED))
            {
                m_creature->GetMotionMaster()->MovePoint(CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);
                debug_log("TSCR: EscortAI start waypoint %u (%f, %f, %f).", CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);

                WaypointStart(CurrentWP->id);

                m_uiWPWaitTimer = 0;
            }
        }
        else
            m_uiWPWaitTimer -= uiDiff;
    }

    //Check if player or any member of his group is within range
    if (HasEscortState(STATE_ESCORT_ESCORTING) && m_uiPlayerGUID && !m_creature->getVictim() && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (m_uiPlayerCheckTimer <= uiDiff)
        {
            if (DespawnAtFar && !IsPlayerOrGroupInRange())
            {
                debug_log("TSCR: EscortAI failed because player/group was to far away or not found");

                if (m_bCanInstantRespawn)
                {
                    m_creature->setDeathState(JUST_DIED);
                    m_creature->Respawn();
                }
                else
                    m_creature->ForcedDespawn();

                return;
            }

            m_uiPlayerCheckTimer = 1000;
        }
        else
            m_uiPlayerCheckTimer -= uiDiff;
    }

    UpdateEscortAI(uiDiff);
}

void npc_escortAI::UpdateEscortAI(const uint32 uiDiff)
{
    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

void npc_escortAI::MovementInform(uint32 uiMoveType, uint32 uiPointId)
{
    if (uiMoveType != POINT_MOTION_TYPE || !HasEscortState(STATE_ESCORT_ESCORTING))
        return;

    //Combat start position reached, continue waypoint movement
    if (uiPointId == POINT_LAST_POINT)
    {
        debug_log("TSCR: EscortAI has returned to original position before combat");

        if (m_bIsRunning && m_creature->HasUnitMovementFlag(MOVEMENTFLAG_WALK_MODE))
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        else if (!m_bIsRunning && !m_creature->HasUnitMovementFlag(MOVEMENTFLAG_WALK_MODE))
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

        RemoveEscortState(STATE_ESCORT_RETURNING);

        if (!m_uiWPWaitTimer)
            m_uiWPWaitTimer = 1;
    }
    else if (uiPointId == POINT_HOME)
    {
        debug_log("TSCR: EscortAI has returned to original home location and will continue from beginning of waypoint list.");

        CurrentWP = WaypointList.begin();
        m_uiWPWaitTimer = 1;
    }
    else
    {
        //Make sure that we are still on the right waypoint
        if (CurrentWP->id != uiPointId)
        {
            error_log("TSCR ERROR: EscortAI reached waypoint out of order %u, expected %u", uiPointId, CurrentWP->id);
            return;
        }

        debug_log("TSCR: EscortAI Waypoint %u reached", CurrentWP->id);

        //Call WP function
        WaypointReached(CurrentWP->id);

        m_uiWPWaitTimer = CurrentWP->WaitTimeMs + 1;

        ++CurrentWP;
    }
}

/*
void npc_escortAI::OnPossess(bool apply)
{
    // We got possessed in the middle of being escorted, store the point
    // where we left off to come back to when possess is removed
    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        if (apply)
            m_creature->GetPosition(LastPos.x, LastPos.y, LastPos.z);
        else
        {
            Returning = true;
            m_creature->GetMotionMaster()->MovementExpired();
            m_creature->GetMotionMaster()->MovePoint(WP_LAST_POINT, LastPos.x, LastPos.y, LastPos.z);
        }
    }
}
*/

void npc_escortAI::AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs)
{
    Escort_Waypoint t(id, x, y, z, WaitTimeMs);

    WaypointList.push_back(t);

    // i think SD2 no longer uses this function
    ScriptWP = true;
    /*PointMovement wp;
    wp.m_uiCreatureEntry = me->GetEntry();
    wp.m_uiPointId = id;
    wp.m_fX = x;
    wp.m_fY = y;
    wp.m_fZ = z;
    wp.m_uiWaitTime = WaitTimeMs;
    PointMovementMap[wp.m_uiCreatureEntry].push_back(wp);*/
}

void npc_escortAI::FillPointMovementListForCreature()
{
    std::vector<ScriptPointMove> const &pPointsEntries = pSystemMgr.GetPointMoveList(m_creature->GetEntry());

    if (pPointsEntries.empty())
        return;

    std::vector<ScriptPointMove>::const_iterator itr;

    for (itr = pPointsEntries.begin(); itr != pPointsEntries.end(); ++itr)
    {
        Escort_Waypoint pPoint(itr->uiPointId, itr->fX, itr->fY, itr->fZ, itr->uiWaitTime);
        WaypointList.push_back(pPoint);
    }
}

void npc_escortAI::SetRun(bool bRun)
{
    if (bRun)
    {
        if (!m_bIsRunning)
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        else
            debug_log("TSCR: EscortAI attempt to set run mode, but is already running.");
    }
    else
    {
        if (m_bIsRunning)
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        else
            debug_log("TSCR: EscortAI attempt to set walk mode, but is already walking.");
    }
    m_bIsRunning = bRun;
}

//TODO: get rid of this many variables passed in function.
void npc_escortAI::Start(bool bIsActiveAttacker, bool bRun, uint64 uiPlayerGUID, const Quest* pQuest, bool bInstantRespawn, bool bCanLoopPath)
{
    if (m_creature->getVictim())
    {
        error_log("TSCR ERROR: EscortAI attempt to Start while in combat.");
        return;
    }

    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        error_log("TSCR: EscortAI attempt to Start while already escorting.");
        return;
    }

    if(!ScriptWP) // sd2 never adds wp in script, but tc does
    {

    if (!WaypointList.empty())
        WaypointList.clear();

    FillPointMovementListForCreature();

    }

    if (WaypointList.empty())
    {
        error_db_log("TSCR: EscortAI Start with 0 waypoints (possible missing entry in script_waypoint. Quest: %u).", pQuest->GetQuestId());
        return;
    }

    //set variables
    m_bIsActiveAttacker = bIsActiveAttacker;
    m_bIsRunning = bRun;

    m_uiPlayerGUID = uiPlayerGUID;
    m_pQuestForEscort = pQuest;

    m_bCanInstantRespawn = bInstantRespawn;
    m_bCanReturnToStart = bCanLoopPath;

    if (m_bCanReturnToStart && m_bCanInstantRespawn)
        debug_log("TSCR: EscortAI is set to return home after waypoint end and instant respawn at waypoint end. Creature will never despawn.");

    if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
    {
        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MoveIdle();
        debug_log("TSCR: EscortAI start with WAYPOINT_MOTION_TYPE, changed to MoveIdle.");
    }

    //disable npcflags
    m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

    debug_log("TSCR: EscortAI started with %u waypoints. ActiveAttacker = %d, Run = %d, PlayerGUID = %u", WaypointList.size(), m_bIsActiveAttacker, m_bIsRunning, m_uiPlayerGUID);

    CurrentWP = WaypointList.begin();

    //Set initial speed
    if (m_bIsRunning)
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
    else
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

    AddEscortState(STATE_ESCORT_ESCORTING);
}

void npc_escortAI::SetEscortPaused(bool bPaused)
{
    if (!HasEscortState(STATE_ESCORT_ESCORTING))
        return;

    if (bPaused)
        AddEscortState(STATE_ESCORT_PAUSED);
    else
        RemoveEscortState(STATE_ESCORT_PAUSED);
}
