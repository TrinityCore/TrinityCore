-- Add some missing guids
SET @GUID := 42153;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,32666,530,1,1,0,0,9830.201,-7389.711,13.68803,5.532694,120,0,0,1,0,0),
(@GUID+1,32667,530,1,1,0,0,9859.044,-7406.975,13.7113,1.658063,120,0,0,1,0,0),
(@GUID+2,31144,530,1,1,0,0,9869.401,-7389.657,13.69022,3.90953755,120,0,0,1,0,0),
(@GUID+3,31144,530,1,1,0,0,9871.973,-7392.763,13.6818113,3.35103226,120,0,0,1,0,0),
(@GUID+4,31146,530,1,1,0,0,9850.529,-7395.442,13.72216,4.694936,120,0,0,1,0,0);
-- Addons
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @GUID AND @GUID+4;
DELETE FROM `creature_addon` WHERE `guid`=66686;
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES
(@GUID,1, '7056 61573'),
(@GUID+1,1, '7056 61573'),
(@GUID+2,1, '7056 61573'),
(@GUID+3,1, '7056 61573'),
(@GUID+4,1, '7056 61573'),
(66686,1, '7056');
-- convert npc to trigger
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=18504;
