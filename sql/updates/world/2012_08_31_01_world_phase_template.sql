DROP TABLE IF EXISTS `phase_template`;
CREATE TABLE `phase_template` (
  `id` mediumint(8) unsigned NOT NULL COMMENT 'id from Phase.dbc',
  `phaseMask` smallint(5) unsigned NOT NULL DEFAULT '1',
  `map` smallint(5) NOT NULL DEFAULT '0',
  `terrainSwap` smallint(5) unsigned NOT NULL DEFAULT '0',
  `unkFirstCounter` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;