DROP TABLE IF EXISTS `conversation_line`;
CREATE TABLE `conversation_line` (
  `Id` int (10) UNSIGNED NOT NULL,
  `BroadcastTextID` int (10) UNSIGNED NOT NULL,
  `SpellVisualKitID` int (10) UNSIGNED NOT NULL,
  `Duration` int (10) UNSIGNED NOT NULL,
  `NextLineID` smallint (5) UNSIGNED NOT NULL,
  `Unk1` smallint (5) UNSIGNED NOT NULL,
  `Yell` tinyint (3) UNSIGNED NOT NULL,
  `Unk2` tinyint (3) UNSIGNED NOT NULL,
  `Unk3` tinyint (3) UNSIGNED NOT NULL,
  `VerifiedBuild` int (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
