-- Urdak SAI
SET @ENTRY := 18541;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Out of Combat - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,1,0,0,0,0,11,32924,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Power of Kran'aish' (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - On Aggro - Cast 'Lightning Bolt' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - On Aggro - Increment Phase By 1 (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,38465,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - Within 0-40 Range - Cast 'Lightning Bolt' (No Repeat)"),
(@ENTRY,0,5,6,3,1,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Mana - Increment Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 35-80 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 5-15 Range - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Within 0-5 Range - Enable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,10,0,3,2,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 30-100% Mana - Decrement Phase By 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,11,0,0,0,100,0,6000,10000,12000,16000,11,32907,1,0,0,0,0,2,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Arakkoa Blast' (Phase 1) (No Repeat)"),
(@ENTRY,0,12,0,0,0,100,0,10000,14000,18000,25000,11,6728,1,0,0,0,0,6,0,0,0,0,0,0,0,"Urdak - In Combat - Cast 'Enveloping Winds' (Phase 1) (No Repeat)"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Set Event Phase 3 (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Enable Combat Movement (No Repeat)"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Urdak - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Pathing for Urdak Entry: 18541 'TDB FORMAT' 
SET @NPC := 66701;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2531.757,`position_y`=5367.723,`position_z`=27.48038 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2531.757,5367.723,27.48038,0,0,0,0,100,0),
(@PATH,2,-2522.244,5363.866,27.5043,0,0,0,0,100,0),
(@PATH,3,-2511.568,5370.136,27.19551,0,0,0,0,100,0),
(@PATH,4,-2509.842,5376.426,27.17996,0,0,0,0,100,0),
(@PATH,5,-2514.843,5388.665,27.42471,0,0,0,0,100,0),
(@PATH,6,-2525.896,5389.706,27.21724,0,0,0,0,100,0),
(@PATH,7,-2531.956,5386.355,27.44649,0,0,0,0,100,0),
(@PATH,8,-2535.825,5377.078,27.48491,0,0,0,0,100,0);
-- 0x1C39304240121B400000D00000395D5F .go -2531.757 5367.723 27.48038

DELETE FROM `creature_formations` WHERE `leaderGUID`=66960;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(66960, 66960, 0, 0, 2),
(66960, 57334, 3, 270, 2);

-- Pathing for Shadowy Hunter Entry: 18718 'TDB FORMAT' 
SET @NPC := 66960;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2399.251,`position_y`=4948.647,`position_z`=33.51818 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2399.251,4948.647,33.51818,0,0,0,0,100,0),
(@PATH,2,-2382.013,4957.111,36.26661,0,0,0,0,100,0),
(@PATH,3,-2386.387,4964.082,33.5477,0,0,0,0,100,0),
(@PATH,4,-2396.421,4967.332,32.63216,0,0,0,0,100,0),
(@PATH,5,-2404.207,4968.344,32.13279,0,0,0,0,100,0),
(@PATH,6,-2411.476,4973.782,31.9511,0,0,0,0,100,0),
(@PATH,7,-2419.75,5004.045,29.51139,0,0,0,0,100,0),
(@PATH,8,-2423.043,5009.497,29.88427,0,0,0,0,100,0),
(@PATH,9,-2425.305,5012.542,29.87346,0,0,0,0,100,0),
(@PATH,10,-2452.268,5014.185,28.21556,0,0,0,0,100,0),
(@PATH,11,-2455.99,5026.977,25.38416,0,0,0,0,100,0),
(@PATH,12,-2461.66,5046.541,20.78516,0,0,0,0,100,0),
(@PATH,13,-2468.601,5062.008,17.91999,0,0,0,0,100,0),
(@PATH,14,-2471.484,5074.755,15.08363,0,0,0,0,100,0),
(@PATH,15,-2462.648,5034.314,23.94722,0,0,0,0,100,0),
(@PATH,16,-2458.38,5013.544,27.85468,0,0,0,0,100,0),
(@PATH,17,-2460.833,5004.856,28.65945,0,0,0,0,100,0),
(@PATH,18,-2468.316,4978.999,31.72539,0,0,0,0,100,0),
(@PATH,19,-2469.694,4960.631,33.31852,0,0,0,0,100,0),
(@PATH,20,-2466.243,4944.808,34.89827,0,0,0,0,100,0),
(@PATH,21,-2466.676,4930.218,36.72472,0,0,0,0,100,0),
(@PATH,22,-2473.81,4922.928,38.69386,0,0,0,0,100,0),
(@PATH,23,-2476.339,4921.196,39.03951,0,0,0,0,100,0),
(@PATH,24,-2486.696,4911.087,38.99028,0,0,0,0,100,0),
(@PATH,25,-2488.085,4899.312,39.16518,0,0,0,0,100,0),
(@PATH,26,-2466.59,4887.837,36.24532,0,0,0,0,100,0),
(@PATH,27,-2459.039,4893.131,34.30416,0,0,0,0,100,0),
(@PATH,28,-2456.6,4895.325,33.89172,0,0,0,0,100,0),
(@PATH,29,-2455.763,4912.572,33.6131,0,0,0,0,100,0),
(@PATH,30,-2459.973,4922.549,33.84817,0,0,0,0,100,0),
(@PATH,31,-2454.409,4941.216,34.89568,0,0,0,0,100,0),
(@PATH,32,-2453.032,4942.258,34.88249,0,0,0,0,100,0),
(@PATH,33,-2441.288,4944.204,34.91498,0,0,0,0,100,0),
(@PATH,34,-2424.706,4957.187,34.11639,0,0,0,0,100,0),
(@PATH,35,-2420.334,4960.088,33.7532,0,0,0,0,100,0),
(@PATH,36,-2399.827,4949.04,33.55933,0,0,0,0,100,0);
-- 0x1C393042401247800000D80000395139 .go -2399.251 4948.647 33.51818

DELETE FROM `creature_formations` WHERE `leaderGUID`=66959;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(66959, 66959, 0, 0, 2),
(66959, 57324, 3, 270, 2);

-- Pathing for Shadowy Hunter Entry: 18718 'TDB FORMAT' 
SET @NPC := 66959;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2458.59,`position_y`=4883.933,`position_z`=34.63649 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2458.59,4883.933,34.63649,0,0,0,0,100,0),
(@PATH,2,-2454.139,4881.942,34.18031,0,0,0,0,100,0),
(@PATH,3,-2441.338,4867.939,34.96668,0,0,0,0,100,0),
(@PATH,4,-2447.259,4881.18,33.54724,0,0,0,0,100,0),
(@PATH,5,-2454.204,4888.805,33.82166,0,0,0,0,100,0),
(@PATH,6,-2455.784,4897.667,33.77719,0,0,0,0,100,0),
(@PATH,7,-2455.145,4910.682,33.57897,0,0,0,0,100,0),
(@PATH,8,-2459.188,4921.684,33.73078,0,0,0,0,100,0),
(@PATH,9,-2455.591,4939.817,34.61909,0,0,0,0,100,0),
(@PATH,10,-2453.116,4941.684,35.0243,0,0,0,0,100,0),
(@PATH,11,-2443.437,4943.616,34.76263,0,0,0,0,100,0),
(@PATH,12,-2431.095,4940.732,36.18304,0,0,0,0,100,0),
(@PATH,13,-2422.104,4931.316,35.36322,0,0,0,0,100,0),
(@PATH,14,-2418.187,4924.916,36.3769,0,0,0,0,100,0),
(@PATH,15,-2425.994,4937.722,36.55001,0,0,0,0,100,0),
(@PATH,16,-2430.061,4945.802,35.26893,0,0,0,0,100,0),
(@PATH,17,-2429.3,4947.917,34.86908,0,0,0,0,100,0),
(@PATH,18,-2424.078,4963.271,33.09982,0,0,0,0,100,0),
(@PATH,19,-2421.393,4974.704,31.43381,0,0,0,0,100,0),
(@PATH,20,-2421.332,4975.644,31.21901,0,0,0,0,100,0),
(@PATH,21,-2418.137,5000.565,30.00104,0,0,0,0,100,0),
(@PATH,22,-2417.527,5002.019,29.37036,0,0,0,0,100,0),
(@PATH,23,-2416.402,5010.205,29.2325,0,0,0,0,100,0),
(@PATH,24,-2417.669,5014.722,28.97691,0,0,0,0,100,0),
(@PATH,25,-2428.226,5012.224,29.9898,0,0,0,0,100,0),
(@PATH,26,-2444.966,5008.044,29.51899,0,0,0,0,100,0),
(@PATH,27,-2453.993,5013.485,28.19345,0,0,0,0,100,0),
(@PATH,28,-2456.664,5023.554,26.07574,0,0,0,0,100,0),
(@PATH,29,-2459.761,5038.568,22.79576,0,0,0,0,100,0),
(@PATH,30,-2465.731,5053.402,19.17121,0,0,0,0,100,0),
(@PATH,31,-2467.348,5032.213,24.09672,0,0,0,0,100,0),
(@PATH,32,-2467.405,5023.126,25.73068,0,0,0,0,100,0),
(@PATH,33,-2467.814,5012.714,28.07976,0,0,0,0,100,0),
(@PATH,34,-2470.525,4997.041,29.28029,0,0,0,0,100,0),
(@PATH,35,-2471.126,4980.461,31.38793,0,0,0,0,100,0),
(@PATH,36,-2477.811,4974.808,32.3695,0,0,0,0,100,0),
(@PATH,37,-2497.777,4966.848,35.28411,0,0,0,0,100,0),
(@PATH,38,-2506.064,4953.317,38.70324,0,0,0,0,100,0),
(@PATH,39,-2510.001,4942.142,39.95487,0,0,0,0,100,0),
(@PATH,40,-2510.834,4938.938,40.30884,0,0,0,0,100,0),
(@PATH,41,-2510.035,4921.547,39.56293,0,0,0,0,100,0),
(@PATH,42,-2510.577,4918.453,39.31087,0,0,0,0,100,0),
(@PATH,43,-2507.691,4905.567,39.31522,0,0,0,0,100,0),
(@PATH,44,-2500.221,4899.546,39.09933,0,0,0,0,100,0),
(@PATH,45,-2490.795,4896.659,39.47167,0,0,0,0,100,0);
-- 0x1C393042401247800000D800003955BB .go -2458.59 4883.933 34.63649

-- Remove 1 too many 'Shadowy Executioner'
DELETE FROM `creature` WHERE `guid`=57323;
