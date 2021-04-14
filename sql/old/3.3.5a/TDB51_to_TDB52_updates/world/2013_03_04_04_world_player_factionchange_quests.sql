-- ----------------------------
-- Table structure for `player_factionchange_quests`
-- ----------------------------
DROP TABLE IF EXISTS `player_factionchange_quests`;
CREATE TABLE `player_factionchange_quests` (
  `alliance_id` int(10) unsigned NOT NULL,
  `horde_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`alliance_id`,`horde_id`),
  UNIQUE INDEX `alliance_uniq` (`alliance_id`),
  UNIQUE INDEX `horde_uniq` (`horde_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
