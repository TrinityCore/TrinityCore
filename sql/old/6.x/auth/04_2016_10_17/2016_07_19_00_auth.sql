--
-- Table structure for table `battlenet_item_appearances`
--
DROP TABLE IF EXISTS `battlenet_item_appearances`;
CREATE TABLE `battlenet_item_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `blobIndex` smallint(5) unsigned NOT NULL,
  `appearanceMask` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`battlenetAccountId`,`blobIndex`),
  CONSTRAINT `fk_battlenet_item_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Table structure for table `battlenet_item_favorite_appearances`
--
DROP TABLE IF EXISTS `battlenet_item_favorite_appearances`;
CREATE TABLE `battlenet_item_favorite_appearances` (
  `battlenetAccountId` int(10) unsigned NOT NULL,
  `itemModifiedAppearanceId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`battlenetAccountId`,`itemModifiedAppearanceId`),
  CONSTRAINT `fk_battlenet_item_favorite_appearances` FOREIGN KEY (`battlenetAccountId`) REFERENCES `battlenet_accounts` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
