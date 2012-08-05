DELETE FROM `gameobject` WHERE map IN (0, 1);

DROP TABLE IF EXISTS `export_id`;
CREATE TABLE `export_id` (`id` INT(10) UNSIGNED NULL,  PRIMARY KEY (`id`) ) COLLATE='latin1_swedish_ci' ENGINE=InnoDB ROW_FORMAT=DEFAULT;

REPLACE INTO `export_id` SELECT `guid` FROM `creature` WHERE `map` IN (0, 1);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT id FROM export_id);
DELETE FROM `creature` WHERE `map` IN (0, 1);

DROP TABLE IF EXISTS `export_id`;