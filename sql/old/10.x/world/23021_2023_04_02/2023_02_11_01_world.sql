SET @CGUID := 9002601;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197762, 0, 1519, 5151, '0', 0, 0, 0, 0, -8660.6025390625, 816.89044189453125, 96.932769775390625, 5.40512704849243164, 120, 0, 0, 112919, 3155, 0, 0, 0, 0, 48001); -- Lord Krazore (Area: Cathedral Square - Difficulty: 0)

UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197762; -- Lord Krazore

-- Waypoints
SET @PATH := (@CGUID+0) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8633.567, 844.2188, 96.86373, NULL, 0),
(@PATH, 1, -8649.598, 830.3646, 96.87789, NULL, 0),
(@PATH, 2, -8663.248, 820.0781, 96.86373, NULL, 0),
(@PATH, 3, -8638.279, 789.9496, 97.05326, NULL, 0),
(@PATH, 4, -8637.797, 783.9739, 97.17826, NULL, 0),
(@PATH, 5, -8664.598, 760.4757, 96.97123, NULL, 0),
(@PATH, 6, -8641.504, 731.1597, 96.89518, NULL, 0),
(@PATH, 7, -8632.5, 740.0208, 97.01419, NULL, 0),
(@PATH, 8, -8625.625, 748.8906, 97.01419, NULL, 0),
(@PATH, 9, -8615.087, 756.4739, 97.10355, NULL, 0),
(@PATH, 10, -8610.292, 761.7031, 97.01419, NULL, 0),
(@PATH, 11, -8614.332, 769.3108, 96.88443, NULL, 0),
(@PATH, 12, -8621.545, 775.5903, 96.88089, NULL, 0),
(@PATH, 13, -8628.507, 785.6302, 96.88919, NULL, 0),
(@PATH, 14, -8632.879, 798.2031, 96.78421, NULL, 0),
(@PATH, 15, -8633.535, 810.8559, 96.8254, NULL, 0),
(@PATH, 16, -8630.283, 822.7396, 96.81436, NULL, 0),
(@PATH, 17, -8601.689, 848.493, 96.99668, NULL, 0),
(@PATH, 18, -8610.458, 860.243, 96.99668, NULL, 0),
(@PATH, 19, -8617.884, 857.4271, 96.99668, NULL, 0);

UPDATE `creature` SET `position_x`= -8633.567, `position_y`= 844.2188, `position_z`= 96.86373, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+0, @PATH, 1);
