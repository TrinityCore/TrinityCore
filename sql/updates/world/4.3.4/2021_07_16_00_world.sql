ALTER TABLE `waypoints` 
ADD COLUMN `smoothTransition` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `delay`;

UPDATE `waypoints` SET `smoothTransition`= 1 WHERE `delay` < 0;
UPDATE `waypoints` SET `delay`= 0 WHERE `delay` < 0;

ALTER TABLE `waypoints` 
MODIFY COLUMN `delay` int UNSIGNED NOT NULL DEFAULT 0 AFTER `velocity`;
