DROP TABLE IF EXISTS `battlenet_account_toys`;

CREATE TABLE `battlenet_account_toys` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(11) NOT NULL DEFAULT '0',
  `isFavourite` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
