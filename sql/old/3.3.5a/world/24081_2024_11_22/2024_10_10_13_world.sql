-- Add missing Battered Chest ID: 2849 with pooling in Ghostlands
SET @OGUID := 10633; -- 7 required
SET @POOLID := 585; -- 2 required

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 2849, 530, 3433, 3516, 1, 1, 7473.455078125, -7896.78662109375, 160.006317138671875, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 360, 255, 1, 42917), -- Zeb'Tela
(@OGUID+1, 2849, 530, 3433, 3516, 1, 1, 7351.85400390625, -7824.33251953125, 147.920196533203125, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 360, 255, 1, 42917), -- Zeb'Tela
(@OGUID+2, 2849, 530, 3433, 3516, 1, 1, 7271.18701171875, -7755.77001953125, 150.018524169921875, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 360, 255, 1, 56713), -- Zeb'Tela
(@OGUID+3, 2849, 530, 3433, 3517, 1, 1, 6806.115234375, -7428.17529296875, 47.94741439819335937, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 360, 255, 1, 42917), -- Zeb'Nowa
(@OGUID+4, 2849, 530, 3433, 3517, 1, 1, 6660.6044921875, -7406.60400390625, 57.55510330200195312, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 360, 255, 1, 41446), -- Zeb'Nowa
(@OGUID+5, 2849, 530, 3433, 3517, 1, 1, 7153.0546875, -7575.98681640625, 49.18671798706054687, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 360, 255, 1, 56713), -- Zeb'Nowa
(@OGUID+6, 2849, 530, 3433, 3517, 1, 1, 7007.033203125, -7526.05908203125, 48.84354400634765625, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 360, 255, 1, 56713); -- Zeb'Nowa

-- Update existing spawns to match new ones.
UPDATE `gameobject` SET `spawntimesecs`=360, `animprogress`=225, `state`=1 WHERE `guid`=27287;

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID AND @POOLID+1;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLID,1,'Battered Chest (2849), Ghostlands, Chest Pool Zeb''Tela'),
(@POOLID+1,1,'Battered Chest (2849), Ghostlands, Chest Pool Zeb''Nowa');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID AND @POOLID+1;
INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`) VALUES
(1,27287,@POOLID,0,'Battered Chest (2849), Zeb''Tela'),
(1,@OGUID,@POOLID,0,'Battered Chest (2849), Zeb''Tela'),
(1,@OGUID+1,@POOLID,0,'Battered Chest (2849), Zeb''Tela'),
(1,@OGUID+2,@POOLID,0,'Battered Chest (2849), Zeb''Tela'),
(1,@OGUID+3,@POOLID+1,0,'Battered Chest (2849), Zeb''Nowa'),
(1,@OGUID+4,@POOLID+1,0,'Battered Chest (2849), Zeb''Nowa'),
(1,@OGUID+5,@POOLID+1,0,'Battered Chest (2849), Zeb''Nowa'),
(1,@OGUID+6,@POOLID+1,0,'Battered Chest (2849), Zeb''Nowa');
