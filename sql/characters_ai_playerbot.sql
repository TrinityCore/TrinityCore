DROP TABLE IF EXISTS `ai_playerbot_random_bots`;

CREATE TABLE `ai_playerbot_random_bots` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `owner` bigint(20) NOT NULL,
  `bot` bigint(20) NOT NULL,
  `time` bigint(20) NOT NULL,
  `validIn` bigint(20) DEFAULT NULL,
  `event` varchar(45) DEFAULT NULL,
  `value` bigint(20) DEFAULT NULL,
  `data` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`),
  KEY `bot` (`bot`),
  KEY `event` (`event`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `ai_playerbot_guild_tasks`;

CREATE TABLE `ai_playerbot_guild_tasks` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `owner` bigint(20) NOT NULL,
  `guildid` bigint(20) NOT NULL,
  `time` bigint(20) NOT NULL,
  `validIn` bigint(20) DEFAULT NULL,
  `type` varchar(45) DEFAULT NULL,
  `value` bigint(20) DEFAULT NULL,
  `data` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`),
  KEY `guildid` (`guildid`),
  KEY `type` (`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
