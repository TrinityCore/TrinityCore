DROP TABLE IF EXISTS `game_event_model_equip`;
CREATE TABLE `game_event_model_equip` (
  `guid` int(11) unsigned NOT NULL DEFAULT '0',
  `modelid` int(11) unsigned NOT NULL DEFAULT '0',
  `equipment_id` int(11) unsigned NOT NULL DEFAULT '0',
  `event` mediumint(9) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
