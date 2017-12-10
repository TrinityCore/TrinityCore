-- Add Missing Spawns
SET @CGUID := 251551;
DELETE FROM creature WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1294.651, -5565.743, 21.22984, 0.7330383, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+1, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1267.925, -5552.052, 21.01184, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+2, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1273.116, -5553.075, 21.0282, 0.1570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+3, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1270.184, -5556.087, 21.14443, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+4, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1342.302, -5538.684, 20.81846, 5.358161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+5, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1271.615, -5545.944, 21.07296, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+6, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1273.220, -5549.733, 21.00912, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+7, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1268.313, -5547.897, 20.94538, 0.2792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+8, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1318.168, -5527.401, 20.77204, 5.410521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+9, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1324.198, -5533.587, 20.85115, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+10, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1321.035, -5530.469, 20.8207, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+11, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1337.073, -5538.205, 20.82421, 5.410521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+12, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1331.458, -5537.667, 21.02953, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+13, 39028, 1, 0, 0, 1, 0, 0, 0, 0, -1327.352, -5536.042, 21.06844, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Darkspear Watcher
(@CGUID+14, 38989, 1, 0, 0, 1, 0, 0, 0, 0, -1330.837, -5558.896, 21.48784, 0.83567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Jornun
(@CGUID+15, 38440, 1, 0, 0, 1, 0, 0, 0, 0, -1329.891, -5556.582, 21.55126, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Tortunga
(@CGUID+16, 38931, 1, 0, 0, 1, 0, 0, 0, 0, -1327.415, -5557.939, 21.5484, 2.892155, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23911), -- Zuni
(@CGUID+17, 39027, 1, 0, 0, 1, 0, 0, 0, 0, -1333.314, -5545.30, 21.04929, 1.797689, 120, 0, 0, 0, 0, 2, 0, 0, 0, 23911); -- Vanira

 -- Pathing for Vanira Entry: 39027
 SET @PATH := @CGUID+17 * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1333.314,-5545.3,21.04929,0,0,0,0,100,0),
(@PATH,2,-1333.314,-5545.3,21.04929,1.797689,30000,0,0,100,0),
(@PATH,3,-1317.899,-5539.196,21.06979,0,0,0,0,100,0),
(@PATH,4,-1317.899,-5539.196,21.06979,2.199115,0,0,0,100,0);

DELETE FROM `creature_template_addon` WHERE `entry`=39028;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (39028,0,14341,65536,1,0, '60921');

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+14,@CGUID+15,@CGUID+16,@CGUID+17);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@CGUID+14,0,0,65536,1,0, '60921'),(@CGUID+15,0,0,65536,1,0, '60921'),(@CGUID+16,0,0,65536,1,0, '60921'),(@CGUID+17,@PATH,0,65536,257,0, '60921');
