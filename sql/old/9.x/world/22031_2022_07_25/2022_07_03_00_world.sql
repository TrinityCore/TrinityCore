--
-- Table structure for table `creature_summoned_data`
--
DROP TABLE IF EXISTS `creature_summoned_data`;
CREATE TABLE `creature_summoned_data` (
  `CreatureID` int unsigned NOT NULL,
  `CreatureIDVisibleToSummoner` int DEFAULT NULL,
  `GroundMountDisplayID` int unsigned DEFAULT NULL,
  `FlyingMountDisplayID` int unsigned DEFAULT NULL,
  PRIMARY KEY (`CreatureID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `creature_summoned_data`
--
INSERT INTO `creature_summoned_data` VALUES
(90382,90240,54563,46930),
(91911,91913,59339,NULL);
