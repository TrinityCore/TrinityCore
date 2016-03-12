--
UPDATE `creature` SET `phaseMask`=1 WHERE `guid` IN (88806, 88792, 88802, 88788, 88777, 88778, 88804, 88790, 88800, 88786, 88803, 88789, 88797, 88783, 88796, 88782, 88799, 88785, 88784, 88798);
DELETE FROM `creature` WHERE `guid` IN (129856, 129855, 129857, 129858, 129864);

SET @GUID := 6341;  -- 3 free gob guid set by TC
DELETE FROM `gameobject` WHERE `guid`IN (@GUID, @GUID+1, @GUID+2);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID+0,196871,571,1,1,8121.33,794.503,481.288,-1.797,0,0,-0.782608,0.622515,180,100,1),
(@GUID+1,196871,571,1,1,5644.50,2107.415,798.054,4.5902,0,0,-0.782608,0.622515,180,100,1),
(@GUID+2,196871,571,1,1,5660.98,2106.137,798.054,4.5902,0,0,-0.782608,0.622515,180,100,1);

DELETE FROM `gameobject_addon` WHERE `guid` IN (164446,164447, 6135, 6134);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES 
(@GUID+1,8,1000), (@GUID+2,8,1000), (6135,9,1000), (6134,9,1000);
