--
-- Table structure for table `corruption_effects`
--
DROP TABLE IF EXISTS `corruption_effects`;
CREATE TABLE `corruption_effects` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MinCorruption` float NOT NULL DEFAULT '0',
  `Aura` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
