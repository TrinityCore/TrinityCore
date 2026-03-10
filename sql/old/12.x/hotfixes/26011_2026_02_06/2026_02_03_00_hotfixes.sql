--
-- Table structure for table `trait_cond_account_element`
--
DROP TABLE IF EXISTS `trait_cond_account_element`;
CREATE TABLE `trait_cond_account_element` (
  `ElementValueInt` bigint NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `PlayerDataElementAccountID` int unsigned NOT NULL DEFAULT '0',
  `Comparison` tinyint unsigned NOT NULL DEFAULT '0',
  `Unused1110` int NOT NULL DEFAULT '0',
  `PlayerDataElementCharacterID` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
