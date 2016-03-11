-- Rename table and column to fit the other guild_*log tables and columns and create indexes
RENAME TABLE `guild_news_log` TO `guild_newslog`;

ALTER TABLE `guild_newslog`
CHANGE COLUMN `guild` `guildid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Guild Identificator',
CHANGE COLUMN `id` `LogGuid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Log record identificator - auxiliary column',
CHANGE COLUMN `eventType` `EventType` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Event type',
CHANGE COLUMN `playerGuid` `PlayerGuid` int(10) unsigned NOT NULL DEFAULT '0',
CHANGE COLUMN `data` `Value` int(10) unsigned NOT NULL DEFAULT '0',
CHANGE COLUMN `flags` `Flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `PlayerGuid`,
CHANGE COLUMN `date` `TimeStamp` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Event UNIX time',
ADD KEY `guildid_key` (`guildid`),
ADD KEY `Idx_PlayerGuid` (`PlayerGuid`),
ADD KEY `Idx_LogGuid` (`LogGuid`);

-- Create missing tabs

ALTER TABLE `guild_member_withdraw`
ADD COLUMN `tab6` int(10) unsigned NOT NULL DEFAULT '0' AFTER `tab5`,
ADD COLUMN `tab7` int(10) unsigned NOT NULL DEFAULT '0' AFTER `tab6`;

