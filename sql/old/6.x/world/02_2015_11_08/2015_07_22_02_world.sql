-- Valley of Trails - Emotes
-- Den Grunt - Waypoints
-- 1.
-- Huklah SAI
SET @ENTRY := 3160;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huklah - Out of Combat - Play Emote 1");

-- 2.
-- Rarc SAI
SET @ENTRY := 3161;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rarc - Out of Combat - Play Emote 1");

-- 3.
-- Kzan Thornslash SAI
SET @ENTRY := 3159;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kzan Thornslash - Out of Combat - Play Emote 1");

-- 4.
-- Zureetha Fargaze SAI
SET @ENTRY := 3145;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zureetha Fargaze - Out of Combat - Play Emote 1");

-- 5.
-- Foreman Thazz'ril SAI
SET @ENTRY := 11378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Thazz'ril - Out of Combat - Play Emote 1");

-- 6.
-- Hraug SAI
SET @ENTRY := 12776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hraug - Out of Combat - Play Emote 1");

-- 7.
-- Nartok SAI
SET @ENTRY := 3156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nartok - Out of Combat - Play Emote 1");

-- 8.
-- Gornek SAI
SET @ENTRY := 3143;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gornek - Out of Combat - Play Emote 7");

-- 9. Pathing for one grunt in cave
SET @NPC := 308545;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-592.4183,`position_y`=-4144.538,`position_z`=42.11545 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-592.4183,-4144.538,42.11545,0,0,0,0,100,0),
(@PATH,2,-594.1683,-4146.038,42.36545,0,0,0,0,100,0),
(@PATH,3,-595.1683,-4147.788,42.86545,0,0,0,0,100,0),
(@PATH,4,-595.4252,-4148.025,42.76385,0,0,0,0,100,0),
(@PATH,5,-597.1752,-4150.275,43.01385,0,0,0,0,100,0),
(@PATH,6,-598.1752,-4150.775,43.26385,0,0,0,0,100,0),
(@PATH,7,-600.1752,-4152.525,43.26385,0,0,0,0,100,0),
(@PATH,8,-602.345,-4154.116,43.25286,0,0,0,0,100,0),
(@PATH,9,-604.345,-4155.866,43.50286,0,0,0,0,100,0),
(@PATH,10,-604.7183,-4156.001,43.54986,0,0,0,0,100,0),
(@PATH,11,-606.2183,-4157.501,43.04986,0,0,0,0,100,0),
(@PATH,12,-605.9683,-4160.751,43.04986,0,0,0,0,100,0),
(@PATH,13,-606.0277,-4160.863,43.04424,0,0,0,0,100,0),
(@PATH,14,-605.7777,-4162.613,42.54424,0,0,0,0,100,0),
(@PATH,15,-605.7777,-4163.863,42.29424,0,0,0,0,100,0),
(@PATH,16,-605.0752,-4169.27,41.48709,0,0,0,0,100,0),
(@PATH,17,-604.8252,-4171.77,41.48709,0,0,0,0,100,0),
(@PATH,18,-604.4944,-4171.907,41.24754,0,0,0,0,100,0),
(@PATH,19,-604.4944,-4174.407,41.24754,0,0,0,0,100,0),
(@PATH,20,-604.2444,-4175.657,41.49754,0,0,0,0,100,0),
(@PATH,21,-604.3888,-4174.307,41.29676,0,0,0,0,100,0),
(@PATH,22,-604.6388,-4172.807,41.29676,0,0,0,0,100,0),
(@PATH,23,-604.8888,-4169.557,41.29676,0,0,0,0,100,0),
(@PATH,24,-605.2297,-4169.213,41.4446,0,0,0,0,100,0),
(@PATH,25,-605.2297,-4168.963,41.6946,0,0,0,0,100,0),
(@PATH,26,-605.4797,-4163.713,42.1946,0,0,0,0,100,0),
(@PATH,27,-605.8757,-4163.593,42.36644,0,0,0,0,100,0),
(@PATH,28,-605.8757,-4162.343,42.61644,0,0,0,0,100,0),
(@PATH,29,-606.1257,-4160.843,43.11644,0,0,0,0,100,0),
(@PATH,30,-606.3243,-4157.373,43.03017,0,0,0,0,100,0),
(@PATH,31,-604.3243,-4156.123,43.53017,0,0,0,0,100,0),
(@PATH,32,-604.3931,-4155.768,43.53776,0,0,0,0,100,0),
(@PATH,33,-602.1431,-4153.768,43.28776,0,0,0,0,100,0),
(@PATH,34,-600.8931,-4153.018,43.28776,0,0,0,0,100,0),
(@PATH,35,-598.1431,-4151.018,43.28776,0,0,0,0,100,0),
(@PATH,36,-597.8702,-4150.589,43.08055,0,0,0,0,100,0),
(@PATH,37,-596.8702,-4150.089,43.08055,0,0,0,0,100,0),
(@PATH,38,-595.6202,-4149.339,42.83055,0,0,0,0,100,0),
(@PATH,39,-593.8702,-4146.589,42.33055,0,0,0,0,100,0),
(@PATH,40,-593.4512,-4146.553,42.31656,0,0,0,0,100,0),
(@PATH,41,-592.7012,-4144.803,42.06656,0,0,0,0,100,0),
(@PATH,42,-592.2012,-4140.803,42.06656,0,0,0,0,100,0),
(@PATH,43,-591.4512,-4135.553,42.06656,0,0,0,0,100,0),
(@PATH,44,-590.9252,-4134.109,42.22979,0,0,0,0,100,0),
(@PATH,45,-589.9252,-4131.359,42.47979,0,0,0,0,100,0),
(@PATH,46,-589.6752,-4130.109,42.72979,0,0,0,0,100,0),
(@PATH,47,-588.9252,-4128.109,43.22979,0,0,0,0,100,0),
(@PATH,48,-588.726,-4127.853,43.16886,0,0,0,0,100,0),
(@PATH,49,-588.226,-4126.603,43.41886,0,0,0,0,100,0),
(@PATH,50,-587.976,-4125.603,43.41886,0,0,0,0,100,0),
(@PATH,51,-586.6942,-4122.214,43.93642,0,0,0,0,100,0),
(@PATH,52,-587.6942,-4118.464,43.93642,0,0,0,0,100,0),
(@PATH,53,-587.8058,-4118.299,44.03777,0,0,0,0,100,0),
(@PATH,54,-588.3058,-4116.049,44.03777,0,0,0,0,100,0),
(@PATH,55,-589.3058,-4115.049,44.28777,0,0,0,0,100,0),
(@PATH,56,-592.0012,-4112.077,44.46067,0,0,0,0,100,0),
(@PATH,57,-595.5012,-4110.827,43.96067,0,0,0,0,100,0),
(@PATH,58,-595.5062,-4110.993,43.98151,0,0,0,0,100,0),
(@PATH,59,-592.7562,-4111.743,44.48151,0,0,0,0,100,0),
(@PATH,60,-592.4868,-4112.001,44.43573,0,0,0,0,100,0),
(@PATH,61,-591.7368,-4112.251,44.43573,0,0,0,0,100,0),
(@PATH,62,-589.2368,-4114.751,44.18573,0,0,0,0,100,0),
(@PATH,63,-589.0537,-4114.994,44.22446,0,0,0,0,100,0),
(@PATH,64,-588.3037,-4116.244,44.22446,0,0,0,0,100,0),
(@PATH,65,-587.8037,-4118.494,43.97446,0,0,0,0,100,0),
(@PATH,66,-587.0537,-4121.494,44.22446,0,0,0,0,100,0),
(@PATH,67,-586.8948,-4121.602,44.06555,0,0,0,0,100,0),
(@PATH,68,-586.6448,-4122.352,44.06555,0,0,0,0,100,0),
(@PATH,69,-587.8948,-4125.352,43.56555,0,0,0,0,100,0),
(@PATH,70,-587.9706,-4125.508,43.57565,0,0,0,0,100,0),
(@PATH,71,-588.4706,-4126.758,43.32565,0,0,0,0,100,0),
(@PATH,72,-588.9706,-4128.008,43.32565,0,0,0,0,100,0),
(@PATH,73,-589.2206,-4129.258,42.82565,0,0,0,0,100,0),
(@PATH,74,-589.9706,-4131.008,42.57565,0,0,0,0,100,0),
(@PATH,75,-590.3362,-4131.271,42.41715,0,0,0,0,100,0),
(@PATH,76,-591.0862,-4133.271,42.16715,0,0,0,0,100,0),
(@PATH,77,-591.3362,-4135.771,41.91715,0,0,0,0,100,0),
(@PATH,78,-591.8362,-4140.521,42.16715,0,0,0,0,100,0),
(@PATH,79,-592.481,-4144.521,42.06772,0,0,0,0,100,0);
