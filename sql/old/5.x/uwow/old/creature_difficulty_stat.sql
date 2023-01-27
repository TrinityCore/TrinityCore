DROP TABLE IF EXISTS `creature_difficulty_stat`;

CREATE TABLE `creature_difficulty_stat` (
  `entry` int(11) unsigned NOT NULL,
  `difficulty` int(5) unsigned NOT NULL DEFAULT '0',
  `dmg_multiplier` float unsigned NOT NULL DEFAULT '1.15',
  `Health_mod` float unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`entry`,`difficulty`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;