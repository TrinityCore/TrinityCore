-- Drak'Tharon Keep

-- Pathing for Drakkari Guardian Entry: 26620
SET @NPC := 127582;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-342.092,`position_y`=-597.7366,`position_z`=72.60764 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-348.2738,-595.0352,72.60789,0,0,0,100,0),
(@PATH,2,-351.4645,-591.2532,72.60825,0,0,0,100,0),
(@PATH,3,-348.2738,-595.0352,72.60789,0,0,0,100,0),
(@PATH,4,-342.092,-597.7366,72.60764,0,0,0,100,0),
(@PATH,5,-337.3541,-596.457,72.60776,0,0,0,100,0),
(@PATH,6,-332.8021,-593.3668,72.60805,0,0,0,100,0),
(@PATH,7,-330.1274,-590.215,72.60835,0,0,0,100,0),
(@PATH,8,-332.8021,-593.3668,72.60805,0,0,0,100,0),
(@PATH,9,-337.3541,-596.457,72.60776,0,0,0,100,0),
(@PATH,10,-342.092,-597.7366,72.60764,0,0,0,100,0);

-- Remove Drakkari Guardian overspawn
DELETE FROM `creature` WHERE `guid` IN (127581);
DELETE FROM `creature_addon` WHERE `guid` IN (127581);

-- Pathing for Drakkari Bat Entry: 26622
SET @NPC := 127614;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-392.2272,`position_y`=-677.325,`position_z`=26.64196 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-386.9386,-680.3297,28.5735,0,0,0,100,0),
(@PATH,2,-381.2936,-675.7957,28.5735,0,0,0,100,0),
(@PATH,3,-378.735,-666.9066,28.57349,0,0,0,100,0),
(@PATH,4,-386.3628,-662.0511,28.57349,0,0,0,100,0),
(@PATH,5,-392.4187,-664.8582,26.64148,0,0,0,100,0),
(@PATH,6,-395.6666,-671.3341,26.64142,0,0,0,100,0),
(@PATH,7,-392.2272,-677.325,26.64196,0,0,0,100,0);

-- Pathing for Drakkari Bat Entry: 26622
SET @NPC := 127613;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-420.6025,`position_y`=-665.9139,`position_z`=27.26924 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-409.9266,-669.2863,26.64212,0,0,0,100,0),
(@PATH,2,-404.8366,-663.6207,26.64172,0,0,0,100,0),
(@PATH,3,-404.446,-655.531,26.64191,0,0,0,100,0),
(@PATH,4,-411.499,-652.1765,28.57349,0,0,0,100,0),
(@PATH,5,-416.9508,-653.751,28.5738,0,0,0,100,0),
(@PATH,6,-421.7345,-661.5891,28.57359,0,0,0,100,0),
(@PATH,7,-420.6025,-665.9139,27.26924,0,0,0,100,0);

-- Pathing for Drakkari Bat Entry: 26622
SET @NPC := 127615;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-416.4136,`position_y`=-662.1977,`position_z`=26.64302 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-423.1144,-663.6149,28.57369,0,0,0,100,0),
(@PATH,2,-428.976,-668.0037,28.5738,0,0,0,100,0),
(@PATH,3,-428.1159,-675.8496,28.5735,0,0,0,100,0),
(@PATH,4,-420.3534,-679.633,27.94913,0,0,0,100,0),
(@PATH,5,-412.9664,-675.6168,26.64376,0,0,0,100,0),
(@PATH,6,-412.3599,-668.2842,26.64241,0,0,0,100,0),
(@PATH,7,-416.4136,-662.1977,26.64302,0,0,0,100,0);

-- Pathing for Drakkari Bat Entry: 26622
SET @NPC := 127612;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-406.5539,`position_y`=-695.0261,`position_z`=28.57405 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-399.3579,-694.1252,28.5735,0,0,0,100,0),
(@PATH,2,-392.8559,-687.9329,28.57349,0,0,0,100,0),
(@PATH,3,-395.3493,-679.3206,26.64168,0,0,0,100,0),
(@PATH,4,-404.5995,-676.0878,26.63831,0,0,0,100,0),
(@PATH,5,-411.1477,-682.6027,26.64155,0,0,0,100,0),
(@PATH,6,-410.6699,-690.0704,28.57438,0,0,0,100,0),
(@PATH,7,-406.5539,-695.0261,28.57405,0,0,0,100,0);

-- Pathing for Scourge Reanimator Entry: 26626
SET @NPC := 127412;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-410.9426,`position_y`=-603.3857,`position_z`=1.024866 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-404.537,-602.8129,1.024867,0,0,0,100,0),
(@PATH,2,-398.1429,-604.8417,1.02487,0,0,0,100,0),
(@PATH,3,-404.537,-602.8129,1.024867,0,0,0,100,0),
(@PATH,4,-410.9426,-603.3857,1.024866,0,0,0,100,0),
(@PATH,5,-416.6559,-600.7515,1.024868,0,0,0,100,0),
(@PATH,6,-424.4983,-599.7261,1.024869,0,0,0,100,0),
(@PATH,7,-416.6559,-600.7515,1.024868,0,0,0,100,0),
(@PATH,8,-410.9426,-603.3857,1.024866,0,0,0,100,0);

-- Pathing for Scourge Reanimator Entry: 26626
SET @NPC := 127411;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-494.1194,`position_y`=-603.9778,`position_z`=2.072221 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-486.8281,-601.2296,1.144565,0,0,0,100,0),
(@PATH,2,-481.1871,-599.9684,1.024871,0,0,0,100,0),
(@PATH,3,-475.4717,-602.4325,1.820062,0,0,0,100,0),
(@PATH,4,-469.6367,-604.8362,1.044375,0,0,0,100,0),
(@PATH,5,-462.5545,-605.178,1.018675,0,0,0,100,0),
(@PATH,6,-469.5573,-604.8443,1.042719,0,0,0,100,0),
(@PATH,7,-475.4717,-602.4325,1.820062,0,0,0,100,0),
(@PATH,8,-481.1871,-599.9684,1.024871,0,0,0,100,0),
(@PATH,9,-486.8281,-601.2296,1.144565,0,0,0,100,0),
(@PATH,10,-494.1194,-603.9778,2.072221,0,0,0,100,0);

-- Remove Scourge Reanimator overspawn
DELETE FROM `creature` WHERE `guid` IN (127450);
DELETE FROM `creature_addon` WHERE `guid` IN (127450);

-- Pathing for Drakkari Gutripper Entry: 26641
SET @NPC := 127456;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-483.0405,`position_y`=-649.0012,`position_z`=28.58858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-486.0568,-648.8849,28.58832,0,0,0,100,0),
(@PATH,2,-483.0405,-649.0012,28.58858,0,0,0,100,0),
(@PATH,3,-480.0255,-649.1176,28.58883,0,0,0,100,0),
(@PATH,4,-477.0105,-649.2339,28.58909,0,0,0,100,0),
(@PATH,5,-474.0007,-649.3502,28.59028,0,0,0,100,0),
(@PATH,6,-470.9918,-649.4663,28.59031,0,0,0,100,0),
(@PATH,7,-467.9779,-649.5826,28.59035,0,0,0,100,0),
(@PATH,8,-464.9656,-649.6989,28.55288,0,0,0,100,0),
(@PATH,9,-461.9586,-649.815,28.50968,0,0,0,100,0),
(@PATH,10,-460.1104,-649.8864,28.4215,0,0,0,100,0),
(@PATH,11,-464.2306,-649.7274,28.54232,0,0,0,100,0),
(@PATH,12,-467.2433,-649.611,28.59036,0,0,0,100,0),
(@PATH,13,-470.2549,-649.4948,28.59032,0,0,0,100,0),
(@PATH,14,-473.2637,-649.3786,28.59029,0,0,0,100,0),
(@PATH,15,-476.2737,-649.2624,28.58915,0,0,0,100,0),
(@PATH,16,-479.2837,-649.1462,28.5889,0,0,0,100,0),
(@PATH,17,-483.0405,-649.0012,28.58858,0,0,0,100,0);

-- Pathing for Drakkari Gutripper Entry: 26641
SET @NPC := 127457;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-483.2729,`position_y`=-654.9966,`position_z`=28.59017 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-486.2876,-654.8802,28.58992,0,0,0,100,0),
(@PATH,2,-483.2729,-654.9966,28.59017,0,0,0,100,0),
(@PATH,3,-480.2569,-655.113,28.59199,0,0,0,100,0),
(@PATH,4,-477.2439,-655.2294,28.59203,0,0,0,100,0),
(@PATH,5,-474.2319,-655.3456,28.59206,0,0,0,100,0),
(@PATH,6,-471.2233,-655.4618,28.5921,0,0,0,100,0),
(@PATH,7,-468.2094,-655.5781,28.59213,0,0,0,100,0),
(@PATH,8,-465.1971,-655.6944,28.55799,0,0,0,100,0),
(@PATH,9,-462.19,-655.8105,28.51479,0,0,0,100,0),
(@PATH,10,-460.3419,-655.8818,28.48824,0,0,0,100,0),
(@PATH,11,-464.463,-655.7228,28.54745,0,0,0,100,0),
(@PATH,12,-467.4753,-655.6064,28.59214,0,0,0,100,0),
(@PATH,13,-470.4877,-655.4902,28.59211,0,0,0,100,0),
(@PATH,14,-473.4938,-655.3741,28.59207,0,0,0,100,0),
(@PATH,15,-476.5032,-655.2579,28.59204,0,0,0,100,0),
(@PATH,16,-479.5138,-655.1417,28.592,0,0,0,100,0),
(@PATH,17,-483.2729,-654.9966,28.59017,0,0,0,100,0);

-- Pathing for Darkweb Hatchling Entry: 26674
SET @NPC := 127472;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-283.7295,`position_y`=-731.8323,`position_z`=27.29189 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-270.1169,-730.9915,27.30806,0,0,0,100,0),
(@PATH,2,-266.1129,-727.931,27.30861,0,0,0,100,0),
(@PATH,3,-265.3598,-715.4077,27.29189,0,0,0,100,0),
(@PATH,4,-274.9025,-707.4509,27.29512,0,0,0,100,0),
(@PATH,5,-282.5379,-706.8624,27.29189,0,0,0,100,0),
(@PATH,6,-287.1734,-717.2089,27.72341,0,0,0,100,0),
(@PATH,7,-290.9054,-722.8333,27.29189,0,0,0,100,0),
(@PATH,8,-283.7295,-731.8323,27.29189,0,0,0,100,0);

-- Pathing for Darkweb Hatchling Entry: 26674
SET @NPC := 127473;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-286.7308,`position_y`=-721.9674,`position_z`=27.29189 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-288.534,-727.5106,27.29189,0,0,0,100,0),
(@PATH,2,-280.5279,-726.8649,27.29189,0,0,0,100,0),
(@PATH,3,-270.6854,-727.6488,27.29941,0,0,0,100,0),
(@PATH,4,-270.441,-721.2595,27.29189,0,0,0,100,0),
(@PATH,5,-270.4362,-712.4268,27.29189,0,0,0,100,0),
(@PATH,6,-278.0521,-710.217,27.29605,0,0,0,100,0),
(@PATH,7,-285.8037,-712.8212,27.29603,0,0,0,100,0),
(@PATH,8,-286.7308,-721.9674,27.29189,0,0,0,100,0);

-- Pathing for Darkweb Hatchling Entry: 26674
SET @NPC := 127474;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-249.4208,`position_y`=-717.0651,`position_z`=27.61007 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-259.6944,-717.1452,26.8645,0,0,0,100,0),
(@PATH,2,-265.6481,-718.8099,27.29189,0,0,0,100,0),
(@PATH,3,-264.446,-725.0237,27.30534,0,0,0,100,0),
(@PATH,4,-256.6581,-724.9134,27.43577,0,0,0,100,0),
(@PATH,5,-246.0695,-725.6784,27.36535,0,0,0,100,0),
(@PATH,6,-245.0813,-719.5449,27.53182,0,0,0,100,0),
(@PATH,7,-249.4208,-717.0651,27.61007,0,0,0,100,0);

-- Pathing for Darkweb Hatchling Entry: 26674
SET @NPC := 127475;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-242.1334,`position_y`=-720.1142,`position_z`=27.43355 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-250.4899,-714.759,27.3011,0,0,0,100,0),
(@PATH,2,-266.1705,-713.7017,27.06336,0,0,0,100,0),
(@PATH,3,-270.4176,-721.0847,27.29189,0,0,0,100,0),
(@PATH,4,-266.1248,-728.0099,27.30877,0,0,0,100,0),
(@PATH,5,-253.1003,-728.3563,27.41331,0,0,0,100,0),
(@PATH,6,-244.1609,-728.7698,27.33719,0,0,0,100,0),
(@PATH,7,-242.1334,-720.1142,27.43355,0,0,0,100,0);

-- Pathing for Risen Drakkari Death Knight Entry: 26830
SET @NPC := 127553;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-390.7345,`position_y`=-608.2701,`position_z`=72.60735 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-402.9046,-608.7485,72.6084,0,0,0,100,0),
(@PATH,2,-414.1785,-608.5219,72.60596,0,0,0,100,0),
(@PATH,3,-423.621,-608.1632,72.60622,0,0,0,100,0),
(@PATH,4,-414.1785,-608.5219,72.60596,0,0,0,100,0),
(@PATH,5,-402.9046,-608.7485,72.6084,0,0,0,100,0),
(@PATH,6,-390.7345,-608.2701,72.60735,0,0,0,100,0);

-- Pathing for Risen Drakkari Death Knight Entry: 26830
SET @NPC := 127552;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-282.7542,`position_y`=-699.7166,`position_z`=101.747 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-280.2459,-720.9793,101.7811,0,0,0,100,0),
(@PATH,2,-279.8599,-737.6229,101.7784,0,0,0,100,0),
(@PATH,3,-280.2459,-720.9793,101.7811,0,0,0,100,0),
(@PATH,4,-282.7542,-699.7166,101.747,0,0,0,100,0);

-- Pathing for Drakkari Commander Entry: 27431
SET @NPC := 127471;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-346.2241,`position_y`=-610.9034,`position_z`=72.60129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-373.7004,-609.6317,72.61194,0,0,0,100,0),
(@PATH,2,-346.2241,-610.9034,72.60129,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127508;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-407.2545,`position_y`=-677.0726,`position_z`=70.22565 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-413.0328,-671.7674,70.14231,0,0,0,100,0),
(@PATH,2,-413.0139,-668.8679,69.94788,0,0,0,100,0),
(@PATH,3,-407.86,-662.8748,70.08675,0,0,0,100,0),
(@PATH,4,-401.7282,-667.11,70.11458,0,0,0,100,0),
(@PATH,5,-401.2929,-673.1425,69.97565,0,0,0,100,0),
(@PATH,6,-407.2545,-677.0726,70.22565,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127509;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-409.4158,`position_y`=-663.9135,`position_z`=62.39258 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-413.1464,-668.7359,61.44815,0,0,0,100,0),
(@PATH,2,-412.7488,-672.1281,61.80927,0,0,0,100,0),
(@PATH,3,-409.5626,-677.9425,62.44814,0,0,0,100,0),
(@PATH,4,-403.616,-679.6837,62.55925,0,0,0,100,0),
(@PATH,5,-398.3275,-677.5518,62.67037,0,0,0,100,0),
(@PATH,6,-396.8555,-671.9451,62.05924,0,0,0,100,0),
(@PATH,7,-398.5243,-664.6963,62.3092,0,0,0,100,0),
(@PATH,8,-404.1799,-662.1304,62.58703,0,0,0,100,0),
(@PATH,9,-409.4158,-663.9135,62.39258,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127510;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-406.932,`position_y`=-676.9556,`position_z`=66.53109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-411.784,-673.2886,64.19775,0,0,0,100,0),
(@PATH,2,-411.4865,-667.8989,63.86424,0,0,0,100,0),
(@PATH,3,-406.9132,-663.992,65.44756,0,0,0,100,0),
(@PATH,4,-401.3338,-665.2374,64.8922,0,0,0,100,0),
(@PATH,5,-398.546,-669.8902,65.44775,0,0,0,100,0),
(@PATH,6,-400.9965,-675.5491,66.19775,0,0,0,100,0),
(@PATH,7,-406.932,-676.9556,66.53109,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127511;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-410.8573,`position_y`=-673.0195,`position_z`=72.72581 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-405.1031,-679.6655,71.92022,0,0,0,100,0),
(@PATH,2,-398.3365,-677.8955,72.69765,0,0,0,100,0),
(@PATH,3,-396.0217,-670.7278,72.72577,0,0,0,100,0),
(@PATH,4,-401.3752,-666.0843,71.7813,0,0,0,100,0),
(@PATH,5,-409.0014,-667.2194,71.83688,0,0,0,100,0),
(@PATH,6,-410.8573,-673.0195,72.72581,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127512;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-409.2986,`position_y`=-663.4329,`position_z`=58.00312 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-411.9643,-668.5157,58.22538,0,0,0,100,0),
(@PATH,2,-411.5511,-675.1073,57.94757,0,0,0,100,0),
(@PATH,3,-406.8594,-679.2547,57.08646,0,0,0,100,0),
(@PATH,4,-401.6542,-679.5847,58.64199,0,0,0,100,0),
(@PATH,5,-396.0136,-673.5827,59.4198,0,0,0,100,0),
(@PATH,6,-396.2527,-666.631,57.83645,0,0,0,100,0),
(@PATH,7,-400.8469,-661.2967,59.25313,0,0,0,100,0),
(@PATH,8,-409.2986,-663.4329,58.00312,0,0,0,100,0);

-- Pathing for Cosmetic Drakkari Bat [PH] Entry: 27490
SET @NPC := 127513;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-412.7229,`position_y`=-650.8453,`position_z`=38.51792 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-405.5179,-645.0265,36.32347,0,0,0,100,0),
(@PATH,2,-397.6033,-648.0791,36.9068,0,0,0,100,0),
(@PATH,3,-394.8318,-652.9764,38.29573,0,0,0,100,0),
(@PATH,4,-395.8389,-657.9083,37.74015,0,0,0,100,0),
(@PATH,5,-401.2168,-663.5585,39.9346,0,0,0,100,0),
(@PATH,6,-407.9547,-663.297,41.68458,0,0,0,100,0),
(@PATH,7,-413.9172,-658.0521,38.18459,0,0,0,100,0),
(@PATH,8,-412.7229,-650.8453,38.51792,0,0,0,100,0);

-- Remove Cosmetic Drakkari Bat [PH] overspawns
DELETE FROM `creature` WHERE `guid` IN (127514,127515,127516);
DELETE FROM `creature_addon` WHERE `guid` IN (127514,127515,127516);
-- Fix Inhabittype for Cosmetic Drakkari Bat [PH] "No one fixes even the simple shit!"
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=27490;

-- Pathing for Risen Drakkari Handler Entry: 26637
SET @NPC := 127444;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-490.2928,`position_y`=-651.7234,`position_z`=28.58877 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,6469, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-460.2261,-652.8841,28.48568,0,0,0,100,0),
(@PATH,2,-490.2928,-651.7234,28.58877,0,0,0,100,0);
