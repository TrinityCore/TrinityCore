DROP TABLE IF EXISTS `spell_areatrigger_vertices`;
CREATE TABLE `spell_areatrigger_vertices` (
  `SpellMiscId` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `VerticeX` float NOT NULL DEFAULT '0',
  `VerticeY` float NOT NULL DEFAULT '0',
  `VerticeTargetX` float DEFAULT NULL,
  `VerticeTargetY` float DEFAULT NULL,
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellMiscId`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_areatrigger_vertices`
  SELECT `sa`.`SpellMiscId`,`atpv`.`Idx`,`atpv`.`VerticeX`,`atpv`.`VerticeY`,`atpv`.`VerticeTargetX`,`atpv`.`VerticeTargetY`,`atpv`.`VerifiedBuild`
  FROM `spell_areatrigger` `sa`
  INNER JOIN `areatrigger_template_polygon_vertices` `atpv` ON `sa`.`AreaTriggerId`=`atpv`.`AreaTriggerId`;

DROP TABLE `areatrigger_template_polygon_vertices`;
