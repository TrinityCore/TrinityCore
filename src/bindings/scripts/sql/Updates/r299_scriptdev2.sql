CREATE TABLE `eventai_summons` (
`id` int(11) unsigned NOT NULL COMMENT 'Location Identifier' AUTO_INCREMENT,
`position_x` float NOT NULL default '0',
`position_y` float NOT NULL default '0',
`position_z` float NOT NULL default '0',
`orientation` float NOT NULL default '0',
`spawntimesecs` int(11) unsigned NOT NULL default '120',
PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Summoning Locations';