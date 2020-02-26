-- Add pool of Borgoth the Bloodletter
SET @CGUID := 52139; -- Need new GUID
SET @POOLENTRY := 380; -- Need new POOLENTRY

DELETE FROM `creature` WHERE `guid`=@CGUID; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 16247, 530, 0, 0, 1, 1, 0, 0, 6439.692, -6643.391, 107.431, 1.7330, 300, 0, 0, 629, 0, 0, 0, 0, 0, 0);

DELETE FROM `pool_template` WHERE `entry`=@POOLENTRY;
INSERT INTO `pool_template` VALUES (@POOLENTRY, 1, "Borgoth the Bloodletter");

DELETE FROM `pool_creature` WHERE `guid` IN (@CGUID, 82889);
INSERT INTO `pool_creature` VALUES 
(@CGUID, @POOLENTRY, 0, "Borgoth the Bloodletter #1"),
(82889, @POOLENTRY, 0, "Borgoth the Bloodletter #2");
