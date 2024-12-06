-- Add missing spawns and pooling for Tattered Chest ID: 2844 in Azuremyst Isle
SET @POOLID := 782; -- 6 required
SET @OGUID := 12722; -- 8 required

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 2844, 530, 3524, 3567, 1, 1, -4434.80810546875, -11967.896484375, 32.12919235229492187, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 360, 255, 1, 45942), -- Pod Cluster
(@OGUID+1, 2844, 530, 3524, 3569, 1, 1, -4826.92822265625, -11486.4384765625, -37.0933952331542968, 2.321286916732788085, 0, 0, 0.917059898376464843, 0.398749500513076782, 360, 255, 1, 40892), -- Tide's Hollow
(@OGUID+2, 2844, 530, 3524, 3571, 1, 1, -4481.47900390625, -11624.3408203125, 11.0514068603515625, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 360, 255, 1, 45942), -- Bristlelimb Village
(@OGUID+3, 2844, 530, 3524, 3572, 1, 1, -3099.85595703125, -12480.6591796875, 0.465005010366439819, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 360, 255, 1, 40892), -- Stillpine Hold
(@OGUID+4, 2844, 530, 3524, 3572, 1, 1, -3222.1826171875, -12490.9609375, 15.47136592864990234, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 360, 255, 1, 45942), -- Stillpine Hold
(@OGUID+5, 2844, 530, 3524, 3577, 1, 1, -4600.736328125, -12871.3798828125, 6.40148019790649414, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 360, 255, 1, 45942), -- Greezie's Camp
(@OGUID+6, 2844, 530, 3524, 3578, 1, 1, -3371.1328125, -12716.5361328125, 19.57845115661621093, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 360, 255, 1, 45942), -- Menagerie Wreckage
(@OGUID+7, 2844, 530, 3524, 3639, 1, 1, -5200.96875, -11046.71875, 26.86562156677246093, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 360, 255, 1, 40892); -- Silvermyst Lsle

UPDATE `gameobject` SET `spawntimesecs`=360, `animprogress`=225, `state`=1 WHERE `guid` IN (12098,29908,12097,30474,85814,12095,12096,30513,12093,12094);

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID AND @POOLID+5;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLID,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Stillpine Hold'),
(@POOLID+1,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Pods and Greezie''s Camp'),
(@POOLID+2,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Menagerie Wreckage'),
(@POOLID+3,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Bristlelimb Village'),
(@POOLID+4,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Tides Hollow'),
(@POOLID+5,1,'Tattered Chest (2844), Azuremyst Isle, Chest Pool Silvermyst Isle');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID AND @POOLID+5;
INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`) VALUES
(1,12093,@POOLID,0,'Tattered Chest (2844), Stillpine Hold'),
(1,@OGUID+3,@POOLID,0,'Tattered Chest (2844), Stillpine Hold'),
(1,@OGUID+4,@POOLID,0,'Tattered Chest (2844), Stillpine Hold'),
(1,30474,@POOLID+1,0,'Tattered Chest (2844), Pod Wreckage'),
(1,@OGUID,@POOLID+1,0,'Tattered Chest (2844), Pod Cluster'),
(1,@OGUID+5,@POOLID+1,0,'Tattered Chest (2844), Greezie''s Camp'),
(1,12094,@POOLID+2,0,'Tattered Chest (2844), Menagerie Wreckage'),
(1,@OGUID+6,@POOLID+2,0,'Tattered Chest (2844), Menagerie Wreckage'),
(1,29908,@POOLID+2,0,'Tattered Chest (2844), Azuremyst Isle'),
(1,12096,@POOLID+3,0,'Tattered Chest (2844), Bristlelimb Village'),
(1,30513,@POOLID+3,0,'Tattered Chest (2844), Bristlelimb Village'),
(1,@OGUID+2,@POOLID+3,0,'Tattered Chest (2844), Bristlelimb Village'),
(1,85814,@POOLID+4,0,'Tattered Chest (2844), Tides Hollow'),
(1,12095,@POOLID+4,0,'Tattered Chest (2844), Tides Hollow'),
(1,@OGUID+1,@POOLID+4,0,'Tattered Chest (2844), Tides Hollow'),
(1,12098,@POOLID+5,0,'Tattered Chest (2844), Silvermyst Isle'),
(1,@OGUID+7,@POOLID+5,0,'Tattered Chest (2844), Silvermyst Isle'),
(1,12097,@POOLID+5,0,'Tattered Chest (2844), Moonwing Den');
