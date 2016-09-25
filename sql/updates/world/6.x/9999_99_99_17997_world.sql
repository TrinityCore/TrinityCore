DROP TABLE IF EXISTS `areatrigger_template`;
CREATE TABLE `areatrigger_template` (
  `Id` int(10) unsigned NOT NULL,
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `MoveCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `ScaleCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `MorphCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `FacingCurveId` int(10) unsigned NOT NULL DEFAULT '0',
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

INSERT INTO `areatrigger_template`(`id`,`flags`,`moveCurveId`,`scaleCurveId`,`morphCurveId`,`facingCurveId`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`scriptName`) VALUES
(2472,65536,0,0,0,0,0,0,0,0,0,0,''),
(4424,131072,0,0,0,0,3,3,4,4,1,1,'');

INSERT INTO `areatrigger_template_polygon_vertices`(`areatriggerId`,`Idx`,`verticeX`,`verticeY`,`verticeTargetX`,`verticeTargetY`) VALUES
(2472,0,-1,0.75,0,0),
(2472,1,-1,-0.75,0,0),
(2472,2,4,-0.75,0,0),
(2472,3,4,0.75,0,0);

