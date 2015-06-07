DROP TABLE IF EXISTS `account_mounts`;
CREATE TABLE `account_mounts` (
  `accountId` INT(10) unsigned NOT NULL DEFAULT '0',
  `spell` MEDIUMINT(8) unsigned NOT NULL DEFAULT '0',
  `favorite` BOOL DEFAULT FALSE,
  PRIMARY KEY (`accountId`, `spell`)
);
