SET @OGUID := 6100;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 191849, 619, 3, 1, 523.5123, -301.1218, 68.84955, -1.570796, -0.004628658, 0.003181458, -0.7086, 0.705588, 7200, 255, 1), -- 191849 (Area: 4627)
(@OGUID+1, 191848, 619, 3, 1, 523.4318, -300.7111, 68.82808, -1.575045, 0, 0, -0.7071066, 0.7071069, 7200, 255, 1); -- 191848 (Area: 4627)


DELETE FROM `areatrigger_teleport` WHERE `id`=5235;
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(5235, 'Ahn''Kahet (exit)', 571, 3817.4,2032.82, 11.0133, 3.612832);
