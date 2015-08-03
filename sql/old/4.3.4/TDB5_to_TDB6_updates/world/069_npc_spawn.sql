SET @CGUID := 24;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 50484, 530, 1, 1, 9372.658, -7160.698, 9.261522, 3.909538, 120, 0, 0); -- Magistrix Nizara (Area: The Dead Scar)
