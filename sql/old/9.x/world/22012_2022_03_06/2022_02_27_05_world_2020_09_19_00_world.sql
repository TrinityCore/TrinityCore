--
ALTER TABLE `waypoints` ADD COLUMN `orientation` FLOAT DEFAULT 0 NOT NULL AFTER `position_z`, ADD COLUMN `delay` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `orientation`;
