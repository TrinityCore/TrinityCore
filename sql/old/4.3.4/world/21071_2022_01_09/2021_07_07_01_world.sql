ALTER TABLE `waypoint_data` 
ADD COLUMN `smoothTransition` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `delay`;

UPDATE `waypoint_data` SET `smoothTransition`= 1 WHERE `delay` < 0;
UPDATE `waypoint_data` SET `delay`= 0 WHERE `delay` < 0;

ALTER TABLE `waypoint_data` 
MODIFY COLUMN `delay` int UNSIGNED NOT NULL DEFAULT 0 AFTER `velocity`;
