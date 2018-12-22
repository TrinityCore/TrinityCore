
-- Pathing for  Entry: 42810 'TDB FORMAT' 
SET @NPC := 340551;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1181.825,`position_y`=1069.069,`position_z`=264.2993 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1181.825,1069.069,264.2993,0,0,0,0,100,0),
(@PATH,2,1183.867,1087.719,263.8982,0,0,0,0,100,0),
(@PATH,3,1187.34,1063.681,263.3675,0,0,0,0,100,0),
(@PATH,4,1187.34,1063.681,263.3675,5.602507,6000,0,0,100,0),
(@PATH,5,1156.91,1047.903,265.4753,0,0,0,0,100,0);
-- 0x2030A45AA029CE8000298500002EC493 .go xyz 1181.825 1069.069 264.2993

-- Pathing for  Entry: 42810 'TDB FORMAT' 
SET @NPC := 340513;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1117.345,`position_y`=1014.186,`position_z`=266.6829 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1117.345,1014.186,266.6829,0,0,0,0,100,0),
(@PATH,2,1136.958,1026.087,267.018,0,0,0,0,100,0),
(@PATH,3,1117.345,1014.186,266.6829,0,0,0,0,100,0),
(@PATH,4,1091.625,992.7847,264.373,0,0,0,0,100,0),
(@PATH,5,1069.092,963.934,260.1193,0,0,0,0,100,0),
(@PATH,6,1091.625,992.7847,264.373,0,0,0,0,100,0);
-- 0x2030A45AA029CE800029850000AEC493 .go xyz 1117.345 1014.186 266.6829

-- Pathing for  Entry: 42810 'TDB FORMAT' 
SET @NPC := 340516;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1150.245,`position_y`=929.8108,`position_z`=284.7753 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1150.245,929.8108,284.7753,0,0,0,0,100,0),
(@PATH,2,1149.689,946.9427,283.7964,0,0,0,0,100,0),
(@PATH,3,1152.821,963.9549,282.9501,0,0,0,0,100,0),
(@PATH,4,1160.462,974.0677,279.9007,0,0,0,0,100,0),
(@PATH,5,1170.483,995.6285,273.9234,0,0,0,0,100,0),
(@PATH,6,1163.292,1017.347,269.8757,0,0,0,0,100,0),
(@PATH,7,1170.483,995.6285,273.9234,0,0,0,0,100,0),
(@PATH,8,1160.508,974.1669,279.8546,0,0,0,0,100,0),
(@PATH,9,1152.821,963.9549,282.9501,0,0,0,0,100,0),
(@PATH,10,1149.689,946.9427,283.7964,0,0,0,0,100,0);
-- 0x2030A45AA029CE8000298500012EC493 .go xyz 1150.245 929.8108 284.7753

-- Pathing for  Entry: 42695 'TDB FORMAT' 
SET @NPC := 340694;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1550.526,`position_y`=1193.469,`position_z`=220.5685 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1550.526,1193.469,220.5685,0,0,0,0,100,0),
(@PATH,2,1543.656,1212.661,223.2393,0,0,0,0,100,0),
(@PATH,3,1563.814,1178.012,218.4005,0,0,0,0,100,0),
(@PATH,4,1574.295,1151.352,216.1228,0,0,0,0,100,0),
(@PATH,5,1567.819,1105.63,215.8223,0,0,0,0,100,0),
(@PATH,6,1573.047,1131.243,215.7169,0,0,0,0,100,0),
(@PATH,7,1570.785,1160.727,216.7745,0,0,0,0,100,0),
(@PATH,8,1557.627,1183.724,219.0554,0,0,0,0,100,0);
-- 0x2030A45AA029B1C000298500002EC493 .go xyz 1550.526 1193.469 220.5685

-- Pathing for  Entry: 42695 'TDB FORMAT' 
SET @NPC := 340711;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1546.345,`position_y`=1159.319,`position_z`=216.7407 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1546.345,1159.319,216.7407,0,0,0,0,100,0),
(@PATH,2,1547.222,1147.325,216.423,0,0,0,0,100,0),
(@PATH,3,1547.339,1128.038,216.3325,0,0,0,0,100,0),
(@PATH,4,1544.799,1114.207,216.3325,0,0,0,0,100,0),
(@PATH,5,1540.96,1106.8,216.3931,0,0,0,0,100,0),
(@PATH,6,1544.799,1114.207,216.3325,0,0,0,0,100,0),
(@PATH,7,1547.339,1128.038,216.3325,0,0,0,0,100,0),
(@PATH,8,1547.222,1147.325,216.423,0,0,0,0,100,0);
-- 0x2030A45AA029B1C000298500002EC494 .go xyz 1546.345 1159.319 216.7407

-- Pathing for  Entry: 42695 'TDB FORMAT' 
SET @NPC := 340654;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1442.42,`position_y`=1189.29,`position_z`=230.9655 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1442.42,1189.29,230.9655,3.682645,7000,0,0,100,0),
(@PATH,2,1460.662,1197.037,230.4427,0,0,0,0,100,0),
(@PATH,3,1455.39,1211.3,230.9601,0,0,0,0,100,0),
(@PATH,4,1448.73,1220.99,231.6259,0,0,0,0,100,0),
(@PATH,5,1444.97,1202.81,229.8786,0,0,0,0,100,0);
-- 0x2030A45AA029B1C00029850000AEC493 .go xyz 1442.42 1189.29 230.9655

-- Pathing for  Entry: 42695 'TDB FORMAT' 
SET @NPC := 340712;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1566.243,`position_y`=1120.368,`position_z`=215.719 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1566.243,1120.368,215.719,0,0,0,0,100,0),
(@PATH,2,1582.618,1117.285,216.2138,0,0,0,0,100,0),
(@PATH,3,1566.243,1120.368,215.719,0,0,0,0,100,0),
(@PATH,4,1574.88,1117.925,215.7319,0,0,0,0,100,0),
(@PATH,5,1553.618,1124.535,216.3345,0,0,0,0,100,0),
(@PATH,6,1541.175,1130.726,216.3325,0,0,0,0,100,0),
(@PATH,7,1566.243,1120.368,215.719,0,0,0,0,100,0),
(@PATH,8,1582.618,1117.285,216.2138,0,0,0,0,100,0),
(@PATH,9,1592.052,1115.46,216.2268,0,0,0,0,100,0),
(@PATH,10,1574.88,1117.925,215.7319,0,0,0,0,100,0);
-- 0x2030A45AA029B1C00029850000AEC494 .go xyz 1566.243 1120.368 215.719

-- Pathing for  Entry: 42692 'TDB FORMAT' 
SET @NPC := 340678;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1288.18,`position_y`=1081.26,`position_z`=212.5155 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1288.18,1081.26,212.5155,4.502949,6000,0,0,100,0),
(@PATH,2,1322.95,1068.75,212.3748,0,0,0,0,100,0),
(@PATH,3,1349.6,1069.2,212.994,0,0,0,0,100,0),
(@PATH,4,1377.69,1068.29,213.098,0,0,0,0,100,0),
(@PATH,5,1404.79,1059.38,212.7177,0,0,0,0,100,0),
(@PATH,6,1386.41,1114.62,212.7551,0,0,0,0,100,0),
(@PATH,7,1356.41,1123.34,213.0578,0,0,0,0,100,0),
(@PATH,8,1335.37,1119.48,213.1407,0,0,0,0,100,0),
(@PATH,9,1313.96,1102.96,212.944,0,0,0,0,100,0);
-- 0x2030A45AA029B10000298500002EC493 .go xyz 1288.18 1081.26 212.5155

-- Pathing for  Entry: 42692 'TDB FORMAT' 
SET @NPC := 340693;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1539.342,`position_y`=1085.764,`position_z`=215.9438 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1539.342,1085.764,215.9438,0,0,0,0,100,0),
(@PATH,2,1553.276,1097.672,215.7756,0,0,0,0,100,0),
(@PATH,3,1554.925,1169.472,216.6244,0,0,0,0,100,0),
(@PATH,4,1562.587,1147.788,215.7576,0,0,0,0,100,0);
-- 0x2030A45AA029B10000298500002EC494 .go xyz 1539.342 1085.764 215.9438

-- Pathing for  Entry: 42692 'TDB FORMAT' 
SET @NPC := 340719;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1554.5,`position_y`=1069.16,`position_z`=217.8835 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1554.5,1069.16,217.8835,0,18000,0,0,100,0),
(@PATH,2,1530.8,1100.64,216.442,0,18000,0,0,100,0);
-- 0x2030A45AA029B1000029850000AEC493 .go xyz 1554.5 1069.16 217.8835

-- Pathing for  Entry: 42692 'TDB FORMAT' 
SET @NPC := 340732;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1585.593,`position_y`=1096.939,`position_z`=216.8126 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1585.593,1096.939,216.8126,0,0,0,0,100,0),
(@PATH,2,1593.496,1103.934,216.6328,0,0,0,0,100,0),
(@PATH,3,1593.496,1103.934,216.6328,0.549201,500,0,0,100,0);
-- 0x2030A45AA029B10000298500012EC493 .go xyz 1585.593 1096.939 216.8126
