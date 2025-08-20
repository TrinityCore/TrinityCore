--
-- Table structure for table `world_state`
--
DROP TABLE IF EXISTS `world_state`;
CREATE TABLE `world_state` (
  `ID` int NOT NULL,
  `DefaultValue` int NOT NULL,
  `MapID` int unsigned DEFAULT NULL,
  `ScriptName` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `Comment` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
