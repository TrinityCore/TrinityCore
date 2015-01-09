ALTER TABLE `guild_eventlog`
CHANGE `guildid` `guildid` INT(10) UNSIGNED NOT NULL COMMENT 'Guild Identificator',
CHANGE `LogGuid` `LogGuid` INT(10) UNSIGNED NOT NULL COMMENT 'Log record identificator - auxiliary column',
CHANGE `EventType` `EventType` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Event type',
CHANGE `PlayerGuid1` `PlayerGuid1` INT(10) UNSIGNED NOT NULL COMMENT 'Player 1',
CHANGE `PlayerGuid2` `PlayerGuid2` INT(10) UNSIGNED NOT NULL COMMENT 'Player 2',
CHANGE `NewRank` `NewRank` TINYINT(3) UNSIGNED NOT NULL COMMENT 'New rank(in case promotion/demotion)',
CHANGE `TimeStamp` `TimeStamp` INT(10) UNSIGNED NOT NULL COMMENT 'Event UNIX time';