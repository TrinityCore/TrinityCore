-- DTK instance entrance portals
DELETE FROM `gameobject` WHERE `guid`=151225;
SET @OGUID  := 6120; -- (need 3)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,192585,571,1,1,4774.532,-2020.723,232.3105,-1.579522,0,0,0.9999905,0.004363241,120,255,1),
(@OGUID+1,192776,571,1,1,4774.532,-2020.723,232.3105,-1.579522,0,0,0.9999905,0.004363241,120,255,1),
(@OGUID+2,192775,571,1,1,4774.532,-2020.723,232.3105,-1.579522,0,0,0.9999905,0.004363241,120,255,1);

-- Gundrak south instance entrance portals
SET @OGUID  := 5287; -- (need 2)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,192635,571,1,1,6700.195,-4662.38,446.7864,3.909541,0,0,0.3746067,0.9271838,120,255,1),
(@OGUID+1,192170,571,1,1,6700.195,-4662.38,446.7864,3.909541,0,0,0.3746067,0.9271838,120,255,1);
