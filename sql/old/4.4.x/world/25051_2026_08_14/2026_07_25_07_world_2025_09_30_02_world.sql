-- Furlbrows Pumpkin Farm
SET @CGUID := 224143;
SET @POOLID := 3000000;

-- Creature (pooled, just one is active at a time)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 199, 0, 40, 109, '0', 0, 0, 0, 0, -9925.439453125, 1177.241943359375, 42.55515289306640625, 2.720944643020629882, 120, 12, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Young Fleshripper (Area: Furlbrow's Pumpkin Farm - Difficulty: 0) CreateObject2
(@CGUID+1, 199, 0, 40, 109, '0', 0, 0, 0, 0, -9918.53125, 1265.4384765625, 42.35733795166015625, 0.615315139293670654, 120, 12, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Young Fleshripper (Area: Furlbrow's Pumpkin Farm - Difficulty: 0) CreateObject2
(@CGUID+2, 199, 0, 40, 109, '0', 0, 0, 0, 0, -9848.490234375, 1229.1529541015625, 41.61896133422851562, 4.414900779724121093, 120, 12, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Young Fleshripper (Area: Furlbrow's Pumpkin Farm - Difficulty: 0) CreateObject2
(@CGUID+3, 199, 0, 40, 109, '0', 0, 0, 0, 0, -9975.0849609375, 1227.3287353515625, 42.44589614868164062, 3.002333402633666992, 120, 12, 0, 1, NULL, NULL, NULL, NULL, 63305); -- Young Fleshripper (Area: Furlbrow's Pumpkin Farm - Difficulty: 0) CreateObject2

-- Added missing _addon
DELETE FROM `creature_addon` WHERE `guid` IN (275897,275898,275895,275896,275894,275892,275899,275901,275900,275902,275904,275906,275908,275903,275907);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(275897, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275898, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275895, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275896, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275894, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275892, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275899, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275901, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(275900, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275902, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275904, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275906, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275908, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275903, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(275907, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'); -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable

-- Pool
DELETE FROM `pool_template` WHERE `entry` = @POOLID;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID, 1, 'Westfall - Furlbrows Pumpkin Farm - Young Fleshripper');

DELETE FROM `pool_members` WHERE (`spawnId` IN (@CGUID+0,@CGUID+1,@CGUID+2,@CGUID+3) AND `type` = 0);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+0, @POOLID, 0, 'Westfall - Furlbrows Pumpkin Farm - Young Fleshripper'),
(0, @CGUID+1, @POOLID, 0, 'Westfall - Furlbrows Pumpkin Farm - Young Fleshripper'),
(0, @CGUID+2, @POOLID, 0, 'Westfall - Furlbrows Pumpkin Farm - Young Fleshripper'),
(0, @CGUID+3, @POOLID, 0, 'Westfall - Furlbrows Pumpkin Farm - Young Fleshripper');

-- Update Coyote to createobject2 spawn positions
UPDATE `creature` SET `position_x` = -9964.841796875, `position_y` = 1207.704833984375, `position_z` = 43.06673812866210937, `orientation` = 5.506795883178710937 WHERE `guid` = 275786;
UPDATE `creature` SET `position_x` = -9930.3642578125, `position_y` = 1223.4166259765625, `position_z` = 42.51685333251953125, `orientation` = 2.779277563095092773 WHERE `guid` = 275808;
UPDATE `creature` SET `position_x` = -9995.138671875, `position_y` = 1261.9271240234375, `position_z` = 44.071380615234375, `orientation` = 2.325879812240600585 WHERE `guid` = 275715;
UPDATE `creature` SET `position_x` = -10003.5244140625, `position_y` = 1220.5242919921875, `position_z` = 41.10367202758789062, `orientation` = 5.126083850860595703 WHERE `guid` = 275712;
UPDATE `creature` SET `position_x` = -9953.734375, `position_y` = 1273.9913330078125, `position_z` = 41.09287643432617187, `orientation` = 4.182867050170898437 WHERE `guid` = 275806;
UPDATE `creature` SET `position_x` = -9955.2607421875, `position_y` = 1251.9791259765625, `position_z` = 42.18105697631835937, `orientation` = 2.021632671356201171 WHERE `guid` = 275784;
UPDATE `creature` SET `position_x` = -9921.8642578125, `position_y` = 1265.017333984375, `position_z` = 42.24509429931640625, `orientation` = 3.713852167129516601 WHERE `guid` = 275810;
UPDATE `creature` SET `position_x` = -9865.779296875, `position_y` = 1229.4010009765625, `position_z` = 41.75061798095703125, `orientation` = 2.131131649017333984 WHERE `guid` = 275861;
UPDATE `creature` SET `position_x` = -9895.341796875, `position_y` = 1202.2569580078125, `position_z` = 41.98929977416992187, `orientation` = 2.342655658721923828 WHERE `guid` = 275811;
UPDATE `creature` SET `position_x` = -9925.310546875, `position_y` = 1178.9097900390625, `position_z` = 42.43995285034179687, `orientation` = 4.924037933349609375 WHERE `guid` = 275804;
UPDATE `creature` SET `position_x` = -9816.17578125, `position_y` = 1222.826416015625, `position_z` = 43.00292587280273437, `orientation` = 0.612595558166503906 WHERE `guid` = 275876;
UPDATE `creature` SET `position_x` = -9916.64453125, `position_y` = 1147.8785400390625, `position_z` = 42.80718612670898437, `orientation` = 4.477817535400390625 WHERE `guid` = 275803;
UPDATE `creature` SET `position_x` = -9982.111328125, `position_y` = 1174.3992919921875, `position_z` = 42.54503250122070312, `orientation` = 4.515748023986816406 WHERE `guid` = 275711;

-- Update Young Fleshripper to createobject2 spawn positions
UPDATE `creature` SET `position_x` = -9991.1494140625, `position_y` = 1309.373291015625, `position_z` = 43.66715240478515625, `orientation` = 3.989080190658569335 WHERE `guid` = 275717;
UPDATE `creature` SET `position_x` = -9848.6533203125, `position_y` = 1177.079833984375, `position_z` = 39.83509445190429687, `orientation` = 5.687968254089355468 WHERE `guid` = 275874;
UPDATE `creature` SET `position_x` = -10047.654296875, `position_y` = 1316.6632080078125, `position_z` = 44.22189712524414062, `orientation` = 0.034313660115003585 WHERE `guid` = 275716;
UPDATE `creature` SET `position_x` = -10031.638671875, `position_y` = 1274.970458984375, `position_z` = 43.83249282836914062, `orientation` = 6.137407302856445312 WHERE `guid` = 275713;

-- Update Young Goretusk to createobject2 spawn positions
UPDATE `creature` SET `position_x` = -9949.4736328125, `position_y` = 1243.948974609375, `position_z` = 42.62841033935546875, `orientation` = 1.369479894638061523 WHERE `guid` = 275809;
UPDATE `creature` SET `position_x` = -9953.2236328125, `position_y` = 1289.501708984375, `position_z` = 43.94571685791015625, `orientation` = 3.136235475540161132 WHERE `guid` = 275783;
UPDATE `creature` SET `position_x` = -9882.20703125, `position_y` = 1227.0511474609375, `position_z` = 41.9536590576171875, `orientation` = 0.625485062599182128 WHERE `guid` = 275860;
UPDATE `creature` SET `position_x` = -9960.5380859375, `position_y` = 1125.704833984375, `position_z` = 40.30907058715820312, `orientation` = 2.365688323974609375 WHERE `guid` = 275708;
UPDATE `creature` SET `position_x` = -9980.1298828125, `position_y` = 1095.532958984375, `position_z` = 40.47197723388671875, `orientation` = 0.818975031375885009 WHERE `guid` = 275710;
UPDATE `creature` SET `position_x` = -9995.4658203125, `position_y` = 1136.0728759765625, `position_z` = 44.09099578857421875, `orientation` = 5.673230171203613281 WHERE `guid` = 275709;

-- Update random movement
UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (275786,275808,275715,275712,275806,275784,275810,275861,275811,275804,275876,275803,275711);
UPDATE `creature` SET `wander_distance` = 6, `MovementType` = 1 WHERE `guid` IN (275809,275783,275860,275708,275710,275709);
UPDATE `creature` SET `wander_distance` = 12, `MovementType` = 1 WHERE `guid` IN (275717,275874,275716,275713);

-- Path for Homeless Stormwind Citizen
SET @MOVERGUID := 275859;
SET @ENTRY := 42384;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Homeless Stormwind Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9878.305, 1297.3676, 42.111702, NULL, 0),
(@PATH, 1, -9876.146, 1295.906, 42.12691, NULL, 0),
(@PATH, 2, -9873.988, 1294.4445, 42.14212, NULL, 0),
(@PATH, 3, -9870.053, 1297.5205, 42.3255, NULL, 0),
(@PATH, 4, -9862.969, 1303.0576, 42.15387, NULL, 0),
(@PATH, 5, -9861.205, 1304.4305, 42.08785, NULL, 0),
(@PATH, 6, -9861.205, 1304.4305, 42.08785, NULL, 0),
(@PATH, 7, -9846.795, 1322.7067, 43.91255, NULL, 0),
(@PATH, 8, -9858.272, 1337.8073, 41.91286, NULL, 0),
(@PATH, 9, -9871.32, 1348.7148, 42.426952, NULL, 0),
(@PATH, 10, -9900.007, 1320.0798, 42.661095, NULL, 0),
(@PATH, 11, -9887.603, 1306.3993, 42.07728, NULL, 0),
(@PATH, 12, -9882.014, 1314.1666, 43.11313, NULL, 0),
(@PATH, 13, -9886.849, 1308.3698, 42.248898, NULL, 0),
(@PATH, 14, -9884.661, 1301.6736, 42.066883, NULL, 0);

UPDATE `creature` SET `position_x`=-9878.305, `position_y`=1297.3676, `position_z`=42.111702, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for West Plains Drifter
SET @MOVERGUID := 275888;
SET @ENTRY := 42400;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'West Plains Drifter - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9826.002, 1271.979, 40.546333, NULL, 0),
(@PATH, 1, -9827.336, 1271.0347, 40.521496, NULL, 0),
(@PATH, 2, -9828.67, 1270.0903, 40.49666, NULL, 0),
(@PATH, 3, -9835.736, 1264.5176, 40.800583, NULL, 0),
(@PATH, 4, -9837.307, 1263.2793, 41.0314, NULL, 0),
(@PATH, 5, -9838.877, 1262.041, 41.439228, NULL, 0),
(@PATH, 6, -9839.662, 1261.4219, 41.74884, NULL, 0),
(@PATH, 7, -9841.232, 1260.1836, 41.95461, NULL, 0),
(@PATH, 8, -9841.393, 1260.0504, 41.95704, NULL, 0),
(@PATH, 9, -9844.854, 1262.0547, 42.251133, NULL, 0),
(@PATH, 10, -9848.314, 1264.0586, 41.961975, NULL, 0),
(@PATH, 11, -9849.18, 1264.5596, 41.790085, NULL, 0),
(@PATH, 12, -9850.045, 1265.0605, 41.619934, NULL, 0),
(@PATH, 13, -9851.759, 1266.0521, 41.506916, NULL, 0),
(@PATH, 14, -9867.886, 1280.066, 40.713776, NULL, 0),
(@PATH, 15, -9856.901, 1292.2048, 41.627167, NULL, 0),
(@PATH, 16, -9842.531, 1300.8021, 41.909256, NULL, 0),
(@PATH, 17, -9830.325, 1289.7709, 40.44865, NULL, 0),
(@PATH, 18, -9819.934, 1276.3066, 40.923073, NULL, 0);

UPDATE `creature` SET `position_x`=-9826.002, `position_y`=1271.979, `position_z`=40.546333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '79143');
