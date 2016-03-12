--
SET @GUID   := 43456;
SET @OLDGUID   := 121; -- 4.x

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+3;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDGUID+0 AND @OLDGUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,30236,571,1,64,0,0,6219.17,59.9983,400.375,1.6057,120,0,0,1,0,0,0,0,0),
(@GUID+1,30236,571,1,64,0,0,6256.11,93.2413,410.92,0.767945,120,0,0,1,0,0,0,0,0),
(@GUID+2,30236,571,1,64,0,0,6297.37,53.5677,410.957,0.802851,120,0,0,1,0,0,0,0,0),
(@GUID+3,30236,571,1,64,0,0,6162.81,60.9792,400.371,1.55334,120,0,0,1,0,0,0,0,0);

SET @OGUID  := 7278;
DELETE FROM `gameobject` WHERE `id` IN (192657,192658,192769,192770,192767,192768,192771,192772);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0, 192657, 571, 1, 64, 6255.958, 93.05556, 403.0368, 5.454153, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+1, 192658, 571, 1, 64, 6255.961, 93.06424, 408.4696, 5.44543, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+2, 192769, 571, 1, 64, 6219.205, 59.86806, 392.5132, 6.283184, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+3, 192770, 571, 1, 64, 6219.202, 59.875, 397.924, 6.274461, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+4, 192767, 571, 1, 64, 6297.223, 53.39583, 402.9972, 5.532692, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+5, 192768, 571, 1, 64, 6297.226, 53.40451, 408.4129, 5.523969, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+6, 192771, 571, 1, 64, 6162.772, 60.73438, 392.4362, 6.265733, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+7, 192772, 571, 1, 64, 6162.768, 60.74306, 397.8138, 6.257008, 0, 0, 0, 1, 120, 255, 1);
