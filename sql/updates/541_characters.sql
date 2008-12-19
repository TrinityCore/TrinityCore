CREATE TABLE `saved_variables` (
    `NextArenaPointDistributionTime` bigint(40) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Variable Saves';

ALTER TABLE arena_team_member CHANGE games_week played_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wins_week wons_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE games_season played_season int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wins_season wons_season int(10) unsigned NOT NULL default '0';

ALTER TABLE `arena_team_member` DROP COLUMN `points_to_add`;
ALTER TABLE `arena_team_member` ADD COLUMN `personal_rating` int(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `characters` ADD COLUMN `arena_pending_points` int(10) UNSIGNED NOT NULL default '0' AFTER `taxi_path`;