/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 */

#ifndef AIWORLD_AGENTTELEMETRYSNAPSHOT_H
#define AIWORLD_AGENTTELEMETRYSNAPSHOT_H

#include "Agent/AgentSnapshot.h"
#include "Agent/AgentType.h"
#include "Action/ActionType.h"
#include "Faction/WorldFactionId.h"
#include "Goal/GoalType.h"
#include "Needs/NeedsState.h"
#include "Scheduler/SimulationTier.h"
#include <optional>
#include <string>

// A value-only observation captured on the world thread. No Creature, Map,
// registry, or other world-owned object crosses the asynchronous boundary.
struct AgentTelemetrySnapshot
{
    AgentId Agent;
    uint64 SpawnId = 0;
    uint32 Entry = 0;
    std::string Name;
    AgentType Type = AgentType::Unclassified;
    AgentControlMode ControlMode = AgentControlMode::ObserveOnly;
    WorldFactionId WorldFaction;
    AgentWorldState WorldState = AgentWorldState::Abstract;
    SimulationTier Tier = SimulationTier::Background;

    // Always authoritative spawn coordinates. Live contains actual current
    // coordinates and stats only when a Creature was resolved during capture.
    uint32 MapId = 0;
    float SpawnX = 0.0f;
    float SpawnY = 0.0f;
    float SpawnZ = 0.0f;
    std::optional<AgentSnapshot> Live;

    NeedsState Needs;
    std::optional<GoalType> Goal;
    std::optional<float> GoalUtility;
    std::optional<GoalType> RoutineGoal;
    std::optional<ActionType> Action;
    std::optional<uint64> GroupId;
};

#endif // AIWORLD_AGENTTELEMETRYSNAPSHOT_H
