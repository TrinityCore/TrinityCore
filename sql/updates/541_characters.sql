DROP TABLE IF EXISTS `saved_variables`;
CREATE TABLE `saved_variables` (
    `NextArenaPointDistributionTime` bigint(40) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Variable Saves';

ALTER TABLE `arena_team_member` DROP COLUMN `points_to_add`;
ALTER TABLE `arena_team_member` ADD COLUMN `personal_rating` int(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `characters` ADD COLUMN `arena_pending_points` int(10) UNSIGNED NOT NULL default '0' AFTER `taxi_path`;

