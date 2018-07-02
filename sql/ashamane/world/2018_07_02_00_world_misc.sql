DELETE FROM `creature` WHERE `id`=82270;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210219086, 82270, 1190, 0, 0, 1, 0, 0, 0, -1, 0, 0, -11270.4, -3632.95, 9.41534, 2.84916, 300, 0, 0, 1265780, 0, 0, 0, 0, 0, 0, 0, '', 0);


-- Ironmarch Grunt
SET @ENTRY := 76189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,159770,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skirmisher\'s Slam'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,159780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skirmisher\'s Speed on Aggro'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,159782,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fury at 40% HP');

-- Ironmarch Grunt
SET @ENTRY := 76556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,159770,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skirmisher\'s Slam'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,159780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skirmisher\'s Speed on Aggro'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,159782,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fury at 40% HP');

UPDATE `creature_template` SET `minlevel` = 90, `maxlevel` = 90, `faction` = 189, `unit_flags` = 131076 WHERE `entry` = 82298;
DELETE FROM `creature` WHERE `id`=82298;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210219087, 82298, 1190, 0, 0, 1, 0, 0, 0, -1, 0, 0, -11403.2, -3478.66, 7.73482, 4.37755, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210219088, 82298, 1190, 0, 0, 1, 0, 0, 0, -1, 0, 0, -11431.2, -3496.76, 9.13634, 4.54798, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210219089, 82298, 1190, 0, 0, 1, 0, 0, 0, -1, 0, 0, -11388.4, -3508.9, 11.0931, 4.88649, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- Ironmarch Scout <Iron Horde>
SET @ENTRY := 76886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,86603,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,3,0,67,0,100,0,3900,6900,0,0,11,159796,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backslash');

-- Ironmarch Executioner
SET @ENTRY := 82774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159949,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ironmarch Shot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,159966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Bomb');

-- Ironmarch Leadspitter
SET @ENTRY := 76651;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159949,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ironmarch Shot'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,159966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Bomb');


REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('73459', '113399', '1'); 
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('73458', '113400', '1'); 
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('73446', '113401', '1'); 
UPDATE `creature_template` SET `HealthScalingExpansion` = '0' WHERE `entry` = '76556'; 


DELETE FROM `gameobject` WHERE `id`=232576;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013512, 232576, 1190, 0, 0, 1, 0, 0, 0, -1, -11023.5, -3368.17, 65.9273, 1.92305, 0, 0, -0.820065, -0.57227, 300, 255, 1, 0, '', 0);


UPDATE `gameobject_template` SET `Data1` = 232576 WHERE `entry` = 232576;

REPLACE INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('232576', '113397', '1'); 


DELETE FROM `creature` WHERE `id`=82446;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(10124266, 82446, 1190, 4, 1438, 1, 0, 0, 0, -1, 0, 0, -11021.4, -3373.11, 65.2694, 1.73734, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 82446;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (82446);
DELETE FROM `creature_template_addon` WHERE (`entry`=82446);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (82446, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 82443;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (82443);
DELETE FROM `creature_template_addon` WHERE (`entry`=82443);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (82443, 0, 0, 7, 1, 0, 29266);

DELETE FROM `gameobject` WHERE `id`=232573;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013528, 232573, 1190, 0, 0, 1, 0, 0, 0, -1, -10948.8, -3456.9, 66.7493, 6.18855, 0, 0, -0.0473023, 0.998881, 300, 255, 1, 0, '', 0);

UPDATE `gameobject_template` SET `Data1` = 232573 WHERE `entry` = 232573;

REPLACE INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('232573', '113395', '1'); 

UPDATE `creature_template` SET `KillCredit1` = 82871 WHERE `entry` = 78507;
DELETE FROM `quest_objectives` WHERE `ID` = '273388'; 
UPDATE `creature_template` SET `unit_flags` = 536871814, `dynamicflags` = 32, `type_flags` = 128 WHERE `entry` = 82445;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (82445);
DELETE FROM `creature_template_addon` WHERE (`entry`=82445);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (82445, 0, 0, 7, 1, 0, 29266);
UPDATE `creature_template` SET `faction` = 189 WHERE `entry` = 80468;
DELETE FROM `gameobject` WHERE `id`=232575;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013529, 232575, 1190, 0, 0, 1, 0, 0, 0, -1, -11068.9, -3415.17, 69.628, 3.38075, 0, 0, -0.992859, 0.119293, 300, 255, 1, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 82871, `KillCredit2` = 85142 WHERE `entry` = 78507;

UPDATE `gameobject_template` SET `Data1` = 232575 WHERE `entry` = 232575;

REPLACE INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('232575', '113396', '1'); 

DELETE FROM `creature_template_addon` WHERE (`entry`=82647);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (82647, 0, 0, 33554432, 0, 0, '');

UPDATE `creature_template` SET `unit_flags` = 32768, `unit_flags2` = 2048, `type_flags` = 32768 WHERE `entry` = 80468;
DELETE FROM `gameobject` WHERE `id`=231826;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013545, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2512.83, 420.876, 4.48051, 5.45378, 0, 0, -0.402916, 0.915237, 300, 255, 1, 0, '', 0),
(51013546, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2544.12, 420.663, 4.69573, 0.513631, 0, 0, -0.254002, -0.967204, 300, 255, 1, 0, '', 0),
(51013547, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2546.51, 464.077, 4.59982, 2.04516, 0, 0, -0.853455, -0.521167, 300, 255, 1, 0, '', 0),
(51013548, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2543.43, 476.854, 5.47089, 4.06677, 0, 0, -0.8949, 0.446268, 300, 255, 1, 0, '', 0),
(51013549, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2518.35, 469.331, 3.82846, 4.08091, 0, 0, -0.891723, 0.452582, 300, 255, 1, 0, '', 0),
(51013550, 231826, 1116, 0, 0, 1, 0, 0, 0, -1, 2493.15, 445.736, 4.39849, 3.05832, 0, 0, -0.999133, -0.0416236, 300, 255, 1, 0, '', 0);
UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 79205;
UPDATE `creature_template` SET `unit_flags` = 32768, `unit_flags2` = 2048 WHERE `entry` = 79205;
UPDATE `creature_template` SET `HealthScalingExpansion` = '0' WHERE `entry` = '72783'; 

UPDATE `creature` SET `spawndist` = 5, `MovementType` = 1 WHERE `id` IN (82774,76886,76524,77724,66282,5990,55238,55290,56198,55489,55279,55291,54988,54703,12922,54989,56070,54558,56304,54702,66290,54627,56201,57232,55195,76556,76189,56650,78193,78667,76648,78674,77721,78670,76085,77771,78348,78488,78694,76672,76673,77643,77090,78921,77925,77644,77101,78695,77723,78142,77790,77767,77640,77845,77653,79205);


UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (11260,73458);