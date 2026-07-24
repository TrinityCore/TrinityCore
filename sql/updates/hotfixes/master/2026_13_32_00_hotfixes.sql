--
-- Table structure for table `warband_scene_placement`
--
DROP TABLE IF EXISTS `warband_scene_placement`;
CREATE TABLE `warband_scene_placement` (
  `PositionX` float NOT NULL DEFAULT '0',
  `PositionY` float NOT NULL DEFAULT '0',
  `PositionZ` float NOT NULL DEFAULT '0',
  `ID` int unsigned NOT NULL DEFAULT '0',
  `WarbandSceneID` int NOT NULL DEFAULT '0',
  `SlotType` int NOT NULL DEFAULT '0',
  `Rotation` float NOT NULL DEFAULT '0',
  `Scale` float NOT NULL DEFAULT '0',
  `Field54210_004` int unsigned NOT NULL DEFAULT '0',
  `Field54210_005` int unsigned NOT NULL DEFAULT '0',
  `Field12063534_008` int NOT NULL DEFAULT '0',
  `SlotID` int NOT NULL DEFAULT '0',
  `Field12063534_010` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
