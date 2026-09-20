-- AI WorldFaction diplomacy matrix (AIWorld_Current_Roadmap.md -
-- WorldFactionRelationCatalog vertical slice). Generated from
-- data/elwynn/factions/world_faction_relations.csv (see
-- tools/elwynn/build_world_faction_relations_defaults.py) - the versioned,
-- reviewed source of truth for these 8 directed (from, to) rows. Do
-- not hand-edit this table's content; regenerate it from that CSV if the
-- matrix changes.
--
-- Deliberately directional, never symmetric: a bidirectional relationship
-- (e.g. Stormwind <-> Defias) is two explicit rows, never inferred from
-- one. Same-faction Friendly is never a row here - it is
-- WorldFactionRelationCatalog::Resolve()'s own implicit rule 1, computed
-- without a table lookup. WorldFactionRelationCatalog::Resolve() falls
-- back to Neutral for any (from, to) pair not present here - see that
-- class's own comment and data/elwynn/factions/README.md's "Nevypsaný
-- cross-faction vztah je NEUTRAL" note.
CREATE TABLE IF NOT EXISTS `ai_world_faction_relations` (
    `from_world_faction_id` INT UNSIGNED NOT NULL,
    `to_world_faction_id` INT UNSIGNED NOT NULL,
    `relation` TINYINT UNSIGNED NOT NULL,
    PRIMARY KEY (`from_world_faction_id`, `to_world_faction_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_world_faction_relations`;
INSERT INTO `ai_world_faction_relations` (`from_world_faction_id`, `to_world_faction_id`, `relation`) VALUES
(1, 2, 2),
(1, 3, 2),
(1, 4, 2),
(1, 5, 2),
(2, 1, 2),
(3, 1, 2),
(4, 1, 2),
(5, 1, 2);
