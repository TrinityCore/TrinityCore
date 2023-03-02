ALTER TABLE `character_currency`
ADD COLUMN `season_count`  int(10) UNSIGNED NOT NULL AFTER `week_count`,
ADD COLUMN `flags`  int(5) UNSIGNED NOT NULL AFTER `season_count`;
