-- 
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry` IN (29095, 29139);

SET @GUID := 27587;
DELETE FROM `creature` WHERE `id`=29139;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID, 29139, 0, 0, 0, 1, 1, 0, 0, 1579.649, 193.2588, -43.01888, 1.570796, 300, 0, 0, 1220, 0, 0, 0, 0, 0, "", 0);
