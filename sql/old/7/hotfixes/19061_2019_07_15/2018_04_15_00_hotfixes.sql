--
-- Table structure for table `reward_pack_x_currency_type`
--
DROP TABLE IF EXISTS `reward_pack_x_currency_type`;
CREATE TABLE `reward_pack_x_currency_type` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CurrencyTypeID` int(10) unsigned NOT NULL DEFAULT '0',
  `Quantity` int(11) NOT NULL DEFAULT '0',
  `RewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
