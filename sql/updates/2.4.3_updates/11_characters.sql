ALTER TABLE `arena_team_member` ADD COLUMN `points_to_add` int(10) UNSIGNED NOT NULL DEFAULT '0';
DROP TABLE IF EXISTS `saved_variables`;
CREATE TABLE `saved_variables` (                                                                             
    `NextArenaPointDistributionTime` timestamp NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Variable Saves';