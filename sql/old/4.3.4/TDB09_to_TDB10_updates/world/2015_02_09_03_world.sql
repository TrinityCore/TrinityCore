--
UPDATE `creature` SET `position_x`=1772.803833, `position_y`=848.654846, `position_z`=123.192604, `orientation`=1.649258 WHERE  `guid`=127067;
UPDATE `creature` SET `position_x`=1772.699585, `position_y`=852.786560, `position_z`=123.192734, `orientation`=4.675874 WHERE  `guid`=127068;

DELETE FROM `creature_addon` WHERE `guid` IN (127051, 127062, 127065, 127059, 127047);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127051, 0, 0, 0, 1, 4, ''),
(127062, 0, 0, 0, 1, 4, ''),
(127065, 0, 0, 0, 1, 4, ''),
(127059, 0, 0, 0, 1, 4, ''),
(127047, 0, 0, 0, 1, 4, '');

DELETE FROM `creature_addon` WHERE `guid` IN (127067, 127068);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127067, 0, 0, 0, 1, 36, ''),
(127068, 0, 0, 0, 1, 36, '');

UPDATE `creature_addon` SET `emote`=20 WHERE  `guid`=127043;

/* emotes for these creatures. http://pokit.org/get/?2ee8b0b514852adc528b2543f704fdcd.jpg*/

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127079;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1580.776,`position_y`=726.0986,`position_z`=143.0329 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1580.776,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,2,1601.526,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,3,1580.776,726.0986,143.0329,0,0,0,0,100,0),
(@PATH,4,1601.526,726.0986,143.0329,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE0002D7B1EE .go 1580.776 726.0986 143.0329

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127077;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1634.252,`position_y`=750.1481,`position_z`=143.0402 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1634.252,750.1481,143.0402,0,0,0,0,100,0),
(@PATH,2,1645.534,749.2593,143.062,0,0,0,0,100,0),
(@PATH,3,1646.846,740.0786,143.036,0,0,0,0,100,0),
(@PATH,4,1643.028,738.3261,143.0428,0,0,0,0,100,0),
(@PATH,5,1634.346,729.3132,143.0253,0,0,0,0,100,0),
(@PATH,6,1629.24,728.4056,143.036,0,0,0,0,100,0),
(@PATH,7,1625.434,724.1005,143.033,0,0,0,0,100,0),
(@PATH,8,1625.066,724.9523,143.0346,0,0,0,0,100,0),
(@PATH,9,1633.39,728.2556,143.0207,0,0,0,0,100,0),
(@PATH,10,1634.352,731.7579,143.036,0,0,0,0,100,0),
(@PATH,11,1642.503,738.0968,143.036,0,0,0,0,100,0),
(@PATH,12,1646.744,748.6193,143.0608,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE0003D7B1EE .go 1634.252 750.1481 143.0402

-- Pathing for  Entry: 29830 'TDB FORMAT' 
SET @NPC := 127078;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1624.936,`position_y`=762.2312,`position_z`=143.0362 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1624.936,762.2312,143.0362,0,0,0,0,100,0),
(@PATH,2,1624.857,762.3463,143.0362,0,0,0,0,100,0),
(@PATH,3,1616.904,760.4952,143.0778,0,0,0,0,100,0),
(@PATH,4,1616.059,757.1263,143.036,0,0,0,0,100,0),
(@PATH,5,1615.883,751.8171,143.036,0,0,0,0,100,0),
(@PATH,6,1612.587,742.8907,143.036,0,0,0,0,100,0),
(@PATH,7,1615.973,735.1326,143.036,0,0,0,0,100,0),
(@PATH,8,1616.567,728.8411,143.0389,0,0,0,0,100,0),
(@PATH,9,1616.565,728.8934,143.0389,0,0,0,0,100,0),
(@PATH,10,1616.015,735.0688,143.036,0,0,0,0,100,0),
(@PATH,11,1612.599,741.9441,143.036,0,0,0,0,100,0),
(@PATH,12,1612.643,745.9359,143.036,0,0,0,0,100,0),
(@PATH,13,1615.984,759.0609,143.0375,0,0,0,0,100,0),
(@PATH,14,1620.861,760.4977,143.036,0,0,0,0,100,0),
(@PATH,15,1624.961,762.2328,143.0362,0,0,0,0,100,0),
(@PATH,16,1624.857,762.3463,143.0362,0,0,0,0,100,0),
(@PATH,17,1616.904,760.5043,143.0776,0,0,0,0,100,0);
-- 0x1C3AE04B801D2180006CCE000357B1EE .go 1624.936 762.2312 143.0362

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid` IN (29774, 29820) AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Pathing for  Entry: 29774 'TDB FORMAT' 
SET @NPC := 127023;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1642.346,`position_y`=653.1481,`position_z`=125.2523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1642.346,653.1481,125.2523,0,0,0,0,100,0),
(@PATH,2,1639.856,642.3232,125.6559,0,0,0,0,100,0),
(@PATH,3,1642.258,637.7573,126.032,0,0,0,0,100,0),
(@PATH,4,1647.147,632.4925,126.6323,0,0,0,0,100,0),
(@PATH,5,1657.781,625.1252,128.0753,0,0,0,0,100,0),
(@PATH,6,1664.838,624.4281,127.6226,0,0,0,0,100,0),
(@PATH,7,1669.714,625.9705,127.4224,0,0,0,0,100,0),
(@PATH,8,1674.736,633.4069,127.3273,0,0,0,0,100,0),
(@PATH,9,1673.877,644.5715,126.3829,0,0,0,0,100,0),
(@PATH,10,1668.756,649.8423,126.1618,0,0,0,0,100,0),
(@PATH,11,1662.11,654.2892,125.6076,0,0,0,0,100,0),
(@PATH,12,1655.857,656.4763,125.5904,0,0,0,0,100,0),
(@PATH,13,1645.618,656.3919,125.2844,0,0,0,0,100,0),
(@PATH,14,1642.373,653.2665,125.2903,0,0,0,0,100,0);
-- 0x1C3AE04B801D1380006CCE0000D7B1EE .go 1642.346 653.1481 125.2523

DELETE FROM `creature_formations` WHERE `leaderGUID`=127023;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127023, 127023, 0, 0, 2, 0, 0),
(127023, 127013, 4, 50, 2, 0, 0),
(127023, 127024, 4, 310, 2, 0, 0);

-- Pathing for  Entry: 29829 'TDB FORMAT' 
SET @NPC := 127069;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1592.818,`position_y`=817.3067,`position_z`=149.783 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1592.818,817.3067,149.783,0,0,0,0,100,0),
(@PATH,2,1601.493,805.8055,146.3105,0,0,0,0,100,0),
(@PATH,3,1609.685,802.7231,145.2017,0,0,0,0,100,0),
(@PATH,4,1623.651,794.6301,143.8499,0,0,0,0,100,0),
(@PATH,5,1615.21,801.1007,144.687,0,0,0,0,100,0),
(@PATH,6,1605.104,803.2402,145.5161,0,0,0,0,100,0),
(@PATH,7,1597.137,810.431,147.7381,0,0,0,0,100,0),
(@PATH,8,1591.998,822.5156,150.5477,0,0,0,0,100,0),
(@PATH,9,1586.166,840.6243,153.7294,0,0,0,0,100,0),
(@PATH,10,1584.692,843.8578,154.2673,0,0,0,0,100,0),
(@PATH,11,1584.178,844.4227,154.4869,0,0,0,0,100,0),
(@PATH,12,1590.102,830.2843,152.1621,0,0,0,0,100,0);
-- 0x1C3AE04B801D2140006CCE0000D7B1EE .go 1592.818 817.3067 149.783

-- Pathing for  Entry: 29829 'TDB FORMAT' 
SET @NPC := 127070;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1706.755,`position_y`=857.1785,`position_z`=129.9813 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1706.755,857.1785,129.9813,0,0,0,0,100,0),
(@PATH,2,1707.281,867.1033,130.2534,0,0,0,0,100,0),
(@PATH,3,1704.177,879.5166,130.7884,0,0,0,0,100,0),
(@PATH,4,1691.342,892.488,132.9258,0,0,0,0,100,0),
(@PATH,5,1679.412,891.944,134.244,0,0,0,0,100,0),
(@PATH,6,1668.286,882.3208,137.746,0,0,0,0,100,0),
(@PATH,7,1673.63,888.4031,136.1639,0,0,0,0,100,0),
(@PATH,8,1687.955,893.6246,133.4256,0,0,0,0,100,0),
(@PATH,9,1701.138,885.8834,131.8191,0,0,0,0,100,0),
(@PATH,10,1706.935,871.8005,130.679,0,0,0,0,100,0);
-- 0x1C3AE04B801D2140006CCE000057B1EE .go 1706.755 857.1785 129.9813

-- Pathing for  Entry: 29820 'TDB FORMAT' 
SET @NPC := 127054;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1627.05,`position_y`=895.2917,`position_z`=145.9627 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1627.05,895.2917,145.9627,0,0,0,0,100,0),
(@PATH,2,1641.819,895.4995,144.4391,0,0,0,0,100,0),
(@PATH,3,1646.381,886.3206,142.0332,0,0,0,0,100,0),
(@PATH,4,1648.376,877.1378,140.8607,0,0,0,0,100,0),
(@PATH,5,1651.261,870.6509,139.9442,0,0,0,0,100,0),
(@PATH,6,1648.879,874.7926,140.348,0,0,0,0,100,0),
(@PATH,7,1648.431,879.759,140.6906,0,0,0,0,100,0),
(@PATH,8,1643.23,894.2725,143.7524,0,0,0,0,100,0),
(@PATH,9,1633.633,896.613,144.9795,0,0,0,0,100,0),
(@PATH,10,1628.168,895.5144,145.8911,0,0,0,0,100,0),
(@PATH,11,1608.678,886.468,148.1761,0,0,0,0,100,0),
(@PATH,12,1600.244,880.922,149.9891,0,0,0,0,100,0),
(@PATH,13,1583.596,870.7088,152.9289,0,0,0,0,100,0),
(@PATH,14,1593.538,876.7352,151.3219,0,0,0,0,100,0),
(@PATH,15,1606.508,885.0313,148.7535,0,0,0,0,100,0),
(@PATH,16,1616.299,891.1467,147.5494,0,0,0,0,100,0),
(@PATH,17,1627.23,895.3035,145.926,0,0,0,0,100,0),
(@PATH,18,1641.784,895.3555,144.6143,0,0,0,0,100,0);
-- 0x1C3AE04B801D1F00006CCE000257B1EE .go 1627.05 895.2917 145.9627

DELETE FROM `creature_formations` WHERE `leaderGUID`=127054;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(127054, 127054, 0, 0, 2, 0, 0),
(127054, 127064, 4, 90, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (127057, 127053, 127063, 127052, 127060, 127055, 127066, 127048, 127049, 127061, 127056, 127050);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(127057, 0, 0, 0, 1, 1, ''),
(127053, 0, 0, 0, 1, 1, ''),
(127063, 0, 0, 0, 1, 1, ''),
(127052, 0, 0, 0, 1, 1, ''),
(127060, 0, 0, 0, 1, 1, ''),
(127055, 0, 0, 0, 1, 1, ''),
(127066, 0, 0, 0, 1, 1, ''),
(127048, 0, 0, 0, 1, 1, ''),
(127049, 0, 0, 0, 1, 1, ''),
(127061, 0, 0, 0, 1, 1, ''),
(127056, 0, 0, 0, 1, 1, ''),
(127050, 0, 0, 0, 1, 1, '');
