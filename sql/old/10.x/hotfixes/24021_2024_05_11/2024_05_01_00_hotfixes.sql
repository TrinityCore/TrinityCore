--
-- Table structure for table `spell_empower`
--
DROP TABLE IF EXISTS `spell_empower`;
CREATE TABLE `spell_empower` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SpellID` int NOT NULL DEFAULT '0',
  `Unused1000` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `spell_empower_stage`
--
DROP TABLE IF EXISTS `spell_empower_stage`;
CREATE TABLE `spell_empower_stage` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Stage` int NOT NULL DEFAULT '0',
  `DurationMs` int NOT NULL DEFAULT '0',
  `SpellEmpowerID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
