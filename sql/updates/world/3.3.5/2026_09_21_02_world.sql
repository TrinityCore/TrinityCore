-- AI WorldFactionId -> Trinity Faction.dbc id bridge table
-- (AIWorld_Current_Roadmap.md - login/allegiance-change ReputationMgr
-- bridge). Generated from data/elwynn/factions/factions.csv,
-- world_faction_vanilla_reputation.csv and world_factions.csv (see
-- tools/elwynn/build_world_faction_reputation_defaults.py) - the versioned,
-- reviewed source of truth for these 5 rows. Do not hand-edit this
-- table's content; regenerate it from those CSVs if the mapping changes.
--
-- Deliberately NOT every WorldFaction: ELWYNN_WOLVES has no row (ecological/
-- social only, never player-visible reputation - README.md's own design
-- note). WorldFactionReputationCatalog::TryResolve() returns false for any
-- WorldFactionId not present here - fail-closed, never guessed.
CREATE TABLE IF NOT EXISTS `ai_world_faction_reputation_defaults` (
    `world_faction_id` INT UNSIGNED NOT NULL,
    `faction_id` INT UNSIGNED NOT NULL,
    PRIMARY KEY (`world_faction_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_world_faction_reputation_defaults`;
INSERT INTO `ai_world_faction_reputation_defaults` (`world_faction_id`, `faction_id`) VALUES
(1, 72),
(2, 1201),
(3, 1202),
(4, 1203),
(5, 1204);
