-- Xariona
SET @CGUID := 396407;
DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 50061, 646, 5042, 5395, 1, 169, 0, 0, 0, 714.94244384765625, 872.816650390625, 458.444610595703125, 3.912934303283691406, 120, 0, 0, 0, 0, 3, 0, 0, 0, 27326); -- Xariona (Area: Chamber of Respite - Difficulty: 0) (Auras: 87239 - Zero Power, 73059 - Rogue Class Crit/Dodge Debuff)

DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `cyclicSplinePathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID, @CGUID * 10, 0, 50331648, 1, 0, '87239 73059'); -- Xariona - 87239 - Zero Power, 73059 - Rogue Class Crit/Dodge Debuff

UPDATE `creature` SET `position_x`= 1187.3926, `position_y`= 77.90289, `position_z`=  458.44458, `MovementType`= 3 WHERE `guid`= @CGUID;
DELETE FROM `waypoint_data` WHERE `id`= @CGUID * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(@CGUID * 10, 0, 1349.8813, 167.04727, 458.44458),
(@CGUID * 10, 1, 1465.8875, 311.58783, 458.44458),
(@CGUID * 10, 2, 1517.7498,  489.5195, 458.44458),
(@CGUID * 10, 3, 1497.5728,  673.7537, 458.44458),
(@CGUID * 10, 4, 1408.4283, 836.24255, 458.44458),
(@CGUID * 10, 5, 1263.8877,  952.2486, 458.44458),
(@CGUID * 10, 6, 1085.956,  1004.1109, 458.44458),
(@CGUID * 10, 7, 901.72186,  983.9339, 458.44458),
(@CGUID * 10, 8, 739.23303,  894.7894, 458.44458),
(@CGUID * 10, 9, 623.22705,  750.2489, 458.44458),
(@CGUID * 10, 10, 571.36475,  572.3173, 458.44458),
(@CGUID * 10, 11, 591.54175, 388.08313, 458.44458),
(@CGUID * 10, 12, 680.68616,  225.5943, 458.44458),
(@CGUID * 10, 13, 825.2266,  109.58829, 458.44458),
(@CGUID * 10, 14, 1003.15826, 57.72589, 458.44458),
(@CGUID * 10, 15, 1187.3926,  77.90289, 458.44458);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 50061;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Swim`) VALUE
(50061, 0, 1, 0);
