UPDATE `creature` SET `MovementType`= 1, `spawndist`= 3 WHERE `guid` IN (277586, 277661, 277662, 277675, 277684, 277693, 277723, 277724, 277725, 277747, 278790, 283092, 284811, 284828, 284838, 284926, 284927, 285182, 285199, 285201, 286515, 286550, 286555, 294901, 294903, 294958, 294991, 295025, 295030, 295032, 295044, 295119, 295161, 314542, 314572, 335961);

-- Pathing for  Entry: 52327 'TDB FORMAT' 
SET @NPC := 277589;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11560.63,`position_y`=-1569.146,`position_z`=52.64712 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11560.63,-1569.146,52.64712,0,0,0,0,100,0),
(@PATH,2,-11561.92,-1580.408,52.64711,0,0,0,0,100,0),
(@PATH,3,-11561.19,-1596.196,52.64511,0,0,0,0,100,0),
(@PATH,4,-11561.92,-1580.408,52.64711,0,0,0,0,100,0),
(@PATH,5,-11545.04,-1568.865,52.64732,0,0,0,0,100,0);
-- 0x20307C6B603319C0002A550000CF0634 .go xyz -11560.63 -1569.146 52.64712

DELETE FROM `creature_formations` WHERE `leaderGUID`= 277589;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(277589, 277589, 0, 0, 515, 0, 0),
(277589, 271428, 2, 45, 515, 0, 0),
(277589, 277587, 2, 315, 515, 0, 0);

-- Pathing for  Entry: 52327 'TDB FORMAT' 
SET @NPC := 334732;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11509.5,`position_y`=-1667.62,`position_z`=74.42554 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11509.5,-1667.62,74.42554,0,0,0,0,100,0),
(@PATH,2,-11510.87,-1653.208,74.42554,0,0,0,0,100,0);
-- 0x20307C6B603319C0002A550001CF0633 .go xyz -11509.5 -1667.62 74.42554

-- Pathing for  Entry: 52327 'TDB FORMAT' 
SET @NPC := 318484;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11531.26,`position_y`=-1621.366,`position_z`=63.55652 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11531.26,-1621.366,63.55652,0,0,0,0,100,0),
(@PATH,2,-11531.53,-1615.422,63.55652,0,0,0,0,100,0),
(@PATH,3,-11531.77,-1608.391,63.55652,0,0,0,0,100,0),
(@PATH,4,-11532.21,-1598.382,63.55652,0,0,0,0,100,0),
(@PATH,5,-11531.77,-1608.391,63.55652,0,0,0,0,100,0),
(@PATH,6,-11531.53,-1615.422,63.55652,0,0,0,0,100,0),
(@PATH,7,-11531.26,-1621.366,63.55652,0,0,0,0,100,0),
(@PATH,8,-11531.04,-1627.219,63.55653,0,0,0,0,100,0);
-- 0x20307C6B603319C0002A550001CF0635 .go xyz -11531.26 -1621.366 63.55652

DELETE FROM `creature_formations` WHERE `leaderGUID`= 318484;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(318484, 318484, 0, 0, 515, 0, 0),
(318484, 318634, 2, 45, 515, 0, 0),
(318484, 262601, 2, 315, 515, 0, 0);

-- Pathing for  Entry: 52325 'TDB FORMAT' 
SET @NPC := 277605;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11560.47,`position_y`=-1658.661,`position_z`=52.64637 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11560.47,-1658.661,52.64637,0,0,0,0,100,0),
(@PATH,2,-11559.21,-1672.903,52.64781,0,0,0,0,100,0),
(@PATH,3,-11539.56,-1672.285,52.64723,0,0,0,0,100,0),
(@PATH,4,-11559.21,-1672.903,52.64781,0,0,0,0,100,0),
(@PATH,5,-11560.47,-1658.661,52.64637,0,0,0,0,100,0),
(@PATH,6,-11539.56,-1672.285,52.64723,0,0,0,0,100,0),
(@PATH,7,-11539.56,-1672.285,52.64723,0,0,0,0,100,0),
(@PATH,8,-11539.56,-1672.285,52.64723,0,0,0,0,100,0),
(@PATH,9,-11559.21,-1672.903,52.64781,0,0,0,0,100,0),
(@PATH,10,-11560.47,-1658.661,52.64637,0,0,0,0,100,0),
(@PATH,11,-11560.2,-1645.477,52.64478,0,0,0,0,100,0);
-- 0x20307C6B60331940002A5500014F0635 .go xyz -11560.47 -1658.661 52.64637

DELETE FROM `creature_formations` WHERE `leaderGUID`= 277605;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(277605, 277605, 0, 0, 515, 0, 0),
(277605, 277612, 2, 45, 515, 0, 0),
(277605, 277606, 2, 315, 515, 0, 0);

-- Pathing for  Entry: 52434 'TDB FORMAT' 
SET @NPC := 277709;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-11598.25,`position_y`=-1824.446,`position_z`=56.60503, `spawntimesecs`= 10 WHERE `guid`=@NPC;
SET @NPC := 52434;
SET @PATH := @NPC * 10;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH,1,-11598.25,-1824.446,56.60503),
(@PATH,2,-11592.29,-1823.34,54.52526),
(@PATH,3,-11588.61,-1825.207,52.89182),
(@PATH,4,-11586.43,-1830.208,51.04684),
(@PATH,5,-11587.81,-1834.25,49.93464),
(@PATH,6,-11592.27,-1836.823,47.78715),
(@PATH,7,-11603.06,-1838.774,43.35886),
(@PATH,8,-11609.89,-1832.519,43.35886),
(@PATH,9,-11626.91,-1836.401,43.35887),
(@PATH,10,-11655.79,-1841.399,40.56507),
(@PATH,11,-11669.11,-1844.938,40.56508),
(@PATH,12,-11682,-1849.417,40.56508),
(@PATH,13,-11696.74,-1851.085,40.56508),
(@PATH,14,-11707.73,-1850.113,40.57219),
(@PATH,15,-11716.26,-1854.286,40.64909),
(@PATH,16,-11716.05,-1871.411,45.80536),
(@PATH,17,-11716.74,-1887.028,51.9267),
(@PATH,18,-11716,-1905.627,55.7054),
(@PATH,19,-11713.54,-1915.406,55.8304),
(@PATH,20,-11707.68,-1927.245,55.8304),
(@PATH,21,-11695.32,-1917.557,55.84901),
(@PATH,22,-11682.38,-1909.868,67.25593),
(@PATH,23,-11667.4,-1901.021,77.27689),
(@PATH,24,-11658.39,-1896.254,77.27689),
(@PATH,25,-11658.39,-1896.254,77.27689);
-- 0x20307C6B60333480002A5500004F0AD7 .go xyz -11598.25 -1824.446 56.60503

-- Creature Gurubashi Villager 52434 SAI
SET @ENTRY := 52434;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -277709;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 53, 0, 524340, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Start path #524340, walk, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 116, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Sets corpse delay of Self to 20s // "),
(@ENTRY, 0, 2, 0, 40, 0, 100, 0, 25, 524340, 0, 0, 11, 97013, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 25 of path 524340 reached - Self: Cast spell 97013 on Self // ");

DELETE FROM `creature` WHERE `guid` IN (277729, 277730, 277708, 277707);

-- Pathing for  Entry: 52434 'TDB FORMAT' 
SET @NPC := 280067;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11792.7,`position_y`=-1850.37,`position_z`=46.13023 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,2,-11792.28,-1838.214,49.01426,0,0,0,0,100,0),
(@PATH,3,-11794.69,-1832.422,50.82394,0,0,0,0,100,0),
(@PATH,4,-11792.38,-1837.965,48.92515,0,0,0,0,100,0),
(@PATH,5,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,6,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,7,-11762.38,-1849.917,40.99553,0,0,0,0,100,0),
(@PATH,8,-11745.71,-1849.571,40.49455,0,0,0,0,100,0),
(@PATH,9,-11762.38,-1849.917,40.99553,0,0,0,0,100,0),
(@PATH,10,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,11,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,12,-11792.28,-1838.214,49.01426,0,0,0,0,100,0),
(@PATH,13,-11794.69,-1832.422,50.82394,0,0,0,0,100,0),
(@PATH,14,-11792.38,-1837.965,48.92515,0,0,0,0,100,0),
(@PATH,15,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,16,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,17,-11762.38,-1849.917,40.99553,0,0,0,0,100,0),
(@PATH,18,-11745.71,-1849.571,40.49455,0,0,0,0,100,0),
(@PATH,19,-11728.33,-1851.554,40.44621,0,0,0,0,100,0),
(@PATH,20,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,21,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,22,-11792.28,-1838.214,49.01426,0,0,0,0,100,0),
(@PATH,23,-11794.69,-1832.422,50.82394,0,0,0,0,100,0),
(@PATH,24,-11792.38,-1837.965,48.92515,0,0,0,0,100,0),
(@PATH,25,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,26,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,27,-11792.7,-1850.37,46.13023,0,0,0,0,100,0),
(@PATH,28,-11773.94,-1850.642,42.78111,0,0,0,0,100,0),
(@PATH,29,-11762.38,-1849.917,40.99553,0,0,0,0,100,0),
(@PATH,30,-11745.71,-1849.571,40.49455,0,0,0,0,100,0),
(@PATH,31,-11728.33,-1851.554,40.44621,0,0,0,0,100,0),
(@PATH,32,-11714.27,-1849.641,40.59148,0,0,0,0,100,0),
(@PATH,33,-11705.3,-1845.773,40.64177,0,0,0,0,100,0),
(@PATH,34,-11700.34,-1836.976,42.82219,0,0,0,0,100,0),
(@PATH,35,-11696.97,-1828.477,41.02749,0,0,0,0,100,0),
(@PATH,36,-11699.3,-1821.571,41.30874,0,0,0,0,100,0),
(@PATH,37,-11696.97,-1828.477,41.02749,0,0,0,0,100,0),
(@PATH,38,-11700.34,-1836.976,42.82219,0,0,0,0,100,0),
(@PATH,39,-11705.3,-1845.773,40.64177,0,0,0,0,100,0),
(@PATH,40,-11714.27,-1849.641,40.59148,0,0,0,0,100,0),
(@PATH,41,-11728.33,-1851.554,40.44621,0,0,0,0,100,0),
(@PATH,42,-11745.71,-1849.571,40.49455,0,0,0,0,100,0),
(@PATH,43,-11762.38,-1849.917,40.99553,0,0,0,0,100,0),
(@PATH,44,-11773.94,-1850.642,42.78111,0,0,0,0,100,0);
-- 0x20307C6B60333480002A5500024F0634 .go xyz -11792.7 -1850.37 46.13023

-- Pathing for  Entry: 52434 'TDB FORMAT' 
SET @NPC := 277681;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11593.16,`position_y`=-1759.618,`position_z`=40.46074 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11593.16,-1759.618,40.46074,0,0,0,0,100,0),
(@PATH,2,-11592.75,-1753.629,39.11918,0,0,0,0,100,0),
(@PATH,3,-11594.77,-1749.811,39.20439,0,0,0,0,100,0),
(@PATH,4,-11601.35,-1750.111,38.95782,0,0,0,0,100,0),
(@PATH,5,-11610.35,-1749.043,38.78375,0,0,0,0,100,0),
(@PATH,6,-11610.97,-1737.639,38.78375,0,0,0,0,100,0),
(@PATH,7,-11611.73,-1729.625,38.80264,0,0,0,0,100,0),
(@PATH,8,-11612.24,-1720.792,38.80264,0,0,0,0,100,0),
(@PATH,9,-11610.35,-1749.043,38.78375,0,0,0,0,100,0),
(@PATH,10,-11610.97,-1737.639,38.78375,0,0,0,0,100,0),
(@PATH,11,-11611.73,-1729.625,38.80264,0,0,0,0,100,0),
(@PATH,12,-11612.24,-1720.792,38.80264,0,0,0,0,100,0),
(@PATH,13,-11606.85,-1715.962,39.28262,0,0,0,0,100,0),
(@PATH,14,-11611.73,-1729.625,38.80264,0,0,0,0,100,0),
(@PATH,15,-11610.97,-1737.639,38.78375,0,0,0,0,100,0),
(@PATH,16,-11610.35,-1749.043,38.78375,0,0,0,0,100,0),
(@PATH,17,-11601.35,-1750.111,38.95782,0,0,0,0,100,0),
(@PATH,18,-11595.85,-1766.671,43.30542,0,0,0,0,100,0),
(@PATH,19,-11591.87,-1759.602,40.2957,0,0,0,0,100,0),
(@PATH,20,-11592.68,-1751.063,39.11918,0,0,0,0,100,0),
(@PATH,21,-11587.63,-1748.649,38.92192,0,0,0,0,100,0),
(@PATH,22,-11581.95,-1745.391,38.88163,0,0,0,0,100,0),
(@PATH,23,-11582.81,-1740.474,39.03862,0,0,0,0,100,0),
(@PATH,24,-11585.81,-1740.417,39.60356,0,0,0,0,100,0),
(@PATH,25,-11593.25,-1737.531,42.26767,0,0,0,0,100,0),
(@PATH,26,-11584.84,-1740.651,39.48735,0,0,0,0,100,0),
(@PATH,27,-11582.18,-1746.667,38.9185,0,0,0,0,100,0),
(@PATH,28,-11578.7,-1749.524,38.74418,0,0,0,0,100,0),
(@PATH,29,-11574.66,-1746.063,38.90263,0,0,0,0,100,0),
(@PATH,30,-11578.7,-1749.524,38.74418,0,0,0,0,100,0),
(@PATH,31,-11582.18,-1746.667,38.9185,0,0,0,0,100,0),
(@PATH,32,-11584.84,-1740.651,39.48735,0,0,0,0,100,0),
(@PATH,33,-11593.25,-1737.531,42.26767,0,0,0,0,100,0),
(@PATH,34,-11585.94,-1740.104,39.74418,0,0,0,0,100,0),
(@PATH,35,-11582.81,-1740.474,39.03862,0,0,0,0,100,0),
(@PATH,36,-11581.95,-1745.391,38.88163,0,0,0,0,100,0),
(@PATH,37,-11587.63,-1748.649,38.92192,0,0,0,0,100,0),
(@PATH,38,-11592.68,-1751.063,39.11918,0,0,0,0,100,0),
(@PATH,39,-11591.87,-1759.602,40.2957,0,0,0,0,100,0),
(@PATH,40,-11595.81,-1766.735,43.30572,0,0,0,0,100,0);
-- 0x20307C6B60333480002A5500034F0633 .go xyz -11593.16 -1759.618 40.46074

-- Pathing for  Entry: 52434 'TDB FORMAT' 
SET @NPC := 284817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11809.63,`position_y`=-1847.7,`position_z`=48.36638 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11809.63,-1847.7,48.36638,0,0,0,0,100,0),
(@PATH,2,-11817.34,-1839.207,49.89934,0,0,0,0,100,0),
(@PATH,3,-11819.79,-1826.575,50.64906,0,0,0,0,100,0),
(@PATH,4,-11826.83,-1818.254,51.02406,0,0,0,0,100,0),
(@PATH,5,-11833.74,-1813.929,51.00972,0,0,0,0,100,0),
(@PATH,6,-11826.83,-1818.254,51.02406,0,0,0,0,100,0),
(@PATH,7,-11819.79,-1826.575,50.64906,0,0,0,0,100,0),
(@PATH,8,-11817.34,-1839.207,49.89934,0,0,0,0,100,0),
(@PATH,9,-11809.63,-1847.7,48.36638,0,0,0,0,100,0),
(@PATH,10,-11803.1,-1851.934,47.28825,0,0,0,0,100,0),
(@PATH,11,-11805.33,-1872.965,45.64853,0,0,0,0,100,0),
(@PATH,12,-11801.61,-1884.802,45.64022,0,0,0,0,100,0),
(@PATH,13,-11802.83,-1890.318,46.84408,0,0,0,0,100,0),
(@PATH,14,-11797.03,-1895.45,51.14334,0,0,0,0,100,0),
(@PATH,15,-11803.12,-1889.584,46.76522,0,0,0,0,100,0),
(@PATH,16,-11799.43,-1883.618,45.77818,0,0,0,0,100,0),
(@PATH,17,-11793.2,-1884.122,46.58579,0,0,0,0,100,0),
(@PATH,18,-11799.43,-1883.618,45.77818,0,0,0,0,100,0),
(@PATH,19,-11803.86,-1889.366,46.73935,0,0,0,0,100,0),
(@PATH,20,-11797.03,-1895.45,51.14334,0,0,0,0,100,0),
(@PATH,21,-11803.12,-1890.625,47.14022,0,0,0,0,100,0),
(@PATH,22,-11801.61,-1884.802,45.64022,0,0,0,0,100,0),
(@PATH,23,-11805.33,-1872.965,45.64853,0,0,0,0,100,0),
(@PATH,24,-11803.1,-1851.934,47.28825,0,0,0,0,100,0);
-- 0x20307C6B60333480002A550004CF0635 .go xyz -11809.63 -1847.7 48.36638

DELETE FROM `creature_addon` WHERE `guid` IN (280015, 280070, 280071, 283089, 283087, 277748);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(280015, 0, 0, 0, '84186'),
(280070, 0, 0, 0, '84186'),
(280071, 0, 0, 0, '84186'),
(283089, 0, 0, 0, '84186'),
(283087, 0, 0, 0, '84186'),
(277748, 0, 0, 0, '84186');

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 5 WHERE `guid` IN (295354, 295356, 312812, 312813, 312867, 312886, 313084, 320521, 335468);

-- Venomtip Needler
UPDATE `creature_template` SET `difficulty_entry_1`= 52518 WHERE `entry`= 52379;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `lootid`= 52379, `DamageModifier`= 25, `BaseVariance`= 0.5, `InhabitType`= 4 WHERE `entry`= 52518;
-- Florawing Needler
UPDATE `creature_template` SET `DamageModifier`= 25, `BaseVariance`= 0.5 WHERE `entry`= 52376;
-- Gurubashi Worker
UPDATE `creature_template` SET `DamageModifier`= 5, `BaseVariance`= 0.5 WHERE `entry`= 52089;
-- Venomancer Mauri
UPDATE `creature_template` SET `difficulty_entry_1`= 52519 WHERE `entry`= 52380;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `unit_class`= 2, `unit_flags`= 64, `lootid`= 52380, `DamageModifier`= 120, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 617299839 WHERE `entry`= 52519;
-- Venomancer T'Kulu
UPDATE `creature_template` SET `difficulty_entry_1`= 52520 WHERE `entry`= 52381;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `unit_class`= 2, `unit_flags`= 64, `lootid`= 52381, `DamageModifier`= 120, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 617299839 WHERE `entry`= 52520;
-- Venomguard Destroyer
UPDATE `creature_template` SET `difficulty_entry_1`= 52521, `ScriptName`= 'npc_zulgurub_venomguard_destroyer' WHERE `entry`= 52311;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `unit_flags`= 64, `lootid`= 52311, `DamageModifier`= 120, `BaseVariance`= 0.5, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 650854271 WHERE `entry`= 52521;
-- Venomtooth
UPDATE `creature_template` SET `DamageModifier`= 5, `BaseVariance`= 0.5 WHERE `entry`= 52402;
-- Pool of Acrid Tears
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130 WHERE `entry`= 52320;
-- Tiki Lord Mu'Loa
UPDATE `creature_template` SET `ScriptName`= 'npc_zulgurub_tiki_lord_mu_loa', `difficulty_entry_1`= 52522, `flags_extra`= 128 | 1073741824 WHERE `entry`= 52340;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `unit_flags`= 64, `lootid`= 52340, `flags_extra`= 128 | 1073741824, `mingold`= 10000, `maxgold`= 15000, `mechanic_immune_mask`= 617299839 WHERE `entry`= 52522;
-- Tiki Lord Zim'Wae
UPDATE `creature_template` SET `ScriptName`= 'npc_zulgurub_tiki_lord_zim_wae' WHERE `entry`= 52362;
-- Zulian Gnasher
UPDATE `creature_template` SET `difficulty_entry_1`= 52511 WHERE `entry`= 52413;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `speed_run`= 0.992063, `unit_flags`= 32832, `lootid`= 52413, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52511;
-- Zandalari Juggernaut
UPDATE `creature_template` SET `difficulty_entry_1`= 52957 WHERE `entry`= 52956;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_flags`= 32832, `lootid`= 52956, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52957;
-- Gurubashi Warmonger
UPDATE `creature_template` SET `difficulty_entry_1`= 52607 WHERE `entry`= 52606;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_flags`= 32832, `lootid`= 52606, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52607;
-- Gurubashi Cauldron Mixer
UPDATE `creature_template` SET `difficulty_entry_1`= 52610 WHERE `entry`= 52076;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52076, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52610;
-- Gurubashi Cauldron Mixer
UPDATE `creature_template` SET `difficulty_entry_1`= 52611 WHERE `entry`= 52081;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52081, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52611;
-- Gurubashi Cauldron Mixer
UPDATE `creature_template` SET `difficulty_entry_1`= 52612 WHERE `entry`= 52082;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52082, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52612;
-- Gurubashi Cauldron Mixer
UPDATE `creature_template` SET `difficulty_entry_1`= 52613 WHERE `entry`= 52088;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52088, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52613;
-- Zandalari Archon
UPDATE `creature_template` SET `difficulty_entry_1`= 52963 WHERE `entry`= 52962;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52962, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52963;
-- Zandalari Archon
UPDATE `creature_template` SET `difficulty_entry_1`= 52969 WHERE `entry`= 52968;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 1, `unit_flags`= 32832, `lootid`= 52968, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52969;
-- Zandalari Bloodslayer
UPDATE `creature_template` SET `difficulty_entry_1`= 52961 WHERE `entry`= 52960;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `lootid`= 52960, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52961;
-- Zandalari Bloodslayer
UPDATE `creature_template` SET `difficulty_entry_1`= 52971 WHERE `entry`= 52970;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `lootid`= 52970, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52971;
-- Zandalari Hierophant
UPDATE `creature_template` SET `difficulty_entry_1`= 52959 WHERE `entry`= 52958;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 2, `unit_flags`= 32832, `lootid`= 52958, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52959;
-- Zandalari Hierophant
UPDATE `creature_template` SET `difficulty_entry_1`= 52973 WHERE `entry`= 52972;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 1, `unit_flags`= 32832, `lootid`= 52972, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52973;
-- Zandalari Juggernaut
UPDATE `creature_template` SET `difficulty_entry_1`= 52975 WHERE `entry`= 52974;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_flags`= 32832, `lootid`= 52975, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52975;
-- Gurubashi Soul-Eater
UPDATE `creature_template` SET `difficulty_entry_1`= 52601 WHERE `entry`= 52598;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.42857, `unit_class`= 8, `unit_flags`= 32832, `lootid`= 52598, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52601;
-- Gurubashi Bloodrager
UPDATE `creature_template` SET `difficulty_entry_1`= 52614 WHERE `entry`= 52079;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.38571, `unit_flags`= 32832, `lootid`= 52079, `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 52614;
-- Ohgan
UPDATE `creature_template` SET `difficulty_entry_1`= 52987, `flags_extra`= 1073741824 WHERE `entry`= 52157;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 14, `BaseAttackTime`= 1500, `unit_flags`= 32832, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271, `flags_extra`= 1073741824 WHERE `entry`= 52987;

DELETE FROM `creature_formations` WHERE `leaderGUID`= 294990;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(294990, 294990, 0, 0, 3, 0, 0),
(294990, 294989, 0, 0, 3, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (52320, 52518, 52522);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(52320, 0, 1, '96756'),
(52518, 0, 1, '96912'),
(52522, 0, 1, '96798');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_venoxis_pool_of_acrid_tears' AND `spell_id`= 96756;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96756, 'spell_venoxis_pool_of_acrid_tears');
