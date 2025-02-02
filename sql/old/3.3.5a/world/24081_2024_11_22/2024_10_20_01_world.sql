-- Add spawns and pooling for Large Battered Chest ID: 75293 in Ghostlands
SET @POOLID := 368; -- One required
SET @OGUID := 10860; -- Three required

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 75293, 530, 3433, 3500, 1, 1, 6443.123046875, -6660.0498046875, 106.3956069946289062, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 360, 255, 1, 41446), -- Deatholme
(@OGUID+1, 75293, 530, 3433, 3500, 1, 1, 6645.44921875, -6329.88427734375, 9.133299827575683593, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 360, 255, 1, 41446), -- Deatholme
-- From Mangos db
(@OGUID+2, 75293, 530, 3433, 3500, 1, 1, 6527.45, -6514.33, 43.762, 3.47321, 0, 0, -0.986285, 0.16505, 5200, 255, 1, 0);

UPDATE `gameobject` SET `spawntimesecs`=360, `animprogress`=225, `state`=1 WHERE `guid` IN (27542);

DELETE FROM `pool_template` WHERE `entry`=@POOLID;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLID,1,'Large Battered Chest (75293), Ghostlands, Chest Pool Deatholme');

DELETE FROM `pool_members` WHERE `poolSpawnId`=@POOLID;
INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`) VALUES
(1,27542,@POOLID,0,'Large Battered Chest (75293), Deatholme'),
(1,@OGUID,@POOLID,0,'Large Battered Chest (75293), Deatholme'),
(1,@OGUID+1,@POOLID,0,'Large Battered Chest (75293), Deatholme'),
(1,@OGUID+2,@POOLID,0,'Large Battered Chest (75293), Deatholme');
