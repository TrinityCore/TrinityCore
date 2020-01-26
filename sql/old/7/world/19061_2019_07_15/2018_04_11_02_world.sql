-- 
SET @CGUID := 452746;
DELETE FROM `creature` WHERE `guid`=452746;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID,61837,0,0,0,1,169,0,0,0,-8722.814,522.0989,98.89994,1.841757,300,0,0,788,655,0,0,0,0,0,0,'',23420);
DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID,0,0,0,257,426,0,0,0,"");
