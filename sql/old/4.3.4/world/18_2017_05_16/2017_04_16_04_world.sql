-- Add missing Milo's Gyro
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=37169;
SET @CGUID := 250022;
DELETE FROM `creature` WHERE `guid` IN (@CGUID, @CGUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 37169, 0, 0, 0, 1, 169, 0, 0, 0, -6243.374, 305.5695, 384.311, 2.356194, 120, 0, 0, 1, 0, 0, 0, 0, 0, 23420);
-- Add missing auras to Milo & Milo's Gyro
DELETE FROM `creature_template_addon` WHERE `entry` IN (37113,37169);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37113,0,0,0,1,0, '70045 70042'),(37169,0,0,0,1,0, '70045 70042');
-- Add missing gameobjects
SET @OGUID := 200623;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 201711, 0, 0, 0, 1, 169, 0, -6218.997, 118.5677, 431.6347, 2.600535, 0, 0, 0.9636297, 0.267241, 120, 255, 1, 23877);
DELETE FROM `gameobject_addon` WHERE `guid`=@OGUID;
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES (@OGUID, 7, 1);
