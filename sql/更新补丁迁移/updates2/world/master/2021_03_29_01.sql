-- DB update 2021_03_29_00 -> 2021_03_29_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_29_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_29_00 2021_03_29_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1605128047204479800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1605128047204479800');

-- SUMMARY: We edit the old table, then we create the new table, then we transfer the rows from the old table to the new table, then we remove no longer used columns from the old table, then we add foreign keys, then we add the strings, then update the .reload command

-- Add new column ID
ALTER TABLE `access_requirement`
ADD `id` tinyint unsigned NOT NULL COMMENT 'The dungeon template ID' AUTO_INCREMENT UNIQUE FIRST;

-- Set new primary key
ALTER TABLE `access_requirement`
ADD PRIMARY KEY `id` (`id`),
DROP INDEX `PRIMARY`,
DROP INDEX `id`;

-- New table
CREATE TABLE `dungeon_access_requirements` (
  `dungeon_access_id` TINYINT unsigned NOT NULL COMMENT 'ID from dungeon_access_template',
  `requirement_type` TINYINT unsigned NOT NULL COMMENT '0 = achiev, 1 = quest, 2 = item',
  `requirement_id` MEDIUMINT unsigned NOT NULL COMMENT 'Achiev/quest/item ID',
  `requirement_note` varchar(255) COLLATE 'utf8mb4_general_ci' NULL COMMENT 'Optional msg shown ingame to player if he cannot enter. You can add extra info',
  `faction` TINYINT unsigned NOT NULL DEFAULT 2 COMMENT '0 = Alliance, 1 = Horde, 2 = Both factions',
  `priority` TINYINT unsigned NULL COMMENT 'Priority order for the requirement, sorted by type. 0 is the highest priority',
  `leader_only` TINYINT NOT NULL DEFAULT 0 COMMENT '0 = check the requirement for the player trying to enter, 1 = check the requirement for the party leader',
  `comment` varchar(255) COLLATE 'utf8mb4_general_ci' NULL,
  PRIMARY KEY (`dungeon_access_id`, `requirement_type`, `requirement_id`)
) COMMENT='Add (multiple) requirements before being able to enter a dungeon/raid' ENGINE='MyISAM' COLLATE 'utf8mb4_general_ci';

-- Transfer from old table to new table:
-- ------------------- ITEMS

INSERT INTO `dungeon_access_requirements` (`dungeon_access_id`, `requirement_type`, `requirement_id`, `requirement_note`, `faction`)
    SELECT `id`,
            2 AS requirement_type,
            `item`,
            NULL,
            0
    FROM `access_requirement`
    WHERE `item` > 0 AND `item2` = 0
    UNION
    -- flamewrought key alliance
    SELECT `id`,
            2 AS requirement_type,
            `item2`,
            NULL,
            0 AS faction
    FROM `access_requirement`
    WHERE `item2` > 0
    UNION
    -- flamewrought key horde
    SELECT `id`,
            2 AS requirement_type,
            `item`,
            NULL,
            1 AS faction
    FROM `access_requirement`
    WHERE `item2` > 0
;

-- ------------------ ACHIEVS

INSERT INTO `dungeon_access_requirements` (`dungeon_access_id`, `requirement_type`, `requirement_id`)
    SELECT `id`,
            0 AS requirement_type,
            `completed_achievement`
    FROM `access_requirement`
    WHERE `completed_achievement` > 0
;

-- ------------------ QUESTS

INSERT INTO `dungeon_access_requirements` (`dungeon_access_id`, `requirement_type`, `requirement_id`, `faction`, `requirement_note`, `leader_only`)
    -- Alliance quests only
    SELECT `id`,
            1 AS requirement_type,
            `quest_done_A`,
            0 AS faction,
			quest_failed_text,
			1 as leader_only
    FROM `access_requirement`
    WHERE `quest_done_A` > 0 AND `quest_done_A` != `quest_done_H`
    UNION
    -- Horde quests only
    SELECT `id`,
            1 AS requirement_type,
            `quest_done_H`,
            1 AS faction,
			quest_failed_text,
			1 as leader_only
    FROM `access_requirement`
    WHERE `quest_done_H` > 0 AND `quest_done_A` != `quest_done_H`
    UNION
    -- Both factions
    SELECT `id`,
            1 AS requirement_type,
            `quest_done_H`,
            2 AS faction,
			quest_failed_text,
			1 as leader_only
    FROM `access_requirement`
    WHERE `quest_done_H` > 0 AND `quest_done_A` = `quest_done_H`
;

-- REORDER PRIMARY KEY
CREATE TEMPORARY TABLE IF NOT EXISTS `temp` select * from `dungeon_access_requirements` ORDER BY dungeon_access_id, faction;
TRUNCATE `dungeon_access_requirements`;
ALTER TABLE `dungeon_access_requirements`; 
INSERT INTO `dungeon_access_requirements` SELECT * FROM `temp`;

-- Verify result with this
-- SELECT `id`, `quest_failed_text` FROM `access_requirement` WHERE `quest_failed_text` IS NOT NULL;


-- Remove columns + rename table
ALTER TABLE `access_requirement`
DROP `item`,
DROP `item2`,
DROP `quest_done_A`,
DROP `quest_done_H`,
DROP `completed_achievement`,
DROP `quest_failed_text`,
RENAME TO `dungeon_access_template`,
COMMENT='Dungeon/raid access template and single requirements';

-- Rename columns
ALTER TABLE `dungeon_access_template`
CHANGE `mapId` `map_id` MEDIUMINT unsigned NOT NULL COMMENT 'Map ID from instance_template' AFTER `id`,
CHANGE `difficulty` `difficulty` TINYINT unsigned NOT NULL DEFAULT 0 COMMENT '5 man: 0 = normal, 1 = heroic, 2 = epic (not implemented) | 10 man: 0 = normal, 2 = heroic | 25 man: 1 = normal, 3 = heroic' AFTER `map_id`,
CHANGE `level_min` `min_level` TINYINT unsigned NULL AFTER `difficulty`,
CHANGE `level_max` `max_level` TINYINT unsigned NULL AFTER `min_level`,
CHANGE `item_level` `min_avg_item_level` SMALLINT unsigned NULL COMMENT 'Min average ilvl required to enter' AFTER `max_level`,
CHANGE `comment` `comment` varchar(255) COLLATE 'utf8mb4_general_ci' NULL COMMENT 'Dungeon Name 5/10/25/40 man - Normal/Heroic' AFTER `min_avg_item_level`;

-- Add KEY CONSTRAINTS
ALTER TABLE `dungeon_access_template` ADD CONSTRAINT `FK_dungeon_access_template__instance_template` FOREIGN KEY (`map_id`) REFERENCES `instance_template` (`map`) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE `dungeon_access_requirements` ADD CONSTRAINT `FK_dungeon_access_requirements__dungeon_access_template` FOREIGN KEY (`dungeon_access_id`) REFERENCES `dungeon_access_template` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;


-- Add the acore_strings
DELETE FROM `acore_string` WHERE `entry` IN (882,883,884,885,886,887,888);
INSERT INTO `acore_string` (`entry`, `content_default`) VALUES 
(882, 'To enter, you must complete the following quest(s):'),
(883, 'To enter, you must complete the following achievement(s):'),
(884, 'To enter, you must have the following item(s) in your inventory:'),
(885, '- Note:'),
(886, 'You cannot enter. Access requirements not met.'),
(887, 'To be able to enter, your equipment\'s average item level must be superior or equal to %u. Your current equipment\'s average ilevel is: %u.'),
(888, 'You must be below level %u to enter.'),
(889, 'To enter, the group leader (%s) must have completed the following quest(s):'),
(890, 'To enter, the group leader (%s) must have completed the following achievement(s):'),
(891, 'To enter, the group leader (%s) must have the following item(s) in his/her inventory:');

-- Update old command
UPDATE `command` SET `name` = 'reload dungeon_access_template', `help` = 'Syntax: .reload dungeon_access_template\r Reload dungeon_access_template table.' WHERE `name` = 'reload access_requirement';
REPLACE INTO `command` (`name`, `security`, `help`) VALUES ('reload dungeon_access_requirements', 3, 'Syntax: .reload dungeon_access_requirements\r Reload dungeon_access_requirements table.');


-- Improve a big part of the comments
-- TODO: Still need to differentiate normal from heroic in the comments and also add the correct raid number for anything above level 60, I didn't want to make any mistake and i was tired.
-- Also can add the whole zone for Hellfire Citadel, Coilfang Reservoir, etc...
UPDATE `dungeon_access_template` SET `comment` = 'Deadmines (DM)' WHERE `id` = 3;
UPDATE `dungeon_access_template` SET `comment` = 'Wailing Caverns (WC)' WHERE `id` = 4;
UPDATE `dungeon_access_template` SET `comment` = 'Blackfathom Deeps Entrance' WHERE `id` = 6;
UPDATE `dungeon_access_template` SET `comment` = 'Sunken Temple (of Atal''Hakkar) Entrance' WHERE `id` = 9;
UPDATE `dungeon_access_template` SET `comment` = 'Ahn''Qiraj Ruins (AQ20) - 20man' WHERE `id` = 27;
UPDATE `dungeon_access_template` SET `comment` = 'Blackwing Lair (BWL) - 40man' WHERE `id` = 26;
UPDATE `dungeon_access_template` SET `comment` = 'Blackrock Spire - Both Lower (LBRS) & Upper (UBRS) - 5/10man' WHERE `id` = 13;
UPDATE `dungeon_access_template` SET `comment` = 'Blackrock Depths (BRD)' WHERE `id` = 14;
UPDATE `dungeon_access_template` SET `comment` = 'Ahn''Qiraj Temple (AQ40) - 40man' WHERE `id` = 28;
UPDATE `dungeon_access_template` SET `comment` = 'Ulduar' WHERE `id` = 88;
UPDATE `dungeon_access_template` SET `comment` = 'Ulduar' WHERE `id` = 89;
UPDATE `dungeon_access_template` SET `comment` = 'Gundrak (North entrance)' WHERE `id` = 90;
UPDATE `dungeon_access_template` SET `comment` = 'Gundrak (North entrance)' WHERE `id` = 91;

UPDATE dungeon_access_template SET `comment` = replace(comment, ' (Entrance)', '');
UPDATE dungeon_access_template SET `comment` = replace(comment, ' (entrance)', '');
UPDATE dungeon_access_template SET `comment` = replace(comment, ' Entrance', '');

UPDATE `dungeon_access_template` SET `comment` = 'Zul''Farrak (ZF)' WHERE `id` = 12;
UPDATE `dungeon_access_template` SET `comment` = 'Zul''Gurub (ZG) - 20man' WHERE `id` = 20;
UPDATE `dungeon_access_template` SET `comment` = 'Ragefire Chasm (RF)' WHERE `id` = 23;
UPDATE `dungeon_access_template` SET `comment` = 'Karazhan - 10man' WHERE `comment` LIKE '%karaz%' AND `id` = 29;
UPDATE `dungeon_access_template` SET `comment` = 'Onyxia''s Lair - 10man' WHERE `id` = 15;
UPDATE `dungeon_access_template` SET `comment` = 'Onyxia''s Lair - 25man' WHERE `id` = 16;
UPDATE `dungeon_access_template` SET `comment` = 'The Obsidian Sanctum - 10man' WHERE `id` = 94;
UPDATE `dungeon_access_template` SET `comment` = 'Naxxramas - 10man' WHERE `id` = 30;
UPDATE `dungeon_access_template` SET `comment` = 'The Eye of Eternity (Malygos) - 10man' WHERE `id` = 96;
UPDATE `dungeon_access_template` SET `comment` = 'Vault of Archavon - 10man' WHERE `id` = 100;
UPDATE `dungeon_access_template` SET `comment` = 'Ulduar - 10man' WHERE `id` = 88;
UPDATE `dungeon_access_template` SET `comment` = 'Trial of the Crusader - 10man Normal' WHERE `id` = 108;
UPDATE `dungeon_access_template` SET `comment` = 'Icecrown Citadel - 10man Normal' WHERE `id` = 102;
UPDATE `dungeon_access_template` SET `comment` = 'The Ruby Sanctum - 10man Normal' WHERE `id` = 118;
UPDATE `dungeon_access_template` SET `comment` = 'Scarlet Monastery (SM) - All wings' WHERE `id` = 11;
UPDATE `dungeon_access_template` SET `comment` = 'Maraudon - All wings' WHERE `id` = 22;
UPDATE `dungeon_access_template` SET `comment` = 'Dire Maul - All wings' WHERE `id` = 25;
UPDATE `dungeon_access_template` SET `comment` = 'Molten Core - 40man' WHERE `id` = 24;
UPDATE `dungeon_access_template` SET `comment` = 'Stratholme' WHERE `id` = 21;
UPDATE `dungeon_access_template` SET `comment` = 'Caverns Of Time: Old Hillsbrad Foothills/Escape from Durnholde - Normal' WHERE `id` = 62;
UPDATE `dungeon_access_template` SET `comment` = 'Caverns Of Time: Old Hillsbrad Foothills/Escape from Durnholde - Heroic' WHERE `id` = 63;
UPDATE `dungeon_access_template` SET `comment` = 'Caverns Of Time: Black Morass/Opening the Dark Portal - Normal' WHERE `id` = 17;
UPDATE `dungeon_access_template` SET `comment` = 'Caverns Of Time: Black Morass/Opening the Dark Portal - Heroic' WHERE `id` = 18;
UPDATE `dungeon_access_template` SET `comment` = 'Hellfire Citadel: Magtheridon''s Lair - 25man' WHERE `id` = 39;
UPDATE `dungeon_access_template` SET `comment` = 'Coilfang Reservoir: Serpentshrine Cavern - 25man' WHERE `id` = 46;
UPDATE `dungeon_access_template` SET `comment` = 'Magisters'' Terrace - Normal' WHERE `id` = 76;
UPDATE `dungeon_access_template` SET `comment` = 'Magisters'' Terrace - Heroic' WHERE `id` = 77;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
