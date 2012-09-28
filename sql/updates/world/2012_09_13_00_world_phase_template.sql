DROP TABLE IF EXISTS `phase_template`;
CREATE TABLE `phase_template` (
  `entry` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `area` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `phaseId` mediumint(8) unsigned NOT NULL COMMENT 'id from Phase.dbc',
  `phaseMask` smallint(5) unsigned NOT NULL DEFAULT '1',
  `map` smallint(6) NOT NULL DEFAULT '-1',
  `terrainSwap` smallint(5) unsigned NOT NULL DEFAULT '0',
  `unkFirstCounter` smallint(5) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;
