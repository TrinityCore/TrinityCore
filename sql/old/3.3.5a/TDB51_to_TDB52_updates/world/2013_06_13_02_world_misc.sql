-- Add missing lake frog spawns
SET @GUID := 72770;
SET @POOL := 60003;

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID+0,33224,571,1,1,0,0,3819.225,-4360.781,182.312,4.927386,120,5,0,1,0,1),
(@GUID+1,33224,571,1,1,0,0,3822.34,-4362.166,182.5561,0.4575224,120,5,0,1,0,1),
(@GUID+2,33224,571,1,1,0,0,3803.501,-4354.347,180.8061,4.409188,120,5,0,1,0,1),
(@GUID+3,33224,571,1,1,0,0,3778.917,-4312.72,183.4503,0.9890772,120,5,0,1,0,1),
(@GUID+4,33224,571,1,1,0,0,3805.652,-4352.625,181.4311,5.342484,120,5,0,1,0,1),
(@GUID+5,33224,571,1,1,0,0,3803.122,-4347.75,180.8061,2.036006,120,5,0,1,0,1);

DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 1, 'Lake Frog (33224)');

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID+0, @POOL, 0, 'Lake Frog (33224) - Spawn 1'),
(@GUID+1, @POOL, 0, 'Lake Frog (33224) - Spawn 2'),
(@GUID+2, @POOL, 0, 'Lake Frog (33224) - Spawn 3'),
(@GUID+3, @POOL, 0, 'Lake Frog (33224) - Spawn 4'),
(@GUID+4, @POOL, 0, 'Lake Frog (33224) - Spawn 5'),
(@GUID+5, @POOL, 0, 'Lake Frog (33224) - Spawn 6');
