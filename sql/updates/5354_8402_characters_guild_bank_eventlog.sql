-- ALTER TABLE character_db_version CHANGE COLUMN required_8402_01_characters_guild_eventlog required_8402_02_characters_guild_bank_eventlog bit;


-- THIS SCRIPT DELETES table `guild_bank_eventlog` - MAKE BACKUP, if you need it.

DROP TABLE IF EXISTS `guild_bank_eventlog`;
CREATE TABLE `guild_bank_eventlog` (
  `guildid` int(11) unsigned NOT NULL default '0' COMMENT 'Guild Identificator',
  `LogGuid` int(11) unsigned NOT NULL default '0' COMMENT 'Log record identificator - auxiliary column',
  `TabId` tinyint(3) unsigned NOT NULL default '0' COMMENT 'Guild bank TabId',
  `EventType` tinyint(3) unsigned NOT NULL default '0' COMMENT 'Event type',
  `PlayerGuid` int(11) unsigned NOT NULL default '0',
  `ItemOrMoney` int(11) unsigned NOT NULL default '0',
  `ItemStackCount` tinyint(3) unsigned NOT NULL default '0',
  `DestTabId` tinyint(1) unsigned NOT NULL default '0' COMMENT 'Destination Tab Id',
  `TimeStamp` bigint(20) unsigned NOT NULL default '0' COMMENT 'Event UNIX time',
  PRIMARY KEY  (`guildid`,`LogGuid`,`TabId`),
  KEY `guildid_key` (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- The reason i decided for such dramatic change is that old guild_bank_eventlog table used `TabId` = 0 for Money events and 
-- used `LogGuid` from 0 to infinity
-- New system uses `LogGuid` from 0 to number defined in config.
