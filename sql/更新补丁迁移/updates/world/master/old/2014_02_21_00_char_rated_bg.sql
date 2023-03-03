DROP TABLE `character_rated_bg`;

DROP TABLE IF EXISTS `character_brackets_info`;
CREATE TABLE `character_brackets_info` (
  `guid` int(11) NOT NULL,
  `bracket` smallint(6) NOT NULL,
  `rating` mediumint(9) NOT NULL DEFAULT '0',
  `best` mediumint(9) NOT NULL DEFAULT '0',
  `bestWeek` smallint(9) NOT NULL DEFAULT '0',
  `mmr` mediumint(9) NOT NULL DEFAULT '0',
  `games` int(11) NOT NULL DEFAULT '0',
  `wins` int(11) NOT NULL DEFAULT '0',
  `weekGames` mediumint(9) NOT NULL DEFAULT '0',
  `weekWins` mediumint(9) NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`,`bracket`),
  KEY `BracketID` (`bracket`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;