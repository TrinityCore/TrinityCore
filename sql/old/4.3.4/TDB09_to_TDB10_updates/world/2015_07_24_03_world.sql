-- 
-- Razor Hill Updates
-- Waypoints
-- Guard 1.
SET @NPC := 310315;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=260.8195,`position_y`=-4747.082,`position_z`=10.17437 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=260.8195,`position_y`=-4747.082,`position_z`=10.17437 WHERE `guid`=310314;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,260.8195,-4747.082,10.17437,0,0,0,0,100,0),
(@PATH,2,261.068,-4746.886,10.34651,0,0,0,0,100,0),
(@PATH,3,267.574,-4747.65,10.22179,0,0,0,0,100,0),
(@PATH,4,274.3544,-4743.961,9.987007,0,0,0,0,100,0),
(@PATH,5,274.1684,-4743.915,9.820413,0,0,0,0,100,0),
(@PATH,6,274.1089,-4743.937,9.872446,0,0,0,0,100,0),
(@PATH,7,267.4261,-4747.646,10.06517,0,0,0,0,100,0),
(@PATH,8,260.7122,-4746.721,10.38764,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=310315;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(310315, 310315, 0, 0, 2, 0, 0),
(310315, 310314, 3, 90, 2, 0, 0);

-- Guard 2.
SET @NPC := 310335;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=275.6352,`position_y`=-4668.426,`position_z`=12.8811 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=275.6352,`position_y`=-4668.426,`position_z`=12.8811 WHERE `guid`=310334;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,275.6352,-4668.426,12.8811,0,0,0,0,100,0),
(@PATH,2,273.6506,-4666.062,13.08665,0,0,0,0,100,0),
(@PATH,3,271.6907,-4663.727,13.25194,0,0,0,0,100,0),
(@PATH,4,269.7554,-4661.421,13.34556,0,0,0,0,100,0),
(@PATH,5,298.0506,-4711.37,12.33724,0,0,0,0,100,0),
(@PATH,6,267.7961,-4659.086,13.46165,0,0,0,0,100,0),
(@PATH,7,265.8544,-4656.773,13.71165,0,0,0,0,100,0),
(@PATH,8,263.9081,-4654.46,13.83665,0,0,0,0,100,0),
(@PATH,9,261.9519,-4652.141,14.02074,0,0,0,0,100,0),
(@PATH,10,260.0037,-4649.832,14.21165,0,0,0,0,100,0),
(@PATH,11,259.4917,-4649.225,14.21165,0,0,0,0,100,0),
(@PATH,12,260.0781,-4649.92,14.21165,0,0,0,0,100,0),
(@PATH,13,262.1337,-4652.373,13.97081,0,0,0,0,100,0),
(@PATH,14,264.0781,-4654.689,13.83665,0,0,0,0,100,0),
(@PATH,15,266.016,-4656.999,13.71165,0,0,0,0,100,0),
(@PATH,16,267.9784,-4659.337,13.46165,0,0,0,0,100,0),
(@PATH,17,269.9297,-4661.662,13.37474,0,0,0,0,100,0),
(@PATH,18,271.8778,-4663.983,13.22118,0,0,0,0,100,0),
(@PATH,19,273.8371,-4666.317,13.08665,0,0,0,0,100,0),
(@PATH,20,275.808,-4668.65,12.85424,0,0,0,0,100,0),
(@PATH,21,277.7315,-4670.925,12.65478,0,0,0,0,100,0),
(@PATH,22,279.667,-4673.257,12.52978,0,0,0,0,100,0),
(@PATH,23,281.6104,-4675.599,12.39526,0,0,0,0,100,0),
(@PATH,24,283.5299,-4677.912,12.15478,0,0,0,0,100,0),
(@PATH,25,285.4637,-4680.241,12.02978,0,0,0,0,100,0),
(@PATH,26,287.4154,-4682.586,12.02978,0,0,0,0,100,0),
(@PATH,27,289.3655,-4684.929,11.77563,0,0,0,0,100,0),
(@PATH,28,291.2932,-4687.246,11.77978,0,0,0,0,100,0),
(@PATH,29,293.2322,-4689.575,11.65478,0,0,0,0,100,0),
(@PATH,30,295.1823,-4691.918,11.57775,0,0,0,0,100,0),
(@PATH,31,295.9389,-4693.084,11.52978,0,0,0,0,100,0),
(@PATH,32,296.8628,-4696.058,11.52978,0,0,0,0,100,0),
(@PATH,33,297.7829,-4699.02,11.40478,0,0,0,0,100,0),
(@PATH,34,298.6939,-4701.953,11.45214,0,0,0,0,100,0),
(@PATH,35,299.6132,-4704.912,11.23656,0,0,0,0,100,0),
(@PATH,36,300.531,-4707.867,10.95788,0,0,0,0,100,0),
(@PATH,37,301.4541,-4710.838,10.84362,0,0,0,0,100,0),
(@PATH,38,301.6698,-4711.533,10.9696,0,0,0,0,100,0),
(@PATH,39,301.4165,-4710.716,10.96364,0,0,0,0,100,0),
(@PATH,40,300.4462,-4707.594,10.98278,0,0,0,0,100,0),
(@PATH,41,299.5423,-4704.684,11.27258,0,0,0,0,100,0),
(@PATH,42,298.6383,-4701.774,11.48022,0,0,0,0,100,0),
(@PATH,43,297.7329,-4698.859,11.40478,0,0,0,0,100,0),
(@PATH,44,296.8334,-4695.963,11.52978,0,0,0,0,100,0),
(@PATH,45,295.9257,-4693.042,11.52978,0,0,0,0,100,0),
(@PATH,46,295.2031,-4691.94,11.57275,0,0,0,0,100,0),
(@PATH,47,312.8671,-4716.274,11.78977,0,0,0,0,100,0),
(@PATH,48,314.1171,-4713.774,12.53977,0,0,0,0,100,0),
(@PATH,49,317.6638,-4721.014,11.66282,0,0,0,0,100,0),
(@PATH,50,321.4138,-4721.264,12.16282,0,0,0,0,100,0),
(@PATH,51,321.6695,-4721.188,12.33877,0,0,0,0,100,0),
(@PATH,52,320.7786,-4718.9,12.46596,0,0,0,0,100,0),
(@PATH,53,323.0286,-4717.65,13.21596,0,0,0,0,100,0),
(@PATH,54,293.2262,-4689.559,11.65478,0,0,0,0,100,0),
(@PATH,55,291.264,-4687.194,11.77978,0,0,0,0,100,0),
(@PATH,56,333.3965,-4722.975,11.41607,0,0,0,0,100,0),
(@PATH,57,335.1465,-4723.225,10.66607,0,0,0,0,100,0),
(@PATH,58,289.2969,-4684.824,11.78832,0,0,0,0,100,0),
(@PATH,59,287.3265,-4682.45,12.02978,0,0,0,0,100,0),
(@PATH,60,285.3611,-4680.082,12.02978,0,0,0,0,100,0),
(@PATH,61,283.3985,-4677.723,12.15478,0,0,0,0,100,0),
(@PATH,62,281.4141,-4675.343,12.42626,0,0,0,0,100,0),
(@PATH,63,279.4396,-4672.974,12.52978,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=310335;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(310335, 310335, 0, 0, 2, 0, 0),
(310335, 310334, 3, 90, 2, 0, 0);

-- Emotes
-- Uhgar SAI
SET @ENTRY := 3163;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Uhgar - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 316300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uhgar - On Script - Set Emote State 69"),
(@ENTRY,9,3,0,0,0,100,0,10000,10000,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uhgar - On Script - Set Emote State 233");

-- Cook Torka SAI
-- Cook Torka SAI
SET @ENTRY := 3191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,20000,20000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cook Torka - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 319100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");
