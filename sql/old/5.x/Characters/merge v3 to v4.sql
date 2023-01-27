SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `character_battleground_weekend`;
CREATE TABLE `character_battleground_weekend` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `character_dynamic_difficulty_maps`;
CREATE TABLE `character_dynamic_difficulty_maps` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Player GUID',
  `mapId` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Id',
  PRIMARY KEY (`guid`,`mapId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `character_weekly_boss_kills`;
CREATE TABLE `character_weekly_boss_kills` (
  `guid` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Player GUID',
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Boss Entry',
  `mapId` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Id',
  `difficulty` mediumint(8) unsigned NOT NULL DEFAULT '0' COMMENT 'Difficulty',
  `looted` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT 'Boss looted',
  PRIMARY KEY (`guid`,`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Loot-based Lockout System';

ALTER TABLE `character_void_storage`
ADD COLUMN `reforgeId`  mediumint(8) NOT NULL AFTER `randomProperty`,
ADD COLUMN `transmogrifyId`  mediumint(8) NOT NULL AFTER `reforgeId`,
ADD COLUMN `upgradeId`  mediumint(8) NOT NULL AFTER `transmogrifyId`;