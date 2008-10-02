ALTER TABLE `guild` ADD COLUMN `BankMoney` bigint(20) NOT NULL DEFAULT 0 AFTER `createdate`;
ALTER TABLE `guild_rank` ADD COLUMN `BankMoneyPerDay` int(11) unsigned NOT NULL default '0' AFTER `rights`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeMoney` int(11) unsigned NOT NULL DEFAULT '0' AFTER `OFFnote`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemMoney` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeMoney`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab0` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemMoney`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab0` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab0`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab1` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemSlotsTab0`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab1` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab1`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab2` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemSlotsTab1`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab2` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab2`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab3` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemSlotsTab2`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab3` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab3`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab4` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemSlotsTab3`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab4` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab4`;
ALTER TABLE `guild_member` ADD COLUMN `BankResetTimeTab5` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankRemSlotsTab4`;
ALTER TABLE `guild_member` ADD COLUMN `BankRemSlotsTab5` int(11) unsigned NOT NULL DEFAULT '0' AFTER `BankResetTimeTab5`;

DROP TABLE IF EXISTS `guild_bank_item`;
CREATE TABLE `guild_bank_item` (
  `guildid` int(11) unsigned NOT NULL default '0',
  `TabId` tinyint(1) unsigned NOT NULL default '0',
  `SlotId` tinyint(3) unsigned NOT NULL default '0',
  `item_guid` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guildid`,`tabid`,`slotid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `guild_bank_tab`;
CREATE TABLE `guild_bank_tab` (
  `guildid` int(11) unsigned NOT NULL default '0',
  `TabId` tinyint(1) unsigned NOT NULL default '0',
  `TabName` varchar(100) NOT NULL default '',
  `TabIcon` varchar(100) NOT NULL default '',
  PRIMARY KEY  (`guildid`,`TabId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `guild_bank_right`;
CREATE TABLE `guild_bank_right` (
  `guildid` int(11) unsigned NOT NULL default '0',
  `TabId` tinyint(1) unsigned NOT NULL default '0',
  `rid` int(11) unsigned NOT NULL default '0',
  `Right` tinyint(3) unsigned NOT NULL default '0',
  `SlotPerDay` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guildid`,`TabId`,`rid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `guild_bank_eventlog`;
CREATE TABLE `guild_bank_eventlog` (
  `guildid` int(11) unsigned NOT NULL default '0',
  `LogGuid` int(11) unsigned NOT NULL default '0',
  `LogEntry` tinyint(1) unsigned NOT NULL default '0',
  `TabId` tinyint(1) unsigned NOT NULL default '0',
  `PlayerGuid` int(11) unsigned NOT NULL default '0',
  `ItemOrMoney` int(11) unsigned NOT NULL default '0',
  `ItemStackCount` tinyint(3) unsigned NOT NULL default '0',
  `DestTabId` tinyint(1) unsigned NOT NULL default '0',
  `TimeStamp` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guildid`,`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
