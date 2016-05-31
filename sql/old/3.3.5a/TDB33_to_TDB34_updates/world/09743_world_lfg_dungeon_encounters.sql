DROP TABLE IF EXISTS `lfg_dungeon_encounters`;
CREATE TABLE `lfg_dungeon_encounters` (
  `achievementId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Achievement marking final boss completion',
  `dungeonId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Dungeon entry from dbc',
  PRIMARY KEY (`achievementId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
