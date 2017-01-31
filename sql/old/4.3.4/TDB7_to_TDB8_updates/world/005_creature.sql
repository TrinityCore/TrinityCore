--
SET @CGUID = 338125;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 51787, 1, 1, 1, -523.3464, -4278.454, 41.72705, 0.113011, 120, 5, 1), -- 51787 (Area: 6451) (possible waypoints or random movement)
(@CGUID+1, 51787, 1, 1, 1, -619.632, -4302.014, 39.99195, 5.166176, 120, 0, 0), -- 51787 (Area: 6451)
(@CGUID+2, 51787, 1, 1, 1, -639.3914, -4241.776, 38.21835, 2.210378, 120, 5, 1); -- 51787 (Area: 6451) (possible waypoints or random movement)
