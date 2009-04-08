ALTER TABLE db_version CHANGE COLUMN required_7622_03_mangos_creature_ai_texts required_7627_01_mangos_achievement_criteria_data bit;

DROP TABLE IF EXISTS `achievement_criteria_data`;
CREATE TABLE `achievement_criteria_data` (
  `criteria_id` mediumint(8) NOT NULL,
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `value1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `value2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`criteria_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Achievment system';
