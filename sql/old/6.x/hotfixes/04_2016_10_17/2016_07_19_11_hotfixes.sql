--
-- Table structure for table `item_child_equipment`
--
DROP TABLE IF EXISTS `item_child_equipment`;
CREATE TABLE `item_child_equipment` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltItemID` int(10) unsigned NOT NULL DEFAULT '0',
  `AltEquipmentSlot` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
