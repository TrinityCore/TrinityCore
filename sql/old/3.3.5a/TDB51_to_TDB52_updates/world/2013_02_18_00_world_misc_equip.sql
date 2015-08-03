-- creature_template.equipment_id deleted
-- creature_equip_template.entry == creature_template.entry
-- id field added to creature_equip_template -> PK(entry, id)
-- id field in creature_equip_template starts at 1
-- creature.equipment_id references id of creature_equip_template
-- creature.equipment_id = 0 means no equipment at all (default 1)
-- creature.equipment_id = -1 means pick a random equipment from creature_equip_template

-- Diff_entries should use the same template of the normal entry
UPDATE `creature_template` SET `equipment_id` = 0 WHERE `name` LIKE '%(1)' OR `name` LIKE '%(2)' OR `name` LIKE '%(3)' OR `name` LIKE '%(4)';

-- Delete unused templates
DROP TABLE IF EXISTS `temp_c_e`;
CREATE TABLE IF NOT EXISTS `temp_c_e` (`entry` mediumint(8));
ALTER TABLE `temp_c_e` ADD INDEX `ind` (`entry`);
INSERT INTO `temp_c_e` SELECT `equipment_id` FROM `creature_template` WHERE `equipment_id` != 0 UNION
                       SELECT `equipment_id` FROM `creature` WHERE `equipment_id` != 0 UNION
                       SELECT `equipment_id` FROM `game_event_model_equip` WHERE `equipment_id` != 0;
DELETE FROM `creature_equip_template` WHERE `entry` NOT IN (SELECT `entry` FROM `temp_c_e`);
DROP TABLE `temp_c_e`;

-- Create temporary table to hold the values of creature_equip_template with converted entry
DROP TABLE IF EXISTS `creature_equip_template2`;
CREATE TABLE IF NOT EXISTS `creature_equip_template2` (
  `entry` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `id` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `itemEntry1` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `itemEntry2` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `itemEntry3` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`, `id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO `creature_equip_template2` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`)
    SELECT `creature_template`.`entry`, 1, `itemEntry1`, `itemEntry2`, `itemEntry3`
    FROM `creature_template`
    JOIN `creature_equip_template` ON `creature_equip_template`.`entry` = `equipment_id`
    WHERE `equipment_id` != 0;

INSERT IGNORE INTO `creature_equip_template2` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`)
    SELECT `creature`.`id`, 2, `itemEntry1`, `itemEntry2`, `itemEntry3`
    FROM `creature`
    JOIN `creature_equip_template` ON `creature_equip_template`.`entry` = `equipment_id`
    WHERE `equipment_id` != 0;

DROP TABLE `creature_equip_template`;
RENAME TABLE `creature_equip_template2` TO `creature_equip_template`;

UPDATE `creature` SET `equipment_id` = 2 WHERE `equipment_id` != 0;
UPDATE `creature` SET `equipment_id` = 1 WHERE `equipment_id` = 0;

-- From game_event_model_equip
UPDATE `creature` SET `equipment_id` = 1 WHERE `guid` IN (12088, 12093, 12095, 79670, 79675, 79676, 79690, 79792, 79807, 79814);
UPDATE `game_event_model_equip` SET `equipment_id` = 2 WHERE `guid` IN (12088, 12093, 12095, 79670, 79675, 79676, 79690, 79792, 79807, 79814);
DELETE FROM `creature_equip_template` WHERE `entry` IN (1976, 23585, 424) AND `id`=2;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(1976, 2, 2715, 143, 0),
(23585, 2, 2715, 143, 0),
(424, 2, 2715, 143, 0);

-- ALTER TABLE `creature_equip_template` CHANGE `entry` `entry` mediumint(8) unsigned NOT NULL;
-- ALTER TABLE `creature_equip_template` ADD `id` tinyint(3) unsigned NOT NULL DEFAULT '1' AFTER `entry`;
-- ALTER TABLE `creature_equip_template` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`entry`, `id`);
ALTER TABLE `creature_template` DROP `equipment_id`;
ALTER TABLE `creature` CHANGE `equipment_id` `equipment_id` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `game_event_model_equip` CHANGE `equipment_id` `equipment_id` tinyint(3) unsigned NOT NULL DEFAULT '1';

-- Conversion from SAI
UPDATE `smart_scripts` SET `action_param1` = 1 WHERE `entryorguid` = 2523901 AND `source_type` = 9 AND `id` = 3;
UPDATE `smart_scripts` SET `action_param1` = 0 WHERE `entryorguid` = 2523900 AND `source_type` = 9 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 2 WHERE `entryorguid` = 32720   AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_equip_template` WHERE `entry` = 25239 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(25239, 1, 6829, 0, 0);
