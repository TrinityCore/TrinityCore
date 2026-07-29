ALTER TABLE `character_arena_stats`
ADD COLUMN `rating` smallint unsigned NOT NULL DEFAULT '0' AFTER `matchMakerRating`;
