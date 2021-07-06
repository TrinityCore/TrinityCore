ALTER TABLE `waypoints` 
  ADD COLUMN `orientation` float NULL DEFAULT NULL AFTER `position_z`,
  ADD COLUMN `velocity` float NOT NULL DEFAULT 0 AFTER `orientation`,
  ADD COLUMN `delay` int(10) NOT NULL DEFAULT 0 AFTER `velocity`;
