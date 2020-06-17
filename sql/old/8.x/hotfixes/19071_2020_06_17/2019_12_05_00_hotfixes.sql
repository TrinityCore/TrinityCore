--
-- Table structure for table `azerite_empowered_item`
--
DROP TABLE IF EXISTS `azerite_empowered_item`;
CREATE TABLE `azerite_empowered_item` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(11) NOT NULL DEFAULT '0',
  `AzeriteTierUnlockSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `AzeritePowerSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_power_set_member`
--
DROP TABLE IF EXISTS `azerite_power_set_member`;
CREATE TABLE `azerite_power_set_member` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AzeritePowerSetID` int(11) NOT NULL DEFAULT '0',
  `AzeritePowerID` int(11) NOT NULL DEFAULT '0',
  `Class` int(11) NOT NULL DEFAULT '0',
  `Tier` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_tier_unlock`
--
DROP TABLE IF EXISTS `azerite_tier_unlock`;
CREATE TABLE `azerite_tier_unlock` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemCreationContext` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Tier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AzeriteLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AzeriteTierUnlockSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_tier_unlock_set`
--
DROP TABLE IF EXISTS `azerite_tier_unlock_set`;
CREATE TABLE `azerite_tier_unlock_set` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `azerite_unlock_mapping`
--
DROP TABLE IF EXISTS `azerite_unlock_mapping`;
CREATE TABLE `azerite_unlock_mapping` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevel` int(11) NOT NULL DEFAULT '0',
  `ItemBonusListHead` int(11) NOT NULL DEFAULT '0',
  `ItemBonusListShoulders` int(11) NOT NULL DEFAULT '0',
  `ItemBonusListChest` int(11) NOT NULL DEFAULT '0',
  `AzeriteUnlockMappingSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
