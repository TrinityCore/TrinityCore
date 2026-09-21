/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef AIWORLD_GOALTYPE_H
#define AIWORLD_GOALTYPE_H

#include "Define.h"

// Milestone 2.7A only generates candidates for the first two - the full
// SURVIVE/MAKE_MONEY/PROTECT_HOME/HELP_FAMILY/WORK/REST/INVESTIGATE/
// REQUEST_HELP catalog (per the roadmap's 2.7 Goal System) comes later,
// once GET_FOOD/FLEE_DANGER have cleared their own runtime gate.
//
// GoToWork/GoHome (2.11C) are a deliberate exception to that: they are
// never produced by GoalSystem::GenerateCandidates()/UpdateActiveGoal(),
// never appear in AgentRecord::ActiveGoalState, and have no Need behind
// them (see RoutineSystem.h for why routine is its own, separate, non-
// Need-driven decision from GoalSystem's). They exist in this enum purely
// so RoutineGoal::Type can double as ActionRequest::SourceGoal/
// ActiveAction::SourceGoal directly - reusing the exact same "AI proposes,
// ActionSystem validates, ActionExecutor executes" MOVE_TO pipeline
// GET_FOOD already goes through, rather than inventing a second, parallel
// action-identity type just for routine.
//
// Regroup (2.12F2) is the same kind of exception, one tier further down:
// never produced by GoalSystem, never appears in ActiveGoalState/
// RoutineGoalState, no Need or persisted schedule behind it - it exists
// purely so GroupCoordinationGoal::Type can double as ActionRequest::
// SourceGoal/ActiveAction::SourceGoal directly, the same "reuse the
// existing MOVE_TO pipeline, don't invent a parallel one" reasoning
// GoToWork/GoHome's own comment already gives. It is the LOWEST-priority
// of the MOVE_TO sources - see AIWorldMgr::UpdateNeeds()'s own
// arbitration comments (2.11C/2.12F2): Emergency ActiveGoal > Normal
// ActiveGoal > RoutineGoal > Regroup/Roam. Produced only by AIWorldMgr::
// DispatchGroupMemberActionProposal(), itself fed by
// AgentGroupIntentSystem/AgentGroupIntentProjector - a group-level
// coordination fact decomposed into one individual member's own,
// separately-validated MOVE_TO, never a command the group issues
// directly (see AgentGroupIntent.h).
//
// Roam (2.12G2) is Regroup's own sibling at that same tier, not a renamed
// Regroup - both are GroupCoordinationGoal-sourced and share the LOWEST
// priority tier and the same MOVE_TO pipeline/range bound
// (ActionSystem::CoordinationMoveToRangeYards()), but they source-tag
// genuinely different individual proposals (AgentGroupIntentType::Regroup
// vs. ::Roam - see GroupMemberActionProposal.h), so ActionRequest::SourceGoal
// must be able to name each honestly rather than reporting every group-
// coordination MOVE_TO as REGROUP regardless of which one actually
// produced it.
//
// Hunt (2.12G3C1) joins Regroup/Roam as a third sibling at that same
// LOWEST tier: Emergency ActiveGoal > Normal ActiveGoal > RoutineGoal >
// Regroup/Roam/Hunt. Unlike Regroup/Roam, it does NOT get its own
// AgentGroupIntentType value - HUNT's group-level intent is already named
// by the separate, purpose-built HuntIntent (2.12G3A/G3B), which
// decomposes directly into per-member HuntProposal values without ever
// passing through AgentGroupIntent/AgentGroupIntentProjector at all. This
// GoalType exists purely so that per-member decomposition can still
// double as ActionRequest::SourceGoal/GroupCoordinationGoal::Type/
// ActiveAction::SourceGoal directly, the same "reuse the existing MOVE_TO
// pipeline, don't invent a parallel one" reasoning every other
// GroupCoordinationGoal-sourced GoalType already gives - HUNT's own
// MOVE_TO (the "approach" leg, 2.12G3C1) still goes through
// ActionType::MoveTo/ActionSystem::Validate()/ActionExecutor exactly like
// Regroup/Roam; only the target-identity requirements it additionally
// enforces (see ActionSystem::ValidateMoveTo()) differ from them. No
// physical attack/combat ActionType exists for Hunt yet - that remains
// out of scope until a later milestone explicitly adds it.
enum class GoalType : uint8
{
    GetFood,
    FleeDanger,
    GoToWork,
    GoHome,
    Regroup,
    Roam,
    Hunt,
    // Living-wolf individual goals, evaluated by UpdateLivingWolf rather
    // than the generic need selector. They preempt group coordination.
    Defend,
    Feed,
    WildlifeRest
};

inline char const* ToString(GoalType type)
{
    switch (type)
    {
        case GoalType::GetFood:    return "GET_FOOD";
        case GoalType::FleeDanger: return "FLEE_DANGER";
        case GoalType::GoToWork:   return "GO_TO_WORK";
        case GoalType::GoHome:     return "GO_HOME";
        case GoalType::Regroup:    return "REGROUP";
        case GoalType::Roam:       return "ROAM";
        case GoalType::Hunt:       return "HUNT";
        case GoalType::Defend:     return "DEFEND";
        case GoalType::Feed:       return "FEED";
        case GoalType::WildlifeRest: return "WILDLIFE_REST";
        default:                   return "UNKNOWN";
    }
}

// Not urgency-ranking within Normal - just marks a candidate as the kind
// that must later be able to interrupt an already-active goal (per the
// roadmap's "přidat možnost cíl přerušit při nouzové situaci"). Selection/
// interruption logic itself is 2.7B - 2.7A only tags candidates with this.
enum class GoalPriority : uint8
{
    Normal,
    Emergency
};

inline char const* ToString(GoalPriority priority)
{
    switch (priority)
    {
        case GoalPriority::Normal:    return "NORMAL";
        case GoalPriority::Emergency: return "EMERGENCY";
        default:                      return "UNKNOWN";
    }
}

// What produced a GoalCandidate. Only Needs exists in 2.7A; a later
// milestone may add e.g. a directly-requested/perceived source without
// changing GoalCandidate's shape.
enum class GoalSource : uint8
{
    Needs
};

inline char const* ToString(GoalSource source)
{
    switch (source)
    {
        case GoalSource::Needs: return "NEEDS";
        default:                return "UNKNOWN";
    }
}

#endif // AIWORLD_GOALTYPE_H
