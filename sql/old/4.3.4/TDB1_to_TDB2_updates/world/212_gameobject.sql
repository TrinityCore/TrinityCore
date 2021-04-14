SET @OGUID := 85;
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0 ;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179899, 726, 1, 1, 1544.55, 303.852, 0.692371, 6.265733, 0, 0, 0, 1, 7200, 255, 1); -- Speed Buff (Area: Dragonmaw Flag Room)
