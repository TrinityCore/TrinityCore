DROP TABLE IF EXISTS `battlenet_account_mounts`;

CREATE TABLE `battlenet_account_mounts` (
  `accountId` int(11) unsigned NOT NULL,
  `spellId` int(11) NOT NULL,
  `isFavourite` tinyint(1) NOT NULL,
  PRIMARY KEY (`accountId`,`spellId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
