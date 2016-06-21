--
-- Table structure for table `item_upgrade`
--

DROP TABLE IF EXISTS `item_upgrade`;
CREATE TABLE `item_upgrade` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `UpgradePath` int(10) unsigned NOT NULL DEFAULT '0',
  `LevelUpgrade` int(10) unsigned NOT NULL DEFAULT '0',
  `prevUpgradeId` int(11) NOT NULL DEFAULT '0',
  `CurrencyId` int(11) NOT NULL DEFAULT '0',
  `CurrencyCost` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


--
-- Table structure for table `ruleset_item_upgrade`
--
DROP TABLE IF EXISTS `ruleset_item_upgrade`;
CREATE TABLE `ruleset_item_upgrade` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `unk` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemUpgradeID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


