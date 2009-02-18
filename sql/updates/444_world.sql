DROP TABLE IF EXISTS `waypoint_data`;

CREATE TABLE `waypoint_data` (
  `id` int(10) unsigned NOT NULL default '0' COMMENT 'Creature GUID',
  `point` mediumint(8) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `move_flag` tinyint(1) NOT NULL default '0',
  `action` int(11) NOT NULL default '0',
  `action_chance` smallint(3) NOT NULL default '100',
  `wpguid` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `waypoint_scripts`;

CREATE TABLE `waypoint_scripts` (
  `id` int(11) unsigned NOT NULL default '0',
  `delay` int(11) unsigned NOT NULL default '0',
  `command` int(11) unsigned NOT NULL default '0',
  `datalong` int(11) unsigned NOT NULL default '0',
  `datalong2` int(11) unsigned NOT NULL default '0',
  `dataint` int(11) unsigned NOT NULL default '0',
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0',
  `guid` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `creature_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `guid`;
ALTER TABLE `creature_template_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `entry`;

