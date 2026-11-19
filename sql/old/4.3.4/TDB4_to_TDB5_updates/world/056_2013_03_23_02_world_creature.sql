SET @CGUID := 264; -- 4.x
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 36656, 571, 1, 1, 5647.669, 2106.526, 798.1375, 4.764749, 120, 0, 0), -- Silver Covenant Sentinel (Area: 4862)
(@CGUID+1, 36656, 571, 1, 1, 5657.819, 2105.712, 798.1375, 4.590216, 120, 0, 0), -- Silver Covenant Sentinel (Area: 4862)
(@CGUID+2, 36624, 571, 1, 1, 5652.733, 2106.208, 798.1375, 4.572762, 120, 0, 0); -- Caladis Brightspear (Area: 4862)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0x10000, 0x1, 0, '71311'),
(@CGUID+1, 0, 0, 0x10000, 0x1, 0, '71311'),
(@CGUID+2, 0, 0, 0x10000, 0x1, 0, '71311');
