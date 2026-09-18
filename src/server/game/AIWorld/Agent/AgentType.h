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

#ifndef AIWORLD_AGENTTYPE_H
#define AIWORLD_AGENTTYPE_H

#include "Define.h"

enum class AgentType : uint8
{
    Civilian = 0,
    Guard = 1,
    Merchant = 2,

    // Milestone 2.12D P2 fix (STATIC review): value 3 (formerly
    // CreatureGroup, briefly AgentGroup) is retired, not reused - a group
    // is no longer represented as an AgentType/AgentRecord at all. See
    // GroupId.h/AgentGroupRecord.h/AgentGroupRegistry.h: a group is a
    // social layer over independent member agents (each a real AgentType
    // above, with its own AgentId/identity/memory/needs/goal/decision/
    // actions/Creature lifecycle), never an aggregate sharing this
    // enum's/AgentRecord's identity space with them. Deliberately left as
    // a gap rather than renumbering Civilian/Guard/Merchant, so a stray
    // agent_type = 3 row from before this migration reads as unknown
    // rather than silently as something else.

    // Milestone 2.12F4B: explicit "no deterministic classification signal
    // available yet" provenance - a bulk world.creature reconciliation
    // bootstrap must never silently mislabel an unclassifiable spawn as
    // Civilian just because that enumerator happens to be 0. See
    // AgentTypeCatalog's own comment for where this comes from now.
    Unclassified = 4,

    // AgentType identity fix (AIWorld_Current_Roadmap.md, Etapa 3): a
    // humanoid whose normal function includes armed combat (bandit,
    // caster, scout, ...). Deliberately does NOT mean "hostile to the
    // player" - hostility is never an agent property, only ever a
    // dynamically computed relationship between two WorldFactions (see
    // data/elwynn/factions/README.md). A Combatant can be Friendly to a
    // given player exactly as a Guard can be Hostile to one, depending on
    // that player's own relationship with the agent's WorldFaction - see
    // AgentRecord::WorldFaction's own comment.
    Combatant = 5,

    // Fauna, not humanoid social/political roles - a beast has no
    // diplomacy, so unlike Combatant its relationship to the player is not
    // expected to vary by WorldFaction membership (see ELWYNN_WOLVES'
    // own "ecological/social, no player reputation" design note in
    // data/elwynn/factions/README.md).
    Predator = 6,
    Prey = 7
};

// Materialized: bound to a currently-loaded Creature (RuntimeGuid valid).
// Abstract: no live Creature right now (grid unloaded, not yet spawned,
// etc.) - the agent itself still exists in AgentRegistry either way.
enum class AgentWorldState : uint8
{
    Abstract = 0,
    Materialized = 1
};

// Milestone 2.12F4A: which owner may act on this agent's own Creature
// binding - deliberately separate from mere AgentRecord existence. An
// earlier model conflated "is a known AIWorld agent" with "AIWorld owns
// this Creature's AI/actions", which meant registering every persistent
// TrinityCore creature spawn would have silently taken over guards,
// vendors, quest NPCs, bosses, and scripted NPCs the moment they got an
// AgentRecord at all. Explicit values, persistently stable (this is
// storage ABI - ai_agents.control_mode - never renumber or reuse a
// retired value):
//
//   ObserveOnly (0, the fail-closed default for every new/default
//   AgentRecord - see AgentRecord::ControlMode's own comment): TrinityCore/
//   scripted CreatureAI remains the owner. AIWorld may observe/state-track
//   this agent (identity, memory, needs, perception, whatever the current
//   pipeline already safely supports) but MUST NOT cause a physical world
//   mutation for it - see AIWorldMgr::OwnsSpawn() (never returns true for
//   ObserveOnly, so FactorySelector::SelectAI() never even instantiates
//   AIWorldCreatureAI for it) and ActionValidationContext::ControlMode/
//   ActionSystem::Validate() (the mandatory authoritative gate - rejects
//   every ActionRequest for anything other than AIWorldControlled, common
//   to every ActionType, before any per-ActionType check).
//
//   AIWorldControlled (1): AIWorldCreatureAI may take over CreatureAI (via
//   OwnsSpawn()), and AIWorld's own Needs -> Goal -> ActionRequest ->
//   ActionSystem -> TrinityCore pipeline may actually execute for this
//   agent.
enum class AgentControlMode : uint8
{
    ObserveOnly = 0,
    AIWorldControlled = 1
};

inline char const* ToString(AgentType type)
{
    switch (type)
    {
        case AgentType::Civilian:     return "CIVILIAN";
        case AgentType::Guard:        return "GUARD";
        case AgentType::Merchant:     return "MERCHANT";
        case AgentType::Unclassified: return "UNCLASSIFIED";
        case AgentType::Combatant:    return "COMBATANT";
        case AgentType::Predator:     return "PREDATOR";
        case AgentType::Prey:         return "PREY";
        default:                      return "UNKNOWN";
    }
}

inline char const* ToString(AgentControlMode mode)
{
    switch (mode)
    {
        case AgentControlMode::ObserveOnly:       return "OBSERVE_ONLY";
        case AgentControlMode::AIWorldControlled: return "AI_WORLD_CONTROLLED";
        default:                                  return "UNKNOWN";
    }
}

#endif // AIWORLD_AGENTTYPE_H
