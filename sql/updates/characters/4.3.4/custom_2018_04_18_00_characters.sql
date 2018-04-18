DROP TABLE IF EXISTS `character_rewardstatus_lfg`;
CREATE TABLE `character_rewardstatus_lfg`(  
  `guid` INT(10) NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `dungeonId` SMALLINT(3) NOT NULL DEFAULT 0 COMMENT 'Dungeon ID Identifier',
  `rewardCount` TINYINT(3) UNSIGNED DEFAULT 0 COMMENT 'Dungeon First Reward Count Identifier',
  `dailyReset` TINYINT(1) UNSIGNED DEFAULT 0 COMMENT 'Reward Count Daily Reset Identifier',
  PRIMARY KEY (`dungeonId`)
);
