DROP TABLE IF EXISTS `phase_area`;
CREATE TABLE `phase_area` (
  `phase` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `area` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `quest_start` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `quest_start_active` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `quest_end` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`phase`,`area`,`quest_start`,`quest_start_active`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;