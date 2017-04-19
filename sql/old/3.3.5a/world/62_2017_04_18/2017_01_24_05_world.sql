-- [NPC][WotlK] Sifreldar Runekeeper and Storm Maiden, missing emotes/paths/spawn locs
-- Add missing creature Spawns
SET @CGUID := 74009;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@CGUID+0, 29323, 571, 0, 0, 1, 1, 0, 1, 6968.38, -1036.38, 804.849, 4.32326, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0),
(@CGUID+1, 29323, 571, 0, 0, 1, 1, 0, 1, 6889.61, -1141.36, 802.432, 1.72516, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0),
(@CGUID+2, 29323, 571, 0, 0, 1, 1, 0, 1, 6610.21, -1084.88, 762.207, 0.786112, 300, 0, 0, 11770, 0, 0, 0, 0, 0, 0),
(@CGUID+3, 29323, 571, 0, 0, 1, 1, 0, 1, 6587.2, -1059.6, 748.807, 3.08891, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0),
(@CGUID+4, 29323, 571, 0, 0, 1, 1, 0, 1, 6599.12, -1111.81, 748.803, 3.4659, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0),
(@CGUID+5, 29331, 571, 0, 0, 1, 1, 0, 1, 6697.06, -1062.14, 764.093, 3.33207, 300, 0, 0, 9740, 8636, 0, 0, 0, 0, 0),
(@CGUID+6, 29323, 571, 0, 0, 1, 1, 0, 1, 6624.12, -1086.51, 748.602, 2.78313, 300, 0, 0, 11770, 0, 0, 0, 0, 0, 0),
(@CGUID+7, 29466, 571, 0, 0, 1, 1, 0, 0, 6618.3, -1104.94, 748.305, 3.52847, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0);

-- Add one missing Cage
SET @OGUID := 42;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@OGUID, 191544, 571, 67, 4423, 1, 1, 6618.3, -1104.94, 748.305, 3.52847, 0, 0, 0.981349, -0.192237, 300, 0, 1, 0);

-- update position for one creature
UPDATE `creature` SET `position_x`=6852.2436, `position_y`=-1072.85864, `position_z`=803.42102, `orientation`=0.58555 WHERE  `guid`=108539;

-- Add emotes
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+6,@CGUID+0,109771,108774,108770,108777,108776,108539,109769);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@CGUID+6,0,0,1,1, 0, ''),
(@CGUID+0,0,0,1,1, 0, ''),
(109771,  0,0,0,1,69, ''),
(108774,  0,0,1,1, 0, ''),
(108770,  0,0,1,1, 0, ''),
(108777,  0,0,1,1, 0, ''),
(108776,  0,0,1,1, 0, ''),
(108539,  0,0,1,1, 0, ''),
(109769,  0,0,0,1,69, '');

-- Delete wrong spawns
DELETE FROM `creature` WHERE `guid` IN (109770, 108766);

-- Add Missing Path
SET @NPC := @CGUID+5;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH,  1, 6701.32, -1060.96, 764.581, 0, 0, 0, 0, 100, 0),
(@PATH,  2, 6711.96, -1057.16, 764.806, 0, 0, 0, 0, 100, 0),
(@PATH,  3, 6715.25, -1051.56, 765.434, 0, 0, 0, 0, 100, 0),
(@PATH,  4, 6710.89, -1057.03, 764.769, 0, 0, 0, 0, 100, 0),
(@PATH,  5, 6696.23, -1062.76, 763.953, 0, 0, 0, 0, 100, 0),
(@PATH,  6, 6682.41, -1064.98, 763.17,  0, 0, 0, 0, 100, 0),
(@PATH,  7, 6675.49, -1066.01, 761.302, 0, 0, 0, 0, 100, 0),
(@PATH,  8, 6661.78, -1068.79, 758.596, 0, 0, 0, 0, 100, 0),
(@PATH,  9, 6648.1,  -1071.75, 758.456, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6634.8,  -1071.28, 758.358, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6620.64, -1073.34, 751.616, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6610.29, -1075.97, 748.604, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 6599.38, -1079.36, 748.595, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 6581.61, -1082.74, 748.701, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 6591.98, -1081.12, 748.582, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 6613.95, -1075.26, 748.602, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 6627.62, -1072.42, 754.901, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 6638.05, -1071.34, 758.457, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 6655.51, -1070.12, 758.455, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 6669.33, -1067.92, 758.782, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 6682.2,  -1065.27, 763.268, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 6695.23, -1062.56, 763.725, 0, 0, 0, 0, 100, 0);

-- Add missing Path
SET @NPC := 108779;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6770.527,`position_y`=-1021.021,`position_z`=766.3752 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,(@POINT := @POINT + 1),6770.527,-1021.021,766.3752,0,0,0,0,100,0), -- 12:41:52
(@PATH,(@POINT := @POINT + 1),6774.866,-1027.486,766.3826,0,0,0,0,100,0), -- 12:41:52
(@PATH,(@POINT := @POINT + 1),6779.206,-1033.951,766.39,0,0,0,0,100,0), -- 12:41:52
(@PATH,(@POINT := @POINT + 1),6779.206,-1033.951,766.39,0,0,0,0,100,0), -- 12:41:52
(@PATH,(@POINT := @POINT + 1),6779.391,-1033.916,766.4652,0,0,0,0,100,0), -- 12:41:53
(@PATH,(@POINT := @POINT + 1),6781.516,-1056.379,766.7101,0,0,0,0,100,0), -- 12:42:01
(@PATH,(@POINT := @POINT + 1),6779.214,-1068.532,766.6703,0,0,0,0,100,0), -- 12:42:06
(@PATH,(@POINT := @POINT + 1),6792.936,-1106.229,772.7088,0,0,0,0,100,0), -- 12:42:12
(@PATH,(@POINT := @POINT + 1),6812.191,-1124.6,786.1531,0,0,0,0,100,0), -- 12:42:35
(@PATH,(@POINT := @POINT + 1),6824.273,-1140.217,796.6036,0,0,0,0,100,0), -- 12:42:36
(@PATH,(@POINT := @POINT + 1),6820.466,-1157.098,805.7188,0,0,0,0,100,0), -- 12:42:46
(@PATH,(@POINT := @POINT + 1),6805.752,-1163.74,811.014,0,0,0,0,100,0), -- 12:42:53
(@PATH,(@POINT := @POINT + 1),6818.727,-1159.172,806.4229,0,0,0,0,100,0), -- 12:43:03
(@PATH,(@POINT := @POINT + 1),6824.18,-1142.572,798.067,0,0,0,0,100,0), -- 12:43:09
(@PATH,(@POINT := @POINT + 1),6812.635,-1125.064,786.6625,0,0,0,0,100,0), -- 12:43:18
(@PATH,(@POINT := @POINT + 1),6795.604,-1109.136,773.9398,0,0,0,0,100,0), -- 12:43:26
(@PATH,(@POINT := @POINT + 1),6780.573,-1088.984,767.4163,0,0,0,0,100,0), -- 12:43:38
(@PATH,(@POINT := @POINT + 1),6775.638,-1081.745,766.4496,0,0,0,0,100,0), -- 12:43:52
(@PATH,(@POINT := @POINT + 1),6779.679,-1068.467,766.4709,0,0,0,0,100,0), -- 12:43:57
(@PATH,(@POINT := @POINT + 1),6781.518,-1056.111,766.6932,0,0,0,0,100,0), -- 12:44:01
(@PATH,(@POINT := @POINT + 1),6779.147,-1033.783,766.6435,0,0,0,0,100,0), -- 12:44:11
(@PATH,(@POINT := @POINT + 1),6774.77,-1027.126,766.6381,0,0,0,0,100,0), -- 12:44:14
(@PATH,(@POINT := @POINT + 1),6759.426,-1017.7,766.6392,0,0,0,0,100,0), -- 12:44:21
(@PATH,(@POINT := @POINT + 1),6756.741,-1000.856,767.1541,0,0,0,0,100,0), -- 12:44:25
(@PATH,(@POINT := @POINT + 1),6756.155,-1001.621,766.9041,0,0,0,0,100,0), -- 12:44:32
(@PATH,(@POINT := @POINT + 1),6753.849,-1010.317,766.4717,0,0,0,0,100,0), -- 12:44:36
(@PATH,(@POINT := @POINT + 1),6759.732,-1017.921,766.6362,0,0,0,0,100,0), -- 12:44:40
(@PATH,(@POINT := @POINT + 1),6775.08,-1027.515,766.6372,0,0,0,0,100,0), -- 12:44:46
(@PATH,(@POINT := @POINT + 1),6779.468,-1034.036,766.4645,0,0,0,0,100,0), -- 12:44:50
(@PATH,(@POINT := @POINT + 1),6781.6,-1056.437,766.7156,0,0,0,0,100,0), -- 12:45:00
(@PATH,(@POINT := @POINT + 1),6779.321,-1068.573,766.6611,0,0,0,0,100,0), -- 12:45:05
(@PATH,(@POINT := @POINT + 1),6792.881,-1106.05,772.7088,0,0,0,0,100,0), -- 12:45:10
(@PATH,(@POINT := @POINT + 1),6810.71,-1123.079,785.4041,0,0,0,0,100,0), -- 12:45:23
(@PATH,(@POINT := @POINT + 1),6824.344,-1140.323,796.4342,0,0,0,0,100,0), -- 12:45:34
(@PATH,(@POINT := @POINT + 1),6820.311,-1157.064,805.7056,0,0,0,0,100,0); -- 12:45:44
-- 0x203AF447601CA4C000279D000005E489 .go 6770.527 -1021.021 766.3752
