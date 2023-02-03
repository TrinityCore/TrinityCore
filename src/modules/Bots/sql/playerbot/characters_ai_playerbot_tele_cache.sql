DROP TABLE IF EXISTS `ai_playerbot_tele_cache`;
CREATE TABLE `ai_playerbot_tele_cache` (
  `id` mediumint(8) auto_increment,
  `level` mediumint(8) NOT NULL,
  `map_id` mediumint(8) NOT NULL,
  `x` float(8) NOT NULL,
  `y` float(8) NOT NULL,
  `z` float(8) NOT NULL,
PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='PlayerbotAI Tele Cache';
