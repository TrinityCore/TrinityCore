DROP TABLE IF EXISTS `item`;
CREATE TABLE `item` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Class` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `SubClass` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `SoundOverrideSubclass` mediumint(8) NOT NULL DEFAULT '0',
  `Material` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `InventoryType` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `SheathType` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `IconFileDataID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `ItemGroupSoundsID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
