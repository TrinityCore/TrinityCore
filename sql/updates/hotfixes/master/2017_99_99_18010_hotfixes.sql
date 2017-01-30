DROP TABLE IF EXISTS `conversation_template`;
CREATE TABLE `conversation_template` (
  `Id` int (10) UNSIGNED NOT NULL,
  `Unk1` int (10) UNSIGNED NOT NULL,
  `Unk2` int (10) UNSIGNED NOT NULL,
  `Unk3` int (10) UNSIGNED NOT NULL,
  `NextLineID` smallint (5) UNSIGNED NOT NULL,
  `Unk4` smallint (5) UNSIGNED NOT NULL,
  `UnkBoolean` tinyint (3) UNSIGNED NOT NULL,
  `Unk5` tinyint (3) UNSIGNED NOT NULL,
  `Unk6` tinyint (3) UNSIGNED NOT NULL,
  `VerifiedBuild` int (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
