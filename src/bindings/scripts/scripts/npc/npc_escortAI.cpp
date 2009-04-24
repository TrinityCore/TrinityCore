/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

/* ScriptData
SDName: Npc_EscortAI
SD%Complete: 100
SDComment:
SDCategory: Npc
EndScriptData */

#include "precompiled.h"
#include "npc_escortAI.h"

#define WP_LAST_POINT   -1

bool npc_escortAI::IsVisible(Unit* who) const
{
    if (!who)
        return false;

    return (m_creature->GetDistance(who) < VISIBLE_RANGE) && who->isVisibleForOrDetect(m_creature,true);
}

void npc_escortAI::AttackStart(Unit *who)
{
    if (!who)
        return;

    if (IsBeingEscorted && !Defend)
        return;


        if ( m_creature->Attack(who, true) )
        {
            m_creature->AddThreat(who, 0.0f);

        if (!InCombat)
        {
            InCombat = true;

            if (IsBeingEscorted)
            {
            //Store last position
            m_creature->GetPosition(LastPos.x, LastPos.y, LastPos.z);

             debug_log("TSCR: EscortAI has entered combat and stored last location.");
            }

            Aggro(who);
        }

        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MoveChase(who);
    }
}

void npc_escortAI::MoveInLineOfSight(Unit *who)
{
    if (IsBeingEscorted && !Attack)
        return;

    if(m_creature->getVictim() || !m_creature->canStartAttack(who))
        return;

    AttackStart(who);
}

void npc_escortAI::JustRespawned()
{
    InCombat = false;
    IsBeingEscorted = false;
    IsOnHold = false;

    //Re-Enable questgiver flag
    m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

    Reset();
}

void npc_escortAI::EnterEvadeMode()
{
    InCombat = false;

    m_creature->RemoveAllAuras();
    m_creature->DeleteThreatList();
    m_creature->CombatStop();
    m_creature->SetLootRecipient(NULL);

    if (IsBeingEscorted)
    {
        debug_log("TSCR: EscortAI has left combat and is now returning to last point.");
        Returning = true;
        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MovePoint(WP_LAST_POINT, LastPos.x, LastPos.y, LastPos.z);

    }else
    {
        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MoveTargetedHome();
    }

    Reset();
}

void npc_escortAI::UpdateAI(const uint32 diff)
{
    //Waypoint Updating
    if (IsBeingEscorted && !InCombat && WaitTimer && !Returning)
    {
        if (WaitTimer <= diff)
    {
        if (ReconnectWP)
        {
            //Correct movement speed
            if (Run)
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            else m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

            //Continue with waypoints
            if( !IsOnHold )
            {
                m_creature->GetMotionMaster()->MovePoint(CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z );
                debug_log("TSCR: EscortAI Reconnect WP is: %u, %f, %f, %f", CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);
                WaitTimer = 0;
                ReconnectWP = false;
                return;
            }
        }

        //End of the line, Despawn self then immediatly respawn
        if (CurrentWP == WaypointList.end())
        {
            if(DespawnAtEnd)
            {
                debug_log("TSCR: EscortAI reached end of waypoints");

                m_creature->setDeathState(JUST_DIED);
                m_creature->SetHealth(0);
                m_creature->CombatStop();
                m_creature->DeleteThreatList();
                m_creature->Respawn();
                m_creature->GetMotionMaster()->Clear(true);

                //Re-Enable gossip
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                IsBeingEscorted = false;
                WaitTimer = 0;
                return;
            }else{
                debug_log("TSCR: EscortAI reached end of waypoints with Despawn off");
                IsBeingEscorted = false;
                WaitTimer = 0;
                return;
            }
        }

        if( !IsOnHold )
        {
            m_creature->GetMotionMaster()->MovePoint(CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z );
            debug_log("TSCR: EscortAI Next WP is: %u, %f, %f, %f", CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);
            WaitTimer = 0;
        }
    }else WaitTimer -= diff;
    }

    //Check if player is within range
    if (IsBeingEscorted && !InCombat && PlayerGUID)
    {
        if (PlayerTimer < diff)
    {
        Unit* p = Unit::GetUnit(*m_creature, PlayerGUID);

        if (DespawnAtFar && (!p || m_creature->GetDistance(p) > GetMaxPlayerDistance()))
        {
            JustDied(m_creature);
            IsBeingEscorted = false;

            debug_log("TSCR: EscortAI Evaded back to spawn point because player was to far away or not found");

            m_creature->setDeathState(JUST_DIED);
            m_creature->SetHealth(0);
            m_creature->CombatStop();
            m_creature->DeleteThreatList();
            m_creature->Respawn();
            m_creature->GetMotionMaster()->Clear(true);

            //Re-Enable gossip
            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        PlayerTimer = 1000;
    }else PlayerTimer -= diff;
    }

    if(CanMelee)
    {
        //Check if we have a current target
        if( m_creature->isAlive() && UpdateVictim())
        {
            //If we are within range melee the target
            if( m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            {
                if( m_creature->isAttackReady() )
                {
                    m_creature->AttackerStateUpdate(m_creature->getVictim());
                    m_creature->resetAttackTimer();
                }
            }
        }
    }
}

void npc_escortAI::MovementInform(uint32 type, uint32 id)
{
    if (type != POINT_MOTION_TYPE || !IsBeingEscorted)
        return;

    //Original position reached, continue waypoint movement
    if (id == WP_LAST_POINT)
    {
        debug_log("TSCR: EscortAI has returned to original position before combat");
        ReconnectWP = true;
        Returning = false;
        WaitTimer = 1;

    }else
    {
        //Make sure that we are still on the right waypoint
        if (CurrentWP->id != id)
        {
            debug_log("SD2 ERROR: EscortAI reached waypoint out of order %d, expected %d", id, CurrentWP->id);
            return;
        }

        debug_log("TSCR: EscortAI Waypoint %d reached", CurrentWP->id);

        //Call WP function
        WaypointReached(CurrentWP->id);

        WaitTimer = CurrentWP->WaitTimeMs + 1;

        ++CurrentWP;
    }
}

void npc_escortAI::OnPossess(bool apply)
{
    // We got possessed in the middle of being escorted, store the point
    // where we left off to come back to when possess is removed
    if (IsBeingEscorted)
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



void npc_escortAI::AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs)
{
    Escort_Waypoint t(id, x, y, z, WaitTimeMs);

    WaypointList.push_back(t);
}

void npc_escortAI::Start(bool bAttack, bool bDefend, bool bRun, uint64 pGUID)
{
    if (InCombat)
    {
        debug_log("SD2 ERROR: EscortAI attempt to Start while in combat");
        return;
    }

    if (WaypointList.empty())
    {
        debug_log("SD2 ERROR: Call to escortAI::Start with 0 waypoints");
        return;
    }

    Attack = bAttack;
    Defend = bDefend;
    Run = bRun;
    PlayerGUID = pGUID;

    debug_log("TSCR: EscortAI started with %d waypoints. Attack = %d, Defend = %d, Run = %d, PlayerGUID = %d", WaypointList.size(), Attack, Defend, Run, PlayerGUID);

    CurrentWP = WaypointList.begin();

    //Set initial speed
    if (Run)
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
    else m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

    //Start WP
    m_creature->GetMotionMaster()->MovePoint(CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z );
    debug_log("TSCR: EscortAI Next WP is: %d, %f, %f, %f", CurrentWP->id, CurrentWP->x, CurrentWP->y, CurrentWP->z);
    IsBeingEscorted = true;
    ReconnectWP = false;
    Returning = false;
    IsOnHold = false;

    //Disable questgiver flag
    m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
}

