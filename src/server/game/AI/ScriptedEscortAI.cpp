/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

/* ScriptData
SDName: EscortAI
SD%Complete: 100
SDComment:
SDCategory: Npc
EndScriptData */

#include "ScriptedEscortAI.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "MovementGenerator.h"
#include "Player.h"
#include "Group.h"

float const DEFAULT_MAX_PLAYER_DISTANCE = 100.0f;
float const DEFAULT_MAX_ASSIST_DISTANCE =  40.0f;

enum
{
    POINT_LAST_POINT    = 0xFFFFFF,
    POINT_HOME          = 0xFFFFFE
};

npc_escortAI::npc_escortAI(Creature* pCreature) : ScriptedAI(pCreature),
    m_uiPlayerGUID(0),
    m_uiPlayerCheckTimer(1000),
    m_uiEscortState(STATE_ESCORT_NONE),
    m_uiDelayBeforeTheFirstWaypoint(2500),
    m_pQuestForEscort(nullptr),
    m_currentWaypointIdx(0),
    m_bIsRunning(false),
    m_bCanInstantRespawn(false),
    m_bCanReturnToStart(false),
    m_bIsPathfindingEnabledBetweenWaypoints(true),
    m_MaxPlayerDistance(DEFAULT_MAX_PLAYER_DISTANCE),
    m_MaxAssistDistance(DEFAULT_MAX_ASSIST_DISTANCE),
    m_combatStartX(m_creature->GetPositionX()),
    m_combatStartY(m_creature->GetPositionY()),
    m_combatStartZ(m_creature->GetPositionZ()),
    m_combatStartO(m_creature->GetOrientation())
{
    m_uiWPWaitTimer = m_uiDelayBeforeTheFirstWaypoint;
    pCreature->SetEscortable(true);
}

void npc_escortAI::setCurrentWP (uint32 idx)
{
    if (idx >= WaypointList.size())
        sLog.outInfo("[npc_escortAI] Attempt to set current waypoint to %u, but NPC entry=%u only has %u waypoints !", idx, m_creature->GetEntry(), WaypointList.size());
    else
    m_currentWaypointIdx = idx;
}

void npc_escortAI::AttackStart(Unit* pWho)
{
    if (!pWho)
        return;

    if (m_creature->Attack(pWho, true))
    {
        //if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
        //    m_creature->GetMotionMaster()->MovementExpired();

        m_creature->AddThreat(pWho);
        m_creature->SetInCombatWith(pWho);
        pWho->SetInCombatWith(m_creature);

        if (IsCombatMovementEnabled())
            m_creature->GetMotionMaster()->MoveChase(pWho);
    }
}

void npc_escortAI::EnterCombat(Unit* pEnemy)
{
    if (!pEnemy)
        return;

    if (!HasEscortState(STATE_ESCORT_RETURNING))
    {
        float x, y, z;
        m_creature->GetPosition(x, y, z);
        SetCombatStartPosition(x, y, z);
        m_combatStartO = m_creature->GetOrientation();      
    }

    Aggro(pEnemy);
}

void npc_escortAI::Aggro(Unit* /*pEnemy*/)
{
}

Player* npc_escortAI::GetPlayerForEscort() const
{
    return m_creature->GetMap()->GetPlayer(m_uiPlayerGUID);
}

bool npc_escortAI::AssistPlayerInCombat(Unit* pWho)
{
    if (!m_uiPlayerGUID)
        return false;

    if (!pWho->GetVictim())
        return false;

    //experimental (unknown) flag not present
    if (!m_creature->CanAssistPlayers())
        return false;

    if (m_creature->HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_FEIGN_DEATH))
        return false;

    //not a player
    if (!pWho->GetVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
        return false;

    //never attack friendly
    if (m_creature->IsFriendlyTo(pWho))
        return false;

    //too far away and no free sight?
    if (m_creature->IsWithinDistInMap(pWho, m_MaxAssistDistance) && m_creature->IsWithinLOSInMap(pWho))
    {
        //already fighting someone?
        if (!m_creature->GetVictim())
        {
            AttackStart(pWho);
            return true;
        }

        pWho->SetInCombatWith(m_creature);
        m_creature->AddThreat(pWho);
        return true;
    }

    return false;
}

void npc_escortAI::MoveInLineOfSight(Unit* pWho)
{
    if (pWho->IsTargetable(true, false) && pWho->IsInAccessablePlaceFor(m_creature))
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING) && AssistPlayerInCombat(pWho))
            return;

        if (!m_creature->CanInitiateAttack())
            return;
       // if (!m_creature->canFly() && m_creature->GetDistanceZ(pWho) > CREATURE_Z_ATTACK_RANGE)
         //   return;

        if (m_creature->IsHostileTo(pWho))
        {
            float fAttackRadius = m_creature->GetAttackDistance(pWho);
            if (m_creature->IsWithinDistInMap(pWho, fAttackRadius, true, false) && m_creature->IsWithinLOSInMap(pWho))
            {
                if (!m_creature->GetVictim())
                {
                    //pWho->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                    AttackStart(pWho);
                }
                else
                {
                    pWho->SetInCombatWith(m_creature);
                    m_creature->AddThreat(pWho);
                }
            }
        }
    }
}

void npc_escortAI::JustDied(Unit* /*pKiller*/)
{
    if (!HasEscortState(STATE_ESCORT_ESCORTING) || !m_uiPlayerGUID || !m_pQuestForEscort)
        return;

    if (Player* pPlayer = GetPlayerForEscort())
    {
        pPlayer->GroupEventFailHappens(m_pQuestForEscort->GetQuestId());
        pPlayer->SetEscortingGuid(ObjectGuid());
    }
}

void npc_escortAI::JustRespawned()
{
    m_uiEscortState = STATE_ESCORT_NONE;

    if (!IsCombatMovementEnabled())
        SetCombatMovement(true);

    //add a small delay before going to first waypoint.
    m_uiWPWaitTimer = m_uiDelayBeforeTheFirstWaypoint;

    if (m_creature->GetFactionTemplateId() != m_creature->GetCreatureInfo()->faction)
        m_creature->SetFactionTemplateId(m_creature->GetCreatureInfo()->faction);

    Reset();
    ResetCreature();
}

void npc_escortAI::EnterEvadeMode()
{
    m_creature->RemoveAurasAtReset();
    m_creature->DeleteThreatList();
    m_creature->CombatStop(true);
    m_creature->SetLootRecipient(nullptr);

    if (!HasEscortState(STATE_ESCORT_ESCORTING))
        ResetCreature();

    // Reset back to default spells template. This also resets timers.
    SetSpellsList(m_creature->GetCreatureInfo()->spell_list_id);

    ReturnToCombatStartPosition();
    Reset();
}

bool npc_escortAI::IsPlayerOrGroupInRange() const
{
    if (Player* pPlayer = GetPlayerForEscort())
    {
        if (Group* pGroup = pPlayer->GetGroup())
        {
            for(GroupReference* pRef = pGroup->GetFirstMember(); pRef != nullptr; pRef = pRef->next())
            {
                Player* pMember = pRef->getSource();

                if (pMember && m_creature->IsWithinDistInMap(pMember, m_MaxPlayerDistance))
                    return true;

            }
        }
        else
        {
            if (m_creature->IsWithinDistInMap(pPlayer, m_MaxPlayerDistance))
                return true;
        }
    }
    return false;
}

void npc_escortAI::UpdateAI(uint32 const uiDiff)
{
    //Waypoint Updating
    if (HasEscortState(STATE_ESCORT_ESCORTING) && !m_creature->IsInCombat() && m_uiWPWaitTimer && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (m_uiWPWaitTimer <= uiDiff)
        {
            //End of the line
            auto CurrentWP = WaypointList.begin();
            if (m_currentWaypointIdx <= WaypointList.size())
                CurrentWP += m_currentWaypointIdx;
            if (CurrentWP == WaypointList.end())
            {
                sLog.outDebug("EscortAI reached end of waypoints");

                ResetCreature();

                if (m_bCanReturnToStart)
                {
                    float fRetX, fRetY, fRetZ;
                    m_creature->GetRespawnCoord(fRetX, fRetY, fRetZ);

                    m_creature->GetMotionMaster()->MovePoint(POINT_HOME, fRetX, fRetY, fRetZ, MOVE_PATHFINDING);

                    m_uiWPWaitTimer = 0;

                    sLog.outDebug("EscortAI are returning home to spawn location: %u, %f, %f, %f", POINT_HOME, fRetX, fRetY, fRetZ);
                    return;
                }
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                m_creature->DisappearAndDie();

                if (Player* player = GetPlayerForEscort())
                    player->SetEscortingGuid(ObjectGuid());

                if (m_bCanInstantRespawn)
                    m_creature->Respawn();
                return;
            }

            if (!HasEscortState(STATE_ESCORT_PAUSED))
            {
                // If the creature has just returned from combat there's a motion to resume
                if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                    m_creature->GetMotionMaster()->top()->Initialize(*m_creature);
                else
                {
                    uint32 options = m_bIsPathfindingEnabledBetweenWaypoints ? MOVE_PATHFINDING : 0;
                    options |= m_bIsRunning ? MOVE_RUN_MODE : MOVE_WALK_MODE;
                    m_creature->GetMotionMaster()->MovePoint(CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z, options);
                    sLog.outDebug("EscortAI start waypoint %u (%f, %f, %f).", CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);

                    WaypointStart(CurrentWP->id);
                }

                m_uiWPWaitTimer = 0;
            }
        }
        else
            m_uiWPWaitTimer -= uiDiff;
    }

    //Check if player or any member of his group is within range
    if (HasEscortState(STATE_ESCORT_ESCORTING) && m_uiPlayerGUID && m_MaxPlayerDistance && !m_creature->IsInCombat() && !HasEscortState(STATE_ESCORT_RETURNING))
    {
        if (m_uiPlayerCheckTimer < uiDiff)
        {
            if (!IsPlayerOrGroupInRange())
            {
                sLog.outDebug("EscortAI failed because player/group was to far away or not found");

                JustDied(nullptr);
                ResetEscort();
                
                return;
            }

            m_uiPlayerCheckTimer = 1000;
        }
        else
            m_uiPlayerCheckTimer -= uiDiff;
    }

    UpdateEscortAI(uiDiff);
}

void npc_escortAI::ResetEscort()
{
    ResetCreature();

    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    m_creature->DisappearAndDie();

    if (m_bCanInstantRespawn)
        m_creature->Respawn();
}

void npc_escortAI::UpdateEscortAI(uint32 const uiDiff)
{
    // Make nearby enemies aggro passive escort npcs
    if (HasEscortState(STATE_ESCORT_ESCORTING) && !m_creature->IsInCombat())
    {
        if (Unit* pTarget = m_creature->SelectNearestHostileUnitInAggroRange(true))
            if ((pTarget->GetTypeId() == TYPEID_UNIT) && !pTarget->GetCharmInfo() && !pTarget->IsInCombat())
                pTarget->AI()->AttackStart(m_creature);
    }

    // Check if we have a current target
    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;

    if (!m_CreatureSpells.empty())
        UpdateSpellsList(uiDiff);

    DoMeleeAttackIfReady();
}

void npc_escortAI::MovementInform(uint32 uiMoveType, uint32 uiPointId)
{
    if (uiMoveType != POINT_MOTION_TYPE || !HasEscortState(STATE_ESCORT_ESCORTING))
        return;

    //Combat start position reached, continue waypoint movement
    if (uiPointId == POINT_LAST_POINT)
    {
        sLog.outDebug("EscortAI has returned to original position before combat");

        if (m_bIsRunning)
            m_creature->SetWalk(false);
        else
            m_creature->SetWalk(true);

        RemoveEscortState(STATE_ESCORT_RETURNING);

        if (!m_uiWPWaitTimer)
            m_uiWPWaitTimer = 1;
    }
    else if (uiPointId == POINT_HOME)
    {
        // wp reach should not count if we crossed it while returning
        if (HasEscortState(STATE_ESCORT_RETURNING)) return;

        sLog.outDebug("EscortAI has returned to original home location and will continue from beginning of waypoint list.");

        m_currentWaypointIdx = 0;
        m_uiWPWaitTimer = 1;
    }
    else
    {
        // wp reach should not count if we crossed it while returning
        if (HasEscortState(STATE_ESCORT_RETURNING)) return;

        if (m_currentWaypointIdx >= WaypointList.size()) return;

        auto const& wp = WaypointList[m_currentWaypointIdx];
        // MovePoint interrupted for any reason
        if (m_creature->GetDistance(wp.x, wp.y, wp.z) > 10.0f)
        {
            m_uiWPWaitTimer = 1;
            return;
        }

        //Make sure that we are still on the right waypoint
        if (wp.id != uiPointId)
        {
            sLog.outError("[ScriptedEscortAI] Waypoint out of order for <#%u - %s>: <%u> instead of <%u>.", 
                m_creature->GetEntry(), m_creature->GetName(), uiPointId, wp.id);
            return;
        }

        sLog.outDebug("EscortAI waypoint %u reached.", wp.id);

        //Call WP function
        WaypointReached(wp.id);

        m_uiWPWaitTimer = wp.WaitTimeMs + 1;

        ++m_currentWaypointIdx;
    }
}

/*void npc_escortAI::AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs)
{
    Escort_Waypoint t(id, x, y, z, WaitTimeMs);

    WaypointList.push_back(t);
}*/

void npc_escortAI::FillPointMovementListForCreature()
{
    auto const& pPointsEntries = sScriptMgr.GetPointMoveList(m_creature->GetEntry());

    if (pPointsEntries.empty())
        return;

    for (const auto& itr : pPointsEntries)
    {
        Escort_Waypoint pPoint(itr.uiPointId, itr.fX, itr.fY, itr.fZ, itr.uiWaitTime);
        WaypointList.push_back(pPoint);
    }
}

void npc_escortAI::SetRun(bool bRun)
{
    if (bRun)
    {
        if (!m_bIsRunning)
            m_creature->SetWalk(false);
        else
            sLog.outDebug("EscortAI attempt to set run mode, but is already running.");
    }
    else
    {
        if (m_bIsRunning)
            m_creature->SetWalk(true);
        else
            sLog.outDebug("EscortAI attempt to set walk mode, but is already walking.");
    }
    m_bIsRunning = bRun;
}

void npc_escortAI::Start(bool bRun, uint64 uiPlayerGUID, Quest const* pQuest, bool bInstantRespawn, bool bCanLoopPath)
{
    if (m_creature->IsInCombat())
    {
        sLog.outError("EscortAI attempt to Start while in combat.");
        return;
    }

    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        sLog.outError("EscortAI attempt to Start while already escorting.");
        return;
    }

    if (!WaypointList.empty())
        WaypointList.clear();

    FillPointMovementListForCreature();

    if (WaypointList.empty())
    {
        sLog.outErrorDb("EscortAI Start with 0 waypoints (possible missing entry in script_waypoint).");
        return;
    }

    //set variables
    m_bIsRunning = bRun;

    m_uiPlayerGUID = uiPlayerGUID;
    m_pQuestForEscort = pQuest;

    m_bCanInstantRespawn = bInstantRespawn;
    m_bCanReturnToStart = bCanLoopPath;

    if (m_bCanReturnToStart && m_bCanInstantRespawn)
        sLog.outDebug("EscortAI is set to return home after waypoint end and instant respawn at waypoint end. Creature will never despawn.");

    if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
    {
        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MoveIdle();
        sLog.outDebug("EscortAI start with WAYPOINT_MOTION_TYPE, changed to MoveIdle.");
    }

    //disable npcflags
    m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
    sLog.outDebug("EscortAI started with %u waypoints. Run = %d, PlayerGUID = %u", WaypointList.size(), m_bIsRunning, m_uiPlayerGUID);

    m_currentWaypointIdx = 0;

    //Set initial speed
    m_creature->SetWalk(!m_bIsRunning);

    AddEscortState(STATE_ESCORT_ESCORTING);

    if (Player* player = GetPlayerForEscort())
        player->SetEscortingGuid(m_creature->GetObjectGuid());

    JustStartedEscort();
}

void npc_escortAI::Stop()
{
    if (Player* player = GetPlayerForEscort())
        player->SetEscortingGuid(ObjectGuid());

    RemoveEscortState(STATE_ESCORT_ESCORTING);
    RemoveEscortState(STATE_ESCORT_PAUSED);
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


void npc_escortAI::GetAIInformation(ChatHandler& reader)
{
    reader.PSendSysMessage("EscortAI. Player %u [maxDist=%f]. State=0x%x", m_uiPlayerGUID, m_MaxPlayerDistance, m_uiEscortState);
    reader.PSendSysMessage("CurrentWaypoint: %u/%u. ReturnStart:%u InstantRespawn:%u", m_currentWaypointIdx, WaypointList.size(), m_bCanReturnToStart, m_bCanInstantRespawn);
    ScriptedAI::GetAIInformation(reader);
}

void npc_escortAI::ReturnToCombatStartPosition()
{
    if (HasEscortState(STATE_ESCORT_ESCORTING))
    {
        sLog.outDebug("EscortAI has left combat and is now returning to CombatStartPosition.");

        if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
        {
            AddEscortState(STATE_ESCORT_RETURNING);

            float fPosX, fPosY, fPosZ;
            GetCombatStartPosition(fPosX, fPosY, fPosZ);

            if (m_creature->GetDistance2d(fPosX, fPosY) > 1000.0f)
            {
                sLog.outError("[ScriptedEscortAI.GetCombatStartPosition] Creature with entry <%u> is in <%f> distance from {%f,%f,%f}.", 
                    m_creature->GetEntry(), m_creature->GetDistance2d(fPosX, fPosY), fPosX, fPosY, fPosZ);
                m_creature->GetPosition(fPosX, fPosY, fPosY);
                SetCombatStartPosition(fPosX, fPosY, fPosZ);
                MovementInform(POINT_MOTION_TYPE, POINT_LAST_POINT);
                return;
            }

            m_creature->GetMotionMaster()->MovePoint(POINT_LAST_POINT, fPosX, fPosY, fPosZ, MOVE_RUN_MODE|MOVE_PATHFINDING, 0, m_combatStartO);
        }
    }
    else
    {
        if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
        {
            m_creature->DisableSpline();
            m_creature->GetMotionMaster()->MoveTargetedHome();
        }
    }
}
