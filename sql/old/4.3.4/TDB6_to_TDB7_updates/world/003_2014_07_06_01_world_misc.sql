--
SET @GUID=5412;

DELETE FROM `gameobject` WHERE `id`=188367;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@GUID,188367,571,1,1,5048.28,-4817.63,219.778,2.49582,0,0,0,1,-60,255,1,0);

DELETE FROM `event_scripts` WHERE `id`=17566;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(17566,0,9,@GUID,60,0,0,0,0,0);
