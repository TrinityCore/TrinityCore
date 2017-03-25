DROP TABLE IF EXISTS `conversation_line`;
CREATE TABLE `conversation_line` (
  `Id` int (10) UNSIGNED NOT NULL,
  `BroadcastTextId` int (10) UNSIGNED NOT NULL,
  `SpellVisualKitID` int (10) UNSIGNED NOT NULL,
  `LineIntervalMS` int (10) UNSIGNED NOT NULL,
  `NextLineID` smallint (5) UNSIGNED NOT NULL,
  `Unk4` smallint (5) UNSIGNED NOT NULL,
  `UnkBoolean` tinyint (3) UNSIGNED NOT NULL,
  `Unk5` tinyint (3) UNSIGNED NOT NULL,
  `Unk6` tinyint (3) UNSIGNED NOT NULL,
  `VerifiedBuild` int (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
