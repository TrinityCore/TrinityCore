-- 
UPDATE `gossip_menu_option` SET `action_menu_id`=9753 WHERE `menu_id`=9754;

-- Pathing for Death Knight Cavalier Entry: 16163 'TDB FORMAT' 
SET @NPC := 127753;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2926.023,`position_y`=-3200.403,`position_z`=273.3712 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,25278,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2926.023,-3200.403,273.3712,0,0,0,0,100,0),
(@PATH,2,2931.457,-3188.328,273.3712,0,0,0,0,100,0),
(@PATH,3,2925.778,-3167.298,273.787,0,0,0,0,100,0),
(@PATH,4,2907.542,-3166.655,273.787,0,0,0,0,100,0),
(@PATH,5,2873.219,-3165.419,273.787,0,0,0,0,100,0),
(@PATH,6,2861.632,-3165.088,273.787,0,0,0,0,100,0),
(@PATH,7,2860.526,-3185.717,273.787,0,0,0,0,100,0),
(@PATH,8,2860.435,-3203.401,273.787,0,0,0,0,100,0),
(@PATH,9,2875.204,-3203.906,273.4088,0,0,0,0,100,0),
(@PATH,10,2892.834,-3204.38,273.3965,0,0,0,0,100,0),
(@PATH,11,2911.993,-3204.611,273.3846,0,0,0,0,100,0);

DELETE FROM `creature_template_addon` WHERE `entry` =16400;

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127631;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3223.018,`position_y`=-3218.725,`position_z`=316.3705 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3223.018,-3218.725,316.3705,0,0,0,0,100,0),
(@PATH,2,3230.179,-3211.59,316.5933,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127632;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3208.167,`position_y`=-3234.595,`position_z`=315.4565 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3208.167,-3234.595,315.4565,0,0,0,0,100,0),
(@PATH,2,3200.392,-3242.829,315.141,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127633;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3178.613,`position_y`=-3263.671,`position_z`=316.4281 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3178.613,-3263.671,316.4281,0,0,0,0,100,0),
(@PATH,2,3174.119,-3267.95,316.7845,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127634;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3217.316,`position_y`=-3224.753,`position_z`=316.0583 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3217.316,-3224.753,316.0583,0,0,0,0,100,0),
(@PATH,2,3209.847,-3232.841,315.5579,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127635;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3190.628,`position_y`=-3252.565,`position_z`=315.5675 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3190.628,-3252.565,315.5675,0,0,0,0,100,0),
(@PATH,2,3196.852,-3246.524,315.0298,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127636;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3244.748,`position_y`=-3198.743,`position_z`=317.3646 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3244.748,-3198.743,317.3646,0,0,0,0,100,0),
(@PATH,2,3236.25,-3205.753,316.6993,0,0,0,0,100,0);

-- Pathing for Toxic Tunnel Entry: 16400 'TDB FORMAT' 
SET @NPC := 127637;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3246.763,`position_y`=-3193.856,`position_z`=317.3302 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '28370');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3246.763,-3193.856,317.3302,0,0,0,0,100,0),
(@PATH,2,3252.532,-3188.566,318.1087,0,0,0,0,100,0);

-- Pathing for Stitched Colossus Entry: 30071 'TDB FORMAT' 
SET @NPC := 128058;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3454.427,`position_y`=-3187.954,`position_z`=294.6607 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3454.427,-3187.954,294.6607,0,0,0,0,100,0),
(@PATH,2,3453.837,-3215.978,284.005,0,0,0,0,100,0),
(@PATH,3,3453.848,-3237.722,272.597,0,0,0,0,100,0),
(@PATH,4,3453.705,-3262.583,267.5943,0,0,0,0,100,0),
(@PATH,5,3453.507,-3285.881,267.5923,0,0,0,0,100,0),
(@PATH,6,3450.008,-3299.009,267.593,0,0,0,0,100,0),
(@PATH,7,3434.539,-3314.597,267.592,0,0,0,0,100,0),
(@PATH,8,3423.135,-3338.302,267.593,0,0,0,0,100,0),
(@PATH,9,3430.531,-3358.816,267.592,0,0,0,0,100,0),
(@PATH,10,3450.598,-3369.066,267.5927,0,0,0,0,100,0),
(@PATH,11,3472.296,-3362.288,267.5991,0,0,0,0,100,0),
(@PATH,12,3483.6,-3341.974,267.5938,0,0,0,0,100,0),
(@PATH,13,3477.419,-3326.692,267.5933,0,0,0,0,100,0),
(@PATH,14,3466.747,-3312.542,267.5925,0,0,0,0,100,0),
(@PATH,15,3455.716,-3299.394,267.5929,0,0,0,0,100,0),
(@PATH,16,3453.988,-3285.853,267.5922,0,0,0,0,100,0),
(@PATH,17,3454.239,-3262.38,267.5943,0,0,0,0,100,0),
(@PATH,18,3454.453,-3237.651,272.6341,0,0,0,0,100,0),
(@PATH,19,3454.135,-3215.837,284.079,0,0,0,0,100,0);

-- Pathing for Stitched Colossus Entry: 30071 'TDB FORMAT' 
SET @NPC := 128057;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3331.301,`position_y`=-3008.488,`position_z`=294.6606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3331.301,-3008.488,294.6606,0,0,0,0,100,0),
(@PATH,2,3352.705,-3027.659,294.6606,0,0,0,0,100,0),
(@PATH,3,3378.292,-3052.875,294.6657,0,0,0,0,100,0),
(@PATH,4,3400.806,-3075.215,294.6628,0,0,0,0,100,0),
(@PATH,5,3420.535,-3095.16,294.6607,0,0,0,0,100,0),
(@PATH,6,3423.608,-3104.254,294.6607,0,0,0,0,100,0),
(@PATH,7,3424.381,-3122.999,294.6599,0,0,0,0,100,0),
(@PATH,8,3428.679,-3145.677,294.659,0,0,0,0,100,0),
(@PATH,9,3444.718,-3157.384,294.6608,0,0,0,0,100,0),
(@PATH,10,3466.77,-3155.3,294.6603,0,0,0,0,100,0),
(@PATH,11,3481.494,-3139.173,294.6597,0,0,0,0,100,0),
(@PATH,12,3480.309,-3114.887,294.6596,0,0,0,0,100,0),
(@PATH,13,3467.193,-3102.655,294.6595,0,0,0,0,100,0),
(@PATH,14,3448.526,-3099.575,294.6612,0,0,0,0,100,0),
(@PATH,15,3428.409,-3099.175,294.6607,0,0,0,0,100,0),
(@PATH,16,3420.901,-3094.735,294.6607,0,0,0,0,100,0),
(@PATH,17,3401.064,-3074.813,294.6629,0,0,0,0,100,0),
(@PATH,18,3378.616,-3052.372,294.6658,0,0,0,0,100,0),
(@PATH,19,3352.98,-3027.292,294.6606,0,0,0,0,100,0),
(@PATH,20,3331.301,-3008.488,294.6606,0,0,0,0,100,0),
(@PATH,21,3311.187,-2990.615,294.6598,0,0,0,0,100,0),
(@PATH,22,3311.187,-2990.615,294.6598,2.505866,0,0,0,100,0),
(@PATH,23,3311.187,-2990.615,294.6598,2.251878,0,0,0,100,0),
(@PATH,24,3311.187,-2990.615,294.6598,3.254467,0,0,0,100,0),
(@PATH,25,3311.187,-2990.615,294.6598,5.113917,0,0,0,100,0);

-- Pathing for Stitched Colossus Entry: 30071 'TDB FORMAT' 
SET @NPC := 128056;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3425.885,`position_y`=-3100.784,`position_z`=294.6607 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3425.885,-3100.784,294.6607,0,0,0,0,100,0),
(@PATH,2,3400.279,-3075.093,294.6628,0,0,0,0,100,0),
(@PATH,3,3373.177,-3047.739,294.6664,0,0,0,0,100,0),
(@PATH,4,3344.838,-3019.543,294.6606,0,0,0,0,100,0),
(@PATH,5,3341.914,-3012.742,294.6606,0,0,0,0,100,0),
(@PATH,6,3339.663,-2995.398,294.6601,0,0,0,0,100,0),
(@PATH,7,3337.08,-2977.52,294.6604,0,0,0,0,100,0),
(@PATH,8,3323.939,-2963.499,294.6603,0,0,0,0,100,0),
(@PATH,9,3299.76,-2962.284,294.6606,0,0,0,0,100,0),
(@PATH,10,3286.439,-2972.35,294.6593,0,0,0,0,100,0),
(@PATH,11,3280.707,-2995.567,294.6606,0,0,0,0,100,0),
(@PATH,12,3288.473,-3011.645,294.6597,0,0,0,0,100,0),
(@PATH,13,3307.809,-3020.176,294.659,0,0,0,0,100,0),
(@PATH,14,3325.226,-3018.351,294.6606,0,0,0,0,100,0),
(@PATH,15,3338.513,-3016.632,294.6606,0,0,0,0,100,0),
(@PATH,16,3344.342,-3020.255,294.6606,0,0,0,0,100,0),
(@PATH,17,3372.666,-3048.441,294.6662,0,0,0,0,100,0),
(@PATH,18,3399.818,-3075.62,294.6627,0,0,0,0,100,0),
(@PATH,19,3425.406,-3101.135,294.6607,0,0,0,0,100,0),
(@PATH,20,3451.888,-3127.903,294.6607,0,0,0,0,100,0),
(@PATH,21,3451.888,-3127.903,294.6607,1.541391,0,0,0,100,0),
(@PATH,22,3456.634,-3133.219,294.6606,0,0,0,0,100,0),
(@PATH,23,3455.112,-3131.514,294.6606,6.06443,0,0,0,100,0),
(@PATH,24,3455.112,-3131.514,294.6606,4.858006,0,0,0,100,0),
(@PATH,25,3455.112,-3131.514,294.6606,2.345938,0,0,0,100,0);

-- Pathing for Stitched Colossus Entry: 30071 'TDB FORMAT' 
SET @NPC := 128054;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3250.639,`position_y`=-2986.463,`position_z`=294.6606 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3250.639,-2986.463,294.6606,0,0,0,0,100,0),
(@PATH,2,3218.217,-2985.765,281.2667,0,0,0,0,100,0),
(@PATH,3,3198.772,-2985.637,271.0636,0,0,0,0,100,0),
(@PATH,4,3178.061,-2985.433,267.5943,0,0,0,0,100,0),
(@PATH,5,3159.365,-2985.343,267.5929,0,0,0,0,100,0),
(@PATH,6,3139.7,-2981.853,267.5929,0,0,0,0,100,0),
(@PATH,7,3126.553,-2971.708,267.5919,0,0,0,0,100,0),
(@PATH,8,3114.558,-2959.215,267.5926,0,0,0,0,100,0),
(@PATH,9,3095.302,-2956.31,267.5921,0,0,0,0,100,0),
(@PATH,10,3078.464,-2964.795,267.5918,0,0,0,0,100,0),
(@PATH,11,3070.598,-2982.696,267.5929,0,0,0,0,100,0),
(@PATH,12,3076.846,-3004.052,267.592,0,0,0,0,100,0),
(@PATH,13,3096.726,-3015.381,267.5934,0,0,0,0,100,0),
(@PATH,14,3115.124,-3011.505,267.5921,0,0,0,0,100,0),
(@PATH,15,3127.605,-2998.091,267.5924,0,0,0,0,100,0),
(@PATH,16,3139.447,-2989.035,267.5929,0,0,0,0,100,0),
(@PATH,17,3159.26,-2985.907,267.5929,0,0,0,0,100,0),
(@PATH,18,3178.106,-2985.838,267.5943,0,0,0,0,100,0),
(@PATH,19,3198.909,-2986.179,271.1352,0,0,0,0,100,0),
(@PATH,20,3218.02,-2986.236,281.1633,0,0,0,0,100,0);

-- Pathing for Shade of Naxxramas Entry: 16164 'TDB FORMAT' 
SET @NPC := 127755;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2915.294,`position_y`=-3343.234,`position_z`=298.1457 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2915.294,-3343.234,298.1457,0,0,0,0,100,0),
(@PATH,2,2898.639,-3327.008,298.1457,0,0,0,0,100,0),
(@PATH,3,2915.294,-3343.234,298.1457,0,0,0,0,100,0),
(@PATH,4,2898.639,-3327.008,298.1457,0,0,0,0,100,0),
(@PATH,5,2915.294,-3343.234,298.1457,0,0,0,0,100,0),
(@PATH,6,2898.639,-3327.008,298.1457,0,0,0,0,100,0);

-- Sludge Belcher SAI On Reset - Cast Disease Cloud was set to OOC
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=16029 AND `source_type`=0 AND `id`=0;
-- These npc's should not be moving
UPDATE creature SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (128070,128071,128072,128073,128074,128067,130957);
