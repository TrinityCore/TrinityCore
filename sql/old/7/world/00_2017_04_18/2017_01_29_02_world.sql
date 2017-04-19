DROP TABLE IF EXISTS `character_template`;
CREATE TABLE IF NOT EXISTS `character_template` (
  `Id` int(10) unsigned NOT NULL,
  `Name` varchar(70) NOT NULL,
  `Description` varchar(100) NOT NULL,
  `Level` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_template_class`;
CREATE TABLE IF NOT EXISTS `character_template_class` (
  `TemplateId` int(10) unsigned NOT NULL,
  `FactionGroup` tinyint(3) unsigned NOT NULL COMMENT '3 - Alliance, 5 - Horde',
  `Class` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`TemplateId`,`FactionGroup`,`Class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
