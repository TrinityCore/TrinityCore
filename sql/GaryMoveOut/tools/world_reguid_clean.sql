-- Variables, which define guid to start with
SET @START_GUID_CRE := 300000;
SET @START_GUID_GOB := 300000;

-- ====== Reguid ======
-- Execute in world-database
-- No cleanup at all for world database, core self diagnostics are more useful

-- REPLACE: `characters` with your characters database name

-- ====== CREATE TEMP TABLE - CRE GUIDS ======
DROP TABLE IF EXISTS `tmp_cre_guid_table`;
CREATE TABLE `tmp_cre_guid_table` (
	`guid_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`guid` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_cre_guid_table` AUTO_INCREMENT = ', @START_GUID_CRE);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_cre_guid_table` (`guid`) SELECT `guid` FROM `creature` WHERE `guid` > @START_GUID_CRE ORDER BY `guid` ASC;



-- ====== CREATE TEMP TABLE - CRE GUIDS ======
DROP TABLE IF EXISTS `tmp_path_id_table`;
CREATE TABLE `tmp_path_id_table` (
	`path_id` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

INSERT INTO `tmp_path_id_table` (`path_id`) SELECT `path_id` FROM `creature_addon` WHERE `path_id` > @START_GUID_CRE * 10 AND `path_id` NOT IN (SELECT `path_id` FROM `creature_template_addon`) ORDER BY `path_id` ASC;



-- ====== CREATE TEMP TABLE - GOB GUIDS ======
DROP TABLE IF EXISTS `tmp_gob_guid_table`;
CREATE TABLE `tmp_gob_guid_table` (
	`guid_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`guid` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_gob_guid_table` AUTO_INCREMENT = ', @START_GUID_GOB);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_gob_guid_table` (`guid`) SELECT `guid` FROM `gameobject` WHERE `guid` > @START_GUID_GOB ORDER BY `guid` ASC;



-- ====== BEGIN PROCESSING - CRE GUIDS ======

-- TABLE: conditions
UPDATE `conditions` JOIN `tmp_cre_guid_table` ON -(`conditions`.`SourceEntry`) = `tmp_cre_guid_table`.`guid` SET `conditions`.`SourceEntry` = -(`tmp_cre_guid_table`.`guid_new`) WHERE `SourceTypeOrReferenceId` = 22;

-- TABLE: creature
UPDATE `creature` JOIN `tmp_cre_guid_table` ON `creature`.`guid` = `tmp_cre_guid_table`.`guid` SET `creature`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: creature_addon
-- Add some keys to improve performance
ALTER TABLE `creature_addon` ADD INDEX `idx_path` (`path_id`);
UPDATE `creature_addon` JOIN `tmp_cre_guid_table` ON `creature_addon`.`guid` = `tmp_cre_guid_table`.`guid` SET `creature_addon`.`path_id` = 10 * (`tmp_cre_guid_table`.`guid_new`) WHERE `creature_addon`.`path_id` IN (SELECT `path_id` FROM `tmp_path_id_table`);
UPDATE `creature_addon` JOIN `tmp_cre_guid_table` ON `creature_addon`.`guid` = `tmp_cre_guid_table`.`guid` SET `creature_addon`.`guid` = `tmp_cre_guid_table`.`guid_new`;
ALTER TABLE `creature_addon` DROP INDEX `idx_path`;

-- TABLE: creature_formations
-- Add some keys to improve performance
ALTER TABLE `creature_formations` ADD INDEX `idx_lead` (`leaderGUID`);
UPDATE `creature_formations` JOIN `tmp_cre_guid_table` ON `creature_formations`.`memberGUID` = `tmp_cre_guid_table`.`guid` SET `creature_formations`.`memberGUID` = `tmp_cre_guid_table`.`guid_new`;
UPDATE `creature_formations` JOIN `tmp_cre_guid_table` ON `creature_formations`.`leaderGUID` = `tmp_cre_guid_table`.`guid` SET `creature_formations`.`leaderGUID` = `tmp_cre_guid_table`.`guid_new`;
ALTER TABLE `creature_formations` DROP INDEX `idx_lead`;

-- TABLE: creature_template_addon
-- Add some keys to improve performance
ALTER TABLE `creature_template_addon` ADD INDEX `idx_path` (`path_id`);
UPDATE `creature_template_addon` JOIN `tmp_cre_guid_table` ON `creature_template_addon`.`path_id` = 10 * (`tmp_cre_guid_table`.`guid`) SET `creature_template_addon`.`path_id` = 10 * (`tmp_cre_guid_table`.`guid_new`) WHERE `creature_template_addon`.`path_id` IN (SELECT `path_id` FROM `tmp_path_id_table`);
ALTER TABLE `creature_template_addon` DROP INDEX `idx_path`;

-- TABLE: game_event_creature
UPDATE `game_event_creature` JOIN `tmp_cre_guid_table` ON `game_event_creature`.`guid` = `tmp_cre_guid_table`.`guid` SET `game_event_creature`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: game_event_npc_vendor
UPDATE `game_event_npc_vendor` JOIN `tmp_cre_guid_table` ON `game_event_npc_vendor`.`guid` = `tmp_cre_guid_table`.`guid` SET `game_event_npc_vendor`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: game_event_npcflag
UPDATE `game_event_npcflag` JOIN `tmp_cre_guid_table` ON `game_event_npcflag`.`guid` = `tmp_cre_guid_table`.`guid` SET `game_event_npcflag`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: linked_respawn
-- Add some keys to improve performance
ALTER TABLE `linked_respawn` ADD INDEX `idx_link` (`linkedGuid`);
UPDATE `linked_respawn` JOIN `tmp_cre_guid_table` ON `linked_respawn`.`guid` = `tmp_cre_guid_table`.`guid` SET `linked_respawn`.`guid` = `tmp_cre_guid_table`.`guid_new`;
UPDATE `linked_respawn` JOIN `tmp_cre_guid_table` ON `linked_respawn`.`linkedGuid` = `tmp_cre_guid_table`.`guid` SET `linked_respawn`.`linkedGuid` = `tmp_cre_guid_table`.`guid_new`;
ALTER TABLE `linked_respawn` DROP INDEX `idx_link`;

-- TABLE: pool_creature
UPDATE `pool_creature` JOIN `tmp_cre_guid_table` ON `pool_creature`.`guid` = `tmp_cre_guid_table`.`guid` SET `pool_creature`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: smart_scripts
UPDATE `smart_scripts` JOIN `tmp_cre_guid_table` ON -(`smart_scripts`.`entryorguid`) = `tmp_cre_guid_table`.`guid` SET `smart_scripts`.`entryorguid` = -(`tmp_cre_guid_table`.`guid_new`) WHERE `source_type` = 0;

-- TABLE: vehicle_accessory
UPDATE `vehicle_accessory` JOIN `tmp_cre_guid_table` ON `vehicle_accessory`.`guid` = `tmp_cre_guid_table`.`guid` SET `vehicle_accessory`.`guid` = `tmp_cre_guid_table`.`guid_new`;

-- TABLE: waypoint_data
-- Add some keys to improve performance
ALTER TABLE `waypoint_data` ADD INDEX `idx_id` (`id`);
UPDATE `waypoint_data` JOIN `tmp_cre_guid_table` ON `waypoint_data`.`id` = 10 * (`tmp_cre_guid_table`.`guid`) SET `waypoint_data`.`id` = 10 * (`tmp_cre_guid_table`.`guid_new`) WHERE `id` IN (SELECT `path_id` FROM `tmp_path_id_table`);
ALTER TABLE `waypoint_data` DROP INDEX `idx_id`;

-- TABLE: `characters`.creature_respawn
UPDATE `characters`.`creature_respawn` JOIN `tmp_cre_guid_table` ON `characters`.`creature_respawn`.`guid` = `tmp_cre_guid_table`.`guid` SET `characters`.`creature_respawn`.`guid` = `tmp_cre_guid_table`.`guid_new`;


-- ====== BEGIN PROCESSING - GOB GUIDS ======

-- TABLE: event_scripts
-- Add some keys to improve performance
ALTER TABLE `event_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `event_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `event_scripts` JOIN `tmp_gob_guid_table` ON `event_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `event_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `event_scripts` JOIN `tmp_gob_guid_table` ON `event_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `event_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `event_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `event_scripts` DROP INDEX `idx_datalong2`;

-- TABLE: game_event_gameobject
UPDATE `game_event_gameobject` JOIN `tmp_gob_guid_table` ON `game_event_gameobject`.`guid` = `tmp_gob_guid_table`.`guid` SET `game_event_gameobject`.`guid` = `tmp_gob_guid_table`.`guid_new`;

-- TABLE: gameobject
UPDATE `gameobject` JOIN `tmp_gob_guid_table` ON `gameobject`.`guid` = `tmp_gob_guid_table`.`guid` SET `gameobject`.`guid` = `tmp_gob_guid_table`.`guid_new`;

-- TABLE: gameobject_scripts
-- Add some keys to improve performance
ALTER TABLE `gameobject_scripts` ADD INDEX `idx_id` (`id`);
ALTER TABLE `gameobject_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `gameobject_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `gameobject_scripts` JOIN `tmp_gob_guid_table` ON `gameobject_scripts`.`id` = `tmp_gob_guid_table`.`guid` SET `gameobject_scripts`.`id` = `tmp_gob_guid_table`.`guid_new`;
UPDATE `gameobject_scripts` JOIN `tmp_gob_guid_table` ON `gameobject_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `gameobject_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `gameobject_scripts` JOIN `tmp_gob_guid_table` ON `gameobject_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `gameobject_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `gameobject_scripts` DROP INDEX `idx_id`;
ALTER TABLE `gameobject_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `gameobject_scripts` DROP INDEX `idx_datalong2`;

-- TABLE: pool_gameobject
UPDATE `pool_gameobject` JOIN `tmp_gob_guid_table` ON `pool_gameobject`.`guid` = `tmp_gob_guid_table`.`guid` SET `pool_gameobject`.`guid` = `tmp_gob_guid_table`.`guid_new`;

-- TABLE: quest_end_scripts
-- Add some keys to improve performance
ALTER TABLE `quest_end_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `quest_end_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `quest_end_scripts` JOIN `tmp_gob_guid_table` ON `quest_end_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `quest_end_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `quest_end_scripts` JOIN `tmp_gob_guid_table` ON `quest_end_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `quest_end_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `quest_end_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `quest_end_scripts` DROP INDEX `idx_datalong2`;

-- TABLE: quest_start_scripts
-- Add some keys to improve performance
ALTER TABLE `quest_start_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `quest_start_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `quest_start_scripts` JOIN `tmp_gob_guid_table` ON `quest_start_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `quest_start_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `quest_start_scripts` JOIN `tmp_gob_guid_table` ON `quest_start_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `quest_start_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `quest_start_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `quest_start_scripts` DROP INDEX `idx_datalong2`;

-- TABLE: smart_scripts
UPDATE `smart_scripts` JOIN `tmp_gob_guid_table` ON -(`smart_scripts`.`entryorguid`) = `tmp_gob_guid_table`.`guid` SET `smart_scripts`.`entryorguid` = -(`tmp_gob_guid_table`.`guid_new`) WHERE `source_type` = 1;

-- TABLE: spell_scripts
-- Add some keys to improve performance
ALTER TABLE `spell_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `spell_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `spell_scripts` JOIN `tmp_gob_guid_table` ON `spell_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `spell_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `spell_scripts` JOIN `tmp_gob_guid_table` ON `spell_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `spell_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `spell_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `spell_scripts` DROP INDEX `idx_datalong2`;

-- TABLE: waypoint_scripts
-- Add some keys to improve performance
ALTER TABLE `waypoint_scripts` ADD INDEX `idx_datalong` (`datalong`);
ALTER TABLE `waypoint_scripts` ADD INDEX `idx_datalong2` (`datalong2`);
UPDATE `waypoint_scripts` JOIN `tmp_gob_guid_table` ON `waypoint_scripts`.`datalong` = `tmp_gob_guid_table`.`guid` SET `waypoint_scripts`.`datalong` = `tmp_gob_guid_table`.`guid_new` WHERE `command` IN (9, 11, 12);
UPDATE `waypoint_scripts` JOIN `tmp_gob_guid_table` ON `waypoint_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid` SET `waypoint_scripts`.`datalong2` = `tmp_gob_guid_table`.`guid_new` WHERE `command` = 21 AND `dataint` = 4;
ALTER TABLE `waypoint_scripts` DROP INDEX `idx_datalong`;
ALTER TABLE `waypoint_scripts` DROP INDEX `idx_datalong2`;


-- TABLE: `characters`.gameobject_respawn
UPDATE `characters`.`gameobject_respawn` JOIN `tmp_gob_guid_table` ON `characters`.`gameobject_respawn`.`guid` = `tmp_gob_guid_table`.`guid` SET `characters`.`gameobject_respawn`.`guid` = `tmp_gob_guid_table`.`guid_new`;



-- ====== BEGIN PROCESSING - AUTO_INCREMENT VALUES ======

-- TABLE: creature
SELECT MAX(`guid`)+1 FROM `creature` INTO @VAR;
SET @s = CONCAT('ALTER TABLE `creature` AUTO_INCREMENT = ', @VAR);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

-- TABLE: gameobject
SELECT MAX(`guid`)+1 FROM `gameobject` INTO @VAR;
SET @s = CONCAT('ALTER TABLE `gameobject` AUTO_INCREMENT = ', @VAR);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;


-- ====== CLEANUP ======
DROP TABLE IF EXISTS `tmp_cre_guid_table`;
DROP TABLE IF EXISTS `tmp_path_id_table`;
DROP TABLE IF EXISTS `tmp_gob_guid_table`;