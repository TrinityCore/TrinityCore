DROP TABLE IF EXISTS `instance`;
CREATE TABLE `instance` (
  `id` int(11) unsigned NOT NULL default '0' COMMENT 'instance id',
  `mapid` int(11) unsigned NOT NULL default '0' COMMENT 'real mapid',
  `state` int(11) NOT NULL default '0' COMMENT 'this instance state',
  `players` int(11) NOT NULL COMMENT 'map creater guid who in this instance',
  `lefttime` int(11) NOT NULL default '0' COMMENT 'this instance  left time',
   PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

