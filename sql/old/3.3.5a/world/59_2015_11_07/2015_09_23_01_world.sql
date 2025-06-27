DELETE FROM `creature` WHERE `guid` IN (86098, 86097, 86092, 86091, 86090, 86088, 86089, 86087, 86086, 86085);

-- Pathing for Dragonmaw Shaman Entry: 21720 'TDB FORMAT' 
SET @NPC := 75806;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4178.686,`position_y`=490.5659,`position_z`=30.16439 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4178.686,490.5659,30.16439,0,0,0,0,100,0), -- 10:20:24
(@PATH,2,-4197.292,485.9068,30.38932,0,0,0,0,100,0), -- 10:20:35
(@PATH,3,-4225.723,467.5575,41.27721,0,0,0,0,100,0), -- 10:20:44
(@PATH,4,-4215.874,436.8994,48.21687,0,0,0,0,100,0), -- 10:20:57
(@PATH,5,-4237.429,402.9925,63.27236,0,0,0,0,100,0), -- 10:21:13
(@PATH,6,-4257.311,375.9668,78.98435,0,0,0,0,100,0), -- 10:21:30
(@PATH,7,-4218.265,427.3583,49.21005,0,0,0,0,100,0), -- 10:21:59
(@PATH,8,-4226.337,464.256,42.97073,0,0,0,0,100,0), -- 10:22:17
(@PATH,9,-4205.016,481.8601,31.38265,0,0,0,0,100,0), -- 10:22:32
(@PATH,10,-4193.525,487.0911,30.10522,0,0,0,0,100,0), -- 10:22:46
(@PATH,11,-4172.567,476.759,31.17034,0,0,0,0,100,0), -- 10:22:55
(@PATH,12,-4151.987,448.1165,33.53831,0,0,0,0,100,0), -- 10:23:06
(@PATH,13,-4113.85,424.8085,34.97233,0,0,0,0,100,0), -- 10:23:18
(@PATH,14,-4147.163,444.2449,34.1104,0,0,0,0,100,0), -- 10:23:38
(@PATH,15,-4157.673,454.7521,31.41072,0,0,0,0,100,0); -- 10:23:57

-- Pathing for Dragonmaw Shaman Entry: 21720 'TDB FORMAT' 
SET @NPC := 75803;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4294.086,`position_y`=400.621,`position_z`=81.62926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,233, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4294.086,400.621,81.62926,0,25000,0,0,100,0), -- 10:13:30
(@PATH,2,-4292.586,399.621,81.62926,0,25000,0,0,100,0); -- 10:13:50

-- Pathing for Dragonmaw Shaman Entry: 21720 'TDB FORMAT' 
SET @NPC := 75798;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4244.082,`position_y`=315.9884,`position_z`=134.664 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4244.082,315.9884,134.664,0,0,0,0,100,0), -- 10:12:22
(@PATH,2,-4235.726,319.797,134.6712,0,0,0,0,100,0), -- 10:12:25
(@PATH,3,-4229.505,315.7428,134.6895,0,0,0,0,100,0), -- 10:12:28
(@PATH,4,-4194.724,303.9587,136.7709,0,0,0,0,100,0), -- 10:12:30
(@PATH,5,-4190.966,294.0813,135.7594,0,0,0,0,100,0), -- 10:12:45
(@PATH,6,-4183.756,287.0773,135.6553,0,0,0,0,100,0), -- 10:14:20
(@PATH,7,-4191.174,297.8928,136.033,0,0,0,0,100,0), -- 10:14:26
(@PATH,8,-4220.702,310.0533,134.9795,0,0,0,0,100,0), -- 10:14:30
(@PATH,9,-4229.358,315.7001,134.6958,0,0,0,0,100,0), -- 10:14:45
(@PATH,10,-4230.426,317.3666,134.676,0,0,0,0,100,0), -- 10:14:48
(@PATH,11,-4235.935,319.6286,134.6698,0,0,0,0,100,0), -- 10:14:50
(@PATH,12,-4255.562,318.7018,134.6108,0,0,0,0,100,0), -- 10:14:54
(@PATH,13,-4249.844,317.125,134.6809,0,0,0,0,100,0), -- 10:15:00
(@PATH,14,-4243.675,313.4105,134.6629,0,0,0,0,100,0), -- 10:15:06
(@PATH,15,-4235.89,308.923,134.6676,0,0,0,0,100,0), -- 10:15:08
(@PATH,16,-4230.517,310.4198,134.6871,0,0,0,0,100,0), -- 10:15:11
(@PATH,17,-4194.894,303.7994,136.77,0,0,0,0,100,0), -- 10:15:14
(@PATH,18,-4188.841,309.6393,135.933,0,0,0,0,100,0), -- 10:15:29
(@PATH,19,-4175.213,316.2365,135.7092,0,0,0,0,100,0), -- 10:15:34
(@PATH,20,-4161.508,360.043,141.9081,0,0,0,0,100,0), -- 10:15:40
(@PATH,21,-4171.737,320.0564,135.9073,0,0,0,0,100,0), -- 10:16:01
(@PATH,22,-4185.639,313.6697,135.3489,0,0,0,0,100,0), -- 10:16:20
(@PATH,23,-4191.21,305.0679,136.4015,0,0,0,0,100,0), -- 10:16:26
(@PATH,24,-4220.617,309.9903,134.8077,0,0,0,0,100,0), -- 10:16:31
(@PATH,25,-4229.755,310.8228,134.6904,0,0,0,0,100,0), -- 10:16:45
(@PATH,26,-4235.208,308.5773,134.6808,0,0,0,0,100,0), -- 10:16:48
(@PATH,27,-4243.492,313.3849,134.6674,0,0,0,0,100,0), -- 10:16:51
(@PATH,28,-4255.519,318.5628,134.6098,0,0,0,0,100,0), -- 10:16:54
(@PATH,29,-4249.62,317.301,134.6521,0,0,0,0,100,0); -- 10:17:00

-- Pathing for Dragonmaw Shaman Entry: 21720 'TDB FORMAT' 
SET @NPC := 75801;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4263.521,`position_y`=408.381,`position_z`=79.67068 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4263.521,408.381,79.67068,0,0,0,0,100,0), -- 10:12:48
(@PATH,2,-4275.601,391.1442,81.45609,0,0,0,0,100,0), -- 10:13:03
(@PATH,3,-4276.916,384.2662,79.99209,0,0,0,0,100,0), -- 10:13:13
(@PATH,4,-4272.852,367.3383,83.40826,0,0,0,0,100,0), -- 10:13:19
(@PATH,5,-4299.143,333.1703,109.8589,0,0,0,0,100,0), -- 10:13:24
(@PATH,6,-4291.638,298.5769,121.6239,0,0,0,0,100,0), -- 10:13:44
(@PATH,7,-4284.62,294.5884,122.3762,0,0,0,0,100,0), -- 10:14:00
(@PATH,8,-4265.867,286.0486,122.6935,0,0,0,0,100,0), -- 10:14:11
(@PATH,9,-4231.655,272.0292,122.6157,0,0,0,0,100,0), -- 10:14:22
(@PATH,10,-4221.664,271.404,122.5952,0,0,0,0,100,0), -- 10:14:30
(@PATH,11,-4221.826,271.2171,122.3309,0,0,0,0,100,0), -- 10:14:42
(@PATH,12,-4241.433,272.7845,122.9299,0,0,0,0,100,0), -- 10:14:50
(@PATH,13,-4243.721,273.0889,123.1742,0,0,0,0,100,0), -- 10:15:00
(@PATH,14,-4287.71,296.0865,122.0869,0,0,0,0,100,0), -- 10:15:09
(@PATH,15,-4299.358,330.6028,110.9833,0,0,0,0,100,0), -- 10:15:20
(@PATH,16,-4274.684,364.696,85.32684,0,0,0,0,100,0), -- 10:15:36
(@PATH,17,-4269.528,373.963,80.26889,0,0,0,0,100,0), -- 10:15:57
(@PATH,18,-4276.889,385.2,79.98441,0,0,0,0,100,0); -- 10:16:01

-- Dragonmaw Subjugator SAI
SET @ENTRY := 21718;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Aggro - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Within 0-40 Range - Cast 'Shadow Bolt' (No Repeat)"),
(@ENTRY,0,4,5,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,10,11,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Subjugator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,13,0,6,0,100,1,0,0,0,0,33,22197,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Subjugator - On Just Died - Quest Credit 'Infiltrating Dragonmaw Fortress' (No Repeat)");

-- Pathing for Dragonmaw Subjugator Entry: 21718 'TDB FORMAT' 
SET @NPC := 75774;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4102.015,`position_y`=377.2606,`position_z`=30.89463 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4102.015,377.2606,30.89463,0,0,0,0,100,0), -- 10:20:43
(@PATH,2,-4108.736,382.3355,30.58962,0,0,0,0,100,0), -- 10:20:47
(@PATH,3,-4115.181,384.7361,30.83398,0,0,0,0,100,0), -- 10:20:49
(@PATH,4,-4115.945,392.739,30.79796,0,0,0,0,100,0), -- 10:20:53
(@PATH,5,-4111.743,392.8836,30.53397,0,0,0,0,100,0), -- 10:20:54
(@PATH,6,-4106.752,389.3356,30.54209,0,0,0,0,100,0), -- 10:20:57
(@PATH,7,-4103.535,395.7037,30.67706,0,0,0,0,100,0), -- 10:21:00
(@PATH,8,-4103.445,396.1037,30.62162,0,0,0,0,100,0), -- 10:21:02
(@PATH,9,-4099.806,402.0006,30.79059,0,0,0,0,100,0), -- 10:21:14
(@PATH,10,-4099.44,401.964,30.87934,0,0,0,0,100,0), -- 10:21:15
(@PATH,11,-4086.569,405.2619,30.82691,0,0,0,0,100,0), -- 10:21:21
(@PATH,12,-4089.497,392.9045,30.76514,0,0,0,0,100,0), -- 10:21:26
(@PATH,13,-4089.03,381.2375,31.16474,0,0,0,0,100,0), -- 10:21:31
(@PATH,14,-4091.608,379.7381,30.97511,0,0,0,0,100,0); -- 10:21:33

-- Pathing for Dragonmaw Subjugator Entry: 21718 'TDB FORMAT' 
SET @NPC := 75780;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4192.549,`position_y`=463.3147,`position_z`=30.76653 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4192.549,463.3147,30.76653,0,0,0,0,100,0), -- 10:21:58
(@PATH,2,-4188.431,467.3629,30.58786,0,0,0,0,100,0); -- 10:22:00
