DROP TABLE IF EXISTS `ai_playerbot_locks`;
CREATE TABLE `ai_playerbot_locks` (
  `name_id` mediumint(8) NOT NULL AUTO_INCREMENT UNIQUE,
  `gearlock` bit(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`name_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Playerbot locks';