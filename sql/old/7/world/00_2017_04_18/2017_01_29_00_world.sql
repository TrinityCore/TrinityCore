DROP TABLE IF EXISTS `areatrigger_template`;
CREATE TABLE `areatrigger_template` (
  `Id` int(10) unsigned NOT NULL,
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Data0` float NOT NULL DEFAULT '0',
  `Data1` float NOT NULL DEFAULT '0',
  `Data2` float NOT NULL DEFAULT '0',
  `Data3` float NOT NULL DEFAULT '0',
  `Data4` float NOT NULL DEFAULT '0',
  `Data5` float NOT NULL DEFAULT '0',
  `ScriptName` char(64) NOT NULL DEFAULT '',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `areatrigger_template_polygon_vertices`;
CREATE TABLE `areatrigger_template_polygon_vertices` (
  `AreaTriggerId` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `VerticeX` float NOT NULL DEFAULT '0',
  `VerticeY` float NOT NULL DEFAULT '0',
  `VerticeTargetX` float NULL,
  `VerticeTargetY` float NULL,
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`AreaTriggerId`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `areatrigger_template_actions`;
CREATE TABLE `areatrigger_template_actions` (
  `AreaTriggerId` int(10) unsigned NOT NULL,
  `ActionType` int(10) unsigned NOT NULL,
  `ActionParam` int(10) unsigned NOT NULL,
  `TargetType` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`AreaTriggerId`, `ActionType`, `ActionParam`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_areatrigger`;
CREATE TABLE `spell_areatrigger` (
  `SpellMiscId` int(10) unsigned NOT NULL,
  `AreaTriggerId` int(10) unsigned NOT NULL,
  `MoveCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `ScaleCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `MorphCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `FacingCurveId` int(10) unsigned NOT NULL DEFAULT '0',
  `DecalPropertiesId` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeToTarget` int(10) unsigned NOT NULL DEFAULT '0',
  `TimeToTargetScale` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellMiscId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_areatrigger_splines`;
CREATE TABLE `spell_areatrigger_splines` (
  `SpellMiscId` int(10) unsigned NOT NULL,
  `Idx` int(10) unsigned NOT NULL,
  `X` float NOT NULL DEFAULT '0',
  `Y` float NOT NULL DEFAULT '0',
  `Z` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`SpellMiscId`,`Idx`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
