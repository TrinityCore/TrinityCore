-- Add missing Terokkar Triggers to db
SET @GUID :=40253;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+12;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
(@GUID+0,23102,530,1,1,0,0,-2414.89038,4436.77,163.188354,0.209439516,120,0,0,1,0,0),
(@GUID+1,23102,530,1,1,0,0,-2414.979,4458.585,165.8086,2.80998015,120,0,0,1,0,0),
(@GUID+2,23102,530,1,1,0,0,-2418.69775,4446.772,165.705322,2.18166161,120,0,0,1,0,0),
(@GUID+3,23102,530,1,1,0,0,-2423.714,4453.51563,165.694977,0.575958669,120,0,0,1,0,0),
(@GUID+4,23102,530,1,1,0,0,-2426.56567,4437.25732,168.060211,3.63028479,120,0,0,1,0,0),
(@GUID+5,23102,530,1,1,0,0,-2428.65723,4460.04932,166.3208,0.7679449,120,0,0,1,0,0),
(@GUID+6,23102,530,1,1,0,0,-2432.37817,4444.567,170.260162,4.59021568,120,0,0,1,0,0),
(@GUID+7,23102,530,1,1,0,0,-2432.45435,4434.5835,170.945572,0.820304751,120,0,0,1,0,0),
(@GUID+8,23102,530,1,1,0,0,-2432.74561,4458.09668,166.1593,1.27409029,120,0,0,1,0,0),
(@GUID+9,23102,530,1,1,0,0,-2435.68359,4440.8667,171.700333,4.049164,120,0,0,1,0,0),
(@GUID+10,23102,530,1,1,0,0,-2443.70239,4634.14355,158.2777,0,120,0,0,1,0,0),
(@GUID+11,23102,530,1,1,0,0,-2466.943,4699.982,155.832977,0,120,0,0,1,0,0),
(@GUID+12,23102,530,1,1,0,0,-2482.24243,4661.68066,161.495926,0,120,0,0,1,0,0);
-- Set Terokkar Trigger as Trigger
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=23102;
-- Missing Go
SET @GUID :=226;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(@GUID,185863,530,1,1,-2466.60474,4700.11963,155.7146,1.81514192,0,0,0,0,120,0,1);
