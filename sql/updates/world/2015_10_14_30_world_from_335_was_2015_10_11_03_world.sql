-- Add missing Firesworn spawn
SET @CGUID := 16399;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 12099, 409, 1, 1, 698.831, -507.815, -214.691, 1.832596, 7200, 0, 0);

-- Garr movement/formation fixup
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `guid`=56609;
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (56609);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(56609,56609,0,0,2,0,0),
(56609,56610,10,45,2,0,0),
(56609,56616,10,90,2,0,0),
(56609,56619,10,135,2,0,0),
(56609,56620,10,180,2,0,0),
(56609,56622,10,225,2,0,0),
(56609,56626,10,270,2,0,0),
(56609,56628,10,315,2,0,0),
(56609,@CGUID,10,360,2,0,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56742;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=619.3152,`position_y`=-1131.169,`position_z`=-201.6246 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,619.3152,-1131.169,-201.6246,0,0,0,0,100,0),
(@PATH,2,635.5156,-1094.704,-196.7484,0,0,0,0,100,0),
(@PATH,3,637.1269,-1060.913,-199.2417,0,0,0,0,100,0),
(@PATH,4,635.5156,-1094.704,-196.7484,0,0,0,0,100,0),
(@PATH,5,619.3152,-1131.169,-201.6246,0,0,0,0,100,0),
(@PATH,6,610.0372,-1155.73,-198.8285,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56743;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1039.667,`position_y`=-791.0968,`position_z`=-151.0096 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1039.667,-791.0968,-151.0096,0,0,0,0,100,0),
(@PATH,2,1026.315,-767.8003,-156.6493,0,0,0,0,100,0),
(@PATH,3,1038.774,-761.6977,-152.658,0,0,0,0,100,0),
(@PATH,4,1064.627,-748.9409,-151.7516,0,0,0,0,100,0),
(@PATH,5,1038.774,-761.6977,-152.658,0,0,0,0,100,0),
(@PATH,6,1026.315,-767.8003,-156.6493,0,0,0,0,100,0),
(@PATH,7,1039.641,-791.0518,-150.9892,0,0,0,0,100,0),
(@PATH,8,1051.314,-799.6896,-151.9713,0,0,0,0,100,0),
(@PATH,9,1040.764,-815.1115,-152.1656,0,0,0,0,100,0),
(@PATH,10,1051.314,-799.6896,-151.9713,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56744;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=862.4832,`position_y`=-1025.388,`position_z`=-193.7729 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,862.4832,-1025.388,-193.7729,0,0,0,0,100,0),
(@PATH,2,837.9779,-1005.705,-203.4326,0,0,0,0,100,0),
(@PATH,3,811.0497,-995.4718,-207.7699,0,0,0,0,100,0),
(@PATH,4,837.9779,-1005.705,-203.4326,0,0,0,0,100,0),
(@PATH,5,862.4832,-1025.388,-193.7729,0,0,0,0,100,0),
(@PATH,6,867.8922,-1050.318,-187.0417,0,0,0,0,100,0),
(@PATH,7,872.7313,-1072.91,-180.5435,0,0,0,0,100,0),
(@PATH,8,866.1934,-1092.763,-172.8487,0,0,0,0,100,0),
(@PATH,9,852.0717,-1110.005,-164.8026,0,0,0,0,100,0),
(@PATH,10,839.597,-1126.927,-156.889,0,0,0,0,100,0),
(@PATH,11,809.0994,-1147.87,-152.4792,0,0,0,0,100,0),
(@PATH,12,797.6674,-1151.59,-151.2095,0,0,0,0,100,0),
(@PATH,13,786.1231,-1142.027,-149.5751,0,0,0,0,100,0),
(@PATH,14,751.8342,-1124.252,-144.3583,0,0,0,0,100,0),
(@PATH,15,726.2703,-1123.733,-140.4308,0,0,0,0,100,0),
(@PATH,16,705.0751,-1129.982,-137.4043,0,0,0,0,100,0),
(@PATH,17,688.8096,-1145.377,-132.6487,0,0,0,0,100,0),
(@PATH,18,681.356,-1157.213,-129.4221,0,0,0,0,100,0),
(@PATH,19,678.912,-1171.258,-124.9925,0,0,0,0,100,0),
(@PATH,20,687.782,-1186.916,-122.3317,0,0,0,0,100,0),
(@PATH,21,702.4774,-1195.069,-120.2255,0,0,0,0,100,0),
(@PATH,22,687.7936,-1186.922,-122.3323,0,0,0,0,100,0),
(@PATH,23,678.912,-1171.258,-124.9925,0,0,0,0,100,0),
(@PATH,24,681.356,-1157.213,-129.4221,0,0,0,0,100,0),
(@PATH,25,688.8096,-1145.377,-132.6487,0,0,0,0,100,0),
(@PATH,26,705.0751,-1129.982,-137.4043,0,0,0,0,100,0),
(@PATH,27,726.2703,-1123.733,-140.4308,0,0,0,0,100,0),
(@PATH,28,751.8342,-1124.252,-144.3583,0,0,0,0,100,0),
(@PATH,29,786.1231,-1142.027,-149.5751,0,0,0,0,100,0),
(@PATH,30,797.6674,-1151.59,-151.2095,0,0,0,0,100,0),
(@PATH,31,809.0994,-1147.87,-152.4792,0,0,0,0,100,0),
(@PATH,32,839.597,-1126.927,-156.889,0,0,0,0,100,0),
(@PATH,33,852.0717,-1110.005,-164.8026,0,0,0,0,100,0),
(@PATH,34,866.1934,-1092.763,-172.8487,0,0,0,0,100,0),
(@PATH,35,872.7313,-1072.91,-180.5435,0,0,0,0,100,0),
(@PATH,36,867.8922,-1050.318,-187.0417,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56745;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=820.8864,`position_y`=-1133.536,`position_z`=-153.9561 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,820.8864,-1133.536,-153.9561,0,0,0,0,100,0),
(@PATH,2,811.4623,-1112.419,-155.1721,0,0,0,0,100,0),
(@PATH,3,791.674,-1098.377,-157.4893,0,0,0,0,100,0),
(@PATH,4,756.4903,-1086.385,-165.0273,0,0,0,0,100,0),
(@PATH,5,713.1385,-1077.042,-178.4627,0,0,0,0,100,0),
(@PATH,6,666.2255,-1071.984,-188.5744,0,0,0,0,100,0),
(@PATH,7,713.1385,-1077.042,-178.4627,0,0,0,0,100,0),
(@PATH,8,756.4903,-1086.385,-165.0273,0,0,0,0,100,0),
(@PATH,9,791.674,-1098.377,-157.4893,0,0,0,0,100,0),
(@PATH,10,811.4623,-1112.419,-155.1721,0,0,0,0,100,0),
(@PATH,11,820.8864,-1133.536,-153.9561,0,0,0,0,100,0),
(@PATH,12,807.4134,-1143.589,-152.2109,0,0,0,0,100,0),
(@PATH,13,788.3813,-1136.843,-150.0572,0,0,0,0,100,0),
(@PATH,14,774.8284,-1122.117,-148.7992,0,0,0,0,100,0),
(@PATH,15,753.0598,-1112.579,-145.9724,0,0,0,0,100,0),
(@PATH,16,723.3937,-1111.516,-142.1575,0,0,0,0,100,0),
(@PATH,17,692.8207,-1125.591,-137.05,0,0,0,0,100,0),
(@PATH,18,670.802,-1153.978,-128.2815,0,0,0,0,100,0),
(@PATH,19,669.009,-1180.974,-123.0805,0,0,0,0,100,0),
(@PATH,20,670.802,-1153.978,-128.2815,0,0,0,0,100,0),
(@PATH,21,692.8207,-1125.591,-137.05,0,0,0,0,100,0),
(@PATH,22,723.3937,-1111.516,-142.1575,0,0,0,0,100,0),
(@PATH,23,753.0598,-1112.579,-145.9724,0,0,0,0,100,0),
(@PATH,24,774.8284,-1122.117,-148.7992,0,0,0,0,100,0),
(@PATH,25,788.3813,-1136.843,-150.0572,0,0,0,0,100,0),
(@PATH,26,807.4134,-1143.589,-152.2109,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=706.5988,`position_y`=-608.756,`position_z`=-209.7862 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,706.5988,-608.756,-209.7862,0,0,0,0,100,0),
(@PATH,2,694.3823,-643.1285,-209.7859,0,0,0,0,100,0),
(@PATH,3,691.9941,-667.7454,-209.6549,0,0,0,0,100,0),
(@PATH,4,712.6238,-699.4688,-209.7263,0,0,0,0,100,0),
(@PATH,5,696.8894,-727.3798,-209.4279,0,0,0,0,100,0),
(@PATH,6,672.7046,-770.8894,-209.0702,0,0,0,0,100,0),
(@PATH,7,696.8894,-727.3798,-209.4279,0,0,0,0,100,0),
(@PATH,8,712.6238,-699.4688,-209.7263,0,0,0,0,100,0),
(@PATH,9,691.9941,-667.7454,-209.6549,0,0,0,0,100,0),
(@PATH,10,694.3823,-643.1285,-209.7859,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56667;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=716.2954,`position_y`=-563.1713,`position_z`=-215.2122 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,716.2954,-563.1713,-215.2122,0,0,0,0,100,0),
(@PATH,2,730.72,-541.2038,-216.5207,0,0,0,0,100,0),
(@PATH,3,751.7352,-537.1676,-215.0087,0,0,0,0,100,0),
(@PATH,4,782.8221,-568.6121,-213.2396,0,0,0,0,100,0),
(@PATH,5,826.4692,-557.4173,-206.1204,0,0,0,0,100,0),
(@PATH,6,862.7628,-559.3347,-203.8248,0,0,0,0,100,0),
(@PATH,7,897.3094,-575.2031,-203.7624,0,0,0,0,100,0),
(@PATH,8,928.274,-599.9254,-203.4944,0,0,0,0,100,0),
(@PATH,9,976.9997,-588.0521,-203.566,0,0,0,0,100,0),
(@PATH,10,1013.348,-611.7108,-198.8222,0,0,0,0,100,0),
(@PATH,11,1031.784,-628.6943,-189.8679,0,0,0,0,100,0),
(@PATH,12,1054.582,-638.4258,-174.0191,0,0,0,0,100,0),
(@PATH,13,1082.93,-658.8265,-159.5947,0,0,0,0,100,0),
(@PATH,14,1102.016,-688.0265,-153.0321,0,0,0,0,100,0),
(@PATH,15,1095.611,-709.971,-151.2729,0,0,0,0,100,0),
(@PATH,16,1102.016,-688.0265,-153.0321,0,0,0,0,100,0),
(@PATH,17,1082.93,-658.8265,-159.5947,0,0,0,0,100,0),
(@PATH,18,1054.582,-638.4258,-174.0191,0,0,0,0,100,0),
(@PATH,19,1031.784,-628.6943,-189.8679,0,0,0,0,100,0),
(@PATH,20,1013.348,-611.7108,-198.8222,0,0,0,0,100,0),
(@PATH,21,976.9997,-588.0521,-203.566,0,0,0,0,100,0),
(@PATH,22,928.274,-599.9254,-203.4944,0,0,0,0,100,0),
(@PATH,23,897.3094,-575.2031,-203.7624,0,0,0,0,100,0),
(@PATH,24,862.7628,-559.3347,-203.8248,0,0,0,0,100,0),
(@PATH,25,826.4692,-557.4173,-206.1204,0,0,0,0,100,0),
(@PATH,26,782.8221,-568.6121,-213.2396,0,0,0,0,100,0),
(@PATH,27,751.7352,-537.1676,-215.0087,0,0,0,0,100,0),
(@PATH,28,730.72,-541.2038,-216.5207,0,0,0,0,100,0),
(@PATH,29,716.2954,-563.1713,-215.2122,0,0,0,0,100,0),
(@PATH,30,710.9113,-588.9549,-211.3497,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56668;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=746.1315,`position_y`=-1006.086,`position_z`=-177.4375 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,746.1315,-1006.086,-177.4375,0,0,0,0,100,0),
(@PATH,2,733.2838,-1027.083,-177.5541,0,0,0,0,100,0),
(@PATH,3,695.6022,-1035.41,-182.9091,0,0,0,0,100,0),
(@PATH,4,652.9347,-1047.064,-195.1933,0,0,0,0,100,0),
(@PATH,5,695.6022,-1035.41,-182.9091,0,0,0,0,100,0),
(@PATH,6,733.2838,-1027.083,-177.5541,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56669;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=819.1058,`position_y`=-631.4754,`position_z`=-202.4386 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,819.1058,-631.4754,-202.4386,0,0,0,0,100,0),
(@PATH,2,842.2988,-620.2899,-203.6502,0,0,0,0,100,0),
(@PATH,3,863.2007,-606.6663,-201.9657,0,0,0,0,100,0),
(@PATH,4,880.7169,-589.9871,-203.5187,0,0,0,0,100,0),
(@PATH,5,891.5865,-563.1656,-204.1768,0,0,0,0,100,0),
(@PATH,6,880.7169,-589.9871,-203.5187,0,0,0,0,100,0),
(@PATH,7,863.2007,-606.6663,-201.9657,0,0,0,0,100,0),
(@PATH,8,842.2988,-620.2899,-203.6502,0,0,0,0,100,0),
(@PATH,9,819.1058,-631.4754,-202.4386,0,0,0,0,100,0),
(@PATH,10,801.1528,-637.2293,-203.2919,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56670;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=640.3456,`position_y`=-838.7157,`position_z`=-208.4006 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,640.3456,-838.7157,-208.4006,0,0,0,0,100,0),
(@PATH,2,606.3914,-839.9142,-207.404,0,0,0,0,100,0),
(@PATH,3,580.7532,-839.1719,-206.0227,0,0,0,0,100,0),
(@PATH,4,571.1739,-823.5732,-206.9356,0,0,0,0,100,0),
(@PATH,5,568.275,-805.6725,-206.7511,0,0,0,0,100,0),
(@PATH,6,574.7719,-784.4373,-207.1243,0,0,0,0,100,0),
(@PATH,7,568.275,-805.6725,-206.7511,0,0,0,0,100,0),
(@PATH,8,571.1739,-823.5732,-206.9356,0,0,0,0,100,0),
(@PATH,9,580.7532,-839.1719,-206.0227,0,0,0,0,100,0),
(@PATH,10,606.3914,-839.9142,-207.404,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=693.7902,`position_y`=-895.4052,`position_z`=-199.3317 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,693.7902,-895.4052,-199.3317,0,0,0,0,100,0),
(@PATH,2,676.3041,-859.0721,-207.3966,0,0,0,0,100,0),
(@PATH,3,660.5331,-846.3304,-208.582,0,0,0,0,100,0),
(@PATH,4,676.3041,-859.0721,-207.3966,0,0,0,0,100,0),
(@PATH,5,693.7902,-895.4052,-199.3317,0,0,0,0,100,0),
(@PATH,6,709.7253,-933.0809,-191.2163,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56672;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=708.7521,`position_y`=-494.4869,`position_z`=-213.9441 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,708.7521,-494.4869,-213.9441,0,0,0,0,100,0),
(@PATH,2,706.8069,-515.2225,-215.4603,0,0,0,0,100,0),
(@PATH,3,695.7981,-526.2382,-214.3069,0,0,0,0,100,0),
(@PATH,4,671.7322,-532.863,-210.5322,0,0,0,0,100,0),
(@PATH,5,695.7981,-526.2382,-214.3069,0,0,0,0,100,0),
(@PATH,6,706.8069,-515.2225,-215.4603,0,0,0,0,100,0),
(@PATH,7,708.7521,-494.4869,-213.9441,0,0,0,0,100,0),
(@PATH,8,706.4074,-474.3789,-211.1673,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56673;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=723.8314,`position_y`=-518.3099,`position_z`=-217.6104 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,723.8314,-518.3099,-217.6104,0,0,0,0,100,0),
(@PATH,2,706.7125,-535.8472,-216.7189,0,0,0,0,100,0),
(@PATH,3,685.7861,-543.6451,-211.2004,0,0,0,0,100,0),
(@PATH,4,667.6307,-538.1242,-209.9916,0,0,0,0,100,0),
(@PATH,5,685.7861,-543.6451,-211.2004,0,0,0,0,100,0),
(@PATH,6,706.7125,-535.8472,-216.7189,0,0,0,0,100,0),
(@PATH,7,723.8314,-518.3099,-217.6104,0,0,0,0,100,0),
(@PATH,8,728.2719,-487.4919,-212.95,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56674;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=831.386,`position_y`=-627.8932,`position_z`=-203.1487 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,831.386,-627.8932,-203.1487,0,0,0,0,100,0),
(@PATH,2,856.4564,-617.9056,-202.1571,0,0,0,0,100,0),
(@PATH,3,899.6118,-613.5433,-202.2377,0,0,0,0,100,0),
(@PATH,4,936.2535,-612.5002,-203.6217,0,0,0,0,100,0),
(@PATH,5,975.1815,-641.0467,-201.5775,0,0,0,0,100,0),
(@PATH,6,1002.311,-661.9902,-194.1922,0,0,0,0,100,0),
(@PATH,7,1024.067,-684.3118,-173.4296,0,0,0,0,100,0),
(@PATH,8,1042.016,-695.8206,-163.7581,0,0,0,0,100,0),
(@PATH,9,1058.163,-706.0782,-156.6107,0,0,0,0,100,0),
(@PATH,10,1068.566,-742.8318,-151.7328,0,0,0,0,100,0),
(@PATH,11,1117.097,-744.479,-145.6289,0,0,0,0,100,0),
(@PATH,12,1149.458,-726.4506,-133.8044,0,0,0,0,100,0),
(@PATH,13,1175.513,-702.1757,-130.9873,0,0,0,0,100,0),
(@PATH,14,1200.504,-670.9343,-128.5453,0,0,0,0,100,0),
(@PATH,15,1202.953,-639.3985,-126.1688,0,0,0,0,100,0),
(@PATH,16,1188.303,-614.0296,-121.8816,0,0,0,0,100,0),
(@PATH,17,1164.196,-595.4036,-115.7764,0,0,0,0,100,0),
(@PATH,18,1155.213,-574.8707,-113.3766,0,0,0,0,100,0),
(@PATH,19,1164.196,-595.4036,-115.7764,0,0,0,0,100,0),
(@PATH,20,1188.303,-614.0296,-121.8816,0,0,0,0,100,0),
(@PATH,21,1202.953,-639.3985,-126.1688,0,0,0,0,100,0),
(@PATH,22,1200.504,-670.9343,-128.5453,0,0,0,0,100,0),
(@PATH,23,1175.589,-702.0806,-130.9749,0,0,0,0,100,0),
(@PATH,24,1149.458,-726.4506,-133.8044,0,0,0,0,100,0),
(@PATH,25,1117.097,-744.479,-145.6289,0,0,0,0,100,0),
(@PATH,26,1068.566,-742.8318,-151.7328,0,0,0,0,100,0),
(@PATH,27,1058.163,-706.0782,-156.6107,0,0,0,0,100,0),
(@PATH,28,1042.016,-695.8206,-163.7581,0,0,0,0,100,0),
(@PATH,29,1024.226,-684.4753,-173.2943,0,0,0,0,100,0),
(@PATH,30,1002.311,-661.9902,-194.1922,0,0,0,0,100,0),
(@PATH,31,975.1815,-641.0467,-201.5775,0,0,0,0,100,0),
(@PATH,32,936.2535,-612.5002,-203.6217,0,0,0,0,100,0),
(@PATH,33,899.6118,-613.5433,-202.2377,0,0,0,0,100,0),
(@PATH,34,856.4564,-617.9056,-202.1571,0,0,0,0,100,0),
(@PATH,35,831.386,-627.8932,-203.1487,0,0,0,0,100,0),
(@PATH,36,816.5816,-641.0675,-203.8891,0,0,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1144.05,`position_y`=-662.6844,`position_z`=-131.4626 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1144.05,-662.6844,-131.4626,0,0,0,0,100,0),
(@PATH,2,1160.286,-696.8795,-132.4863,0,0,0,0,100,0),
(@PATH,3,1129.031,-721.049,-139.5804,0,0,0,0,100,0),
(@PATH,4,1118.512,-712.1383,-144.2585,0,0,0,0,100,0),
(@PATH,5,1104.687,-722.1303,-146.9832,0,0,0,0,100,0),
(@PATH,6,1090.824,-731.3634,-149.9868,0,0,0,0,100,0),
(@PATH,7,1070.791,-717.5623,-153.4831,0,0,0,0,100,0),
(@PATH,8,1080.754,-681.5721,-159.8726,0,0,0,0,100,0),
(@PATH,9,1081.626,-681.3043,-159.6755,0,12000,0,0,100,0),
(@PATH,10,1079.369,-678.5401,-160.8983,0,10000,0,0,100,0),
(@PATH,11,1081.374,-680.3018,-159.9551,0,1000,0,0,100,0),
(@PATH,12,1080.824,-681.4283,-159.8819,0,2000,0,0,100,0),
(@PATH,13,1081.491,-679.0739,-160.1742,0,1000,0,0,100,0),
(@PATH,14,1079.343,-678.3975,-160.9352,0,5000,0,0,100,0),
(@PATH,15,1081.436,-676.3215,-160.7577,0,8000,0,0,100,0),
(@PATH,16,1080.754,-681.5721,-159.8726,0,1000,0,0,100,0),
(@PATH,17,1077.228,-678.6388,-161.4971,0,1000,0,0,100,0),
(@PATH,18,1077.687,-678.7886,-161.3334,0,1000,0,0,100,0),
(@PATH,19,1079.716,-679.3854,-160.6235,0,10000,0,0,100,0),
(@PATH,20,1081.338,-682.8629,-159.4373,0,10000,0,0,100,0),
(@PATH,21,1079.463,-680.3129,-160.5056,0,1000,0,0,100,0),
(@PATH,22,1080.754,-681.5721,-159.8726,0,1000,0,0,100,0),
(@PATH,23,1080.708,-679.2873,-160.3567,0,1000,0,0,100,0),
(@PATH,24,1082.191,-681.9566,-159.3777,0,9000,0,0,100,0),
(@PATH,25,1079.69,-678.5046,-160.8126,0,8000,0,0,100,0),
(@PATH,26,1080.177,-679.1766,-160.5332,0,1000,0,0,100,0),
(@PATH,27,1078.341,-677.3896,-161.4327,0,9000,0,0,100,0),
(@PATH,28,1079.791,-676.366,-161.2243,0,1000,0,0,100,0),
(@PATH,29,1078.341,-677.3896,-161.4327,0,1000,0,0,100,0),
(@PATH,30,1081.163,-683.5833,-159.3395,0,7000,0,0,100,0),
(@PATH,31,1080.636,-682.1011,-159.7975,0,1000,0,0,100,0),
(@PATH,32,1081.985,-678.5395,-160.1417,0,2000,0,0,100,0),
(@PATH,33,1081.526,-679.8784,-159.9983,0,1000,0,0,100,0),
(@PATH,34,1080.778,-681.3652,-159.9082,0,1000,0,0,100,0),
(@PATH,35,1079.221,-677.4147,-161.1729,0,1000,0,0,100,0),
(@PATH,36,1079.501,-678.1235,-160.946,0,2000,0,0,100,0),
(@PATH,37,1080.827,-681.6636,-159.8325,0,6000,0,0,100,0),
(@PATH,38,1085.063,-680.338,-158.8806,0,8000,0,0,100,0),
(@PATH,39,1079.092,-677.261,-161.242,0,1000,0,0,100,0),
(@PATH,40,1079.541,-677.6991,-161.0217,0,1000,0,0,100,0),
(@PATH,41,1081.284,-682.4361,-159.5412,0,2000,0,0,100,0),
(@PATH,42,1080.757,-681.0048,-159.9885,0,1000,0,0,100,0),
(@PATH,43,1083.066,-680.2807,-159.4699,0,6000,0,0,100,0),
(@PATH,44,1081.552,-677.1035,-160.5629,0,1000,0,0,100,0),
(@PATH,45,1081.611,-680.4688,-159.852,0,11000,0,0,100,0),
(@PATH,46,1080.048,-679.4224,-160.5198,0,7000,0,0,100,0),
(@PATH,47,1082.761,-681.9189,-159.2203,0,11000,0,0,100,0),
(@PATH,48,1078.952,-678.8635,-160.9521,0,8000,0,0,100,0),
(@PATH,49,1081.18,-681.5133,-159.7614,0,1000,0,0,100,0),
(@PATH,50,1080.676,-681.3997,-159.9307,0,11000,0,0,100,0),
(@PATH,51,1078.617,-679.6107,-160.8951,0,1000,0,0,100,0),
(@PATH,52,1081.279,-680.4371,-159.9548,0,1000,0,0,100,0),
(@PATH,53,1078.764,-677.3422,-161.3203,0,1000,0,0,100,0),
(@PATH,54,1080.66,-681.4279,-159.9294,0,2000,0,0,100,0),
(@PATH,55,1080.101,-708.452,-154.2289,0,1000,0,0,100,0),
(@PATH,56,1084.528,-731.8951,-151.0118,0,0,0,0,100,0),
(@PATH,57,1093.696,-748.0836,-149.2619,0,0,0,0,100,0),
(@PATH,58,1110.641,-738.1426,-146.5005,0,0,0,0,100,0),
(@PATH,59,1115.694,-716.585,-144.6347,0,0,0,0,100,0),
(@PATH,60,1148.22,-713.5815,-132.988,0,0,0,0,100,0),
(@PATH,61,1161.699,-694.4932,-132.2003,0,0,0,0,100,0),
(@PATH,62,1149.113,-669.7729,-130.3396,0,0,0,0,100,0),
(@PATH,63,1142.684,-647.411,-131.9233,0,0,0,0,100,0),
(@PATH,64,1142.684,-647.411,-131.9233,1.53589,60000,0,0,100,0);

-- Pathing for Core Hound Entry: 11673 'TDB FORMAT' 
SET @NPC := 56676;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=820.1378,`position_y`=-991.096,`position_z`=-207.1345 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '18950');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,820.1378,-991.096,-207.1345,0,0,0,0,100,0),
(@PATH,2,815.0589,-979.8468,-208.6176,0,0,0,0,100,0),
(@PATH,3,820.1378,-991.096,-207.1345,0,0,0,0,100,0),
(@PATH,4,837.5117,-1001.866,-203.9284,0,0,0,0,100,0),
(@PATH,5,875.2714,-1009.17,-195.7951,0,0,0,0,100,0),
(@PATH,6,884.1406,-1024.13,-192.9333,0,0,0,0,100,0),
(@PATH,7,875.2714,-1009.17,-195.7951,0,0,0,0,100,0),
(@PATH,8,837.5117,-1001.866,-203.9284,0,0,0,0,100,0);

-- Pathing for Baron Geddon Entry: 12056 'TDB FORMAT' 
SET @NPC := 56655;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=747.5466,`position_y`=-981.676,`position_z`=-178.401 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,747.5466,-981.676,-178.401,0,0,1,0,100,0),
(@PATH,2,739.986,-953.2151,-185.7548,0,0,1,0,100,0),
(@PATH,3,716.3201,-910.8809,-193.1546,0,0,1,0,100,0),
(@PATH,4,701.403,-887.8356,-199.5063,0,0,1,0,100,0),
(@PATH,5,675.8235,-847.7932,-208.2585,0,0,1,0,100,0),
(@PATH,6,639.0753,-830.6404,-208.4202,0,0,1,0,100,0),
(@PATH,7,611.1107,-828.0424,-207.401,0,0,1,0,100,0),
(@PATH,8,591.2252,-811.5459,-205.4029,0,0,1,0,100,0),
(@PATH,9,608.8426,-787.6771,-207.4771,0,0,1,0,100,0),
(@PATH,10,643.6417,-778.0462,-208.7169,0,0,1,0,100,0),
(@PATH,11,664.3234,-786.412,-208.9517,0,0,1,0,100,0),
(@PATH,12,661.6707,-816.6882,-208.705,0,0,1,0,100,0),
(@PATH,13,678.5975,-847.099,-208.2891,0,0,1,0,100,0),
(@PATH,14,699.6382,-878.082,-201.5386,0,0,1,0,100,0),
(@PATH,15,718.3248,-907.4992,-193.3159,0,0,1,0,100,0),
(@PATH,16,740.3997,-949.3792,-186.3494,0,0,1,0,100,0),
(@PATH,17,746.6027,-966.5585,-181.5636,0,0,1,0,100,0);

-- Pathing for Shazzrah Entry: 12264 'TDB FORMAT' 
SET @NPC := 56608;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=587.3033,`position_y`=-801.9748,`position_z`=-205.1575 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,587.3033,-801.9748,-205.1575,0,0,0,0,100,0),
(@PATH,2,588.8104,-806.2665,-205.0612,0,0,0,0,100,0),
(@PATH,3,587.384,-811.3304,-205.1067,0,0,0,0,100,0),
(@PATH,4,583.1524,-811.6958,-205.1573,0,0,0,0,100,0),
(@PATH,5,579.2105,-806.6736,-205.2536,0,0,0,0,100,0),
(@PATH,6,579.0768,-804.3456,-205.2396,0,0,0,0,100,0),
(@PATH,7,580.0167,-800.6034,-205.4058,0,0,0,0,100,0),
(@PATH,8,583.49,-799.7552,-205.3562,0,0,0,0,100,0);

-- Pathing for Lucifron Entry: 12118 'TDB FORMAT' 
SET @NPC := 56605;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1037.022,`position_y`=-986.3419,`position_z`=-181.5163 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1037.022,-986.3419,-181.5163,0,0,0,0,100,0),
(@PATH,2,1053.15,-990.7546,-182.6615,0,0,0,0,100,0),
(@PATH,3,1070.411,-1006.765,-185.5444,0,0,0,0,100,0),
(@PATH,4,1053.299,-990.8936,-182.7192,0,0,0,0,100,0),
(@PATH,5,1037.022,-986.3419,-181.5163,0,0,0,0,100,0),
(@PATH,6,1014.705,-978.6508,-181.182,0,0,0,0,100,0),
(@PATH,7,1007.782,-958.0884,-180.174,0,0,0,0,100,0),
(@PATH,8,1000.203,-955.4069,-179.5825,0,0,0,0,100,0),
(@PATH,9,1007.782,-958.0884,-180.174,0,0,0,0,100,0),
(@PATH,10,1014.45,-978.5632,-181.1854,0,0,0,0,100,0);
-- Lucifron formation fixup
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (56605);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(56605,56605,0,0,2,0,0),
(56605,56606,4,90,2,3,8),
(56605,56607,4,270,2,3,8);
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1035.672,`position_y`=-989.7419,`position_z`=-181.7763 WHERE `guid`=56606;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1038.512,`position_y`=-982.9519,`position_z`=-181.2578 WHERE `guid`=56607;
DELETE FROM `waypoint_data` WHERE `id` IN (566060,566070);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56656;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1028.491,`position_y`=-908.0417,`position_z`=-161.3687 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1028.491,-908.0417,-161.3687,0,0,1,0,100,0),
(@PATH,2,1041.238,-888.9818,-158.3343,0,0,1,0,100,0),
(@PATH,3,1061.057,-900.0848,-159.2599,0,0,1,0,100,0),
(@PATH,4,1071.243,-893.1624,-156.4947,0,0,1,0,100,0),
(@PATH,5,1041.238,-888.9818,-158.3343,0,0,1,0,100,0),
(@PATH,6,1028.491,-908.0417,-161.3687,0,0,1,0,100,0),
(@PATH,7,1008.565,-890.0919,-165.3463,0,0,1,0,100,0),
(@PATH,8,980.3823,-904.361,-171.1376,0,0,1,0,100,0),
(@PATH,9,966.753,-899.8453,-175.7252,0,0,1,0,100,0),
(@PATH,10,957.4196,-885.538,-173.7588,0,0,1,0,100,0),
(@PATH,11,980.3823,-904.361,-171.1376,0,0,1,0,100,0),
(@PATH,12,1008.565,-890.0919,-165.3463,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56657;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=748.5151,`position_y`=-725.4263,`position_z`=-211.9395 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,748.5151,-725.4263,-211.9395,0,0,1,0,100,0),
(@PATH,2,739.7422,-763.3509,-218.9724,0,0,1,0,100,0),
(@PATH,3,737.3899,-809.9995,-225.6305,0,0,1,0,100,0),
(@PATH,4,745.2436,-850.8501,-223.6281,0,0,1,0,100,0),
(@PATH,5,737.3899,-809.9995,-225.6305,0,0,1,0,100,0),
(@PATH,6,739.7422,-763.3509,-218.9724,0,0,1,0,100,0),
(@PATH,7,748.5151,-725.4263,-211.9395,0,0,1,0,100,0),
(@PATH,8,764.8676,-686.4996,-212.5972,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56658;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=975.5094,`position_y`=-589.3787,`position_z`=-203.781 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,975.5094,-589.3787,-203.781,0,0,1,0,100,0),
(@PATH,2,958.4057,-595.7327,-203.9931,0,0,1,0,100,0),
(@PATH,3,950.7159,-608.6719,-202.882,0,0,1,0,100,0),
(@PATH,4,957.0149,-625.9316,-203.259,0,0,1,0,100,0),
(@PATH,5,980.0177,-632.2986,-203.5142,0,0,1,0,100,0),
(@PATH,6,990.2437,-625.777,-200.7675,0,0,1,0,100,0),
(@PATH,7,998.6928,-609.5692,-202.0619,0,0,1,0,100,0),
(@PATH,8,989.8893,-595.9269,-203.2261,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56659;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=864.6398,`position_y`=-983.1211,`position_z`=-199.6699 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,864.6398,-983.1211,-199.6699,0,0,1,0,100,0),
(@PATH,2,875.8871,-1014.841,-194.9043,0,0,1,0,100,0),
(@PATH,3,891.3988,-1050.081,-187.1399,0,0,1,0,100,0),
(@PATH,4,891.1622,-1067.062,-182.6621,0,0,1,0,100,0),
(@PATH,5,883.1496,-1090.733,-176.0342,0,0,1,0,100,0),
(@PATH,6,870.0406,-1110.407,-169.6678,0,0,1,0,100,0),
(@PATH,7,855.7172,-1121.873,-161.9807,0,0,1,0,100,0),
(@PATH,8,839.0113,-1128.492,-156.5452,0,0,1,0,100,0),
(@PATH,9,819.8719,-1143.5,-153.6145,0,0,1,0,100,0),
(@PATH,10,809.326,-1150.683,-152.5631,0,0,1,0,100,0),
(@PATH,11,791.812,-1152.45,-150.4214,0,0,1,0,100,0),
(@PATH,12,787.2233,-1123.192,-150.5524,0,0,1,0,100,0),
(@PATH,13,757.2313,-1129.672,-145.1273,0,0,1,0,100,0),
(@PATH,14,723.393,-1106.211,-143.0938,0,0,1,0,100,0),
(@PATH,15,701.5763,-1137.426,-135.6903,0,0,1,0,100,0),
(@PATH,16,666.1591,-1162.693,-126.0165,0,0,1,0,100,0),
(@PATH,17,693.4008,-1186.742,-120.9137,0,0,1,0,100,0),
(@PATH,18,717.1637,-1193.438,-118.9491,0,0,1,0,100,0),
(@PATH,19,736.2715,-1211.634,-118.8998,0,0,1,0,100,0),
(@PATH,20,759.3818,-1228.879,-119.2757,0,0,1,0,100,0),
(@PATH,21,736.2715,-1211.634,-118.8998,0,0,1,0,100,0),
(@PATH,22,717.1637,-1193.438,-118.9491,0,0,1,0,100,0),
(@PATH,23,693.4008,-1186.742,-120.9137,0,0,1,0,100,0),
(@PATH,24,666.1591,-1162.693,-126.0165,0,0,1,0,100,0),
(@PATH,25,701.5763,-1137.426,-135.6903,0,0,1,0,100,0),
(@PATH,26,723.393,-1106.211,-143.0938,0,0,1,0,100,0),
(@PATH,27,757.2313,-1129.672,-145.1273,0,0,1,0,100,0),
(@PATH,28,787.2233,-1123.192,-150.5524,0,0,1,0,100,0),
(@PATH,29,791.812,-1152.45,-150.4214,0,0,1,0,100,0),
(@PATH,30,809.326,-1150.683,-152.5631,0,0,1,0,100,0),
(@PATH,31,819.8719,-1143.5,-153.6145,0,0,1,0,100,0),
(@PATH,32,839.0113,-1128.492,-156.5452,0,0,1,0,100,0),
(@PATH,33,855.7172,-1121.873,-161.9807,0,0,1,0,100,0),
(@PATH,34,870.0406,-1110.407,-169.6678,0,0,1,0,100,0),
(@PATH,35,883.1496,-1090.733,-176.0342,0,0,1,0,100,0),
(@PATH,36,891.1622,-1067.062,-182.6621,0,0,1,0,100,0),
(@PATH,37,891.3988,-1050.081,-187.1399,0,0,1,0,100,0),
(@PATH,38,875.8871,-1014.841,-194.9043,0,0,1,0,100,0),
(@PATH,39,864.6398,-983.1211,-199.6699,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56660;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=912.38,`position_y`=-812.9961,`position_z`=-227.3731 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,912.38,-812.9961,-227.3731,0,0,1,0,100,0),
(@PATH,2,917.8469,-848.5494,-219.4701,0,0,1,0,100,0),
(@PATH,3,913.7874,-875.5369,-214.22,0,0,1,0,100,0),
(@PATH,4,890.5936,-905.0054,-222.0683,0,0,1,0,100,0),
(@PATH,5,860.6026,-921.1229,-225.7609,0,0,1,0,100,0),
(@PATH,6,816.981,-920.8954,-225.8454,0,0,1,0,100,0),
(@PATH,7,782.662,-911.1868,-222.6471,0,0,1,0,100,0),
(@PATH,8,816.9766,-920.8942,-225.8542,0,0,1,0,100,0),
(@PATH,9,860.6026,-921.1229,-225.7609,0,0,1,0,100,0),
(@PATH,10,890.5936,-905.0054,-222.0683,0,0,1,0,100,0),
(@PATH,11,913.7874,-875.5369,-214.22,0,0,1,0,100,0),
(@PATH,12,917.8469,-848.5494,-219.4701,0,0,1,0,100,0),
(@PATH,13,912.38,-812.9961,-227.3731,0,0,1,0,100,0),
(@PATH,14,909.2687,-788.947,-226.9377,0,0,1,0,100,0),
(@PATH,15,895.7159,-764.4568,-224.3548,0,0,1,0,100,0),
(@PATH,16,879.3519,-761.3517,-224.0491,0,0,1,0,100,0),
(@PATH,17,865.0396,-765.1099,-224.75,0,0,1,0,100,0),
(@PATH,18,884.0205,-803.6951,-226.6926,0,0,1,0,100,0),
(@PATH,19,889.6862,-825.1835,-227.3351,0,0,1,0,100,0),
(@PATH,20,865.6118,-779.7151,-225.9819,0,0,1,0,100,0),
(@PATH,21,865.0396,-765.1099,-224.75,0,0,1,0,100,0),
(@PATH,22,879.3519,-761.3517,-224.0491,0,0,1,0,100,0),
(@PATH,23,895.7159,-764.4568,-224.3548,0,0,1,0,100,0),
(@PATH,24,909.2687,-788.947,-226.9377,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56661;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1031.916,`position_y`=-889.574,`position_z`=-160.0134 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1031.916,-889.574,-160.0134,0,0,1,0,100,0),
(@PATH,2,1069.734,-893.855,-156.7931,0,0,1,0,100,0),
(@PATH,3,1031.916,-889.574,-160.0134,0,0,1,0,100,0),
(@PATH,4,996.8139,-897.9012,-168.1947,0,0,1,0,100,0),
(@PATH,5,962.845,-884.6795,-173.6825,0,0,1,0,100,0),
(@PATH,6,987.062,-893.2951,-169.7379,0,0,1,0,100,0),
(@PATH,7,1001.684,-886.9771,-167.0547,0,0,1,0,100,0),
(@PATH,8,1008.282,-863.9785,-164.7876,0,0,1,0,100,0),
(@PATH,9,987.062,-893.2951,-169.7379,0,0,1,0,100,0),
(@PATH,10,962.845,-884.6795,-173.6825,0,0,1,0,100,0),
(@PATH,11,996.8139,-897.9012,-168.1947,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56662;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1068.962,`position_y`=-696.559,`position_z`=-157.781 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1068.962,-696.559,-157.781,0,0,1,0,100,0),
(@PATH,2,1053.966,-737.0459,-151.7794,0,0,1,0,100,0),
(@PATH,3,1059.624,-760.5685,-151.586,0,0,1,0,100,0),
(@PATH,4,1084.683,-739.8831,-150.7728,0,0,1,0,100,0),
(@PATH,5,1099.292,-778.5201,-151.1692,0,0,1,0,100,0),
(@PATH,6,1125.305,-739.6833,-142.7612,0,0,1,0,100,0),
(@PATH,7,1159.508,-719.2535,-133.2384,0,0,1,0,100,0),
(@PATH,8,1192.168,-686.1762,-128.7967,0,0,1,0,100,0),
(@PATH,9,1211.332,-653.7628,-127.9139,0,0,1,0,100,0),
(@PATH,10,1187.516,-611.0389,-121.1588,0,0,1,0,100,0),
(@PATH,11,1148.847,-599.9906,-114.898,0,0,1,0,100,0),
(@PATH,12,1187.516,-611.0389,-121.1588,0,0,1,0,100,0),
(@PATH,13,1211.332,-653.7628,-127.9139,0,0,1,0,100,0),
(@PATH,14,1192.168,-686.1762,-128.7967,0,0,1,0,100,0),
(@PATH,15,1159.508,-719.2535,-133.2384,0,0,1,0,100,0),
(@PATH,16,1125.392,-739.6312,-142.7302,0,0,1,0,100,0),
(@PATH,17,1099.292,-778.5201,-151.1692,0,0,1,0,100,0),
(@PATH,18,1084.683,-739.8831,-150.7728,0,0,1,0,100,0),
(@PATH,19,1059.654,-760.5442,-151.592,0,0,1,0,100,0),
(@PATH,20,1053.966,-737.0459,-151.7794,0,0,1,0,100,0),
(@PATH,21,1068.962,-696.559,-157.781,0,0,1,0,100,0),
(@PATH,22,1046.413,-674.9515,-169.5157,0,0,1,0,100,0),
(@PATH,23,1023.84,-646.451,-189.8513,0,0,1,0,100,0),
(@PATH,24,1046.413,-674.9515,-169.5157,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56664;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=759.9225,`position_y`=-689.7131,`position_z`=-212.5623 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,759.9225,-689.7131,-212.5623,0,0,1,0,100,0),
(@PATH,2,779.0322,-680.1849,-213.9095,0,0,1,0,100,0),
(@PATH,3,800.4368,-665.5578,-208.9407,0,0,1,0,100,0),
(@PATH,4,807.4164,-656.269,-206.1155,0,0,1,0,100,0),
(@PATH,5,779.0322,-680.1849,-213.9095,0,0,1,0,100,0),
(@PATH,6,759.9225,-689.7131,-212.5623,0,0,1,0,100,0),
(@PATH,7,753.9745,-704.1632,-211.753,0,0,1,0,100,0),
(@PATH,8,758.8966,-684.4725,-212.381,0,0,1,0,100,0),
(@PATH,9,780.8896,-669.565,-211.4591,0,0,1,0,100,0),
(@PATH,10,791.4582,-652.981,-207.6324,0,0,1,0,100,0),
(@PATH,11,758.8966,-684.4725,-212.381,0,0,1,0,100,0),
(@PATH,12,753.9745,-704.1632,-211.753,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56665;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1035.173,`position_y`=-854.7958,`position_z`=-158.8589 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1035.173,-854.7958,-158.8589,0,0,1,0,100,0),
(@PATH,2,1057.385,-862.5274,-159.6177,0,0,1,0,100,0),
(@PATH,3,995.0676,-853.4235,-165.4317,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56740;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=667.9337,`position_y`=-1066.047,`position_z`=-188.3889 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,667.9337,-1066.047,-188.3889,0,0,1,0,100,0),
(@PATH,2,619.8726,-1066.64,-199.7958,0,0,1,0,100,0),
(@PATH,3,613.3337,-1099.887,-198.7582,0,0,1,0,100,0),
(@PATH,4,591.3667,-1135.207,-200.2088,0,0,1,0,100,0),
(@PATH,5,578.8029,-1173.733,-194.7558,0,0,1,0,100,0),
(@PATH,6,591.5503,-1192.438,-195.7943,0,0,1,0,100,0),
(@PATH,7,608.195,-1194.054,-195.7651,0,0,1,0,100,0),
(@PATH,8,623.8442,-1186.21,-195.8348,0,0,1,0,100,0),
(@PATH,9,628.4896,-1171.869,-194.5435,0,0,1,0,100,0),
(@PATH,10,628.3709,-1151.011,-197.0152,0,0,1,0,100,0),
(@PATH,11,626.806,-1131.724,-200.8709,0,0,1,0,100,0),
(@PATH,12,645.6395,-1106.676,-196.4797,0,0,1,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56741;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1055.823,`position_y`=-833.2653,`position_z`=-154.468 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1055.823,-833.2653,-154.468,0,0,0,0,100,0),
(@PATH,2,1032.143,-826.1788,-154.2626,0,0,0,0,100,0),
(@PATH,3,1015.666,-808.7546,-148.7213,0,0,0,0,100,0),
(@PATH,4,1032.143,-826.1788,-154.2626,0,0,0,0,100,0);

-- Pathing for Lava Surger Entry: 12101 'TDB FORMAT' 
SET @NPC := 56789;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=679.1953,`position_y`=-847.3836,`position_z`=-208.2482 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,679.1953,-847.3836,-208.2482,0,0,1,0,100,0),
(@PATH,2,676.7046,-829.8509,-208.8353,0,0,1,0,100,0),
(@PATH,3,665.002,-813.2372,-208.774,0,0,1,0,100,0),
(@PATH,4,681.6021,-776.7833,-209.1657,0,0,1,0,100,0),
(@PATH,5,686.1985,-738.5436,-209.2948,0,0,1,0,100,0),
(@PATH,6,707.9111,-711.0708,-209.5187,0,0,1,0,100,0),
(@PATH,7,708.2624,-692.8405,-209.5718,0,0,1,0,100,0),
(@PATH,8,690.2739,-662.6287,-209.6574,0,0,1,0,100,0),
(@PATH,9,708.2625,-692.8368,-209.5175,0,0,1,0,100,0),
(@PATH,10,707.9111,-711.0708,-209.5187,0,0,1,0,100,0),
(@PATH,11,686.1985,-738.5436,-209.2948,0,0,1,0,100,0),
(@PATH,12,681.6021,-776.7833,-209.1657,0,0,1,0,100,0),
(@PATH,13,665.002,-813.2372,-208.774,0,0,1,0,100,0),
(@PATH,14,676.7046,-829.8509,-208.8353,0,0,1,0,100,0),
(@PATH,15,679.1953,-847.3836,-208.2482,0,0,1,0,100,0),
(@PATH,16,696.5482,-855.4606,-206.0954,0,0,1,0,100,0),
(@PATH,17,710.7119,-882.6242,-198.953,0,0,1,0,100,0),
(@PATH,18,714.8118,-907.6405,-193.7685,0,0,1,0,100,0),
(@PATH,19,735.3042,-937.3447,-188.4066,0,0,1,0,100,0),
(@PATH,20,714.8118,-907.6405,-193.7685,0,0,1,0,100,0),
(@PATH,21,710.7119,-882.6242,-198.953,0,0,1,0,100,0),
(@PATH,22,697.0541,-866.1818,-204.0854,0,0,1,0,100,0);
