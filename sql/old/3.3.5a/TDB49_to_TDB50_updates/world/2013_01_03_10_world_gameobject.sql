-- Issue 8693 Invincible Grave Plaque
DELETE FROM `gameobject` WHERE `guid`=364;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(364,192835,0,1,1,2044.38,-520.9688,46.01406,-3.097385,0,0,0,1,120,255,1);
