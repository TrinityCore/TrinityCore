--
SET @CGUID := 43498;
DELETE FROM `creature` WHERE id=37527;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 37527, 530, 1, 1, 12559.3, -6783.323, 15.06894, 0.06981317, 120, 0, 0);
