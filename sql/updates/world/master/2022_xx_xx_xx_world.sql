-- waypoints
ALTER TABLE `waypoints` 
	ADD COLUMN `smoothTransition` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `delay`;

-- waypoint_data
ALTER TABLE `waypoint_data`
	ADD COLUMN `velocity` FLOAT NOT NULL DEFAULT 0 AFTER `orientation`,
	ADD COLUMN `smoothTransition` TINYINT UNSIGNED NOT NULL DEFAULT 0 AFTER `delay`;

-- waypoint_data_addon
DROP TABLE IF EXISTS `waypoint_data_addon`;
CREATE TABLE `waypoint_data_addon` (  
  `PathID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `PointID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `SplinePointIndex` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
  `PositionX` FLOAT NOT NULL DEFAULT 0,
  `PositionY` FLOAT NOT NULL DEFAULT 0,
  `PositionZ` FLOAT NOT NULL DEFAULT 0
);
