ALTER TABLE `creature` MODIFY COLUMN `curHealthPct` int UNSIGNED NULL DEFAULT NULL AFTER `currentwaypoint`;

UPDATE `creature` SET `curHealthPct` = NULL WHERE `curHealthPct` <= 0 OR `curHealthPct` >= 100;
