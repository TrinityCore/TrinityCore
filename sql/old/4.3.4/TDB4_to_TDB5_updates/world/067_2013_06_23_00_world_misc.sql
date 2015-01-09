-- Delete no longer used data from World Database
DELETE FROM `game_event_condition` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_creature_quest` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_npc_vendor` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_npcflag` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_prerequisite` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event_quest_condition` WHERE `eventEntry` BETWEEN 33 AND 47;
DELETE FROM `game_event` WHERE `description` LIKE '%Shattered Sun Offensive:%';

UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=29833;
