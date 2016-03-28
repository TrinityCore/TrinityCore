DROP TABLE IF EXISTS `battlenet_components`;
DROP TABLE IF EXISTS `battlenet_modules`;

DROP TABLE IF EXISTS `account_last_played_character`;
CREATE TABLE `account_last_played_character` (
  `accountId` int(10) unsigned NOT NULL,
  `region` tinyint(3) unsigned NOT NULL,
  `battlegroup` tinyint(3) unsigned NOT NULL,
  `realmId` int(10) unsigned,
  `characterName` varchar(12),
  `characterGUID` bigint(20) unsigned,
  `lastPlayedTime` int(10) unsigned,
  PRIMARY KEY(`accountId`,`region`,`battlegroup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `battlenet_accounts`
  DROP `s`,
  DROP `v`,
  DROP `sessionKey`;

UPDATE `realmlist` SET `gamebuild`=21355 WHERE `gamebuild`=20726;
