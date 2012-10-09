-- arena_logs
DROP TABLE IF EXISTS `arena_logs`;
CREATE TABLE `arena_logs` (
  `team1` int(10) unsigned NOT NULL DEFAULT '0',
  `team1_members` varchar(60) CHARACTER SET latin1 NOT NULL DEFAULT '',
  `team1_rating_change` int(11) NOT NULL DEFAULT '0',
  `team2` int(10) unsigned NOT NULL DEFAULT '0',
  `team2_members` varchar(60) CHARACTER SET latin1 NOT NULL DEFAULT '',
  `team2_rating_change` int(11) NOT NULL DEFAULT '0',
  `winner` int(10) unsigned NOT NULL DEFAULT '0',
  `timestamp` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`team1`,`team2`,`timestamp`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
