CREATE TABLE `item_loot_template` (
  `entry` int(11) unsigned NOT NULL default '0',
  `item` int(11) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '100',
  `questchance` float NOT NULL default '0',
  `maxcount` int(11) unsigned NOT NULL default '1',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';
