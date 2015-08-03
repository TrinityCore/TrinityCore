--
SET @GGUID=148;

DELETE FROM `gameobject` WHERE `id`=181632 AND `guid`=5338;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GGUID, 194905,603,3,1,401.308,-13.8236,409.524,3.14159,0,0,0,0,604800,0,0);
