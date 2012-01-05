-- Template updates for gameobject 186831 (Saga of the Twins)
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry`=186831; -- Saga of the Twins
DELETE FROM `gameobject` WHERE `id`=186831;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(216,186831,571,1,1,957.1025,-5308.23,189.3529,2.600535,0,0,0.9636297,0.267241,300,100,1); 
