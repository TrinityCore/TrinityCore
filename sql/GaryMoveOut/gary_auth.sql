-- [MOD] CharacterHistory.
DROP TABLE IF EXISTS `character_history`;
CREATE TABLE `character_history` (
  `HistoryId` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `AccountId` int(10) unsigned NOT NULL DEFAULT '0',
  `RealmId` int(10) unsigned NOT NULL DEFAULT '0',
  `SessionIP` varchar(32) NOT NULL,
  `HistoryType` tinyint(2) unsigned NOT NULL DEFAULT '0',
  `CharacterGuid` int(10) unsigned NOT NULL DEFAULT '0',
  `CharacterName` varchar(12) NOT NULL,
  `HistoryTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`HistoryId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
