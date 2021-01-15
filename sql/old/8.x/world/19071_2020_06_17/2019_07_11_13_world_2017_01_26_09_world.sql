-- [NPC][WotlK] Stormforged Iron Giant, missing paths, emote, 1 spawn locs, mini event
-- increase rndmmovement for Stormforged Iron Giant to 26 yards
UPDATE `creature` SET `spawndist`=26 WHERE `id`=29375 AND `spawndist` > 0;

-- spawn two missing Stormforged Iron Giant (one static spawn, one eventspawn with waypoints)
SET @CGUID := 74017; -- SET by TC
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 29375, 571, 67, 4495, '0', 0, 27092, 1, 7164.41, -3565.155, 827.6359, 0.5585054, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormforged Iron Giant (Area: Fjorn's Anvil)
(@CGUID+1, 29375, 571, 67, 4495, '0', 0, 27092, 1, 7164.41, -3565.155, 827.6359, 0.5585054, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Stormforged Iron Giant (Area: Fjorn's Anvil)

-- add roar emotescript for Stormforged Iron Giant every 13 - 16 seconds
SET @MAXGUID := 942; 
SET @SCRIPTID := 11393600; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
-- EMOTE (oneshot)
(@SCRIPTID+0, 13, 1, 53, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

-- add roar emote for Fjorn on waypoint 7
UPDATE `waypoint_data` SET `action`=@SCRIPTID WHERE  `id`=883080 AND `point`=7;

-- we use wp scripts here to avoid -guid sai scripts
SET @NPC := 113936;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `action`) VALUES
(@PATH, 1, 7233.65, -3437.45, 838.956, 2.6529, 15000, @SCRIPTID);

SET @NPC := 113937;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `action`) VALUES
(@PATH, 1, 7181, -3349.72, 848.463, 1.09956, 4000, 0),
(@PATH, 2, 7181, -3349.72, 848.463, 1.09956, 15000, @SCRIPTID);

SET @NPC := @CGUID+0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `action`) VALUES
(@PATH, 1, 7164.41, -3565.16, 827.636, 0.558505, 15000, @SCRIPTID);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);

-- wps for eventspawn of Stormforged Iron Giant
-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7199.968,`position_y`=-3600.629,`position_z`=827.002 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7199.968,-3600.629,827.002,0,0,0,0,100,0), -- 10:38:27
(@PATH,2,7189.104,-3563.368,827.3765,0,0,0,0,100,0), -- 10:38:31
(@PATH,3,7188.668,-3539.213,827.3962,0,0,0,0,100,0), -- 10:38:38
(@PATH,4,7195.016,-3509.103,828.8126,0,0,0,0,100,0), -- 10:38:43
(@PATH,5,7214.329,-3441.1,837.9941,0,0,0,0,100,0), -- 10:38:53
(@PATH,6,7208.163,-3399.303,842.7413,0,0,0,0,100,0), -- 10:39:01
(@PATH,7,7204.88,-3331.804,843.1924,0,0,0,0,100,0), -- 10:39:06
(@PATH,8,7207.137,-3299.045,837.8273,0,0,0,0,100,0), -- 10:39:16
(@PATH,9,7231.24,-3264.245,837.8268,0,0,0,0,100,0), -- 10:39:22
(@PATH,10,7253.341,-3234.825,837.8268,0,0,0,0,100,0), -- 10:39:27
(@PATH,11,7269.063,-3209.878,837.8268,0,0,0,0,100,0), -- 10:39:31
(@PATH,12,7296.788,-3181.641,837.8268,0,0,0,0,100,0), -- 10:39:36
(@PATH,13,7337.208,-3163.068,837.8268,0,0,0,0,100,0), -- 10:39:44
(@PATH,14,7364.17,-3148.588,837.8268,0,0,0,0,100,0), -- 10:39:47
(@PATH,15,7395.288,-3140.528,837.8268,0,0,0,0,100,0), -- 10:39:52
(@PATH,16,7421.594,-3121.072,837.8268,0,5000,0,1188,100,0); -- 10:39:57
-- 0x20197C47601CAFC00000360000087213 .go 7199.968 -3600.629 827.002
