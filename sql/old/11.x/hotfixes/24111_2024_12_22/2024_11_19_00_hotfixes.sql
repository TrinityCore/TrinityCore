--
-- Table structure for table `mount_equipment`
--
DROP TABLE IF EXISTS `mount_equipment`;
CREATE TABLE `mount_equipment` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Item` int NOT NULL DEFAULT '0',
  `BuffSpell` int NOT NULL DEFAULT '0',
  `Unknown820` int NOT NULL DEFAULT '0',
  `LearnedBySpell` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
