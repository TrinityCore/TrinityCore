--
-- Table structure for table `spell_keybound_override`
--
DROP TABLE IF EXISTS `spell_keybound_override`;
CREATE TABLE `spell_keybound_override` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Function` text,
  `Type` tinyint(4) NOT NULL DEFAULT '0',
  `Data` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
