/*ALTER TABLE db_version CHANGE COLUMN required_7290_01_mangos_command required_7292_01_mangos_points_of_interest bit;*/

DROP TABLE IF EXISTS `points_of_interest`;
CREATE TABLE `points_of_interest` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `icon` mediumint(8) unsigned NOT NULL default '0',
  `flags` mediumint(8) unsigned NOT NULL default '0',
  `data` mediumint(8) unsigned NOT NULL default '0',
  `icon_name` text NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
