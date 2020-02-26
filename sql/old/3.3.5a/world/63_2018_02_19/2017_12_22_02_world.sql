-- 
SET @CGUID:= 42637; -- 1 guid

DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID, 16031, 329, 0, 0, 1, 1, 0, 0, 4044.78, -3333.68, 117.26, 4.153883, 7200, 0, 0, 4120, 0, 0, 0, 0, 0, '', 0);
