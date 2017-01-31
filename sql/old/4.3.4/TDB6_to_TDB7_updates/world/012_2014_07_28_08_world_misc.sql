-- Pathing for Sparik Entry: 19012
SET @NPC := 68323;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `equipment_id`=1,`spawndist`=0,`MovementType`=2,`position_x`=-2539.584,`position_y`=7356.25,`position_z`=7.047175 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`,`emote`) VALUES (@NPC,@PATH,257,0, '', 233);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2539.584,7356.25,7.047175,0,0,0,0,100,0),
(@PATH,2,-2542.437,7364.194,7.077205,0,0,0,0,100,0),
(@PATH,3,-2541.9,7364.772,7.012752,0,45000,0,0,100,0),
(@PATH,4,-2539.584,7356.25,7.047175,0,0,0,0,100,0),
(@PATH,5,-2533.325,7352.424,9.283463,0,0,0,0,100,0),
(@PATH,6,-2530.663,7354.053,9.283456,0,60000,0,0,100,0);

DELETE FROM `creature_equip_template` WHERE `entry` IN (19012,17134);
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`,`VerifiedBuild`) VALUES 
(19012,1,5956,13611,0,18414),
(17134,1,3326,0,0,18414),
(17134,2,5292,0,0,18414),
(17134,3,5293,0,0,18414),
(17134,4,5300,0,0,18414),
(17134,5,5301,0,0,18414),
(17134,6,5491,0,0,18414),
(17134,7,17942,0,0,18414);

-- Pathing for Boulderfist Crusher Entry: 17134
SET @NPC := 60060;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2257.554,`position_y`=6220.683,`position_z`=44.19547 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2257.554,6220.683,44.19547,0,0,0,0,100,0),
(@PATH,2,-2269.54,6185.135,50.54529,0,0,0,0,100,0),
(@PATH,3,-2300.504,6160.397,57.35026,0,0,0,0,100,0),
(@PATH,4,-2333.537,6174.551,51.46076,0,0,0,0,100,0),
(@PATH,5,-2354.695,6165.477,54.33383,0,0,0,0,100,0),
(@PATH,6,-2353.252,6135.473,60.3641,0,0,0,0,100,0),
(@PATH,7,-2345.113,6126.771,60.89935,0,0,0,0,100,0),
(@PATH,8,-2353.252,6135.473,60.3641,0,0,0,0,100,0),
(@PATH,9,-2354.915,6165.381,54.32211,0,0,0,0,100,0),
(@PATH,10,-2333.537,6174.551,51.46076,0,0,0,0,100,0),
(@PATH,11,-2300.504,6160.397,57.35026,0,0,0,0,100,0),
(@PATH,12,-2269.54,6185.135,50.54529,0,0,0,0,100,0);

-- Pathing for Boulderfist Crusher Entry: 17134
SET @NPC := 60059;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2399.844,`position_y`=6147.982,`position_z`=71.06328 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2399.844,6147.982,71.06328,0,0,0,0,100,0),
(@PATH,2,-2432.956,6121.422,83.23274,0,0,0,0,100,0),
(@PATH,3,-2466.083,6121.511,88.61314,0,0,0,0,100,0),
(@PATH,4,-2481.856,6120.785,91.89808,0,0,0,0,100,0),
(@PATH,5,-2498.95,6129.08,92.34127,0,0,0,0,100,0),
(@PATH,6,-2509.331,6142.653,93.18784,0,0,0,0,100,0),
(@PATH,7,-2498.272,6119,92.22591,0,0,0,0,100,0),
(@PATH,8,-2478.536,6077.883,93.76772,0,0,0,0,100,0),
(@PATH,9,-2465.792,6100.151,92.3082,0,0,0,0,100,0),
(@PATH,10,-2448.861,6127.569,83.04636,0,0,0,0,100,0),
(@PATH,11,-2448.847,6140.451,77.72874,0,0,0,0,100,0),
(@PATH,12,-2474.902,6153.139,63.35086,0,0,0,0,100,0),
(@PATH,13,-2500.071,6186.787,60.56055,0,0,0,0,100,0),
(@PATH,14,-2533.038,6182.577,60.19934,0,0,0,0,100,0),
(@PATH,15,-2541.146,6187.5,60.79309,0,0,0,0,100,0),
(@PATH,16,-2500.569,6181.5,60.06873,0,0,0,0,100,0),
(@PATH,17,-2466.607,6169.582,58.25665,0,0,0,0,100,0),
(@PATH,18,-2447.577,6166.336,54.24046,0,0,0,0,100,0),
(@PATH,19,-2450.868,6199.792,31.97747,0,0,0,0,100,0),
(@PATH,20,-2470.541,6233.041,30.6633,0,0,0,0,100,0),
(@PATH,21,-2466.961,6261.01,31.04571,0,0,0,0,100,0),
(@PATH,22,-2499.331,6266.069,27.68829,0,0,0,0,100,0),
(@PATH,23,-2466.961,6261.01,31.04571,0,0,0,0,100,0),
(@PATH,24,-2470.675,6233.3,30.707,0,0,0,0,100,0),
(@PATH,25,-2450.868,6199.792,31.97747,0,0,0,0,100,0),
(@PATH,26,-2447.577,6166.336,54.24046,0,0,0,0,100,0),
(@PATH,27,-2466.316,6169.527,58.25665,0,0,0,0,100,0),
(@PATH,28,-2500.569,6181.5,60.06873,0,0,0,0,100,0),
(@PATH,29,-2541.146,6187.5,60.79309,0,0,0,0,100,0),
(@PATH,30,-2533.038,6182.577,60.19934,0,0,0,0,100,0),
(@PATH,31,-2500.071,6186.787,60.56055,0,0,0,0,100,0),
(@PATH,32,-2475.183,6153.281,63.52248,0,0,0,0,100,0),
(@PATH,33,-2449.129,6140.594,77.34264,0,0,0,0,100,0),
(@PATH,34,-2448.861,6127.569,83.04636,0,0,0,0,100,0),
(@PATH,35,-2465.792,6100.151,92.3082,0,0,0,0,100,0),
(@PATH,36,-2478.536,6077.883,93.76772,0,0,0,0,100,0),
(@PATH,37,-2498.272,6119,92.22591,0,0,0,0,100,0),
(@PATH,38,-2509.331,6142.653,93.18784,0,0,0,0,100,0),
(@PATH,39,-2498.95,6129.08,92.34127,0,0,0,0,100,0),
(@PATH,40,-2466.666,6121.875,88.72591,0,0,0,0,100,0),
(@PATH,41,-2432.956,6121.422,83.23274,0,0,0,0,100,0),
(@PATH,42,-2399.844,6147.982,71.06328,0,0,0,0,100,0),
(@PATH,43,-2367.009,6154.886,59.9362,0,0,0,0,100,0);

-- Pathing for Boulderfist Crusher Entry: 17134
SET @NPC := 60064;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2241.646,`position_y`=6073.002,`position_z`=73.11702 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2241.646,6073.002,73.11702,0,0,0,0,100,0),
(@PATH,2,-2251.782,6080.446,76.50385,0,0,0,0,100,0),
(@PATH,3,-2257.793,6097.254,77.32147,0,0,0,0,100,0),
(@PATH,4,-2269.76,6109.586,74.90349,0,0,0,0,100,0),
(@PATH,5,-2298.05,6128.994,63.42472,0,0,0,0,100,0),
(@PATH,6,-2269.76,6109.586,74.90349,0,0,0,0,100,0),
(@PATH,7,-2258.203,6097.282,77.32253,0,0,0,0,100,0),
(@PATH,8,-2251.782,6080.446,76.50385,0,0,0,0,100,0),
(@PATH,9,-2241.646,6073.002,73.11702,0,0,0,0,100,0),
(@PATH,10,-2219.986,6071.252,71.84301,0,0,0,0,100,0),
(@PATH,11,-2189.278,6094.729,72.98857,0,0,0,0,100,0),
(@PATH,12,-2207.289,6076.843,72.2662,0,0,0,0,100,0),
(@PATH,13,-2203.843,6069.921,72.09104,0,0,0,0,100,0),
(@PATH,14,-2215.665,6058.173,68.39651,0,0,0,0,100,0),
(@PATH,15,-2210.043,6046.705,67.68399,0,0,0,0,100,0),
(@PATH,16,-2199.021,6048.374,68.0714,0,0,0,0,100,0),
(@PATH,17,-2187.256,6042.542,67.49065,0,0,0,0,100,0),
(@PATH,18,-2185.898,6029.625,66.28046,0,0,0,0,100,0),
(@PATH,19,-2197.731,6020.948,66.3587,0,0,0,0,100,0),
(@PATH,20,-2216.761,6010.768,67.10131,0,0,0,0,100,0),
(@PATH,21,-2197.731,6020.948,66.3587,0,0,0,0,100,0),
(@PATH,22,-2185.898,6029.625,66.28046,0,0,0,0,100,0),
(@PATH,23,-2187.256,6042.542,67.49065,0,0,0,0,100,0),
(@PATH,24,-2199.021,6048.374,68.0714,0,0,0,0,100,0),
(@PATH,25,-2210.043,6046.705,67.68399,0,0,0,0,100,0),
(@PATH,26,-2215.665,6058.173,68.39651,0,0,0,0,100,0),
(@PATH,27,-2203.843,6069.921,72.09104,0,0,0,0,100,0),
(@PATH,28,-2207.289,6076.843,72.2662,0,0,0,0,100,0),
(@PATH,29,-2189.263,6094.723,72.98553,0,0,0,0,100,0),
(@PATH,30,-2219.709,6071.23,71.80058,0,0,0,0,100,0);

UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid` IN (60048,60049,60061,60089,60073);
UPDATE `creature` SET `position_x`=-2254.501,`position_y`=6228.208,`position_z`=43.00068,`orientation`=4.066617 WHERE `guid`=60070;
UPDATE `creature` SET `position_x`=-2258.156,`position_y`=6223.644,`position_z`=43.70845,`orientation`=0.8377581 WHERE `guid`=60071;
UPDATE `creature` SET `id`=17135,`position_x`=-2353.576,`position_y`=6196.409,`position_z`=49.09693,`orientation`=0 WHERE `guid`=60069;

-- Boulderfist Crusher SAI
SET @ENTRY := 17134;
UPDATE `creature` SET `equipment_id`=-1 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,12000,12000,11,2676,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Crusher - In Combat - Cast 'Pulverize'");

-- Boulderfist Mystic SAI
SET @ENTRY := 17135;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,8000,4000,8000,5,1,0,0,0,0,0,9,17135,4,7,0,0,0,0,"Boulderfist Mystic - Out of Combat - Emote talk"),
(@ENTRY,0,1,0,0,0,100,0,6000,6000,8000,12000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Mystic - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,12000,16000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Mystic - In Combat - Cast 'Earth Shock'"),
(@ENTRY,0,3,0,2,0,100,0,0,49,22000,22000,11,11431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Mystic - Hp below 50 - Cast 'Healing Touch'");
