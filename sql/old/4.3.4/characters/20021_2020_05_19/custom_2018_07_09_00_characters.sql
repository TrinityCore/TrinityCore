DROP TABLE IF EXISTS `guild_old_member`;
CREATE TABLE `guild_old_member` (
  `guid` int(10) unsigned NOT NULL,
  `guildId` int(10) unsigned NOT NULL,
  `weekReputation` int(10) unsigned NOT NULL,
  `leaveDate` int(10) unsigned NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

ALTER TABLE `guild_member`
ADD COLUMN `activity` int(10) unsigned NOT NULL DEFAULT '0' AFTER `offnote`,
ADD COLUMN `weekActivity` int(10) unsigned NOT NULL DEFAULT '0' AFTER `activity`,
ADD COLUMN `weekReputation` int(10) unsigned NOT NULL DEFAULT '0' AFTER `weekActivity`;

ALTER TABLE `characters` 
ADD COLUMN `achievementPoints` int(10) unsigned NOT NULL DEFAULT '0' AFTER `grantableLevels`;
