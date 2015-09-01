--
SET @ADARRAH := 24405;
SET @CGUID := 77; -- 4.x

DELETE FROM `creature` WHERE `guid`=86444;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(86444, @ADARRAH, 571, 1, 1, 4912.768, -4797.917, 32.68771, 3.595378, 300, 0, 0);
