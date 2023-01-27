--
-- Add pool of Masophet the Black
SET @CGUID := 52140; -- Need new GUID
SET @POOLENTRY := 381; -- Need new POOLENTRY

DELETE FROM `creature` WHERE `guid` IN (@CGUID,52640,60777,60792); 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 16249, 530, 0, 0, '0', 0, 0, 1, 6310.767, -6249.392, 80.812, 2.4250, 300, 0, 0, 486, 1202, 0, 0, 0, 0, 0),
(52640, 16317, 530, 0, 0, '0', 0, 0, 1, 6301.899, -6257.172, 77.8141, 0.802766, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(60777, 16317, 530, 0, 0, '0', 0, 0, 1, 6301.729, -6241.071, 77.8141, 5.446064, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(60792, 16317, 530, 0, 0, '0', 0, 0, 1, 6318.017, -6240.674, 77.8141, 3.948309, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature` SET `position_x`=6376.408, `position_y`=-6451.7163, `position_z`=70.686, `orientation`=2.766143 WHERE `guid`=82866;
UPDATE `creature` SET `position_x`=6355.741, `position_y`=-6456.6611, `position_z`=74.923, `orientation`=3.543688 WHERE `guid`=82919;

DELETE FROM `pool_template` WHERE `entry`=@POOLENTRY;
INSERT INTO `pool_template` VALUES (@POOLENTRY, 1, "Masophet the Black");

DELETE FROM `pool_creature` WHERE `guid` IN (@CGUID, 82907);
INSERT INTO `pool_creature` VALUES
(@CGUID, @POOLENTRY, 0, "Masophet the Black #1"),
(82907, @POOLENTRY, 0, "Masophet the Black #2");
