UPDATE `gameobject` SET `spawnMask`=1 WHERE `guid`=2853;
DELETE FROM `gameobject` WHERE `id`=193603;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(150,193603,578,2,1,1015.06,1051.09,605.619,0.017452,0,0,0,1,-608400,0,1);