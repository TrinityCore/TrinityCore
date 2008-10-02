DROP TABLE IF EXISTS `transports`;
CREATE TABLE `transports` (
  `entry` int(11) unsigned NOT NULL default '0',
  `name` text,
  `period` int(11) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Transports';

