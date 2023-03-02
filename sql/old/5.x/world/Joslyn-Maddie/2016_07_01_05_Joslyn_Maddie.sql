-- Fix quest "The Way of the Tushui(29414)"
-- Fix NPC's related to quest.

UPDATE `quest_template` SET `Method` = '2' WHERE `Id` = '29414' ;
UPDATE `quest_template` SET `SuggestedPlayers` = '0' WHERE `Id` = '29414' ;

UPDATE `quest_template` SET `StartScript` = '0' WHERE `Id` = '29414' ;

DELETE FROM `creature_addon` WHERE `guid` = '940589' ;
DELETE FROM `creature_addon` WHERE `guid` = '940585' ;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('940589', '0', '0', '0', '0', '0', '(NULL)');
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('940585', '0', '0', '0', '0', '455', '(NULL)');




