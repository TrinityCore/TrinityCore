ALTER TABLE db_version CHANGE COLUMN required_7034_01_mangos_spell_proc_event required_7040_01_mangos_achievement_reward bit;

DROP TABLE IF EXISTS `achievement_reward`;
CREATE TABLE `achievement_reward` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `title_A` mediumint(8) unsigned NOT NULL default '0',
  `title_H` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `sender` mediumint(8) unsigned NOT NULL default '0',
  `subject` varchar(255) default NULL,
  `text` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';


DROP TABLE IF EXISTS `locales_achievement_reward`;
CREATE TABLE `locales_achievement_reward` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `subject_loc1` varchar(100) NOT NULL default '',
  `subject_loc2` varchar(100) NOT NULL default '',
  `subject_loc3` varchar(100) NOT NULL default '',
  `subject_loc4` varchar(100) NOT NULL default '',
  `subject_loc5` varchar(100) NOT NULL default '',
  `subject_loc6` varchar(100) NOT NULL default '',
  `subject_loc7` varchar(100) NOT NULL default '',
  `subject_loc8` varchar(100) NOT NULL default '',
  `text_loc1` text default NULL,
  `text_loc2` text default NULL,
  `text_loc3` text default NULL,
  `text_loc4` text default NULL,
  `text_loc5` text default NULL,
  `text_loc6` text default NULL,
  `text_loc7` text default NULL,
  `text_loc8` text default NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
