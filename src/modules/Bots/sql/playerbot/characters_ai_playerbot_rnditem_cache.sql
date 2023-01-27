DROP TABLE IF EXISTS `ai_playerbot_rnditem_cache`;
CREATE TABLE `ai_playerbot_rnditem_cache` (
  `id` bigint auto_increment,
  `lvl` mediumint(8) NOT NULL,
  `type` mediumint(8) NOT NULL,
  `item` mediumint(8) NOT NULL,
PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='PlayerbotAI Random Item Cache';
