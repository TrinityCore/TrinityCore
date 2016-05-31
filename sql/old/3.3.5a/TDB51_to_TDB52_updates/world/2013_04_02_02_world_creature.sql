SET @CGUID := 40471;

DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 23143, 530, 1, 1, -5142.569, 581.3281, 84.13567, 0.5061455, 120, 0, 0); -- Horus (Area: Netherwing Ledge)
