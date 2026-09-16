-- creature_onkill_reputation: reputation reward for killing an Elwynn NPC
-- affiliated with one of the four player-visible custom WorldFactions
-- (data/elwynn/factions/README.md). `RewOnKillRepFaction1` is a real
-- Faction.dbc id (1201-1204, data/elwynn/factions/factions.csv) -
-- ObjectMgr::LoadReputationOnKill() validates it against sFactionStore at
-- startup, and Player::RewardReputation() (src/server/game/Entities/Player/
-- Player.cpp) is what actually calls ReputationMgr::ModifyReputation() the
-- moment a player lands the killing blow.
--
-- entry -> faction mapping is exactly data/elwynn/factions/
-- world_faction_assignments.csv's own `world_faction`/`onkill_rep_value`
-- columns for every row already marked `tc_faction_action = CLONED` - the
-- same 32 entries the FactionTemplate.dbc clones/creature_template repoint
-- (2026_09_16_01_world.sql) already cover, cross-verified against that CSV
-- before writing this file. Regenerate this migration from that CSV if
-- either the entry list or onkill_rep_value ever changes.
--
-- V1 flat baseline (deliberately simple, not a game-balance pass): +1
-- reputation per kill for every one of the 32 entries, whether common
-- trash (Defias Thug, 71 spawns) or a unique named NPC (Hogger, 1 spawn).
-- Tiering unique/rare kills higher than common trash is a legitimate
-- follow-up, not attempted here.
--
-- MaxStanding1 = 8, not 0: Player::RewardReputation() only applies a kill's
-- reputation directly if `current_reputation_rank <= MaxStanding` (see its
-- own ModifyReputation() call, `spillOverOnly = rank > MaxStanding1`) -
-- REP_EXALTED (SharedDefines.h ReputationRank) is 7, so 8 is one past the
-- highest reachable rank and this cap never actually trips (reputation can
-- climb all the way to Exalted from kills alone). MaxStanding1 = 0 would
-- have been wrong here: these factions already start at REP_NEUTRAL (3, >
-- 0), so a 0 cap would silently spillover-only (i.e. block, since these
-- factions have no ParentFactionID) reputation gain from the very first
-- kill, before the bar could ever move.
--
-- RewOnKillRepFaction2/MaxStanding2/IsTeamAward2/RewOnKillRepValue2 = 0
-- (unused - one target faction per NPC, not a team-split Alliance/Horde
-- reward). TeamDependent = 0 and IsTeamAward1 = 0: every playable race
-- gains the same individual reputation from the same kill, matching
-- factions.csv's own RaceMask = RACEMASK_ALL_PLAYABLE (visible/available to
-- every playable race, not split by team).

DELETE FROM `creature_onkill_reputation`
WHERE `creature_id` IN (6, 38, 40, 46, 60, 61, 79, 80, 94, 97, 99, 100, 103, 116, 257, 285, 327, 448,
    472, 473, 474, 475, 476, 478, 732, 735, 880, 881, 6093, 6846, 6927, 13159);

INSERT INTO `creature_onkill_reputation`
    (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`,
     `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`)
VALUES
(6, 1203, 0, 8, 0, 1, 0, 0, 0, 0),      -- Kobold Vermin
(38, 1201, 0, 8, 0, 1, 0, 0, 0, 0),     -- Defias Thug
(40, 1203, 0, 8, 0, 1, 0, 0, 0, 0),     -- Kobold Miner
(46, 1204, 0, 8, 0, 1, 0, 0, 0, 0),     -- Murloc Forager
(60, 1203, 0, 8, 0, 1, 0, 0, 0, 0),     -- Ruklar the Trapper
(61, 1201, 0, 8, 0, 1, 0, 0, 0, 0),     -- Thuros Lightfingers
(79, 1203, 0, 8, 0, 1, 0, 0, 0, 0),     -- Narg the Taskmaster
(80, 1203, 0, 8, 0, 1, 0, 0, 0, 0),     -- Kobold Laborer
(94, 1201, 0, 8, 0, 1, 0, 0, 0, 0),     -- Defias Cutpurse
(97, 1202, 0, 8, 0, 1, 0, 0, 0, 0),     -- Riverpaw Runt
(99, 1201, 0, 8, 0, 1, 0, 0, 0, 0),     -- Morgaine the Sly
(100, 1202, 0, 8, 0, 1, 0, 0, 0, 0),    -- Gruff Swiftbite
(103, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Garrick Padfoot
(116, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Defias Bandit
(257, 1203, 0, 8, 0, 1, 0, 0, 0, 0),    -- Kobold Worker
(285, 1204, 0, 8, 0, 1, 0, 0, 0, 0),    -- Murloc
(327, 1203, 0, 8, 0, 1, 0, 0, 0, 0),    -- Goldtooth
(448, 1202, 0, 8, 0, 1, 0, 0, 0, 0),    -- Hogger
(472, 1202, 0, 8, 0, 1, 0, 0, 0, 0),    -- Fedfennel
(473, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Morgan the Collector
(474, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Defias Rogue Wizard
(475, 1203, 0, 8, 0, 1, 0, 0, 0, 0),    -- Kobold Tunneler
(476, 1203, 0, 8, 0, 1, 0, 0, 0, 0),    -- Kobold Geomancer
(478, 1202, 0, 8, 0, 1, 0, 0, 0, 0),    -- Riverpaw Outrunner
(732, 1204, 0, 8, 0, 1, 0, 0, 0, 0),    -- Murloc Lurker
(735, 1204, 0, 8, 0, 1, 0, 0, 0, 0),    -- Murloc Streamrunner
(880, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Erlan Drudgemoor
(881, 1201, 0, 8, 0, 1, 0, 0, 0, 0),    -- Surena Caledon
(6093, 1201, 0, 8, 0, 1, 0, 0, 0, 0),   -- Dead-Tooth Jack
(6846, 1201, 0, 8, 0, 1, 0, 0, 0, 0),   -- Defias Dockmaster
(6927, 1201, 0, 8, 0, 1, 0, 0, 0, 0),   -- Defias Dockworker
(13159, 1201, 0, 8, 0, 1, 0, 0, 0, 0);  -- James Clark
