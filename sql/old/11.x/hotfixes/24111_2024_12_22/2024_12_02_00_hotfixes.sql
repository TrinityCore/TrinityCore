--
-- Table structure for table `creature_label`
--
DROP TABLE IF EXISTS `creature_label`;
CREATE TABLE `creature_label` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `LabelID` int NOT NULL DEFAULT '0',
  `CreatureDifficultyID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `gameobject_label`
--
DROP TABLE IF EXISTS `gameobject_label`;
CREATE TABLE `gameobject_label` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `LabelID` int NOT NULL DEFAULT '0',
  `GameObjectID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
