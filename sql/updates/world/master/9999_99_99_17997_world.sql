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

DROP TABLE IF EXISTS `areatrigger_template_splines`;
CREATE TABLE `areatrigger_template_splines` (
  `MoveCurveId` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `SplineX` float NOT NULL DEFAULT '0',
  `SplineY` float NOT NULL DEFAULT '0',
  `SplineZ` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`MoveCurveId`,`Idx`)
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
  `TimeToTarget` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeToTargetScale` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellMiscId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `spell_areatrigger` (`SpellMiscId`,`AreatriggerId`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`TimeToTarget`,`TimeToTargetScale`) VALUES
(4424, 9170, 0, 0, 0, 0, 0, 0),
(2472, 5207, 0, 0, 0, 0, 0, 0),
(4488, 9228, 0, 0, 0, 0, 0, 0);

INSERT INTO `areatrigger_template`(`Id`,`Flags`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`ScriptName`,`VerifiedBuild`) VALUES
(5207, 65536, 0, 0, 0, 0, 0, 0, '', 22810),
(9170, 131072,3, 3, 4, 4, 1, 1, '', 22810),
(9228, 16384, 8, 8, 0, 0, 0, 0, '', 22810);

INSERT INTO `areatrigger_template_polygon_vertices`(`AreaTriggerId`,`Idx`,`VerticeX`,`VerticeY`,`VerticeTargetX`,`VerticeTargetY`,`VerifiedBuild`) VALUES
(5207, 0, -1, 0.75,  0, 0, 22810),
(5207, 1, -1, -0.75, 0, 0, 22810),
(5207, 2, 4,  -0.75, 0, 0, 22810),
(5207, 3, 4,  0.75,  0, 0, 22810);

