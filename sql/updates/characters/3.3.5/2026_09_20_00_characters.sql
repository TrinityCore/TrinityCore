-- AI player WorldFaction membership (AIWorld_Current_Roadmap.md - player
-- WorldFaction membership vertical slice). V1: at most one active
-- membership per character - row absent means "none" (WorldFactions::
-- Unaffiliated), never an explicit world_faction_id = 0 row. Deliberately
-- separate from character_reputation (earned reputation, TrinityCore's own
-- table, untouched by this) and from combat/ReputationMgr - this table is
-- read/written only by PlayerWorldFactionPersistence (src/server/game/
-- AIWorld/Faction/), on demand, never cached on the live Player object and
-- never loaded via Player::LoadFromDB()'s LoginQueryHolder.
CREATE TABLE IF NOT EXISTS `ai_player_world_faction` (
    `character_guid` INT UNSIGNED NOT NULL,
    `world_faction_id` INT UNSIGNED NOT NULL,
    `joined_at` BIGINT UNSIGNED NOT NULL,
    PRIMARY KEY (`character_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='AI WorldFaction player membership (V1: one active membership per character)';
