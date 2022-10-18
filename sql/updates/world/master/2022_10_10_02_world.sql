-- Harbor Guard Captain Entry: 140350, Boralus
SET @PHASE := 0;
SET @SWAP := -1;
SET @CGUID := 850599;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 1056.8473, -995.05035, 16.498705, 5.410520553588867187, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+1, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 1095.974, -634.11285, 17.630829, 3.155911922454833984, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+2, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 1096.9497, -476.63196, 36.510532, 6.233836650848388671, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+3, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 1014.12115, -466.36838, 44.455368, 3.089592456817626953, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+4, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 989.7535, -458.97223, 44.41196, 3.809622764587402343, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+5, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 888.0174, -459.61978, 44.270454, 5.203876495361328125, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID+6, 140350, 1643, 0, 0, 0, @PHASE, 0, @SWAP, 0, 1, 674.2747, -544.88184, 44.555004, 3.711420297622680664, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`MountCreatureID`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`visibilityDistanceType`,`auras`) VALUES
(@CGUID+0,0,0,0,0,1,0,0,0,0,0,'131700'),
(@CGUID+1,0,0,0,0,1,0,0,0,0,0,'131700 273259'),
(@CGUID+2,0,0,0,0,0,0,0,0,0,0,'131700'),
(@CGUID+3,0,0,0,0,1,0,0,0,0,0,'131700'),
(@CGUID+4,0,0,0,0,0,0,0,0,0,0,'131700'),
(@CGUID+5,0,0,0,0,0,0,0,0,0,0,'131700'),
(@CGUID+6,0,0,0,0,1,0,0,0,0,0,'131700');

-- Harbor Guard Captain Entry: 140350 SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=140350;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID-2,-@CGUID-4,-@CGUID-5) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID-2,0,0,0,1,0,100,0,5000,15000,5000,15000,0,10,1,6,273,274,0,0,1,0,0,0,0,0,0,0,0,'Harbor Guard Captain - OOC - Do random emote'),
(-@CGUID-4,0,0,0,1,0,100,0,5000,15000,5000,15000,0,10,1,6,273,274,0,0,1,0,0,0,0,0,0,0,0,'Harbor Guard Captain - OOC - Do random emote'),
(-@CGUID-5,0,0,0,1,0,100,0,5000,15000,5000,15000,0,10,1,6,273,274,0,0,1,0,0,0,0,0,0,0,0,'Harbor Guard Captain - OOC - Do random emote');

-- Pathing for Harbor Guard Captain Entry: 140350
SET @NPC := @CGUID+3;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=991,`position_y`=-465.16495,`position_z`=44.45536 WHERE `guid`=@NPC;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,991,-465.16495,44.45536,NULL,0,0,0,100,0),
(@PATH,2,1014.882,-466.408,44.455368,NULL,4000,0,0,100,0),
(@PATH,3,991,-465.16495,44.45536,NULL,0,0,0,100,0),
(@PATH,4,952.2778,-465.24307,44.45536,NULL,0,0,0,100,0),
(@PATH,5,937.3733,-466.38022,44.455368,NULL,0,0,0,100,0),
(@PATH,6,913.6455,-469.19626,44.52638,NULL,0,0,0,100,0),
(@PATH,7,888.033,-472.69272,44.466824,NULL,0,0,0,100,0),
(@PATH,8,857.6893,-477.25174,44.556526,NULL,4000,0,0,100,0),
(@PATH,9,888.033,-472.69272,44.466824,NULL,0,0,0,100,0),
(@PATH,10,913.6024,-469.2014,44.54396,NULL,0,0,0,100,0),
(@PATH,11,937.3733,-466.38022,44.455368,NULL,0,0,0,100,0),
(@PATH,12,952.2778,-465.24307,44.45536,NULL,0,0,0,100,0);

-- Pathing for Harbor Guard Captain Entry: 140350
SET @NPC := @CGUID+6;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=657.67017,`position_y`=-555.5208,`position_z`=44.520054 WHERE `guid`=@NPC;
UPDATE `creature_addon` SET `path_id`=@PATH WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,657.67017,-555.5208,44.520054,NULL,0,0,0,100,0),
(@PATH,2,674.9167,-544.4705,44.55491,NULL,4000,0,0,100,0),
(@PATH,3,657.67017,-555.5208,44.520054,NULL,0,0,0,100,0),
(@PATH,4,642.6406,-565.5018,44.472332,NULL,0,0,0,100,0),
(@PATH,5,618.8906,-581.25696,44.458122,NULL,0,0,0,100,0),
(@PATH,6,608.8403,-588.61115,44.519245,NULL,0,0,0,100,0),
(@PATH,7,594.6493,-600.5903,44.528545,NULL,0,0,0,100,0),
(@PATH,8,575.8264,-616.2465,44.530075,NULL,0,0,0,100,0),
(@PATH,9,562.9549,-627.9358,44.458122,NULL,0,0,0,100,0),
(@PATH,10,549.7049,-640.13715,44.458122,NULL,0,0,0,100,0),
(@PATH,11,537.11456,-653.59204,44.551437,NULL,0,0,0,100,0),
(@PATH,12,523.42706,-668.3368,44.47702,NULL,0,0,0,100,0),
(@PATH,13,509.61633,-685.40454,44.459534,NULL,0,0,0,100,0),
(@PATH,14,497.8212,-700.42017,44.552464,NULL,4000,0,0,100,0),
(@PATH,15,509.61633,-685.40454,44.459534,NULL,0,0,0,100,0),
(@PATH,16,523.42706,-668.3368,44.47702,NULL,0,0,0,100,0),
(@PATH,17,537.11456,-653.59204,44.551437,NULL,0,0,0,100,0),
(@PATH,18,549.7049,-640.13715,44.458122,NULL,0,0,0,100,0),
(@PATH,19,562.9549,-627.9358,44.458122,NULL,0,0,0,100,0),
(@PATH,20,575.8264,-616.2465,44.530075,NULL,0,0,0,100,0),
(@PATH,21,594.6493,-600.5903,44.528545,NULL,0,0,0,100,0),
(@PATH,22,608.8403,-588.61115,44.519245,NULL,0,0,0,100,0),
(@PATH,23,618.8906,-581.25696,44.458122,NULL,0,0,0,100,0),
(@PATH,24,642.6406,-565.5018,44.472332,NULL,0,0,0,100,0);
