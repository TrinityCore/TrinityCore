-- Badlands Fixes

-- Difficulty fixes
-- Missing Content Tuning
DELETE FROM `creature_template_difficulty` WHERE Entry IN (50728) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (50728) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 27 WHERE Entry = 7057 AND DifficultyID = 0;

-- Template Addons
UPDATE creature_template_addon SET emote = 233 WHERE Entry IN (2739,46773,4846,46772);

-- Creature Spawns
SET @CGUID := 900000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1230 AND @CGUID+1245;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `phaseId`, `phaseGroup`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
-- Broken Tooth
(@CGUID+1230, 2850, 0, 3, 5322, 0, 0, 0, 0, 0, -6671, -3198, 260.96, 5.164, 3600),
(@CGUID+1231, 2850, 0, 3, 3, 0, 0, 0, 0, 0, -6376.69, -3563.98, 262.806, 2.1523, 3600),
(@CGUID+1232, 2850, 0, 3, 3, 0, 0, 0, 0, 0, -6147.18, -3413.65, 246.71, 0.0332949, 3600),
(@CGUID+1233, 2850, 0, 3, 3, 0, 0, 0, 0, 0, -7103.96, -2599.17, 271.594, 4.4855, 3600),
-- Anathemus
(@CGUID+1234, 2754, 0, 3, 3, 0, 0, 0, 0, 1, -6968, -3519, 241.671, 6.277, 3600),
(@CGUID+1235, 2754, 0, 3, 3, 0, 0, 0, 0, 1, -7221.81, -2158.13, 304.574, 1.38221, 3600),
-- Vorticus
(@CGUID+1236, 51021, 0, 3, 1878, 0, 0, 0, 0, 0, -6610, -2585.48, 267.707, 3.69258, 3600),
-- Serkett
(@CGUID+1237, 51007, 0, 3, 1878, 0, 0, 0, 0, 0, -6635.26, -2717.89, 243.842, 4.12752, 3600),
-- Kalixx
(@CGUID+1238, 50726, 0, 3, 1878, 0, 0, 0, 0, 0, -6588.14, -2883.43, 263.762, 4.31316, 3600),
-- Shadowforge Commander
(@CGUID+1239, 2744, 0, 3, 338, 0, 0, 0, 0, 1, -6383, -3143, 301.11, 0.582, 3600),
(@CGUID+1240, 2744, 0, 3, 338, 0, 0, 0, 0, 1, -6356.25, -3123.82, 283.972, 1.01229, 3600),
-- War Golem
(@CGUID+1241, 2751, 0, 3, 1897, 0, 0, 0, 0, 0, -6065.22, -3170.8, 281.172, 5.50772, 3600),
(@CGUID+1242, 2751, 0, 3, 346, 0, 0, 0, 0, 0, -6454.15, -3354.48, 241.79, 0.11987, 3600),
(@CGUID+1243, 2751, 0, 3, 338, 0, 0, 0, 0, 0, -6449.57, -3118.19, 315.774, 5.98035, 3600),
(@CGUID+1244, 2751, 0, 3, 346, 0, 0, 0, 0, 0, -6382.71, -3408.98, 241.75, 0.907571, 3600),
-- Zormus
(@CGUID+1245, 51018, 0, 3, 3, 0, 0, 0, 0, 0, -6554.34, -3486.96, 292.678, 4.74527, 3600);

SET @POOLID := 900000;
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+9 AND @POOLID+12;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+9, 1, 'Badlands - Broken Tooth'),
(@POOLID+10, 1, 'Badlands - Anathemus'),
(@POOLID+11, 1, 'Badlands - Shadowforge Commander'),
(@POOLID+12, 1, 'Badlands - War Golem');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID+9 AND @POOLID+12;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+1230, @POOLID+9, 0, 'Badlands - Broken Tooth'),
(0, @CGUID+1231, @POOLID+9, 0, 'Badlands - Broken Tooth'),
(0, @CGUID+1232, @POOLID+9, 0, 'Badlands - Broken Tooth'),
(0, @CGUID+1233, @POOLID+9, 0, 'Badlands - Broken Tooth'),
(0, @CGUID+1234, @POOLID+10, 0, 'Badlands - Anathemus'),
(0, @CGUID+1235, @POOLID+10, 0, 'Badlands - Anathemus'),
(0, @CGUID+1239, @POOLID+11, 0, 'Badlands - Shadowforge Commander'),
(0, @CGUID+1240, @POOLID+11, 0, 'Badlands - Shadowforge Commander'),
(0, @CGUID+1241, @POOLID+12, 0, 'Badlands - War Golem'),
(0, @CGUID+1242, @POOLID+12, 0, 'Badlands - War Golem'),
(0, @CGUID+1243, @POOLID+12, 0, 'Badlands - War Golem'),
(0, @CGUID+1244, @POOLID+12, 0, 'Badlands - War Golem');

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    2729,2732,46693,46695,2740,2743,2742,2830,4844,46694,
    2725,2726,92,46915,46914,2717,2718,2831,2734,2730,
    46917,46918
);
