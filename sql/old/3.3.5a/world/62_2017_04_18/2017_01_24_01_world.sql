-- [NPC][WotlK] Savage Hill Brute/Mystic/Scavenger, missing spawn loc and emote
SET @CGUID := 73938; -- SET BY TC TEAM
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID+0, 29404, 571, 0, 0, 1, 1, 0, 1, 6089.3, -359.966, 455.223, 2.41823, 300, 6, 0, 11379, 0, 1, 0, 0, 0, 0),
(@CGUID+1, 29404, 571, 0, 0, 1, 1, 0, 1, 6104.57, -380.103, 431.085, 1.31082, 300, 6, 0, 11379, 0, 1, 0, 0, 0, 0),
(@CGUID+2, 29622, 571, 0, 0, 1, 1, 0, 1, 6106.41, -307.385, 445.287, 5.63439, 300, 0, 0, 9416, 8459, 0, 0, 0, 0, 0),
(@CGUID+3, 29622, 571, 0, 0, 1, 1, 0, 1, 6151.58, -333.755, 436.37, 4.16491, 300, 0, 0, 9103, 8313, 0, 0, 0, 0, 0),
(@CGUID+4, 29622, 571, 0, 0, 1, 1, 0, 1, 6131.09, -340.995, 436.336, 5.1412, 300, 0, 0, 9416, 8459, 0, 0, 0, 0, 0),
(@CGUID+5, 29622, 571, 0, 0, 1, 1, 0, 1, 6119.04, -350.294, 436.988, 5.33912, 300, 0, 0, 9103, 8313, 0, 0, 0, 0, 0),
(@CGUID+6, 29622, 571, 0, 0, 1, 1, 0, 1, 6158.21, -359.72, 435.302, 3.23503, 300, 0, 0, 9416, 8459, 0, 0, 0, 0, 0),
(@CGUID+7, 29623, 571, 0, 0, 1, 1, 0, 1, 6135.28, -362.313, 433.083, 2.42607, 300, 6, 0, 11770, 0, 1, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (117085, 113242, 113314, 113327);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(117085,0,0,3,1,0, ''),
(113242,0,0,3,1,0, ''),
(113314,0,0,3,1,0, ''),
(113327,0,0,3,1,0, '');

-- Savage Hill Scavenger SAI
SET @ENTRY := 29404;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Scavenger - On Aggro - Remove Flag Standstate Sleep");

-- Savage Hill Mystic SAI
SET @ENTRY := 29622;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Mystic - On Aggro - Remove Flag Standstate Sleep");

-- Savage Hill Brute SAI
SET @ENTRY := 29623;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`= 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Brute - On Aggro - Remove Flag Standstate Sleep");

SET @NPC := 113241;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6276.32, -648.906, 418.674, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6269.54, -647.148, 418.458, 0, 10000, 0, 0, 100, 0),
(@PATH, 3, 6259.28, -644.926, 417.527, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6249.04, -642.598, 416.282, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6235.14, -639.409, 414.451, 0, 10000, 0, 0, 100, 0),
(@PATH, 6, 6238.54, -640.251, 414.906, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6252.14, -643.517, 416.649, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6262.42, -645.655, 417.845, 0, 0, 0, 0, 100, 0);

SET @NPC := 113325;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6133.69, -454.762, 410.059, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6123.02, -443.385, 411.551, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6107.9, -429.985, 414.557, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6121.41, -441.725, 411.852, 0, 0, 0, 0, 100, 0);

SET @NPC := 113326;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6161.12, -428.764, 414.44, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6143.3, -443.667, 412.639, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6155.79, -433.246, 414.151, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6177.02, -412.869, 415.473, 0, 0, 0, 0, 100, 0);
