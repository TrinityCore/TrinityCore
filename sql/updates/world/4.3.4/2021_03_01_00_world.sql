UPDATE `creature` SET `PhaseId`= 226 WHERE `guid` IN (349909, 349910, 349911, 349912, 349913, 349914, 349915, 349916, 349917, 349918, 349919, 349920, 349921, 349922, 349923, 349924, 349925, 349926, 349927, 349928, 349929, 349930, 349931, 349932, 349933, 349934, 349935, 349937, 349938, 349939, 349940, 349941, 349942, 349943, 349944, 349945, 349946, 349947, 349948, 349949, 349950, 349951, 349952, 349953, 349954, 349955, 349956, 349957, 349958, 349959, 349960, 349961, 349962, 349963, 349964, 349965, 349966, 349967, 349968, 349969, 349970, 349971, 349972, 349973, 349974, 349975, 349976, 349977, 349978, 349979, 349980, 349981, 349982, 349983, 349984, 349985, 349986, 349987, 349988, 349989, 349990, 349991, 349992, 349993, 349994, 349995, 349996, 349997, 349998, 349999, 350000, 350001, 350002, 350003, 350004, 350005, 350006, 350007, 350008, 350009, 350010, 350012, 350013, 350014, 350015, 350016, 350017, 350018, 350019, 350020, 350021, 350022, 350023, 350024, 350025, 350026, 350027, 350028, 350029, 350030, 350031, 350032, 350033, 350036, 350037, 350038, 350039, 350040);
UPDATE `gameobject` SET `PhaseId`= 226 WHERE `guid` IN (222398, 222399, 222400, 222401, 222403, 222404, 222405, 222406, 222407, 222408, 222409, 222410, 222411, 222412, 222413, 222414, 222415, 222416, 222417, 222418);
UPDATE `creature_template_addon` SET `aiAnimKit`= 676 WHERE `entry`= 42635;

SET @CGUID := 350866;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID-0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 42309, 0, 40, 108, 1, 169, 0, 0, 0, -10506.2568359375, 1047.701416015625, 60.60131072998046875, 4.293509960174560546, 120, 0, 0, 2856, 0, 0, 0, 0, 0, 25881), -- Stormwind Investigator (Area: Sentinel Hill - Difficulty: 0) (Auras: 79497 - Apply Quest Invis Zone 3)
(@CGUID+1, 42308, 0, 40, 108, 1, 169, 0, 0, 0, -10507.9580078125, 1047.54345703125, 60.51798248291015625, 4.363323211669921875, 120, 0, 0, 8070, 0, 0, 0, 0, 0, 25881), -- Lieutenant Horatio Laine (Area: Sentinel Hill - Difficulty: 0) (Auras: 79497 - Apply Quest Invis Zone 3)
(@CGUID+2, 42309, 0, 40, 108, 1, 169, 0, 0, 0, -10509.0537109375, 1048.5555419921875, 60.60131072998046875, 4.520402908325195312, 120, 0, 0, 3452, 0, 0, 0, 0, 0, 25881), -- Stormwind Investigator (Area: Sentinel Hill - Difficulty: 0) (Auras: 79497 - Apply Quest Invis Zone 3)
(@CGUID+3, 869, 0, 40, 108, 1, 226, 0, 0, 0, -10544.0673828125, 1034.626708984375, 56.68906021118164062, 3.228859186172485351, 120, 0, 0, 5380, 0, 0, 0, 0, 0, 25881), -- Protector Dorana (Area: Sentinel Hill - Difficulty: 0)
(@CGUID+4, 874, 0, 40, 108, 1, 226, 0, 0, 0, -10541.265625, 1034.8975830078125, 56.68906021118164062, 3.176499128341674804, 120, 0, 0, 5380, 0, 0, 0, 0, 0, 25881); -- Protector Korelor (Area: Sentinel Hill - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID-0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 1, 0, '79497'),
(@CGUID+1, 0, 1, 0, '79497'),
(@CGUID+2, 0, 1, 0, '79497'),
(@CGUID+3, 0, 1, 333, ''),
(@CGUID+4, 0, 1, 333, '');

-- Waypoints
SET @CGUID := 275167;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10498.09, 1032.982, 95.61337, 0, -1066),
(@PATH, 1, -10494.1, 1028.51, 95.61249, 0, -922),
(@PATH, 2, -10493.71, 1023.374, 95.61249, 0, -628),
(@PATH, 3, -10497.35, 1019.126, 95.61249, 0, -1641),
(@PATH, 4, -10503.21, 1018.588, 95.61249, 0, -1533),
(@PATH, 5, -10506.96, 1021.805, 95.61249, 0, -1207),
(@PATH, 6, -10508.08, 1027.11, 95.61249, 0, -873),
(@PATH, 7, -10503.8, 1032.672, 95.61249, 0, -1211);

UPDATE `creature` SET `position_x`= -10498.09, `position_y`= 1032.982, `position_z`= 95.61337, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

SET @CGUID := 275159;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10499.22, 1045.555, 60.5062, 0, -800),
(@PATH, 1, -10516.6, 1039.766, 60.51799, 0, -907),
(@PATH, 2, -10521.01, 1024.184, 60.4726, 0, -1256),
(@PATH, 3, -10511.89, 1008.212, 60.41823, 0, -1370),
(@PATH, 4, -10503.62, 1006.058, 60.52855, 0, -1150),
(@PATH, 5, -10493.65, 1008.358, 60.45516, 0, -1666),
(@PATH, 6, -10484.87, 1014.422, 60.41488, 0, -1031),
(@PATH, 7, -10481.82, 1029.529, 60.49055, 0, -1164),
(@PATH, 8, -10488.06, 1041.137, 60.42339, 0, -1590);

UPDATE `creature` SET `position_x`= -10499.22, `position_y`= 1045.555, `position_z`= 60.5062, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);
