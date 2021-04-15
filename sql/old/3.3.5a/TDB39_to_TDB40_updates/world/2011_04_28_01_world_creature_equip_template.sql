ALTER TABLE `creature_equip_template`
CHANGE `entry` `entry` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `equipentry1` `itemEntry1` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `equipentry2` `itemEntry2` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `equipentry3` `itemEntry3` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL,
ADD COLUMN `newEntry` INT UNSIGNED AUTO_INCREMENT,
ADD INDEX(newEntry),
DROP PRIMARY KEY;

UPDATE `creature_template` ct, `creature_equip_template` cet
SET ct.`equipment_id` = cet.`newEntry`
WHERE ct.`equipment_id` = cet.`entry`;

UPDATE `game_event_model_equip` geme, `creature_equip_template` cet
SET geme.`equipment_id` = cet.`newEntry`
WHERE geme.`equipment_id` = cet.`entry`;

UPDATE `creature` c, `creature_equip_template` cet
SET c.`equipment_id` = cet.`newEntry`
WHERE c.`equipment_id` = cet.`entry`;

UPDATE `creature_equip_template` SET `entry` = `newEntry`;

ALTER TABLE `creature_equip_template`
ADD PRIMARY KEY(`entry`),
DROP COLUMN `newEntry`;