-- Update game_event
ALTER TABLE `game_event` 
CHANGE `entry` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event';

-- Update game_event_battleground_holiday
ALTER TABLE `game_event_battleground_holiday`
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST;

-- Update game_event_condition
ALTER TABLE `game_event_condition`
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST;

-- Update game_event_creature
ALTER TABLE `game_event_creature` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_creature_quest
ALTER TABLE `game_event_creature_quest` CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_gameobject
ALTER TABLE `game_event_gameobject` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_gameobject_quest
ALTER TABLE `game_event_gameobject_quest` 
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST;

-- Update game_event_model_equip
ALTER TABLE `game_event_model_equip` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_npc_vendor
ALTER TABLE `game_event_npc_vendor` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update game_event_npcflag
ALTER TABLE `game_event_npcflag` 
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST;

-- Update game_event_pool
ALTER TABLE `game_event_pool` CHANGE `event` `eventEntry` TINYINT(3) NOT NULL COMMENT 'Entry of the game event. Put negative entry to remove during event.' FIRST;

-- Update game_event_prerequisite
ALTER TABLE `game_event_prerequisite`
CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST;

-- Update game_event_quest_condition
ALTER TABLE `game_event_quest_condition` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event.' FIRST;

-- Update season_linked_event
ALTER TABLE season_linked_event
RENAME TO `game_event_arena_seasons`,
CHANGE `event` `eventEntry` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Entry of the game event' FIRST,
CHANGE `season` `season` TINYINT(3) UNSIGNED NOT NULL COMMENT 'Arena season number';

