DROP TABLE IF EXISTS `playercreateinfo_cast_spell`;
CREATE TABLE IF NOT EXISTS `playercreateinfo_cast_spell` (
  `raceMask` int(10) unsigned NOT NULL DEFAULT '0',
  `classMask` int(10) unsigned NOT NULL DEFAULT '0',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `note` varchar(255) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
