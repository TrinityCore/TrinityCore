DROP TABLE IF EXISTS `areatrigger_template`;
CREATE TABLE `areatrigger_template` (
  `Id` int(10) unsigned NOT NULL,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Data0` float NOT NULL DEFAULT '0',
  `Data1` float NOT NULL DEFAULT '0',
  `Data2` float NOT NULL DEFAULT '0',
  `Data3` float NOT NULL DEFAULT '0',
  `Data4` float NOT NULL DEFAULT '0',
  `Data5` float NOT NULL DEFAULT '0',
  `TimeToTargetScale` int(10) unsigned NOT NULL DEFAULT '0',
  `ScriptName` char(64) NOT NULL DEFAULT '',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `areatrigger_template_polygon_vertices`;
CREATE TABLE `areatrigger_template_polygon_vertices` (
  `AreaTriggerId` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `VerticeX` float NOT NULL DEFAULT '0',
  `VerticeY` float NOT NULL DEFAULT '0',
  `VerticeTargetX` float NOT NULL DEFAULT '0',
  `VerticeTargetY` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`areatriggerId`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `areatrigger_template_auras`;
CREATE TABLE `areatrigger_template_auras` (
  `AreaTriggerId` int(10) unsigned NOT NULL,
  `AuraId` int(10) unsigned NOT NULL,
  `TargetType` int(10) unsigned NOT NULL DEFAULT '0',
  `CastType` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_areatrigger`;
CREATE TABLE `spell_areatrigger` (
  `SpellMiscId` int(10) unsigned NOT NULL,
  `AreatriggerId` int(10) unsigned NOT NULL,
  `MoveCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `ScaleCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `MorphCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `FacingCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellMiscId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_areatrigger` (`SpellMiscId`,`AreatriggerId`) VALUES
(4424, 9170),
(2472, 5207),
(4488, 9228);

INSERT INTO `areatrigger_template`(`Id`,`Flags`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`TimeToTargetScale`,`ScriptName`,`VerifiedBuild`) VALUES
(5207, 65536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 22810),
(9170, 131072,0, 0, 0, 0, 3, 3, 4, 4, 1, 1, 0, '', 22810),
(9228, 16384, 0, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, '', 22810);

INSERT INTO `areatrigger_template_polygon_vertices`(`AreaTriggerId`,`Idx`,`VerticeX`,`VerticeY`,`VerticeTargetX`,`VerticeTargetY`,`VerifiedBuild`) VALUES
(5207, 0, -1, 0.75,  0, 0, 22810),
(5207, 1, -1, -0.75, 0, 0, 22810),
(5207, 2, 4,  -0.75, 0, 0, 22810),
(5207, 3, 4,  0.75,  0, 0, 22810);

