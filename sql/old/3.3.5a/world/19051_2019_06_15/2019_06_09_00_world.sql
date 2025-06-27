-- 
UPDATE `creature_template` SET `spell1`=56504, `spell2`=56513, `spell3`=56524,`unit_flags`=256 WHERE  `entry`=30301;
DELETE FROM `creature` WHERE `guid` IN (111098,111101);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(111098, 30322, 571, 0, 0, 1, 8, 0, 1, 8501.92, -22.6061, 786.147, 3.01197, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(111101, 30301, 571, 0, 0, 1, 8, 0, 0, 8492.53, -35.9508, 787.042, 2.64262, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `gameobject` WHERE `guid` IN (9004);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9004, 192262, 571, 0, 0, 1, 8, 8494.46, -27.2724, 787.036, 2.8863, 0, 0, -0.991864, -0.1273, 300, 255, 1, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (6096);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(6096,60960,0,1,'');

UPDATE `creature` SET `MovementType`=2 WHERE `id`= 30300;
DELETE FROM `waypoint_data` WHERE `id` IN (60960);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`, `action_chance`, `move_type`, `wpguid`) VALUES
(60960, 1,8015.62988, -126.51499, 865.740234, 3.39914, 100, 0, 0),
(60960, 2,7951.34668, -145.65760, 870.674805, 3.28296, 100, 0, 0),
(60960, 3,7886.42480, -168.71707, 869.549194, 3.44004, 100, 0, 0),
(60960, 4,7937.22900, -154.84613, 868.431519, 0.31415, 100, 0, 0),
(60960, 5,8015.62988, -126.51499, 865.740234, 3.39914, 100, 0, 0),
(60960, 6,8086.52685, -105.65644, 859.413513, 0.31415, 100, 0, 0),
(60960, 7,8118.80419, -95.168877, 855.644043, 0.31415, 100, 0, 0);
