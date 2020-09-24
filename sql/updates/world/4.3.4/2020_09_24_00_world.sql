--
ALTER TABLE `waypoint_data` ADD COLUMN `velocity` FLOAT DEFAULT 0 NOT NULL AFTER `orientation`;
