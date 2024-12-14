-- Correct spawn group boss state values for LCT spawn groups
UPDATE `instance_spawn_groups` SET `bossStates`= 0x17 WHERE `instanceMapId`= 755;

UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `ScriptName`= 'boss_lockmaw' WHERE `entry`= 43614;
UPDATE `creature_template` SET `flags_extra`= 0x80 WHERE `entry` IN (45124, 43655, 43650);
UPDATE `creature_template` SET `flags_extra`= 0x100, `ScriptName`= 'npc_lockmaw_frenzied_crocolisk' WHERE `entry`= 43658;
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `speed_walk`= 2.4, `speed_run`= 0.85714, `ScriptName`= 'npc_lockmaw_augh_add' WHERE `entry` IN (45379, 45378);
UPDATE `creature_template` SET `mechanic_immune_mask`= 667893759, `ScriptName`= 'npc_lockmaw_augh_boss' WHERE `entry`= 49045;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_lockmaw_scent_of_blood', 'spell_gen_random_aggro_taunt', 'spell_husam_hurl_vehicle');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81690, 'spell_lockmaw_scent_of_blood'),
(81690, 'spell_gen_random_aggro_taunt');

DELETE FROM `creature_text` WHERE `CreatureID` IN (45379, 49045);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(45379, 0, 0, 'Bwagauugh!!! Augh feed you to da crocs!!!', 12, 0, 100, 53, 0, 0, 45544, 0, 'Augh'),
(45379, 1, 0, 'Gwaaaaaaaaaaaahhh!!!', 12, 0, 100, 0, 0, 0, 45530, 0, 'Augh'),
(49045, 0, 0, 'Augh appears from the distance!', 41, 0, 100, 0, 0, 0, 50638, 0, 'Augh'),
(49045, 1, 0, 'GAAAH! How you kill croc?!', 12, 0, 100, 53, 0, 0, 49169, 0, 'Augh'),
(49045, 2, 0, 'Augh smart! Augh already steal treasure while you no looking! ', 12, 0, 100, 1, 0, 0, 49170, 0, 'Augh'),
(49045, 3, 0, 'Augh da boss! Oh yeah!', 12, 0, 100, 0, 0, 0, 49171, 0, 'Augh'),
(49045, 4, 0, 'Augh steal your treasure. Uhn uhn uhnnn!', 12, 0, 100, 0, 0, 0, 49173, 0, 'Augh'),
(49045, 5, 0, 'Who bad?! Augh bad!! Ugn!', 12, 0, 100, 0, 0, 0, 49172, 0, 'Augh');

SET @CGUID := 339734;
DELETE FROM `creature` WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 49045, 755, 5396, 5631, '1,2', 169, 0, 0, 1, -11058.9111328125, -1625.342041015625, -0.13049933314323425, 4.78220224380493164, 7200, 0, 0, 702775, 0, 0, NULL, NULL, NULL, NULL, 26654); -- Augh (Area: Oasis of the Fallen Prophet - Difficulty: 2) CreateObject2

DELETE FROM `spawn_group_template` WHERE `groupId`= 1037;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(1037, 'The Lost City of the Tol''vir - Augh (Heroic)', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 1037;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(1037, 0, @CGUID);
