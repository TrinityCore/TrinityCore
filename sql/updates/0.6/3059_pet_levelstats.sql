CREATE TABLE `pet_levelstats` (
  `creature_entry` int(11) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL,
  `hp`   smallint(5) unsigned NOT NULL,
  `mana` smallint(5) unsigned NOT NULL,
  `str`  smallint(5) unsigned NOT NULL,
  `agi`  smallint(5) unsigned NOT NULL,
  `sta`  smallint(5) unsigned NOT NULL,
  `int`  smallint(5) unsigned NOT NULL,
  `spi`  smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`creature_entry`,`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 PACK_KEYS=0 COMMENT='Stores pet levels stats.';
