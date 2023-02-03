DROP TABLE IF EXISTS `ai_playerbot_equip_cache`;
CREATE TABLE `ai_playerbot_equip_cache` (
  `id` bigint auto_increment,
  `clazz` mediumint(8) NOT NULL,
  `lvl` mediumint(8) NOT NULL,
  `slot` mediumint(8) NOT NULL,
  `quality` mediumint(8) NOT NULL,
  `item` mediumint(8) NOT NULL,
PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='PlayerbotAI equip Cache';
