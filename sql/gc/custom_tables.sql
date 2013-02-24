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
  `HistoryTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`team1`,`team2`,`HistoryTime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- token_rewards
DROP TABLE IF EXISTS `token_rewards`;
CREATE TABLE `token_rewards` (
  `itemId` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `total` smallint(5) unsigned NOT NULL DEFAULT '0',
  `comment` char(64) COLLATE utf8_bin DEFAULT NULL,
  `horde` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `alliance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `category` char(64) COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
