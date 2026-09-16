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

#ifndef AIWORLD_COALITIONFORMATIONPROFILEID_H
#define AIWORLD_COALITIONFORMATIONPROFILEID_H

#include "Define.h"
#include "Faction/WorldFactionId.h"
#include <optional>

// Milestone 2.12E4R: which CoalitionFormationProfile a formation
// pass/attempt belongs to - identity only, never itself carried across the
// generic CoalitionFormationSystem/CoalitionCandidate/CoalitionProposal
// pipeline (those stay entirely unaware that "WolfLoose" is the only
// profile that exists today). Used to key AIWorldMgr's own per-profile
// in-flight tracking (see AIWorldMgr::_formationInFlight) and to name a
// formation attempt in logs. WolfLoose is the only real value that exists
// yet - see CoalitionFormationProfile.h for why adding a second profile
// (e.g. a future bandit or caravan formation) needs no change to
// CoalitionFormationSystem/AIWorldMgr's own orchestration methods, only a
// new CoalitionFormationProfile value and a new enumerator here.
//
// Milestone 2.12E4R P3 fix (STATIC review): Invalid = 0 is deliberately the
// first (default-constructed) value, not WolfLoose - an earlier version had
// WolfLoose as the only value at all, so both CoalitionFormationProfile::Id
// and CoalitionFormationAttempt::ProfileId's own default-member-initializers
// silently defaulted to WolfLoose. That is fail-OPEN: a future profile
// whose author forgot to set Id explicitly would not fail to compile or run
// - it would just quietly masquerade as WolfLoose and share its
// AIWorldMgr::_formationInFlight/_formationReservedMembers identity with
// the real WolfLoose profile. RunCoalitionFormation() now refuses Invalid
// outright (see its own comment) - see CoalitionFormationProfile.h for the
// matching default-member-initializer change.
//
// Milestone 2.12E4C2 P2 fix (STATIC review): every value below has an
// EXPLICIT numeric literal, and MUST keep it from here on - see
// AgentGroupRecord::ProfileId and ai_agent_groups.profile_id (migration
// 2026_08_28_00). Once a value is persisted to that column it is storage
// ABI, not just an in-process identity: an implicit, position-based
// enumerator value (the C++ default) would silently renumber every
// already-persisted profile_id the moment a new enumerator is inserted
// anywhere but the end, or an existing one is reordered/removed - e.g.
// inserting BanditLoose between Invalid and WolfLoose would make every
// already-persisted profile_id=1 (WolfLoose) read back as BanditLoose
// after the next restart, with no error, no migration, and no way to
// detect it happened. A new profile is always appended with its own
// explicit, never-before-used literal; an enumerator's own value, once
// shipped, is never changed or reassigned to a different profile, even if
// that profile is later removed (retire the enumerator, do not recycle its
// number).
// Milestone 2.12G1: DefiasLoose is the second real profile - genericity
// proof that CoalitionFormationSystem/CoalitionMaintenanceSystem/
// AgentGroupIntentSystem/AgentGroupIntentProjector/ActionSystem need no
// change at all to gain a second, unrelated coalition (see this enum's
// own header comment above and CoalitionFormationProfile.h for why). 2 is
// the correct next explicit literal - appended, never inserted before
// WolfLoose's own 1.
enum class CoalitionFormationProfileId : uint8
{
    Invalid     = 0,
    WolfLoose   = 1,
    DefiasLoose = 2
};

inline char const* ToString(CoalitionFormationProfileId id)
{
    switch (id)
    {
        case CoalitionFormationProfileId::Invalid:     return "INVALID";
        case CoalitionFormationProfileId::WolfLoose:   return "WOLF_LOOSE";
        case CoalitionFormationProfileId::DefiasLoose: return "DEFIAS_LOOSE";
        default:                                       return "UNKNOWN";
    }
}

// AI WorldFactionId (data/elwynn/factions/README.md) coalition/faction
// hardening: the one WorldFactionId every member of a group created by this
// profile must belong to - a fixed property of the profile's own identity,
// never a per-deployment config value (unlike CreatureEntry, which
// AIWorld.WolfGroupCreatureEntry/AIWorld.DefiasGroupCreatureEntry may point
// at any real creature_template - that creature_template's own
// WorldFactionCatalog affiliation is not itself configurable). The single
// source of truth for "WolfLoose means ELWYNN_WOLVES, DefiasLoose means
// DEFIAS_BROTHERHOOD" - read by AIWorldMgr::Initialize() when building
// CoalitionFormationProfile::RequiredWorldFaction,
// AgentGroupLifecycleSystem::RequestJoinGroup() when a joiner would become
// an empty group's first member (nothing yet to compare against), and
// AgentGroupPersistence::LoadGroupMembers() when validating a persisted
// group's every member on load - never three independently-maintained
// copies of the same fact.
//
// std::nullopt for Invalid (and any future/unknown value): Invalid means no
// automatic profile owns this group at all (see AgentGroupRecord::ProfileId's
// own comment) - a manual/admin-created group has no fixed WorldFaction
// requirement to check here, which is a different thing from "requires
// Unaffiliated" (WorldFactionId{0}). Callers must treat nullopt as "skip
// this check", never as a WorldFactionId{0} requirement.
inline std::optional<WorldFactionId> RequiredWorldFactionFor(CoalitionFormationProfileId id)
{
    switch (id)
    {
        case CoalitionFormationProfileId::WolfLoose:   return WorldFactions::ElwynnWolves;
        case CoalitionFormationProfileId::DefiasLoose: return WorldFactions::DefiasBrotherhood;
        case CoalitionFormationProfileId::Invalid:     return std::nullopt;
        default:                                       return std::nullopt;
    }
}

#endif // AIWORLD_COALITIONFORMATIONPROFILEID_H
