-- mangos rev 8402
-- ALTER TABLE character_db_version CHANGE COLUMN required_8397_03_characters_character_spell required_8402_01_characters_guild_eventlog bit;


-- THIS SCRIPT DELETES table `guild_eventlog` - MAKE BACKUP, if you need it.

DROP TABLE IF EXISTS `guild_eventlog`;
CREATE TABLE `guild_eventlog` (
  `guildid` int(11) NOT NULL COMMENT 'Guild Identificator',
  `LogGuid` int(11) NOT NULL COMMENT 'Log record identificator - auxiliary column',
  `EventType` tinyint(1) NOT NULL COMMENT 'Event type',
  `PlayerGuid1` int(11) NOT NULL COMMENT 'Player 1',
  `PlayerGuid2` int(11) NOT NULL COMMENT 'Player 2',
  `NewRank` tinyint(2) NOT NULL COMMENT 'New rank(in case promotion/demotion)',
  `TimeStamp` bigint(20) NOT NULL COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`, `LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT 'Guild Eventlog';

-- The reason i decided for such dramatic change is that old guild_eventlog table didn't have Primary key and
-- used LogGuids from 0 to infinity
-- New system uses LogGuids from 0 to number defined in config.
