UPDATE `gameobject_template` SET `WDBVerified`=12340 WHERE `entry`=179545;
DELETE FROM `gameobject` WHERE `id` IN (179545,179485);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(6,179545,429,1,1,116.135,638.836,-48.467,-0.785397,0,0,0,1,7200,255,1),
(159,179485,429,1,1,558.806,550.065,-25.4008,3.14159,0,0,0,1,180,255,1);
