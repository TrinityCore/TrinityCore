ALTER TABLE `guild_bank_eventlog`
CHANGE `guildid` `guildid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Guild Identificator',
CHANGE `LogGuid` `LogGuid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Log record identificator - auxiliary column',
CHANGE `PlayerGuid` `PlayerGuid` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `ItemOrMoney` `ItemOrMoney` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `ItemStackCount` `ItemStackCount` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0',
CHANGE `DestTabId` `DestTabId` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Destination Tab Id',
CHANGE `TimeStamp` `TimeStamp` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Event UNIX time';