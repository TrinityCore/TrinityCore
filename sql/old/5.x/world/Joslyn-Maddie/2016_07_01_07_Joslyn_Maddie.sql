-- Fix quest "Fanning the Flames(29523)"

UPDATE `quest_template` SET `SuggestedPlayers` = '0' WHERE `Id` = '29523' ;

-- Delete some double spawned Loose dogwood Root
DELETE FROM `gameobject` WHERE `guid` = '521385' ;
DELETE FROM `gameobject` WHERE `guid` = '521377' ;

-- change Hozen hanging bunny(56739) model, was the wrong model and could be seen by players.
UPDATE `creature_template` SET `modelid1` = '11686' WHERE `entry` = '56739' ;


-- Some work on the fire path, Need to figure out what spell it uses.
DELETE FROM `creature_template_addon` WHERE `entry` = '59626' ;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES('59626', '0', '0', '0', '1', '0', '114686');
UPDATE `creature_template` SET `unit_flags` = '33555202' WHERE `entry` = '59626' ;
DELETE FROM smart_scripts WHERE entryorguid=59626;
INSERT INTO `smart_scripts` VALUES (59626, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 114686, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame jet - Visual ground');
INSERT INTO `smart_scripts` VALUES (59626, 0, 1, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 11, 114685, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Jet - Fight off damage');
INSERT INTO `smart_scripts` VALUES (59626, 0, 2, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 11, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Visual Effect flames out of combat');
INSERT INTO `smart_scripts` VALUES (59626, 0, 3, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 114685, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Jet - fight Damage');
INSERT INTO `smart_scripts` VALUES (59626, 0, 4, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Visual Effect fighting in flames');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=59626;


DELETE FROM `creature` WHERE `guid` = '940414' ;
DELETE FROM `creature` WHERE `guid` = '940417' ;
DELETE FROM `creature` WHERE `guid` = '940421' ;
DELETE FROM `creature` WHERE `guid` = '940419' ;
DELETE FROM `creature` WHERE `guid` = '940422' ;


-- "Fix" quest "()" fix the phasing and spawns
UPDATE `creature_template` SET `ScriptName` = 'npc_li_fei' WHERE	`entry` = '54135' ;
UPDATE `creature_template` SET `faction_A` = '14' , `faction_H` = '14' WHERE `entry` = '54856' ;
UPDATE `quest_template` SET `Method` = '2' WHERE `Id` = '29421' ;
DELETE FROM `creature` WHERE `guid` = '997523' ;
UPDATE `creature_template` SET `faction_A` = '35' , `faction_H` = '35' WHERE `entry` = '54135' ;
