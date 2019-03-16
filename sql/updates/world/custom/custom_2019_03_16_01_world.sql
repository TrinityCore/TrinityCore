-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=154.2913,`position_y`=1515.59,`position_z`=21.2338 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,154.2913,1515.59,21.2338,0,0,1,0,100,0),
(@PATH,2,128.5005,1528.975,21.23378,0,0,1,0,100,0),
(@PATH,3,119.3157,1541.36,26.99657,0,0,1,0,100,0),
(@PATH,4,113.1714,1555.668,35.92979,0,0,1,0,100,0),
(@PATH,5,114.0046,1568.094,43.13112,0,0,1,0,100,0),
(@PATH,6,116.8414,1588.832,43.4869,0,0,1,0,100,0),
(@PATH,7,120.7421,1607.12,43.51799,0,0,1,0,100,0),
(@PATH,8,120.6979,1635.587,42.47051,0,0,1,0,100,0);
-- 0x2041004700175440001C8700007ECDE6 .go xyz 154.2913 1515.59 21.2338

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291947;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=89.21932,`position_y`=1529.004,`position_z`=21.23377 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,89.21932,1529.004,21.23377,0,0,1,0,100,0),
(@PATH,2,120.3557,1532.734,21.41358,0,0,1,0,100,0),
(@PATH,3,128.1771,1544.955,29.31073,0,0,1,0,100,0),
(@PATH,4,121.786,1568.195,43.16284,0,0,1,0,100,0),
(@PATH,5,118.9054,1576.203,43.53218,0,0,1,0,100,0),
(@PATH,6,115.8393,1595.472,43.42813,0,0,1,0,100,0),
(@PATH,7,121.0499,1606.704,43.51988,0,0,1,0,100,0),
(@PATH,8,120.7738,1632.364,42.68732,0,0,1,0,100,0);
-- 0x2041004700175440001C870000FECDE6 .go xyz 89.21932 1529.004 21.23377

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291946;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=166.3321,`position_y`=1526.035,`position_z`=21.23378 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,166.3321,1526.035,21.23378,0,0,1,0,100,0),
(@PATH,2,130.1579,1533.549,21.91744,0,0,1,0,100,0),
(@PATH,3,135.2021,1550.365,32.36158,0,0,1,0,100,0),
(@PATH,4,133.7431,1567.71,42.97315,0,0,1,0,100,0),
(@PATH,5,128.5429,1587.893,43.57858,0,0,1,0,100,0),
(@PATH,6,123.404,1609.29,43.50814,0,0,1,0,100,0),
(@PATH,7,120.999,1636.745,42.37431,3.544869,0,1,0,100,0);
-- 0x2041004700175440001C8700017ECDE6 .go xyz 166.3321 1526.035 21.23378


-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291944;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=157.6418,`position_y`=1527.899,`position_z`=21.23381 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,157.6418,1527.899,21.23381,0,0,1,0,100,0),
(@PATH,2,135.0565,1533.453,21.84341,0,0,1,0,100,0),
(@PATH,3,133.4965,1555.037,35.29915,0,0,1,0,100,0),
(@PATH,4,127.6717,1579.582,43.51157,0,0,1,0,100,0),
(@PATH,5,127.7423,1607.962,43.33985,0,0,1,0,100,0),
(@PATH,6,121.5374,1639.786,42.13855,0,0,1,0,100,0);
-- 0x2041004700175440001C870001FECDE6 .go xyz 157.6418 1527.899 21.23381

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291948;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=122.6295,`position_y`=1525.514,`position_z`=21.2338 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,122.6295,1525.514,21.2338,0,0,1,0,100,0),
(@PATH,2,120.9172,1568.208,43.16438,0,0,1,0,100,0),
(@PATH,3,117.4092,1582.276,43.49669,0,0,1,0,100,0),
(@PATH,4,113.9742,1604.199,43.34784,0,0,1,0,100,0),
(@PATH,5,120.0438,1640.776,42.06852,0,0,1,0,100,0);
-- 0x2041004700175440001C8700027ECDE6 .go xyz 122.6295 1525.514 21.2338

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291945;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=108.2463,`position_y`=1523.122,`position_z`=21.2338 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,108.2463,1523.122,21.2338,0,0,1,0,100,0),
(@PATH,2,112.4648,1555.267,35.64463,0,0,1,0,100,0),
(@PATH,3,119.8036,1568.642,43.40822,0,0,1,0,100,0),
(@PATH,4,126.8447,1592.178,43.53218,0,0,1,0,100,0),
(@PATH,5,128.6846,1606.297,43.25053,0,0,1,0,100,0),
(@PATH,6,121.9729,1638.072,42.23449,0,0,1,0,100,0);
-- 0x2041004700175440001C870002FECDE6 .go xyz 108.2463 1523.122 21.2338

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291943;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=130.1109,`position_y`=1525.499,`position_z`=21.23379 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,130.1109,1525.499,21.23379,0,0,1,0,100,0),
(@PATH,2,133.0854,1567.142,42.64884,0,0,1,0,100,0),
(@PATH,3,127.2359,1590.394,43.5386,0,0,1,0,100,0),
(@PATH,4,124.4366,1606.791,43.4163,0,0,1,0,100,0),
(@PATH,5,121.0056,1640.746,42.10158,0,0,1,0,100,0);
-- 0x2041004700175440001C8700037ECDE6 .go xyz 130.1109 1525.499 21.23379

-- Pathing for  Entry: 23889 'TDB FORMAT' 
SET @NPC := 291949;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=81.98914,`position_y`=1514.848,`position_z`=21.23375 WHERE `guid`=@NPC;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,81.98914,1514.848,21.23375,0,0,1,0,100,0),
(@PATH,2,120.9924,1538.065,24.86532,0,0,1,0,100,0),
(@PATH,3,130.4884,1551.527,33.26072,0,0,1,0,100,0),
(@PATH,4,128.8892,1568.421,43.33992,0,0,1,0,100,0),
(@PATH,5,126.9395,1583.673,43.48764,0,0,1,0,100,0),
(@PATH,6,121.0085,1605.67,43.4987,0,0,1,0,100,0),
(@PATH,7,120.7583,1632.894,42.65181,0,0,1,0,100,0);
-- 0x2041004700175440001C870003FECDE6 .go xyz 81.98914 1514.848 21.23375
