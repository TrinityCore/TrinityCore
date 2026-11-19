DROP TABLE IF EXISTS `battlenet_account_heirlooms`;

CREATE TABLE `battlenet_account_heirlooms` (
  `accountId` int(10) unsigned NOT NULL,
  `itemId` int(11) unsigned NOT NULL DEFAULT '0',
  `flags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`accountId`,`itemId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
