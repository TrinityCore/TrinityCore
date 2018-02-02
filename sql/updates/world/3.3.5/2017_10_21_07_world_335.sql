SET @POOLENTRY := 378;  -- need a new pool_template entry for this
SET @GUID := 36943; -- need a new GUID for the 2nd spawn
SET @CGUID := 26081;  -- original TDB spawn

-- new spawn location (sniff)
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUES
(@GUID, 5786, 1, 1, -2780.27, -702.809, 6.526313, 0.1570796, 3600, 176);

DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `bytes2`) VALUES (@GUID, 4097);

DELETE FROM `pool_template` WHERE `entry`=@POOLENTRY;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLENTRY, 1, 'Snagglespear');

DELETE FROM `pool_creature` WHERE `guid` IN (@CGUID, @GUID);
INSERT INTO `pool_creature` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@CGUID, @POOLENTRY, 0, 'Snagglespear Spawn 1'),
(@GUID, @POOLENTRY, 0, 'Snagglespear Spawn 2');

-- Reduce original Snagglespear (5786) spawn time to 1 hour
UPDATE `creature` SET `spawntimesecs`=3600 WHERE `guid`=@CGUID;
