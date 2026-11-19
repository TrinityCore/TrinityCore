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

INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5644, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5645, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5646, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5647, 0, 669, 'Blackwing Descent - Omnotron Defense System - Achieve-a-tron'),
(5117, 0, 670, 'Grim Batol - Erudax - Don\'t need to Break Eggs to Make an Omelet');
