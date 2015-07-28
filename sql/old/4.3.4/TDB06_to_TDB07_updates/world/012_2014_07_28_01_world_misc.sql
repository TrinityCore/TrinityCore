-- Kil'sorrow Spellbinder SAI
SET @ENTRY := 17146;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - In Combat CMC - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,20000,25000,11,22744,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - In Combat - Cast 'Chains of Ice'"),
(@ENTRY,0,2,0,13,0,90,0,25000,25000,0,0,11,31999,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Target Casting - Cast 'Counterspell'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Spellbinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Kil'sorrow Cultist SAI
SET @ENTRY := -28654;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,31902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Cultist - Reset - Cast 'Purple Beam'"),
(@ENTRY,0,1,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 'Mind Sear'");

-- Kil'sorrow Cultist SAI
SET @ENTRY := -28655;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,31902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Cultist - Reset - Cast 'Purple Beam'"),
(@ENTRY,0,1,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 'Mind Sear'");

-- Kil'sorrow Cultist SAI
SET @ENTRY := -28656;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,31902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Cultist - Reset - Cast 'Purple Beam'"),
(@ENTRY,0,1,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 'Mind Sear'");

-- Kil'sorrow Cultist SAI
SET @ENTRY := -28657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,31902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kil'sorrow Cultist - Reset - Cast 'Purple Beam'"),
(@ENTRY,0,1,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 'Mind Sear'");

-- Kil'sorrow Cultist SAI
SET @ENTRY := 17147;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,4500,4500,7000,11000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kil'sorrow Cultist - In Combat - Cast 'Mind Sear'");

-- Kil'sorrow Cultist fix up addons
DELETE FROM `creature_addon` WHERE `guid` IN (28654,28655,28656,28657,60213,60215,60221);
DELETE FROM `creature_template_addon` WHERE `entry`=17147;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`)VALUES (17147,0,0,0,1,0, '16592');

-- Add spell condition for Purple Beam
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=31902;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 31902, 0, 0, 31, 0, 3, 19656, 0, 0, 0, 0, '', 'Purple Beam Targets Invisible Location Trigger');

-- Add Missing Kil'sorrow Spellbinder & Cultist Spawns
SET @CGUID := 213225;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 17147, 530, 1, 1, 1, -2966.403, 6452.863, 84.96134, 6.021386, 120, 0, 0),
(@CGUID+1, 17146, 530, 1, 1, 1, -2966.403, 6450.863, 84.96134, 6.021386, 120, 0, 0),
(@CGUID+2, 17147, 530, 1, 1, 1, -2884.375, 6580.407, 49.82686, 4.698485, 120, 0, 0),
(@CGUID+3, 17146, 530, 1, 1, 1, -2886.375, 6580.407, 49.82686, 4.698485, 120, 0, 0),
(@CGUID+4, 17147, 530, 1, 1, 1, -2794.054, 6424.335, 62.25868, 4.572828, 120, 0, 0),
(@CGUID+5, 17146, 530, 1, 1, 1, -2796.054, 6424.335, 62.25868, 4.572828, 120, 0, 0),
(@CGUID+6, 17147, 530, 1, 1, 1, -2857.618, 6466.858, 82.75233, 4.788821, 120, 0, 0),
(@CGUID+7, 17146, 530, 1, 1, 1, -2858.218, 6466.858, 82.75233, 4.788821, 120, 0, 0),
(@CGUID+8, 17147, 530, 1, 1, 1, -2934.352, 6331.253, 88.43297, 1.203481, 120, 0, 0),
(@CGUID+9, 17146, 530, 1, 1, 1, -2932.352, 6330.253, 88.43297, 1.203481, 120, 0, 0);

-- Kil'sorrow Spellbinder / Cultist Formations
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (213226,213228,213230,213232,213234);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`)VALUES
(213226,213226,0,0,2),(213226,213225,2,270,2),
(213228,213228,0,0,2),(213228,213227,2,270,2),
(213230,213230,0,0,2),(213230,213229,2,270,2),
(213232,213232,0,0,2),(213232,213231,2,270,2),
(213234,213234,0,0,2),(213234,213233,2,270,2);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 213226;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2966.403,`position_y`=6450.863,`position_z`=84.96134 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2966.403,6450.863,84.96134,0,0,0,0,100,0),
(@PATH,2,-2951.366,6451.252,84.06266,0,0,0,0,100,0),
(@PATH,3,-2947.001,6458.422,83.78898,0,0,0,0,100,0),
(@PATH,4,-2933.374,6459.891,82.71134,0,0,0,0,100,0),
(@PATH,5,-2928.819,6466.733,82.45881,0,0,0,0,100,0),
(@PATH,6,-2933.261,6499.875,81.98237,0,0,0,0,100,0),
(@PATH,7,-2932.741,6517.529,76.60457,0,0,0,0,100,0),
(@PATH,8,-2924.629,6533.378,69.05309,0,0,0,0,100,0),
(@PATH,9,-2899.833,6556.306,55.69653,0,0,0,0,100,0),
(@PATH,10,-2878.803,6570.991,49.01436,0,0,0,0,100,0),
(@PATH,11,-2855.887,6555.953,40.81544,0,0,0,0,100,0),
(@PATH,12,-2878.803,6570.991,49.01436,0,0,0,0,100,0),
(@PATH,13,-2899.833,6556.306,55.69653,0,0,0,0,100,0),
(@PATH,14,-2924.472,6533.658,69.22276,0,0,0,0,100,0),
(@PATH,15,-2932.741,6517.529,76.60457,0,0,0,0,100,0),
(@PATH,16,-2933.261,6499.875,81.98237,0,0,0,0,100,0),
(@PATH,17,-2928.819,6466.733,82.45881,0,0,0,0,100,0),
(@PATH,18,-2933.374,6459.891,82.71134,0,0,0,0,100,0),
(@PATH,19,-2947.001,6458.422,83.78898,0,0,0,0,100,0),
(@PATH,20,-2951.366,6451.252,84.06266,0,0,0,0,100,0);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 213228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2886.375,`position_y`=6580.407,`position_z`=49.82686 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2886.375,6580.407,49.82686,0,0,0,0,100,0),
(@PATH,2,-2889.297,6558.6,52.20752,0,0,0,0,100,0),
(@PATH,3,-2875.24,6533.176,54.37968,0,0,0,0,100,0),
(@PATH,4,-2866.895,6523.676,56.61101,0,0,0,0,100,0),
(@PATH,5,-2845.4,6500.211,62.02013,0,0,0,0,100,0),
(@PATH,6,-2833.535,6486.23,62.87733,0,0,0,0,100,0),
(@PATH,7,-2822.089,6466.063,63.05643,0,0,0,0,100,0),
(@PATH,8,-2813.894,6437.624,63.46805,0,0,0,0,100,0),
(@PATH,9,-2800.375,6432.741,62.70899,0,0,0,0,100,0),
(@PATH,10,-2782.428,6431.978,61.04139,0,0,0,0,100,0),
(@PATH,11,-2800.375,6432.741,62.70899,0,0,0,0,100,0),
(@PATH,12,-2813.894,6437.624,63.46805,0,0,0,0,100,0),
(@PATH,13,-2822.089,6466.063,63.05643,0,0,0,0,100,0),
(@PATH,14,-2833.535,6486.23,62.87733,0,0,0,0,100,0),
(@PATH,15,-2845.4,6500.211,62.02013,0,0,0,0,100,0),
(@PATH,16,-2866.895,6523.676,56.61101,0,0,0,0,100,0),
(@PATH,17,-2875.24,6533.176,54.37968,0,0,0,0,100,0),
(@PATH,18,-2889.303,6558.567,52.30542,0,0,0,0,100,0);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 213230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2796.054,`position_y`=6424.335,`position_z`=62.25868 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2796.054,6424.335,62.25868,0,0,0,0,100,0),
(@PATH,2,-2800.321,6399.666,62.34266,0,0,0,0,100,0),
(@PATH,3,-2799.676,6388.983,63.19019,0,0,0,0,100,0),
(@PATH,4,-2792.213,6366.481,63.53901,0,0,0,0,100,0),
(@PATH,5,-2800.327,6352.1,63.54148,0,0,0,0,100,0),
(@PATH,6,-2811.064,6333.319,63.71547,0,0,0,0,100,0),
(@PATH,7,-2820.251,6313.478,63.65468,0,0,0,0,100,0),
(@PATH,8,-2833.449,6304.563,65.49826,0,0,0,0,100,0),
(@PATH,9,-2867.439,6307.764,77.54279,0,0,0,0,100,0),
(@PATH,10,-2878.416,6326.375,83.02692,0,0,0,0,100,0),
(@PATH,11,-2867.439,6307.764,77.54279,0,0,0,0,100,0),
(@PATH,12,-2833.449,6304.563,65.49826,0,0,0,0,100,0),
(@PATH,13,-2820.251,6313.478,63.65468,0,0,0,0,100,0),
(@PATH,14,-2811.064,6333.319,63.71547,0,0,0,0,100,0),
(@PATH,15,-2800.327,6352.1,63.54148,0,0,0,0,100,0),
(@PATH,16,-2792.213,6366.481,63.53901,0,0,0,0,100,0),
(@PATH,17,-2799.676,6388.983,63.19019,0,0,0,0,100,0),
(@PATH,18,-2800.321,6399.666,62.34266,0,0,0,0,100,0);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 213232;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2858.218,`position_y`=6466.858,`position_z`=82.75233 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2858.218,6466.858,82.75233,0,0,0,0,100,0),
(@PATH,2,-2857.816,6444.058,82.75547,0,0,0,0,100,0),
(@PATH,3,-2866.552,6441.649,82.75547,0,0,0,0,100,0),
(@PATH,4,-2879.884,6432.936,82.39103,0,0,0,0,100,0),
(@PATH,5,-2899.292,6416.391,82.04545,0,0,0,0,100,0),
(@PATH,6,-2913.055,6413.213,82.4074,0,0,0,0,100,0),
(@PATH,7,-2923.442,6433.533,82.46134,0,0,0,0,100,0),
(@PATH,8,-2929.056,6459.67,82.58634,0,0,0,0,100,0),
(@PATH,9,-2943.927,6460.137,83.43241,0,0,0,0,100,0),
(@PATH,10,-2947.446,6466.739,84.1551,0,0,0,0,100,0),
(@PATH,11,-2972.279,6499.877,91.33967,0,0,0,0,100,0),
(@PATH,12,-2982.886,6518.872,96.93003,0,0,0,0,100,0),
(@PATH,13,-2981.053,6533.41,97.79256,0,0,0,0,100,0),
(@PATH,14,-2989.642,6543.227,97.79256,0,0,0,0,100,0),
(@PATH,15,-2999.918,6546.718,97.91756,0,0,0,0,100,0),
(@PATH,16,-2989.642,6543.227,97.79256,0,0,0,0,100,0),
(@PATH,17,-2981.053,6533.41,97.79256,0,0,0,0,100,0),
(@PATH,18,-2982.886,6518.872,96.93003,0,0,0,0,100,0),
(@PATH,19,-2972.279,6499.877,91.33967,0,0,0,0,100,0),
(@PATH,20,-2947.446,6466.739,84.1551,0,0,0,0,100,0),
(@PATH,21,-2943.927,6460.137,83.43241,0,0,0,0,100,0),
(@PATH,22,-2929.056,6459.67,82.58634,0,0,0,0,100,0),
(@PATH,23,-2923.442,6433.533,82.46134,0,0,0,0,100,0),
(@PATH,24,-2913.055,6413.213,82.4074,0,0,0,0,100,0),
(@PATH,25,-2899.292,6416.391,82.04545,0,0,0,0,100,0),
(@PATH,26,-2879.884,6432.936,82.39103,0,0,0,0,100,0),
(@PATH,27,-2866.552,6441.649,82.75547,0,0,0,0,100,0),
(@PATH,28,-2857.816,6444.058,82.75547,0,0,0,0,100,0);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 213234;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2932.352,`position_y`=6330.253,`position_z`=88.43297 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2932.352,6330.253,88.43297,0,0,0,0,100,0),
(@PATH,2,-2923.53,6348.927,88.30698,0,0,0,0,100,0),
(@PATH,3,-2911.74,6366.638,86.12277,0,0,0,0,100,0),
(@PATH,4,-2911.893,6383.025,84.73821,0,0,0,0,100,0),
(@PATH,5,-2900.083,6384.457,82.65923,0,0,0,0,100,0),
(@PATH,6,-2866.759,6392.461,80.9828,0,0,0,0,100,0),
(@PATH,7,-2853.948,6386.78,79.65498,0,0,0,0,100,0),
(@PATH,8,-2842.023,6385.775,79.38105,0,0,0,0,100,0),
(@PATH,9,-2857.746,6387.74,80.24799,0,0,0,0,100,0),
(@PATH,10,-2857.456,6398.598,79.31879,0,0,0,0,100,0),
(@PATH,11,-2834.581,6418.426,71.13242,0,0,0,0,100,0),
(@PATH,12,-2819.072,6434.312,64.01407,0,0,0,0,100,0),
(@PATH,13,-2834.581,6418.426,71.13242,0,0,0,0,100,0),
(@PATH,14,-2857.456,6398.598,79.31879,0,0,0,0,100,0),
(@PATH,15,-2857.746,6387.74,80.24799,0,0,0,0,100,0),
(@PATH,16,-2842.023,6385.775,79.38105,0,0,0,0,100,0),
(@PATH,17,-2853.948,6386.78,79.65498,0,0,0,0,100,0),
(@PATH,18,-2866.759,6392.461,80.9828,0,0,0,0,100,0),
(@PATH,19,-2900.083,6384.457,82.65923,0,0,0,0,100,0),
(@PATH,20,-2911.893,6383.025,84.73821,0,0,0,0,100,0),
(@PATH,21,-2911.74,6366.638,86.12277,0,0,0,0,100,0),
(@PATH,22,-2923.53,6348.927,88.30698,0,0,0,0,100,0);

-- Pathing for Kil'sorrow Spellbinder Entry: 17146
SET @NPC := 60206;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2937.746,`position_y`=6326.745,`position_z`=89.08513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2937.746,6326.745,89.08513,0,0,0,0,100,0),
(@PATH,2,-2935.963,6330.98,88.382,0,0,0,0,100,0),
(@PATH,3,-2939.063,6332.813,88.37883,0,17000,0,476,100,0),
(@PATH,4,-2945.232,6323.478,89.62395,0,0,0,21,100,0),
(@PATH,5,-2959.155,6319.953,88.50652,0,0,0,0,100,0),
(@PATH,6,-2967.078,6318.835,87.68221,0,0,0,0,100,0),
(@PATH,7,-2968.813,6321.961,88.57487,0,20000,0,476,100,0),
(@PATH,8,-2960.756,6319.746,88.10429,0,0,0,21,100,0),
(@PATH,9,-2960.143,6317.857,88.76093,0,2000,0,0,100,0),
(@PATH,10,-2960.174,6317.34,88.76093,0,5000,0,50,100,0),
(@PATH,11,-2960.174,6317.34,88.76093,0,3000,0,12,100,0),
(@PATH,12,-2946.525,6321.191,89.73332,0,0,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=21;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES 
(21,0,1,0,1,0,0,0,0,0,21);
