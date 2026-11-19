DELETE FROM `creature_template_addon` WHERE `entry`=49044;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(49044, 0, 0x3010000, 0x1, '49414');

DELETE FROM `creature` WHERE `id`=49044;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(999999, 49044, 0, 1, 1, 0, 1700.2, 1703.361, 137.1976, 1.675516, 120, 0, 0); -- temp guid to "fix" travis.
