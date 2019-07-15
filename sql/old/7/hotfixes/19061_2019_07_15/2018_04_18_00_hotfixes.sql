--
-- Table structure for table `item_limit_category_condition`
--
DROP TABLE IF EXISTS `item_limit_category_condition`;
CREATE TABLE `item_limit_category_condition` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `AddQuantity` tinyint(3) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `ParentItemLimitCategoryID` int(10) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
