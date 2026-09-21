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

#ifndef AIWORLD_AIWORLDMGR_H
#define AIWORLD_AIWORLDMGR_H

#include "Action/ActionCompletion.h"
#include "Action/ActionEngineEventBus.h"
#include "Action/ActionExecutor.h"
#include "Action/ActionSystem.h"
#include "Action/PendingEatContinuation.h"
#include "Agent/AgentGroupCoordinationProfile.h"
#include "Agent/AgentGroupIntentProjector.h"
#include "Agent/AgentGroupIntentSystem.h"
#include "Agent/AgentGroupLifecycleSystem.h"
#include "Agent/AgentGroupOperationSource.h"
#include "Agent/AgentGroupPolicyConfig.h"
#include "Agent/AgentGroupPolicySystem.h"
#include "Agent/AgentGroupRegistry.h"
#include "Agent/AgentGroupSimulationSystem.h"
#include "Agent/AgentId.h"
#include "Agent/AgentRegistry.h"
#include "Agent/CoalitionCandidate.h"
#include "Agent/CoalitionFormationAttempt.h"
#include "Agent/CoalitionFormationProfile.h"
#include "Agent/CoalitionFormationReservationKey.h"
#include "Agent/CoalitionFormationSystem.h"
#include "Agent/CoalitionMaintenanceSystem.h"
#include "Agent/GroupId.h"
#include "Agent/GroupMemberActionProposal.h"
#include "Agent/HuntIntentProjector.h"
#include "Agent/HuntIntentSystem.h"
#include "Define.h"
#include "Event/EventBus.h"
#include "Event/WorldEvent.h"
#include "Agent/AgentTypeCatalog.h"
#include "Faction/PlayerWorldFactionPersistence.h"
#include "Faction/WorldFactionCatalog.h"
#include "Faction/WorldFactionRelationCatalog.h"
#include "Faction/WorldFactionReputationCatalog.h"
#include "Reconciliation/SpawnParticipationCatalog.h"
#include "Goal/FoodTargetResolver.h"
#include "Goal/GoalSystem.h"
#include "Goal/RoutineActivitySystem.h"
#include "Goal/RoutineSystem.h"
#include "Inference/AIClient.h"
#include "Inference/DynamicTaskAcceptance.h"
#include "Inference/DynamicTaskCandidate.h"
#include "Inference/DynamicTaskValidation.h"
#include "Memory/LongTermMemory.h"
#include "Memory/MemoryRetrieval.h"
#include "Memory/ShortTermMemory.h"
#include "Needs/NeedsSystem.h"
#include "Perception/PerceptionSystem.h"
#include "Persistence/AgentGroupPersistence.h"
#include "Persistence/AgentPersistence.h"
#include "Persistence/MemoryPersistence.h"
#include "Persistence/TransactionCallbackProcessor.h"
#include "Quest/DynamicQuestCreation.h"
#include "Quest/DynamicQuestIdAllocator.h"
#include "Quest/DynamicQuestKillEventBus.h"
#include "Quest/DynamicQuestLifecycle.h"
#include "Quest/DynamicQuestPlayerAcceptance.h"
#include "Quest/DynamicQuestPlayerCompletion.h"
#include "Quest/DynamicQuestRegistry.h"
#include "Scheduler/CoarseSimulationScheduler.h"
#include "Scheduler/DecisionScheduler.h"
#include "Scheduler/GroupCoarseSimulationScheduler.h"
#include "Scheduler/SimulationScheduleState.h"
#include "Scheduler/SimulationTier.h"
#include "Scheduler/StableAgentHash.h"
#include "Telemetry/TelemetryExporter.h"
#include <array>
#include <atomic>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Trinity::Asio { class IoContext; }
class Creature;
class Player;
class AIWorldCreatureAI;

// Entry point for the AIWorld subsystem. Driven from the world update thread
// only (called after sMapMgr->Update() in World::Update()) - never spawns its
// own thread and never mutates Creature/Map state itself. Milestone 2.13C4
// P2 fix (STATIC review): an earlier exception this comment used to document
// (a ReconcileDynamicQuestGossipFlag() method toggling UNIT_NPC_FLAG_GOSSIP
// directly here) was removed - that mutation, and the "did AIWorld itself
// add this flag" ownership bit it needs to stay safe, now live in
// AIWorldCreatureAI instead (see its own _ownsDynamicQuestGossipFlag
// comment). This class only ever answers the read-only question of whether
// that flag SHOULD be up (see HasLiveDynamicQuestStateForGiver()).
//
// Milestone 2.13C5 (STATIC review, documentation fix): a real, deliberate
// exception to "never mutates Player state" now exists -
// CompleteDynamicQuestForPlayer()/CompensateDynamicQuestReward() call
// Player::ModifyMoney() directly to pay (and, on a failed completion,
// revert) a dynamic quest's already-2.13B-validated RewardMoneyCopper. This
// is still the only Player-mutating path in the class, gated by the same
// full player/giver/lifecycle re-validation every other authority boundary
// here already requires, and every ModifyMoney() call's own result (and the
// resulting balance) is independently verified, never assumed - see those
// methods' own comments. Otherwise still fully inert unless
// AIWorld.Enable = 1.
class TC_GAME_API AIWorldMgr
{
    // Milestone 2.13C4 P1 fix (STATIC review): AIWorldCreatureAI is the
    // ONE external, non-world-thread-owning class this milestone's own
    // player-facing gossip/accept integration requires calling into
    // private world-thread-only methods (GetDynamicQuestGossipContent(),
    // AcceptDynamicQuestForPlayer(), GetCurrentTimeMs(), and the private
    // nested DynamicQuestGossipContent type itself) - without this,
    // AIWorldCreatureAI.cpp simply does not compile. Milestone 2.13C5
    // added CompleteDynamicQuestForPlayer() to that same list (the
    // turn-in counterpart to AcceptDynamicQuestForPlayer()) - no new
    // friend needed, the same grant already covers it. Every other class
    // in the codebase still goes through this class's public thread-safe
    // enqueue/query API only.
    friend class AIWorldCreatureAI;

    public:
        static AIWorldMgr* instance();

        void Initialize(Trinity::Asio::IoContext& ioContext);
        void Update(uint32 diff);
        void Shutdown();

        bool IsEnabled() const { return _enabled; }

        // Safe to call from ANY thread that can observe a game-world fact
        // (a map/combat worker, not just the world thread). Does nothing
        // but a relaxed-ish atomic check and a mutex-guarded enqueue - never
        // looks up a Creature/AgentRecord, never calls ai-server, never
        // mutates world state. See EventBus for the actual thread-safety
        // story.
        //
        // Milestone 2.13C6B1: returns whether the event was actually
        // enqueued - false either because _acceptEvents was false or
        // because the bounded/lossy EventBus itself was full
        // (EventBus::Publish() returns false rather than blocking or
        // growing unbounded). Existing call sites are free to keep
        // ignoring the return value (a dropped perception fact was
        // already an accepted, logged possibility before this milestone -
        // see EventBus's own comment); a caller that itself needs to know
        // (e.g. to log a dropped authoritative dynamic quest outcome) now
        // can.
        bool PublishWorldEvent(WorldEvent event);

        // Milestone 2.8A.5: consulted from FactorySelector::SelectAI()
        // (CreatureAISelector.cpp), ahead of pet/scripted/AIName/
        // Permissible-based AI selection, to decide whether a Creature
        // gets AIWorldCreatureAI instead of its normal default AI. Safe to
        // call from a map-updater thread during grid loading even though
        // AgentRegistry's mutating calls are world-thread-only:
        // MapManager::Update() (MapManager.cpp) blocks on m_updater.wait()
        // before returning, and AIWorldMgr::Update() (which is the only
        // thing that ever mutates _registry once Initialize() has run) is
        // called strictly after sMapMgr->Update() returns in World::Update()
        // - so no map-updater thread executing FactorySelector::SelectAI()
        // is ever concurrent with anything that mutates _registry.
        // Multiple map-updater threads calling this concurrently with each
        // other, for different maps, is fine too: this and everything it
        // calls (AgentRegistry::FindBySpawn() const) are read-only. Never
        // touches Creature/Map, never calls ai-server.
        //
        // Milestone 2.12F4A: true only for AgentControlMode::AIWorldControlled
        // - an AgentRecord existing is no longer sufficient by itself (see
        // AgentControlMode's own comment, AgentType.h). An ObserveOnly
        // agent falls through to TrinityCore's normal AI selection exactly
        // as if it had no AgentRecord at all - the read stays safe from a
        // map-updater thread since ControlMode is only ever set at load
        // time in this milestone, never mutated concurrently with it.
        bool OwnsSpawn(uint32 mapId, uint64 spawnId) const;

        // Login/allegiance-change ReputationMgr bridge (AIWorld_Current_
        // Roadmap.md, 2026-09-21 architectural audit) - read-only accessors
        // to catalogs that were already private members with no consumer.
        // Both are startup-loaded, read-only for the rest of this process's
        // lifetime (see each catalog's own Load() comment), so returning a
        // const reference is safe to call from anywhere that already holds
        // a valid AIWorldMgr instance, including Player::LoadFromDB() (the
        // world thread, during login) and a GM command callback.
        WorldFactionRelationCatalog const& GetWorldFactionRelationCatalog() const { return _worldFactionRelationCatalog; }
        WorldFactionReputationCatalog const& GetWorldFactionReputationCatalog() const { return _worldFactionReputationCatalog; }

        // AI 3.4 runtime coalition gate debug tooling (AIWorld_Current_
        // Roadmap.md, "Coalition pravidla uvnitr frakci") - read-only
        // lookups plus the first EXTERNAL (GM command) caller of
        // RequestJoinGroupWithPolicy()/RequestLeaveGroupWithPolicy() below,
        // both otherwise-private and reachable only from AIWorldMgr's own
        // internal callers (the manual smoke test) today. See
        // cs_aiworld_group.cpp for the actual command surface built on top
        // of these - this class exposes nothing about group lifecycle
        // mutation beyond the two Manual-only wrappers below.

        // Resolves a live Creature's own (map, spawnId) binding to its
        // AgentId via AgentRegistry::FindBySpawn() - AgentId{} (0) if this
        // creature has no registered AgentRecord at all. Read-only, safe
        // to call from the world thread (a GM command handler).
        AgentId FindAgentIdForCreature(Creature const& creature) const;

        // WorldFactionId of a registered agent, or WorldFactions::
        // Unaffiliated for an unknown/never-registered AgentId - see
        // AgentRecord::WorldFaction.
        WorldFactionId GetAgentWorldFaction(AgentId id) const;

        // Every GroupId this agent currently belongs to - see
        // AgentGroupRegistry::GetGroupsOfMember() (almost always 0 or 1,
        // never assumed to be at most 1).
        std::vector<GroupId> GetGroupsOfAgent(AgentId id) const;

        // Read-only identity snapshot of one group - Kind/ProfileId/that
        // profile's own RequiredWorldFactionFor()/live member count - or
        // std::nullopt for an unknown GroupId. See AgentGroupRegistry::Find().
        struct GroupDebugInfo
        {
            AgentGroupKind Kind = AgentGroupKind::Loose;
            CoalitionFormationProfileId ProfileId = CoalitionFormationProfileId::Invalid;
            std::optional<WorldFactionId> RequiredWorldFaction;
            std::size_t MemberCount = 0;
        };
        std::optional<GroupDebugInfo> DescribeGroup(GroupId id) const;

        // On-demand, read-only WolfLoose diagnostic. A proposal is a snapshot,
        // not a promise that the next async formation pass will admit this agent.
        struct WolfFormationDebugInfo
        {
            AgentControlMode ControlMode = AgentControlMode::ObserveOnly;
            uint32 ExpectedEntry = 0;
            uint32 MinMembers = 0;
            float FormationRadius = 0.0f;
            float Hunger = 0.0f;
            bool LivingEnabled = false;
            std::optional<uint32> NearbyEligibleIncludingSelf;
            char const* Goal = "NONE";
            char const* Action = "NONE";
            char const* FormationState = "UNKNOWN";
        };
        std::optional<WolfFormationDebugInfo> DescribeWolfFormation(Creature const& creature) const;

        // Thin Manual-only wrappers around the otherwise-private
        // RequestJoinGroupWithPolicy()/RequestLeaveGroupWithPolicy() below -
        // AgentGroupOperationSource::Manual is baked in here rather than
        // exposed as a caller-supplied parameter, so a debug command can
        // never accidentally drive these as AutomaticPolicy (see
        // AgentGroupOperationSource.h's own comment - Manual is exactly
        // "an admin/test command", the case this method exists for). Same
        // (success, decision) contract as RequestJoinGroupWithPolicy()/
        // RequestLeaveGroupWithPolicy() themselves.
        void RequestManualJoinGroup(GroupId groupId, AgentId memberId, std::function<void(bool success, AgentGroupPolicyDecision decision)> onComplete);
        void RequestManualLeaveGroup(GroupId groupId, AgentId memberId, std::function<void(bool success, AgentGroupPolicyDecision decision)> onComplete);

        // Milestone 2.8F: safe to call from ANY thread TrinityCore itself
        // calls AIWorldCreatureAI::MovementInform() from (a map-updater
        // thread during Map::Update(), not necessarily the world thread).
        // Same enqueue-only contract as PublishWorldEvent(): never touches
        // Creature/AgentRegistry, never calls ai-server, never mutates
        // world state. See ActionEngineEventBus for the thread-safety
        // story.
        void PublishActionEngineEvent(ActionEngineEvent event);

        // Milestone 2.13C4 P2 fix (STATIC review): safe to call from ANY
        // thread that can observe a real kill (a map/combat worker, the
        // same context Unit::Kill() itself runs in) - same enqueue-only
        // contract as PublishWorldEvent()/PublishActionEngineEvent():
        // never touches Creature/AgentRegistry/DynamicQuestRegistry,
        // never calls ai-server, never mutates world state. Exists as its
        // own bus, separate from PublishWorldEvent()'s shared perception/
        // memory EventBus, specifically so authoritative dynamic-quest
        // kill credit never has to compete for capacity with (or get
        // dropped alongside) unrelated perception traffic - see
        // DynamicQuestKillEventBus's own comment for the full reasoning.
        // Unit::Kill() calls this only for a player killer; see that call
        // site's own comment.
        void PublishDynamicQuestKillEvent(DynamicQuestKillEvent event);

    private:
        AIWorldMgr() = default;
        ~AIWorldMgr() = default;
        AIWorldMgr(AIWorldMgr const&) = delete;
        AIWorldMgr& operator=(AIWorldMgr const&) = delete;

        std::optional<AIRequest> ProcessAgent(AgentId id);
        AIRequest CaptureAgentContext(AgentId id, AgentRecord& record, Creature& creature);
        // Milestone 2.13C6C: beyond the normal per-agent Sight loop, gives
        // a dynamic quest outcome event's own issuer (event.Target.Agent)
        // exactly one directed/Rumor fallback Observation via
        // PerceptionSystem::ObserveDirectedEvent() when Sight itself did
        // not already deliver one - see that method's own comment and
        // this one's definition comment for the full reasoning. Every
        // other WorldEventType is unaffected.
        void ProcessWorldEvent(WorldEvent& event);
        void ProcessObservation(Observation const& observation);
        void ScanNearbyEntities();
        void UpdateNeeds(uint32 elapsedMs);
        void CaptureTelemetry();
        void ProcessActionEngineEvent(ActionEngineEvent const& event);
        void HandleActionCompletion(AgentRecord& record, ActionCompletion const& completion);
        void TryEat(AgentRecord& record, Creature& creature, PendingEatContinuation const& pending, uint64 nowMs);

        // Milestone 2.11E2 P3 fix: a convenience for the common "apply one
        // mutation, then persist" shape every economy change so far has
        // (see UpdateNeeds()'s WORK reward block) - not itself the source
        // of the Version-bump guarantee. That guarantee now lives in
        // AgentPersistence::SaveEconomyState() itself (it increments
        // Version unconditionally, first thing, regardless of caller) -
        // see its own comment for why a convention at this layer alone was
        // not enough: anyone could still call SaveEconomyState() directly
        // and bypass this method entirely.
        void MutateEconomyAndPersist(AgentRecord& record, std::function<void(AgentEconomyState&)> const& mutate);
        void ValidateDecisionIntent(AgentId id, AgentRecord const& record, AIResponse const& response);
        std::vector<DecisionSubmitResult> SubmitDecisionContexts(std::vector<AIRequest> requests);
        void RunDecisionScheduler();
        bool UpdateSimulationTier(AgentId id, SimulationTier tier);

        // Milestone 2.13A3B: builds a /dynamic-task request from real,
        // already-observed state only - never a synthetic/test-authored
        // QuestContext. sourceMemory must be a real, still-fresh
        // WorldEvent short-term memory owned by this exact agent (see the
        // .cpp for the full eligibility checks); record/creature must be
        // a live, AIWorldControlled, alive incarnation. Returns nullopt on
        // any ineligibility - never a partially-built request. Candidate
        // targets come only from this agent's own active CreatureSeen
        // memories, each live-re-resolved and re-validated (never a fresh
        // spatial scan, never a stored pointer) before it can become a
        // model-visible QuestTargetCandidate/QuestTargetBinding pair -
        // see QuestContext.h/QuestRequestProvenance.h for why the model
        // only ever sees the opaque token, never the ObjectGuid. Also
        // returns nullopt (review follow-up) if that scan finds zero
        // eligible candidates - the only supported objective is
        // KILL_CREATURE, so a request with an empty CandidateTargets
        // could never receive a response any target_token in it could
        // legally answer. This check runs, and the request is rejected,
        // BEFORE record.SnapshotSequence is bumped - a doomed request
        // never consumes a fresh snapshot value for nothing.
        std::optional<AIRequest> BuildDynamicTaskRequest(AgentRecord& record, Creature& creature, MemoryRecord const& sourceMemory, uint64 nowMs);

        // Milestone 2.13A3B: the one production entry point for actually
        // submitting a dynamic-task request. Fails closed (returns false,
        // submits nothing) if the feature is disabled, this agent already
        // has a pending request (at most one in flight per agent - the
        // map itself is the duplicate guard), the global
        // AIWorld.DynamicTaskMaxInFlight cap is already reached (AIClient
        // enforces its own independent copy of this bound too - defense
        // in depth), or BuildDynamicTaskRequest() itself returns nullopt.
        // Records the pending request (context/provenance actually sent,
        // never re-derived later) only once AIClient::SubmitDynamicTask()
        // has returned a nonzero request id.
        bool TrySubmitDynamicTask(AgentRecord& record, Creature& creature, MemoryRecord const& sourceMemory);

        // Milestone 2.13A3B: the terminal handler for every
        // AIRequestType::DynamicTask response TryPopResponse() delivers -
        // see Update()'s own response-drain loop. Looks up the pending
        // request for response.Agent; a response naming a different
        // RequestId than that pending entry is a stale/foreign response
        // and is discarded WITHOUT touching the current pending entry
        // (see DynamicTaskResponseMatchesPending()'s own comment for why
        // this must gate erasure, not just be checked after it) - only a
        // matching RequestId ever consumes/erases the pending entry.
        // Every acceptance check afterward runs against that erased
        // pending's own Context/Provenance, never against anything the
        // response itself claims about Agent/SnapshotSequence (AIClient
        // already proved those match at the envelope level, but world-
        // thread acceptance stands on its own captured pending request,
        // exactly like /decision's ValidateDecisionIntent()). Produces at
        // most one DynamicTaskCandidate, handed to
        // OnDynamicTaskCandidateAccepted() - never anything else.
        void HandleDynamicTaskResponse(AIResponse const& response);

        // Milestone 2.13B: the authoritative validation seam for a
        // DynamicTaskCandidate that already passed 2.13A3B's own
        // provenance/staleness/target-binding acceptance. This is a NEW
        // security boundary, not a continuation of that trust - but it
        // does not re-resolve the giver/target a second time itself
        // (nothing could have changed in the same synchronous call
        // stack); instead `facts` is the caller's own fresh live
        // re-derivation, from HandleDynamicTaskResponse()'s own
        // resolution, of exactly what a static candidate/provenance
        // snapshot cannot supply by itself - see
        // DynamicTaskAuthoritativeFacts' own comment. Judges candidate
        // and facts with the pure ValidateDynamicTaskCandidate() against
        // the server's CURRENT policy limits (never
        // candidate.RequestContext.Limits, which is only a snapshot of
        // policy as of request-build time). Still no ActionRequest, no
        // ActionSystem::Validate()/ActionExecutor call, no Player/Quest/DB
        // touch, no reward, no world mutation of any kind - this
        // milestone only decides VALIDATED vs REJECTED and logs which.
        // Milestone 2.13C2: on VALIDATED, the resulting QuestProposal is
        // no longer unconditionally discarded - it is handed to
        // CreateDynamicQuestOffer() for its own separate, independent
        // applicability boundary (a validated proposal is still not
        // gameplay authorization - see QuestProposal's own comment).
        void OnDynamicTaskCandidateAccepted(DynamicTaskCandidate const& candidate, DynamicTaskAuthoritativeFacts const& facts);

        // Milestone 2.13C2: the sole authority for minting a
        // DynamicQuestId - a thin wrapper around the pure, independently
        // testable AdvanceDynamicQuestIdCounter() over this instance's
        // own _nextDynamicQuestId. Returns DynamicQuestId{} (0) once the
        // process-lifetime uint64 counter is exhausted - see that
        // function's own comment for why 0 is never reused as a valid id.
        DynamicQuestId AllocateDynamicQuestId();

        // Milestone 2.13C2: the ONLY place a validated QuestProposal
        // (2.13B's own output) may become a real, registry-owned Offered
        // DynamicQuestInstance. A validated proposal is not gameplay
        // authorization by itself (see QuestProposal's own comment) - the
        // world may have moved on since 2.13B ran, so this re-resolves
        // giver and target fresh from live world state (never trusting
        // anything the proposal itself claims) and judges the result with
        // the pure CheckDynamicQuestCreateApplicability(). In order:
        // RegistryFull (AIWorld.DynamicQuestMaxLive, checked first so a
        // full registry fails fast before paying for any live
        // resolution) -> applicability -> AllocateDynamicQuestId() ->
        // DynamicQuestRegistry::Offer(), which is itself the only way a
        // NEW instance may enter the registry (see its own comment) - id
        // allocation only happens once applicability is already proven,
        // and Offer() only touches the registry once OfferDynamicQuest()
        // itself has already succeeded internally. On any failure at any
        // step, nothing is created: no id is consumed (except in the
        // applicability-already-proven case where Offer() itself rejects
        // - see DynamicQuestCreateReason::OfferRejected's own comment for
        // why that should be unreachable in practice), and the registry
        // is left completely untouched. Still no ActionRequest, no
        // ActionSystem/ActionExecutor, no Player/Quest/DB, no reward, no
        // world mutation - this only ever creates an inert, server-only
        // Offered lifecycle instance.
        //
        // Milestone 2.13C6B2: also captures a server-owned
        // GiverLocationAtOffer snapshot from the live giverCreature right
        // after applicability confirms it, and passes it into
        // DynamicQuestRegistry::Offer() - see DynamicQuestInstance's own
        // comment for why a later terminal Expired/Failed outcome needs
        // this fallback.
        DynamicQuestCreateResult CreateDynamicQuestOffer(QuestProposal const& proposal, uint64 nowMs);

        // Milestone 2.13C2 P2 fix (STATIC review): keeps _dynamicQuestRegistry
        // bounded. Nothing in 2.13C2 itself ever removes an Offered
        // instance nobody accepts before its own ExpiresAtMs - without
        // this, the registry would grow forever under repeated
        // submission. Runs on its own AIWorld.DynamicQuestMaintenanceIntervalMs
        // timer, examining up to AIWorld.DynamicQuestMaintenanceScanMaxPerPass
        // ids per pass via the same bounded, cursor-resumable, snapshot-
        // bounded scan-cycle shape RunCoalitionMaintenance() already
        // established (_dynamicQuestMaintenanceCursor/
        // _dynamicQuestMaintenanceCycleHighWater - see that method's own
        // comment for why a plain unbounded cursor would let continuous
        // quest creation starve the earliest-created entries forever).
        // For each discovered id still in a non-terminal state
        // (Offered/Active) whose deadline has passed
        // (IsDynamicQuestExpired()), transitions it to Expired via
        // DynamicQuestRegistry::Expire() (never the pure
        // ExpireDynamicQuest() directly - see that class's own comment
        // for why only its own mutation entry points may ever produce a
        // transition committed against its stored state) and then
        // removes it from the registry - once Expired, 2.13C2 itself has
        // no further use for it (no player was ever bound to an Offered
        // instance nobody accepted; an Active one that already expired
        // is equally done).
        // Completed/Failed instances are left alone here: their lifecycle
        // and reclamation are owned by their respective authoritative
        // paths, not expiry maintenance.
        //
        // Milestone 2.13C6B2: once DynamicQuestRegistry::Expire() above
        // actually succeeds, publishes the terminal outcome WorldEvent
        // built from *expireResult.Instance (the registry's own
        // just-committed value) before Remove() runs. Location is
        // live-current-or-offer-fallback: the giver may no longer be
        // materialized at expiry, so this starts from
        // DynamicQuestInstance::GiverLocationAtOffer and only overrides
        // it with a freshly re-resolved live position when that
        // resolution's GUID still matches GiverRuntimeGuid (never
        // attributing a despawned-and-respawned giver's new incarnation
        // to the old instance's outcome). A publish failure (EventBus is
        // bounded/lossy) never blocks or reverts the Expired transition,
        // already authoritative by that point; only
        // DYNAMIC_QUEST_OUTCOME_EVENT_DROPPED is logged.
        void RunDynamicQuestMaintenance(uint64 nowMs);

        // Milestone 2.13C3: the ONLY place a player's request to accept a
        // registry-owned Offered dynamic quest may turn into a real
        // Offered->Active transition. Deliberately does NOT touch the
        // standard TrinityCore quest log - see this milestone's own
        // roadmap note for why a dynamic quest cannot yet go through
        // Player::CanTakeQuest()/CanAddQuest()/AddQuestAndCheckCompletion()
        // (those require a real Quest const* from ObjectMgr, which needs
        // a dynamic QuestTemplate and client-facing uint32 QuestId this
        // milestone does not attempt to solve). Fresh re-resolves BOTH
        // sides from live world state (never a cached/stored Player*/
        // Creature*): the player via ObjectAccessor::FindPlayer() (real
        // player identity, online, alive) and the giver via AgentRecord/
        // Creature* (still exists, same runtime incarnation, still
        // Materialized/AIWorldControlled/alive) - then requires player
        // and giver to share a map and be within
        // AIWorld.DynamicQuestPlayerAcceptMaxRangeYards of each other, so
        // a quest can never be accepted from across the map. Only once
        // CheckDynamicQuestPlayerAcceptApplicability() returns None does
        // it call the existing DynamicQuestRegistry::Accept(id,
        // playerGuid, nowMs), which is itself still the sole authority
        // over whether the stored instance's own State/expiry actually
        // permit the transition (this method never re-checks or
        // duplicates that). Logs DYNAMIC_QUEST_ACCEPTED (never a GUID) or
        // a typed reject reason, and (Milestone 2.13C4) sends the
        // accepting player a confirmation chat message using the
        // instance's own already-2.13B-validated Title. This is the ONLY
        // mutation entry point regardless of caller - 2.13C4's own
        // AIWorldCreatureAI::OnGossipSelect() calls this exact method,
        // never anything else. Still no Player::AddQuest, no standard
        // quest log/marker, no client quest packet, no DB persistence -
        // kill credit (2.13C4's own ProcessDynamicQuestKillProgress()) and
        // completion/reward (2.13C5's own CompleteDynamicQuestForPlayer())
        // are handled by their own separate methods, never folded into
        // this one. AcceptedByPlayerGuid exists only inside this
        // process's own in-memory DynamicQuestRegistry.
        DynamicQuestPlayerAcceptResult AcceptDynamicQuestForPlayer(DynamicQuestId id, ObjectGuid playerGuid, uint64 nowMs);

        // Milestone 2.13C5: the ONLY place a player's request to turn in
        // a registry-owned Active, objective-complete dynamic quest may
        // turn into a real Active->Completed transition plus a paid
        // reward - the player-facing counterpart to
        // AcceptDynamicQuestForPlayer() above, against a completely
        // different quest state. Fresh re-resolves BOTH sides from live
        // world state exactly like that method does (never a cached/
        // stored Player*/Creature*), reusing the SAME
        // AIWorld.DynamicQuestPlayerAcceptMaxRangeYards policy value -
        // interaction range is one physical concept regardless of which
        // action the player is performing against this giver, so this
        // deliberately does not introduce a second, separately-configured
        // range for turn-in specifically. Only once
        // CheckDynamicQuestPlayerCompleteApplicability() returns None
        // does this even attempt Player::ModifyMoney() for
        // instance->RewardMoneyCopper (never ignoring its own bool
        // return - see this method's own definition comment for the
        // preflight-then-compensate ordering), followed by the existing
        // DynamicQuestRegistry::Complete(id, nowMs), which is itself
        // still the sole authority over whether the stored instance's
        // own State/expiry/progress actually permit the transition - this
        // method never commits that transition itself, but
        // CheckDynamicQuestPlayerCompleteApplicability() (and, as defense
        // in depth, a second non-committing CompleteDynamicQuest()
        // preflight below) deliberately re-checks State/expiry/progress
        // ahead of time too, specifically so a rejection is never
        // discovered only after Player::ModifyMoney() has already moved
        // real money (see that preflight's own comment for why a
        // compensated mutation is not equivalent to "never happened").
        // Removes the instance from the registry immediately once
        // Completed - a terminal instance is never meant to linger (see
        // DynamicQuestRegistry::Remove()'s own comment), and this doubles
        // as the simplest possible in-process replay guard: a second
        // turn-in attempt against the same id finds QuestNotFound above,
        // never a second payout. Logs DYNAMIC_QUEST_COMPLETED/
        // DYNAMIC_QUEST_COMPLETE_REJECTED (never a GUID) and sends the
        // player two confirmation chat messages on success. Still no
        // Player::AddQuest, no standard quest log/marker, no client quest
        // packet, no group/party credit, no DB persistence, no restart/
        // crash recovery - this is the same in-process-only boundary
        // AcceptDynamicQuestForPlayer() already established, just for the
        // opposite end of the lifecycle.
        //
        // Milestone 2.13C5 P3 fix (STATIC review, advisory): every
        // rejection path that can be reached with a resolved live player
        // also sends one FormatDynamicQuestCompleteRejectedMessage() chat
        // line (a single generic message, plus one specific wording for
        // RewardMoneyLimit - see that function's own comment for why the
        // full typed reason is never surfaced to the player, only logged)
        // - previously a rejected "Turn in" click closed the gossip
        // window with no feedback at all.
        //
        // Milestone 2.13C6B1: once DynamicQuestRegistry::Complete()
        // above actually succeeds, publishes the terminal outcome
        // WorldEvent built by BuildDynamicQuestOutcomeWorldEvent() from
        // *completeResult.Instance (the registry's own just-committed
        // value, never the earlier preflight instance) and a validated
        // turn-in location captured before reward callbacks - before
        // Remove() runs. Milestone 2.13C6B1 P2 fix (STATIC review): that
        // location is captured right after applicability confirms a live
        // giver, NOT re-read from giverCreature after
        // Player::ModifyMoney() - ModifyMoney() synchronously calls
        // sScriptMgr->OnPlayerMoneyChanged() before its own mutation, and
        // that hook can run arbitrary registered PlayerScript code, so
        // giverCreature's position is no longer authoritatively known to
        // still be valid once that call has happened. A publish failure
        // (EventBus is bounded/lossy) never rolls back the reward or the
        // Completed transition, both already authoritative by that
        // point; only DYNAMIC_QUEST_OUTCOME_EVENT_DROPPED is logged.
        // Expired outcomes publish from RunDynamicQuestMaintenance(),
        // Failed ones from ReclaimDynamicQuestsAfterKillCreditLoss() and
        // CompensateDynamicQuestReward() - all three share the same
        // PublishDynamicQuestOutcome() helper (see its own comment).
        DynamicQuestPlayerCompleteResult CompleteDynamicQuestForPlayer(DynamicQuestId id, ObjectGuid playerGuid, uint64 nowMs);

        // Milestone 2.13C5 P1 fix (STATIC review, round 3): the shared
        // "an incorrectly-applied dynamic quest reward must be reverted,
        // and verified, not just attempted" logic
        // CompleteDynamicQuestForPlayer() needs at two separate points
        // (the forward grant's own postcondition check, and the
        // Complete()-rejection fallback). Reverts by the real observed
        // balance delta (player->GetMoney() - moneyBeforeReward), never
        // an assumed fixed amount, then verifies both ModifyMoney()'s own
        // bool return AND that the balance actually landed back on
        // moneyBeforeReward. If either check fails, the instance is made
        // immediately non-replayable via
        // DynamicQuestRegistry::TerminateForReplayContainment(id, nowMs)
        // (Milestone 2.13C5 P3 fix, round 4: that Fail()-then-
        // unconditional-Remove() sequence now lives as its own pure,
        // registry-only, directly Catch2-tested primitive - see its own
        // comment for why preventing a repeat money mutation matters more
        // at that point than a clean terminal-state transition). Logs
        // DYNAMIC_QUEST_REWARD_COMPENSATION_FAILED at FATAL only in that
        // failure case. Returns true if the player's balance is
        // confirmed back at moneyBeforeReward (instance untouched);
        // false if the instance was just Fail()ed/Remove()d instead (the
        // caller must report DynamicQuestPlayerCompleteReason::
        // RewardApplicationFailed and stop, never fall through to acting
        // on this id again).
        //
        // Milestone 2.13C6B3: on that failure path, once
        // DynamicQuestRegistry::TerminateForReplayContainment() returns,
        // publishes a DynamicQuestFailed outcome via
        // PublishDynamicQuestOutcome() if and only if its FailedInstance
        // is set (Fail() itself actually succeeded) - AFTER Remove() has
        // already run internally, since replay-containment's own removal
        // is the safety priority here, never gated on publication.
        bool CompensateDynamicQuestReward(DynamicQuestId id, uint64 nowMs, Player* player, uint32 moneyBeforeReward);

        // Milestone 2.13C6B3: the single shared "build and publish one
        // terminal dynamic quest outcome WorldEvent" helper every C6B
        // publication call site (Completed/Expired/Failed) now goes
        // through, replacing three near-identical inline blocks.
        // BuildDynamicQuestOutcomeWorldEvent() only ever returns nullopt
        // for a non-terminal instance.State - reaching this method with
        // one would itself be a caller bug (every call site only ever
        // passes an instance a registry transition just committed as
        // terminal), so that case is logged as
        // DYNAMIC_QUEST_OUTCOME_EVENT_BUILD_REJECTED rather than silently
        // ignored. A publish failure (EventBus is bounded/lossy) only
        // logs DYNAMIC_QUEST_OUTCOME_EVENT_DROPPED - the caller's own
        // lifecycle transition is already authoritative and committed by
        // the time this runs, regardless of whether this downstream fact
        // is ever delivered.
        void PublishDynamicQuestOutcome(DynamicQuestInstance const& instance, WorldEventLocation const& location);

        // Milestone 2.13C6B3: the single shared live-current-or-offer-
        // fallback location resolution C6B2's own Expired path already
        // established, pulled out so C6B3's Failed path (two separate
        // production call sites) does not have to duplicate it. Starts
        // from instance.GiverLocationAtOffer (the server-owned snapshot
        // captured at Offer() time - see its own comment), then tries to
        // improve on it with a freshly re-resolved live giver position
        // ONLY if that resolution's GUID still matches
        // instance.GiverRuntimeGuid - a despawned-and-respawned giver
        // under the same AgentId must never have this outcome's location
        // attributed to the NEW incarnation's position. Never force-loads
        // a map/grid, never unbinds anything on a failed resolve - just
        // keeps the fallback. Deliberately NOT used by
        // CompleteDynamicQuestForPlayer()'s own completionLocation, which
        // stays its own pre-reward-mutation live snapshot (see that
        // method's own comment for why re-reading the giver that late is
        // unsafe) - Completed always has a definitely-live giver at that
        // point, so there is nothing this fallback would add there.
        WorldEventLocation ResolveDynamicQuestOutcomeLocation(DynamicQuestInstance const& instance);

        // Milestone 2.13C4: read-only gossip-UI query -
        // AIWorldCreatureAI::OnGossipHello() calls this to decide what (if
        // anything) to show a specific player at a specific giver
        // Creature. Resolves the giver's AgentId fresh from
        // (MapId, SpawnId) - never touches AcceptedByPlayerGuid/State
        // itself, only reads whatever DynamicQuestRegistry already
        // stores. Checks Kind::Active for THIS player first, Kind::Offered
        // second: once a player has accepted, revisiting the giver must
        // keep showing their own progress (2.13C4's own "gossip stays
        // useful after accept" requirement), never regress to a fresh
        // Offered instance the same giver might otherwise have created in
        // the meantime. Either an Offered or an Active instance whose
        // deadline has already passed (RunDynamicQuestMaintenance() has
        // not reclaimed it yet - see that method's own comment, it treats
        // both states as expirable) is treated as Kind::NoQuest rather
        // than shown stale.
        //
        // Milestone 2.13C5: Kind::ReadyToTurnIn is a strictly more
        // specific version of what used to always be Kind::Active once
        // Progress >= RequiredCount - AIWorldCreatureAI::OnGossipHello()
        // uses this distinction to show a "Turn in" row instead of a bare
        // progress line, and OnGossipSelect() uses it (re-derived fresh,
        // never trusted from an earlier query) to decide whether a click
        // may even attempt AIWorldMgr::CompleteDynamicQuestForPlayer().
        //
        // Milestone 2.13C6D: Kind::RecentOutcome is checked only once
        // neither a live Active/ReadyToTurnIn nor a live Offered instance
        // exists for this giver - its source is exclusively the giver's
        // own ShortTermMemory (via SelectDynamicQuestOutcomeReaction(),
        // see Quest/DynamicQuestOutcomeReaction.h), NEVER
        // DynamicQuestRegistry, which has already Remove()d the terminal
        // instance by the time this could ever be reached (Complete()/
        // Expire()/Fail() each remove their own instance - see their own
        // callers' comments). This is the visible-issuer-impact half of
        // the causal loop the roadmap's 2.13C6 section requires: the
        // giver's own memory of its quest's outcome, surfaced to any
        // player who opens this giver's gossip while that outcome memory
        // is still active - not exclusively the player who was part of
        // it, and never re-checked against AcceptedByPlayerGuid (that
        // identity no longer exists once the terminal instance is
        // Remove()d). No DynamicQuestId/Title/Description to show (the
        // terminal instance no longer exists to provide them) - only
        // OutcomeType/SourceEventId/OutcomeChannel/GiverAgent, the fields
        // FormatDynamicQuestOutcomeReaction() and the
        // DYNAMIC_QUEST_OUTCOME_REACTION_SHOWN log line need.
        struct DynamicQuestGossipContent
        {
            enum class ContentKind : uint8 { NoQuest, Offered, Active, ReadyToTurnIn, RecentOutcome };

            ContentKind Kind = ContentKind::NoQuest;
            DynamicQuestId Id;
            std::string Title;
            std::string Description;
            uint32 Progress = 0;
            uint32 RequiredCount = 0;

            // Only meaningful for Kind::RecentOutcome.
            WorldEventType OutcomeType = WorldEventType::DynamicQuestCompleted;
            uint64 SourceEventId = 0;
            PerceptionChannel OutcomeChannel = PerceptionChannel::Sight;
            AgentId GiverAgent;
        };
        DynamicQuestGossipContent GetDynamicQuestGossipContent(Creature* giverCreature, Player const* player);

        // Milestone 2.13C4 P2 fix (STATIC review): pure read-only decision
        // query - does giverCreature's CURRENT incarnation currently have
        // ANY live, not-yet-expired Offered/Active dynamic quest state at
        // all, regardless of which player (if any) has accepted it? Never
        // touches UNIT_NPC_FLAG_GOSSIP or any other Creature field itself
        // - AIWorldCreatureAI::UpdateAI() calls this on its own throttle
        // and owns the actual flag add/remove plus "did I add this"
        // bookkeeping itself (see its own _ownsDynamicQuestGossipFlag
        // comment for why that ownership bit cannot live here: this class
        // has no per-Creature state to persist it in across ticks, and a
        // stateless "native flag absent -> safe to remove" rule cannot
        // tell AIWorld's own earlier addition apart from something else
        // entirely setting the flag at runtime).
        bool HasLiveDynamicQuestStateForGiver(Creature* giverCreature);

        // Milestone 2.13C6D: the gossip-flag query AIWorldCreatureAI's own
        // ReconcileDynamicQuestGossipFlag() actually calls now - broader
        // than HasLiveDynamicQuestStateForGiver() above, which this method
        // does NOT replace or redefine (a caller that specifically needs
        // "is there a live Offered/Active instance" still has that exact
        // query available, unchanged). Returns true if EITHER
        // HasLiveDynamicQuestStateForGiver() is true, OR
        // SelectDynamicQuestOutcomeReaction() finds a still-active
        // (ShortTermMemory TTL, ~60s default) dynamic quest outcome
        // memory for this giver's AgentId. This keeps the gossip flag up
        // long enough for a player to see a RecentOutcome reaction after
        // Expired/Failed removed the terminal instance from
        // DynamicQuestRegistry - without this, ReconcileDynamicQuestGossipFlag()
        // would tear the flag down the instant the instance is Remove()d,
        // even though GetDynamicQuestGossipContent() can still produce a
        // Kind::RecentOutcome for a few more seconds.
        //
        // C6D intentionally accepts the bounded copy performed by
        // GetActiveForAgent() for this ~1 Hz player-facing probe. An
        // allocation-free outcome-presence index is deferred to
        // world-scale/performance hardening.
        bool HasDynamicQuestGossipContentForGiver(Creature* giverCreature);

        // Milestone 2.13C4: the ONLY authoritative direct-killer
        // KILL_CREATURE progress hook.
        //
        // Milestone 2.13C4 P2 fix (STATIC review): drained from
        // _dynamicQuestKillEventBus, NOT from the shared perception/memory
        // EventBus ProcessWorldEvent() drains - the earlier version reused
        // that shared, drop-under-overload bus for this, which meant
        // authoritative quest credit could silently vanish under the same
        // conditions that are an acceptable tradeoff for perception/memory
        // (see PublishDynamicQuestKillEvent()'s own comment for the full
        // reasoning). Uses event.EventId (unique within
        // DynamicQuestKillEventBus - see that class's own comment) as the
        // replay-guard identity DynamicQuestRegistry::ApplyProgress()
        // requires. On success, sends the killer a progress chat message,
        // and (once Progress == RequiredCount) a separate objective-
        // complete message naming the giver's live display name if it can
        // still be re-resolved. Direct-killer credit only in this
        // milestone - no group/party credit sharing (that is explicitly
        // deferred, see the roadmap's own note); a kill by anyone other
        // than the quest's own AcceptedByPlayerGuid contributes no
        // progress. Still independently re-checks event.KillerGuid.
        // IsPlayer() even though Unit::Kill() itself only ever publishes
        // to this bus for a player killer - never trust an upstream
        // publisher's own filtering as this class's only guarantee.
        //
        // Milestone 2.13C4 P2 fix (STATIC review, round 3): matches via
        // DynamicQuestRegistry::FindActiveByPlayerAndVictimEntry()
        // (event.VictimEntry + event.MapId), not the exact runtime
        // VictimGuid the earlier version used - see that method's own
        // comment for why an exact-spawn match cannot generally satisfy
        // RequiredCount > 1 (the same spawn is not guaranteed to respawn
        // at all, let alone enough times before the quest's own
        // ExpiryMs). "3 wolves" now means 3 wolves of the model's chosen
        // TargetEntry, on the same TargetMapId, not the same runtime GUID
        // three times.
        void ProcessDynamicQuestKillProgress(DynamicQuestKillEvent const& event);

        // Milestone 2.13C4 P2 fix (STATIC review, round 3): the fail-
        // closed half of "authoritative" dynamic-quest kill credit.
        // DynamicQuestKillEventBus is still a bounded queue by necessity
        // (a map thread must never block or grow memory without bound -
        // see that class's own comment) - an actual drop under truly
        // pathological load or a stalled world thread is not
        // mathematically impossible, only extremely rare. What must never
        // happen regardless is a player's quest silently sitting at a
        // progress count that may now be wrong with no signal anywhere.
        // Called once per Update() tick, right after draining
        // _dynamicQuestKillEventBus: if
        // _dynamicQuestKillEventBus.GetDroppedEventCount() has increased
        // since the last tick, this registry has no way to know WHICH
        // Active instance (if any) the lost kill(s) belonged to - so
        // every currently Active instance is Fail()ed rather than risk
        // even one of them staying silently, permanently short of a
        // credit it actually earned. Deliberately broad and costly - this
        // is meant to be exceptionally rare and to fail loudly
        // (TC_LOG_ERROR, naming exactly how many quests were affected)
        // rather than silently.
        //
        // Milestone 2.13C4 P3 fix (STATIC review, round 4): this method
        // itself only ever decides WHETHER a drop happened - the actual
        // "fail every Active instance" consequence is
        // DynamicQuestRegistry::FailAllActiveInstances(), which has its
        // own direct Catch2 coverage (the STATIC review's own advisory
        // finding was that this orchestration had no test of its own).
        // This method stays here only because GetDroppedEventCount()
        // lives on DynamicQuestKillEventBus, which DynamicQuestRegistry
        // has no knowledge of - it is still not itself unit-testable in
        // this sandbox (no compiler/live world), but everything it
        // delegates to now is.
        //
        // Milestone 2.13C6B3: for each instance FailAllActiveInstances()
        // actually returns (a real committed Failed value, never a
        // rejected/no-op one), publishes a DynamicQuestFailed outcome via
        // PublishDynamicQuestOutcome() and then removes it from the
        // registry - publish-then-remove, same order Completed/Expired
        // already use, so a drop never blocks or reverts the transition.
        //
        // Milestone 2.13C6D: the actual fail-all/publish/remove sequence
        // now lives in ForceFailAllActiveDynamicQuestsForKillCreditLoss()
        // below - this method's own remaining job is unchanged (decide
        // whether a drop was really observed), so TryRunTestDynamicQuestKillCreditLoss()
        // can drive the exact same consequence without a real
        // DynamicQuestKillEventBus overflow.
        void ReclaimDynamicQuestsAfterKillCreditLoss();

        // Milestone 2.13C6D: the shared consequence
        // ReclaimDynamicQuestsAfterKillCreditLoss() above and
        // TryRunTestDynamicQuestKillCreditLoss() below both call, once
        // each has separately decided a (real or, for the test hook,
        // simulated) kill-credit loss actually happened - see this
        // method's own definition comment for why neither caller ever
        // reimplements this sequence itself. droppedEventCount and
        // simulated only affect the DYNAMIC_QUEST_KILL_CREDIT_LOST log
        // line's wording (P3 fix, STATIC review: this method cannot
        // otherwise tell a real bus drop apart from the test hook's
        // simulated one, so it must never claim a real event was
        // "detected" for the simulated path) - neither changes what
        // actually gets failed.
        void ForceFailAllActiveDynamicQuestsForKillCreditLoss(uint64 droppedEventCount, bool simulated);

        // Milestone 2.13C6D: AIWorld.TestDynamicQuestKillCreditLoss
        // (default false = disabled) - a runtime-provable way to reach
        // the SAME authoritative Failed path
        // ReclaimDynamicQuestsAfterKillCreditLoss() uses, without
        // actually exhausting DynamicQuestKillEventBus's real 16384-event
        // capacity (not something a live test server should try to do)
        // or manufacturing an unrecoverable reward-compensation failure
        // (the bus's own other real Failed production path). Simulates
        // ONLY the detection of one lost kill-credit event - never
        // fabricates a WorldEvent, never writes Memory, never builds a
        // reaction directly; everything from
        // ForceFailAllActiveDynamicQuestsForKillCreditLoss() onward is
        // the exact same production sequence: real DynamicQuestState::
        // Failed -> PublishDynamicQuestOutcome() -> Remove() -> the
        // normal EventBus/Perception/Memory/gossip-reaction path. Retries
        // every tick while enabled and not yet fired, only actually
        // firing (and logging DYNAMIC_QUEST_TEST_KILL_CREDIT_LOSS_TRIGGERED)
        // once at least one Active instance is genuinely fail-applicable
        // (P3 fix, STATIC review: Active alone is not enough - a stale,
        // already-expired-but-not-yet-reclaimed Active instance would
        // make FailDynamicQuest() itself reject with AlreadyExpired,
        // which would burn this one-shot latch on a no-op) - see this
        // method's own definition comment.
        void TryRunTestDynamicQuestKillCreditLoss();

        // Milestone 2.13C4: the same wall-clock "now" every nowMs
        // parameter on this class already uses internally (see
        // AIWorldMgr.cpp's own anonymous-namespace CurrentTimeMs()) -
        // exposed only because AIWorldCreatureAI::OnGossipSelect() must
        // supply a nowMs to call AcceptDynamicQuestForPlayer() and lives
        // outside this class; a second, independently-written copy of the
        // same formula would risk drifting from this one over time.
        uint64 GetCurrentTimeMs() const;

        // Milestone 2.13A3B: AIWorld.TestDynamicTaskAgentId (AgentId{} =
        // disabled) - once the configured agent is live/materialized and
        // has at least one real, fresh WorldEvent short-term memory, calls
        // the real production TrySubmitDynamicTask() with that real
        // memory - never a synthetic QuestContext, never its own
        // JSON/HTTP/fake-response logic. Fires (sets
        // _testDynamicTaskFired) only once TrySubmitDynamicTask() itself
        // actually returns true; otherwise tries again next tick, exactly
        // like every other one-shot AIWorld.Test* hook in this file.
        void TryRunDynamicTaskRuntimeProbe();

        // Milestone 2.12E2/2.12E3B P2 fix (STATIC review): the raw,
        // policy-UNGATED dissolve path - thin wrapper around
        // _groupLifecycleSystem.RequestDissolveGroup(), except it also
        // erases _groupSimulationSchedule's entry for groupId once the
        // dissolve is confirmed (2.12E2 hardening: an earlier version left
        // that entry behind on every dissolve, growing
        // _groupSimulationSchedule without bound across repeated
        // create/dissolve cycles - RequestDissolveGroup() itself has no
        // access to that map, it is AIWorldMgr-only scheduling bookkeeping,
        // so this is the one place that can close the gap). onComplete
        // fires with the same success/failure AgentGroupLifecycleSystem::
        // RequestDissolveGroup() itself would have reported.
        //
        // NOT the canonical dissolve entry point any more (STATIC review:
        // an earlier version of this comment claimed it was meant for
        // "any automatic/policy-driven caller too" - wrong, since this
        // method has no AgentGroupOperationSource and asks
        // AgentGroupPolicySystem nothing, an automatic caller going
        // through this directly could dissolve a Stable group outright,
        // exactly what StableGroupProtected exists to prevent for
        // CanLeave()). Reserved for callers that are themselves already
        // the policy decision - today's manual smoke test/cleanup paths,
        // which are unconditionally allowed the same way a Manual request
        // always is. Any automatic/policy-driven caller (2.12E4+) MUST use
        // RequestDissolveGroupWithPolicy() below instead.
        void RequestDissolveGroup(GroupId groupId, std::function<void(bool)> onComplete);

        // Milestone 2.12E3B P2 fix (STATIC review): the canonical,
        // policy-gated dissolve entry point - the Dissolve counterpart to
        // RequestJoinGroupWithPolicy()/RequestLeaveGroupWithPolicy() below,
        // closing the gap those two already covered but
        // RequestDissolveGroup() above never did. source ==
        // AgentGroupOperationSource::Manual always proceeds straight to
        // RequestDissolveGroup(), the same "a deliberately-authorized
        // individual request is never policy-blocked" rule CanLeave()
        // already gives Manual. source == AutomaticPolicy asks
        // _groupPolicySystem.ShouldDissolve() first - which already
        // encodes both halves of the rule this milestone's own roadmap
        // message asked for (AutomaticPolicy + Stable -> always false,
        // i.e. rejected; AutomaticPolicy + Loose -> only when actually
        // below AIWorld.LooseGroupMinMembers) without this method needing
        // to duplicate that Kind-branch itself - only calls through to
        // RequestDissolveGroup() if that returns true. An unknown groupId
        // or a rejected decision calls onComplete(false) synchronously and
        // never reaches AgentGroupLifecycleSystem/the DB at all, the same
        // contract RequestJoinGroupWithPolicy()/
        // RequestLeaveGroupWithPolicy() already hold.
        void RequestDissolveGroupWithPolicy(GroupId groupId, AgentGroupOperationSource source, std::function<void(bool)> onComplete);

        // Milestone 2.12E4R test hook: one-shot, gated behind
        // AIWorld.TestDissolveGroupId (default 0 = disabled) - runs first
        // among Initialize()'s own manual test actions, so an operator can
        // clear a specific leftover AgentGroup out of the way before
        // AIWorld.WolfGroupAutoFormation's own timer (which cannot fire
        // until Update() first runs, strictly after Initialize() returns)
        // ever gets a chance to see its former members as still grouped.
        // Goes through RequestDissolveGroupWithPolicy(..., Manual) - the
        // same policy-gated path any other deliberately-authorized
        // individual request already uses - never
        // AgentGroupRegistry::Remove() or a raw DB DELETE. See its own
        // .cpp comment for the full "fresh formation" regression this
        // makes repeatable.
        void RunTestDissolveGroup(GroupId groupId);

        // Milestone 2.12G2R: the shared ownership-tuple proof that a
        // specific AgentRecord currently has a GENUINELY in-flight,
        // coordination-sourced MOVE_TO (Regroup or Roam) - generalizes the
        // exact fail-closed six-part proof CheckTestDissolveOnActiveRegroup()
        // itself established for Regroup alone (2.12F3 P3 fix, round 2 -
        // see its own comment below for why each part is needed), so that
        // hook (refactored to call this instead of re-deriving the check
        // inline) and the three new active-Roam test hooks below all share
        // ONE definition rather than four independently-maintained copies
        // that could silently drift apart. requiredSourceGroup, if
        // non-empty, additionally requires GroupCoordinationGoalState::
        // SourceGroup to name that exact group - the two dissolve hooks'
        // own need, each scanning one specific group's own members;
        // GroupId{} (the default/disabled value) accepts any currently-
        // owning group - the preempt/leave hooks' own need, which target
        // one specific AgentId rather than one specific GroupId. Pure
        // read-only proof, never mutates record or anything else - the
        // caller decides what to do once this returns true.
        bool HasActiveCoordinationMoveTo(AgentRecord const& record, GoalType goalType, GroupId requiredSourceGroup = GroupId{}) const;

        // Milestone 2.12G3D1: one captured HUNT attempt's own full
        // identity - what CaptureActiveHuntAttempt() below returns once
        // every one of its own fail-closed checks has held. Pure value:
        // no Creature*/Unit*/Map*, nothing this struct itself resolved
        // stays alive past the call that produced it.
        struct TestHuntAttemptIdentity
        {
            AgentId Member;
            GroupId SourceGroup;
            uint64 StartedAtMs = 0;
            ActionTargetRef Target;
            uint64 TargetObservedAtMs = 0;
        };

        // Milestone 2.12G3D1: CheckTestObserveActiveHunt()'s own read-only
        // proof that a specific AgentRecord currently has a GENUINELY
        // in-flight, fully-owned HUNT approach - built on top of
        // HasActiveCoordinationMoveTo(record, GoalType::Hunt) (the exact
        // same six-part ownership-tuple proof Regroup/Roam already share -
        // generalized here, not duplicated) and then extended with HUNT's
        // own additional target-identity requirements, in order:
        //   - HasActiveCoordinationMoveTo(record, GoalType::Hunt) itself
        //     already requires ActiveActionState::Type == MoveTo,
        //     ::SourceGoal == Hunt, GroupCoordinationGoalState::Type ==
        //     Hunt, the two attempts' own StartedAtMs/GoalStartedAtMs
        //     identity matching, the member Materialized with a live,
        //     transiently-resolved Creature, and HasOwnMoveToGenerator()
        //     actually true on it;
        //   - record.ActiveActionState->Target exists;
        //   - that Target's own Guid/Entry match
        //     GroupCoordinationGoalState::TargetGuid/TargetEntry exactly -
        //     ActiveAction and GroupCoordinationGoal must agree on WHICH
        //     target this attempt is for, not merely on goal/group/
        //     timestamp;
        //   - that Guid provably IS a creature, and its own embedded entry
        //     matches the declared Entry (the same GUID/entry-binding
        //     discipline ActionSystem::ValidateHuntTarget() already
        //     enforces at dispatch time, re-proven here rather than
        //     trusted to still hold);
        //   - GroupCoordinationGoalState::SourceGroup still resolves in
        //     _groupRegistry, AND record.Id is still actually one of its
        //     Members (never trusts that either still holds by the time
        //     this specific poll runs);
        //   - the member's own re-resolved live Creature IsAlive()
        //     (2.12G3D1 P2 fix, STATIC review: ResolveLiveCreature() only
        //     looks up a pointer by spawn, it does not itself check
        //     liveness - HasActiveCoordinationMoveTo() above never claimed
        //     to either, so this method checks it explicitly to actually
        //     satisfy its own declared "materialized/alive actor"
        //     requirement, without changing HasActiveCoordinationMoveTo()
        //     itself and risking the older Regroup/Roam test hooks that
        //     already share it);
        //   - the target transiently resolves live by its exact Guid
        //     (ObjectAccessor::GetCreature(), never a force-load, never
        //     stored past this call) and IsAlive();
        //   - that live target is on the SAME map as the member's own
        //     live Creature, its own live Entry still matches the
        //     declared one, and it is still IsValidAttackTarget() for
        //     this member.
        // Returns nullopt the instant any one of these does not hold - no
        // partial/best-effort identity is ever returned. Never mutates
        // record or anything else; the caller decides what to do (here,
        // only log) once this returns a value.
        std::optional<TestHuntAttemptIdentity> CaptureActiveHuntAttempt(AgentRecord const& record) const;

        // Milestone 2.12G2R P2 fix, round 2 (STATIC review): the four
        // independent facts VerifyCoordinationStop() below reports -
        // returned as a named struct, not a single bool, specifically so
        // a FAILED log can say precisely which one(s), if any, did not
        // hold, and so a caller never has to conflate "did the expected
        // stop event happen" with "is the bookkeeping now fully clean"
        // the way an earlier, single-bool HasMatchingCoordinationAttempt()
        // (round 1, now removed) accidentally allowed: that helper
        // returned false the moment ANY ONE of its own checked fields
        // stopped matching, which "the attempt concluded" does NOT
        // require to mean ALL of them did - a partially-cleared state
        // (e.g. ActiveActionState gone but GroupCoordinationGoalState
        // still lingering) would have silently passed verification too.
        struct CoordinationStopVerification
        {
            // AgentRecord::LastCoordinationStop names this EXACT captured
            // attempt (same Reason/SourceGoal/SourceGroup/StartedAtMs) -
            // see CoordinationStopEvent.h for why this is the one fact
            // that actually distinguishes a genuine production stop from
            // the attempt simply having arrived naturally in the
            // meantime (which never writes this event at all).
            bool StopEventMatches = false;

            // The captured attempt's own GroupCoordinationGoalState/
            // ActiveActionState are independently re-confirmed gone from
            // AgentRecord's own CURRENT state, not merely inferred from
            // StopEventMatches - defense in depth against the event
            // itself somehow having been recorded without the state
            // actually being cleared.
            bool GroupCoordinationGoalGone = false;
            bool ActiveActionStateGone = false;

            // Milestone 2.12G2R P2 fix, round 3 (STATIC review): straight
            // from the matching event's own EngineGeneratorWasRunningBeforeStop
            // AND EngineGeneratorConfirmedStoppedAfterStop, both required -
            // see CoordinationStopEvent.h for why checking only the
            // "after" half (an earlier version) let a stop that found
            // nothing running in the first place (the attempt had already
            // arrived naturally) be misread as genuine evidence of a
            // production stop interrupting a live movement. False whenever
            // StopEventMatches itself is false.
            bool EngineGeneratorGone = false;

            // Milestone 2.12G2R P2 fix, round 3 (STATIC review): only
            // meaningful (and only ever set) when the matching event's own
            // Reason == PreemptedByGoal - straight from that event's own
            // PreemptingOwner/PreemptingGoal, captured synchronously at the
            // exact stop moment by the production code itself, never
            // re-derived by a caller from AgentRecord's own CURRENT (and
            // possibly already-moved-on) ActiveGoalState/RoutineGoalState.
            std::optional<CoordinationPreemptingOwner> PreemptingOwner;
            std::optional<GoalType> PreemptingGoal;

            bool FullyConfirmed() const { return StopEventMatches && GroupCoordinationGoalGone && ActiveActionStateGone && EngineGeneratorGone; }
        };

        // Milestone 2.12G2R P2 fix, round 2 (STATIC review): the shared
        // provenance-aware postcondition check the three active-Roam
        // lifecycle test hooks below poll in their own VERIFY phase - see
        // CoordinationStopVerification's own comment for why this reports
        // four independent facts instead of one combined bool.
        // expectedReason distinguishes CheckTestPreemptOnActiveRoam()'s
        // own PreemptedByGoal from CheckTestLeaveOnActiveRoam()/
        // CheckTestDissolveOnActiveRoam()'s own StoppedByLifecycle - a
        // matching-identity event recorded for the WRONG reason (e.g. the
        // agent's Roam attempt happened to be preempted by an unrelated
        // individual goal while a leave hook was waiting for a lifecycle
        // stop) must not be accepted as proof of the specific production
        // path each hook is actually trying to prove.
        CoordinationStopVerification VerifyCoordinationStop(AgentRecord const& record, CoordinationStopReason expectedReason,
            GoalType goalType, GroupId sourceGroup, uint64 startedAtMs) const;

        // Milestone 2.12F3 test hook: the runtime-proof counterpart to
        // RunTestDissolveGroup() - gated behind
        // AIWorld.TestDissolveOnActiveRegroupGroupId (default 0 = disabled,
        // also set true - "already fired" - at Initialize() if the
        // configured GroupId does not resolve, see Initialize()'s own
        // comment) and _testDissolveOnActiveRegroupFired, called from
        // Update() only right after a RunCoalitionCoordination() pass
        // actually runs (2.12F3 P3 fix, round 2, STATIC review - not every
        // tick the way an earlier version did; a Regroup is only ever
        // freshly dispatched from inside that same pass, so there is
        // nothing new to find in between two passes), since (unlike
        // RunTestDissolveGroup()'s own leftover-group cleanup) this hook
        // has to WAIT for a runtime condition that cannot exist yet at
        // Initialize() time: some member of the configured group actually
        // mid-REGROUP, proven by the full ownership provenance tuple
        // (2.12F3 P3 fix, round 2, STATIC review - not just
        // ActiveActionState::SourceGoal/GroupCoordinationGoalState::SourceGroup
        // alone, which does not by itself prove a MOVE_TO is really
        // running): ActiveActionState::Type == MoveTo,
        // ActiveActionState::SourceGoal == Regroup,
        // GroupCoordinationGoalState::Type == Regroup,
        // GroupCoordinationGoalState::SourceGroup naming this exact group,
        // the two attempts' own StartedAtMs/GoalStartedAtMs identity
        // matching, the member Materialized with a live, transiently-
        // resolved Creature, and HasOwnMoveToGenerator() actually true on
        // it - see this method's own definition for the full reasoning.
        // Once observed, requests a Manual dissolve through
        // RequestDissolveGroupWithPolicy() - the same entry point
        // RunTestDissolveGroup() itself uses, never AgentGroupRegistry::
        // Remove(), never a raw StopMoveTo() called directly from this
        // hook, never a raw DB DELETE - so this proves AIWorldMgr::
        // RequestDissolveGroup()'s own StopGroupCoordinationForMember()
        // call (2.12F2 P2 fix, STATIC review) actually stops a real
        // in-flight Regroup end to end, through the exact same production
        // path a real dissolve-while-regrouping would take. Sets
        // _testDissolveOnActiveRegroupFired BEFORE submitting the dissolve
        // request, unconditionally - fires at most once ever, the same
        // guarantee every other AIWorld.Test* hook in this file gives. Its
        // own completion logs CONFIRMED, not PASSED (2.12F3 P3 fix, STATIC
        // review) - a successful dissolve alone does not prove it actually
        // stopped a still-running REGROUP, only that the dissolve itself
        // committed; the triggering member's REGROUP could naturally have
        // already ended on its own before the async dissolve confirmed.
        // Also self-disables (logs, sets _testDissolveOnActiveRegroupFired)
        // if the configured group no longer resolves at all (2.12F3 P3 fix,
        // round 3, STATIC review) - the group can legitimately dissolve
        // through the normal lifecycle path before this hook ever observes
        // an active REGROUP, and Initialize()'s own existence check only
        // ever catches a target already gone at startup, not one that
        // vanishes later; without this, a vanished target would otherwise
        // be polled once per coordination pass forever.
        void CheckTestDissolveOnActiveRegroup();

        // Milestone 2.12G2R: the ROAM lifecycle runtime closure - three
        // test hooks (preempt via a real individual goal, leave and
        // dissolve via AgentGroupOperationSource::Manual) proving that the
        // exact production paths already proven for Regroup
        // (2.12F3's own emergency-preemption and dissolve-during-active-
        // REGROUP proofs) work identically for Roam, since 2.12G2 itself
        // only proved formation/target/dispatch/arrival, never lifecycle.
        // All three are called from Update() only right after a
        // RunCoalitionCoordination() pass actually runs (same reasoning as
        // CheckTestDissolveOnActiveRegroup()'s own comment - Roam is only
        // ever freshly dispatched from inside that same pass), and each
        // fires at most once ever, gated behind its own config key AND its
        // own *Fired latch, exactly the same "costs nothing once disabled
        // or fired" contract every other AIWorld.Test* hook in this file
        // already gives.
        //
        // Milestone 2.12G2R P2 fix (STATIC review): each hook is now
        // explicitly two-phase, not "trigger and immediately declare
        // done" - an earlier version set its own *Fired latch (and, for
        // preempt, logged nothing further at all) the instant the
        // triggering action was SUBMITTED, before anything had actually
        // been confirmed to happen; the targeted ROAM attempt could
        // naturally have ended on its own (ARRIVED) moments later, and the
        // hook would still have silently reported success.
        //
        // Milestone 2.12G2R P2 fix, round 2 (STATIC review): VERIFY itself
        // was still not enough - polling "is the old attempt's bookkeeping
        // gone" cannot tell WHY it is gone (a natural ARRIVED clears the
        // exact same fields a genuine preemption/lifecycle stop does), and
        // preempt's own re-derivation of "is GetFood active NOW" could
        // itself go stale between polls (GetFood could finish and release
        // ActiveGoalState again before the next ~5s coordination pass ever
        // polls). VERIFY now instead waits for AgentRecord::
        // LastCoordinationStop (CoordinationStopEvent.h) - a record
        // written SYNCHRONOUSLY by the real production stop sites
        // themselves (UpdateNeeds()'s own COORDINATION_PREEMPTED_BY_GOAL
        // block, StopInFlightGroupCoordination()'s own
        // COORDINATION_STOPPED_BY_LIFECYCLE path), at the exact moment
        // they stop an attempt - never speculatively, never by a test
        // hook itself. Full shape:
        //   1. TRIGGER phase (*Triggered false): waits for
        //      HasActiveCoordinationMoveTo(..., Roam) to prove a real
        //      attempt is active, captures that exact attempt's own
        //      identity (SourceGroup/StartedAtMs, or - dissolve only -
        //      every currently-roaming member's own), submits the
        //      triggering action, and sets *Triggered true (plus a
        //      verification deadline) - never sets *Fired yet.
        //   2. VERIFY phase (*Triggered true): polled on every subsequent
        //      RunCoalitionCoordination()-gated pass via
        //      VerifyCoordinationStop() (with the expectedReason each
        //      hook's own comment below names) until it reports
        //      StopEventMatches - the ONLY thing that gates leaving this
        //      phase - or the verification deadline passes. Only once
        //      StopEventMatches is true does the hook set *Fired true and
        //      decide PASSED/FAILED, from CoordinationStopVerification's
        //      remaining fields plus whatever additional postcondition
        //      each hook's own comment below lists - never CONFIRMED/
        //      PASSED on an unverified assumption, and never purely from
        //      re-deriving current live state (which could itself have
        //      already moved on by poll time).

        // AIWorld.TestPreemptOnActiveRoamAgentId (default 0 = disabled):
        // TRIGGER - once the configured AgentId is observed genuinely
        // mid-ROAM, raises its own AgentRecord::Needs.Hunger to 1.0 - the
        // ONLY thing this hook ever touches. Deliberately NOT
        // SafetyPressure/FLEE_DANGER: SafetyPressure is fully recomputed
        // from live InCombat/MemorySafetyPressure every single
        // NeedsSystem::Update() call (see NeedsSystem.cpp), so setting it
        // directly here would be silently overwritten before GoalSystem
        // ever saw it; Hunger instead drifts additively (also
        // NeedsSystem::Update()), so this sticks the same way a real
        // FoodShortage WorldEvent's own organic push toward GoalSystem's
        // GoalCandidateThreshold (0.80) would. Setting it does NOT itself
        // activate a goal or touch ActiveGoalState/ActiveActionState/
        // GroupCoordinationGoalState/registry/membership in any way - the
        // next real UpdateNeeds() pass's own unmodified GoalSystem::
        // GenerateCandidates()/UpdateActiveGoal() is what actually
        // activates GET_FOOD as a real Normal-priority ActiveGoal, and
        // UpdateNeeds()'s own existing, unmodified
        // COORDINATION_PREEMPTED_BY_GOAL block is what actually stops the
        // in-flight Roam MOVE_TO once that happens.
        // VERIFY - polls VerifyCoordinationStop(..., PreemptedByGoal, Roam,
        // capturedGroup, capturedStartedAtMs). PASSED only once
        // StopEventMatches AND GroupCoordinationGoalGone AND
        // ActiveActionStateGone AND EngineGeneratorGone all hold AND the
        // SAME matching event's own PreemptingGoal == GetFood (2.12G2R P2
        // fix, round 3, STATIC review: read from CoordinationStopVerification::
        // PreemptingGoal - captured synchronously by UpdateNeeds() itself
        // at the exact stop moment, NOT re-derived from AgentRecord::
        // ActiveGoalState's own CURRENT state on this later poll, which
        // could already have moved on - the preempting goal may have
        // already finished, or a different one may have taken its place,
        // by the time this hook gets a chance to look). FAILED on a
        // verification timeout (the expected stop event never observed -
        // most likely a natural ARRIVED, which never produces one at all)
        // or if the event is observed but was not genuinely caused by a
        // GetFood preemption.
        void CheckTestPreemptOnActiveRoam();

        // AIWorld.TestLeaveOnActiveRoamAgentId (default 0 = disabled):
        // TRIGGER - once the configured AgentId is observed genuinely
        // mid-ROAM, requests a Manual leave for it from its own current
        // GroupCoordinationGoalState::SourceGroup via the existing
        // RequestLeaveGroupWithPolicy() entry point - never a direct
        // AgentGroupRegistry::RemoveMember() or membership-table mutation.
        // VERIFY - polls VerifyCoordinationStop(..., StoppedByLifecycle,
        // Roam, capturedGroup, capturedStartedAtMs) AND, independently,
        // fresh membership (queried from _groupRegistry, never trusted
        // from the leave request's own completion callback). PASSED only
        // once StopEventMatches AND GroupCoordinationGoalGone AND
        // ActiveActionStateGone AND EngineGeneratorGone all hold AND the
        // agent is confirmed no longer a member - proving
        // RequestLeaveGroupWithPolicy()'s own existing
        // StopGroupCoordinationForMember() call, tagged with the correct
        // lifecycle reason, actually stopped the in-flight movement, not
        // just that the membership edge changed. FAILED on a verification
        // timeout or if membership was removed without the matching
        // StoppedByLifecycle event ever being observed.
        void CheckTestLeaveOnActiveRoam();

        // AIWorld.TestDissolveOnActiveRoamGroupId (default 0 = disabled):
        // the Roam counterpart to CheckTestDissolveOnActiveRegroup(), but
        // - Milestone 2.12G2R P2 fix (STATIC review) - captures EVERY
        // currently-roaming member of the configured group, not just the
        // first one found: a group-wide dissolve must be proven to stop
        // every one of them, not merely whichever one this hook happened
        // to check first while iterating Members.
        // TRIGGER - once at least one member is observed genuinely
        // mid-ROAM, captures each roaming member's own (AgentId,
        // StartedAtMs) identity and requests a Manual dissolve through
        // RequestDissolveGroupWithPolicy() - never a direct
        // AgentGroupRegistry mutation, never a raw StopMoveTo() called
        // from the hook itself, never a DB DELETE.
        // VERIFY - waits for the group itself to no longer resolve in
        // _groupRegistry, then polls VerifyCoordinationStop(...,
        // StoppedByLifecycle, Roam, groupId, startedAtMs) for EVERY
        // captured member independently. PASSED only once the group is
        // gone AND every captured member's own StopEventMatches AND
        // GroupCoordinationGoalGone AND ActiveActionStateGone AND
        // EngineGeneratorGone all hold - proving RequestDissolveGroup()'s
        // own StopGroupCoordinationForMember() call, tagged with the
        // correct lifecycle reason, actually stopped ALL of them, not
        // just that the dissolve itself committed. FAILED on a
        // verification timeout (group still resolves) or if the group is
        // gone but any captured member's own matching stop event was
        // never observed.
        void CheckTestDissolveOnActiveRoam();

        // Milestone 2.12G3D1: AIWorld.TestObserveActiveHuntAgentId
        // (default 0 = disabled) - a non-invasive, read-only runtime proof
        // that a real, production-dispatched HUNT approach can reach the
        // exact same fully-owned state HasActiveCoordinationMoveTo()/
        // CaptureActiveHuntAttempt() already require, end to end: a
        // genuine CreatureSeen memory observation -> HuntIntentSystem::
        // Evaluate() -> HuntIntentProjector::Project() ->
        // DispatchHuntProposal()'s own live revalidation ->
        // ActionSystem::Validate() ALLOWED -> a real engine MoveTo
        // generator actually running, with ActiveAction/
        // GroupCoordinationGoal agreeing on the exact same target
        // identity. Unlike the active-Roam TRIGGER/VERIFY hooks above,
        // this one changes and starts NOTHING - it never submits an
        // action, never mutates AgentRecord, never calls StopMoveTo() -
        // purely polls CaptureActiveHuntAttempt() for the one configured
        // agent. Checked only right after a RunCoalitionCoordination()
        // pass actually runs (the same cadence-tying reasoning
        // CheckTestDissolveOnActiveRegroup()'s own comment already gives -
        // a HUNT MOVE_TO is only ever freshly dispatched from inside that
        // same pass), gated on _testObserveActiveHuntAgentId being set AND
        // not yet fired. On the first pass CaptureActiveHuntAttempt()
        // returns a value, logs PASSED with the full captured identity and
        // sets the one-shot latch - never fires again for the rest of this
        // process's lifetime. If the configured agent stops resolving in
        // _registry entirely (removed/never existed), disables itself with
        // a logged ERROR the same way the config-time check at
        // Initialize() already does.
        void CheckTestObserveActiveHunt();

        // Milestone 2.12E4C2 P2 fix (STATIC review): one-shot, gated
        // behind AIWorld.AdoptGroupId (default 0 = disabled) - the
        // controlled adoption path for a group whose persistent
        // AgentGroupRecord::ProfileId (added this same milestone, backfilled
        // to Invalid for every pre-existing row) does not yet reflect which
        // CoalitionFormationProfile actually governs it. Deliberately NOT
        // automatic: this milestone's own migration backfills every
        // pre-existing group to ProfileId::Invalid rather than guessing,
        // since silently relabeling an existing Loose group as WolfLoose
        // (or any other profile) with no operator confirmation is exactly
        // the kind of false-provenance assignment this whole ProfileId
        // field exists to prevent. Recovering a specific, already-known-
        // legitimate pre-existing group is instead this explicit, human-
        // triggered call - the same "no raw SQL/direct registry mutation,
        // go through the existing persistence API" discipline
        // RunTestDissolveGroup() already holds, applied to a metadata
        // correction instead of a lifecycle operation. Refuses anything but
        // a recognized, non-Invalid CoalitionFormationProfileId (an
        // explicit allow-list, not merely "!= Invalid" - a stray/garbage
        // config value must be refused here, not deferred to the next
        // restart's own LoadGroups() fail-closed switch to catch) or an
        // unresolvable groupId.
        //
        // 2.12E4C2 P2 fix, round 2 (STATIC review): submits
        // AgentGroupPersistence::AdoptGroupProfileAsync() (a confirmed
        // TransactionCallback, enqueued into _groupLifecyclePending like
        // every other AgentGroup persistence write) rather than mutating
        // AgentGroupRecord::ProfileId immediately and calling the existing
        // fire-and-forget SaveGroupState() - an earlier version did exactly
        // that and logged "adopted" before the DB write was even known to
        // have landed, so a failed async UPDATE could leave
        // RunCoalitionMaintenance() treating an only-in-RAM-adopted group
        // as WolfLoose (able to Leave/Dissolve its members) while the DB
        // itself still read Invalid, reverting silently on the next
        // restart. The in-memory AgentGroupRecord::ProfileId is now only
        // ever mutated inside that completion, once success is confirmed -
        // "adopted" is never logged, and the group is never treated as
        // adopted by anything else, before that.
        //
        // 2.12E4C2 P2 fix, round 3 (STATIC review): marks groupId in
        // _groupProfileAdoptionInFlight for the duration of the async
        // write - see that member's own declaration comment for the
        // cross-write race this closes against the group coarse tick's
        // own SaveGroupState() (a second, uncoordinated writer of the same
        // profile_id column that could otherwise commit either before or
        // after this one and silently undo it).
        void RunGroupProfileAdoption(GroupId groupId, CoalitionFormationProfileId profileId);

        // Milestone 2.12E2: manual proof that AgentGroupLifecycleSystem's
        // async Request* API never touches Creature/WorldState and never
        // blocks the world thread - runs once from Initialize(), only when
        // all three AIWorld.TestGroupMemberAgentId1/2/3 resolve to
        // already-registered agents. Never creates an agent itself (see
        // this method's own .cpp comment for why an earlier version doing
        // so was wrong). Kicks off RequestCreateGroup(), whose completion
        // chains into RunGroupLifecycleSmokeTestJoinStep() to join the
        // three members one at a time (each join only issued from the
        // previous one's own completion - see AgentGroupLifecycleSystem.h
        // for why a synchronous loop can no longer do this), which in turn
        // chains into a leave and a dissolve. Every step's outcome is
        // checked; a failure anywhere logs FAILED and attempts a
        // best-effort RequestDissolveGroup() cleanup via
        // RunGroupLifecycleSmokeTestAbort() rather than leaving a partially
        // joined test group behind.
        void RunGroupLifecycleSmokeTest(AgentId memberId1, AgentId memberId2, AgentId memberId3);

        // Milestone 2.12E2: joins memberIds[index], then recurses into
        // index+1 - once index reaches memberIds.size(), leaves the last
        // member and dissolves the group instead. See
        // RunGroupLifecycleSmokeTest()'s own comment for why this is a
        // chain of completions rather than a loop.
        void RunGroupLifecycleSmokeTestJoinStep(GroupId groupId, std::array<AgentId, 3> memberIds, std::size_t index);

        // Milestone 2.12E2: logs the smoke test as FAILED (naming which
        // step and member failed), then fires a fire-and-forget
        // RequestDissolveGroup() best-effort cleanup for groupId so a
        // mid-sequence failure (e.g. the second Join succeeds but the
        // third fails) does not leave a partially joined test group
        // sitting in the DB/registry forever. The cleanup's own outcome is
        // only logged, never chained into anything further - this is
        // best-effort, not a guarantee.
        void RunGroupLifecycleSmokeTestAbort(GroupId groupId, char const* step, AgentId memberId);

        // Milestone 2.12E3B: the canonical way ANY part of AIWorldMgr asks
        // to join a group - resolves groupId in _groupRegistry, asks
        // _groupPolicySystem.CanJoin() (source is always relevant here,
        // even though CanJoin() itself never reads it - kept in the
        // signature for symmetry with RequestLeaveGroupWithPolicy() and so
        // every call site names who is asking, matching
        // AgentGroupOperationSource.h's own comment on why that matters
        // for logging even where a rule does not yet branch on it), and
        // only calls through to _groupLifecycleSystem.RequestJoinGroup()
        // if the answer is Allowed. An unknown groupId or a rejected
        // decision calls onComplete(false, decision) synchronously and
        // never reaches AgentGroupLifecycleSystem/the DB at all - see
        // AgentGroupPolicySystem.h's own class comment for why this gate
        // sits strictly upstream of lifecycle, never inside it.
        //
        // Milestone 2.12E3B P3 fix (STATIC review): onComplete carries the
        // AgentGroupPolicyDecision alongside success, not just a bare bool
        // - decision != Allowed means policy itself rejected the request
        // (success is always false in that case, and nothing downstream of
        // policy was ever touched); decision == Allowed means the request
        // reached AgentGroupLifecycleSystem, and success reflects whatever
        // that layer/the DB ultimately reported. Without this, a caller
        // (a test, or future policy/AI code reacting to a rejection)
        // cannot tell "policy said no" apart from "policy said yes but the
        // DB write failed" from the bool alone - see
        // RunGroupPolicySmokeTest()'s own integration half for exactly the
        // assertion this makes possible that a bare bool could not
        // (STABLE_GROUP_PROTECTED specifically, not just "some rejection
        // happened, for some reason, somewhere"). InvalidOperation is used
        // for the one case that never reaches AgentGroupPolicySystem at
        // all - an unknown groupId, see AgentGroupPolicyDecision.h's own
        // comment on why that value was reserved rather than invented here.
        void RequestJoinGroupWithPolicy(GroupId groupId, AgentId memberId, uint64 joinedAtMs, AgentGroupOperationSource source,
            std::function<void(bool success, AgentGroupPolicyDecision decision)> onComplete);

        // Milestone 2.12E3B: same shape as RequestJoinGroupWithPolicy(),
        // asking _groupPolicySystem.CanLeave() instead - this is the one
        // that actually matters for Stable protection, since CanLeave()
        // rejects (StableGroupProtected) an AutomaticPolicy leave for a
        // Stable group but allows a Manual one for either kind. An unknown
        // groupId or a rejected decision calls onComplete(false, decision)
        // synchronously and never reaches AgentGroupLifecycleSystem/the DB
        // - see RequestJoinGroupWithPolicy()'s own comment (2.12E3B P3 fix)
        // for why decision is reported alongside success.
        void RequestLeaveGroupWithPolicy(GroupId groupId, AgentId memberId, AgentGroupOperationSource source,
            std::function<void(bool success, AgentGroupPolicyDecision decision)> onComplete);

        // Milestone 2.12E3B: manual proof of AgentGroupPolicySystem's own
        // rules, in two parts. Part one is pure - synthetic
        // AgentGroupRecord values built on the stack, fed straight to
        // _groupPolicySystem.CanJoin()/CanLeave()/ShouldDissolve(), no
        // registry/DB touched at all, exercising every rule
        // AgentGroupPolicySystem.cpp implements (capacity, Manual-vs-
        // AutomaticPolicy leave, Loose-below-minimum dissolution, Stable
        // protection). Always runs when this method is called at all (see
        // AIWorld.TestGroupPolicy). Part two only runs if testMemberId is
        // set and resolves in _registry - creates a real Stable test
        // group, joins testMemberId, then proves the policy gate actually
        // protects RequestLeaveGroupWithPolicy(): an AutomaticPolicy leave
        // must be rejected with membership left untouched, a Manual leave
        // for the same member must then succeed, and the test group is
        // dissolved (manually, via RequestDissolveGroup()) either way
        // before finishing, so it never lingers as a permanent DB fixture.
        void RunGroupPolicySmokeTest(AgentId testMemberId);

        // Milestone 2.12E4C1: manual proof of CoalitionMaintenanceSystem's
        // own rules, entirely pure - synthetic AgentGroupRecord/
        // CoalitionMemberObservation values built on the stack, fed
        // straight to a stack-local CoalitionMaintenanceSystem::Evaluate(),
        // no registry/DB/AIWorldMgr member state touched at all (unlike
        // RunGroupPolicySmokeTest(), this has no integration half yet -
        // 2.12E4C1 deliberately adds no lifecycle orchestration, see
        // CoalitionMaintenanceSystem.h's own class comment). Exercises
        // every rule CoalitionMaintenanceSystem.cpp implements: a
        // materialized/alive/same-map member past LeaveRadius proposes
        // LeaveMember; one well within it proposes None; an unloaded or
        // dead member is never a Leave candidate regardless of its last
        // known position; a group already below MinMembers proposes
        // DissolveGroup outright; and - the one case that matters most -
        // Evaluate() proposes LeaveMember for a Stable group's own
        // far-away member exactly as readily as for a Loose one, proving
        // this class does not (and must not) special-case Stable itself.
        // Always runs when this method is called at all (see
        // AIWorld.TestCoalitionMaintenance).
        void RunCoalitionMaintenanceSmokeTest() const;

        // Milestone 2.12F1: manual proof of AgentGroupIntentSystem's own
        // rules, entirely pure - synthetic AgentGroupRecord/
        // CoalitionMemberObservation/AgentGroupCoordinationProfile values
        // built on the stack, fed straight to a stack-local
        // AgentGroupIntentSystem::Evaluate(), no registry/DB/AIWorldMgr
        // member state touched at all (the same "pure layer first, zero
        // orchestration" scoping CoalitionMaintenanceSystem's own
        // RunCoalitionMaintenanceSmokeTest() already established for
        // 2.12E4C1 - 2.12F1 deliberately adds no AgentGroupIntentProjector/
        // ActionSystem wiring yet, see AgentGroupIntentSystem.h's own
        // class comment). Exercises every rule AgentGroupIntentSystem.cpp
        // implements: a materialized/alive/same-map member past
        // RegroupRadius proposes Regroup; one well within it proposes
        // None; an unloaded or dead member is never a Regroup trigger
        // regardless of its last known position; RegroupEnabled=false
        // proposes None even for an otherwise-textbook dispersed member;
        // and an Invalid profile, a Kind mismatch, or a ProfileId
        // mismatch all fail closed to None, the same three-way guard
        // CoalitionMaintenanceSystem::Evaluate() already holds. Milestone
        // 2.12G2 extends this with Roam's own rules: RoamEnabled=false
        // proposes None even for an otherwise-eligible group; a dispersed
        // group with BOTH RegroupEnabled and RoamEnabled proposes Regroup,
        // never Roam (REGROUP always outranks ROAM); a cohesive
        // (non-dispersed) group with RoamEnabled proposes Roam, targeting
        // a point within RoamDistance of its own territory; and two
        // Evaluate() calls given the same nowMs (hence the same roam
        // phase) agree on the exact same target. Always runs when this
        // method is called at all (see AIWorld.TestGroupIntent).
        void RunGroupIntentSmokeTest() const;

        // Milestone 2.12F2: manual proof of AgentGroupIntentProjector's own
        // rules, entirely pure - a synthetic AgentGroupIntent/
        // AgentGroupCoordinationProfile/CoalitionMemberObservation values
        // built on the stack, fed straight to a stack-local
        // AgentGroupIntentProjector::Project(), no registry/DB/AIWorldMgr
        // member state touched at all (the same "pure layer first" scoping
        // RunGroupIntentSmokeTest() itself already established for
        // AgentGroupIntentSystem - this milestone deliberately adds no
        // ActionSystem/orchestration wiring yet, see
        // AgentGroupIntentProjector.h's own class comment). Exercises every
        // rule AgentGroupIntentProjector.cpp implements: a materialized/
        // alive/same-map member past RegroupRadius gets a proposal
        // targeting the intent's own point; one well within it gets none;
        // an unloaded or dead member never gets one regardless of its last
        // known position; a different-map member never gets one either;
        // and intent.Type == None produces no proposals for anyone,
        // regardless of how dispersed the members are. Milestone 2.12G2
        // extends this with Roam's own rules: a Roam intent gets the exact
        // same materialized/alive/same-map/unloaded/dead/different-map
        // treatment as Regroup, just compared against RoamArrivalRadius
        // instead of RegroupRadius; and an unrecognized AgentGroupIntentType
        // value (neither None, Regroup, nor Roam) fails closed to no
        // proposals at all, the same explicit-switch discipline Project()
        // itself holds to. Always runs when this method is called at all
        // (see AIWorld.TestGroupIntentProjector).
        void RunGroupIntentProjectorSmokeTest() const;

        // Milestone 2.12G3B: manual proof of HuntIntentSystem's and
        // HuntIntentProjector's own rules, entirely pure - synthetic
        // AgentGroupRecord/AgentGroupCoordinationProfile/
        // CoalitionMemberObservation/HuntTargetObservation/HuntIntent
        // values built on the stack, fed straight to stack-local
        // HuntIntentSystem::Evaluate()/HuntIntentProjector::Project()
        // instances, no registry/DB/AIWorldMgr member state touched at all
        // (the same "pure layer first, zero orchestration" scoping
        // RunGroupIntentSmokeTest()/RunGroupIntentProjectorSmokeTest()
        // already established for 2.12F1/F2 - this milestone deliberately
        // adds no GoalType::Hunt, ActionSystem wiring, or
        // RunCoalitionCoordination() integration, see HuntIntentSystem.h/
        // HuntIntentProjector.h's own class comments). Exercises every
        // rule HuntIntentSystem.cpp/HuntIntentProjector.cpp implement,
        // including: a valid target selects a HuntIntent; a disabled or
        // mismatched profile selects nullopt; an empty GUID, wrong
        // creature entry, dead target, stale/future-dated observation,
        // different-map target, missing line-of-sight, or an
        // out-of-radius target is each individually rejected; an
        // unloaded/dead/non-member observer's sighting is never trusted;
        // of two valid targets the nearer one wins, with a stable
        // TargetGuid tie-break on equal distance; reordering the input
        // candidates never changes the result; StartedAtMs equals nowMs
        // while Target.ObservedAtMs is preserved unchanged, never
        // conflated with the attempt timestamp; and on the projection
        // side, two valid members get two proposals, an unloaded/dead/
        // different-map member gets none, an invalid intent produces no
        // proposals at all, and every produced proposal carries the exact
        // target/group/attempt timestamp the intent itself had. Always
        // runs when this method is called at all (see
        // AIWorld.TestHuntIntent).
        void RunHuntIntentSmokeTest() const;

        // Milestone 2.12G3C1: manual proof of ActionSystem::Validate()'s own
        // authoritative HUNT approach validation contract, entirely pure -
        // synthetic ActionRequest/ActionValidationContext values built on
        // the stack, fed straight to _actionSystem.Validate(), no
        // registry/DB/live Creature/Map/grid access at all, and no
        // ActionExecutor/movement (the same "pure layer first" scoping
        // RunControlModeSmokeTest() already established for the ControlMode
        // gate - this milestone deliberately adds no
        // RunCoalitionCoordination()/DispatchHuntProposal() wiring, see
        // ActionSystem::ValidateHuntTarget()'s own class comment).
        // Exercises: a fully honest HUNT approach (MoveTo, SourceGoal=Hunt,
        // Target naming the exact context-resolved target, Destination
        // exactly matching the target's own current position) is ALLOWED;
        // a missing Target, empty GUID, or zero Entry, an unresolved/dead/
        // non-attackable context target, a request Target GUID/Entry that
        // disagrees with the context's own resolved GUID/Entry, a target
        // not on the actor's own map, a Destination not on the actor's own
        // map, a Destination that does not match the target's own current
        // position (including a non-finite target position), and a target
        // beyond the shared coordination MOVE_TO range are each
        // individually rejected with their own distinct
        // ActionRejectReason; the pre-existing ControlMode/materialized/
        // alive/goal-honesty/ActorMovementBusy common checks still apply
        // unchanged to a HUNT request; and an ordinary Regroup/Roam MoveTo
        // (no Target at all) still validates exactly as it did before this
        // milestone. Always runs when this method is called at all (see
        // AIWorld.TestHuntActionValidation).
        void RunHuntActionValidationSmokeTest() const;

        // Milestone 2.12G3D1 P2 fix (runtime finding): manual proof of
        // HandleActionCompletion()'s own HUNT arrival-ownership retention,
        // entirely pure - synthetic AgentRecord/ActionCompletion values
        // built on the stack, fed straight to HandleActionCompletion()
        // itself (the real production method, not a reimplementation);
        // both types are plain values, no live Creature/Map/registry
        // access needed. Not const, unlike the other pure Hunt smoke
        // tests above - HandleActionCompletion() itself is a non-const
        // private method, so this cannot be called from a const context.
        // Exercises: a genuine Succeeded/Arrived completion for a
        // HUNT-sourced action releases ActiveActionState but RETAINS
        // GroupCoordinationGoalState with the exact same group/target/
        // StartedAtMs identity, explicitly transitioned to
        // HuntPhase::AtTarget (2.12G3D2A - never merely inferred from
        // ActiveActionState's own absence, see HuntPhase's own comment in
        // GroupCoordinationGoal.h); every OTHER HUNT completion reason
        // (Failed/DestinationNotReached, GoalInterrupted,
        // ActorDematerialized, ActorDead, EngineStopped) still releases
        // ownership exactly like before; and Regroup/Roam arrival is
        // proven unaffected - the retention exception is HUNT-only, never
        // generalized. Deliberately does NOT simulate two full
        // RunCoalitionCoordination() passes end to end, and does NOT
        // exercise DispatchHuntProposal()'s own re-approach rule
        // (2.12G3D2A - a member already AtTarget for the SAME attempt is
        // only re-dispatched once the target has genuinely moved beyond
        // ArrivalToleranceYards) - both need a live registry/Map/Creature,
        // out of scope for a pure smoke test; see
        // AIWorld.TestObserveActiveHuntAgentId's own "stage=ARRIVED"/
        // "stage=REAPPROACH"/"reason=ALREADY_AT_TARGET" diagnostic logging
        // for the live-server equivalent. This test instead directly
        // proves the ONE mechanism the loop-prevention actually depends
        // on. Always runs when this method is called at all (see
        // AIWorld.TestHuntArrivalOwnership).
        void RunHuntArrivalOwnershipSmokeTest();

        // Milestone 2.12F4A: manual proof only, gated behind
        // AIWorld.TestControlMode (default 0 = disabled) - runs at most once,
        // from Initialize(), only against a real, already-registered AgentId
        // (never a fake/ghost AgentRecord). Proves ActionSystem::Validate()'s
        // own mandatory, authoritative ControlMode gate: the exact same
        // otherwise-fully-valid MOVE_TO ActionRequest/context is validated
        // twice, with only ActionValidationContext::ControlMode changed
        // between the two calls (ObserveOnly, then AIWorldControlled) - so
        // any difference in outcome can only be attributed to that gate,
        // never to some other check incidentally differing too. Entirely
        // pure - no live Creature/Map/grid access, since the gate under
        // test is a plain-value check inside ActionSystem itself.
        void RunControlModeSmokeTest(AgentId testAgentId) const;

        // Milestone 2.12F4B/2.12F4B2: bidirectional reconciliation between
        // eligible persistent non-instance world.creature spawns and
        // ai_agents, SCOPED to zoneId (2.12F4B2 - see Initialize()'s own
        // comment for the fail-closed AIWorld.EnableSpawnReconciliation/
        // AIWorld.SpawnReconciliationZoneId gating: this is only ever
        // called with an already-validated, nonzero zoneId - there is
        // deliberately no unscoped/global code path any more, see
        // AIWorld_Current_Roadmap.md's own "2.12F4B2" section for why a
        // global mode is deferred to its own explicit future override
        // rather than being reachable from here). Called right after
        // _persistence.LoadAgents(_registry) and before anything (group/
        // memory loaders, the AIWorld.TestSpawnId fixture) consumes
        // _registry, so every downstream startup step sees the final,
        // reconciled state. The 2.12F4B engine itself (diff/reconcile) is
        // unchanged by 2.12F4B2 - only its own `census` input is filtered
        // down to FetchCreatureSpawnIdsForZone(zoneId)'s result before
        // being passed to BuildReconciliationPlan(); BuildAllKnownCreatureSpawnIds()
        // stays global/unscoped, so an existing agent outside the
        // configured zone still correctly falls into OutOfScopeCount, not
        // Orphaned. The diff is built against ai_agents' own PHYSICAL
        // content (_persistence.LoadAllBindings(), 2.12F4B P2 fix STATIC
        // review) rather than _registry, so a row LoadAgents() itself
        // already quarantined (AgentId != SpawnId, 2.12F4A2) is still
        // known to occupy its (map_id, spawn_id) binding AND its agent_id,
        // and is never treated as Missing - nor is a census spawn whose
        // intended new AgentId collides with a different quarantined
        // row's own agent_id (AGENT_ID_COLLISION, see
        // SpawnReconciliationPlan.h). MISSING census entries get a freshly
        // created AgentRecord (AgentId = SpawnId, ControlMode =
        // ObserveOnly - reconciliation never mass-grants AIWorldControlled),
        // inserted via a genuine chunked multi-row INSERT (AgentPersistence::
        // CreateCreatureAgentsBatch()), not one statement per row.
        // ORPHANED and CONFLICTED (spawn still eligible, but the row's own
        // stored MapId disagrees with world.creature) bindings are both
        // removed from _registry only - never an aggressive ai_agents
        // DELETE/auto-repair, see RunSpawnReconciliation()'s own .cpp
        // comment. Bounded/administered (runs once at startup, never
        // recurring per-tick) - scale hardening for a fully-reconciled
        // population at world scale is 2.12F4C's own job, not this one's
        // (2.12F4B already measured 128849 agents world-wide with a real
        // world-thread performance regression - see the roadmap's own
        // 2.12F4B "Runtime evidence" note).
        void RunSpawnReconciliation(uint32 zoneId);

        // Runtime participation/scope boundary fix (AIWorld_Current_
        // Roadmap.md, Etapa 3): unlike RunSpawnReconciliation()/
        // RunZoneControlActivation() above, this is NOT gated behind
        // AIWorld.EnableSpawnReconciliation - a safety invariant must not
        // depend on an optional data-reconciliation feature flag. Called
        // unconditionally from Initialize() right after
        // _spawnParticipationCatalog.Load(), before the reconciliation
        // gate. Scans the WHOLE AgentRegistry (every persisted agent, not
        // just one zone's census) via SpawnParticipationCatalog::TryResolve()
        // - a SpawnId this catalog has no data for at all (outside the
        // currently-classified census, e.g. a different zone) is left
        // completely alone; only a SpawnId this catalog explicitly
        // classifies is acted on:
        //   Excluded (EXCLUDED_EVENT): must never be a live agent -
        //   quarantined from _registry only, ai_agents row/control_mode
        //   left untouched (same policy RunSpawnReconciliation()'s own
        //   ExcludedButBound pass already applies whenever it happens to
        //   run - this method makes that enforcement unconditional).
        //   VanillaOnly (e.g. Spirit Healer): a legitimate permanent agent
        //   that must simply never be AIWorldControlled - persisted
        //   demotion via AgentPersistence::DemoteControlModeBatch()
        //   (batch + read-back confirm, the same fail-closed shape every
        //   other batch persistence method in this subsystem uses), record
        //   removed nowhere.
        void ApplyParticipationControlPolicy();

        // Milestone 2.12F4B3: promotes every scoped-eligible agent in
        // `zoneId` from ObserveOnly to AIWorldControlled - gated behind
        // AIWorld.EnableZoneControlActivation/AIWorld.ControlZoneId (see
        // Initialize()'s own comment for the fail-closed combination,
        // mirroring 2.12F4B2's AIWorld.EnableSpawnReconciliation/
        // AIWorld.SpawnReconciliationZoneId gating - only ever called with
        // an already-validated, nonzero zoneId, no unscoped/global code
        // path). Recomputes its own scoped identity set exactly the same
        // way RunSpawnReconciliation() does (BuildCreatureSpawnCensus()
        // intersected with FetchCreatureSpawnIdsForZone(zoneId)) rather
        // than reusing any state 2.12F4B2 may have left behind - safe to
        // run on a restart where reconciliation did not just run, since
        // _registry is always freshly rebuilt from ai_agents by
        // LoadAgents() regardless. For each scoped-eligible identity with
        // an existing, matching AgentRecord (AgentId == SpawnId already
        // guaranteed by AgentRegistry; MapId re-checked defensively here
        // in case this runs without 2.12F4B2 having just quarantined a
        // Conflicted row out of _registry this same startup) that is not
        // already AIWorldControlled, promotes via one batched
        // AgentPersistence::PromoteControlModeBatch() call - never a
        // per-agent SetControlMode() loop over a zone-sized population.
        // Only entries PromoteControlModeBatch() itself confirms via
        // read-back are reflected into AgentRecord::ControlMode in memory;
        // this never optimistically assumes an unconfirmed write landed.
        // A scoped-eligible spawn with no existing AgentRecord yet (2.12F4B2
        // reconciliation hasn't created it) is never created here - this
        // method only ever promotes, never mints new identity. Milestone
        // 2.12F4B3 P2 fix (STATIC review): fail-closed WHOLE-zone
        // activation, not partial - if ANY scoped-eligible spawn has no
        // valid AgentRecord yet, this refuses to promote even the
        // candidates that do, logs an ERROR, and returns without touching
        // ai_agents at all. A mixed Controlled/ObserveOnly zone that the
        // server just carries on with is exactly the outcome this
        // milestone's target state ("N eligible spawns -> N Controlled,
        // 0 ObserveOnly") rules out.
        void RunZoneControlActivation(uint32 zoneId);

        // Milestone 2.12E4R (generalized from 2.12E4A's
        // CollectWolfCoalitionCandidates()): builds the value-only
        // candidate list CoalitionFormationSystem::Propose() needs - one
        // entry per currently registered agent that is Materialized and
        // alive, with NO further eligibility filtering at all (STATIC
        // review's own "WORLD OBSERVATION / FORMATION PROFILE split"
        // guidance): this method has no idea which CreatureEntry, Kind, or
        // group membership any particular CoalitionFormationProfile cares
        // about - that is CoalitionFormationSystem::Propose() and
        // RunCoalitionFormation()'s own job (see CollectMemberIdsOfKind()
        // for the membership half). Never mutates anything - no
        // BindCreature/UnbindCreature call, no registry/DB write. A
        // candidate's position/MapId/CreatureEntry come from its live
        // Creature, resolved fresh this call, never a stored/stale
        // AgentRecord field - the same "the live Creature is the ground
        // truth for where an agent actually is" discipline
        // UpdateNeeds()/RunDecisionScheduler() already follow. Never
        // force-loads a grid: an agent whose Creature does not currently
        // resolve is simply absent from the returned list, the same as if
        // it did not exist for this pass at all - an unload must never be
        // misread as a formation-relevant fact.
        std::vector<CoalitionCandidate> CollectCoalitionCandidates() const;

        // Milestone 2.12E4R (STATIC review): replaces the old wolf-only
        // IsMemberOfAnyLooseGroup() - builds a one-off O(1)-lookup set of
        // every AgentId currently a member of ANY group of exactly kind,
        // by walking _groupRegistry.GetGroups()/Find() exactly once per
        // RunCoalitionFormation() call, rather than re-walking every group
        // (and every one of its members) for every single candidate the
        // way the method this replaces did - the performance debt that
        // review flagged. AgentGroupRegistry::IsMemberOfKind() is
        // deliberately NOT called once per candidate here for that same
        // reason; IsMemberOfKind() itself stays reserved for a single,
        // one-off re-check (see RunCoalitionJoinStep()), where building a
        // whole snapshot for one member would be wasted work.
        std::unordered_set<uint64> CollectMemberIdsOfKind(AgentGroupKind kind) const;

        // Milestone 2.12G1 P2 fix (STATIC review): the shared formation
        // scheduler/pass - called unconditionally, every Update() tick,
        // for EVERY registered formation profile (today: WolfLoose,
        // DefiasLoose), the same "one shared discovery pass, then
        // per-item profile resolution" shape RunCoalitionMaintenance()/
        // RunCoalitionCoordination() already use. Replaces an earlier
        // shape (2.12G1's own first version) that gave each profile its
        // own independent Update() `if (autoFormation) { timer...;
        // RunCoalitionFormation(profile); }` branch - reviewed and
        // rejected: RunCoalitionFormation() used to do its own
        // CollectCoalitionCandidates()/CollectMemberIdsOfKind() every
        // time it was called, so two profiles due the same pass meant two
        // full redundant scans of the same registry/group state
        // (O(profiles x registry) instead of O(registry)), AND the fixed
        // WolfLoose-then-DefiasLoose branch order gave WolfLoose an
        // implicit, deterministic first claim on the shared
        // _coalitionFormationMaxInFlight budget every time both profiles'
        // matching-default (5000ms, both starting at 0) timers fired on
        // the same tick.
        //
        // Each profile still owns its own enabled flag/cadence as plain
        // per-profile data (_wolfGroupAutoFormation/
        // _wolfGroupFormationIntervalMs/_wolfGroupFormationTimer and their
        // Defias equivalents) - that data is what varies per profile,
        // never the orchestration loop itself. If no profile's timer is
        // due this call, returns immediately with zero discovery cost,
        // the same "no cost at all unless something is due" treatment
        // every other bounded pass in this class already gets.
        //
        // Milestone 2.12G1 P2 fix, round 2 (STATIC review): fairness is
        // admission-aware, not merely timer-aware - an earlier version of
        // this method reset every due profile's own timer up front and
        // flipped _formationPassFavorDefiasFirst unconditionally every
        // pass, regardless of whether either profile actually got a
        // formation attempt STARTED. Under the shared
        // _coalitionFormationMaxInFlight budget (default 1) that let a
        // long-running async formation saga for one profile keep the
        // OTHER profile's due timer resetting (and the rotation toggle
        // flipping) every pass anyway, purely by timing coincidence -
        // concretely, a profile could be evaluated, found budget-blocked,
        // have its timer reset regardless, and then never get a real
        // shot again for as long as the toggle kept landing on the
        // "wrong" side relative to which pass the budget happened to free
        // up on. Now:
        //   - if the shared budget is already fully occupied before any
        //     due profile is even considered, this returns immediately -
        //     no discovery, no timer resets, every due profile stays due
        //     and is reconsidered the very next tick;
        //   - within the pass, a due profile blocked because an EARLIER
        //     due profile in the SAME pass just consumed the budget also
        //     keeps its own timer running (not reset) for the same
        //     reason;
        //   - a profile's timer only resets once it is genuinely
        //     EVALUATED (RunCoalitionFormation() actually called for it);
        //   - _formationPassFavorDefiasFirst only flips if some profile's
        //     RunCoalitionFormation() call actually returned true (a real
        //     attempt started this pass) - never merely because a pass
        //     ran.
        // Otherwise unchanged: exactly ONE CollectCoalitionCandidates()
        // call for every due profile this pass, and
        // CollectMemberIdsOfKind() cached per DISTINCT AgentGroupKind
        // actually needed this pass (today WolfLoose/DefiasLoose share
        // Kind::Loose, so this collapses to one call for both, not two -
        // still correct if a future profile of a different Kind is
        // added).
        void RunCoalitionFormationPass(uint32 diff);

        // Milestone 2.12E4R (generalized from 2.12E4A/B's
        // RunWolfCoalitionFormation()): the per-profile evaluate/dispatch
        // half of formation - called only from RunCoalitionFormationPass()
        // above, once per due profile per pass, never called directly
        // from Update() any more (2.12G1 P2 fix, STATIC review). Refuses
        // profile.Id == Invalid outright (2.12E4R P3 fix, STATIC review -
        // see CoalitionFormationProfileId.h), refuses if profile.Id is
        // already in _formationInFlight (at most one attempt in flight
        // PER PROFILE - see its own declaration comment), and refuses if
        // _formationInFlight.size() has already reached
        // _coalitionFormationMaxInFlight (2.12E4R P3 fix, STATIC review:
        // the per-profile bound alone has no ceiling on how many DIFFERENT
        // profiles' formations can all be in flight at once - see
        // _coalitionFormationMaxInFlight's own declaration comment;
        // 2.12G1 P2 fix, round 2, STATIC review: RunCoalitionFormationPass()
        // already checks this same budget before ever calling here, so
        // this check should be unreachable in practice - kept as defense
        // in depth, this method must never itself assume its only caller
        // is that pass).
        //
        // Milestone 2.12G1 P2 fix (STATIC review): `candidates` and
        // `excludedMembers` are now the CALLER's own responsibility
        // (RunCoalitionFormationPass()'s shared discovery for this whole
        // pass) - this method no longer calls CollectCoalitionCandidates()/
        // CollectMemberIdsOfKind() itself, so evaluating N due profiles in
        // the same pass costs one discovery, not N. `excludedMembers` must
        // already be profile.Kind's own CollectMemberIdsOfKind() result -
        // every candidate already a CONFIRMED member of a profile.Kind
        // group is excluded via it, AND every candidate already RESERVED
        // for a profile.Kind formation still in flight
        // (_formationReservedMembers - 2.12E4R P2 fix, STATIC review, see
        // its own declaration comment for the cross-profile race this
        // closes) is excluded here directly - then asks
        // _coalitionFormationSystem.Propose() for a deterministic
        // CoalitionProposal. No proposal this pass is not an error - it
        // just means nothing eligible was close enough right now, and
        // nothing is reserved or added to _formationInFlight for it.
        //
        // On an actual proposal: reserves every Proposal.Members entry
        // (CoalitionFormationReservationKey{member, profile.Kind}) BEFORE
        // submitting RequestCreateGroup() - this is what actually closes
        // the cross-profile race, not the join-time re-check alone (that
        // re-check only ever sees CONFIRMED AgentGroupRegistry state, which
        // is exactly the window two same-Kind profiles' own in-flight
        // CreateGroup/Join chains do not yet occupy) - then turns the
        // proposal into a real AgentGroup via RequestCreateGroup() followed
        // by a RequestJoinGroupWithPolicy(AutomaticPolicy) chain (see
        // RunCoalitionJoinStep()). Reservations are released
        // (ReleaseCoalitionFormationReservations()) at every terminal
        // outcome - a failed CreateGroup here, a fully successful join
        // chain, or a cleaned-up aborted one - never left dangling.
        //
        // Milestone 2.12G1 P2 fix, round 2 (STATIC review): returns
        // whether an attempt genuinely STARTED this call (a real proposal
        // was found and the CreateGroup/Join chain was just submitted) -
        // false for every refusal/no-proposal outcome above. This is what
        // RunCoalitionFormationPass() uses to decide whether to reset a
        // profile's own timer / advance its rotation cursor, never merely
        // "was this method called".
        //
        // WolfLoose and, since 2.12G1, DefiasLoose both go through this
        // exact same method - nothing here reads AIWorld.Wolf*/
        // AIWorld.Defias* config directly, confirming a profile is just a
        // CoalitionFormationProfile value passed in by
        // RunCoalitionFormationPass(), never a new orchestration path of
        // its own.
        bool RunCoalitionFormation(CoalitionFormationProfile const& profile,
            std::vector<CoalitionCandidate> const& candidates,
            std::unordered_set<uint64> const& excludedMembers);

        // Milestone 2.12E4R (generalized from 2.12E4B's
        // RunWolfCoalitionJoinStep()): joins
        // attempt.Proposal.Members[attempt.NextMemberIndex] with
        // AgentGroupOperationSource::AutomaticPolicy, then recurses with
        // NextMemberIndex+1 - once NextMemberIndex reaches
        // attempt.Proposal.Members.size(), formation is complete, logged
        // PASSED, attempt.Proposal's own reservations are released
        // (ReleaseCoalitionFormationReservations() - 2.12E4R P2 fix, now
        // redundant with real AgentGroupRegistry membership but released
        // for symmetry with every other terminal outcome), and
        // attempt.ProfileId is erased from _formationInFlight. The same
        // "chain each step from the previous one's own completion" shape
        // RunGroupLifecycleSmokeTestJoinStep() already uses, for the same
        // reason (AgentGroupLifecycleSystem allows at most one in-flight
        // operation per GroupId - see its own header comment). Any join
        // failure aborts the whole formation and best-effort dissolves the
        // group already created for it (AbortCoalitionFormation()) rather
        // than leaving a partially joined automatic coalition behind.
        //
        // 2.12E4A/B P2 fix (STATIC review), preserved unchanged by this
        // generalization: re-checks the member still resolves in
        // _registry AND is still not a member of any attempt.Proposal.Kind
        // group (AgentGroupRegistry::IsMemberOfKind()), immediately before
        // issuing its own join - the exact eligibility
        // CollectCoalitionCandidates()/CollectMemberIdsOfKind() already
        // checked once when the proposal was built, but that snapshot can
        // go stale by the time a later step in this chain actually runs
        // (the async CreateGroup round trip, and every join before this
        // one, all take real time - a manual/lifecycle/other-policy change
        // to this member's own membership could land in between).
        // RequestJoinGroupWithPolicy()'s own CanJoin() only ever validates
        // against THIS groupId - AgentGroupPolicySystem deliberately has no
        // global one-group invariant (see its own class comment) - so it
        // cannot catch a member that is already in some OTHER group of the
        // same Kind; only this re-check (plus RunCoalitionFormation()'s own
        // reservation, for the cross-PROFILE case specifically) can. A
        // failure here aborts and cleans up the same way a rejected/failed
        // join itself does.
        void RunCoalitionJoinStep(CoalitionFormationAttempt attempt);

        // Milestone 2.12E4R (generalized from 2.12E4B's
        // RunWolfCoalitionFormationAbort()): logs the formation attempt as
        // FAILED (naming the member that could not join) and fires a
        // fire-and-forget RequestDissolveGroup() best-effort cleanup for
        // attempt.Group - the same reasoning
        // RunGroupLifecycleSmokeTestAbort() already documents for the
        // manual lifecycle smoke test. This is cleanup of an already
        // policy-approved formation operation (CanJoin() already said
        // Allowed for every member that got this far), never a way to
        // bypass automatic policy. attempt.Proposal's own reservations are
        // released (ReleaseCoalitionFormationReservations()) and
        // attempt.ProfileId is erased from _formationInFlight only once
        // this cleanup dissolve itself completes (success or failure),
        // never synchronously inside this method - see
        // _formationInFlight's own declaration comment.
        void AbortCoalitionFormation(CoalitionFormationAttempt const& attempt, AgentId failedMember);

        // Milestone 2.12E4R P2 fix (STATIC review): erases
        // CoalitionFormationReservationKey{member.Value, proposal.Kind} for
        // every proposal.Members entry from _formationReservedMembers - the
        // one place every RunCoalitionFormation()/RunCoalitionJoinStep()/
        // AbortCoalitionFormation() terminal outcome releases its own
        // reservations, so there is exactly one place that has to get the
        // "release everything this proposal reserved" logic right.
        void ReleaseCoalitionFormationReservations(CoalitionProposal const& proposal);

        // Milestone 2.12E4C2: builds one CoalitionMemberObservation per
        // group.Members entry - the maintenance-side counterpart to
        // CollectCoalitionCandidates(), walking an EXISTING group's own
        // membership rather than scanning the whole registry for new
        // candidates. Never mutates anything, never force-loads a grid -
        // a member whose Creature does not currently resolve (or whose
        // AgentRecord is not even Materialized) simply gets a default
        // (Materialized=false) observation, never skipped outright, so
        // CoalitionMaintenanceSystem::Evaluate() sees one observation per
        // membership edge, present or not.
        std::vector<CoalitionMemberObservation> CollectCoalitionMemberObservations(AgentGroupRecord const& group) const;

        // Milestone 2.12E4C2: AIWorld.CoalitionMaintenanceIntervalMs-
        // cadenced pass, only ever called while AIWorld.CoalitionMaintenance
        // is enabled - a SEPARATE gate from AIWorld.WolfGroupAutoFormation
        // (2.12E4C2 P2 fix, STATIC review - see _coalitionMaintenanceEnabled's
        // own declaration comment for why formation and maintenance must
        // not share one on/off switch).
        //
        // Milestone 2.12E4C2 P2 fix, round 2 (STATIC review): takes NO
        // profile parameter any more - an earlier version was itself a
        // per-profile function called once per configured profile, each
        // with its own _maintenanceScanCursor... except there was only
        // ever ONE cursor (a single AIWorldMgr member), shared across
        // every call. With only WolfLoose configured this happened to
        // work; the moment a second profile existed, both would share and
        // mutate that same cursor (profile A's own pass advances it past
        // groups 1-100, profile B's own pass - sharing that SAME
        // post-A cursor position - then only ever sees 101-200, never
        // 1-100, and the next pass both wrap together from wherever B
        // left it) - a group whose GroupId never happens to fall in
        // whichever slice its own profile's call ends up scanning is
        // starved forever, the same class of cross-profile bug already
        // fixed once for formation's own member reservations (see
        // CoalitionFormationReservationKey.h). Discovery is now a SINGLE
        // GLOBAL bounded scan across ALL groups regardless of profile,
        // with per-group profile resolution happening AFTER discovery -
        // see the two stages below - so total discovery work stays
        // bounded by one scan bound regardless of how many profiles exist,
        // rather than growing as profileCount * ScanMaxPerPass.
        //
        // Two independently bounded stages, deliberately not one:
        //   1. DISCOVERY: AgentGroupRegistry::GetGroupsAfterUntil(_maintenanceScanCursor,
        //      _maintenanceScanCycleHighWater, AIWorld.CoalitionMaintenanceScanMaxPerPass)
        //      - 2.12E4C2 P3 fix. An earlier version built its candidate
        //      list from GetGroups(), which materializes and filters
        //      EVERY registered group every single pass regardless of how
        //      few of them ever get admitted - O(all groups) recurring
        //      world-thread work, exactly the class of problem
        //      GroupCoarseSimulationScheduler was already introduced to
        //      prevent for admission, just not yet for discovery.
        //
        //      2.12E4C2 P2 fix, round 3 (STATIC review): an interim
        //      version bounded discovery per PASS (GetGroupsAfter(), no
        //      upper bound) but not per SCAN CYCLE - GroupIds are
        //      monotonically increasing, so under continuous group
        //      creation (new groups always minted with a HIGHER id than
        //      any that exist yet) the scan could always find a higher
        //      GroupId waiting past the cursor and would never reach
        //      empty, never wrap, so the earliest-created groups (closest
        //      to GroupId{}) would never be revisited - starved
        //      indefinitely, not merely delayed. _maintenanceScanCycleHighWater
        //      (see its own declaration comment) fixes this: it snapshots
        //      GetHighestGroupId() once at the START of each scan cycle,
        //      and the whole cycle only ever scans up to that snapshot -
        //      a group created mid-cycle is deferred to the NEXT cycle's
        //      own snapshot, never chased by the one already running, so
        //      every cycle is provably finite regardless of creation
        //      rate. The pass immediately after one that reaches the
        //      cycle's own high-water mark gets an EMPTY result and
        //      starts a fresh cycle (new snapshot, cursor reset to
        //      GroupId{}) - a tail pass that returns a non-empty but
        //      under-capacity batch does NOT itself backfill from the
        //      start to top up to ScanMaxPerPass, it simply leaves some
        //      of that pass's own budget unused. Every group that existed
        //      at the start of a cycle is still seen exactly once by the
        //      end of that cycle, spread over several bounded passes
        //      instead of scanned in one unbounded one.
        //   2. Per discovered group, ResolveMaintenanceProfile(group->ProfileId)
        //      - NOT a check against one fixed profile.ProfileId parameter
        //      any more, since this function no longer receives one. A
        //      group whose ProfileId does not resolve (Invalid, or a
        //      profile this process does not know how to maintain) is
        //      simply not a maintenance candidate this pass - see that
        //      method's own comment for why a manually/admin-created group
        //      must never be swept in just because some profile's Kind
        //      happens to match its own. The resolved candidates are then
        //      handed to GroupCoarseSimulationScheduler
        //      (_maintenanceScheduler/_maintenanceSchedule - its own
        //      dedicated instance/schedule map, entirely separate from
        //      _groupCoarseSimulationScheduler/_groupSimulationSchedule's
        //      own resource-drift tick) for the same phase-offset, bounded,
        //      deterministic per-pass admission the group coarse tick
        //      already uses, capped at AIWorld.CoalitionMaintenanceMaxPerPass
        //      - globally, across every profile mixed together in this
        //      pass's own discovered batch, not per profile.
        // Every admitted group is handed to RunCoalitionMaintenanceForGroup()
        // together with its own already-resolved CoalitionMaintenanceProfile.
        void RunCoalitionMaintenance();

        // Milestone 2.12E4C2 P2 fix, round 2 (STATIC review): the one
        // place that maps a persistent AgentGroupRecord::ProfileId to the
        // CoalitionMaintenanceProfile that governs it - std::nullopt for
        // Invalid or any profileId this process has no maintenance rules
        // configured for. WolfLoose (to _wolfLooseMaintenanceProfile) and,
        // since 2.12G1, DefiasLoose (to _defiasLooseMaintenanceProfile)
        // resolve - confirming a second profile really is just another
        // case added here, not a change to RunCoalitionMaintenance()'s own
        // discovery/admission shape.
        std::optional<CoalitionMaintenanceProfile> ResolveMaintenanceProfile(CoalitionFormationProfileId profileId) const;

        // Milestone 2.12E4C2: one group this pass's maintenance scheduler
        // admitted, together with the CoalitionMaintenanceProfile
        // RunCoalitionMaintenance() already resolved for it via
        // ResolveMaintenanceProfile() (2.12E4C2 P2 fix, round 2 - a single
        // pass's own admitted batch can now mix groups governed by
        // different profiles, so profile is no longer necessarily the
        // same value across every call in one pass). Refuses to start if
        // groupId is already in
        // _maintenanceInFlight (see its own declaration comment for the
        // repeated-request spam this guards against) or no longer resolves
        // in _groupRegistry. Builds this group's own observations
        // (CollectCoalitionMemberObservations()) and asks
        // _coalitionMaintenanceSystem.Evaluate() for a deterministic
        // CoalitionMaintenanceDecision:
        //   - LeaveMember: marks groupId in flight, then
        //     RequestLeaveGroupWithPolicy(..., AutomaticPolicy) - the same
        //     policy-gated path RunCoalitionJoinStep() already uses for
        //     joins, so a Stable group's own member is protected the exact
        //     same way an automatic formation join would be rejected for
        //     one (see AgentGroupPolicySystem::CanLeave()). On a confirmed
        //     leave, chains into RunCoalitionMaintenanceAfterLeave() -
        //     never re-uses the AgentGroupRecord* this pass already
        //     resolved, always re-resolves fresh from _groupRegistry once
        //     the leave actually confirms.
        //   - DissolveGroup: marks groupId in flight, then straight into
        //     RunCoalitionMaintenanceDissolveGroup().
        //   - None: nothing to do, groupId is never marked in flight for
        //     it.
        void RunCoalitionMaintenanceForGroup(GroupId groupId, CoalitionMaintenanceProfile const& profile);

        // Milestone 2.12E4C2: runs once a LeaveMember request this same
        // maintenance pass already confirmed - re-resolves groupId fresh
        // from _groupRegistry (never trusts the AgentGroupRecord*/snapshot
        // RunCoalitionMaintenanceForGroup() itself resolved before the
        // leave; that reference is stale by the time this runs, possibly
        // several ticks later - the same "a completion never trusts
        // request-time validity" discipline AgentGroupLifecycleSystem.h's
        // own header comment already documents). An unknown groupId
        // (dissolved some other way in the meantime) just clears
        // _maintenanceInFlight and returns. Otherwise: Kind == Loose and
        // now below profile.MinMembers chains into
        // RunCoalitionMaintenanceDissolveGroup() (still going through
        // policy, so Stable is never reachable here in the first place -
        // Kind is re-read from the freshly-resolved group, not assumed
        // from profile); anything else clears _maintenanceInFlight - the
        // leave alone was the whole maintenance action needed this pass.
        void RunCoalitionMaintenanceAfterLeave(GroupId groupId, CoalitionMaintenanceProfile profile);

        // Milestone 2.12E4C2: RequestDissolveGroupWithPolicy(...,
        // AutomaticPolicy) for groupId - reached either directly from a
        // DissolveGroup decision (a group already below minimum,
        // independent of any single member's own distance) or from
        // RunCoalitionMaintenanceAfterLeave() (a group that just dropped
        // below minimum as a result of its own confirmed leave). Going
        // through policy here (never a raw RequestDissolveGroup()) is what
        // keeps a Stable group protected - AgentGroupPolicySystem::
        // ShouldDissolve() already refuses Stable unconditionally, the
        // same protection RunCoalitionMaintenanceForGroup()'s own
        // LeaveMember path gets from CanLeave(). Always clears
        // _maintenanceInFlight once this dissolve attempt itself completes
        // (success or failure) - the one place every
        // RunCoalitionMaintenanceForGroup()/RunCoalitionMaintenanceAfterLeave()
        // path that reaches a dissolve funnels through, so there is
        // exactly one place that has to get that release right.
        void RunCoalitionMaintenanceDissolveGroup(GroupId groupId);

        // Milestone 2.12F2: the one place that maps a persistent
        // AgentGroupRecord::ProfileId to the AgentGroupCoordinationProfile
        // that governs it - std::nullopt for Invalid or any profileId this
        // process has no coordination rules configured for. WolfLoose (to
        // _wolfLooseCoordinationProfile) and, since 2.12G1, DefiasLoose (to
        // _defiasLooseCoordinationProfile) resolve - the same "profile
        // identity is data, not a new code path" discipline
        // ResolveMaintenanceProfile() already established, and this
        // milestone's own architectural mandate confirmed: a second group
        // TYPE never required a new orchestration method, only a new
        // profile value.
        std::optional<AgentGroupCoordinationProfile> ResolveCoordinationProfile(CoalitionFormationProfileId profileId) const;

        // Milestone 2.12F2: the bounded orchestration pass - AgentGroup ->
        // generic observations -> generic intent (_agentGroupIntentSystem)
        // -> per-member proposals (_agentGroupIntentProjector) -> individual
        // ActionRequest (DispatchGroupMemberActionProposal()). Reuses the
        // exact two-stage bounded-discovery shape RunCoalitionMaintenance()
        // already established (AgentGroupRegistry::GetGroupsAfterUntil()/
        // GetHighestGroupId(), AIWorld.GroupCoordinationScanMaxPerPass) -
        // its own dedicated cursor/high-water pair
        // (_coordinationScanCursor/_coordinationScanCycleHighWater),
        // entirely separate from _maintenanceScanCursor/
        // _maintenanceScanCycleHighWater. A shared cursor would reproduce
        // the exact cross-scan starvation _maintenanceScanCursor's own
        // 2.12E4C2 P2 fix already closed for cross-PROFILE sharing within
        // one concern - two entirely different concerns (maintenance,
        // coordination) scanning the same registry must never share one
        // cursor either, for the same reason.
        //
        // Deliberately no second GroupCoarseSimulationScheduler-backed
        // admission tier the way RunCoalitionMaintenance() has - dispatching
        // a MOVE_TO proposal is a cheap, synchronous, in-memory operation
        // (no async DB write the way an automatic leave/dissolve is), so
        // there is nothing here that needs a separate admission bound
        // beyond the scan bound itself.
        //
        // Milestone 2.12F2 P2 fix (STATIC review): a discovered group whose
        // GroupId currently has a Join/Leave/Dissolve in flight
        // (_groupLifecycleSystem.HasPendingOperation()) is skipped entirely
        // this pass, before ResolveCoordinationProfile()/observations/intent
        // are even attempted. AgentGroupLifecycleSystem only ever mutates
        // AgentGroupRecord::Members inside a Request*'s own confirmed
        // completion (see its own header comment) - so a group with an
        // operation still in flight has membership that is ABOUT to change
        // but has not yet, and evaluating intent/proposing movement against
        // that stale snapshot could dispatch a fresh Regroup for a member
        // whose Leave is already committed to the DB and about to remove
        // them. Failing closed here (skip the whole group, not just the
        // one member already known to be leaving - Dissolve affects every
        // member, and this call has no cheap way to tell which case it is
        // without re-deriving lifecycle's own bookkeeping) is simpler and
        // safer than trying to filter the one affected member out: the
        // group is re-evaluated fresh, with fresh membership, the very next
        // pass once the operation resolves either way.
        //
        // Milestone 2.12F2 P2 fix, round 2 (STATIC review): overlap
        // arbitration is checked per-proposal against how many
        // RegroupEnabled groups that proposal's own Member currently
        // belongs to (AgentGroupRegistry::GetGroupsOfMember(), 2.12F2 P3
        // fix, round 2 - see that method's own comment), not against how
        // many proposals this pass's own bounded discovery batch happened
        // to produce. A first version of this fix collected proposals per
        // pass and counted duplicates only within that same batch - STATIC
        // review correctly identified that as provably incomplete: with
        // AIWorld.GroupCoordinationScanMaxPerPass smaller than the
        // registry, two overlapping groups can simply never be discovered
        // in the same pass, so a batch-local count silently degrades back
        // to "whichever group's own pass runs first wins", the exact
        // hidden discovery-order priority this mechanism exists to remove.
        // A second version fixed THAT by scanning the whole registry once
        // per call up front - STATIC review correctly identified THAT as
        // reintroducing the exact O(all groups) recurring world-thread
        // work class already eliminated from maintenance discovery (see
        // this method's own bounded-discovery paragraph above). Checking
        // per-PROPOSAL via GetGroupsOfMember() instead means this
        // arbitration step's total cost scales with how many proposals
        // this pass actually produced (typically small, and already
        // bounded by AIWorld.GroupCoordinationScanMaxPerPass indirectly via
        // discovered group count), never with total registry size. Nothing
        // in AgentGroupPolicySystem::CanJoin() enforces that one agent can
        // only ever be a real member of ONE coordination-enabled group at a
        // time (it only checks duplicate membership WITHIN the target group
        // and that group's own capacity) - so two different groups can, in
        // principle, both legitimately claim the same AgentId. Any AgentId
        // that belongs to more than one group whose own resolved profile
        // has RegroupEnabled gets NO proposal dispatched for it, from any
        // of them, for as long as that overlap persists - this generic
        // layer has no basis to pick a winner between two coordination
        // profiles it knows nothing else about; leaving the member standing
        // still (re-evaluated fresh next pass) is the only choice that does
        // not invent an implicit, undocumented arbitration rule. Logged at
        // DEBUG, at most once per conflicted AgentId per call - see this
        // method's own definition for why (2.12F2 P3 fix, STATIC review: an
        // earlier version logged a WARN per proposal per pass, turning a
        // persistent, expected arbitration state into recurring log spam).
        //
        // Milestone 2.12F2 P2 fix, round 4 (STATIC review): this arbitration
        // only ever protects a NEW dispatch - it says nothing about an
        // ALREADY in-flight Regroup/Roam that a confirmed Join, some time
        // after that dispatch, newly makes ambiguous. See
        // ReconcileGroupCoordinationForMember() (called from
        // RequestJoinGroupWithPolicy()'s own confirmed-join completion, not
        // from here) for the counterpart that closes that gap; both share
        // the exact same CountCoordinationEnabledMemberships() definition
        // of "ambiguous" so the two can never silently disagree.
        //
        // Milestone 2.12G2: Evaluate() now takes an explicit nowMs (one
        // shared CurrentTimeMs() call for this whole pass, not one per
        // group - see this method's own definition), and its result is
        // accepted for EITHER AgentGroupIntentType::Regroup or ::Roam, not
        // Regroup alone - the same explicit two-value check
        // AgentGroupIntentProjector::Project() already holds its own
        // switch to (2.12F2 P3 fix), so a future third intent type is
        // never silently forwarded just because it is non-None.
        //
        // Milestone 2.12G2 P2 fix (STATIC review): the nowMs actually
        // passed to Evaluate() for a given group is NOT always the shared
        // pass-level one - HasInFlightRoamAttempt()/_roamAttemptPinnedNowMs
        // pin it to whatever nowMs this group's own still-in-flight ROAM
        // attempt was first evaluated with, for as long as any member is
        // still mid-move toward it, so a RoamIntervalMs phase-bucket
        // boundary crossing mid-attempt can never split one group's
        // members across two different ROAM targets at once - see
        // _roamAttemptPinnedNowMs's own declaration comment for the exact
        // interleaving this closes.
        //
        // Per resolved, non-pending group: CollectCoalitionMemberObservations(),
        // _agentGroupIntentSystem.Evaluate(), and - only if the result is
        // Regroup or Roam - _agentGroupIntentProjector.Project(), whose
        // proposals are appended to this pass's own combined batch.
        //
        // Milestone 2.12G3C2: REGROUP > already in-flight HUNT > newly
        // selected HUNT > ROAM. REGROUP is checked first; on a hit, any
        // in-flight HUNT this group's own members currently own is stopped
        // FIRST (StopInFlightGroupCoordination(), CoordinationStopReason::
        // PreemptedByRegroup - 2.12G3C2 P2 fix, STATIC review: outranking
        // HUNT on paper is worthless if DispatchGroupMemberActionProposal()'s
        // own "member already has an ActiveActionState" gate then silently
        // drops the REGROUP proposal against a still-busy member), and only
        // then is REGROUP projected/dispatched. Otherwise HUNT is always
        // considered next, regardless of
        // whether this group's own Regroup/Roam intent.Type came back Roam
        // or None - see ResolveHuntIntentForGroup()/HasInFlightHuntAttempt()
        // for how an already in-flight attempt keeps owning this group's
        // action slot (even producing no NEW proposal this pass) rather
        // than letting a settling ROAM phase steal it back mid-hunt. Only
        // once HUNT claims nothing at all this pass - no in-flight
        // attempt, no fresh selection - does ROAM's own existing rules
        // apply, unchanged from 2.12G2. ReconcileActiveHuntTargetsForGroup()
        // runs once per discovered group, before any of the above, so a
        // just-invalidated in-flight HUNT target is stopped before this
        // same pass decides what (if anything) replaces it.
        //
        // Milestone 2.12G3D1 diagnostic-only addition (STATIC review): for
        // whichever group actually contains the one AgentId currently
        // watched by AIWorld.TestObserveActiveHuntAgentId (and only while
        // that hook has not yet fired), logs "stage=INTENT
        // result=SELECTED|NONE" right after huntIntent is resolved, and -
        // only when an intent was selected - "stage=PROJECT
        // result=PROPOSED|NO_PROPOSAL" right after Project(), reporting
        // specifically whether the watched agent itself received a
        // proposal. Purely read-only tracing - never changes which branch
        // is taken and never sets _testObserveActiveHuntFired.
        void RunCoalitionCoordination();

        // Milestone 2.12G3C2: production HUNT target observation
        // collection - explicitly NOT a new unbounded spatial scan. Reuses
        // whatever CreatureSeen memories PerceptionSystem already wrote
        // into _shortTermMemory for each of group's own members
        // (ShortTermMemory::GetActiveForAgent(), the same TTL'd/
        // deduplicated retrieval MemoryRetrieval's own decision-context
        // path already uses), converting each active CreatureSeen record
        // into one HuntTargetObservation: Observer from MemoryRecord::Owner
        // itself (2.12G3C2 P3 fix, STATIC review - the record's own
        // claimed owner, never the group.Members loop variable used to
        // fetch it; provenance must not be reassigned in this conversion -
        // HuntIntentSystem::Evaluate() is what verifies this Observer
        // actually names a real member of the group), Target.TargetGuid/
        // TargetEntry from MemoryRecord::Target.Guid/Entry, Target.MapId/
        // X/Y/Z from MemoryRecord::Location, Target.ObservedAtMs from
        // MemoryRecord::LastObservedAtMs, Distance/LineOfSight from
        // MemoryRecord::LastDistance/LastLineOfSight. Target.Alive is
        // always set true - PerceptionSystem::ObserveNearbyCreature()
        // itself only ever produces a CreatureSeen Observation for a
        // target that IS alive at observation time (see its own
        // `if (!seen.IsAlive()) return std::nullopt;` guard), so this is
        // an honest fact about how the record was created, not an
        // assumption that it is STILL true now - HuntIntentSystem's own
        // staleness/max-age check is what actually protects against a
        // since-died target's memory record being trusted past its
        // freshness window, and DispatchHuntProposal()'s own live
        // re-resolution is what protects against one trusted right up to
        // dispatch time. No live Creature*/Unit*, no force-load, no
        // registry mutation - a plain read of already-collected memory.
        std::vector<HuntTargetObservation> CollectHuntTargetObservations(AgentGroupRecord const& group, uint64 nowMs) const;

        // Milestone 2.12G3C2: what (if anything) this group's own HUNT
        // should target this pass - the one place that reconstructs an
        // already in-flight attempt's own identity purely from its
        // members' own AgentRecord::GroupCoordinationGoalState, rather
        // than a separate manager-level pin map the way ROAM's own
        // _roamAttemptPinnedNowMs is (HUNT's own target/attempt identity
        // already lives on every dispatched member's own
        // GroupCoordinationGoalState - see GroupCoordinationGoal.h's own
        // 2.12G3C1 comment - so a second, independently-tracked copy of
        // the same fact would just be a new place for the two to silently
        // disagree). Scans group.Members for any whose
        // GroupCoordinationGoalState has Type == GoalType::Hunt and
        // SourceGroup == group.Id: if none exist, no attempt is in
        // flight, and a fresh HuntIntentSystem::Evaluate() (fed
        // CollectHuntTargetObservations()'s own output) is free to select
        // any eligible target. If every such member agrees on the exact
        // same (TargetGuid, TargetEntry, StartedAtMs) tuple, that identity
        // is REUSED - never re-selected from scratch. Milestone 2.12G3C2
        // P2 fix (STATIC review): "reused" does NOT mean hand-picking the
        // freshest matching observation outside the normal rule set - this
        // call filters CollectHuntTargetObservations()'s own output down
        // to ONLY the pinned TargetGuid and sends that filtered set
        // through the exact same HuntIntentSystem::Evaluate() a fresh
        // selection uses, so staleness (HuntObservationMaxAgeMs), observer
        // alive/materialized/same-map, LOS/acquisition-distance, profile
        // entry eligibility, and conflicting-duplicate detection all still
        // apply to the pinned target every single pass, not just at the
        // moment it was first selected. Only Evaluate()'s own resulting
        // StartedAtMs is overridden with the pinned attempt's own stable
        // identity afterward. If Evaluate() itself returns nullopt (the
        // pinned target no longer passes its own rules this pass), this
        // returns nullopt too - nothing NEW to propose; already in-flight
        // members are left entirely untouched either way, never by this
        // method (see ReconcileActiveHuntTargetsForGroup() for their own
        // separate target-validity lifecycle). If members DISAGREE on that
        // tuple,
        // the group's own HUNT state is ambiguous - logged, and nullopt
        // is returned unconditionally, exactly the same "cannot safely
        // pick a winner" fail-closed choice CountCoordinationEnabledMemberships()'s
        // own overlap arbitration already makes for cross-group ambiguity,
        // applied here to a single group's own internally-inconsistent
        // state instead.
        std::optional<HuntIntent> ResolveHuntIntentForGroup(AgentGroupRecord const& group, AgentGroupCoordinationProfile const& profile,
            std::vector<CoalitionMemberObservation> const& observations, uint64 nowMs) const;

        // Milestone 2.12G3C2: the HUNT counterpart to HasInFlightRoamAttempt() -
        // whether ANY current member of group still has an in-flight HUNT
        // attempt SOURCED FROM THIS GROUP (GroupCoordinationGoalState set,
        // Type == GoalType::Hunt, SourceGroup == group.Id), regardless of
        // whether that attempt's own identity is internally consistent
        // across members. Used by RunCoalitionCoordination() purely to
        // decide whether HUNT owns this group's action slot this pass EVEN
        // WHEN ResolveHuntIntentForGroup() itself returns nullopt (an
        // in-flight attempt with nothing NEW to propose this pass must
        // still block ROAM from claiming the slot back mid-hunt).
        bool HasInFlightHuntAttempt(AgentGroupRecord const& group) const;

        // Milestone 2.12G3C2: re-validates every current member of group
        // whose GroupCoordinationGoalState is an in-flight HUNT attempt
        // (Type == GoalType::Hunt, SourceGroup == group.Id) against LIVE
        // target reality - never against the memory-derived
        // HuntTargetProvenance that originally selected it, which can
        // already be stale by the time this runs. For each such member
        // with a live, resolvable, Materialized+Alive Creature: transiently
        // resolves the target by its own stored TargetGuid
        // (ObjectAccessor::GetCreature(), a plain already-loaded-object
        // lookup - never a force-load), then requires ALL of: the target
        // resolves at all; is alive; is on the SAME map as this member's
        // own live Creature; its own live Entry still matches the stored
        // TargetEntry; and it is still IsValidAttackTarget() for this
        // member. The first fact that fails calls
        // StopInFlightGroupCoordination(..., CoordinationStopReason::
        // StoppedByTargetInvalid) for that member - never a partial/
        // best-effort stop, and never anything beyond what
        // StopInFlightGroupCoordination() itself already does (engine
        // MoveTo stop, ActiveActionState/GroupCoordinationGoalState
        // cleared, LastCoordinationStop recorded). A member that cannot be
        // resolved live at all (not Materialized, or ResolveLiveCreature()
        // fails) is left untouched THIS call - neither confirmed valid nor
        // invalidated, since there is nothing here to honestly check
        // either way; existing dematerialization handling elsewhere is
        // what governs that member's own state, not this method. Called
        // once per discovered group, from within RunCoalitionCoordination()'s
        // own bounded per-pass loop - no separate unbounded scan.
        //
        // Milestone 2.12G3D: one exception to the StoppedByTargetInvalid
        // rule above - a member whose own HuntPhase is Engaging (actually
        // fighting the target, ActiveActionState == Attack) and whose
        // target resolves but is no longer ALIVE never goes through
        // StopInFlightGroupCoordination() at all. That path means "this
        // attempt's own target stopped being a legitimate one" - a
        // genuinely defeated target is the opposite, this attempt's own
        // SUCCESS - so it is routed instead through
        // ActionExecutor::StopAttack() (only if ActiveActionState still
        // provably matches this exact attempt) followed by
        // HandleActionCompletion() with ActionCompletionReason::
        // TargetDefeated, which releases ownership the same way any other
        // non-Arrived HUNT completion already does. A member only
        // Approaching/AtTarget (never Engaging) when its own target
        // happens to die from something else entirely still falls through
        // to the unchanged StoppedByTargetInvalid path below - it never
        // fought it at all, so there is no HUNT success to report.
        void ReconcileActiveHuntTargetsForGroup(AgentGroupRecord const& group);

        // Milestone 2.12F2: the one place a GroupMemberActionProposal
        // (AgentGroupIntentProjector's own output - a group-level intent
        // already decomposed to one individual member, but still only a
        // PROPOSAL, not an authorization - see GroupMemberActionProposal.h)
        // is turned into a real, individually-validated MOVE_TO
        // ActionRequest. Full revalidation, never trusting anything
        // RunCoalitionCoordination() itself already resolved earlier this
        // same pass (a proposal can be several members old by the time
        // this specific one runs):
        //   - proposal.SourceIntent maps to a known GoalType (2.12F2 P3
        //     fix, STATIC review - fail-closed the same way
        //     AgentGroupIntentProjector::Project() itself now is; 2.12G2:
        //     Regroup -> GoalType::Regroup, Roam -> GoalType::Roam, so
        //     ActionRequest::SourceGoal/GroupCoordinationGoal::Type always
        //     honestly name which intent actually produced this proposal,
        //     never hard-coded to Regroup regardless. None/any future/
        //     unrecognized value returns outright - this dispatcher must
        //     never silently start a MOVE_TO for an intent type it does
        //     not yet know how to honestly source-tag).
        //   - proposal.Member still resolves in _registry.
        //   - proposal.SourceGroup still resolves in _groupRegistry, AND
        //     proposal.Member is still actually one of its Members (a leave
        //     that lands between Project() and this call must not dispatch
        //     a movement for a member who already left).
        //   - the member is Materialized with a live, resolvable Creature,
        //     and Alive.
        //   - no higher-priority individual reason to ignore this: neither
        //     ActiveGoalState nor RoutineGoalState set (Regroup/Roam are
        //     the LOWEST tier - see AIWorldMgr::UpdateNeeds()'s own
        //     arbitration comment), and no ActiveActionState already
        //     running (a member already mid-action, of ANY SourceGoal, is
        //     left alone - this pass never preempts anything; only
        //     UpdateNeeds()'s own COORDINATION_PREEMPTED_BY_GOAL/routine-
        //     preemption blocks ever interrupt an in-flight Regroup/Roam,
        //     never the reverse).
        //   - proposal.X/Y/Z is within ActionSystem::CoordinationMoveToRangeYards()
        //     of the member's own actual current position (2.12F2 P3 fix,
        //     round 2, STATIC review - explicit "unreachable coordination
        //     member" semantics). AgentGroupIntentProjector::Project() only
        //     ever compares distance against the matching TRIGGER radius
        //     (profile.RegroupRadius or, since 2.12G2,
        //     profile.RoamArrivalRadius), never against this
        //     execution-layer bound - by design, so the pure projector
        //     never needs to know an ActionSystem constant. This is
        //     deliberately the ONLY place that enforces reachability at
        //     all (2.12F2 P2 fix, round 3, STATIC review):
        //     AIWorld.WolfGroupFormationRadius/AIWorld.WolfGroupLeaveRadius
        //     are NOT clamped against this bound - Formation/Maintenance
        //     is its own capability with its own enable flag, independent
        //     of Coordination's, and must not have its own policy silently
        //     narrowed by a completely different, possibly-disabled
        //     capability's own execution limit (see
        //     AIWorld.WolfGroupLeaveRadius's own Initialize() comment).
        //     AIWorld.WolfGroupRegroupRadius/AIWorld.WolfGroupRoamDistance
        //     are still clamped at Initialize(), since those ARE
        //     Coordination-layer trigger thresholds. So a member can
        //     legitimately remain a group member, or even trigger a
        //     Regroup/Roam intent, from farther away than this dispatcher
        //     can actually reach - that gap is expected, not a
        //     misconfiguration, and this check turns it into a clean,
        //     named "nothing to do" rather than rebuilding and
        //     re-rejecting an identical ActionRequest as DestinationTooFar
        //     every pass, forever.
        //   - (Roam only, 2.12G2 P2 fix, STATIC review) proposal.X/Y
        //     resolves to a real ground point (Map::GetHeight(), reading
        //     only already-loaded grid/vmap data - no force-load) within a
        //     modest vertical sanity bound of the member's own current Z,
        //     AND PathGenerator finds a real navigable path to it
        //     (rejected only on PATHFIND_NOPATH, the same convention
        //     MoveSplineInit.cpp/ChaseMovementGenerator.cpp already use -
        //     PATHFIND_INCOMPLETE is still accepted, a real partial path,
        //     not a straight-line fallback). Regroup is NOT put through
        //     this - its own target is TerritoryX/Y/Z, a real,
        //     previously-occupied location, never a synthesized one the
        //     way a Roam target (a deterministic compass offset
        //     AgentGroupIntentSystem computes with no Map access at all)
        //     is. Needed because ActionSystem::ValidateMoveTo() never
        //     checks navigability, only map/finite-coordinates/distance,
        //     and MotionMaster::MovePoint()'s own PathGenerator use is NOT
        //     fail-closed - a PATHFIND_NOPATH result still falls back to a
        //     straight two-point spline to the raw coordinates
        //     (MoveSplineInit::MoveTo()), which could walk a member
        //     through a wall, off a cliff, or under/above the terrain,
        //     and would still eventually fire an ordinary arrival
        //     completion. The resolved ground Z (not proposal.Z) is what
        //     actually becomes this dispatch's own Destination.
        // On every rejection above, this simply returns - no log spam for
        // what is an expected, frequent outcome (most members most passes
        // are not eligible), the same restraint RunCoalitionMaintenanceForGroup()
        // already shows for its own None decision.
        //
        // Sets record->GroupCoordinationGoalState BEFORE calling
        // ActionSystem::Validate() (the same order UpdateNeeds()'s own
        // RoutineGoal MOVE_TO dispatch already uses, so Validate()'s
        // ActiveGoalType/ActiveGoalStartedAtMs context can honestly name
        // this attempt), and clears it again immediately if Validate()
        // rejects or ExecuteMoveTo() fails to actually start - a
        // GroupCoordinationGoalState must never survive naming an attempt
        // that never actually became a running ActiveActionState (see
        // GroupCoordinationGoal.h for why this differs from RoutineGoalState,
        // which is stateless and needs no such rollback).
        void DispatchGroupMemberActionProposal(GroupMemberActionProposal const& proposal);

        // Milestone 2.12G3C2: the HUNT counterpart to
        // DispatchGroupMemberActionProposal() - turns a HuntProposal
        // (HuntIntentProjector's own output, still only a proposal, never
        // an authorization) into a real, individually-validated MOVE_TO
        // ActionRequest, revalidating everything fresh rather than
        // trusting anything resolved earlier this same pass. Fail-closed
        // order: proposal.Member resolves in _registry; the member is
        // AIWorldControlled; proposal.SourceGroup resolves in
        // _groupRegistry; that group has no lifecycle operation currently
        // pending (2.12G3C2's own extra defense-in-depth check - unlike
        // DispatchGroupMemberActionProposal(), which relies entirely on
        // RunCoalitionCoordination()'s own upstream discovery-time filter);
        // proposal.Member is still actually one of the group's Members;
        // the group's own profile still resolves and still has HuntEnabled;
        // the member is Materialized; no ActiveGoalState/RoutineGoalState
        // (HUNT is the same LOWEST tier as Regroup/Roam); no
        // ActiveActionState already running; and no GroupCoordinationGoalState
        // already owning a DIFFERENT attempt (a different group/target/
        // StartedAtMs, or this exact attempt while still Approaching -
        // ActiveActionState's own check above should already have caught
        // that, but this is re-verified independently, never assumed).
        // Milestone 2.12G3D2A: a GroupCoordinationGoalState for THIS EXACT
        // attempt while HuntPhase::AtTarget is the one case that is NOT an
        // outright reject - see this method's own header comment below for
        // the re-approach rule that governs it instead. HUNT's own
        // GroupCoordinationGoalState carries target identity that must
        // never be silently overwritten by anything else. The member does
        // not structurally belong to more than one
        // coordination-enabled group (CountCoordinationEnabledMemberships(),
        // re-checked here too, never trusting that
        // RunCoalitionCoordination()'s own upstream arbitration still
        // holds by the time this specific proposal runs); the member's own
        // live Creature resolves and is alive; the proposal's own claimed
        // target resolves live by its exact TargetGuid
        // (ObjectAccessor::GetCreature(), never a force-load) and is
        // alive; that live target's own Entry/MapId honestly match the
        // proposal's own claimed Target.TargetEntry/Target.MapId; the
        // target is not the member itself; the target is still
        // IsValidAttackTarget() for this member; the target's live
        // position is loaded into locals and confirmed finite (2.12G3C2 P2
        // fix, STATIC review: BEFORE any distance/LOS/PathGenerator/
        // Destination use - an earlier version called IsWithinLOS() and
        // computed distance against the live target directly, checking
        // isfinite() only afterward);
        // (2.12G3D2A) if this member's own GroupCoordinationGoalState
        // already names THIS EXACT attempt in HuntPhase::AtTarget, this is
        // only a genuine re-approach - not an ALREADY_AT_TARGET reject -
        // if the member's own live position is no longer within
        // ArrivalToleranceYards (ArrivalTolerance.h - the same shared
        // tolerance MOVE_TO arrival/Eat/Work-Rest already use) of the
        // target's own live position; never re-dispatched while still
        // effectively standing at it; the member's own live distance to
        // the target is within profile.HuntAcquisitionRadius AND within
        // ActionSystem::CoordinationMoveToRangeYards() (the same
        // UNREACHABLE semantics DispatchGroupMemberActionProposal() already
        // established, applied against the target's live position rather
        // than a fixed proposal point); the member has line-of-sight to
        // the target's live position; and PathGenerator finds a real
        // navigable path to it (PATHFIND_NOPATH only - the same convention
        // Roam's own dispatch-time path check already uses).
        //
        // The MOVE_TO Destination built from all of this is the target's
        // ACTUAL CURRENT position (live Creature::GetPosition*()), never
        // proposal.Target.X/Y/Z - those came from a HuntTargetObservation
        // that can already be stale by the time this runs; only the live,
        // just-reconfirmed position is ever actually moved toward.
        // ActionRequest::SourceGoal/GoalStartedAtMs are GoalType::Hunt/
        // proposal.StartedAtMs (the group-wide HUNT ATTEMPT's own stable
        // identity - deliberately NOT a fresh per-dispatch CurrentTimeMs()
        // the way Regroup/Roam use, so every member subsequently dispatched
        // into the SAME ongoing attempt, across however many
        // RunCoalitionCoordination() passes it spans, gets the exact same
        // StartedAtMs - see ResolveHuntIntentForGroup()'s own comment for
        // why that stability is what lets it recognize them all as one
        // attempt rather than reporting a false ambiguity). Sets
        // record->GroupCoordinationGoalState (Type/SourceGroup/StartedAtMs/
        // TargetGuid/TargetEntry/TargetObservedAtMs, the latter from
        // proposal.Target.ObservedAtMs, and Phase always explicitly reset
        // to HuntPhase::Approaching - 2.12G3D2A, even on the re-approach
        // path, which may be overwriting an existing AtTarget-phase state)
        // BEFORE calling ActionSystem::Validate(), the same order/
        // rollback-on-rejection discipline DispatchGroupMemberActionProposal()
        // already holds to. On a successfully started MOVE_TO, the
        // resulting ActiveAction also carries Target (2.12G3C2 P2 fix,
        // STATIC review: the same ActionTargetRef the request itself
        // used) - see ActiveAction::Target's own comment for why a HUNT
        // completion needs this to verify target identity, not just
        // goal-attempt identity, before treating it as owned by the
        // current attempt.
        //
        // Milestone 2.12G3D1 diagnostic-only addition (STATIC review),
        // extended 2.12G3D2A: if this specific proposal.Member is the one
        // AgentId currently watched by AIWorld.TestObserveActiveHuntAgentId,
        // every early return above also logs "stage=DISPATCH
        // result=REJECTED reason=<...>" naming exactly which fail-closed
        // check rejected it - one of AGENT_MISSING/CONTROL_MODE/
        // GROUP_MISSING/LIFECYCLE_PENDING/NOT_MEMBER/PROFILE_DISABLED/
        // ACTOR_NOT_MATERIALIZED/ACTIVE_GOAL/ROUTINE_GOAL/ACTIVE_ACTION/
        // COORDINATION_GOAL/MEMBERSHIP_AMBIGUOUS/ACTOR_UNRESOLVED_OR_DEAD/
        // TARGET_UNRESOLVED_OR_DEAD/TARGET_IDENTITY_MISMATCH/SELF_TARGET/
        // TARGET_NOT_ATTACKABLE/TARGET_POSITION_INVALID/
        // ALREADY_AT_TARGET (2.12G3D2A - AtTarget for this exact attempt
        // and still within ArrivalToleranceYards of the target, so no
        // re-approach is warranted yet)/TARGET_OUT_OF_RANGE/TARGET_NO_LOS/
        // TARGET_NO_PATH; and (2.12G3D2A, its own separate log line, not a
        // rejection) "stage=REAPPROACH result=APPROACHING" when a genuine
        // re-approach for the SAME attempt actually proceeds. 2.12G3D2A
        // also drops this diagnostic's own former dependency on
        // !_testObserveActiveHuntFired - that latch is specific to
        // CheckTestObserveActiveHunt()'s own one-shot proof, which fires
        // well before arrival/re-approach could ever be observed. Purely
        // read-only logging either way - never changes which branch is
        // taken, never mutates record/anything else, and never itself
        // sets _testObserveActiveHuntFired (only CheckTestObserveActiveHunt()
        // does that, on a genuine full PASS).
        void DispatchHuntProposal(HuntProposal const& proposal);

        // Milestone 2.12G3D: the combat counterpart to DispatchHuntProposal()
        // above - dispatches ActionType::Attack (never MoveTo) for a member
        // whose GroupCoordinationGoalState is already Type == GoalType::Hunt,
        // SourceGroup == sourceGroup, and Phase == HuntPhase::AtTarget, with
        // no ActiveActionState of its own yet. Called from
        // RunCoalitionCoordination()'s own per-group loop, once per such
        // member, only while profile->HuntEnabled (the same gate MOVE_TO
        // dispatch already requires) - never for Approaching (still has an
        // ActiveActionState, rejected by the same ACTIVE_ACTION check
        // DispatchHuntProposal() itself uses) or already-Engaging members
        // (the caller's own loop filter excludes Phase != AtTarget, so this
        // is never even called for them - "do not repeatedly call
        // AttackStart() every coordination pass" is enforced structurally,
        // by never re-entering this function for a member that already has
        // an Attack-type ActiveActionState, not by a special-cased skip
        // inside it).
        //
        // Re-verifies membership/lifecycle/materialized/alive/target
        // identity/attackability/self-or-group-member independently here -
        // never trusts the retained GroupCoordinationGoal alone, the same
        // "never assume, always check" discipline DispatchHuntProposal()
        // already holds to for its own re-approach path. Unlike
        // DispatchHuntProposal(), never needs a previousCoordinationGoal
        // rollback-on-failure: this method only ever mutates
        // GroupCoordinationGoalState::Phase (Approaching/AtTarget ->
        // Engaging) and sets ActiveActionState AFTER Validate()/
        // ActionExecutor::ExecuteAttack() both already confirmed success -
        // there is nothing to roll back on a rejected/failed attempt, the
        // member simply stays AtTarget and is reconsidered next pass.
        //
        // Milestone 2.12G3D P2 fix (STATIC review): also freshly resolves
        // the target's own CURRENT live distance/line-of-sight here and
        // passes both into ActionValidationContext::TargetWithinAttackRange/
        // TargetInLineOfSight - HuntPhase::AtTarget alone (a retained
        // value with no live position of its own) is never trusted as
        // proof the target is still actually reachable for melee; if
        // either fails, ValidateAttack() rejects and this member simply
        // stays AtTarget - DispatchHuntProposal()'s own existing
        // re-approach path (a fresh HuntProposal for the same pinned
        // attempt, if one is produced this or a later pass) is what closes
        // the distance again, this method never re-approaches on its own.
        //
        // Idempotency: if the actor's own current live victim
        // (Unit::GetVictim()) already equals the pinned target, this is
        // treated as already validly Engaging - Validate() still runs (the
        // authoritative safety gate is never skipped), but
        // ActionExecutor::ExecuteAttack() itself is not called again (see
        // ActionValidationContext::ActorCurrentVictimGuid's own comment for
        // why this is allowed rather than rejected) - only
        // ActiveActionState/Phase bookkeeping is (re)applied. This is a
        // defensive-in-depth case (a genuinely fresh dispatch can only ever
        // reach this function once per Engaging transition, by the caller's
        // own loop filter above), covering a hypothetical bookkeeping/engine
        // desync (e.g. ActiveActionState reconciled away while the live
        // Creature is still actually mid-combat) the same paranoid way
        // ActionCompletionReason::EngineStopped already covers the
        // equivalent desync for MOVE_TO.
        //
        // Diagnostic-only: gated on AIWorld.TestObserveActiveHuntAgentId,
        // the same one-watched-agent, purely-read-only, never-state-
        // affecting logging pattern every other HUNT dispatch stage already
        // uses - "stage=ATTACK result=REJECTED reason=<...>" on an early
        // return, or "stage=ATTACK result=STARTED|ALREADY_ENGAGED" on
        // success.
        void DispatchHuntAttack(AgentId member, GroupId sourceGroup);
        bool IsLivingWolf(AgentRecord const& record) const;
        void UpdateLivingWolf(AgentRecord& record, Creature& creature, uint64 nowMs);
        void StopLivingWolfAction(AgentRecord& record, Creature& creature);
        bool _livingWolvesEnabled = false;

        // Milestone 2.12F2 P2 fix, round 4 (STATIC review): how many
        // currently-registered groups member belongs to whose own resolved
        // profile has RegroupEnabled, RoamEnabled, or (2.12G3C2) HuntEnabled -
        // the one shared definition of "coordination-ambiguous membership"
        // both RunCoalitionCoordination()'s own overlap arbitration (for
        // Regroup/Roam AND Hunt proposals alike) and
        // ReconcileGroupCoordinationForMember() now use, via
        // AgentGroupRegistry::GetGroupsOfMember() (O(k) where k is however
        // many groups member is actually in, almost always 0 or 1 - see
        // that method's own comment). Deliberately an OR across all three
        // capabilities, not any one alone - see this method's own
        // definition for why scoping this safety net to only the
        // capabilities that existed when it was first written would leave
        // a real gap the moment a new one is added.
        uint32 CountCoordinationEnabledMemberships(AgentId member) const;

        // Milestone 2.12G2 P2 fix (STATIC review): whether ANY current
        // member of group still has an in-flight ROAM attempt SOURCED
        // FROM THIS GROUP - GroupCoordinationGoalState set, Type ==
        // GoalType::Roam, SourceGroup == group.Id. Used by
        // RunCoalitionCoordination() to decide whether this pass's own
        // Evaluate() call for this group must keep using the pinned nowMs
        // from _roamAttemptPinnedNowMs (so every member converges on the
        // SAME phase's target) or is free to use the real current nowMs
        // (the group's previous attempt has fully concluded - see
        // _roamAttemptPinnedNowMs's own declaration comment for the exact
        // race this closes). O(group size), the same cost
        // CollectCoalitionMemberObservations() already pays for this same
        // group this same pass.
        bool HasInFlightRoamAttempt(AgentGroupRecord const& group) const;

        // Milestone 2.12F2 P2 fix, round 4 (STATIC review): the shared
        // mechanics both StopGroupCoordinationForMember() and
        // ReconcileGroupCoordinationForMember() need - captures
        // record.GroupCoordinationGoalState's OWN identity in full
        // (Type/SourceGroup/StartedAtMs/TargetGuid/TargetEntry) before
        // unconditionally clearing it, then records a CoordinationStopEvent
        // sourced entirely from that captured value - never from
        // record.ActiveActionState (2.12G3D2A P2 fix, STATIC review: an
        // earlier version sourced SourceGoal/StartedAtMs from
        // ActiveActionState and returned WITHOUT recording anything at all
        // if it was absent, which silently dropped provenance for
        // HuntPhase::AtTarget - 2.12G3D2A - a member can legitimately own
        // an attempt with NO ActiveActionState at all, since nothing is
        // currently running; target-invalid/leave/dissolve/preemption
        // stopping such a member must still honestly record WHAT was
        // stopped). The ownership invariant Dispatch*Proposal() already
        // establishes - both fields, whenever they coexist, always agree
        // on Type/StartedAtMs - means this is always at least as correct
        // for Regroup/Roam (which never have an AtTarget-equivalent state)
        // as the old ActiveActionState-sourced version.
        //
        // Milestone 2.12G3D2A P2 fix, round 2 (STATIC review): the engine
        // is now only ever touched (StopMoveTo(), engine-generator
        // observation, ActiveActionState reset) when an explicit
        // ownsStoppedMovement check confirms record.ActiveActionState is
        // an EXACT match for the captured GroupCoordinationGoal - same
        // ActionType::MoveTo, same SourceGoal, same GoalStartedAtMs, and
        // for GoalType::Hunt additionally the same live Target
        // Guid/Entry. An earlier version called StopMoveTo() unconditionally
        // for any Materialized member with a coordination-sourced goal,
        // regardless of whether the CURRENT ActiveActionState actually
        // belonged to it - since ActionExecutor::StopMoveTo() recognizes
        // only the shared AIWorld MovePointId, not the source goal, this
        // could silently stop an unrelated action already in flight for
        // the same agent (e.g. GetFood dispatched after this coordination
        // attempt reached HuntPhase::AtTarget), while that unrelated
        // ActiveActionState was left claiming to still be running.
        // ownsStoppedMovement is false (engine left untouched, both
        // engine-generator fields honestly read false/false, and
        // ActiveActionState left alone) both for a true HuntPhase::AtTarget
        // member (no ActiveActionState at all) and for a member whose
        // ActiveActionState belongs to a different attempt entirely -
        // ownership removal and CoordinationStopEvent recording still
        // happen unconditionally in both cases. reason is a literal
        // describing WHY this particular caller stopped it, logged the
        // same way - callers never share one generic reason string.
        //
        // Milestone 2.12G3D: ownsStoppedMovement now also accepts
        // ActionType::Attack, not just MoveTo - a HuntPhase::Engaging
        // member's own ActiveActionState is Attack, and the engine touch
        // itself is type-dispatched (ActionExecutor::StopAttack(), never
        // StopMoveTo(), for that case) - StopMoveTo() recognizes only its
        // own POINT_MOTION_TYPE generator and would silently do nothing
        // for a member that is actually mid-combat. The engine-generator
        // observation fields are likewise type-dispatched (HasOwnAttackEngagement()
        // in place of HasOwnMoveToGenerator()) rather than reused as-is,
        // since "engine activity for this attempt" means a live victim
        // match for Attack, not a movement generator.
        //
        // Milestone 2.12G2R P2 fix, round 3 (STATIC review): stopReason is
        // a SEPARATE, structured counterpart to the free-text `reason`
        // above, recorded into AgentRecord::LastCoordinationStop
        // (CoordinationStopEvent.h) - this method is shared by two
        // genuinely different callers (StopGroupCoordinationForMember(),
        // a confirmed Leave/Dissolve; ReconcileGroupCoordinationForMember(),
        // a confirmed Join making membership newly ambiguous), and an
        // earlier version always recorded CoordinationStopReason::
        // StoppedByLifecycle regardless of which one actually called it -
        // a verifying test hook waiting specifically for a Leave/Dissolve-
        // sourced stop could then have accepted a membership-ambiguity
        // stop as false evidence of the wrong production path. Each
        // caller now passes its own distinct reason explicitly.
        void StopInFlightGroupCoordination(AgentRecord& record, char const* reason, CoordinationStopReason stopReason);

        // Milestone 2.12G3 lifecycle closure P3 fix (STATIC review):
        // extracted from UpdateNeeds()'s own inline COORDINATION_PREEMPTED_BY_GOAL
        // block, purely so this can be exercised directly by a pure
        // value-state smoke test the same way StopInFlightGroupCoordination()
        // already is - no production behavior change from the extraction
        // itself. Self-guarding: a no-op unless (record.ActiveGoalState ||
        // record.RoutineGoalState) && record.GroupCoordinationGoalState &&
        // IsCoordinationSourceGoal(record.GroupCoordinationGoalState->Type)
        // - an agent's own individual/routine goal taking the action slot
        // back from an automatic group nudge (Regroup/Roam/Hunt).
        //
        // Self-contained the same way StopInFlightGroupCoordination() is:
        // resolves its own Map*/Creature* internally from record.WorldState/
        // record.MapId/record.SpawnId, rather than requiring the caller to
        // already have one - which is what lets a synthetic, non-Materialized
        // AgentRecord (WorldState left at its own Abstract default) exercise
        // the full ownsAction/CoordinationStopEvent logic below purely, the
        // engine-touch block simply never reached for it.
        //
        // The engine (StopAttack()/StopMoveTo(), type-dispatched) is only
        // ever touched when record.ActiveActionState is an EXACT match for
        // record.GroupCoordinationGoalState - the same ownsStoppedMovement
        // discipline StopInFlightGroupCoordination() itself already
        // established (Type+SourceGoal+GoalStartedAtMs, plus Target
        // Guid/Entry for HUNT) - never assumed just because a coordination-
        // sourced ActiveActionState happens to exist. False for a true
        // HuntPhase::AtTarget member (no ActiveActionState at all, the exact
        // gap this extraction closes) and for a member whose
        // ActiveActionState belongs to a different attempt/target entirely -
        // both correctly skip every engine touch, with both engine-generator
        // fields honestly read false/false, and record.ActiveActionState
        // itself left completely untouched. record.GroupCoordinationGoalState
        // is always cleared regardless (this attempt's own group ownership
        // ends either way), and LastCoordinationStop's SourceGoal/SourceGroup/
        // StartedAtMs/TargetGuid/TargetEntry are always sourced from
        // GroupCoordinationGoalState, never from ActiveActionState, so the
        // event still records honestly even when there was nothing to stop.
        //
        // PreemptingOwner/PreemptingGoal capture WHICH of ActiveGoalState/
        // RoutineGoalState actually did the preempting (ActiveGoalState
        // takes precedence when both happen to be set, matching this
        // method's own self-guard OR and this file's own established
        // ActiveGoalState > RoutineGoalState arbitration) - captured
        // synchronously, so a verifying test hook never has to re-derive
        // "what preempted this" from AgentRecord's own CURRENT state on a
        // later poll. nowMs is the caller's own shared tick timestamp
        // (UpdateNeeds()'s own nowMs), not a fresh CurrentTimeMs() call
        // here, so every stop event recorded this same tick agrees.
        void PreemptInFlightGroupCoordination(AgentRecord& record, uint64 nowMs);

        // Milestone 2.12F2 P2 fix (STATIC review): the one place an
        // in-flight Regroup/Roam attempt (AgentRecord::
        // GroupCoordinationGoalState/ActiveActionState) is stopped because
        // its OWNING GROUP changed underneath it, not because a
        // higher-priority individual goal preempted it (see UpdateNeeds()'s
        // own COORDINATION_PREEMPTED_BY_GOAL block for that other case).
        // GroupCoordinationGoal.h's own class comment previously documented
        // this as a deliberate non-goal ("a dissolve/leave that happens
        // while this attempt is already moving simply lets the movement
        // run to its own natural conclusion") - STATIC review correctly
        // identified that as a real bug, not a deliberate simplification:
        // a confirmed Leave/Dissolve for groupId must stop any member
        // still actively moving toward that now-former group's own
        // territory/roam target, or the movement completes as a stale
        // group-owned action with no group behind it any more.
        //
        // A no-op if memberId has no GroupCoordinationGoalState at all, or
        // one whose SourceGroup names a different group (an agent can only
        // ever have one in flight at a time - see DispatchGroupMemberActionProposal()'s
        // own ActiveActionState check). Called from RequestDissolveGroup()'s
        // own confirmed-dissolve completion (for every FORMER member,
        // captured before the dissolve was ever submitted - see that
        // method's own comment for why membership cannot have changed in
        // the meantime) and from RequestLeaveGroupWithPolicy()'s own
        // confirmed-leave completion (for the one member who just left).
        void StopGroupCoordinationForMember(AgentId memberId, GroupId groupId);

        // Milestone 2.12F2 P2 fix, round 4 (STATIC review): the Join-side
        // counterpart to StopGroupCoordinationForMember() - a confirmed
        // Join, unlike a confirmed Leave/Dissolve, can newly CREATE
        // coordination ambiguity for memberId (a second coordination-
        // enabled group now claims it - see
        // CountCoordinationEnabledMemberships()) while a Regroup/Roam
        // dispatched before this join, back when membership was still
        // unambiguous, may still be actively running. Without this,
        // RunCoalitionCoordination()'s own overlap-arbitration rule would
        // only ever apply to NEW dispatches - an already in-flight action
        // would keep running to its own natural conclusion purely because
        // it started before the join confirmed, an implicit "whoever got
        // there first keeps it" priority the arbitration rule exists
        // specifically to remove. Deliberately generic - this only ever
        // asks AgentGroupRegistry/CountCoordinationEnabledMemberships() "is
        // this membership still unambiguous", never anything about
        // WolfLoose/DefiasLoose or any other specific profile - so a
        // future third coordination-enabled profile needs no change here.
        //
        // A no-op if memberId has no GroupCoordinationGoalState at all (the
        // overwhelmingly common case - most joins never race an in-flight
        // Regroup/Roam) or if CountCoordinationEnabledMemberships() still
        // resolves to at most 1 (the join did not actually create
        // ambiguity - e.g. the newly-joined group's own profile has both
        // RegroupEnabled and RoamEnabled false). Called only from
        // RequestJoinGroupWithPolicy()'s own confirmed-join completion -
        // deliberately not placed inside AgentGroupLifecycleSystem itself,
        // which has (and must keep) no knowledge of
        // AgentGroupCoordinationProfile/RegroupEnabled/RoamEnabled; this is
        // AIWorldMgr's own post-confirmation orchestration, the same layer
        // StopGroupCoordinationForMember() already lives at.
        void ReconcileGroupCoordinationForMember(AgentId memberId);

        bool _enabled = false;

        // Milestone 2.10A/2.10B: how often RunDecisionScheduler() itself
        // runs - not every tick (GetAgents() allocates, so this avoids
        // paying that cost every single world tick the way
        // _needsUpdateTimer/_nearbyPerceptionTimer already don't either),
        // and deliberately faster than either per-agent decision interval
        // below (AIWorld.DecisionSchedulerIntervalMs, default 250ms) - see
        // RunDecisionScheduler()'s own comment for why scheduler-poll
        // cadence and per-agent decision cadence are two different things.
        uint32 _decisionSchedulerIntervalMs = 250;
        uint32 _decisionSchedulerTimer = 0;

        // Milestone 2.10B: per-agent decision interval, chosen fresh each
        // pass by DecisionCadenceClass (see RunDecisionScheduler()) rather
        // than one interval for every agent - Nearby (a real Player within
        // _decisionNearbyPlayerRange right now) gets faster decisions than
        // Active (everyone else materialized).
        uint32 _decisionNearbyIntervalMs = 1000;
        uint32 _decisionActiveIntervalMs = 5000;
        float _decisionNearbyPlayerRange = 60.0f;

        // Registry of persistent agents - survives its Creature being
        // unloaded/reloaded; only ProcessAgent()'s Bind/UnbindCreature calls
        // change an agent's WorldState. Purely in-memory; rebuilt from
        // _persistence every startup.
        AgentRegistry _registry;

        // characters-DB authority for AgentId (Milestone 2.2A): _registry
        // never mints an id itself, only ever receives one already assigned
        // by this. Used exclusively during Initialize(), never per-tick.
        AgentPersistence _persistence;

        // AI WorldFactionId catalog (data/elwynn/factions/README.md) - one
        // world DB read at Initialize(), before RunSpawnReconciliation()
        // first needs it, then read-only for the rest of this process's
        // lifetime. RunSpawnReconciliation() is the only caller: it resolves
        // each Missing entry's own WorldFaction through this when building
        // PendingCreatureAgent, and separately refreshes any already-valid
        // agent whose stored world_faction_id has drifted from what this
        // catalog now says.
        WorldFactionCatalog _worldFactionCatalog;

        // AgentType identity fix (AIWorld_Current_Roadmap.md, Etapa 3) - one
        // world DB read at Initialize(), same lifecycle as
        // _worldFactionCatalog above. RunSpawnReconciliation() is the only
        // caller: it resolves each Missing entry's own AgentType through
        // this when building PendingCreatureAgent, and separately refreshes
        // any already-valid agent whose stored agent_type has drifted from
        // what this catalog now says.
        AgentTypeCatalog _agentTypeCatalog;

        // Runtime participation/scope boundary fix (AIWorld_Current_
        // Roadmap.md, Etapa 3) - one world DB read at Initialize(), same
        // lifecycle as _worldFactionCatalog/_agentTypeCatalog above.
        // RunSpawnReconciliation() is the only caller: an Excluded
        // (EXCLUDED_EVENT) SpawnId is never turned into a new permanent
        // agent, and any already-physical row for one is quarantined from
        // _registry (never a DB write) - see SpawnReconciliationPlan::
        // ExcludedButBound/ExcludedSkippedCount for the actual boundary.
        SpawnParticipationCatalog _spawnParticipationCatalog;

        // WorldFactionRelationCatalog vertical slice (AIWorld_Current_
        // Roadmap.md) - one world DB read at Initialize(), same lifecycle
        // as the catalogs above. Deliberately has NO caller yet: this is
        // only the static WorldFaction <-> WorldFaction diplomacy layer,
        // loaded and ready to Resolve() - player membership, the
        // TrinityCore ReputationMgr bridge, and any combat/behavior
        // decision built on top of it are separate, later steps. Loading
        // it unconditionally now (rather than only once a consumer exists)
        // matches _worldFactionCatalog/_agentTypeCatalog's own precedent.
        WorldFactionRelationCatalog _worldFactionRelationCatalog;

        // Player WorldFaction membership vertical slice (AIWorld_Current_
        // Roadmap.md) - unlike every catalog above, this is stateless (no
        // Load(), nothing to initialize): every method is an independent,
        // on-demand characters-DB query keyed by ObjectGuid, never a bulk
        // startup load. Held here purely as a convenient, uniform access
        // point (the same reason _persistence exists) - deliberately no
        // caller yet, same as _worldFactionRelationCatalog.
        PlayerWorldFactionPersistence _playerWorldFactionPersistence;

        // WorldFactionId -> Trinity Faction.dbc id bridge table
        // (AIWorld_Current_Roadmap.md, login/allegiance-change ReputationMgr
        // bridge) - one world DB read at Initialize(), same lifecycle as the
        // catalogs above. No caller yet, same "load the layer before a
        // consumer exists" precedent _worldFactionRelationCatalog already
        // set - the login/allegiance-change bridge that actually consumes
        // this is a separate, later step.
        WorldFactionReputationCatalog _worldFactionReputationCatalog;

        // Milestone 2.12D (STATIC review P2 fix): registry of persistent
        // AgentGroups - deliberately its own registry/GroupId identity
        // space, not part of _registry/AgentId any more (see GroupId.h for
        // why the old shared-identity model was wrong). Purely in-memory;
        // rebuilt from _groupPersistence every startup, after _registry
        // itself (LoadGroupMembers() needs both already populated).
        AgentGroupRegistry _groupRegistry;

        // characters-DB authority for GroupId - the group-side counterpart
        // to _persistence, see AgentGroupPersistence's own class comment
        // for why this is a separate class rather than folded into
        // AgentPersistence.
        AgentGroupPersistence _groupPersistence;

        // Milestone 2.12E1: the single owner of AgentGroup create/join/
        // leave/dissolve - see its own class comment. Stateless (every
        // dependency is a parameter), so this is just a stable place to
        // call through rather than constructing one per call; no different
        // in spirit from _agentGroupSimulationSystem below.
        AgentGroupLifecycleSystem _groupLifecycleSystem;

        // Milestone 2.12E2: every AgentGroupPersistence async write's
        // TransactionCallback lands here (via _groupLifecycleSystem's own
        // Request* methods) and is polled once per world tick in Update()
        // - the same "enqueue, poll every Update()" shape
        // World::_queryProcessor already uses for QueryCallback. A
        // completion only ever runs from inside that poll, so it is always
        // world-thread-only.
        TransactionCallbackProcessor _groupLifecyclePending;

        // Milestone 2.12E3A/2.12E3B: "is this socially allowed?" - see its
        // own class comment for why this is a separate question from
        // everything _groupLifecycleSystem already answers. Pure/stateless
        // like _groupLifecycleSystem, called only from
        // RequestJoinGroupWithPolicy()/RequestLeaveGroupWithPolicy() below
        // (and the smoke test) - _groupLifecycleSystem's own Request*
        // methods are never called directly by anything else in this file
        // any more once 2.12E3B's own automatic-policy callers exist,
        // though 2.12E2's own lifecycle-only smoke test still does, since
        // it is deliberately testing the seam one layer below this one.
        AgentGroupPolicySystem _groupPolicySystem;

        // Milestone 2.12E3B: loaded and clamped once at Initialize() from
        // AIWorld.Loose/StableGroupMin/MaxMembers - see
        // AgentGroupPolicyConfig.h for why _groupPolicySystem itself never
        // reads config directly. Copied into a fresh AgentGroupPolicyContext
        // for every CanJoin()/CanLeave()/ShouldDissolve() call rather than
        // referenced, the same reasoning AgentGroupPolicyContext.h's own
        // comment gives.
        AgentGroupPolicyConfig _groupPolicyConfig;

        // Milestone 2.10A: deterministic admission ranking over every
        // registered+Materialized agent - see DecisionScheduler.h. Pure
        // value transform, like _needsSystem/_goalSystem/_actionSystem;
        // RunDecisionScheduler() is the one place that resolves live
        // Creatures/AgentRecords and drives it.
        DecisionScheduler _decisionScheduler;

        // Per-agent scheduling bookkeeping (LastDecisionSubmittedAtMs/
        // AwaitingResponse) for _decisionScheduler - deliberately not part
        // of AgentRecord/AgentRegistry, see DecisionScheduleState.h. Keyed
        // by AgentId::Value.
        std::unordered_map<uint64, DecisionScheduleState> _decisionSchedule;

        // Milestone 2.10C: last SimulationTier observed for each registered
        // agent - deliberately not part of AgentRecord/AgentRegistry either
        // (a tier transition must never disturb AgentId/Needs/memories/
        // goal state, only ever log against it), purely so
        // UpdateSimulationTier() can tell a real transition apart from an
        // unchanged tier. Keyed by AgentId::Value; an agent with no entry
        // yet is logged as an initial assignment, not a "from" transition.
        std::unordered_map<uint64, SimulationTier> _agentSimulationTier;

        // Milestone 2.10D: coarse Background tick cadence
        // (AIWorld.BackgroundSimulationIntervalMs, default 60s) - not a
        // decision cadence, deliberately much coarser. See
        // RunDecisionScheduler()'s own comment for why this stays a pure
        // observability scaffold in 2.10D - no live Creature/Map lookup,
        // no /decision, no ActionExecutor, no gameplay state change.
        uint32 _backgroundSimulationIntervalMs = 60000;

        // Milestone 2.12D P2 fix (STATIC review): the group coarse-tick
        // cadence (AIWorld.GroupSimulationIntervalMs, default 5min) -
        // renamed from _abstractSimulationIntervalMs now that groups no
        // longer go through SimulationTier::Abstract at all (that tier is
        // gone - see SimulationTier.h). Governs how often
        // RunDecisionScheduler()'s own group coarse-tick loop below
        // simulates each AgentGroup.
        uint32 _groupSimulationIntervalMs = 300000;

        // Milestone 2.10D P2 fix: deterministic bounded admission for the
        // Background coarse tick, the exact same reason _decisionScheduler/
        // _decisionMaxInFlight exist for the decision-eligible tiers - see
        // CoarseSimulationScheduler.h for why an unbounded coarse tick
        // would both spike world-thread work and permanently phase-lock
        // every Background agent onto the same tick pass. AgentId-only -
        // the group coarse tick below has its own GroupId-keyed sibling
        // instead, see _groupCoarseSimulationScheduler.
        CoarseSimulationScheduler _coarseSimulationScheduler;
        uint32 _coarseSimulationMaxPerPass = 50;

        // Per-agent bookkeeping for the Background coarse tick above -
        // deliberately not part of AgentRecord/AgentRegistry, see
        // SimulationScheduleState.h. Keyed by AgentId::Value; never
        // touched for a Materialized (Active/Nearby) agent.
        std::unordered_map<uint64, SimulationScheduleState> _simulationSchedule;

        // Milestone 2.12D P2 fix (STATIC review): the group coarse tick's
        // own bounded admission, GroupId's sibling to
        // _coarseSimulationScheduler/_coarseSimulationMaxPerPass above - an
        // earlier version of this same milestone ticked every due
        // AgentGroup unconditionally on the assumption that group
        // cardinality would stay small; rejected by review once dynamic
        // LOOSE coalitions (which do not have a fixed, small population
        // the way scripted/STABLE groups do) entered the picture. See
        // GroupCoarseSimulationScheduler.h for the full reasoning.
        GroupCoarseSimulationScheduler _groupCoarseSimulationScheduler;
        uint32 _groupSimulationMaxPerPass = 50;

        // Per-group bookkeeping for the group coarse tick above -
        // deliberately not part of AgentGroupRecord/AgentGroupRegistry, see
        // SimulationScheduleState.h (its own comment on why it is reused
        // unmodified here). Keyed by GroupId::Value.
        std::unordered_map<uint64, SimulationScheduleState> _groupSimulationSchedule;

        // Milestone 2.12E4C2 P2 fix, round 3 (STATIC review): GroupId::Value
        // entries with a RunGroupProfileAdoption() write currently
        // in flight - the group coarse tick's own resource-drift loop
        // below (RunDecisionScheduler()) skips a group entirely (Update()/
        // SaveGroupState() both, schedule state left untouched so it stays
        // due and is retried the very next pass) while its GroupId is in
        // this set. Without this, AgentGroupPersistence::AdoptGroupProfileAsync()'s
        // own targeted "SET profile_id = ? WHERE group_id = ?" and
        // SaveGroupState()'s own whole-row "SET ..., profile_id = ?,
        // version = ? WHERE group_id = ? AND version < ?" (built from
        // whatever AgentGroupRecord::ProfileId the RAM copy still held
        // BEFORE the adoption's own completion updates it) can commit in
        // either order - both are individually valid UPDATEs the DB
        // reports as successful, but if SaveGroupState()'s commits second,
        // it silently overwrites the just-adopted profile_id back to its
        // old (pre-adoption) value, and the adoption's own already-logged
        // "PASSED" (RAM now says adopted) no longer matches what the DB
        // holds - exactly the persistence/provenance divergence the
        // confirmed-write fix (round 2) was meant to close, reintroduced
        // by a second, uncoordinated write path to the same column.
        // Inserted right before RunGroupProfileAdoption() submits its own
        // AdoptGroupProfileAsync() call, erased unconditionally at the top
        // of that call's own completion (success or failure) - the same
        // "always cleared first, regardless of outcome" shape
        // AgentGroupLifecycleSystem::_pendingGroupOperations already uses.
        std::unordered_set<uint64> _groupProfileAdoptionInFlight;

        // Milestone 2.12B/2.12D: the only simulation the group coarse tick
        // runs - called from RunDecisionScheduler()'s own group coarse-tick
        // loop, unconditionally for every due AgentGroup (2.12D P2 fix:
        // no longer gated on whether any member happens to be materialized
        // right now - see AgentGroupRecord.h). No config of its own beyond
        // _agentGroupSimulationRates.
        AgentGroupSimulationSystem _agentGroupSimulationSystem;
        AgentGroupSimulationRates _agentGroupSimulationRates;

        // Milestone 2.12E4R (generalized from 2.12E4A's
        // _wolfCoalitionFormationSystem): pure formation candidate-
        // selection system - see its own class comment for why this is a
        // separate question from AgentGroupPolicySystem's "is this
        // socially allowed?" (a formation proposal still has to pass
        // CanJoin() for every member, same as any other automatic join -
        // see RunCoalitionJoinStep()). Stateless and profile-agnostic,
        // called only from RunCoalitionFormation().
        CoalitionFormationSystem _coalitionFormationSystem;

        // Milestone 2.12E4R: AIWorldMgr's own one existing
        // CoalitionFormationProfile, built once at Initialize() from
        // AIWorld.WolfGroupCreatureEntry/FormationRadius and
        // _groupPolicyConfig.LooseMinMembers/LooseMaxMembers - see
        // CoalitionFormationProfile.h for why Min/MaxMembers are never
        // independently-tunable here. Passed to RunCoalitionFormation()
        // from Update()'s own AIWorld.WolfGroupFormationIntervalMs timer.
        // A second profile would be another member exactly like this one,
        // built the same way, with its own timer/call site - nothing
        // about CoalitionFormationSystem/RunCoalitionFormation() itself
        // would need to change.
        CoalitionFormationProfile _wolfLooseFormationProfile;

        // Milestone 2.12E4A: AIWorld.WolfGroupAutoFormation - off by
        // default, see RunCoalitionFormation()'s own comment.
        bool _wolfGroupAutoFormation = false;

        // Milestone 2.12E4A: AIWorld.WolfGroupCreatureEntry - the one
        // creature_template entry _wolfLooseFormationProfile is built
        // with. A single fixed entry, not a list/category - deliberately
        // narrow for this milestone's own vertical slice, the same "prove
        // it for one concrete case first" scoping the manual group
        // lifecycle/policy smoke tests already followed. AI WorldFactionId
        // P1 fix: was 1423 ("Stormwind Guard", STORMWIND_ALLIANCE) - a
        // latent species/config mismatch invisible before
        // _wolfLooseFormationProfile.RequiredWorldFaction (ElwynnWolves)
        // existed to catch it. Now 69 ("Diseased Timber Wolf",
        // ELWYNN_WOLVES per data/elwynn/factions/world_faction_assignments.csv) -
        // any value here that doesn't resolve to ElwynnWolves in
        // WorldFactionCatalog can never form a coalition any more,
        // regardless of this config.
        uint32 _wolfGroupCreatureEntry = 69;

        // Milestone 2.12E4A: AIWorld.WolfGroupFormationIntervalMs -
        // Update()'s own cadence for RunCoalitionFormation(_wolfLooseFormationProfile),
        // deliberately its own timer rather than piggybacking on any
        // existing one (a formation scan is neither a decision nor a
        // coarse simulation tick).
        uint32 _wolfGroupFormationIntervalMs = 5000;
        uint32 _wolfGroupFormationTimer = 0;

        // Milestone 2.12E4A: AIWorld.WolfGroupFormationRadius -
        // _wolfLooseFormationProfile's own FormationRadius.
        float _wolfGroupFormationRadius = 30.0f;

        // Milestone 2.12G1: AIWorldMgr's second CoalitionFormationProfile -
        // the genericity proof _wolfLooseFormationProfile's own comment
        // above already predicted. Built once at Initialize() from
        // AIWorld.DefiasGroupCreatureEntry/FormationRadius and
        // _groupPolicyConfig.LooseMinMembers/LooseMaxMembers, exactly the
        // same shape as _wolfLooseFormationProfile - passed to its own
        // RunCoalitionFormation() call site from Update()'s own
        // AIWorld.DefiasGroupFormationIntervalMs timer. No change to
        // CoalitionFormationSystem/RunCoalitionFormation() itself.
        CoalitionFormationProfile _defiasLooseFormationProfile;

        // Milestone 2.12G1: AIWorld.DefiasGroupAutoFormation - off by
        // default, see RunCoalitionFormation()'s own comment. A SEPARATE
        // gate from _wolfGroupAutoFormation - each profile's own automatic
        // formation is independently controllable, the same "each
        // capability gets its own gate" discipline every other AIWorld.*
        // enable flag in this class already follows.
        bool _defiasGroupAutoFormation = false;

        // Milestone 2.12G1: AIWorld.DefiasGroupCreatureEntry - the one
        // creature_template entry _defiasLooseFormationProfile is built
        // with (38, Defias Thug - see AIWorld_Current_Roadmap.md's own
        // "2.12G1" section for why this entry was chosen: a real,
        // sufficiently-populated Elwynn spawn, not a synthetic/test one).
        uint32 _defiasGroupCreatureEntry = 38;

        // Milestone 2.12G1: AIWorld.DefiasGroupFormationIntervalMs -
        // Update()'s own cadence for RunCoalitionFormation(_defiasLooseFormationProfile),
        // its own timer, independent of _wolfGroupFormationTimer.
        uint32 _defiasGroupFormationIntervalMs = 5000;
        uint32 _defiasGroupFormationTimer = 0;

        // Milestone 2.12G1: AIWorld.DefiasGroupFormationRadius -
        // _defiasLooseFormationProfile's own FormationRadius.
        float _defiasGroupFormationRadius = 30.0f;

        // Milestone 2.12E4R (STATIC review, generalized from 2.12E4B's
        // bool _wolfFormationInFlight): the CoalitionFormationProfileIds
        // with a formation attempt currently in flight - a per-PROFILE
        // bound now, not a single global boolean, so a future second
        // profile (e.g. a bandit or caravan formation) never has its own
        // formation blocked by an unrelated one already in progress for
        // WolfLoose. Still at most one in-flight attempt PER profile,
        // exactly the same guarantee 2.12E4B's own roadmap message asked
        // for: without it, two RunCoalitionFormation() passes for the
        // SAME profile landing before the first's CreateGroup/Join chain
        // even completes could both propose (and then create a group for)
        // the same still-ungrouped candidates, since neither pass's
        // candidate list reflects a join that has not landed in
        // _groupRegistry yet. profile.Id is inserted (and, when no
        // proposal exists, never inserted) at the top of
        // RunCoalitionFormation(); erased once RunCoalitionJoinStep()
        // reaches NextMemberIndex==Proposal.Members.size() (full success),
        // or once AbortCoalitionFormation()'s own best-effort dissolve
        // attempt completes (success or failure) - never synchronously
        // inside AbortCoalitionFormation() itself, so a new formation pass
        // for that same profile cannot start until any cleanup dissolve
        // for a failed attempt has also finished.
        //
        // Deliberately per-profile ONLY, not a cross-profile guarantee by
        // itself - see _formationReservedMembers below for the P2 STATIC
        // review fix that closes the gap this alone leaves for two
        // DIFFERENT profiles of the same AgentGroupKind, and
        // _coalitionFormationMaxInFlight for the P3 fix bounding how many
        // DIFFERENT profiles can have an entry here at once.
        std::unordered_set<CoalitionFormationProfileId> _formationInFlight;

        // Milestone 2.12E4R P2 fix (STATIC review): every (member, Kind)
        // reserved by a formation attempt currently building its
        // CreateGroup/Join chain - see CoalitionFormationReservationKey.h
        // for the exact cross-profile race this closes, and
        // RunCoalitionFormation()/RunCoalitionJoinStep()/
        // AbortCoalitionFormation()/ReleaseCoalitionFormationReservations()
        // for where entries are inserted and erased. With only one profile
        // (WolfLoose) existing today this can never actually collide with
        // itself - _formationInFlight above already prevents that - but it
        // is what makes a second, concurrently-running same-Kind profile
        // safe once one exists, without requiring _formationInFlight to
        // become a single cross-profile lock again.
        std::unordered_set<CoalitionFormationReservationKey, CoalitionFormationReservationKeyHash> _formationReservedMembers;

        // Milestone 2.12E4R P3 fix (STATIC review): AIWorld.CoalitionFormationMaxInFlight
        // - the hard ceiling on _formationInFlight.size() RunCoalitionFormation()
        // admits against, regardless of how many distinct profiles exist.
        // _formationInFlight alone bounds each profile to at most one
        // attempt, but places no bound on the number of DIFFERENT profiles
        // that can all be mid-formation at the same time - with only one
        // profile today that is moot, but a future profile registry
        // (WolfLoose, BanditLoose, Caravan, ...) would otherwise let the
        // number of concurrent automatic-formation async DB sagas grow
        // with the number of profiles, unbounded. Defaults to 1 - with
        // today's single profile, this reproduces the exact "at most one
        // automatic formation in flight, period" behavior 2.12E4B's own
        // bool _wolfFormationInFlight already gave.
        uint32 _coalitionFormationMaxInFlight = 1;

        // Milestone 2.12G1 P2 fix (STATIC review): flips every
        // RunCoalitionFormationPass() call, regardless of how many
        // profiles are actually due that pass - when more than one due
        // profile is being evaluated in the same pass, this decides which
        // one RunCoalitionFormation() is called for FIRST, so neither
        // profile has a fixed, deterministic first claim on the shared
        // _coalitionFormationMaxInFlight budget purely from source-code
        // ordering (see RunCoalitionFormationPass()'s own comment for the
        // concrete starvation this fixes).
        bool _formationPassFavorDefiasFirst = false;

        // Milestone 2.12E4C1/C2: pure decision system - see its own class
        // comment. Stateless, called only from RunCoalitionMaintenance().
        CoalitionMaintenanceSystem _coalitionMaintenanceSystem;

        // Milestone 2.12E4C2: AIWorldMgr's own one existing
        // CoalitionMaintenanceProfile, paired with
        // _wolfLooseFormationProfile above (same ProfileId/Kind) - built
        // once at Initialize() from AIWorld.WolfGroupLeaveRadius and
        // _groupPolicyConfig.LooseMinMembers.
        CoalitionMaintenanceProfile _wolfLooseMaintenanceProfile;

        // Milestone 2.12G1: paired with _defiasLooseFormationProfile above
        // (same ProfileId/Kind) - built once at Initialize() from
        // AIWorld.DefiasGroupLeaveRadius and _groupPolicyConfig.LooseMinMembers.
        // Maintenance's own enable gate/cadence/bounds
        // (_coalitionMaintenanceEnabled/_coalitionMaintenanceIntervalMs/
        // _coalitionMaintenanceMaxPerPass/_coalitionMaintenanceScanMaxPerPass)
        // stay shared across every profile - see RunCoalitionMaintenance()'s
        // own comment for why a per-profile maintenance pass would be
        // wrong, not just unnecessary.
        CoalitionMaintenanceProfile _defiasLooseMaintenanceProfile;

        // Milestone 2.12E4C2 P2 fix (STATIC review): AIWorld.CoalitionMaintenance
        // - a SEPARATE enable gate from _wolfGroupAutoFormation, off by
        // default. An earlier version shared _wolfGroupAutoFormation's own
        // gate for both formation AND maintenance, on the argument that
        // "maintenance has nothing to maintain until formation has created
        // something" - wrong: a group can persist across a restart, or be
        // created manually/by an admin tool, entirely independent of
        // whether automatic formation is currently enabled. An operator
        // who sets AIWorld.WolfGroupAutoFormation = 0 to stop NEW groups
        // from forming must not also silently freeze every EXISTING
        // group's automatic leave/dissolve maintenance - creation and
        // maintenance are two different lifecycle capabilities. See
        // RunCoalitionMaintenance()'s own call site in Update().
        bool _coalitionMaintenanceEnabled = false;

        // Milestone 2.12E4C2: AIWorld.WolfGroupLeaveRadius -
        // _wolfLooseMaintenanceProfile's own LeaveRadius, clamped at
        // Initialize() to never fall below _wolfGroupFormationRadius (see
        // Initialize()'s own comment for why a smaller LeaveRadius would
        // defeat the formation/leave hysteresis entirely).
        float _wolfGroupLeaveRadius = 60.0f;

        // Milestone 2.12G1: AIWorld.DefiasGroupLeaveRadius -
        // _defiasLooseMaintenanceProfile's own LeaveRadius, clamped at
        // Initialize() to never fall below _defiasGroupFormationRadius, the
        // same hysteresis rule AIWorld.WolfGroupLeaveRadius already
        // follows.
        float _defiasGroupLeaveRadius = 60.0f;

        // Milestone 2.12E4C2: RunCoalitionMaintenance()'s own cadence,
        // deliberately its own timer (a maintenance pass is neither a
        // formation pass nor a group coarse simulation tick). Milestone
        // 2.12E4C2 P2 fix (STATIC review): only advances while
        // _coalitionMaintenanceEnabled is true - a SEPARATE gate from
        // _wolfGroupAutoFormation, not shared with it, see
        // _coalitionMaintenanceEnabled's own declaration comment for why.
        uint32 _coalitionMaintenanceIntervalMs = 5000;
        uint32 _coalitionMaintenanceTimer = 0;

        // Milestone 2.12E4C2: RunCoalitionMaintenance()'s own bounded,
        // deterministic per-pass admission - GroupCoarseSimulationScheduler's
        // own dedicated instance/schedule map for the maintenance pass,
        // entirely separate from _groupCoarseSimulationScheduler/
        // _groupSimulationSchedule's own resource-drift tick (different
        // cadence, different candidate filter, different meaning of "due"
        // - sharing either the instance or the schedule map across both
        // concerns would let one pass's admission accounting bleed into
        // the other's). See GroupCoarseSimulationScheduler.h for why an
        // unbounded per-pass scan is rejected for the exact same reason
        // here as it already is for the group coarse tick.
        //
        // Milestone 2.12E4C2 P3 fix (STATIC review): erased on every
        // confirmed dissolve (see RequestDissolveGroup()'s own completion),
        // the same GroupId-keyed-bookkeeping-never-recycled reasoning
        // _groupSimulationSchedule's own erase there already documents -
        // GroupIds are never reused (see GroupId.h), so a schedule entry
        // left behind after its group is gone would grow this map without
        // bound across a long-running world's dynamic create/dissolve
        // history instead of tracking only currently-existing groups.
        GroupCoarseSimulationScheduler _maintenanceScheduler;
        std::unordered_map<uint64, SimulationScheduleState> _maintenanceSchedule;
        uint32 _coalitionMaintenanceMaxPerPass = 20;

        // Milestone 2.12E4C2 P3 fix (STATIC review): AIWorld.CoalitionMaintenanceScanMaxPerPass
        // - the bound on DISCOVERY (AgentGroupRegistry::GetGroupsAfterUntil()),
        // separate from _coalitionMaintenanceMaxPerPass's own bound on
        // actual per-group WORK (SelectDue() admission) - see
        // RunCoalitionMaintenance()'s own comment for why these are two
        // independently bounded stages, not one. Typically larger than
        // _coalitionMaintenanceMaxPerPass (discovery only filters/reads,
        // work is comparatively expensive), but nothing enforces that
        // relationship - a smaller scan bound just means admission rarely
        // reaches its own ceiling, which is harmless, not incorrect.
        uint32 _coalitionMaintenanceScanMaxPerPass = 100;

        // Milestone 2.12E4C2 P3 fix (STATIC review): RunCoalitionMaintenance()'s
        // own discovery cursor - the last GroupId a GetGroupsAfterUntil()
        // call returned, so the NEXT pass resumes immediately after it
        // rather than re-scanning from the beginning every time. GroupId{}
        // (0) both starts a fresh scan cycle and marks "the previous pass
        // reached the end of the CURRENT cycle's own high-water mark" -
        // every real GroupId is nonzero (see GroupId.h), so 0 is never
        // ambiguous with an actual group. A dissolve between passes never
        // permanently disrupts this: GetGroupsAfterUntil() resumes from
        // whatever GroupId value survives immediately after the cursor,
        // regardless of whether the cursor's own former group still
        // exists - see that method's own comment.
        //
        // Milestone 2.12E4C2 P2 fix, round 2 (STATIC review): deliberately
        // a SINGLE GLOBAL cursor, not one per CoalitionMaintenanceProfile -
        // RunCoalitionMaintenance() itself no longer takes a profile
        // parameter (discovery happens once, across every profile
        // together, then each discovered group's own profile is resolved
        // - see that method's own comment for the cross-profile
        // starvation a per-profile cursor would otherwise cause, and why
        // that would also multiply total discovery work by the number of
        // configured profiles).
        GroupId _maintenanceScanCursor;

        // Milestone 2.12E4C2 P2 fix, round 3 (STATIC review): the highest
        // GroupId (AgentGroupRegistry::GetHighestGroupId()) that existed
        // at the moment the CURRENT scan cycle began - RunCoalitionMaintenance()
        // never discovers a group with a higher GroupId than this within
        // the same cycle, even if one is created mid-cycle. Recomputed
        // fresh (from whatever the registry actually holds right then)
        // every time _maintenanceScanCursor is at GroupId{} - both the
        // very first call ever and every subsequent cycle start after a
        // wrap use the exact same "cursor is 0, so take a fresh snapshot"
        // path, no separate bootstrap needed. Without this, GroupIds being
        // monotonically increasing means a registry growing faster than
        // the scan can advance past it would always have a higher GroupId
        // waiting past the cursor - the scan would never reach empty,
        // never wrap, and the earliest-created groups would never be
        // revisited at all, not merely delayed. See
        // AgentGroupRegistry::GetGroupsAfterUntil()'s own comment for the
        // full reasoning.
        GroupId _maintenanceScanCycleHighWater;

        // Milestone 2.12E4C2: GroupId::Value entries with a maintenance
        // Leave/Dissolve chain currently in flight - inserted by
        // RunCoalitionMaintenanceForGroup() before its own
        // RequestLeaveGroupWithPolicy()/RequestDissolveGroupWithPolicy()
        // call, erased only once that chain's own terminal outcome is
        // fully resolved (RunCoalitionMaintenanceAfterLeave() when no
        // dissolve follows, or RunCoalitionMaintenanceDissolveGroup()'s own
        // completion otherwise - see each method's own comment). Exists so
        // this orchestrator never deliberately re-issues a request for a
        // group it already knows has one in flight - AgentGroupLifecycleSystem's
        // own per-GroupId pending-operation guard (see its header comment)
        // is a second, independent line of defense against the same class
        // of race, not a substitute for this one: that guard only ever
        // rejects an overlapping request AFTER it has already been built
        // and submitted, where this avoids building/logging/submitting a
        // redundant one at all - the concrete case this closes is a group
        // still being processed from a previous maintenance pass (a Leave
        // -> Dissolve chain spanning several ticks) getting re-selected
        // and re-evaluated by a later pass before the first chain has
        // finished.
        std::unordered_set<uint64> _maintenanceInFlight;

        // Milestone 2.12F1/2.12F2: pure decision systems - see their own
        // class comments. Stateless, called only from
        // RunCoalitionCoordination().
        AgentGroupIntentSystem _agentGroupIntentSystem;
        AgentGroupIntentProjector _agentGroupIntentProjector;

        // Milestone 2.12G3B: pure decision systems - see their own class
        // comments. Stateless, called only from RunCoalitionCoordination()/
        // ResolveHuntIntentForGroup(), the same way _agentGroupIntentSystem/
        // _agentGroupIntentProjector already are for Regroup/Roam.
        HuntIntentSystem _huntIntentSystem;
        HuntIntentProjector _huntIntentProjector;

        // Milestone 2.12F2: AIWorldMgr's own one existing
        // AgentGroupCoordinationProfile, paired with
        // _wolfLooseFormationProfile/_wolfLooseMaintenanceProfile above
        // (same ProfileId/Kind) - built once at Initialize() from
        // AIWorld.WolfGroupRegroupEnabled/AIWorld.WolfGroupRegroupRadius
        // and, since 2.12G2, AIWorld.WolfGroupRoamEnabled/
        // AIWorld.WolfGroupRoamDistance/AIWorld.WolfGroupRoamIntervalMs/
        // AIWorld.WolfGroupRoamArrivalRadius.
        AgentGroupCoordinationProfile _wolfLooseCoordinationProfile;

        // Milestone 2.12G1: paired with _defiasLooseFormationProfile/
        // _defiasLooseMaintenanceProfile above (same ProfileId/Kind) -
        // built once at Initialize() from
        // AIWorld.DefiasGroupRegroupEnabled/AIWorld.DefiasGroupRegroupRadius
        // and, since 2.12G2, AIWorld.DefiasGroupRoamEnabled/
        // AIWorld.DefiasGroupRoamDistance/AIWorld.DefiasGroupRoamIntervalMs/
        // AIWorld.DefiasGroupRoamArrivalRadius. Coordination's own enable
        // gate/cadence (_groupCoordinationEnabled/_groupCoordinationIntervalMs/
        // _groupCoordinationScanMaxPerPass) stay shared across every
        // profile AND every intent type - Roam gets no orchestration
        // scheduler of its own, only its own profile DATA, the same
        // discipline 2.12G1's own STATIC review already established for a
        // second PROFILE and this milestone applies to a second INTENT.
        AgentGroupCoordinationProfile _defiasLooseCoordinationProfile;

        // Milestone 2.12F2: gated on its OWN AIWorld.GroupCoordination flag,
        // deliberately NOT _wolfGroupAutoFormation or
        // _coalitionMaintenanceEnabled - the same "each capability gets its
        // own gate" discipline _coalitionMaintenanceEnabled's own
        // declaration comment already established, applied to a third,
        // independent capability (an operator stopping automatic
        // maintenance must not also silently freeze coordination movement
        // of groups that already exist, and vice versa).
        bool _groupCoordinationEnabled = false;

        // Milestone 2.12F2: RunCoalitionCoordination()'s own cadence,
        // deliberately its own timer - a coordination pass is neither a
        // formation pass, a maintenance pass, nor a group coarse simulation
        // tick.
        uint32 _groupCoordinationIntervalMs = 5000;
        uint32 _groupCoordinationTimer = 0;

        // Milestone 2.12F2: the bound on RunCoalitionCoordination()'s own
        // DISCOVERY (AgentGroupRegistry::GetGroupsAfterUntil()) -
        // AIWorld.GroupCoordinationScanMaxPerPass. No separate admission
        // bound exists the way _coalitionMaintenanceMaxPerPass is separate
        // from _coalitionMaintenanceScanMaxPerPass - see
        // RunCoalitionCoordination()'s own comment for why a dispatched
        // MOVE_TO proposal needs no second bounded tier.
        uint32 _groupCoordinationScanMaxPerPass = 100;

        // Milestone 2.12F2: RunCoalitionCoordination()'s own discovery
        // cursor/scan-cycle high-water mark - the exact same two-field
        // pattern _maintenanceScanCursor/_maintenanceScanCycleHighWater
        // already established (see their own declaration comments for the
        // full reasoning), just a dedicated pair for this concern so
        // coordination discovery and maintenance discovery never share, and
        // therefore never race on, one cursor.
        GroupId _coordinationScanCursor;
        GroupId _coordinationScanCycleHighWater;

        // Milestone 2.12G2 P2 fix (STATIC review): the nowMs a still-in-
        // flight ROAM attempt for this GroupId was FIRST evaluated with -
        // keyed by GroupId::Value, entirely runtime-only (never persisted,
        // never survives a restart, the same "ephemeral like
        // GroupCoordinationGoalState" lifetime every other in-flight-
        // attempt tracking field in this class already has). Exists
        // because AgentGroupIntentSystem::Evaluate()'s ROAM target is a
        // pure function of nowMs (via nowMs / profile.RoamIntervalMs) -
        // without this, a phase-bucket boundary crossing mid-attempt
        // (member A already dispatched toward phase P's target, still
        // mid-move, while member B of the SAME group is evaluated fresh
        // once nowMs has ticked into phase P+1) would let one group
        // coordinate its own members toward two DIFFERENT ROAM targets at
        // once - see RunCoalitionCoordination()'s own comment for the
        // exact interleaving this closes. RunCoalitionCoordination() pins
        // the nowMs it passes to Evaluate() to this recorded value for as
        // long as ANY member of the group still has an in-flight
        // GroupCoordinationGoalState with Type == Roam and SourceGroup ==
        // this group (HasInFlightRoamAttempt()) - once none do (the whole
        // group's own attempt has concluded, one way or another, for
        // every member), the entry is erased and the next pass resumes
        // using the real current nowMs, picking up whatever phase is
        // actually current then. Never read or written by
        // AgentGroupIntentSystem itself, which stays a pure function of
        // whatever nowMs its caller decides to pass - this is entirely
        // AIWorldMgr's own orchestration-layer bookkeeping, the same
        // layer _formationInFlight/_maintenanceInFlight already live at.
        //
        // Milestone 2.12G2 P2 fix, round 2 (STATIC review): a dissolved
        // group's own entry is NOT reliably cleared by
        // RunCoalitionCoordination() revisiting it later - a dissolved
        // GroupId is removed from _groupRegistry entirely
        // (AgentGroupRegistry::Remove()), so
        // AgentGroupRegistry::GetGroupsAfterUntil() can never discover it
        // again, and GroupIds are never recycled (see GroupId.h). The
        // authoritative clear is RequestDissolveGroup()'s own confirmed-
        // dissolve completion (see its own comment) - the one place every
        // dissolve path funnels through - with RunCoalitionCoordination()'s
        // own `!group` branch erasing it too, purely as defense in depth.
        std::unordered_map<uint64, uint64> _roamAttemptPinnedNowMs;

        // Milestone 2.12F3 test hook: AIWorld.TestDissolveOnActiveRegroupGroupId
        // - see CheckTestDissolveOnActiveRegroup()'s own comment. GroupId{}
        // (0) means disabled, reloaded fresh every Initialize() (parsed
        // fail-closed there against a negative config value - 2.12F3 P3
        // fix, STATIC review - before ever being stored here). Unlike
        // _coordinationScanCursor/_coordinationScanCycleHighWater above,
        // this is not scan state - it is simply which single group (if
        // any) this test hook is watching.
        GroupId _testDissolveOnActiveRegroupGroupId;

        // Milestone 2.12F3 test hook: doubles as this hook's own enabled/
        // disabled latch, not only "already fired successfully" - besides
        // being set once CheckTestDissolveOnActiveRegroup() has submitted
        // its one and only dissolve request, Initialize() itself also sets
        // this true up front (2.12F3 P3 fix, STATIC review) if
        // _testDissolveOnActiveRegroupGroupId does not resolve in
        // _groupRegistry right after LoadGroups()/LoadGroupMembers() - a
        // configured GroupId that will never exist this process's
        // lifetime must disable the hook outright, not leave it silently
        // polling forever once per coordination pass. CheckTestDissolveOnActiveRegroup()
        // itself sets this the same way (2.12F3 P3 fix, round 3, STATIC
        // review) if the group later stops resolving at all - a group can
        // legitimately dissolve through the normal lifecycle path before
        // this hook ever observes an active REGROUP, which the
        // Initialize()-time existence check above cannot catch. Either way, never
        // fires a second time for the rest of this process's lifetime
        // (even if the group somehow still resolves and still has a
        // member mid-REGROUP for some other reason afterward) - the same
        // at-most-once guarantee _formationInFlight/_maintenanceInFlight
        // give their own in-flight work, just for a single test group
        // rather than a set of them since only one groupId is ever
        // configured at a time. Reset to false every Initialize(), before
        // the existence check above can set it back to true.
        bool _testDissolveOnActiveRegroupFired = false;

        // Milestone 2.12G2R: one captured ROAM attempt's own identity -
        // used only by CheckTestDissolveOnActiveRoam()'s own postcondition
        // verification (see its own declaration comment), which has to
        // remember EVERY currently-roaming member's own attempt
        // separately (2.12G2R P2 fix, STATIC review: a group-wide
        // dissolve must be proven to stop every one of them, not just
        // whichever member the hook happened to observe first).
        struct TestRoamAttemptIdentity
        {
            AgentId Member;
            uint64 StartedAtMs = 0;
        };

        // Milestone 2.12G2R test hooks: AIWorld.TestPreemptOnActiveRoamAgentId/
        // AIWorld.TestLeaveOnActiveRoamAgentId (AgentId{} disabled) and
        // AIWorld.TestDissolveOnActiveRoamGroupId (GroupId{} disabled) -
        // same shape/lifetime as _testDissolveOnActiveRegroupGroupId/
        // _testDissolveOnActiveRegroupFired above for the configured id
        // and the final *Fired latch. Reloaded fresh every Initialize()
        // (fail-closed against a negative config value before ever being
        // stored here, same as the Regroup hook; the *Triggered/Captured*/
        // VerifyDeadlineMs fields below are reset there too, so a runtime
        // reload never resumes a stale in-progress verification from a
        // previous run). *Fired is set true up front at Initialize() if
        // its configured id does not resolve, or by its own Check* method
        // once its own VERIFY phase concludes (PASSED or FAILED) or the
        // target later stops resolving at all - see
        // CheckTestPreemptOnActiveRoam()/CheckTestLeaveOnActiveRoam()/
        // CheckTestDissolveOnActiveRoam()'s own comments for the full
        // TRIGGER/VERIFY two-phase shape (2.12G2R P2 fix, STATIC review)
        // the remaining fields below exist for.
        AgentId _testPreemptOnActiveRoamAgentId;
        bool _testPreemptOnActiveRoamFired = false;
        bool _testPreemptOnActiveRoamTriggered = false;
        GroupId _testPreemptOnActiveRoamCapturedGroup;
        uint64 _testPreemptOnActiveRoamCapturedStartedAtMs = 0;
        uint64 _testPreemptOnActiveRoamVerifyDeadlineMs = 0;

        AgentId _testLeaveOnActiveRoamAgentId;
        bool _testLeaveOnActiveRoamFired = false;
        bool _testLeaveOnActiveRoamTriggered = false;
        GroupId _testLeaveOnActiveRoamCapturedGroup;
        uint64 _testLeaveOnActiveRoamCapturedStartedAtMs = 0;
        uint64 _testLeaveOnActiveRoamVerifyDeadlineMs = 0;

        GroupId _testDissolveOnActiveRoamGroupId;
        bool _testDissolveOnActiveRoamFired = false;
        bool _testDissolveOnActiveRoamTriggered = false;
        std::vector<TestRoamAttemptIdentity> _testDissolveOnActiveRoamCapturedMembers;
        uint64 _testDissolveOnActiveRoamVerifyDeadlineMs = 0;

        // Milestone 2.12G3D1: AIWorld.TestObserveActiveHuntAgentId
        // (AgentId{} = disabled) - same fail-closed parsing/existence-check
        // shape as the active-Roam hooks above, reloaded fresh every
        // Initialize() so a runtime reload never resumes a stale latch
        // from a previous run. No TRIGGER/Captured*/VerifyDeadlineMs
        // fields - this hook is purely observational, see
        // CheckTestObserveActiveHunt()'s own comment.
        AgentId _testObserveActiveHuntAgentId;
        bool _testObserveActiveHuntFired = false;

        // AIWorld.DecisionMaxInFlight - the hard global cap RunDecisionScheduler()
        // admits against and AIClient itself separately enforces (defense in
        // depth: even a scheduler bug can't get more than this many
        // concurrent /decision requests out of AIClient).
        uint32 _decisionMaxInFlight = 4;

        // Milestone 2.13A3B: AIWorld.DynamicTaskEnable (default false).
        // When false, BuildDynamicTaskRequest()/TrySubmitDynamicTask() are
        // never even reached from a real caller - see
        // TrySubmitDynamicTask()'s own fail-closed check - AND AIClient
        // itself is constructed with zero dynamic-task slots (see
        // Initialize()), so even a hypothetical direct
        // AIClient::SubmitDynamicTask() call from anywhere else could
        // never actually get a request out. Two independent default-off
        // gates, the same defense-in-depth AIWorld.DynamicTaskMaxInFlight
        // already gets against AIClient's own separate counter.
        bool _dynamicTaskEnabled = false;

        // AIWorld.DynamicTaskMaxInFlight - the hard cap TrySubmitDynamicTask()
        // admits _pendingDynamicTasks against; AIClient enforces its own
        // independent copy of this same bound too (defense in depth,
        // exactly like _decisionMaxInFlight above).
        uint32 _dynamicTaskMaxInFlight = 2;

        // AIWorld.DynamicTaskResponseMaxAgeMs / AIWorld.DynamicTaskSourceMaxAgeMs -
        // see CheckDynamicTaskResponseAcceptance()/BuildDynamicTaskRequest()'s
        // own comments for exactly what each bounds.
        uint64 _dynamicTaskResponseMaxAgeMs = 10000;
        uint64 _dynamicTaskSourceMaxAgeMs = 30000;

        // AIWorld.DynamicTaskMaxRequiredCount/MaxRangeYards/MaxExpiryMs/
        // MaxRewardMoneyCopper - the server-owned policy window
        // BuildDynamicTaskRequest() stamps onto every QuestContext::Limits
        // it builds, and CheckDynamicTaskResponseAcceptance() re-checks a
        // draft against afterward. Defense in depth only, never
        // authoritative - see QuestProposalLimits' own comment; 2.13B
        // re-validates independently against current server policy.
        uint32 _dynamicTaskMaxRequiredCount = 5;
        float _dynamicTaskMaxRangeYards = 60.0f;
        uint32 _dynamicTaskMaxExpiryMs = 300000;
        uint32 _dynamicTaskMaxRewardMoneyCopper = 0;

        // AIWorld.AIResponseDrainMaxPerTick - bounds how many AIClient
        // responses (of any AIRequestType) Update() drains from the
        // shared MPSCQueue in one tick; anything beyond it simply stays
        // queued for the next tick rather than being lost.
        uint32 _aiResponseDrainMaxPerTick = 64;

        // Milestone 2.13A3B: one outstanding /dynamic-task request per
        // agent, keyed by AgentId::Value - this map IS the duplicate-
        // submission guard (TrySubmitDynamicTask() checks contains()
        // before ever calling AIClient::SubmitDynamicTask()) as well as
        // where HandleDynamicTaskResponse() looks up what a response is
        // actually supposed to answer. An entry is only ever erased once
        // its own RequestId is confirmed to match an incoming response
        // (DynamicTaskResponseMatchesPending()) - a stale/foreign
        // response for the same agent must never erase a newer pending
        // entry it does not actually answer.
        std::unordered_map<uint64, PendingDynamicTaskRequest> _pendingDynamicTasks;

        // Milestone 2.13C2: every currently-live Offered/Active dynamic
        // quest, world-thread-owned exactly like _pendingDynamicTasks
        // above - no mutex, no separate thread. See
        // DynamicQuestRegistry's own comment.
        DynamicQuestRegistry _dynamicQuestRegistry;

        // Milestone 2.13C4 P2 fix (STATIC review): cross-thread ingress
        // for DynamicQuestKillEvents (see DynamicQuestKillEventBus's own
        // comment) - Unit::Kill() publishes into it, potentially from a
        // map-updater thread; the world thread drains it once per tick in
        // Update(), alongside but separate from _eventBus's own Drain().
        // Deliberately its own bus, not a reuse of _eventBus - see that
        // class's comment for why authoritative dynamic-quest kill credit
        // cannot share the shared perception/memory bus's drop-under-
        // overload behavior.
        DynamicQuestKillEventBus _dynamicQuestKillEventBus;

        // Milestone 2.13C4 P2 fix (STATIC review, round 3): the last
        // _dynamicQuestKillEventBus.GetDroppedEventCount() value
        // ReclaimDynamicQuestsAfterKillCreditLoss() observed - see that
        // method's own comment. Starts at 0, matching
        // DynamicQuestKillEventBus's own counter starting at 0.
        uint64 _lastObservedDynamicQuestKillDropCount = 0;

        // Milestone 2.13C2: the sole DynamicQuestId minting authority -
        // see AllocateDynamicQuestId()'s own comment. Starts at 1 (0 is
        // DynamicQuestId's own permanently-invalid value), advances via
        // the pure AdvanceDynamicQuestIdCounter(), and is explicitly set
        // to 0 forever once UINT64_MAX has been handed out - a
        // process-lifetime-only counter, never persisted or reset.
        uint64 _nextDynamicQuestId = 1;

        // Milestone 2.13C2 P3 fix (STATIC review): AIWorld.
        // DynamicQuestMaxLive - the absolute cap CreateDynamicQuestOffer()
        // enforces against _dynamicQuestRegistry.GetCount() before doing
        // anything else, checked before any live giver/target
        // re-resolution so a full registry fails fast. Bounded expiry
        // maintenance (RunDynamicQuestMaintenance()) reclaims Offered/
        // Active instances nobody accepts before their own ExpiresAtMs,
        // but has no effect on Completed/Failed ones (nothing produces
        // those yet) or on a creation rate that outpaces reclamation -
        // this cap is the hard backstop for both.
        uint32 _dynamicQuestMaxLive = 1000;

        // Milestone 2.13C3: AIWorld.DynamicQuestPlayerAcceptMaxRangeYards -
        // the live giver-to-player interaction range
        // AcceptDynamicQuestForPlayer() enforces, so a quest can never be
        // accepted from across the map. Deliberately its own config, not
        // reused from AIWorld.DynamicTaskMaxRangeYards (that bounds a
        // proposed quest's own objective range, an unrelated concern) or
        // any TrinityCore gossip/interaction constant (see this method's
        // own declaration comment for why the standard
        // CanInteractWithQuestGiver() path is not used here).
        float _dynamicQuestPlayerAcceptMaxRangeYards = 10.0f;

        // Milestone 2.13C2 P2 fix (STATIC review): AIWorld.
        // DynamicQuestMaintenanceIntervalMs/ScanMaxPerPass - how often
        // RunDynamicQuestMaintenance() runs and how many ids it may
        // examine per pass. Unlike coalition maintenance, this has no
        // separate "enabled" gate: a bounded scan over an empty (or
        // small) registry is already cheap, and 2.13C2 only ever creates
        // Offered instances - there is no world in which leaving this
        // permanently off would be the correct default the way
        // AIWorld.CoalitionMaintenance's off-by-default toggle is.
        uint32 _dynamicQuestMaintenanceIntervalMs = 30000;
        uint32 _dynamicQuestMaintenanceTimer = 0;
        uint32 _dynamicQuestMaintenanceScanMaxPerPass = 100;

        // Milestone 2.13C2 P2 fix (STATIC review): the same cursor +
        // scan-cycle-high-water-mark pair _maintenanceScanCursor/
        // _maintenanceScanCycleHighWater already establish for coalition
        // maintenance - see RunDynamicQuestMaintenance()'s own comment
        // and DynamicQuestRegistry::GetIdsAfterUntil()'s own comment for
        // why `until` is required, not just a plain cursor.
        DynamicQuestId _dynamicQuestMaintenanceCursor;
        DynamicQuestId _dynamicQuestMaintenanceCycleHighWater;

        // Milestone 2.13A3B: AIWorld.TestDynamicTaskAgentId (AgentId{} =
        // disabled) - same fail-closed parsing/existence-check shape as
        // AIWorld.TestObserveActiveHuntAgentId above, reloaded fresh
        // every Initialize(). See TryRunDynamicTaskRuntimeProbe()'s own
        // comment for exactly what this hook does (and does not do).
        AgentId _testDynamicTaskAgentId;
        bool _testDynamicTaskFired = false;

        // Milestone 2.13C6D: AIWorld.TestDynamicQuestKillCreditLoss
        // (false = disabled), reloaded fresh every Initialize() - see
        // TryRunTestDynamicQuestKillCreditLoss()'s own comment.
        bool _testDynamicQuestKillCreditLoss = false;
        bool _testDynamicQuestKillCreditLossFired = false;

        // Owned for the process lifetime, deliberately not reset in
        // Shutdown(): by the time Shutdown() runs, the io_context it was
        // built on may already be stopped and its worker threads joined
        // (see Main.cpp), so there is no safe moment left to tear it down
        // early. Setting _enabled = false just stops new submissions.
        std::unique_ptr<AIClient> _aiClient;
        std::unique_ptr<TelemetryExporter> _telemetryExporter;
        uint32 _telemetryTimer = 0;
        std::unordered_set<uint64> _telemetrySpawnIds;

        uint32 _healthIntervalMs = 10000;
        uint32 _healthTimer = 0;

        // Cross-thread ingress for WorldEvents (see EventBus) - map/combat
        // workers publish into it concurrently with the world thread
        // draining it once per tick. _acceptEvents is the only thing
        // PublishWorldEvent() reads before touching _eventBus; it has to be
        // atomic because, unlike every other member here, it's read from
        // threads other than the world thread. Set true at the end of
        // Initialize(), false at the very first line of Shutdown(), to
        // narrow the window a worker could publish into a half-constructed
        // or tearing-down manager - not a hard barrier: a worker can still
        // read true, get preempted before Publish() takes _eventBus's
        // mutex, and only reach it after Shutdown() has already flipped
        // the flag. Harmless today (EventBus is a plain process-lifetime
        // member and Publish() never touches anything else on AIWorldMgr),
        // but don't treat this as a real teardown barrier once one is
        // needed - that'll want an EventBus::Close() serialized on its own
        // mutex instead.
        EventBus _eventBus;
        std::atomic<bool> _acceptEvents{ false };

        // World-thread-only: turns a witnessed WorldEvent (or, since
        // Milestone 2.4B/2.4C, a nearby Player/Creature - see
        // ScanNearbyEntities()) into an Observation per Materialized agent
        // (range + LOS). Never called from a map/combat worker - only
        // after this manager has already resolved the observer's live
        // Creature itself.
        PerceptionSystem _perception;
        uint32 _perceptionSightRange = 40;

        // Milestone 2.4B/2.4C: periodic PlayerSeen/CreatureSeen
        // perception, independent of any WorldEvent. Deliberately its own
        // (faster, ~1s) cadence rather than piggybacking on the decision
        // scheduler's own cadence - like ProcessWorldEvent()'s perception
        // loop, ScanNearbyEntities() treats live Creature existence as the
        // authority for whether an agent can perceive anything, not
        // record->WorldState.
        uint32 _nearbyPerceptionIntervalMs = 1000;
        uint32 _nearbyPerceptionTimer = 0;

        // Milestone 2.5A/2.5B1: deduplicated, TTL'd summary of every
        // Observation ProcessObservation() sees, weighted by
        // MemoryImportance::Score(). Not persisted, not read by any
        // decision context yet.
        ShortTermMemory _shortTermMemory;
        uint32 _shortTermMemoryTtlMs = 30000;

        // Expiry doesn't need to run every tick - its own ~1s cadence,
        // independent of every other timer here.
        uint32 _memoryMaintenanceTimer = 0;

        // Milestone 2.5B: every Observation goes into _shortTermMemory
        // unconditionally, but only importance >= _longTermMemoryMinImportance
        // gets promoted into _longTermMemory and (on an actual promotion,
        // not a refresh of an existing one) queued for async persistence
        // via _memoryPersistence. Rebuilt from characters.
        // ai_long_term_memories every startup, the same way _registry is
        // rebuilt from _persistence.
        LongTermMemory _longTermMemory;
        MemoryPersistence _memoryPersistence;
        float _longTermMemoryMinImportance = 0.75f;

        // Milestone 2.5C/2.9A: deterministic relevance scoring over
        // _shortTermMemory/_longTermMemory, run once per CaptureAgentContext()
        // right after the AgentSnapshot is built - its Top-N result feeds
        // AgentContext::RelevantMemories.
        MemoryRetrieval _memoryRetrieval;
        uint32 _memoryRetrievalTopN = 5;

        // Milestone 2.6A: deterministic per-agent NeedsState drift, run only
        // for Materialized agents (see UpdateNeeds()) on its own ~1s cadence,
        // independent of the decision scheduler's cadence - Needs is a
        // simulation subsystem, not part of the snapshot/decision cadence.
        // Pure value transform: NeedsSystem itself never touches AgentId/
        // Creature/Map.
        NeedsSystem _needsSystem;
        NeedsUpdateRates _needsRates;
        uint32 _needsUpdateIntervalMs = 1000;
        uint32 _needsUpdateTimer = 0;

        // Milestone 2.7A: deterministic, level-triggered goal candidate
        // generation from NeedsState, run right after UpdateNeeds() so it
        // always sees this tick's freshly-updated Needs. Logged only - no
        // ActiveGoal, no selection, no Action API (that's 2.7B/2.8). Pure
        // value transform: GoalSystem itself never touches AgentId/
        // Creature/Map/AgentRecord/DB.
        GoalSystem _goalSystem;

        // Milestone 2.8A/2.8B: the safety boundary between "AI proposes"
        // and "TrinityCore executes" - AIWorldMgr builds an ActionRequest
        // only on FLEE_DANGER's ACTIVATED/INTERRUPTED transition (see
        // UpdateNeeds()) and asks Validate() whether it's currently
        // ALLOWED. Debug-logged either way.
        ActionSystem _actionSystem;

        // Milestone 2.8B: the only member allowed to actually touch
        // TrinityCore's engine API on AIWorld's behalf, and only after
        // _actionSystem has already returned Allowed == true for the exact
        // request being executed.
        ActionExecutor _actionExecutor;

        // Milestone 2.8E: answers "where should a hungry agent go" for
        // GET_FOOD's ACTIVATED transition (see UpdateNeeds()) - superseding
        // 2.8D's generic, goal-agnostic MOVE_TO test trigger, now that a
        // real Goal -> target -> Action pipeline exists. _foodTargetConfig
        // is shared configuration (AIWorld.TestFoodTarget*, loaded once at
        // Initialize()), passed into Resolve() per call - the same
        // pattern _needsRates already uses for NeedsSystem. Pure value
        // transform: FoodTargetResolver itself never touches AgentId/
        // Creature/Map/DB.
        FoodTargetResolver _foodTargetResolver;
        FoodTargetConfig _foodTargetConfig;

        // Milestone 2.11B: run alongside GoalSystem in UpdateNeeds() (same
        // Needs-cadence tick, right after ActiveGoalState is finalized for
        // it), independent of GoalSystem's own Needs-driven selection - see
        // RoutineSystem.h for why routine is deliberately not folded into
        // GoalCandidate/ActiveGoal. _routineScheduleConfig is shared
        // configuration (AIWorld.Routine*, loaded and cross-validated once
        // at Initialize()), passed into DeriveGoal() per call, the same
        // pattern _foodTargetConfig already uses for FoodTargetResolver.
        RoutineSystem _routineSystem;
        RoutineScheduleConfig _routineScheduleConfig;

        // Milestone 2.11D: run in UpdateNeeds() right after RoutineGoalState/
        // its own MOVE_TO handling, from facts AIWorldMgr resolves itself
        // (materialized/alive/live position vs. RoutineGoalState's target) -
        // see RoutineActivitySystem.h for why this is a separate class from
        // RoutineSystem rather than a third responsibility folded into it.
        // No config of its own; ArrivalToleranceYards (already shared with
        // MOVE_TO arrival/Eat) is reused, not duplicated.
        RoutineActivitySystem _routineActivitySystem;

        // Milestone 2.11E2: how much AgentRecord::EconomyState::Money a WORK
        // ActionCompletion reaching Succeeded/Performed adds - see
        // UpdateNeeds()'s activity block. Loaded once at Initialize() from
        // AIWorld.WorkMoneyReward.
        uint32 _workMoneyReward = 1;

        // Milestone 2.8F: cross-thread ingress for ActionEngineEvents (see
        // ActionEngineEventBus) - AIWorldCreatureAI::MovementInform()
        // publishes into it, potentially from a map-updater thread, the
        // world thread drains it once per tick in Update(), right after
        // _eventBus's own Drain(). Gated by the same _acceptEvents flag as
        // PublishWorldEvent(), for the same reason.
        ActionEngineEventBus _actionEngineEventBus;
};

#define sAIWorldMgr AIWorldMgr::instance()

#endif // AIWORLD_AIWORLDMGR_H
