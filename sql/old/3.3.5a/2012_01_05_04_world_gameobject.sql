-- add  South Point Station Valve gameobject
DELETE FROM `gameobject` WHERE `id`=188109;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(221,188109,571,1,1,3792.77,4808.874,-11.56067,1.483528,0,0,0.6755896,0.7372779,0,0,1);
