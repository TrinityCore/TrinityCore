-- [NPC][WotlK] Ancient Sentinel, missing spawns/paths/level 
SET @CGUID := 77855;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
DELETE FROM `creature` WHERE `id`=31797;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 31797, 571, 0, 0, '0', 0, 0, 0, 7422.168, -2048.153, 825.7407, 5.874895, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+1, 31797, 571, 0, 0, '0', 0, 0, 0, 7485.472, -2054.825, 807.2446, 5.227731, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+2, 31797, 571, 0, 0, '0', 0, 0, 0, 7442.518, -2017.241, 824.0923, 5.892366, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+3, 31797, 571, 0, 0, '0', 0, 0, 0, 7547.453, -2104.698, 786.1619, 5.84351, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+4, 31797, 571, 0, 0, '0', 0, 0, 0, 7554.138, -2071.981, 788.3517, 4.09328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+5, 31797, 571, 0, 0, '0', 0, 0, 0, 7594.692, -2129.201, 780.3125, 2.565634, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+6, 31797, 571, 0, 0, '0', 0, 0, 0, 7609.039, -2093.105, 780.6818, 3.316126, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+7, 31797, 571, 0, 0, '0', 0, 0, 0, 7649.875, -2132.675, 779.6909, 2.71671, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ancient Sentinel (Area: Loken's Bargain)
(@CGUID+8, 31797, 571, 0, 0, '0', 0, 0, 0, 7694.706, -2167.39, 785.2208, 2.792527, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Ancient Sentinel (Area: Loken's Bargain)

-- level 1 lol?
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE  `entry`=31797;

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7550.282,`position_y`=-2077.013,`position_z`=788.8428 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7550.282,-2077.013,788.8428,0,0,0,0,100,0),
(@PATH,2,7548.532,-2079.763,789.0928,0,0,0,0,100,0),
(@PATH,3,7550.624,-2077.129,788.8112,0,0,0,0,100,0),
(@PATH,4,7550.874,-2076.129,788.3112,0,0,0,0,100,0),
(@PATH,5,7551.624,-2075.379,788.8112,0,0,0,0,100,0),
(@PATH,6,7552.763,-2074.289,788.7057,0,0,0,0,100,0),
(@PATH,7,7555.013,-2071.039,788.4557,0,0,0,0,100,0),
(@PATH,8,7561.116,-2073.723,786.6885,0,0,0,0,100,0),
(@PATH,9,7569.586,-2077.436,783.9506,0,0,0,0,100,0),
(@PATH,10,7560.874,-2073.81,786.4338,0,0,0,0,100,0),
(@PATH,11,7554.636,-2071.227,788.5483,0,0,0,0,100,0),
(@PATH,12,7552.636,-2074.227,788.5483,0,0,0,0,100,0),
(@PATH,13,7551.136,-2076.227,788.0483,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D000009FED9 .go 7550.282 -2077.013 788.8428

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7448.692,`position_y`=-2059.581,`position_z`=817.574 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7448.692,-2059.581,817.574,0,0,0,0,100,0),
(@PATH,2,7466.879,-2066.882,811.9438,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D00000A0037 .go 7448.692 -2059.581 817.574

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7490.584,`position_y`=-2063.406,`position_z`=805.2521 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7490.584,-2063.406,805.2521,0,0,0,0,100,0),
(@PATH,2,7488.572,-2059.999,806.084,0,0,0,0,100,0),
(@PATH,3,7487.072,-2057.249,806.834,0,0,0,0,100,0),
(@PATH,4,7485.527,-2054.638,807.5553,0,0,0,0,100,0),
(@PATH,5,7478.113,-2051.191,811.0731,0,0,0,0,100,0),
(@PATH,6,7476.113,-2050.191,811.8231,0,0,0,0,100,0),
(@PATH,7,7468.904,-2047.126,813.8514,0,0,0,0,100,0),
(@PATH,8,7467.904,-2048.626,813.8514,0,0,0,0,100,0),
(@PATH,9,7466.904,-2050.126,813.8514,0,0,0,0,100,0),
(@PATH,10,7462.482,-2050.411,815.353,0,0,0,0,100,0),
(@PATH,11,7466.283,-2050,814.4337,0,0,0,0,100,0),
(@PATH,12,7468.378,-2047.79,814.1212,0,0,0,0,100,0),
(@PATH,13,7476.222,-2050.408,811.5497,0,0,0,0,100,0),
(@PATH,14,7478.472,-2051.408,810.7997,0,0,0,0,100,0),
(@PATH,15,7485.779,-2054.854,807.3547,0,0,0,0,100,0),
(@PATH,16,7486.779,-2057.104,806.8547,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D00000A0042 .go 7490.584 -2063.406 805.2521

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+7;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7640.099,`position_y`=-2128.295,`position_z`=779.8099 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7640.099,-2128.295,779.8099,0,0,0,0,100,0),
(@PATH,2,7636.087,-2126.223,780.1163,0,0,0,0,100,0),
(@PATH,3,7630.909,-2124.346,779.991,0,0,0,0,100,0),
(@PATH,4,7635.909,-2126.346,779.991,0,0,0,0,100,0),
(@PATH,5,7637.951,-2127.438,780.0607,0,0,0,0,100,0),
(@PATH,6,7648.995,-2132.307,779.9624,0,0,0,0,100,0),
(@PATH,7,7651.495,-2133.307,779.9624,0,0,0,0,100,0),
(@PATH,8,7662.196,-2138.055,779.7883,0,0,0,0,100,0),
(@PATH,9,7674.446,-2143.555,779.7883,0,0,0,0,100,0),
(@PATH,10,7683.696,-2147.555,780.0383,0,0,0,0,100,0),
(@PATH,11,7675.156,-2143.739,780.0312,0,0,0,0,100,0),
(@PATH,12,7661.753,-2137.754,779.722,0,0,0,0,100,0),
(@PATH,13,7648.792,-2131.948,779.7809,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D00000A0090 .go 7640.099 -2128.295 779.8099

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+3;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7550.756,`position_y`=-2105.977,`position_z`=785.3231 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7550.756,-2105.977,785.3231,0,0,0,0,100,0),
(@PATH,2,7534.166,-2098.272,790.5508,0,0,0,0,100,0),
(@PATH,3,7522.059,-2091.89,795.4978,0,0,0,0,100,0),
(@PATH,4,7520.059,-2091.14,795.9978,0,0,0,0,100,0),
(@PATH,5,7510.826,-2087.808,798.7095,0,0,0,0,100,0),
(@PATH,6,7503.326,-2084.058,800.9595,0,0,0,0,100,0),
(@PATH,7,7511.13,-2088.017,798.521,0,0,0,0,100,0),
(@PATH,8,7520.354,-2091.321,795.7565,0,0,0,0,100,0),
(@PATH,9,7534.39,-2098.547,790.3604,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D00000A0092 .go 7550.756 -2105.977 785.3231

-- Pathing for  Entry: Entry: 'TDB FORMAT' 
SET @NPC := @CGUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7459.342,`position_y`=-2024.512,`position_z`=818.7993 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7459.342,-2024.512,818.7993,0,0,0,0,100,0),
(@PATH,2,7466.841,-2027.784,816.7145,0,0,0,0,100,0),
(@PATH,3,7487.065,-2036.556,810.4653,0,0,0,0,100,0),
(@PATH,4,7466.964,-2027.668,816.6499,0,0,0,0,100,0),
(@PATH,5,7459.381,-2024.334,819.2529,0,0,0,0,100,0),
(@PATH,6,7443.692,-2017.446,824.0328,0,0,0,0,100,0);
-- 0x203CD047601F0D40000C1D000408E709 .go 7459.342 -2024.512 818.7993
