-- Create temporary table that holds the entry conversion data. (Generating numbers by index and autoincrement is not used because
-- we need the same numbers to update the characters db and need to do that without cross db queries
CREATE TABLE `game_event_temp` (
  `entryOld` TINYINT(3) UNSIGNED NOT NULL,
  `entryNew` TINYINT(3) UNSIGNED NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Renumbered entry data
INSERT INTO `game_event_temp` (`entryOld`,`entryNew`) VALUES
(1,1),(2,2),(3,3),(4,4),(5,5),(6,6),(7,7),(8,8),(9,9),(10,10),(11,11),(12,12),(13,13),(14,14),(15,15),(16,16),(17,17),(18,18),(19,19),(20,20),(21,21),(22,22),
(23,23),(26,24),(27,25),(28,26),(29,27),(30,28),(31,29),(32,30),(33,31),(34,32),(35,33),(36,34),(37,35),(38,36),(39,37),(40,38),(41,39),(42,40),(43,41),(44,42),
(45,43),(46,44),(47,45),(48,46),(49,47),(50,48),(51,49),(52,50),(53,51),(54,52),(124,53),(125,54),(126,55),(127,56),(128,57),(129,58),(130,59),(131,60);

-- Update game_event
ALTER TABLE `game_event` DROP PRIMARY KEY;
UPDATE `game_event`, `game_event_temp` SET `game_event`.`entry` = `game_event_temp`.`entryNew` WHERE `game_event`.`entry` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event`
CHANGE `entry` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event',
ADD PRIMARY KEY (`eventEntry`);

-- Update game_event_battleground_holiday
ALTER TABLE `game_event_battleground_holiday` DROP PRIMARY KEY;
UPDATE `game_event_battleground_holiday`, `game_event_temp` SET `game_event_battleground_holiday`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_battleground_holiday`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_battleground_holiday`
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
ADD PRIMARY KEY (`eventEntry`);

-- Update game_event_condition
ALTER TABLE `game_event_condition` DROP PRIMARY KEY;
UPDATE `game_event_condition`, `game_event_temp` SET `game_event_condition`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_condition`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_condition`
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
ADD PRIMARY KEY (`eventEntry`, `condition_id`);

-- Update game_event_creature
UPDATE `game_event_creature`, `game_event_temp` SET `game_event_creature`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_creature`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_creature` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_creature_quest
UPDATE `game_event_creature_quest`, `game_event_temp` SET `game_event_creature_quest`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_creature_quest`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_creature_quest` CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_gameobject
UPDATE `game_event_gameobject`, `game_event_temp` SET `game_event_gameobject`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_gameobject`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_gameobject` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_gameobject_quest
ALTER TABLE `game_event_gameobject_quest` DROP PRIMARY KEY;
UPDATE `game_event_gameobject_quest`, `game_event_temp` SET `game_event_gameobject_quest`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_gameobject_quest`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_gameobject_quest`
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
ADD PRIMARY KEY (`id`, `quest`, `eventEntry`);

-- Update game_event_model_equip
UPDATE `game_event_model_equip`, `game_event_temp` SET `game_event_model_equip`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_model_equip`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_model_equip` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_npc_vendor
UPDATE `game_event_npc_vendor`, `game_event_temp` SET `game_event_npc_vendor`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_npc_vendor`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_npc_vendor` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_npcflag
ALTER TABLE `game_event_npcflag` DROP PRIMARY KEY;
UPDATE `game_event_npcflag`, `game_event_temp` SET `game_event_npcflag`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_npcflag`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_npcflag`
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
ADD PRIMARY KEY (`guid`, `eventEntry`);

-- Update game_event_pool
UPDATE `game_event_pool`, `game_event_temp` SET `game_event_pool`.`event` = `game_event_temp`.`entryNew` WHERE `game_event_pool`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_pool` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_prerequisite
ALTER TABLE `game_event_prerequisite` DROP PRIMARY KEY;
UPDATE `game_event_prerequisite`, `game_event_temp` SET `game_event_prerequisite`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_prerequisite`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_prerequisite`
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
ADD PRIMARY KEY (`eventEntry`, `prerequisite_event`);

-- Update game_event_quest_condition
UPDATE `game_event_quest_condition`, `game_event_temp` SET `game_event_quest_condition`.`event_id` = `game_event_temp`.`entryNew` WHERE `game_event_quest_condition`.`event_id` = `game_event_temp`.`entryOld`;
ALTER TABLE `game_event_quest_condition` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update season_linked_event
ALTER TABLE `season_linked_event` DROP PRIMARY KEY;
UPDATE `season_linked_event`, `game_event_temp` SET `season_linked_event`.`event` = `game_event_temp`.`entryNew` WHERE `season_linked_event`.`event` = `game_event_temp`.`entryOld`;
ALTER TABLE season_linked_event
RENAME TO `game_event_arena_seasons`,
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
CHANGE `season` `season` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Arena season number';

-- Remove temporary table
DROP TABLE `game_event_temp`;
