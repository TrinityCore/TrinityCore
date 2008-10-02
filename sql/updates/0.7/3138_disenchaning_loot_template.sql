DROP TABLE IF EXISTS `disenchant_loot_template`;
CREATE TABLE `disenchant_loot_template` (
  `entry` int(11) unsigned NOT NULL default '0',
  `item` int(11) unsigned NOT NULL default '0',
  `ChanceOrRef` float NOT NULL default '100',
  `QuestChanceOrGroup` tinyint(3) NOT NULL default '0',
  `mincount` tinyint(3) unsigned NOT NULL default '1',
  `maxcount` tinyint(3) unsigned NOT NULL default '1',
  `quest_freeforall` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';
